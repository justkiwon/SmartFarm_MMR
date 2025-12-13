#!/usr/bin/env python3
import time
import rclpy
from rclpy.node import Node
from rclpy.action import ActionServer

# Interfaces
from mmr_interfaces.action import PickAndPlace
from mmr_interfaces.srv import RotateTurret, GetDropPose

import sys
# Force venv site-packages into sys.path
sys.path.append('/home/pandora/dev/strawberry/shared/venvs/.venv_production/lib/python3.10/site-packages')

# xArm SDK
try:
    from xarm.wrapper import XArmAPI
    HAS_XARM = True
except ImportError:
    HAS_XARM = False
    print("⚠️  xarm-python-sdk not found.")

class PalletizingNode(Node):
    """
    Super Kinetic Controller
    1. Action: kinetic/pick_and_place (Precise Manipulation)
    2. Service: kinetic/rotate_turret (Camera View Control)
    3. Service: kinetic/get_drop_pose (Slot Management)
    """

    # --- Config ---
    ROBOT_IP = '192.168.10.217'
    SPEED = 100
    ACC   = 1000

    # Gripper
    GRIP_OPEN  = 300
    GRIP_CLOSE = 0
    GRIP_SPEED = 5000

    # Key Poses (Unit: mm, degree)
    # [x, y, z, r, p, yaw]
    # Note: Roll=180, Pitch=0(or -90) makes gripper look down. 
    # Let's assume standard top-down grasp: r=180, p=0, y=0 (or y varies)
    
    # HOME (Forward, Packed)
    POSE_HOME  = [206, 0, 200, 180, 0, 0]
    
    # Overview Poses (High Z, Rotated Base)
    POSE_LOOK_LEFT  = [200,  150, 400, 180, 0, 90]  # Base rotated +90 (Left)
    POSE_LOOK_RIGHT = [200, -150, 400, 180, 0, -90] # Base rotated -90 (Right)
    POSE_LOOK_FWD   = [300,    0, 400, 180, 0, 0]   # Look Forward

    # Pallet Slots (Simple Logic)
    # 2x2 Grid start from ...
    drop_slot_index = 0

    def __init__(self):
        super().__init__('palletizing_node')

        self.arm = None
        self._init_xarm()

        # Action Server
        self.pnp_server = ActionServer(
            self, PickAndPlace, 'kinetic/pick_and_place', self.pnp_callback
        )

        # Service Servers
        self.srv_turret = self.create_service(
            RotateTurret, 'kinetic/rotate_turret', self.turret_cb
        )
        self.srv_drop = self.create_service(
            GetDropPose, 'kinetic/get_drop_pose', self.drop_pose_cb
        )

        self.get_logger().info('PalletizingNode Ready (PickAndPlace, RotateTurret, GetDropPose)')

    # --- xArm Init & Utils ---
    def _init_xarm(self):
        if not HAS_XARM: return
        try:
            self.arm = XArmAPI(self.ROBOT_IP)
            self.arm.motion_enable(True)
            self.arm.set_mode(0); self.arm.set_state(0)
            self.arm.clean_error()
            time.sleep(0.5)
            # Gripper
            self.arm.set_gripper_enable(True)
            self.arm.set_gripper_mode(0)
            self.arm.set_gripper_position(self.GRIP_OPEN, wait=True, speed=self.GRIP_SPEED)
            # Move Home
            self.move_pose(self.POSE_HOME)
        except Exception as e:
            self.get_logger().error(f'xArm Init Failed: {e}')
            self.arm = None

    def move_pose(self, pose):
        """ pose: [x,y,z,r,p,y] mm/deg """
        if self.arm:
            self.arm.set_position(*pose, speed=self.SPEED, acc=self.ACC, wait=True)
            time.sleep(0.1)
        else:
            self.get_logger().info(f'[Sim] Move to {pose}')
            time.sleep(0.5)

    def gripper(self, open=True):
        pos = self.GRIP_OPEN if open else self.GRIP_CLOSE
        if self.arm:
            self.arm.set_gripper_position(pos, wait=True, speed=self.GRIP_SPEED, auto_enable=True)
            time.sleep(0.3)
        else:
            self.get_logger().info(f'[Sim] Gripper {"Open" if open else "Close"}')

    # --- Service Callbacks ---

    def turret_cb(self, request, response):
        """ Rotate xArm to look Left/Right/Fwd """
        d = request.direction
        target = self.POSE_HOME # Default

        if d == RotateTurret.Request.LEFT:
            target = self.POSE_LOOK_LEFT
            lbl = "LEFT"
        elif d == RotateTurret.Request.RIGHT:
            target = self.POSE_LOOK_RIGHT
            lbl = "RIGHT"
        else: # Forward
            target = self.POSE_LOOK_FWD
            lbl = "FORWARD"
        
        self.get_logger().info(f'[Turret] Rotating to {lbl}...')
        self.move_pose(target)
        
        response.success = True
        return response

    def drop_pose_cb(self, request, response):
        """ Calculate where to put the object based on tag """
        # Logic: Increment slot index to stack items
        # Let's say we have a palette on the back of AMR at x=-0.2, y=0.0
        
        # Simple Logic: 2 stacks
        idx = self.drop_slot_index % 4
        self.drop_slot_index += 1
        
        # Determine x, y offset
        # Base drop area: x=-200mm (behind base), y=0
        base_x = -0.2
        col = idx % 2
        row = idx // 2
        
        tx = base_x - (row * 0.1) # -0.2, -0.3
        ty = -0.1 + (col * 0.2)   # -0.1, +0.1
        tz = 0.1                  # height
        
        response.success = True
        response.x = tx
        response.y = ty
        response.z = tz
        self.get_logger().info(f'[DropSolver] Tag="{request.tag}" -> Slot {idx}: ({tx:.2f}, {ty:.2f})')
        return response

    # --- Action Callback ---

    def pnp_callback(self, goal_handle):
        """ Pick (A) -> Place (B) """
        pick = goal_handle.request.pick_pose   # [x,y,z] unit: meter
        place = goal_handle.request.place_pose # [x,y,z] unit: meter

        self.get_logger().info(f'[PnP] Start: Pick({pick}) -> Place({place})')
        fb = PickAndPlace.Feedback()
        fb.status = "Approaching Pick"
        goal_handle.publish_feedback(fb)

        # 1. Convert units
        p_x, p_y, p_z = [v * 1000.0 for v in pick]
        d_x, d_y, d_z = [v * 1000.0 for v in place]

        # 2. Pick Sequence
        # Approach (z + 50mm)
        self.move_pose([p_x, p_y, p_z + 50, 180, 0, 0])
        # Down
        self.move_pose([p_x, p_y, p_z,      180, 0, 0])
        # Grip
        self.gripper(open=False)
        # Up
        self.move_pose([p_x, p_y, p_z + 150, 180, 0, 0])

        fb.status = "Moving to Place"
        fb.progress = 50.0
        goal_handle.publish_feedback(fb)

        # 3. Place Sequence
        # Approach (z + 50mm)
        self.move_pose([d_x, d_y, d_z + 50, 180, 0, 0])
        # Down
        self.move_pose([d_x, d_y, d_z,      180, 0, 0])
        # Ungrip
        self.gripper(open=True)
        # Up
        self.move_pose([d_x, d_y, d_z + 50, 180, 0, 0])

        # 4. Finish
        self.move_pose(self.POSE_HOME)
        
        goal_handle.succeed()
        result = PickAndPlace.Result()
        result.success = True
        result.message = "PnP Complete"
        return result

def main(args=None):
    rclpy.init(args=args)
    node = PalletizingNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt: pass
    finally:
        if node.arm: node.arm.disconnect()
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
