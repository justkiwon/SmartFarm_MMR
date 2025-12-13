// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from mmr_interfaces:srv/GetDropPose.idl
// generated code does not contain a copyright notice

#ifndef MMR_INTERFACES__SRV__DETAIL__GET_DROP_POSE__STRUCT_H_
#define MMR_INTERFACES__SRV__DETAIL__GET_DROP_POSE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'tag'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/GetDropPose in the package mmr_interfaces.
typedef struct mmr_interfaces__srv__GetDropPose_Request
{
  rosidl_runtime_c__String tag;
} mmr_interfaces__srv__GetDropPose_Request;

// Struct for a sequence of mmr_interfaces__srv__GetDropPose_Request.
typedef struct mmr_interfaces__srv__GetDropPose_Request__Sequence
{
  mmr_interfaces__srv__GetDropPose_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mmr_interfaces__srv__GetDropPose_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/GetDropPose in the package mmr_interfaces.
typedef struct mmr_interfaces__srv__GetDropPose_Response
{
  bool success;
  double x;
  double y;
  double z;
} mmr_interfaces__srv__GetDropPose_Response;

// Struct for a sequence of mmr_interfaces__srv__GetDropPose_Response.
typedef struct mmr_interfaces__srv__GetDropPose_Response__Sequence
{
  mmr_interfaces__srv__GetDropPose_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mmr_interfaces__srv__GetDropPose_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MMR_INTERFACES__SRV__DETAIL__GET_DROP_POSE__STRUCT_H_
