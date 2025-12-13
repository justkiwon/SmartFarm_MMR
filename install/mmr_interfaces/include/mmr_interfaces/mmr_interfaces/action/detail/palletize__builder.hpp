// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from mmr_interfaces:action/Palletize.idl
// generated code does not contain a copyright notice

#ifndef MMR_INTERFACES__ACTION__DETAIL__PALLETIZE__BUILDER_HPP_
#define MMR_INTERFACES__ACTION__DETAIL__PALLETIZE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "mmr_interfaces/action/detail/palletize__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace mmr_interfaces
{

namespace action
{

namespace builder
{

class Init_Palletize_Goal_num_points
{
public:
  explicit Init_Palletize_Goal_num_points(::mmr_interfaces::action::Palletize_Goal & msg)
  : msg_(msg)
  {}
  ::mmr_interfaces::action::Palletize_Goal num_points(::mmr_interfaces::action::Palletize_Goal::_num_points_type arg)
  {
    msg_.num_points = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mmr_interfaces::action::Palletize_Goal msg_;
};

class Init_Palletize_Goal_pose_2d
{
public:
  Init_Palletize_Goal_pose_2d()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Palletize_Goal_num_points pose_2d(::mmr_interfaces::action::Palletize_Goal::_pose_2d_type arg)
  {
    msg_.pose_2d = std::move(arg);
    return Init_Palletize_Goal_num_points(msg_);
  }

private:
  ::mmr_interfaces::action::Palletize_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::mmr_interfaces::action::Palletize_Goal>()
{
  return mmr_interfaces::action::builder::Init_Palletize_Goal_pose_2d();
}

}  // namespace mmr_interfaces


namespace mmr_interfaces
{

namespace action
{

namespace builder
{

class Init_Palletize_Result_message
{
public:
  explicit Init_Palletize_Result_message(::mmr_interfaces::action::Palletize_Result & msg)
  : msg_(msg)
  {}
  ::mmr_interfaces::action::Palletize_Result message(::mmr_interfaces::action::Palletize_Result::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mmr_interfaces::action::Palletize_Result msg_;
};

class Init_Palletize_Result_success
{
public:
  Init_Palletize_Result_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Palletize_Result_message success(::mmr_interfaces::action::Palletize_Result::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_Palletize_Result_message(msg_);
  }

private:
  ::mmr_interfaces::action::Palletize_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::mmr_interfaces::action::Palletize_Result>()
{
  return mmr_interfaces::action::builder::Init_Palletize_Result_success();
}

}  // namespace mmr_interfaces


namespace mmr_interfaces
{

namespace action
{

namespace builder
{

class Init_Palletize_Feedback_progress
{
public:
  Init_Palletize_Feedback_progress()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::mmr_interfaces::action::Palletize_Feedback progress(::mmr_interfaces::action::Palletize_Feedback::_progress_type arg)
  {
    msg_.progress = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mmr_interfaces::action::Palletize_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::mmr_interfaces::action::Palletize_Feedback>()
{
  return mmr_interfaces::action::builder::Init_Palletize_Feedback_progress();
}

}  // namespace mmr_interfaces


namespace mmr_interfaces
{

namespace action
{

namespace builder
{

class Init_Palletize_SendGoal_Request_goal
{
public:
  explicit Init_Palletize_SendGoal_Request_goal(::mmr_interfaces::action::Palletize_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::mmr_interfaces::action::Palletize_SendGoal_Request goal(::mmr_interfaces::action::Palletize_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mmr_interfaces::action::Palletize_SendGoal_Request msg_;
};

class Init_Palletize_SendGoal_Request_goal_id
{
public:
  Init_Palletize_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Palletize_SendGoal_Request_goal goal_id(::mmr_interfaces::action::Palletize_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Palletize_SendGoal_Request_goal(msg_);
  }

private:
  ::mmr_interfaces::action::Palletize_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::mmr_interfaces::action::Palletize_SendGoal_Request>()
{
  return mmr_interfaces::action::builder::Init_Palletize_SendGoal_Request_goal_id();
}

}  // namespace mmr_interfaces


namespace mmr_interfaces
{

namespace action
{

namespace builder
{

class Init_Palletize_SendGoal_Response_stamp
{
public:
  explicit Init_Palletize_SendGoal_Response_stamp(::mmr_interfaces::action::Palletize_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::mmr_interfaces::action::Palletize_SendGoal_Response stamp(::mmr_interfaces::action::Palletize_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mmr_interfaces::action::Palletize_SendGoal_Response msg_;
};

class Init_Palletize_SendGoal_Response_accepted
{
public:
  Init_Palletize_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Palletize_SendGoal_Response_stamp accepted(::mmr_interfaces::action::Palletize_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_Palletize_SendGoal_Response_stamp(msg_);
  }

private:
  ::mmr_interfaces::action::Palletize_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::mmr_interfaces::action::Palletize_SendGoal_Response>()
{
  return mmr_interfaces::action::builder::Init_Palletize_SendGoal_Response_accepted();
}

}  // namespace mmr_interfaces


namespace mmr_interfaces
{

namespace action
{

namespace builder
{

class Init_Palletize_GetResult_Request_goal_id
{
public:
  Init_Palletize_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::mmr_interfaces::action::Palletize_GetResult_Request goal_id(::mmr_interfaces::action::Palletize_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mmr_interfaces::action::Palletize_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::mmr_interfaces::action::Palletize_GetResult_Request>()
{
  return mmr_interfaces::action::builder::Init_Palletize_GetResult_Request_goal_id();
}

}  // namespace mmr_interfaces


namespace mmr_interfaces
{

namespace action
{

namespace builder
{

class Init_Palletize_GetResult_Response_result
{
public:
  explicit Init_Palletize_GetResult_Response_result(::mmr_interfaces::action::Palletize_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::mmr_interfaces::action::Palletize_GetResult_Response result(::mmr_interfaces::action::Palletize_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mmr_interfaces::action::Palletize_GetResult_Response msg_;
};

class Init_Palletize_GetResult_Response_status
{
public:
  Init_Palletize_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Palletize_GetResult_Response_result status(::mmr_interfaces::action::Palletize_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_Palletize_GetResult_Response_result(msg_);
  }

private:
  ::mmr_interfaces::action::Palletize_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::mmr_interfaces::action::Palletize_GetResult_Response>()
{
  return mmr_interfaces::action::builder::Init_Palletize_GetResult_Response_status();
}

}  // namespace mmr_interfaces


namespace mmr_interfaces
{

namespace action
{

namespace builder
{

class Init_Palletize_FeedbackMessage_feedback
{
public:
  explicit Init_Palletize_FeedbackMessage_feedback(::mmr_interfaces::action::Palletize_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::mmr_interfaces::action::Palletize_FeedbackMessage feedback(::mmr_interfaces::action::Palletize_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mmr_interfaces::action::Palletize_FeedbackMessage msg_;
};

class Init_Palletize_FeedbackMessage_goal_id
{
public:
  Init_Palletize_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Palletize_FeedbackMessage_feedback goal_id(::mmr_interfaces::action::Palletize_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Palletize_FeedbackMessage_feedback(msg_);
  }

private:
  ::mmr_interfaces::action::Palletize_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::mmr_interfaces::action::Palletize_FeedbackMessage>()
{
  return mmr_interfaces::action::builder::Init_Palletize_FeedbackMessage_goal_id();
}

}  // namespace mmr_interfaces

#endif  // MMR_INTERFACES__ACTION__DETAIL__PALLETIZE__BUILDER_HPP_
