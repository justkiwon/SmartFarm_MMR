#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient

# Interfaces
from mmr_interfaces.srv import MoveDistance, CaptureVision, GetDropPose, RotateTurret, MoveArm
from mmr_interfaces.action import PickAndPlace

class MMROrchestrator(Node):
    """
    Main Logic (Modified):
    1. Scan & Work (Overview -> Loop Items)
       - Rotate Turret (Overview Pose)
       - Vision Overview -> Get Item List
       - For Each Item:
         - Move Arm near Item (Approach)
         - Vision Detail -> Get Refined Pose
         - Get Drop Slot
         - Pick And Place
    2. Move AMR (50cm)
    3. Repeat
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
        self.cli_arm_move = self.create_client(MoveArm, 'kinetic/move_arm')
        self.act_pnp = ActionClient(self, PickAndPlace, 'kinetic/pick_and_place')

        self.get_logger().info('Orchestrator Ready. Waiting for services...')
        self.wait_for_services()
        
        self.started = False

    def wait_for_services(self):
        self.cli_amr.wait_for_service()
        self.cli_vision.wait_for_service()
        self.cli_turret.wait_for_service()
        self.cli_drop.wait_for_service()
        self.cli_arm_move.wait_for_service()
        self.act_pnp.wait_for_server()
        self.get_logger().info('All Services/Actions Connected!')

    def on_start(self):
        # Thread Entry Point
        import time
        time.sleep(2.0) # Wait a bit for everything to settle
        self.run_sequence()

    def run_sequence(self):
        self.get_logger().info('>>> MMR MISSION START (Orchestrated Flow) <<<')

        for i in range(1, self.total_steps + 1):
            self.get_logger().info(f'--- Step {i}/{self.total_steps} ---')

            # 1. LEFT Side Scan & Process
            self.get_logger().info('[Orchestrator] === LEFT SIDE ===')
            self.process_side(RotateTurret.Request.LEFT)
            
            # 2. RIGHT Side Scan & Process
            self.get_logger().info('[Orchestrator] === RIGHT SIDE ===')
            self.process_side(RotateTurret.Request.RIGHT)
            
            # 3. Return to HOME
            self.get_logger().info('[Orchestrator] Returning to HOME...')
            self.call_turret(RotateTurret.Request.FORWARD)  # FORWARD = HOME

            # 4. AMR Move (After both sides complete)
            self.get_logger().info(f'[Orchestrator] Section Done. Moving AMR {self.step_dist}m ...')
            if not self.call_amr(self.step_dist):
                self.get_logger().error('AMR Error. Abort.')
                break
            
        self.get_logger().info('>>> MISSION COMPLETE <<<')

    def process_side(self, direction):
        # 1. Move to Overview Pose
        self.get_logger().info('[Orchestrator] Moving to Overview Pose...')
        success, arm_pose_full = self.call_turret(direction)
        
        if not success:
            self.get_logger().error('Turret rotation failed')
            return
        
        if not arm_pose_full or len(arm_pose_full) < 6:
            self.get_logger().warn('No pose from turret, using default')
            arm_pose_full = [300.0, 0.0, 400.0, 180.0, 0.0, 0.0]
        
        self._current_arm_pose = arm_pose_full  # Store full [x,y,z,r,p,y]
        self.get_logger().info(f'[Orchestrator] Arm at XYZ: {arm_pose_full[:3]}, RPY: {arm_pose_full[3:6]}')

        # 2. Vision Overview
        self.get_logger().info('[Orchestrator] Capturing Overview...')
        found, xs, ys, zs, tags = self.call_vision(mode=0) # Overview
        
        if not found or not tags:
            self.get_logger().info('  -> No items found in overview.')
            return

        self.get_logger().info(f'  -> Found {len(tags)} items. Starting Loop...')

        # 3. Loop through items
        for k in range(len(tags)):
            tag = tags[k]
            
            # Get actual robot arm position (stored from turret call)
            arm_pose = getattr(self, '_current_arm_pose', [300.0, 0.0, 400.0, 180.0, 0.0, 0.0])
            
            # [IMPORTANT] Camera Coordinate System:
            # Camera faces FORWARD (not downward!)
            # - cam_x: lateral offset (left/right from camera center)
            # - cam_y: vertical offset (up/down from camera center)
            # - cam_depth: distance forward (away from camera)
            cam_x = xs[k]      # mm - lateral offset
            cam_y = ys[k]      # mm - vertical offset  
            cam_depth = zs[k]  # mm - forward distance
            
            # Transform to Base Frame
            # Assuming camera's forward direction aligns with robot's current orientation
            # For LEFT pose: camera points in +Y direction (sideways)
            # This is a simplified transform - may need calibration!
            
            # Simple approximation (needs refinement based on actual setup):
            base_x = arm_pose[0] + cam_x       # Lateral becomes X offset
            base_y = arm_pose[1] + cam_depth   # Depth becomes Y (forward for LEFT)
            base_z = arm_pose[2] - cam_y       # Vertical becomes Z (down is negative)
            
            self.get_logger().info(f'  [Item #{k+1}] {tag}')
            self.get_logger().info(f'    Camera: lateral={cam_x:.1f}, vertical={cam_y:.1f}, depth={cam_depth:.1f} mm')
            self.get_logger().info(f'    Arm: ({arm_pose[0]:.1f}, {arm_pose[1]:.1f}, {arm_pose[2]:.1f})')
            self.get_logger().info(f'    Base: ({base_x:.1f}, {base_y:.1f}, {base_z:.1f}) mm')

            # 3-a. Move Arm Near Item (Approach for Detail Shot)
            # Use SAME orientation as overview (keep aligned)
            # Z + 200mm offset for approach
            approach_pose = [base_x, base_y, base_z + 200.0, arm_pose[3], arm_pose[4], arm_pose[5]] 
            
            self.get_logger().info(f'    -> Moving to Approach Pose: {approach_pose}')
            if not self.call_arm_move(approach_pose):
                self.get_logger().error('    -> Arm Move Failed. Skip.')
                continue

            # 3-b. Vision Detail (Refine)
            # Pass base pose (mm) for matching
            approx_pose = [base_x, base_y, base_z]
            self.get_logger().info('    -> Capturing Detail Shot...')
            ok, r_xs, r_ys, r_zs, _ = self.call_vision(mode=1, init_pose=approx_pose)
            
            if not ok or not r_xs:
                self.get_logger().warn('    -> Vision Detail Failed. Skip.')
                continue
            
            # Refined pose from vision (Camera Frame -> Base Frame)
            # Apply same transform as overview (forward-facing camera)
            refined_cam_x = r_xs[0]      # mm - lateral
            refined_cam_y = r_ys[0]      # mm - vertical
            refined_cam_depth = r_zs[0]  # mm - depth
            
            pick_x = arm_pose[0] + refined_cam_x
            pick_y = arm_pose[1] + refined_cam_depth
            pick_z = arm_pose[2] - refined_cam_y
            
            # IMPORTANT: Also include RPY to stay aligned!
            pick_pose = [pick_x, pick_y, pick_z, arm_pose[3], arm_pose[4], arm_pose[5]]
            self.get_logger().info(f'    -> Refined Pick: ({pick_x:.1f}, {pick_y:.1f}, {pick_z:.1f}) RPY=({arm_pose[3]:.1f}, {arm_pose[4]:.1f}, {arm_pose[5]:.1f})')

            # 3-c. Get Drop Pose
            drop_pose = self.call_get_drop(tag)

            # 3-d. Pick And Place (Grasp -> Place)
            self.get_logger().info('    -> Executing Grasp & Place Action...')
            if self.call_pnp(pick_pose, drop_pose):
                self.get_logger().info('    -> Success.')
            else:
                self.get_logger().error('    -> Grasp Action Failed.')

    # --- Client Wrappers (Running in Mission Thread) ---
    def call_amr(self, dist):
        req = MoveDistance.Request(); req.distance = float(dist)
        res = self.cli_amr.call(req)
        return res.success

    def call_turret(self, direction):
        req = RotateTurret.Request(); req.direction = direction
        res = self.cli_turret.call(req)
        if res.success and len(res.current_pose) >= 6:
            return res.success, res.current_pose[:6]  # Return [x,y,z,r,p,y]
        return res.success, None

    def call_vision(self, mode, init_pose=[0.0,0.0,0.0]):
        req = CaptureVision.Request()
        req.mode = mode
        req.initial_pose = [float(v) for v in init_pose]
        res = self.cli_vision.call(req)
        if res.success:
            return True, res.poses_x, res.poses_y, res.poses_z, res.tags
        return False, [], [], [], []

    def call_get_drop(self, tag):
        req = GetDropPose.Request(); req.tag = tag
        res = self.cli_drop.call(req)
        return [res.x, res.y, res.z]
    
    def call_arm_move(self, pose_list):
        req = MoveArm.Request()
        req.pose = [float(v) for v in pose_list]
        res = self.cli_arm_move.call(req)
        return res.success

    def call_pnp(self, pick, place):
        goal = PickAndPlace.Goal()
        goal.pick_pose = [float(v) for v in pick]
        goal.place_pose = [float(v) for v in place]
        
        future = self.act_pnp.send_goal_async(goal)
        while not future.done():
            import time; time.sleep(0.1)
            
        gh = future.result()
        if not gh.accepted:
            self.get_logger().error('    -> PnP Rejected.')
            return False
            
        res_future = gh.get_result_async()
        while not res_future.done():
            import time; time.sleep(0.1)
            
        return res_future.result().result.success
    
    def get_arm_pose(self):
        """Get approximate arm position based on last direction"""
        # Approximate positions for each overview pose (in mm)
        # These should be calibrated for actual robot
        # LEFT [90,-60,-13,0,-15,0] -> roughly at (+Y side)
        # RIGHT [-90,-60,-13,0,-15,0] -> roughly at (-Y side)
        
        # For now, use rough estimates
        # TODO: Query actual position from robot
        if not hasattr(self, '_last_direction'):
            return [300.0, 0.0, 400.0]
        
        if self._last_direction == RotateTurret.Request.LEFT:
            # Camera is on left (+Y) side
            return [100.0, 250.0, 450.0]  # Approximate LEFT position
        elif self._last_direction == RotateTurret.Request.RIGHT:
            # Camera is on right (-Y) side  
            return [100.0, -250.0, 450.0]  # Approximate RIGHT position
        else:
            return [300.0, 0.0, 400.0]  # FORWARD/HOME

def main(args=None):
    rclpy.init(args=args)
    
    node = MMROrchestrator()
    
    from rclpy.executors import MultiThreadedExecutor
    executor = MultiThreadedExecutor()
    executor.add_node(node)
    
    import threading
    thread = threading.Thread(target=node.on_start, daemon=True)
    thread.start()
    
    try:
        executor.spin()
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
