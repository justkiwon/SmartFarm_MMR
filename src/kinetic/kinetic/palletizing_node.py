#!/usr/bin/env python3
import time
import socket
import rclpy
from rclpy.node import Node
from rclpy.action import ActionServer

# Interfaces
from mmr_interfaces.action import PickAndPlace
from mmr_interfaces.srv import RotateTurret, GetDropPose, MoveArm

# Note: We now talk to xarm_pose_server_min.py via TCP, so no direct SDK needed here.

class PalletizingNode(Node):
    """
    Slot Manager Node
    Provides: kinetic/get_drop_pose
    """
    # Pallet Slots (4x5 grid below HOME)
    # Grid spacing: 50mm
    PALLET_START_X = 100.0  # mm
    PALLET_START_Y = -150.0  # mm
    PALLET_START_Z = 50.0    # mm
    PALLET_SPACING_X = 60.0
    PALLET_SPACING_Y = 60.0
    
    pallet_index = 0

    def __init__(self):
        super().__init__('palletizing_node')
        
        self.srv_drop = self.create_service(
            GetDropPose, 'kinetic/get_drop_pose', self.drop_pose_cb
        )
        self.get_logger().info('PalletizingNode (Slot Manager) Ready')

    def drop_pose_cb(self, request, response):
        """ Calculate where to put the object in 4x5 grid """
        row = self.pallet_index // 5
        col = self.pallet_index % 5
        self.pallet_index += 1
        
        if self.pallet_index >= 20: 
            self.pallet_index = 0
        
        drop_x = self.PALLET_START_X + col * self.PALLET_SPACING_X
        drop_y = self.PALLET_START_Y + row * self.PALLET_SPACING_Y
        drop_z = self.PALLET_START_Z
        
        response.x = drop_x
        response.y = drop_y
        response.z = drop_z
        self.get_logger().info(f'[DropPose] Slot [{row},{col}] -> ({drop_x:.1f}, {drop_y:.1f}, {drop_z:.1f})')
        return response

def main(args=None):
    rclpy.init(args=args)
    node = PalletizingNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt: pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
