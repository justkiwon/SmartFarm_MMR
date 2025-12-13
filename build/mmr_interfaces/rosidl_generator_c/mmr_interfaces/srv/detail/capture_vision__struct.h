// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from mmr_interfaces:srv/CaptureVision.idl
// generated code does not contain a copyright notice

#ifndef MMR_INTERFACES__SRV__DETAIL__CAPTURE_VISION__STRUCT_H_
#define MMR_INTERFACES__SRV__DETAIL__CAPTURE_VISION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'initial_pose'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in srv/CaptureVision in the package mmr_interfaces.
typedef struct mmr_interfaces__srv__CaptureVision_Request
{
  /// 0: Overview, 1: Detail
  int32_t mode;
  /// Detail 모드일 때 참고할 대략적 위치 (x,y,z)
  rosidl_runtime_c__double__Sequence initial_pose;
} mmr_interfaces__srv__CaptureVision_Request;

// Struct for a sequence of mmr_interfaces__srv__CaptureVision_Request.
typedef struct mmr_interfaces__srv__CaptureVision_Request__Sequence
{
  mmr_interfaces__srv__CaptureVision_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mmr_interfaces__srv__CaptureVision_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'poses_x'
// Member 'poses_y'
// Member 'poses_z'
// already included above
// #include "rosidl_runtime_c/primitives_sequence.h"
// Member 'tags'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/CaptureVision in the package mmr_interfaces.
typedef struct mmr_interfaces__srv__CaptureVision_Response
{
  bool success;
  int32_t num_objects;
  rosidl_runtime_c__double__Sequence poses_x;
  rosidl_runtime_c__double__Sequence poses_y;
  rosidl_runtime_c__double__Sequence poses_z;
  rosidl_runtime_c__String__Sequence tags;
} mmr_interfaces__srv__CaptureVision_Response;

// Struct for a sequence of mmr_interfaces__srv__CaptureVision_Response.
typedef struct mmr_interfaces__srv__CaptureVision_Response__Sequence
{
  mmr_interfaces__srv__CaptureVision_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mmr_interfaces__srv__CaptureVision_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MMR_INTERFACES__SRV__DETAIL__CAPTURE_VISION__STRUCT_H_
