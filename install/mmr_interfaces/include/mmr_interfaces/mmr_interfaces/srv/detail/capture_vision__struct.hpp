// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from mmr_interfaces:srv/CaptureVision.idl
// generated code does not contain a copyright notice

#ifndef MMR_INTERFACES__SRV__DETAIL__CAPTURE_VISION__STRUCT_HPP_
#define MMR_INTERFACES__SRV__DETAIL__CAPTURE_VISION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__mmr_interfaces__srv__CaptureVision_Request __attribute__((deprecated))
#else
# define DEPRECATED__mmr_interfaces__srv__CaptureVision_Request __declspec(deprecated)
#endif

namespace mmr_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct CaptureVision_Request_
{
  using Type = CaptureVision_Request_<ContainerAllocator>;

  explicit CaptureVision_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mode = 0l;
    }
  }

  explicit CaptureVision_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mode = 0l;
    }
  }

  // field types and members
  using _mode_type =
    int32_t;
  _mode_type mode;
  using _initial_pose_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _initial_pose_type initial_pose;

  // setters for named parameter idiom
  Type & set__mode(
    const int32_t & _arg)
  {
    this->mode = _arg;
    return *this;
  }
  Type & set__initial_pose(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->initial_pose = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    mmr_interfaces::srv::CaptureVision_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const mmr_interfaces::srv::CaptureVision_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<mmr_interfaces::srv::CaptureVision_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<mmr_interfaces::srv::CaptureVision_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      mmr_interfaces::srv::CaptureVision_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<mmr_interfaces::srv::CaptureVision_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      mmr_interfaces::srv::CaptureVision_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<mmr_interfaces::srv::CaptureVision_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<mmr_interfaces::srv::CaptureVision_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<mmr_interfaces::srv::CaptureVision_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__mmr_interfaces__srv__CaptureVision_Request
    std::shared_ptr<mmr_interfaces::srv::CaptureVision_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__mmr_interfaces__srv__CaptureVision_Request
    std::shared_ptr<mmr_interfaces::srv::CaptureVision_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CaptureVision_Request_ & other) const
  {
    if (this->mode != other.mode) {
      return false;
    }
    if (this->initial_pose != other.initial_pose) {
      return false;
    }
    return true;
  }
  bool operator!=(const CaptureVision_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CaptureVision_Request_

// alias to use template instance with default allocator
using CaptureVision_Request =
  mmr_interfaces::srv::CaptureVision_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace mmr_interfaces


#ifndef _WIN32
# define DEPRECATED__mmr_interfaces__srv__CaptureVision_Response __attribute__((deprecated))
#else
# define DEPRECATED__mmr_interfaces__srv__CaptureVision_Response __declspec(deprecated)
#endif

namespace mmr_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct CaptureVision_Response_
{
  using Type = CaptureVision_Response_<ContainerAllocator>;

  explicit CaptureVision_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->num_objects = 0l;
    }
  }

  explicit CaptureVision_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->num_objects = 0l;
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _num_objects_type =
    int32_t;
  _num_objects_type num_objects;
  using _poses_x_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _poses_x_type poses_x;
  using _poses_y_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _poses_y_type poses_y;
  using _poses_z_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _poses_z_type poses_z;
  using _tags_type =
    std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>>;
  _tags_type tags;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__num_objects(
    const int32_t & _arg)
  {
    this->num_objects = _arg;
    return *this;
  }
  Type & set__poses_x(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->poses_x = _arg;
    return *this;
  }
  Type & set__poses_y(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->poses_y = _arg;
    return *this;
  }
  Type & set__poses_z(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->poses_z = _arg;
    return *this;
  }
  Type & set__tags(
    const std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>> & _arg)
  {
    this->tags = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    mmr_interfaces::srv::CaptureVision_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const mmr_interfaces::srv::CaptureVision_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<mmr_interfaces::srv::CaptureVision_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<mmr_interfaces::srv::CaptureVision_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      mmr_interfaces::srv::CaptureVision_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<mmr_interfaces::srv::CaptureVision_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      mmr_interfaces::srv::CaptureVision_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<mmr_interfaces::srv::CaptureVision_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<mmr_interfaces::srv::CaptureVision_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<mmr_interfaces::srv::CaptureVision_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__mmr_interfaces__srv__CaptureVision_Response
    std::shared_ptr<mmr_interfaces::srv::CaptureVision_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__mmr_interfaces__srv__CaptureVision_Response
    std::shared_ptr<mmr_interfaces::srv::CaptureVision_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CaptureVision_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->num_objects != other.num_objects) {
      return false;
    }
    if (this->poses_x != other.poses_x) {
      return false;
    }
    if (this->poses_y != other.poses_y) {
      return false;
    }
    if (this->poses_z != other.poses_z) {
      return false;
    }
    if (this->tags != other.tags) {
      return false;
    }
    return true;
  }
  bool operator!=(const CaptureVision_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CaptureVision_Response_

// alias to use template instance with default allocator
using CaptureVision_Response =
  mmr_interfaces::srv::CaptureVision_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace mmr_interfaces

namespace mmr_interfaces
{

namespace srv
{

struct CaptureVision
{
  using Request = mmr_interfaces::srv::CaptureVision_Request;
  using Response = mmr_interfaces::srv::CaptureVision_Response;
};

}  // namespace srv

}  // namespace mmr_interfaces

#endif  // MMR_INTERFACES__SRV__DETAIL__CAPTURE_VISION__STRUCT_HPP_
