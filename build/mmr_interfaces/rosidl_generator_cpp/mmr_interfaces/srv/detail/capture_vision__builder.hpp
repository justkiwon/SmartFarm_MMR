// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from mmr_interfaces:srv/CaptureVision.idl
// generated code does not contain a copyright notice

#ifndef MMR_INTERFACES__SRV__DETAIL__CAPTURE_VISION__BUILDER_HPP_
#define MMR_INTERFACES__SRV__DETAIL__CAPTURE_VISION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "mmr_interfaces/srv/detail/capture_vision__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace mmr_interfaces
{

namespace srv
{

namespace builder
{

class Init_CaptureVision_Request_initial_pose
{
public:
  explicit Init_CaptureVision_Request_initial_pose(::mmr_interfaces::srv::CaptureVision_Request & msg)
  : msg_(msg)
  {}
  ::mmr_interfaces::srv::CaptureVision_Request initial_pose(::mmr_interfaces::srv::CaptureVision_Request::_initial_pose_type arg)
  {
    msg_.initial_pose = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mmr_interfaces::srv::CaptureVision_Request msg_;
};

class Init_CaptureVision_Request_mode
{
public:
  Init_CaptureVision_Request_mode()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CaptureVision_Request_initial_pose mode(::mmr_interfaces::srv::CaptureVision_Request::_mode_type arg)
  {
    msg_.mode = std::move(arg);
    return Init_CaptureVision_Request_initial_pose(msg_);
  }

private:
  ::mmr_interfaces::srv::CaptureVision_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::mmr_interfaces::srv::CaptureVision_Request>()
{
  return mmr_interfaces::srv::builder::Init_CaptureVision_Request_mode();
}

}  // namespace mmr_interfaces


namespace mmr_interfaces
{

namespace srv
{

namespace builder
{

class Init_CaptureVision_Response_tags
{
public:
  explicit Init_CaptureVision_Response_tags(::mmr_interfaces::srv::CaptureVision_Response & msg)
  : msg_(msg)
  {}
  ::mmr_interfaces::srv::CaptureVision_Response tags(::mmr_interfaces::srv::CaptureVision_Response::_tags_type arg)
  {
    msg_.tags = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mmr_interfaces::srv::CaptureVision_Response msg_;
};

class Init_CaptureVision_Response_poses_z
{
public:
  explicit Init_CaptureVision_Response_poses_z(::mmr_interfaces::srv::CaptureVision_Response & msg)
  : msg_(msg)
  {}
  Init_CaptureVision_Response_tags poses_z(::mmr_interfaces::srv::CaptureVision_Response::_poses_z_type arg)
  {
    msg_.poses_z = std::move(arg);
    return Init_CaptureVision_Response_tags(msg_);
  }

private:
  ::mmr_interfaces::srv::CaptureVision_Response msg_;
};

class Init_CaptureVision_Response_poses_y
{
public:
  explicit Init_CaptureVision_Response_poses_y(::mmr_interfaces::srv::CaptureVision_Response & msg)
  : msg_(msg)
  {}
  Init_CaptureVision_Response_poses_z poses_y(::mmr_interfaces::srv::CaptureVision_Response::_poses_y_type arg)
  {
    msg_.poses_y = std::move(arg);
    return Init_CaptureVision_Response_poses_z(msg_);
  }

private:
  ::mmr_interfaces::srv::CaptureVision_Response msg_;
};

class Init_CaptureVision_Response_poses_x
{
public:
  explicit Init_CaptureVision_Response_poses_x(::mmr_interfaces::srv::CaptureVision_Response & msg)
  : msg_(msg)
  {}
  Init_CaptureVision_Response_poses_y poses_x(::mmr_interfaces::srv::CaptureVision_Response::_poses_x_type arg)
  {
    msg_.poses_x = std::move(arg);
    return Init_CaptureVision_Response_poses_y(msg_);
  }

private:
  ::mmr_interfaces::srv::CaptureVision_Response msg_;
};

class Init_CaptureVision_Response_num_objects
{
public:
  explicit Init_CaptureVision_Response_num_objects(::mmr_interfaces::srv::CaptureVision_Response & msg)
  : msg_(msg)
  {}
  Init_CaptureVision_Response_poses_x num_objects(::mmr_interfaces::srv::CaptureVision_Response::_num_objects_type arg)
  {
    msg_.num_objects = std::move(arg);
    return Init_CaptureVision_Response_poses_x(msg_);
  }

private:
  ::mmr_interfaces::srv::CaptureVision_Response msg_;
};

class Init_CaptureVision_Response_success
{
public:
  Init_CaptureVision_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CaptureVision_Response_num_objects success(::mmr_interfaces::srv::CaptureVision_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_CaptureVision_Response_num_objects(msg_);
  }

private:
  ::mmr_interfaces::srv::CaptureVision_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::mmr_interfaces::srv::CaptureVision_Response>()
{
  return mmr_interfaces::srv::builder::Init_CaptureVision_Response_success();
}

}  // namespace mmr_interfaces

#endif  // MMR_INTERFACES__SRV__DETAIL__CAPTURE_VISION__BUILDER_HPP_
