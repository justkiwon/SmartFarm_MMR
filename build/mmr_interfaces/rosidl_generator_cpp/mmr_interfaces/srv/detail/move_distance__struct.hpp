// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from mmr_interfaces:srv/MoveDistance.idl
// generated code does not contain a copyright notice

#ifndef MMR_INTERFACES__SRV__DETAIL__MOVE_DISTANCE__STRUCT_HPP_
#define MMR_INTERFACES__SRV__DETAIL__MOVE_DISTANCE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__mmr_interfaces__srv__MoveDistance_Request __attribute__((deprecated))
#else
# define DEPRECATED__mmr_interfaces__srv__MoveDistance_Request __declspec(deprecated)
#endif

namespace mmr_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct MoveDistance_Request_
{
  using Type = MoveDistance_Request_<ContainerAllocator>;

  explicit MoveDistance_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->distance = 0.0;
    }
  }

  explicit MoveDistance_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->distance = 0.0;
    }
  }

  // field types and members
  using _distance_type =
    double;
  _distance_type distance;

  // setters for named parameter idiom
  Type & set__distance(
    const double & _arg)
  {
    this->distance = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    mmr_interfaces::srv::MoveDistance_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const mmr_interfaces::srv::MoveDistance_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<mmr_interfaces::srv::MoveDistance_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<mmr_interfaces::srv::MoveDistance_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      mmr_interfaces::srv::MoveDistance_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<mmr_interfaces::srv::MoveDistance_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      mmr_interfaces::srv::MoveDistance_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<mmr_interfaces::srv::MoveDistance_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<mmr_interfaces::srv::MoveDistance_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<mmr_interfaces::srv::MoveDistance_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__mmr_interfaces__srv__MoveDistance_Request
    std::shared_ptr<mmr_interfaces::srv::MoveDistance_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__mmr_interfaces__srv__MoveDistance_Request
    std::shared_ptr<mmr_interfaces::srv::MoveDistance_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MoveDistance_Request_ & other) const
  {
    if (this->distance != other.distance) {
      return false;
    }
    return true;
  }
  bool operator!=(const MoveDistance_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MoveDistance_Request_

// alias to use template instance with default allocator
using MoveDistance_Request =
  mmr_interfaces::srv::MoveDistance_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace mmr_interfaces


#ifndef _WIN32
# define DEPRECATED__mmr_interfaces__srv__MoveDistance_Response __attribute__((deprecated))
#else
# define DEPRECATED__mmr_interfaces__srv__MoveDistance_Response __declspec(deprecated)
#endif

namespace mmr_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct MoveDistance_Response_
{
  using Type = MoveDistance_Response_<ContainerAllocator>;

  explicit MoveDistance_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  explicit MoveDistance_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    mmr_interfaces::srv::MoveDistance_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const mmr_interfaces::srv::MoveDistance_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<mmr_interfaces::srv::MoveDistance_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<mmr_interfaces::srv::MoveDistance_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      mmr_interfaces::srv::MoveDistance_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<mmr_interfaces::srv::MoveDistance_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      mmr_interfaces::srv::MoveDistance_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<mmr_interfaces::srv::MoveDistance_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<mmr_interfaces::srv::MoveDistance_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<mmr_interfaces::srv::MoveDistance_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__mmr_interfaces__srv__MoveDistance_Response
    std::shared_ptr<mmr_interfaces::srv::MoveDistance_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__mmr_interfaces__srv__MoveDistance_Response
    std::shared_ptr<mmr_interfaces::srv::MoveDistance_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MoveDistance_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const MoveDistance_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MoveDistance_Response_

// alias to use template instance with default allocator
using MoveDistance_Response =
  mmr_interfaces::srv::MoveDistance_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace mmr_interfaces

namespace mmr_interfaces
{

namespace srv
{

struct MoveDistance
{
  using Request = mmr_interfaces::srv::MoveDistance_Request;
  using Response = mmr_interfaces::srv::MoveDistance_Response;
};

}  // namespace srv

}  // namespace mmr_interfaces

#endif  // MMR_INTERFACES__SRV__DETAIL__MOVE_DISTANCE__STRUCT_HPP_
