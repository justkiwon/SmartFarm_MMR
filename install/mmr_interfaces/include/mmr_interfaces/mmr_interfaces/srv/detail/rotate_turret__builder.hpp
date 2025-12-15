// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from mmr_interfaces:srv/RotateTurret.idl
// generated code does not contain a copyright notice

#ifndef MMR_INTERFACES__SRV__DETAIL__ROTATE_TURRET__BUILDER_HPP_
#define MMR_INTERFACES__SRV__DETAIL__ROTATE_TURRET__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "mmr_interfaces/srv/detail/rotate_turret__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace mmr_interfaces
{

namespace srv
{

namespace builder
{

class Init_RotateTurret_Request_direction
{
public:
  Init_RotateTurret_Request_direction()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::mmr_interfaces::srv::RotateTurret_Request direction(::mmr_interfaces::srv::RotateTurret_Request::_direction_type arg)
  {
    msg_.direction = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mmr_interfaces::srv::RotateTurret_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::mmr_interfaces::srv::RotateTurret_Request>()
{
  return mmr_interfaces::srv::builder::Init_RotateTurret_Request_direction();
}

}  // namespace mmr_interfaces


namespace mmr_interfaces
{

namespace srv
{

namespace builder
{

class Init_RotateTurret_Response_message
{
public:
  explicit Init_RotateTurret_Response_message(::mmr_interfaces::srv::RotateTurret_Response & msg)
  : msg_(msg)
  {}
  ::mmr_interfaces::srv::RotateTurret_Response message(::mmr_interfaces::srv::RotateTurret_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mmr_interfaces::srv::RotateTurret_Response msg_;
};

class Init_RotateTurret_Response_current_pose
{
public:
  explicit Init_RotateTurret_Response_current_pose(::mmr_interfaces::srv::RotateTurret_Response & msg)
  : msg_(msg)
  {}
  Init_RotateTurret_Response_message current_pose(::mmr_interfaces::srv::RotateTurret_Response::_current_pose_type arg)
  {
    msg_.current_pose = std::move(arg);
    return Init_RotateTurret_Response_message(msg_);
  }

private:
  ::mmr_interfaces::srv::RotateTurret_Response msg_;
};

class Init_RotateTurret_Response_success
{
public:
  Init_RotateTurret_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RotateTurret_Response_current_pose success(::mmr_interfaces::srv::RotateTurret_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_RotateTurret_Response_current_pose(msg_);
  }

private:
  ::mmr_interfaces::srv::RotateTurret_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::mmr_interfaces::srv::RotateTurret_Response>()
{
  return mmr_interfaces::srv::builder::Init_RotateTurret_Response_success();
}

}  // namespace mmr_interfaces

#endif  // MMR_INTERFACES__SRV__DETAIL__ROTATE_TURRET__BUILDER_HPP_
