// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from mmr_interfaces:srv/CaptureVision.idl
// generated code does not contain a copyright notice

#ifndef MMR_INTERFACES__SRV__DETAIL__CAPTURE_VISION__TRAITS_HPP_
#define MMR_INTERFACES__SRV__DETAIL__CAPTURE_VISION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "mmr_interfaces/srv/detail/capture_vision__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace mmr_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const CaptureVision_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: mode
  {
    out << "mode: ";
    rosidl_generator_traits::value_to_yaml(msg.mode, out);
    out << ", ";
  }

  // member: initial_pose
  {
    if (msg.initial_pose.size() == 0) {
      out << "initial_pose: []";
    } else {
      out << "initial_pose: [";
      size_t pending_items = msg.initial_pose.size();
      for (auto item : msg.initial_pose) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const CaptureVision_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mode: ";
    rosidl_generator_traits::value_to_yaml(msg.mode, out);
    out << "\n";
  }

  // member: initial_pose
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.initial_pose.size() == 0) {
      out << "initial_pose: []\n";
    } else {
      out << "initial_pose:\n";
      for (auto item : msg.initial_pose) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const CaptureVision_Request & msg, bool use_flow_style = false)
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
  const mmr_interfaces::srv::CaptureVision_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  mmr_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use mmr_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const mmr_interfaces::srv::CaptureVision_Request & msg)
{
  return mmr_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<mmr_interfaces::srv::CaptureVision_Request>()
{
  return "mmr_interfaces::srv::CaptureVision_Request";
}

template<>
inline const char * name<mmr_interfaces::srv::CaptureVision_Request>()
{
  return "mmr_interfaces/srv/CaptureVision_Request";
}

template<>
struct has_fixed_size<mmr_interfaces::srv::CaptureVision_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<mmr_interfaces::srv::CaptureVision_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<mmr_interfaces::srv::CaptureVision_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace mmr_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const CaptureVision_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: num_objects
  {
    out << "num_objects: ";
    rosidl_generator_traits::value_to_yaml(msg.num_objects, out);
    out << ", ";
  }

  // member: poses_x
  {
    if (msg.poses_x.size() == 0) {
      out << "poses_x: []";
    } else {
      out << "poses_x: [";
      size_t pending_items = msg.poses_x.size();
      for (auto item : msg.poses_x) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: poses_y
  {
    if (msg.poses_y.size() == 0) {
      out << "poses_y: []";
    } else {
      out << "poses_y: [";
      size_t pending_items = msg.poses_y.size();
      for (auto item : msg.poses_y) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: poses_z
  {
    if (msg.poses_z.size() == 0) {
      out << "poses_z: []";
    } else {
      out << "poses_z: [";
      size_t pending_items = msg.poses_z.size();
      for (auto item : msg.poses_z) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: tags
  {
    if (msg.tags.size() == 0) {
      out << "tags: []";
    } else {
      out << "tags: [";
      size_t pending_items = msg.tags.size();
      for (auto item : msg.tags) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const CaptureVision_Response & msg,
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

  // member: num_objects
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "num_objects: ";
    rosidl_generator_traits::value_to_yaml(msg.num_objects, out);
    out << "\n";
  }

  // member: poses_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.poses_x.size() == 0) {
      out << "poses_x: []\n";
    } else {
      out << "poses_x:\n";
      for (auto item : msg.poses_x) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: poses_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.poses_y.size() == 0) {
      out << "poses_y: []\n";
    } else {
      out << "poses_y:\n";
      for (auto item : msg.poses_y) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: poses_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.poses_z.size() == 0) {
      out << "poses_z: []\n";
    } else {
      out << "poses_z:\n";
      for (auto item : msg.poses_z) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: tags
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.tags.size() == 0) {
      out << "tags: []\n";
    } else {
      out << "tags:\n";
      for (auto item : msg.tags) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const CaptureVision_Response & msg, bool use_flow_style = false)
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
  const mmr_interfaces::srv::CaptureVision_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  mmr_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use mmr_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const mmr_interfaces::srv::CaptureVision_Response & msg)
{
  return mmr_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<mmr_interfaces::srv::CaptureVision_Response>()
{
  return "mmr_interfaces::srv::CaptureVision_Response";
}

template<>
inline const char * name<mmr_interfaces::srv::CaptureVision_Response>()
{
  return "mmr_interfaces/srv/CaptureVision_Response";
}

template<>
struct has_fixed_size<mmr_interfaces::srv::CaptureVision_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<mmr_interfaces::srv::CaptureVision_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<mmr_interfaces::srv::CaptureVision_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<mmr_interfaces::srv::CaptureVision>()
{
  return "mmr_interfaces::srv::CaptureVision";
}

template<>
inline const char * name<mmr_interfaces::srv::CaptureVision>()
{
  return "mmr_interfaces/srv/CaptureVision";
}

template<>
struct has_fixed_size<mmr_interfaces::srv::CaptureVision>
  : std::integral_constant<
    bool,
    has_fixed_size<mmr_interfaces::srv::CaptureVision_Request>::value &&
    has_fixed_size<mmr_interfaces::srv::CaptureVision_Response>::value
  >
{
};

template<>
struct has_bounded_size<mmr_interfaces::srv::CaptureVision>
  : std::integral_constant<
    bool,
    has_bounded_size<mmr_interfaces::srv::CaptureVision_Request>::value &&
    has_bounded_size<mmr_interfaces::srv::CaptureVision_Response>::value
  >
{
};

template<>
struct is_service<mmr_interfaces::srv::CaptureVision>
  : std::true_type
{
};

template<>
struct is_service_request<mmr_interfaces::srv::CaptureVision_Request>
  : std::true_type
{
};

template<>
struct is_service_response<mmr_interfaces::srv::CaptureVision_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // MMR_INTERFACES__SRV__DETAIL__CAPTURE_VISION__TRAITS_HPP_
