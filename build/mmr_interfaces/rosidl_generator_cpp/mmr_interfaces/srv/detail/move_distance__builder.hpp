// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from mmr_interfaces:srv/MoveDistance.idl
// generated code does not contain a copyright notice

#ifndef MMR_INTERFACES__SRV__DETAIL__MOVE_DISTANCE__BUILDER_HPP_
#define MMR_INTERFACES__SRV__DETAIL__MOVE_DISTANCE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "mmr_interfaces/srv/detail/move_distance__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace mmr_interfaces
{

namespace srv
{

namespace builder
{

class Init_MoveDistance_Request_distance
{
public:
  Init_MoveDistance_Request_distance()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::mmr_interfaces::srv::MoveDistance_Request distance(::mmr_interfaces::srv::MoveDistance_Request::_distance_type arg)
  {
    msg_.distance = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mmr_interfaces::srv::MoveDistance_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::mmr_interfaces::srv::MoveDistance_Request>()
{
  return mmr_interfaces::srv::builder::Init_MoveDistance_Request_distance();
}

}  // namespace mmr_interfaces


namespace mmr_interfaces
{

namespace srv
{

namespace builder
{

class Init_MoveDistance_Response_message
{
public:
  explicit Init_MoveDistance_Response_message(::mmr_interfaces::srv::MoveDistance_Response & msg)
  : msg_(msg)
  {}
  ::mmr_interfaces::srv::MoveDistance_Response message(::mmr_interfaces::srv::MoveDistance_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mmr_interfaces::srv::MoveDistance_Response msg_;
};

class Init_MoveDistance_Response_success
{
public:
  Init_MoveDistance_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveDistance_Response_message success(::mmr_interfaces::srv::MoveDistance_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_MoveDistance_Response_message(msg_);
  }

private:
  ::mmr_interfaces::srv::MoveDistance_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::mmr_interfaces::srv::MoveDistance_Response>()
{
  return mmr_interfaces::srv::builder::Init_MoveDistance_Response_success();
}

}  // namespace mmr_interfaces

#endif  // MMR_INTERFACES__SRV__DETAIL__MOVE_DISTANCE__BUILDER_HPP_
