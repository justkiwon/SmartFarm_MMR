import sys
import os
# Force venv site-packages into sys.path to find cv2/xarm/requests if running with system python
sys.path.insert(0, '/home/pandora/dev/strawberry/shared/venvs/.venv_production/lib/python3.10/site-packages')

import rclpy
from rclpy.node import Node
import numpy as np

# Updated Srv
from mmr_interfaces.srv import CaptureVision

from .strawberry_client import StrawberryClient

class VisionCaptureNode(Node):
    """
    Vision Node using Strawberry Web API
    
    Service: vision/capture_vision
    """
    
    MODE_OVERVIEW = 0
    MODE_DETAIL = 1

    def __init__(self):
        super().__init__('vision_capture_node')
        
        # API Client
        self.client = StrawberryClient(base_url="http://127.0.0.1:8000")

        self.srv = self.create_service(
            CaptureVision, 'vision/capture_vision', self.capture_cb
        )

        self.get_logger().info('VisionCaptureNode (API Wrapper) Ready')

    def capture_cb(self, request, response):
        """
        Service Callback
        """
        response.success = True
        
        if request.mode == self.MODE_OVERVIEW:
            self.run_api_overview(response)
        elif request.mode == self.MODE_DETAIL:
            self.run_api_detail(request, response)
        else:
            response.success = False
            self.get_logger().warn(f'Unknown mode: {request.mode}')

        return response

    def run_api_overview(self, response):
        """
        Call API /api/inference/detect
        """
        self.get_logger().info('[Vision] Calling API Detect (Overview)...')
        
        detections = self.client.trigger_detect()
        
        if not detections:
            self.get_logger().warn('[Vision] No detections returned from API.')
            response.num_objects = 0
            return

        response.num_objects = len(detections)
        
        poses_x = []
        poses_y = []
        poses_z = []
        tags = []
        
        for i, det in enumerate(detections):
            center_mm = det['center_mm']
            # Keep in mm (no conversion needed)
            x = center_mm[0]
            y = center_mm[1]
            z = center_mm[2]
            
            self.get_logger().info(f'  [Obj #{i+1}] Raw(mm): {center_mm}')
            
            poses_x.append(x)
            poses_y.append(y)
            poses_z.append(z)
            # Default tag since API doesn't provide class labels in this endpoint yet
            tags.append(f"item_{i+1}")
            
        response.poses_x = poses_x
        response.poses_y = poses_y
        response.poses_z = poses_z
        response.tags = tags
        
        self.get_logger().info(f'[Vision] Found {len(detections)} objects.')

    def run_api_detail(self, request, response):
        """
        Call API /api/inference/grasp/{id}
        """
        init_pose = request.initial_pose
        if hasattr(init_pose, 'position'):
            target_pos = (init_pose.position.x, init_pose.position.y, init_pose.position.z)
        else:
            # It's likely a list/tuple/array from the service request
            try:
                target_pos = (float(init_pose[0]), float(init_pose[1]), float(init_pose[2]))
            except (IndexError, TypeError, ValueError) as e:
                self.get_logger().error(f'[Vision] Invalid initial_pose format: {init_pose} ({e})')
                response.success = False
                return

        self.get_logger().info(f'[Vision] Doing Detail Analysis (Grasp) near {target_pos}')
        
        target_id = self.client.find_closest_target(target_pos)
        
        if target_id is None:
            self.get_logger().error('[Vision] Could not find matching target in cache.')
            response.success = False
            return
            
        self.get_logger().info(f'[Vision] Identify target ID: {target_id}')
        
        grasp_center_mm = self.client.trigger_grasp(target_id)
        
        if grasp_center_mm is None:
             self.get_logger().error(f'[Vision] Grasp detection failed for ID {target_id}')
             response.success = False
             return
             
        # Keep in mm
        gx = grasp_center_mm[0]
        gy = grasp_center_mm[1]
        gz = grasp_center_mm[2]
        
        response.num_objects = 1
        response.poses_x = [gx]
        response.poses_y = [gy]
        response.poses_z = [gz]
        response.tags = ["verified_item"]
        
        self.get_logger().info(f'[Vision] Grasp point refined: ({gx:.1f}, {gy:.1f}, {gz:.1f}) mm')

def main(args=None):
    rclpy.init(args=args)
    node = VisionCaptureNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
