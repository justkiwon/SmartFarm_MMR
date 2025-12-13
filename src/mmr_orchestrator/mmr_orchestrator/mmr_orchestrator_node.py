#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient

# Interfaces
from mmr_interfaces.srv import MoveDistance, CaptureVision, GetDropPose, RotateTurret
from mmr_interfaces.action import PickAndPlace

class MMROrchestrator(Node):
    """
    Main Logic:
    Loop 5m (every 0.5m):
      1. Move AMR
      2. Routine(Left)
      3. Routine(Right)
    
    Routine(Side):
      1. Rotate Turret
      2. Vision Overview -> Get Items
      3. For Item in Items:
         - Move Arm near Item (?) - Implicit in PnP or use Turret?
           (Here we assume Vision Detail simulates Zoom/Focus, 
            so we just call Vision Detail with coarse pose)
         - Vision Detail -> Get Refined Pose
         - Get Drop Slot
         - Action Pick & Place
    """

    def __init__(self):
        super().__init__('mmr_orchestrator')

        # Params
        self.declare_parameter('step_distance', 0.5)
        self.declare_parameter('total_distance', 5.0)
        self.step_dist = self.get_parameter('step_distance').value
        self.total_dist = self.get_parameter('total_distance').value
        self.total_steps = int(self.total_dist / self.step_dist)

        # Clients
        self.cli_amr = self.create_client(MoveDistance, 'amr/move_distance')
        self.cli_vision = self.create_client(CaptureVision, 'vision/capture_vision')
        self.cli_turret = self.create_client(RotateTurret, 'kinetic/rotate_turret')
        self.cli_drop = self.create_client(GetDropPose, 'kinetic/get_drop_pose')
        self.act_pnp = ActionClient(self, PickAndPlace, 'kinetic/pick_and_place')

        self.get_logger().info('Orchestrator Ready. Waiting for services...')
        self.wait_for_services()
        
        # Start
        self.timer = self.create_timer(1.0, self.on_start)
        self.started = False

    def wait_for_services(self):
        self.cli_amr.wait_for_service()
        self.cli_vision.wait_for_service()
        self.cli_turret.wait_for_service()
        self.cli_drop.wait_for_service()
        self.act_pnp.wait_for_server()
        self.get_logger().info('All Services/Actions Connected!')

    def on_start(self):
        if self.started: return
        self.started = True
        self.timer.cancel()
        self.run_sequence()

    def run_sequence(self):
        self.get_logger().info('>>> MMR MISSION START <<<')

        for i in range(1, self.total_steps + 1):
            self.get_logger().info(f'--- Step {i}/{self.total_steps} ---')

            # 1. AMR Move
            if not self.call_amr(self.step_dist):
                self.get_logger().error('AMR Error. Abort.')
                break

            # 2. Left Scan & Work
            self.get_logger().info('[Routine] LEFT Side')
            self.process_side(RotateTurret.LEFT)

            # 3. Right Scan & Work
            self.get_logger().info('[Routine] RIGHT Side')
            self.process_side(RotateTurret.RIGHT)

        self.get_logger().info('>>> MISSION COMPLETE <<<')

    def process_side(self, direction):
        # 1. Rotate Turret
        self.call_turret(direction)

        # 2. Vision Overview
        found, xs, ys, zs, tags = self.call_vision(mode=0) # 0=Overview
        if not found or not tags:
            self.get_logger().info('  -> Nothing found.')
            return

        # 3. Process Each Item
        for k in range(len(tags)):
            tag = tags[k]
            approx_pose = [xs[k], ys[k], zs[k]]
            self.get_logger().info(f'  -> Processing Item: {tag} at {approx_pose}')
            
            # 3-1. Detail Vision (Refine)
            # In real scenario, we might move arm closer first.
            # Here, we just ask vision to focus on approx_pose
            ok, r_xs, r_ys, r_zs, _ = self.call_vision(mode=1, init_pose=approx_pose) # 1=Detail
            if not ok or not r_xs:
                self.get_logger().warn('    -> Detail Vision Failed. Skip.')
                continue
            
            pick_pose = [r_xs[0], r_ys[0], r_zs[0]]

            # 3-2. Get Drop Pose
            drop_pose = self.call_get_drop(tag)
            
            # 3-3. Pick And Place
            self.call_pnp(pick_pose, drop_pose)

    # --- Client Wrappers ---
    def call_amr(self, dist):
        req = MoveDistance.Request(); req.distance = float(dist)
        future = self.cli_amr.call_async(req)
        rclpy.spin_until_future_complete(self, future)
        return future.result().success

    def call_turret(self, direction):
        req = RotateTurret.Request(); req.direction = direction
        future = self.cli_turret.call_async(req)
        rclpy.spin_until_future_complete(self, future)
        return future.result().success

    def call_vision(self, mode, init_pose=[0.0,0.0,0.0]):
        req = CaptureVision.Request()
        req.mode = mode
        req.initial_pose = [float(v) for v in init_pose]
        future = self.cli_vision.call_async(req)
        rclpy.spin_until_future_complete(self, future)
        res = future.result()
        if res.success:
            return True, res.poses_x, res.poses_y, res.poses_z, res.tags
        return False, [], [], [], []

    def call_get_drop(self, tag):
        req = GetDropPose.Request(); req.tag = tag
        future = self.cli_drop.call_async(req)
        rclpy.spin_until_future_complete(self, future)
        res = future.result()
        return [res.x, res.y, res.z]

    def call_pnp(self, pick, place):
        goal = PickAndPlace.Goal()
        goal.pick_pose = [float(v) for v in pick]
        goal.place_pose = [float(v) for v in place]
        
        future = self.act_pnp.send_goal_async(goal)
        rclpy.spin_until_future_complete(self, future)
        gh = future.result()
        if not gh.accepted:
            self.get_logger().error('    -> PnP Rejected.')
            return False
            
        res_future = gh.get_result_async()
        rclpy.spin_until_future_complete(self, res_future)
        return res_future.result().result.success

def main(args=None):
    rclpy.init(args=args)
    node = MMROrchestrator()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
