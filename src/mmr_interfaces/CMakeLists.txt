cmake_minimum_required(VERSION 3.8)
project(mmr_interfaces)

find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(sensor_msgs REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
  "srv/MoveDistance.srv"
  "srv/CaptureVision.srv"
  "srv/GetDropPose.srv"
  "srv/RotateTurret.srv"
  "action/Palletize.action"
  "action/PickAndPlace.action"
  DEPENDENCIES sensor_msgs
)

ament_export_dependencies(rosidl_default_runtime)
ament_package()
