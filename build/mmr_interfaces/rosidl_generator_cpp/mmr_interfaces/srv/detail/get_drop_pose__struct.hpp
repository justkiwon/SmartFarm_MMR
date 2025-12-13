// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from mmr_interfaces:srv/GetDropPose.idl
// generated code does not contain a copyright notice

#ifndef MMR_INTERFACES__SRV__DETAIL__GET_DROP_POSE__STRUCT_HPP_
#define MMR_INTERFACES__SRV__DETAIL__GET_DROP_POSE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__mmr_interfaces__srv__GetDropPose_Request __attribute__((deprecated))
#else
# define DEPRECATED__mmr_interfaces__srv__GetDropPose_Request __declspec(deprecated)
#endif

namespace mmr_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetDropPose_Request_
{
  using Type = GetDropPose_Request_<ContainerAllocator>;

  explicit GetDropPose_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->tag = "";
    }
  }

  explicit GetDropPose_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : tag(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->tag = "";
    }
  }

  // field types and members
  using _tag_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _tag_type tag;

  // setters for named parameter idiom
  Type & set__tag(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->tag = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    mmr_interfaces::srv::GetDropPose_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const mmr_interfaces::srv::GetDropPose_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<mmr_interfaces::srv::GetDropPose_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<mmr_interfaces::srv::GetDropPose_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      mmr_interfaces::srv::GetDropPose_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<mmr_interfaces::srv::GetDropPose_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      mmr_interfaces::srv::GetDropPose_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<mmr_interfaces::srv::GetDropPose_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<mmr_interfaces::srv::GetDropPose_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<mmr_interfaces::srv::GetDropPose_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__mmr_interfaces__srv__GetDropPose_Request
    std::shared_ptr<mmr_interfaces::srv::GetDropPose_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__mmr_interfaces__srv__GetDropPose_Request
    std::shared_ptr<mmr_interfaces::srv::GetDropPose_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetDropPose_Request_ & other) const
  {
    if (this->tag != other.tag) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetDropPose_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetDropPose_Request_

// alias to use template instance with default allocator
using GetDropPose_Request =
  mmr_interfaces::srv::GetDropPose_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace mmr_interfaces


#ifndef _WIN32
# define DEPRECATED__mmr_interfaces__srv__GetDropPose_Response __attribute__((deprecated))
#else
# define DEPRECATED__mmr_interfaces__srv__GetDropPose_Response __declspec(deprecated)
#endif

namespace mmr_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetDropPose_Response_
{
  using Type = GetDropPose_Response_<ContainerAllocator>;

  explicit GetDropPose_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->x = 0.0;
      this->y = 0.0;
      this->z = 0.0;
    }
  }

  explicit GetDropPose_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->x = 0.0;
      this->y = 0.0;
      this->z = 0.0;
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _x_type =
    double;
  _x_type x;
  using _y_type =
    double;
  _y_type y;
  using _z_type =
    double;
  _z_type z;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__x(
    const double & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const double & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__z(
    const double & _arg)
  {
    this->z = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    mmr_interfaces::srv::GetDropPose_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const mmr_interfaces::srv::GetDropPose_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<mmr_interfaces::srv::GetDropPose_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<mmr_interfaces::srv::GetDropPose_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      mmr_interfaces::srv::GetDropPose_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<mmr_interfaces::srv::GetDropPose_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      mmr_interfaces::srv::GetDropPose_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<mmr_interfaces::srv::GetDropPose_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<mmr_interfaces::srv::GetDropPose_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<mmr_interfaces::srv::GetDropPose_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__mmr_interfaces__srv__GetDropPose_Response
    std::shared_ptr<mmr_interfaces::srv::GetDropPose_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__mmr_interfaces__srv__GetDropPose_Response
    std::shared_ptr<mmr_interfaces::srv::GetDropPose_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetDropPose_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->z != other.z) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetDropPose_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetDropPose_Response_

// alias to use template instance with default allocator
using GetDropPose_Response =
  mmr_interfaces::srv::GetDropPose_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace mmr_interfaces

namespace mmr_interfaces
{

namespace srv
{

struct GetDropPose
{
  using Request = mmr_interfaces::srv::GetDropPose_Request;
  using Response = mmr_interfaces::srv::GetDropPose_Response;
};

}  // namespace srv

}  // namespace mmr_interfaces

#endif  // MMR_INTERFACES__SRV__DETAIL__GET_DROP_POSE__STRUCT_HPP_
