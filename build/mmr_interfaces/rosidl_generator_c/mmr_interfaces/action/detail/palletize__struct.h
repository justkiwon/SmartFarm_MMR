// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from mmr_interfaces:action/Palletize.idl
// generated code does not contain a copyright notice

#ifndef MMR_INTERFACES__ACTION__DETAIL__PALLETIZE__STRUCT_H_
#define MMR_INTERFACES__ACTION__DETAIL__PALLETIZE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'pose_2d'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in action/Palletize in the package mmr_interfaces.
typedef struct mmr_interfaces__action__Palletize_Goal
{
  rosidl_runtime_c__double__Sequence pose_2d;
  int32_t num_points;
} mmr_interfaces__action__Palletize_Goal;

// Struct for a sequence of mmr_interfaces__action__Palletize_Goal.
typedef struct mmr_interfaces__action__Palletize_Goal__Sequence
{
  mmr_interfaces__action__Palletize_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mmr_interfaces__action__Palletize_Goal__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in action/Palletize in the package mmr_interfaces.
typedef struct mmr_interfaces__action__Palletize_Result
{
  bool success;
  rosidl_runtime_c__String message;
} mmr_interfaces__action__Palletize_Result;

// Struct for a sequence of mmr_interfaces__action__Palletize_Result.
typedef struct mmr_interfaces__action__Palletize_Result__Sequence
{
  mmr_interfaces__action__Palletize_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mmr_interfaces__action__Palletize_Result__Sequence;


// Constants defined in the message

/// Struct defined in action/Palletize in the package mmr_interfaces.
typedef struct mmr_interfaces__action__Palletize_Feedback
{
  float progress;
} mmr_interfaces__action__Palletize_Feedback;

// Struct for a sequence of mmr_interfaces__action__Palletize_Feedback.
typedef struct mmr_interfaces__action__Palletize_Feedback__Sequence
{
  mmr_interfaces__action__Palletize_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mmr_interfaces__action__Palletize_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "mmr_interfaces/action/detail/palletize__struct.h"

/// Struct defined in action/Palletize in the package mmr_interfaces.
typedef struct mmr_interfaces__action__Palletize_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  mmr_interfaces__action__Palletize_Goal goal;
} mmr_interfaces__action__Palletize_SendGoal_Request;

// Struct for a sequence of mmr_interfaces__action__Palletize_SendGoal_Request.
typedef struct mmr_interfaces__action__Palletize_SendGoal_Request__Sequence
{
  mmr_interfaces__action__Palletize_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mmr_interfaces__action__Palletize_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/Palletize in the package mmr_interfaces.
typedef struct mmr_interfaces__action__Palletize_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} mmr_interfaces__action__Palletize_SendGoal_Response;

// Struct for a sequence of mmr_interfaces__action__Palletize_SendGoal_Response.
typedef struct mmr_interfaces__action__Palletize_SendGoal_Response__Sequence
{
  mmr_interfaces__action__Palletize_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mmr_interfaces__action__Palletize_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/Palletize in the package mmr_interfaces.
typedef struct mmr_interfaces__action__Palletize_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} mmr_interfaces__action__Palletize_GetResult_Request;

// Struct for a sequence of mmr_interfaces__action__Palletize_GetResult_Request.
typedef struct mmr_interfaces__action__Palletize_GetResult_Request__Sequence
{
  mmr_interfaces__action__Palletize_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mmr_interfaces__action__Palletize_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "mmr_interfaces/action/detail/palletize__struct.h"

/// Struct defined in action/Palletize in the package mmr_interfaces.
typedef struct mmr_interfaces__action__Palletize_GetResult_Response
{
  int8_t status;
  mmr_interfaces__action__Palletize_Result result;
} mmr_interfaces__action__Palletize_GetResult_Response;

// Struct for a sequence of mmr_interfaces__action__Palletize_GetResult_Response.
typedef struct mmr_interfaces__action__Palletize_GetResult_Response__Sequence
{
  mmr_interfaces__action__Palletize_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mmr_interfaces__action__Palletize_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "mmr_interfaces/action/detail/palletize__struct.h"

/// Struct defined in action/Palletize in the package mmr_interfaces.
typedef struct mmr_interfaces__action__Palletize_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  mmr_interfaces__action__Palletize_Feedback feedback;
} mmr_interfaces__action__Palletize_FeedbackMessage;

// Struct for a sequence of mmr_interfaces__action__Palletize_FeedbackMessage.
typedef struct mmr_interfaces__action__Palletize_FeedbackMessage__Sequence
{
  mmr_interfaces__action__Palletize_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mmr_interfaces__action__Palletize_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MMR_INTERFACES__ACTION__DETAIL__PALLETIZE__STRUCT_H_
