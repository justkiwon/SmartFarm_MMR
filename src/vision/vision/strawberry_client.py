import requests
import logging
import numpy as np

class StrawberryClient:
    def __init__(self, base_url="http://127.0.0.1:8000"):
        self.base_url = base_url.rstrip('/')
        self.logger = logging.getLogger('StrawberryClient')
        # Cache detections to map 3D pose to ID for grasp
        self.last_detections = [] 

    def trigger_detect(self):
        """
        Calls POST /api/inference/detect
        Returns: list of dicts with 'center_mm' (x,y,z in mm)
        API Response: [[x,y,z], ...] (List of lists) or {'targets': [[x,y,z], ...]}
        """
        url = f"{self.base_url}/api/inference/detect"
        try:
            resp = requests.post(url, timeout=10)
            resp.raise_for_status()
            data = resp.json()
            
            targets = []
            if isinstance(data, list):
                # Direct list of coordinates
                targets = data
            elif isinstance(data, dict):
                # Wrapped in dict
                targets = data.get("targets", [])
            
            self.last_detections = []
            results = []
            
            for i, coord in enumerate(targets):
                # coord is [x, y, z] in mm
                if not isinstance(coord, list) or len(coord) < 3:
                     continue
                     
                obj = {
                    "id": i + 1, # 1-based index for API
                    "center_mm": coord
                }
                self.last_detections.append(obj)
                results.append(obj)
                
            return results
            
        except requests.RequestException as e:
            self.logger.error(f"Failed to trigger detection: {e}")
            return []

    def trigger_grasp(self, target_id):
        """
        Calls POST /api/inference/grasp/{target_id}
        Returns: [x,y,z] in mm
        API Response: [x,y,z] or {'target': [x,y,z]}
        """
        url = f"{self.base_url}/api/inference/grasp/{target_id}"
        try:
            resp = requests.post(url, timeout=10)
            resp.raise_for_status()
            data = resp.json()
            
            if isinstance(data, list) and len(data) >= 3:
                 return data
            elif isinstance(data, dict):
                 return data.get("target")
            
            return None
        except requests.RequestException as e:
            self.logger.error(f"Failed to trigger grasp for id {target_id}: {e}")
            return None

    def find_closest_target(self, target_pose_m):
        """
        Finds the closest target ID from the cache based on 3D distance.
        target_pose_m: (x, y, z) tuple in meters
        Returns: target_id (int) or None
        """
        if not self.last_detections:
            return None
            
        tx, ty, tz = target_pose_m
        t_mm = np.array([tx * 1000, ty * 1000, tz * 1000])
        
        best_id = None
        min_dist = float('inf')
        
        for det in self.last_detections:
            center = np.array(det['center_mm'])
            dist = np.linalg.norm(center - t_mm)
            if dist < min_dist:
                min_dist = dist
                best_id = det['id']
                
        # Optional: Add a threshold?
        if min_dist > 500: # 50cm tolerance?
            self.logger.warning(f"Closest target is {min_dist}mm away. Might be wrong.")
            
        return best_id
