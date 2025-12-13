// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from mmr_interfaces:srv/MoveDistance.idl
// generated code does not contain a copyright notice

#ifndef MMR_INTERFACES__SRV__DETAIL__MOVE_DISTANCE__STRUCT_H_
#define MMR_INTERFACES__SRV__DETAIL__MOVE_DISTANCE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/MoveDistance in the package mmr_interfaces.
typedef struct mmr_interfaces__srv__MoveDistance_Request
{
  double distance;
} mmr_interfaces__srv__MoveDistance_Request;

// Struct for a sequence of mmr_interfaces__srv__MoveDistance_Request.
typedef struct mmr_interfaces__srv__MoveDistance_Request__Sequence
{
  mmr_interfaces__srv__MoveDistance_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mmr_interfaces__srv__MoveDistance_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/MoveDistance in the package mmr_interfaces.
typedef struct mmr_interfaces__srv__MoveDistance_Response
{
  bool success;
  rosidl_runtime_c__String message;
} mmr_interfaces__srv__MoveDistance_Response;

// Struct for a sequence of mmr_interfaces__srv__MoveDistance_Response.
typedef struct mmr_interfaces__srv__MoveDistance_Response__Sequence
{
  mmr_interfaces__srv__MoveDistance_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mmr_interfaces__srv__MoveDistance_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MMR_INTERFACES__SRV__DETAIL__MOVE_DISTANCE__STRUCT_H_
