import sys
import os
# Force venv site-packages into sys.path to find cv2/xarm if running with system python
sys.path.insert(0, '/home/pandora/dev/strawberry/shared/venvs/.venv_production/lib/python3.10/site-packages')

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image, CameraInfo
import numpy as np
import cv2

# Updated Srv
from mmr_interfaces.srv import CaptureVision

class SimpleBridge:
    def imgmsg_to_cv2(self, img_msg, desired_encoding="passthrough"):
        if desired_encoding == "bgr8":
            dtype = np.uint8
            n_channels = 3
        elif desired_encoding == "passthrough":
            if "16UC1" in img_msg.encoding:
                dtype = np.uint16
                n_channels = 1
            elif "8UC3" in img_msg.encoding:
                 dtype = np.uint8
                 n_channels = 3
            else:
                 # Default fallback if unknown, treat as byte array
                 dtype = np.uint8
                 n_channels = 1 # Warning: this might be wrong for complex types
        else:
             dtype = np.uint8
             n_channels = 1

        im = np.ndarray(shape=(img_msg.height, img_msg.width, n_channels),
                           dtype=dtype, buffer=img_msg.data)
        
        # If we need BGR and data is RGB, conversion might be needed, 
        # but usually cameras send what they say.
        # Ideally we should check img_msg.encoding.
        if desired_encoding == "bgr8" and img_msg.encoding == "rgb8":
            im = cv2.cvtColor(im, cv2.COLOR_RGB2BGR)
            
        return im

class VisionCaptureNode(Node):
    """
    Vision Node for RealSense Setup
    
    Subscriptions:
      - /camera/color/image_raw (RGB)
      - /camera/aligned_depth_to_color/image_raw (Depth aligned)
      - /camera/color/camera_info (Intrinsics)
      
    Service: vision/capture_vision
    """
    
    MODE_OVERVIEW = 0
    MODE_DETAIL = 1

    def __init__(self):
        super().__init__('vision_capture_node')
        self.bridge = SimpleBridge()
        
        # Data buffers
        self.color_image = None
        self.depth_image = None
        self.camera_info = None

        # --- RealSense Subscriptions ---
        # 1. Color Image
        self.sub_color = self.create_subscription(
            Image, 
            '/camera/color/image_raw', 
            self.color_cb, 
            10
        )
        
        # 2. Depth Image (Aligned)
        self.sub_depth = self.create_subscription(
            Image, 
            '/camera/aligned_depth_to_color/image_raw', 
            self.depth_cb, 
            10
        )
        
        # 3. Camera Info
        self.sub_info = self.create_subscription(
            CameraInfo, 
            '/camera/color/camera_info', 
            self.info_cb, 
            10
        )

        self.srv = self.create_service(
            CaptureVision, 'vision/capture_vision', self.capture_cb
        )

        self.get_logger().info('VisionCaptureNode (RealSense) Ready')

    def color_cb(self, msg):
        try:
            # Convert ROS Image to OpenCV (BGR)
            self.color_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')
        except Exception as e:
            self.get_logger().error(f'Color conversion error: {e}')

    def depth_cb(self, msg):
        try:
            # Convert ROS Image to OpenCV (16-bit mm or 32-bit float)
            self.depth_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding='passthrough')
        except Exception as e:
            self.get_logger().error(f'Depth conversion error: {e}')

    def info_cb(self, msg):
        self.camera_info = msg
        # We only need info once, but keeping subscription is fine
        
    def capture_cb(self, request, response):
        """
        Service Callback
        """
        # For boilerplate purpose, we just warn if no image, but proceed with dummy for Orchestrator test
        if self.color_image is None or self.depth_image is None:
            self.get_logger().warn('No RealSense frames received yet. Using dummy return.')
            # In production, you might return success=False here.
        
        response.success = True
        
        if request.mode == self.MODE_OVERVIEW:
            self.run_yolo_overview(response)
        elif request.mode == self.MODE_DETAIL:
            self.run_detail_analysis(request, response)
        else:
            response.success = False
            self.get_logger().warn(f'Unknown mode: {request.mode}')

        return response

    def run_yolo_overview(self, response):
        """
        [TODO for Vision Team]
        1. Run YOLO on self.color_image
        2. Get Bounding Boxes & Class IDs
        3. Get Depth at Center of Box from self.depth_image
        4. Deproject Pixel(u,v) + Depth(z) -> Point(x,y,z) using self.camera_info
        5. Fill response
        """
        self.get_logger().info('[Vision] Doing YOLO Overview...')
        
        # --- DUMMY DATA FOR ORCHESTRATOR TEST ---
        response.num_objects = 2
        response.poses_x = [0.35, 0.35] # Forward
        response.poses_y = [0.10, -0.10]
        response.poses_z = [0.0, 0.0]
        response.tags    = ["real_box_A", "real_box_B"]
        # ----------------------------------------

    def run_detail_analysis(self, request, response):
        """
        [TODO for Vision Team]
        1. Crop image around request.initial_pose (projected to pixel)
        2. Do Precision Check (Barcode, OCR, Quality, etc)
        3. Refine 3D Pose
        """
        init_pose = request.initial_pose
        self.get_logger().info(f'[Vision] Doing Detail Analysis on {init_pose}')
        
        # --- DUMMY DATA FOR ORCHESTRATOR TEST ---
        # Refine pose slightly
        response.num_objects = 1
        response.poses_x = [init_pose[0]]
        response.poses_y = [init_pose[1]]
        response.poses_z = [init_pose[2]]
        response.tags    = ["verified_item"]
        # ----------------------------------------

def main(args=None):
    rclpy.init(args=args)
    node = VisionCaptureNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
