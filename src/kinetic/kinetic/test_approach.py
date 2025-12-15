#!/usr/bin/env python3
import sys
import time
import requests
import numpy as np

# Add xArm SDK path
sys.path.append('/home/pandora/dev/strawberry/shared/venvs/.venv_production/lib/python3.10/site-packages')
from xarm.wrapper import XArmAPI

class IndependentVisionTest:
    def __init__(self, robot_ip='192.168.10.217', api_url='http://127.0.0.1:8000'):
        self.api_url = api_url
        self.robot_ip = robot_ip
        self.arm = self._connect_arm()
        self.last_detections = []
        self.JOINTS_LOOK_LEFT  = [90, -60, -13, 0, -15, 0]
        self.JOINTS_LOOK_RIGHT = [-90, -60, -13, 0, -15, 0]
        self.JOINTS_HOME = [0, -50, -20, 0, -20, 0]
        self.gripper_offset_depth = 220
        self.gripper_offset_height = 90
        self.gripper_offset_width = 50 # +50만큼 편향 됨

    def _connect_arm(self):
        print(f"Connecting to Robot: {self.robot_ip}")
        try:
            arm = XArmAPI(self.robot_ip)
            arm.motion_enable(True)
            arm.clean_warn()
            arm.clean_error()
            arm.set_mode(0)
            arm.set_state(0)
            time.sleep(1.0)
            return arm
        except Exception as e:
            print(f"Failed to connect: {e}")
            sys.exit(1)

    def trigger_detect(self):
        print("Calling Vision API (Overview)...")
        try:
            resp = requests.post(f"{self.api_url}/api/inference/detect", timeout=10)
            resp.raise_for_status()
            data = resp.json()
            targets = data.get("targets", [])
            
            self.last_detections = []
            results = []
            for i, coord in enumerate(targets):
                obj = {"id": i + 1, "center_mm": coord}
                self.last_detections.append(obj)
                results.append(obj)
            return results
        except Exception as e:
            print(f"Vision call failed: {e}")
            return []

    def trigger_grasp(self, target_id):
        print(f"Calling Vision API (Detail) for ID {target_id}...")
        try:
            resp = requests.post(f"{self.api_url}/api/inference/grasp/{target_id}", timeout=10)
            resp.raise_for_status()
            data = resp.json()
            return data.get("target") # [x,y,z]
        except Exception as e:
            print(f"Detail call failed: {e}")
            return None

    def find_target_id(self, input_pos):
        # find closest ID from last detections
        # input_pos is [x,y,z] (where we moved to)
        # But wait, Vision returns Camera Relative? Or Base Relative? 
        # Vision Node says: "Raw(mm): [x,y,z]". 
        # Usually Vision returns Camera Frame coordinates.
        # But `find_closest_target` in strawberry_client uses cached detections.
        # Cached detections are in Camera Frame of OVERVIEW.
        # When we move, the frame changes? 
        # Ah, the API `grasp/{id}` re-detects? Or uses cached?
        # If we moved closer, the coordinates change!
        # `vision_capture_node` re-calls `trigger_grasp(target_id)`.
        # Does the API handle the new image? Yes.
        # But how does it know which object is which if we moved?
        # `find_closest_target` uses `target_pose_m` (converted to mm) to match against `last_detections`?
        # If we moved, the coordinates in Camera Frame are DIFFERENT.
        # Unless `last_detections` are in Base Frame? 
        # No, `vision_capture_node` prints Raw(mm).
        # We need to trust the ID? Or does `detect` return IDs that persist?
        # `strawberry_client` Logic:
        # `find_closest_target` takes `target_pos` (Where we REQUESTED detail for? Or where we ARE?).
        # In `vision_capture_node`: `target_pos = init_pose` sent by Orchestrator.
        # Orchestrator sent `[0,0,0]` in our fix.
        # So `find_closest_target` looks for closest to `0,0,0`?
        # And `last_detections` are from Overview.
        # If `last_detections` has item at `370` z.
        # `0,0,0` is far?
        # This Logic seems flawed if we use `0,0,0`.
        # BUT for this test script, we can just use index or re-detect?
        # Let's match logic of `vision_capture_node`: It finds ID from `last_detections`. 
        # If we pass 0,0,0, it finds closest to 0,0,0 (Object 2 in log: 22, -5, 389).
        # We want the object we just approached?
        # We should pass the coordinate of the object we just processed!
        return self._find_closest_internal(input_pos)

    def _find_closest_internal(self, pos):
        # simple dist
        if not self.last_detections: return None
        pos = np.array(pos)
        best = None
        min_d = float('inf')
        for d in self.last_detections:
            dist = np.linalg.norm(np.array(d['center_mm']) - pos)
            if dist < min_d:
                min_d = dist
                best = d['id']
        return best

    def move_joints(self, joints):
        print(f"  [Move Joints] {joints}")
        ret = self.arm.set_servo_angle(angle=joints, speed=50, wait=True)
        if ret < 0:
            print("  Move Joints Failed.")
            self.arm.clean_error()
            return False
        return True

    def move_tool(self, x, y, z):
        print(f"  [Move] Tool Command: X={x:.1f}, Y={y:.1f}, Z={z:.1f}, wait=True")
        ret = self.arm.set_tool_position(x=x, y=y, z=z, speed=100, acc=1000, wait=True)
        if ret < 0:
            print("  Move Error. Cleaning...")
            self.arm.clean_error()
            self.arm.set_state(0)
            return False
        return True

    
    def run(self):
        print("Starting Test Sequence...")
        
        # Move to Start Position
        print("Moving to Home...")
        self.move_joints(self.JOINTS_HOME)
        time.sleep(0.7)
        print("Moving to Look Left...")
        self.move_joints(self.JOINTS_LOOK_LEFT)
        time.sleep(0.7)
        
        # 1. Overview
        detections = self.trigger_detect()
        if not detections:
            print("No items found.")
            return
        
        print(f"Found {len(detections)} items.")
        
        for i, det in enumerate(detections):
            center = det['center_mm']
            print(f"\n--- Processing Item {i+1} (ID: {det['id']}) ---")
            print(f"  [Vision] Raw: {center}")
            
            depth, lat, vert  = center[2], center[0], center[1]
            
            # MAPPING: 
            # Depth -> Tool Z (Approach)
            # Lat -> Tool Y (Horizontal)
            # Vert -> Tool X (Vertical)
            move_z = depth-self.gripper_offset_depth if depth-self.gripper_offset_depth >0 else 0
            move_y = lat-self.gripper_offset_width if lat-self.gripper_offset_width >0 else 0
            move_x = vert+self.gripper_offset_height if vert+self.gripper_offset_height >0 else 0
            
            print(f"  [Map] Depth({depth})->Z, Lat({lat})->Y, Vert({vert})->X")
            
            # Approach
            if not self.move_tool(move_x, move_y, move_z):
                print("Skipping Item (Approach Fail)")
                continue
            
            # Detail
            # We are now at Approach point.
            # We need to find the ID again. 
            # We pass the OLD center to find the ID (since ID comes from cached overview).
            target_id = self._find_closest_internal(center)
            
            if target_id:
                res = self.trigger_grasp(target_id)
                if res:
                    # Refine
                    r_lat, r_vert, r_depth = res[0], res[1], res[2]
                    print(f"  [Refine Vision] Raw: {res}")
                    
                    ref_z = r_depth - self.gripper_offset_depth if r_depth - self.gripper_offset_depth >0 else 0
                    ref_y = r_lat-self.gripper_offset_width if r_lat-self.gripper_offset_width >0 else 0
                    ref_x = r_vert+self.gripper_offset_height if r_vert+self.gripper_offset_height >0 else 0
                    
                    if not self.move_tool(ref_x, ref_y, ref_z):
                         print("Refine Move Failed. Skipping.")
                         self.move_tool(0, 0, -300)
                         continue
                    
                    # Retreat
                    print("  [Retreat] Moving Z -300")
                    self.move_tool(0, 0, -300) 
            
            else:
                print("Lost Target ID?")
                self.move_tool(0, 0, -300) # Safety retreat

        print("Test Done.")

if __name__ == "__main__":
    test = IndependentVisionTest()
    test.run()
