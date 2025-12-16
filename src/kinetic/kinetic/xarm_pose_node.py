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
        self.SPEED = 50
        self.ACC = 100
        
        # Gripper
        self.GRIP_CLOSE_POS = 0
        self.GRIP_OPEN_POS = 300
        self.GRIP_SPEED = 5000
        
        # Offsets (From test_approach.py)
        self.gripper_offset_depth = 220
        self.gripper_offset_height = 90
        self.gripper_offset_width = 0

        # Joint Poses
        self.JOINTS_LOOK_LEFT  = [90, -105, -80, 0, 95, 0]
        self.JOINTS_LOOK_RIGHT = [-90, -105, -80, 0, 95, 0]
        self.JOINTS_HOME = [-180, -90, -60, 175, 120, 0]

        # Connect xArm
        self.arm = self._connect_arm()
        self.get_logger().info("Xarm Connected!!!")
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
        if ret != 0:
            self.get_logger().error(f'Move Joints Failed: {ret}')
            self.arm.clean_error() # Ensure error cleared here too
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
        
        if ret != 0:
            self.get_logger().error(f'Move Pose Failed: {ret}. Clearing Error...')
            self.arm.clean_error()
            self.arm.set_state(0)
            return False
        return True

    def gripper(self, open=True):
        pos = self.GRIP_OPEN_POS if open else self.GRIP_CLOSE_POS
        ret = self.arm.set_gripper_position(pos, wait=True, speed=self.GRIP_SPEED, auto_enable=True)
        if ret != 0:
             self.get_logger().error(f'Gripper Failed: {ret}')
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
        
        # 2. Right
        if not self._process_single_side(1):
             self.get_logger().warn('Right Side Interrupted/Failed')

        # 1. Left
        #if not self._process_single_side(0): 
        #    self.get_logger().warn('Left Side Interrupted/Failed')
            # Continue to Right anyway? Or stop? usually continue.
        

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
            
            # --- ABSOLUTE ROBOT COORDINATES (No Mapping Needed) ---
            # API returns Robot Frame X, Y, Z directly.
            t_x = xs[k]
            t_y = ys[k]
            t_z = zs[k]
            
            # Safety Check: Invalid Depth
            if t_z > 1500: # 1.5m
                self.get_logger().error(f"[{tag}] Invalid Z {t_z:.1f}mm (>1.5m). Skipping.")
                continue

            # Approach Height Override?
            # t_z is the actual item height. We want to hover ABOVE it.
            # 2-Stage Relative Approach Logic (Tool Coordinate)
            # User requirement: "Relative vision move", "Tool Coordinate"
            # Mapping: X=Vert, Y=Horz, Z=Depth
            
            # Vision returns Deltas from Image Center (Tool Center)
            # t_x (Vert), t_y (Horz), t_z (Depth)
            
            self.get_logger().info(f'[{tag}] Stage 1 Relative Align: X={t_x:.1f}, Y={t_y:.1f} (Z={t_z:.1f} ignored)')
            
            # STAGE 1 MOVE: Align X (Vert) and Y (Horz) relative
            # We assume Vision X/Y aligns with Tool X/Y axes directions
            if not self.move_pose([t_x, t_y, 0, 0, 0, 0], relative=True):
                self.get_logger().warn('Stage 1 Align Failed. Skipping.')
                continue

            # 4. Refine (Vision Detail)
            # We are now Aligned. Call Refine.
            req_refine = CaptureVision.Request(); req_refine.mode = 1
            # Initial pose hint is less relevant for relative, but passing zero or estimated depth might help?
            # Passing [0,0, t_z] as hint of depth remaining?
            req_refine.initial_pose = [0.0, 0.0, t_z] 
            res_refine = self.cli_vision.call(req_refine)
            
            final_x, final_y, final_z = t_x, t_y, t_z # Default if fail
            
            if res_refine.success and res_refine.poses_x:
                # Refine Success
                final_x = res_refine.poses_x[0]
                final_y = res_refine.poses_y[0]
                final_z = res_refine.poses_z[0]
                self.get_logger().info(f'[{tag}] Refined Relative Target: X={final_x:.1f}, Y={final_y:.1f}, Z={final_z:.1f}')
            else:
                self.get_logger().warn('Refine Vision Failed. Using Last Estimated Depth.')
            
            # 5. Grasp Sequence
            # STAGE 2 MOVE: Go to Grasp Point (Relative Z + residual X/Y)
            
            self.get_logger().info(f'Approaching Grasp Point (Rel Z={final_z:.1f})...')
            if not self.move_pose([final_x, final_y, final_z, 0, 0, 0], relative=True):
                 self.get_logger().warn('Grasp Approach Failed. Retreating.')
                 self.move_pose([0, 0, -100, 0, 0, 0], relative=True) # Retreat Back relative
                 continue
                 
            # Close Gripper
            if not self.gripper(open=False):
                self.get_logger().warn('Grasp Failed.')
            
            # 6. Retreat (Back Relative 200mm)
            self.get_logger().info('Retreating (Back 200mm)...')
            self.move_pose([0, 0, -200.0, 0, 0, 0], relative=True)
            
            # 7. Get Drop Pose (Absolute)
            # NOTE: GetDropPose returns Absolute Base Coordinates? Or Relative?
            # Usually Drop is fixed absolute location.
            req_drop = GetDropPose.Request(); req_drop.tag = tag
            if self.cli_drop.wait_for_service(timeout_sec=1.0):
                res_drop = self.cli_drop.call(req_drop)
                d_x, d_y, d_z = res_drop.x, res_drop.y, res_drop.z
                
                self.get_logger().info(f'Placing at (Abs): {d_x}, {d_y}, {d_z}')
                
                # Move to Drop (Absolute)
                # Sequence: Up/Safe -> Drop -> Open -> Up
                
                # First, Move to Safe Transport Height (Absolute Z=400?)
                # We need to know where we are or just command absolute.
                # Sequence: Appr (240mm) -> Pre-Drop(dz+15) -> Drop (dz) -> Open -> Up (240mm)
                # User req: "Z only 15 high wait"
                
                # 1. Safe Height
                ok1 = self.move_pose([d_x, d_y, 240.0, 180, 0, 0], relative=False)
                # 2. Pre-Drop (Wait)
                self.get_logger().info('Pre-Drop Wait (Z+15mm)...')
                ok2 = self.move_pose([d_x, d_y, d_z + 15.0, 180, 0, 0], relative=False)
                # 3. Drop
                self.get_logger().info('Dropping...')
                ok3 = self.move_pose([d_x, d_y, d_z, 180, 0, 0], relative=False)
                
                self.gripper(open=True)
                
                # 4. Up
                ok4 = self.move_pose([d_x, d_y, 240.0, 180, 0, 0], relative=False)
                
                if not (ok1 and ok2 and ok3 and ok4):
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