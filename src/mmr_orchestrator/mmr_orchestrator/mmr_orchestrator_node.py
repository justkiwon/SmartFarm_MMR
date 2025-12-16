#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient

# Interfaces
from mmr_interfaces.srv import MoveDistance, CaptureVision, GetDropPose, RotateTurret, MoveArm, ProcessSide
from mmr_interfaces.action import PickAndPlace
import numpy as np
import threading
import time

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
        total_dist = self.get_parameter('total_distance').value
        self.total_steps = int(total_dist / self.step_dist)

        # Palletizing grid tracking (4x5)
        self.pallet_row = 0
        self.pallet_col = 0
        self.PALLET_ROWS = 4
        self.PALLET_COLS = 5

        # Clients
        self.cli_amr = self.create_client(MoveDistance, 'amr/move_distance')
        self.cli_process = self.create_client(ProcessSide, 'mmr/process_side')
        
        self.get_logger().info('Orchestrator Ready. Waiting for services...')
        
        # Wait for Critical Services
        while not self.cli_amr.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Waiting for AMR service...')
        
        # Wait for ProcessSide (xArm Node)
        while not self.cli_process.wait_for_service(timeout_sec=1.0):
             self.get_logger().info('Waiting for ProcessSide (xArm) service...')

        self.get_logger().info('All Services Connected!')

    def on_start(self):
        """ Start the detailed sequence in a thread """
        t = threading.Thread(target=self.run_sequence)
        t.start()
        
    def run_sequence(self):
        self.get_logger().info('>>> MMR MISSION START (Orchestrated Flow) <<<')
        
        # Steps
        steps = []
        # Run Loop until 5m reached
        total_covered = 0.0
        target_total = 5.0 # meters
        step_len_m = 0.5   # meters (50cm)
        step_len_cm = 50.0 # used for service
        
        while total_covered < target_total:
            self.get_logger().info(f'=== LOOP START (Covered: {total_covered} / {target_total} m) ===')
            
             # 1. Process Cycle (Left + Right + Palletize checked internally by Robot)
            self.get_logger().info('[Orchestrator] Step A: PROCESSING CYCLE (Left -> Right)')
            self.process_side(0) # This now triggers the FULL cycle in xarm_pose_node
            # Wait is implied by service call blocking
            
            time.sleep(1.0)
            
            # 2. Move AMR (50cm)
            if total_covered + step_len_m <= target_total:
                self.get_logger().info('[Orchestrator] Step B: AMR MOVE (50cm)')
                # amr_move_node expects METERS. It converts to cm.
                # 0.5m -> 50cm.
                if self.call_amr(step_len_m):
                    self.get_logger().info('  AMR Move Success')
                    total_covered += step_len_m
                else:
                    self.get_logger().error('  AMR Move Failed!')
                    break
            else:
                self.get_logger().info('  Target Distance Reached. Stopping.')
                break
                
            time.sleep(1.0)
            time.sleep(1.0)
            
        self.get_logger().info('>>> MISSION COMPLETE <<<')

    def process_side(self, side_idx):
        # Trigger the xArm Node to process the side
        self.get_logger().info(f'[Orchestrator] Triggering Process Side: {side_idx}')
        if self.call_process_side(side_idx):
            self.get_logger().info('  -> Side Complete.')
        else:
            self.get_logger().error('  -> Side Failed.')

    # --- Client Wrappers (Running in Mission Thread) ---
    def call_amr(self, dist):
        req = MoveDistance.Request(); req.distance = float(dist)
        res = self.cli_amr.call(req)
        return res.success

    def call_process_side(self, side):
        req = ProcessSide.Request(); req.side = side # 0=Left, 1=Right
        future = self.cli_process.call_async(req)
        # Block until done
        rclpy.spin_until_future_complete(self, future)
        return future.result().success
        
    def get_next_pallet_slot(self):
        """Get next pallet coordinates in 4x5 grid (row, col) and increment"""
        row = self.pallet_row
        col = self.pallet_col
        
        # Increment for next time
        self.pallet_col += 1
        if self.pallet_col >= self.PALLET_COLS:
            self.pallet_col = 0
            self.pallet_row += 1
            if self.pallet_row >= self.PALLET_ROWS:
                self.pallet_row = 0  # Wrap around
        
        return row, col
    
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