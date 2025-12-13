// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from mmr_interfaces:srv/GetDropPose.idl
// generated code does not contain a copyright notice

#ifndef MMR_INTERFACES__SRV__DETAIL__GET_DROP_POSE__BUILDER_HPP_
#define MMR_INTERFACES__SRV__DETAIL__GET_DROP_POSE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "mmr_interfaces/srv/detail/get_drop_pose__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace mmr_interfaces
{

namespace srv
{

namespace builder
{

class Init_GetDropPose_Request_tag
{
public:
  Init_GetDropPose_Request_tag()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::mmr_interfaces::srv::GetDropPose_Request tag(::mmr_interfaces::srv::GetDropPose_Request::_tag_type arg)
  {
    msg_.tag = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mmr_interfaces::srv::GetDropPose_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::mmr_interfaces::srv::GetDropPose_Request>()
{
  return mmr_interfaces::srv::builder::Init_GetDropPose_Request_tag();
}

}  // namespace mmr_interfaces


namespace mmr_interfaces
{

namespace srv
{

namespace builder
{

class Init_GetDropPose_Response_z
{
public:
  explicit Init_GetDropPose_Response_z(::mmr_interfaces::srv::GetDropPose_Response & msg)
  : msg_(msg)
  {}
  ::mmr_interfaces::srv::GetDropPose_Response z(::mmr_interfaces::srv::GetDropPose_Response::_z_type arg)
  {
    msg_.z = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mmr_interfaces::srv::GetDropPose_Response msg_;
};

class Init_GetDropPose_Response_y
{
public:
  explicit Init_GetDropPose_Response_y(::mmr_interfaces::srv::GetDropPose_Response & msg)
  : msg_(msg)
  {}
  Init_GetDropPose_Response_z y(::mmr_interfaces::srv::GetDropPose_Response::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_GetDropPose_Response_z(msg_);
  }

private:
  ::mmr_interfaces::srv::GetDropPose_Response msg_;
};

class Init_GetDropPose_Response_x
{
public:
  explicit Init_GetDropPose_Response_x(::mmr_interfaces::srv::GetDropPose_Response & msg)
  : msg_(msg)
  {}
  Init_GetDropPose_Response_y x(::mmr_interfaces::srv::GetDropPose_Response::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_GetDropPose_Response_y(msg_);
  }

private:
  ::mmr_interfaces::srv::GetDropPose_Response msg_;
};

class Init_GetDropPose_Response_success
{
public:
  Init_GetDropPose_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetDropPose_Response_x success(::mmr_interfaces::srv::GetDropPose_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_GetDropPose_Response_x(msg_);
  }

private:
  ::mmr_interfaces::srv::GetDropPose_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::mmr_interfaces::srv::GetDropPose_Response>()
{
  return mmr_interfaces::srv::builder::Init_GetDropPose_Response_success();
}

}  // namespace mmr_interfaces

#endif  // MMR_INTERFACES__SRV__DETAIL__GET_DROP_POSE__BUILDER_HPP_
