// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from mmr_interfaces:srv/RotateTurret.idl
// generated code does not contain a copyright notice

#ifndef MMR_INTERFACES__SRV__DETAIL__ROTATE_TURRET__STRUCT_H_
#define MMR_INTERFACES__SRV__DETAIL__ROTATE_TURRET__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'FORWARD'.
enum
{
  mmr_interfaces__srv__RotateTurret_Request__FORWARD = 0
};

/// Constant 'LEFT'.
enum
{
  mmr_interfaces__srv__RotateTurret_Request__LEFT = 1
};

/// Constant 'RIGHT'.
enum
{
  mmr_interfaces__srv__RotateTurret_Request__RIGHT = 2
};

/// Struct defined in srv/RotateTurret in the package mmr_interfaces.
typedef struct mmr_interfaces__srv__RotateTurret_Request
{
  int32_t direction;
} mmr_interfaces__srv__RotateTurret_Request;

// Struct for a sequence of mmr_interfaces__srv__RotateTurret_Request.
typedef struct mmr_interfaces__srv__RotateTurret_Request__Sequence
{
  mmr_interfaces__srv__RotateTurret_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mmr_interfaces__srv__RotateTurret_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'current_pose'
#include "rosidl_runtime_c/primitives_sequence.h"
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/RotateTurret in the package mmr_interfaces.
typedef struct mmr_interfaces__srv__RotateTurret_Response
{
  bool success;
  /// [x, y, z] in mm after rotation
  rosidl_runtime_c__double__Sequence current_pose;
  rosidl_runtime_c__String message;
} mmr_interfaces__srv__RotateTurret_Response;

// Struct for a sequence of mmr_interfaces__srv__RotateTurret_Response.
typedef struct mmr_interfaces__srv__RotateTurret_Response__Sequence
{
  mmr_interfaces__srv__RotateTurret_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mmr_interfaces__srv__RotateTurret_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MMR_INTERFACES__SRV__DETAIL__ROTATE_TURRET__STRUCT_H_
