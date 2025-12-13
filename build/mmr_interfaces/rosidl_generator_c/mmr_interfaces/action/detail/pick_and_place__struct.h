// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from mmr_interfaces:action/PickAndPlace.idl
// generated code does not contain a copyright notice

#ifndef MMR_INTERFACES__ACTION__DETAIL__PICK_AND_PLACE__STRUCT_H_
#define MMR_INTERFACES__ACTION__DETAIL__PICK_AND_PLACE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'pick_pose'
// Member 'place_pose'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in action/PickAndPlace in the package mmr_interfaces.
typedef struct mmr_interfaces__action__PickAndPlace_Goal
{
  /// x, y, z
  rosidl_runtime_c__double__Sequence pick_pose;
  /// x, y, z
  rosidl_runtime_c__double__Sequence place_pose;
} mmr_interfaces__action__PickAndPlace_Goal;

// Struct for a sequence of mmr_interfaces__action__PickAndPlace_Goal.
typedef struct mmr_interfaces__action__PickAndPlace_Goal__Sequence
{
  mmr_interfaces__action__PickAndPlace_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mmr_interfaces__action__PickAndPlace_Goal__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in action/PickAndPlace in the package mmr_interfaces.
typedef struct mmr_interfaces__action__PickAndPlace_Result
{
  bool success;
  rosidl_runtime_c__String message;
} mmr_interfaces__action__PickAndPlace_Result;

// Struct for a sequence of mmr_interfaces__action__PickAndPlace_Result.
typedef struct mmr_interfaces__action__PickAndPlace_Result__Sequence
{
  mmr_interfaces__action__PickAndPlace_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mmr_interfaces__action__PickAndPlace_Result__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'status'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in action/PickAndPlace in the package mmr_interfaces.
typedef struct mmr_interfaces__action__PickAndPlace_Feedback
{
  float progress;
  rosidl_runtime_c__String status;
} mmr_interfaces__action__PickAndPlace_Feedback;

// Struct for a sequence of mmr_interfaces__action__PickAndPlace_Feedback.
typedef struct mmr_interfaces__action__PickAndPlace_Feedback__Sequence
{
  mmr_interfaces__action__PickAndPlace_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mmr_interfaces__action__PickAndPlace_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "mmr_interfaces/action/detail/pick_and_place__struct.h"

/// Struct defined in action/PickAndPlace in the package mmr_interfaces.
typedef struct mmr_interfaces__action__PickAndPlace_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  mmr_interfaces__action__PickAndPlace_Goal goal;
} mmr_interfaces__action__PickAndPlace_SendGoal_Request;

// Struct for a sequence of mmr_interfaces__action__PickAndPlace_SendGoal_Request.
typedef struct mmr_interfaces__action__PickAndPlace_SendGoal_Request__Sequence
{
  mmr_interfaces__action__PickAndPlace_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mmr_interfaces__action__PickAndPlace_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/PickAndPlace in the package mmr_interfaces.
typedef struct mmr_interfaces__action__PickAndPlace_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} mmr_interfaces__action__PickAndPlace_SendGoal_Response;

// Struct for a sequence of mmr_interfaces__action__PickAndPlace_SendGoal_Response.
typedef struct mmr_interfaces__action__PickAndPlace_SendGoal_Response__Sequence
{
  mmr_interfaces__action__PickAndPlace_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mmr_interfaces__action__PickAndPlace_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/PickAndPlace in the package mmr_interfaces.
typedef struct mmr_interfaces__action__PickAndPlace_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} mmr_interfaces__action__PickAndPlace_GetResult_Request;

// Struct for a sequence of mmr_interfaces__action__PickAndPlace_GetResult_Request.
typedef struct mmr_interfaces__action__PickAndPlace_GetResult_Request__Sequence
{
  mmr_interfaces__action__PickAndPlace_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mmr_interfaces__action__PickAndPlace_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "mmr_interfaces/action/detail/pick_and_place__struct.h"

/// Struct defined in action/PickAndPlace in the package mmr_interfaces.
typedef struct mmr_interfaces__action__PickAndPlace_GetResult_Response
{
  int8_t status;
  mmr_interfaces__action__PickAndPlace_Result result;
} mmr_interfaces__action__PickAndPlace_GetResult_Response;

// Struct for a sequence of mmr_interfaces__action__PickAndPlace_GetResult_Response.
typedef struct mmr_interfaces__action__PickAndPlace_GetResult_Response__Sequence
{
  mmr_interfaces__action__PickAndPlace_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mmr_interfaces__action__PickAndPlace_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "mmr_interfaces/action/detail/pick_and_place__struct.h"

/// Struct defined in action/PickAndPlace in the package mmr_interfaces.
typedef struct mmr_interfaces__action__PickAndPlace_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  mmr_interfaces__action__PickAndPlace_Feedback feedback;
} mmr_interfaces__action__PickAndPlace_FeedbackMessage;

// Struct for a sequence of mmr_interfaces__action__PickAndPlace_FeedbackMessage.
typedef struct mmr_interfaces__action__PickAndPlace_FeedbackMessage__Sequence
{
  mmr_interfaces__action__PickAndPlace_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mmr_interfaces__action__PickAndPlace_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MMR_INTERFACES__ACTION__DETAIL__PICK_AND_PLACE__STRUCT_H_
