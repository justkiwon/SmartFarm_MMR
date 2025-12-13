// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from mmr_interfaces:srv/MoveDistance.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "mmr_interfaces/srv/detail/move_distance__rosidl_typesupport_introspection_c.h"
#include "mmr_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "mmr_interfaces/srv/detail/move_distance__functions.h"
#include "mmr_interfaces/srv/detail/move_distance__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void mmr_interfaces__srv__MoveDistance_Request__rosidl_typesupport_introspection_c__MoveDistance_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  mmr_interfaces__srv__MoveDistance_Request__init(message_memory);
}

void mmr_interfaces__srv__MoveDistance_Request__rosidl_typesupport_introspection_c__MoveDistance_Request_fini_function(void * message_memory)
{
  mmr_interfaces__srv__MoveDistance_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember mmr_interfaces__srv__MoveDistance_Request__rosidl_typesupport_introspection_c__MoveDistance_Request_message_member_array[1] = {
  {
    "distance",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(mmr_interfaces__srv__MoveDistance_Request, distance),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers mmr_interfaces__srv__MoveDistance_Request__rosidl_typesupport_introspection_c__MoveDistance_Request_message_members = {
  "mmr_interfaces__srv",  // message namespace
  "MoveDistance_Request",  // message name
  1,  // number of fields
  sizeof(mmr_interfaces__srv__MoveDistance_Request),
  mmr_interfaces__srv__MoveDistance_Request__rosidl_typesupport_introspection_c__MoveDistance_Request_message_member_array,  // message members
  mmr_interfaces__srv__MoveDistance_Request__rosidl_typesupport_introspection_c__MoveDistance_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  mmr_interfaces__srv__MoveDistance_Request__rosidl_typesupport_introspection_c__MoveDistance_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t mmr_interfaces__srv__MoveDistance_Request__rosidl_typesupport_introspection_c__MoveDistance_Request_message_type_support_handle = {
  0,
  &mmr_interfaces__srv__MoveDistance_Request__rosidl_typesupport_introspection_c__MoveDistance_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_mmr_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mmr_interfaces, srv, MoveDistance_Request)() {
  if (!mmr_interfaces__srv__MoveDistance_Request__rosidl_typesupport_introspection_c__MoveDistance_Request_message_type_support_handle.typesupport_identifier) {
    mmr_interfaces__srv__MoveDistance_Request__rosidl_typesupport_introspection_c__MoveDistance_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &mmr_interfaces__srv__MoveDistance_Request__rosidl_typesupport_introspection_c__MoveDistance_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "mmr_interfaces/srv/detail/move_distance__rosidl_typesupport_introspection_c.h"
// already included above
// #include "mmr_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "mmr_interfaces/srv/detail/move_distance__functions.h"
// already included above
// #include "mmr_interfaces/srv/detail/move_distance__struct.h"


// Include directives for member types
// Member `message`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void mmr_interfaces__srv__MoveDistance_Response__rosidl_typesupport_introspection_c__MoveDistance_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  mmr_interfaces__srv__MoveDistance_Response__init(message_memory);
}

void mmr_interfaces__srv__MoveDistance_Response__rosidl_typesupport_introspection_c__MoveDistance_Response_fini_function(void * message_memory)
{
  mmr_interfaces__srv__MoveDistance_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember mmr_interfaces__srv__MoveDistance_Response__rosidl_typesupport_introspection_c__MoveDistance_Response_message_member_array[2] = {
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(mmr_interfaces__srv__MoveDistance_Response, success),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "message",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(mmr_interfaces__srv__MoveDistance_Response, message),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers mmr_interfaces__srv__MoveDistance_Response__rosidl_typesupport_introspection_c__MoveDistance_Response_message_members = {
  "mmr_interfaces__srv",  // message namespace
  "MoveDistance_Response",  // message name
  2,  // number of fields
  sizeof(mmr_interfaces__srv__MoveDistance_Response),
  mmr_interfaces__srv__MoveDistance_Response__rosidl_typesupport_introspection_c__MoveDistance_Response_message_member_array,  // message members
  mmr_interfaces__srv__MoveDistance_Response__rosidl_typesupport_introspection_c__MoveDistance_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  mmr_interfaces__srv__MoveDistance_Response__rosidl_typesupport_introspection_c__MoveDistance_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t mmr_interfaces__srv__MoveDistance_Response__rosidl_typesupport_introspection_c__MoveDistance_Response_message_type_support_handle = {
  0,
  &mmr_interfaces__srv__MoveDistance_Response__rosidl_typesupport_introspection_c__MoveDistance_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_mmr_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mmr_interfaces, srv, MoveDistance_Response)() {
  if (!mmr_interfaces__srv__MoveDistance_Response__rosidl_typesupport_introspection_c__MoveDistance_Response_message_type_support_handle.typesupport_identifier) {
    mmr_interfaces__srv__MoveDistance_Response__rosidl_typesupport_introspection_c__MoveDistance_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &mmr_interfaces__srv__MoveDistance_Response__rosidl_typesupport_introspection_c__MoveDistance_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "mmr_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "mmr_interfaces/srv/detail/move_distance__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers mmr_interfaces__srv__detail__move_distance__rosidl_typesupport_introspection_c__MoveDistance_service_members = {
  "mmr_interfaces__srv",  // service namespace
  "MoveDistance",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // mmr_interfaces__srv__detail__move_distance__rosidl_typesupport_introspection_c__MoveDistance_Request_message_type_support_handle,
  NULL  // response message
  // mmr_interfaces__srv__detail__move_distance__rosidl_typesupport_introspection_c__MoveDistance_Response_message_type_support_handle
};

static rosidl_service_type_support_t mmr_interfaces__srv__detail__move_distance__rosidl_typesupport_introspection_c__MoveDistance_service_type_support_handle = {
  0,
  &mmr_interfaces__srv__detail__move_distance__rosidl_typesupport_introspection_c__MoveDistance_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mmr_interfaces, srv, MoveDistance_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mmr_interfaces, srv, MoveDistance_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_mmr_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mmr_interfaces, srv, MoveDistance)() {
  if (!mmr_interfaces__srv__detail__move_distance__rosidl_typesupport_introspection_c__MoveDistance_service_type_support_handle.typesupport_identifier) {
    mmr_interfaces__srv__detail__move_distance__rosidl_typesupport_introspection_c__MoveDistance_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)mmr_interfaces__srv__detail__move_distance__rosidl_typesupport_introspection_c__MoveDistance_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mmr_interfaces, srv, MoveDistance_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mmr_interfaces, srv, MoveDistance_Response)()->data;
  }

  return &mmr_interfaces__srv__detail__move_distance__rosidl_typesupport_introspection_c__MoveDistance_service_type_support_handle;
}
