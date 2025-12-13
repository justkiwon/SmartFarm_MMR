// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from mmr_interfaces:srv/MoveDistance.idl
// generated code does not contain a copyright notice

#ifndef MMR_INTERFACES__SRV__DETAIL__MOVE_DISTANCE__TRAITS_HPP_
#define MMR_INTERFACES__SRV__DETAIL__MOVE_DISTANCE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "mmr_interfaces/srv/detail/move_distance__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace mmr_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const MoveDistance_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: distance
  {
    out << "distance: ";
    rosidl_generator_traits::value_to_yaml(msg.distance, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MoveDistance_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: distance
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "distance: ";
    rosidl_generator_traits::value_to_yaml(msg.distance, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MoveDistance_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace mmr_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use mmr_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const mmr_interfaces::srv::MoveDistance_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  mmr_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use mmr_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const mmr_interfaces::srv::MoveDistance_Request & msg)
{
  return mmr_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<mmr_interfaces::srv::MoveDistance_Request>()
{
  return "mmr_interfaces::srv::MoveDistance_Request";
}

template<>
inline const char * name<mmr_interfaces::srv::MoveDistance_Request>()
{
  return "mmr_interfaces/srv/MoveDistance_Request";
}

template<>
struct has_fixed_size<mmr_interfaces::srv::MoveDistance_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<mmr_interfaces::srv::MoveDistance_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<mmr_interfaces::srv::MoveDistance_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace mmr_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const MoveDistance_Response & msg,
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
  const MoveDistance_Response & msg,
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

inline std::string to_yaml(const MoveDistance_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace mmr_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use mmr_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const mmr_interfaces::srv::MoveDistance_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  mmr_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use mmr_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const mmr_interfaces::srv::MoveDistance_Response & msg)
{
  return mmr_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<mmr_interfaces::srv::MoveDistance_Response>()
{
  return "mmr_interfaces::srv::MoveDistance_Response";
}

template<>
inline const char * name<mmr_interfaces::srv::MoveDistance_Response>()
{
  return "mmr_interfaces/srv/MoveDistance_Response";
}

template<>
struct has_fixed_size<mmr_interfaces::srv::MoveDistance_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<mmr_interfaces::srv::MoveDistance_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<mmr_interfaces::srv::MoveDistance_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<mmr_interfaces::srv::MoveDistance>()
{
  return "mmr_interfaces::srv::MoveDistance";
}

template<>
inline const char * name<mmr_interfaces::srv::MoveDistance>()
{
  return "mmr_interfaces/srv/MoveDistance";
}

template<>
struct has_fixed_size<mmr_interfaces::srv::MoveDistance>
  : std::integral_constant<
    bool,
    has_fixed_size<mmr_interfaces::srv::MoveDistance_Request>::value &&
    has_fixed_size<mmr_interfaces::srv::MoveDistance_Response>::value
  >
{
};

template<>
struct has_bounded_size<mmr_interfaces::srv::MoveDistance>
  : std::integral_constant<
    bool,
    has_bounded_size<mmr_interfaces::srv::MoveDistance_Request>::value &&
    has_bounded_size<mmr_interfaces::srv::MoveDistance_Response>::value
  >
{
};

template<>
struct is_service<mmr_interfaces::srv::MoveDistance>
  : std::true_type
{
};

template<>
struct is_service_request<mmr_interfaces::srv::MoveDistance_Request>
  : std::true_type
{
};

template<>
struct is_service_response<mmr_interfaces::srv::MoveDistance_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // MMR_INTERFACES__SRV__DETAIL__MOVE_DISTANCE__TRAITS_HPP_
