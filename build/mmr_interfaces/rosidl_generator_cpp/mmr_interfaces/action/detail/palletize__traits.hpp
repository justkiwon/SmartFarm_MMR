// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from mmr_interfaces:action/Palletize.idl
// generated code does not contain a copyright notice

#ifndef MMR_INTERFACES__ACTION__DETAIL__PALLETIZE__TRAITS_HPP_
#define MMR_INTERFACES__ACTION__DETAIL__PALLETIZE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "mmr_interfaces/action/detail/palletize__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace mmr_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const Palletize_Goal & msg,
  std::ostream & out)
{
  out << "{";
  // member: pose_2d
  {
    if (msg.pose_2d.size() == 0) {
      out << "pose_2d: []";
    } else {
      out << "pose_2d: [";
      size_t pending_items = msg.pose_2d.size();
      for (auto item : msg.pose_2d) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: num_points
  {
    out << "num_points: ";
    rosidl_generator_traits::value_to_yaml(msg.num_points, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Palletize_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: pose_2d
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.pose_2d.size() == 0) {
      out << "pose_2d: []\n";
    } else {
      out << "pose_2d:\n";
      for (auto item : msg.pose_2d) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: num_points
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "num_points: ";
    rosidl_generator_traits::value_to_yaml(msg.num_points, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Palletize_Goal & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace mmr_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use mmr_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const mmr_interfaces::action::Palletize_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  mmr_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use mmr_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const mmr_interfaces::action::Palletize_Goal & msg)
{
  return mmr_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<mmr_interfaces::action::Palletize_Goal>()
{
  return "mmr_interfaces::action::Palletize_Goal";
}

template<>
inline const char * name<mmr_interfaces::action::Palletize_Goal>()
{
  return "mmr_interfaces/action/Palletize_Goal";
}

template<>
struct has_fixed_size<mmr_interfaces::action::Palletize_Goal>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<mmr_interfaces::action::Palletize_Goal>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<mmr_interfaces::action::Palletize_Goal>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace mmr_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const Palletize_Result & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Palletize_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Palletize_Result & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace mmr_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use mmr_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const mmr_interfaces::action::Palletize_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  mmr_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use mmr_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const mmr_interfaces::action::Palletize_Result & msg)
{
  return mmr_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<mmr_interfaces::action::Palletize_Result>()
{
  return "mmr_interfaces::action::Palletize_Result";
}

template<>
inline const char * name<mmr_interfaces::action::Palletize_Result>()
{
  return "mmr_interfaces/action/Palletize_Result";
}

template<>
struct has_fixed_size<mmr_interfaces::action::Palletize_Result>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<mmr_interfaces::action::Palletize_Result>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<mmr_interfaces::action::Palletize_Result>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace mmr_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const Palletize_Feedback & msg,
  std::ostream & out)
{
  out << "{";
  // member: progress
  {
    out << "progress: ";
    rosidl_generator_traits::value_to_yaml(msg.progress, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Palletize_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: progress
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "progress: ";
    rosidl_generator_traits::value_to_yaml(msg.progress, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Palletize_Feedback & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace mmr_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use mmr_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const mmr_interfaces::action::Palletize_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  mmr_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use mmr_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const mmr_interfaces::action::Palletize_Feedback & msg)
{
  return mmr_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<mmr_interfaces::action::Palletize_Feedback>()
{
  return "mmr_interfaces::action::Palletize_Feedback";
}

template<>
inline const char * name<mmr_interfaces::action::Palletize_Feedback>()
{
  return "mmr_interfaces/action/Palletize_Feedback";
}

template<>
struct has_fixed_size<mmr_interfaces::action::Palletize_Feedback>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<mmr_interfaces::action::Palletize_Feedback>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<mmr_interfaces::action::Palletize_Feedback>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'goal'
#include "mmr_interfaces/action/detail/palletize__traits.hpp"

namespace mmr_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const Palletize_SendGoal_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: goal
  {
    out << "goal: ";
    to_flow_style_yaml(msg.goal, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Palletize_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: goal
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal:\n";
    to_block_style_yaml(msg.goal, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Palletize_SendGoal_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace mmr_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use mmr_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const mmr_interfaces::action::Palletize_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  mmr_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use mmr_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const mmr_interfaces::action::Palletize_SendGoal_Request & msg)
{
  return mmr_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<mmr_interfaces::action::Palletize_SendGoal_Request>()
{
  return "mmr_interfaces::action::Palletize_SendGoal_Request";
}

template<>
inline const char * name<mmr_interfaces::action::Palletize_SendGoal_Request>()
{
  return "mmr_interfaces/action/Palletize_SendGoal_Request";
}

template<>
struct has_fixed_size<mmr_interfaces::action::Palletize_SendGoal_Request>
  : std::integral_constant<bool, has_fixed_size<mmr_interfaces::action::Palletize_Goal>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<mmr_interfaces::action::Palletize_SendGoal_Request>
  : std::integral_constant<bool, has_bounded_size<mmr_interfaces::action::Palletize_Goal>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<mmr_interfaces::action::Palletize_SendGoal_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace mmr_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const Palletize_SendGoal_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: accepted
  {
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << ", ";
  }

  // member: stamp
  {
    out << "stamp: ";
    to_flow_style_yaml(msg.stamp, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Palletize_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: accepted
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << "\n";
  }

  // member: stamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stamp:\n";
    to_block_style_yaml(msg.stamp, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Palletize_SendGoal_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace mmr_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use mmr_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const mmr_interfaces::action::Palletize_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  mmr_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use mmr_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const mmr_interfaces::action::Palletize_SendGoal_Response & msg)
{
  return mmr_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<mmr_interfaces::action::Palletize_SendGoal_Response>()
{
  return "mmr_interfaces::action::Palletize_SendGoal_Response";
}

template<>
inline const char * name<mmr_interfaces::action::Palletize_SendGoal_Response>()
{
  return "mmr_interfaces/action/Palletize_SendGoal_Response";
}

template<>
struct has_fixed_size<mmr_interfaces::action::Palletize_SendGoal_Response>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<mmr_interfaces::action::Palletize_SendGoal_Response>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<mmr_interfaces::action::Palletize_SendGoal_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<mmr_interfaces::action::Palletize_SendGoal>()
{
  return "mmr_interfaces::action::Palletize_SendGoal";
}

template<>
inline const char * name<mmr_interfaces::action::Palletize_SendGoal>()
{
  return "mmr_interfaces/action/Palletize_SendGoal";
}

template<>
struct has_fixed_size<mmr_interfaces::action::Palletize_SendGoal>
  : std::integral_constant<
    bool,
    has_fixed_size<mmr_interfaces::action::Palletize_SendGoal_Request>::value &&
    has_fixed_size<mmr_interfaces::action::Palletize_SendGoal_Response>::value
  >
{
};

template<>
struct has_bounded_size<mmr_interfaces::action::Palletize_SendGoal>
  : std::integral_constant<
    bool,
    has_bounded_size<mmr_interfaces::action::Palletize_SendGoal_Request>::value &&
    has_bounded_size<mmr_interfaces::action::Palletize_SendGoal_Response>::value
  >
{
};

template<>
struct is_service<mmr_interfaces::action::Palletize_SendGoal>
  : std::true_type
{
};

template<>
struct is_service_request<mmr_interfaces::action::Palletize_SendGoal_Request>
  : std::true_type
{
};

template<>
struct is_service_response<mmr_interfaces::action::Palletize_SendGoal_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"

namespace mmr_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const Palletize_GetResult_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Palletize_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Palletize_GetResult_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace mmr_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use mmr_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const mmr_interfaces::action::Palletize_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  mmr_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use mmr_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const mmr_interfaces::action::Palletize_GetResult_Request & msg)
{
  return mmr_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<mmr_interfaces::action::Palletize_GetResult_Request>()
{
  return "mmr_interfaces::action::Palletize_GetResult_Request";
}

template<>
inline const char * name<mmr_interfaces::action::Palletize_GetResult_Request>()
{
  return "mmr_interfaces/action/Palletize_GetResult_Request";
}

template<>
struct has_fixed_size<mmr_interfaces::action::Palletize_GetResult_Request>
  : std::integral_constant<bool, has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<mmr_interfaces::action::Palletize_GetResult_Request>
  : std::integral_constant<bool, has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<mmr_interfaces::action::Palletize_GetResult_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'result'
// already included above
// #include "mmr_interfaces/action/detail/palletize__traits.hpp"

namespace mmr_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const Palletize_GetResult_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << ", ";
  }

  // member: result
  {
    out << "result: ";
    to_flow_style_yaml(msg.result, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Palletize_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << "\n";
  }

  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result:\n";
    to_block_style_yaml(msg.result, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Palletize_GetResult_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace mmr_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use mmr_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const mmr_interfaces::action::Palletize_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  mmr_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use mmr_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const mmr_interfaces::action::Palletize_GetResult_Response & msg)
{
  return mmr_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<mmr_interfaces::action::Palletize_GetResult_Response>()
{
  return "mmr_interfaces::action::Palletize_GetResult_Response";
}

template<>
inline const char * name<mmr_interfaces::action::Palletize_GetResult_Response>()
{
  return "mmr_interfaces/action/Palletize_GetResult_Response";
}

template<>
struct has_fixed_size<mmr_interfaces::action::Palletize_GetResult_Response>
  : std::integral_constant<bool, has_fixed_size<mmr_interfaces::action::Palletize_Result>::value> {};

template<>
struct has_bounded_size<mmr_interfaces::action::Palletize_GetResult_Response>
  : std::integral_constant<bool, has_bounded_size<mmr_interfaces::action::Palletize_Result>::value> {};

template<>
struct is_message<mmr_interfaces::action::Palletize_GetResult_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<mmr_interfaces::action::Palletize_GetResult>()
{
  return "mmr_interfaces::action::Palletize_GetResult";
}

template<>
inline const char * name<mmr_interfaces::action::Palletize_GetResult>()
{
  return "mmr_interfaces/action/Palletize_GetResult";
}

template<>
struct has_fixed_size<mmr_interfaces::action::Palletize_GetResult>
  : std::integral_constant<
    bool,
    has_fixed_size<mmr_interfaces::action::Palletize_GetResult_Request>::value &&
    has_fixed_size<mmr_interfaces::action::Palletize_GetResult_Response>::value
  >
{
};

template<>
struct has_bounded_size<mmr_interfaces::action::Palletize_GetResult>
  : std::integral_constant<
    bool,
    has_bounded_size<mmr_interfaces::action::Palletize_GetResult_Request>::value &&
    has_bounded_size<mmr_interfaces::action::Palletize_GetResult_Response>::value
  >
{
};

template<>
struct is_service<mmr_interfaces::action::Palletize_GetResult>
  : std::true_type
{
};

template<>
struct is_service_request<mmr_interfaces::action::Palletize_GetResult_Request>
  : std::true_type
{
};

template<>
struct is_service_response<mmr_interfaces::action::Palletize_GetResult_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'feedback'
// already included above
// #include "mmr_interfaces/action/detail/palletize__traits.hpp"

namespace mmr_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const Palletize_FeedbackMessage & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: feedback
  {
    out << "feedback: ";
    to_flow_style_yaml(msg.feedback, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Palletize_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: feedback
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "feedback:\n";
    to_block_style_yaml(msg.feedback, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Palletize_FeedbackMessage & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace mmr_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use mmr_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const mmr_interfaces::action::Palletize_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  mmr_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use mmr_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const mmr_interfaces::action::Palletize_FeedbackMessage & msg)
{
  return mmr_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<mmr_interfaces::action::Palletize_FeedbackMessage>()
{
  return "mmr_interfaces::action::Palletize_FeedbackMessage";
}

template<>
inline const char * name<mmr_interfaces::action::Palletize_FeedbackMessage>()
{
  return "mmr_interfaces/action/Palletize_FeedbackMessage";
}

template<>
struct has_fixed_size<mmr_interfaces::action::Palletize_FeedbackMessage>
  : std::integral_constant<bool, has_fixed_size<mmr_interfaces::action::Palletize_Feedback>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<mmr_interfaces::action::Palletize_FeedbackMessage>
  : std::integral_constant<bool, has_bounded_size<mmr_interfaces::action::Palletize_Feedback>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<mmr_interfaces::action::Palletize_FeedbackMessage>
  : std::true_type {};

}  // namespace rosidl_generator_traits


namespace rosidl_generator_traits
{

template<>
struct is_action<mmr_interfaces::action::Palletize>
  : std::true_type
{
};

template<>
struct is_action_goal<mmr_interfaces::action::Palletize_Goal>
  : std::true_type
{
};

template<>
struct is_action_result<mmr_interfaces::action::Palletize_Result>
  : std::true_type
{
};

template<>
struct is_action_feedback<mmr_interfaces::action::Palletize_Feedback>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits


#endif  // MMR_INTERFACES__ACTION__DETAIL__PALLETIZE__TRAITS_HPP_
