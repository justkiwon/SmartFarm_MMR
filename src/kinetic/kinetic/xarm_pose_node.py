#!/usr/bin/env python3
import time
import sys
import rclpy
from rclpy.node import Node
import numpy as np

# Interfaces
from mmr_interfaces.srv import ProcessSide, RotateTurret, GetDropPose, CaptureVision
from mmr_interfaces.action import PickAndPlace

# xArm SDK
sys.path.append('/home/pandora/dev/strawberry/shared/venvs/.venv_production/lib/python3.10/site-packages')
try:
    from xarm.wrapper import XArmAPI
except ImportError:
    print("❌ xArm SDK not found.")
    sys.exit(1)

from rclpy.executors import MultiThreadedExecutor
from rclpy.callback_groups import ReentrantCallbackGroup

class XArmPoseNode(Node):
    def __init__(self):
        super().__init__('xarm_pose_node')
        
        self.cb_group = ReentrantCallbackGroup()
        
        # --- Config ---
        self.ROBOT_IP = '192.168.10.217'
        self.SPEED = 100
        self.ACC = 1000
        
        # Gripper
        self.GRIP_CLOSE_POS = 0
        self.GRIP_OPEN_POS = 300
        self.GRIP_SPEED = 5000
        
        # Offsets (From test_approach.py)
        self.gripper_offset_depth = 220
        self.gripper_offset_height = 90
        self.gripper_offset_width = 50

        # Joint Poses
        self.JOINTS_LOOK_LEFT  = [90, -60, -13, 0, -15, 0]
        self.JOINTS_LOOK_RIGHT = [-90, -60, -13, 0, -15, 0]
        self.JOINTS_HOME = [0, -50, -20, 0, -20, 0]

        # Connect xArm
        self.arm = self._connect_arm()
        
        # Services Provided (Use Reentrant Group)
        self.srv_process = self.create_service(ProcessSide, 'mmr/process_side', self.process_side_cb, callback_group=self.cb_group)
        
        # Clients Needed (Use Reentrant Group for calls too?)
        self.cli_vision = self.create_client(CaptureVision, 'vision/capture_vision', callback_group=self.cb_group)
        self.cli_drop = self.create_client(GetDropPose, 'kinetic/get_drop_pose', callback_group=self.cb_group)
        
        self.get_logger().info('XArmPoseNode Ready (SDK Mode) - Waiting for ProcessSide request...')

    def _connect_arm(self):
        try:
            arm = XArmAPI(self.ROBOT_IP)
            arm.motion_enable(True)
            arm.clean_warn()
            arm.clean_error()
            arm.set_mode(0)
            arm.set_state(0)
            time.sleep(1.0)
            
            # Init Gripper
            arm.set_gripper_enable(True)
            arm.set_gripper_mode(0)
            arm.set_gripper_position(self.GRIP_OPEN_POS, wait=True, speed=self.GRIP_SPEED, auto_enable=True)
            
            return arm
        except Exception as e:
            self.get_logger().error(f'Failed to connect to xArm: {e}')
            sys.exit(1)

    # --- Low Level Helpers ---
    def move_joints(self, joints):
        ret = self.arm.set_servo_angle(angle=joints, speed=50, wait=True)
        if ret < 0:
            self.get_logger().error(f'Move Joints Failed: {ret}')
            return False
        return True

    def move_pose(self, pose, relative=False):
        # pose: [x,y,z,r,p,y]
        if relative:
            # Use Tool Coordinate Movement
            # Note: set_tool_position usually takes cartesian tool frame deltas.
            ret = self.arm.set_tool_position(x=pose[0], y=pose[1], z=pose[2],
                                             roll=pose[3], pitch=pose[4], yaw=pose[5],
                                             speed=self.SPEED, acc=self.ACC, wait=True)
        else:
            # Absolute Move (Base Coordinate)
            ret = self.arm.set_position(x=pose[0], y=pose[1], z=pose[2],
                                        roll=pose[3], pitch=pose[4], yaw=pose[5],
                                        speed=self.SPEED, acc=self.ACC, wait=True, relative=False)
        
        # User requested: Wait for value after motion
        time.sleep(0.5)
        
        if ret < 0:
            self.get_logger().error(f'Move Pose Failed: {ret}. Clearing Error...')
            self.arm.clean_error()
            self.arm.set_state(0)
            return False
        return True

    def gripper(self, open=True):
        pos = self.GRIP_OPEN_POS if open else self.GRIP_CLOSE_POS
        ret = self.arm.set_gripper_position(pos, wait=True, speed=self.GRIP_SPEED, auto_enable=True)
        if ret < 0:
             self.arm.clean_error()
             return False
        return True

    def get_current_pose(self):
        code, pos = self.arm.get_position()
        if code == 0:
            return pos # [x,y,z,r,p,y]
        return None

    # --- Logic ---
    def process_side_cb(self, request, response):
        self.gripper(open=True)
        # Ignores specific side request, does FULL CYCLE (Left -> Right)
        self.get_logger().info('>>> STARTING HARVEST CYCLE (Left + Right) <<<')
        
        # 1. Left
        if not self._process_single_side(0): 
            self.get_logger().warn('Left Side Interrupted/Failed')
            # Continue to Right anyway? Or stop? usually continue.
        
        # 2. Right
        if not self._process_single_side(1):
             self.get_logger().warn('Right Side Interrupted/Failed')
             
        # 3. Home
        self.move_joints(self.JOINTS_HOME)
        
        response.success = True
        response.message = "Cycle Complete"
        return response

    def _process_single_side(self, side):
        side_str = "LEFT" if side == 0 else "RIGHT"
        self.get_logger().info(f'--- Processing Side: {side_str} ---')
        
        # 1. Rotate Turret
        target_joints = self.JOINTS_LOOK_LEFT if side == 0 else self.JOINTS_LOOK_RIGHT
        if not self.move_joints(target_joints):
            self.get_logger().error("Turret Fail")
            return False
            
        # 2. Capture Vision (Overview)
        self.get_logger().info('Capturing Vision (Overview)...')
        if not self.cli_vision.wait_for_service(timeout_sec=2.0):
             self.get_logger().error("Vision Timeout")
             return False
             
        req_vis = CaptureVision.Request(); req_vis.mode = 0
        req_vis.initial_pose = [0.0, 0.0, 0.0]
        res_vis = self.cli_vision.call(req_vis) 
        
        if not res_vis.success or not res_vis.tags:
            self.get_logger().info(f'No Items Found on {side_str}.')
            return True # Not an error, just empty
            
        tags = res_vis.tags
        xs, ys, zs = res_vis.poses_x, res_vis.poses_y, res_vis.poses_z
        
        self.get_logger().info(f'Found {len(tags)} items on {side_str}.')
        
        for k in range(len(tags)):
            tag = tags[k]
            
            # 3. MAPPING
            cam_lat = xs[k]
            cam_vert = ys[k]
            cam_depth = zs[k]
            
            # Map Raw Vision to Tool Frame Deltas WITH OFFSETS
            # Depth -> Z
            # Lat -> X
            # Vert -> Y
            move_z = cam_depth - self.gripper_offset_depth
            if move_z < 0: move_z = 0
            
            move_x = cam_lat - self.gripper_offset_width
            # Check if negative ok? Relative move can be negative.
            # test_approach.py: if lat-width > 0 else 0. 
            # Actually test_approach logic was:
            # move_y = lat - width if lat - width > 0 else 0
            # Wait, lat (x in vision) can be negative? 
            # In test_approach, it seemed to assume positive range or handle it. 
            # Let's trust test_approach logic:
            if move_x < 0: move_x = 0 
            
            move_y = cam_vert + self.gripper_offset_height
            if move_y < 0: move_y = 0
            
            self.get_logger().info(f'[{tag}] (Overview) Appr Tool: X={move_x:.1f}, Y={move_y:.1f}, Z={move_z:.1f}')
            
            # Move Approach
            if not self.move_pose([move_x, move_y, move_z, 0,0,0], relative=True):
                self.get_logger().warn('Approach Failed. Skipping Item.')
                continue

            # 4. Refine (Vision Detail)
            # We are now at Approach point.
            # We pass the OLD center to find the ID (since ID comes from cached overview).
            req_refine = CaptureVision.Request(); req_refine.mode = 1
            req_refine.initial_pose = [cam_lat, cam_vert, cam_depth] 
            res_refine = self.cli_vision.call(req_refine)
            
            if res_refine.success and res_refine.poses_x:
                # Refine Move
                r_lat = res_refine.poses_x[0]
                r_vert = res_refine.poses_y[0]
                r_depth = res_refine.poses_z[0]
                
                # Apply SAME Offsets
                r_z = r_depth - self.gripper_offset_depth
                if r_z < 0: r_z = 0
                
                r_x = r_lat - self.gripper_offset_width
                if r_x < 0: r_x = 0
                
                r_y = r_vert + self.gripper_offset_height
                if r_y < 0: r_y = 0
                
                self.get_logger().info(f'[{tag}] (Refine) Tool: X={r_x:.1f}, Y={r_y:.1f}, Z={r_z:.1f}')
                if not self.move_pose([r_x, r_y, r_z, 0,0,0], relative=True):
                    self.get_logger().warn('Refine Move Failed. Skipping Item.')
                    self.move_pose([0, 0, -300, 0, 0, 0], relative=True) # Retreat
                    continue
            else:
                self.get_logger().warn('Refine Vision Failed. Skipping Item...')
                self.move_pose([0, 0, -300, 0, 0, 0], relative=True)
                continue

            # 5. Grasp
            if not self.gripper(open=False):
                self.get_logger().warn('Grasp Failed. Skipping Item.')
                self.move_pose([0, 0, -300, 0, 0, 0], relative=True)
                continue
            
            # 6. Retreat (Up/Back)
            self.get_logger().info('Retreating...')
            # Retreat in Z (Back out)
            self.move_pose([0, 0, -300, 0, 0, 0], relative=True)
            
            # 7. Get Drop Pose
            req_drop = GetDropPose.Request(); req_drop.tag = tag
            if self.cli_drop.wait_for_service(timeout_sec=1.0):
                res_drop = self.cli_drop.call(req_drop)
                d_x, d_y, d_z = res_drop.x, res_drop.y, res_drop.z
                
                self.get_logger().info(f'Placing at: {d_x}, {d_y}, {d_z}')
                
                # Sequence: Appr -> Down -> Open -> Up
                ok1 = self.move_pose([d_x, d_y, d_z + 50, 180, 0, 0], relative=False)
                ok2 = self.move_pose([d_x, d_y, d_z, 180, 0, 0], relative=False)
                self.gripper(open=True)
                ok3 = self.move_pose([d_x, d_y, d_z + 50, 180, 0, 0], relative=False)
                
                if not (ok1 and ok2 and ok3):
                     self.get_logger().error('Placement Sequence Partial Fail')
            else:
                self.get_logger().error('GetDropPose Service failed')
                self.gripper(open=True)

            # Return to Turret position for next item
            self.move_joints(target_joints)
            
        return True

def main(args=None):
    rclpy.init(args=args)
    node = XArmPoseNode()
    
    executor = MultiThreadedExecutor()
    executor.add_node(node)
    
    try:
        executor.spin()
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
