// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from mmr_interfaces:action/PickAndPlace.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "mmr_interfaces/action/detail/pick_and_place__struct.h"
#include "mmr_interfaces/action/detail/pick_and_place__type_support.h"
#include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/message_type_support_dispatch.h"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace mmr_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _PickAndPlace_Goal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PickAndPlace_Goal_type_support_ids_t;

static const _PickAndPlace_Goal_type_support_ids_t _PickAndPlace_Goal_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _PickAndPlace_Goal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PickAndPlace_Goal_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PickAndPlace_Goal_type_support_symbol_names_t _PickAndPlace_Goal_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, mmr_interfaces, action, PickAndPlace_Goal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mmr_interfaces, action, PickAndPlace_Goal)),
  }
};

typedef struct _PickAndPlace_Goal_type_support_data_t
{
  void * data[2];
} _PickAndPlace_Goal_type_support_data_t;

static _PickAndPlace_Goal_type_support_data_t _PickAndPlace_Goal_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PickAndPlace_Goal_message_typesupport_map = {
  2,
  "mmr_interfaces",
  &_PickAndPlace_Goal_message_typesupport_ids.typesupport_identifier[0],
  &_PickAndPlace_Goal_message_typesupport_symbol_names.symbol_name[0],
  &_PickAndPlace_Goal_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t PickAndPlace_Goal_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PickAndPlace_Goal_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace mmr_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, mmr_interfaces, action, PickAndPlace_Goal)() {
  return &::mmr_interfaces::action::rosidl_typesupport_c::PickAndPlace_Goal_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "mmr_interfaces/action/detail/pick_and_place__struct.h"
// already included above
// #include "mmr_interfaces/action/detail/pick_and_place__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace mmr_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _PickAndPlace_Result_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PickAndPlace_Result_type_support_ids_t;

static const _PickAndPlace_Result_type_support_ids_t _PickAndPlace_Result_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _PickAndPlace_Result_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PickAndPlace_Result_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PickAndPlace_Result_type_support_symbol_names_t _PickAndPlace_Result_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, mmr_interfaces, action, PickAndPlace_Result)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mmr_interfaces, action, PickAndPlace_Result)),
  }
};

typedef struct _PickAndPlace_Result_type_support_data_t
{
  void * data[2];
} _PickAndPlace_Result_type_support_data_t;

static _PickAndPlace_Result_type_support_data_t _PickAndPlace_Result_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PickAndPlace_Result_message_typesupport_map = {
  2,
  "mmr_interfaces",
  &_PickAndPlace_Result_message_typesupport_ids.typesupport_identifier[0],
  &_PickAndPlace_Result_message_typesupport_symbol_names.symbol_name[0],
  &_PickAndPlace_Result_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t PickAndPlace_Result_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PickAndPlace_Result_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace mmr_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, mmr_interfaces, action, PickAndPlace_Result)() {
  return &::mmr_interfaces::action::rosidl_typesupport_c::PickAndPlace_Result_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "mmr_interfaces/action/detail/pick_and_place__struct.h"
// already included above
// #include "mmr_interfaces/action/detail/pick_and_place__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace mmr_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _PickAndPlace_Feedback_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PickAndPlace_Feedback_type_support_ids_t;

static const _PickAndPlace_Feedback_type_support_ids_t _PickAndPlace_Feedback_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _PickAndPlace_Feedback_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PickAndPlace_Feedback_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PickAndPlace_Feedback_type_support_symbol_names_t _PickAndPlace_Feedback_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, mmr_interfaces, action, PickAndPlace_Feedback)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mmr_interfaces, action, PickAndPlace_Feedback)),
  }
};

typedef struct _PickAndPlace_Feedback_type_support_data_t
{
  void * data[2];
} _PickAndPlace_Feedback_type_support_data_t;

static _PickAndPlace_Feedback_type_support_data_t _PickAndPlace_Feedback_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PickAndPlace_Feedback_message_typesupport_map = {
  2,
  "mmr_interfaces",
  &_PickAndPlace_Feedback_message_typesupport_ids.typesupport_identifier[0],
  &_PickAndPlace_Feedback_message_typesupport_symbol_names.symbol_name[0],
  &_PickAndPlace_Feedback_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t PickAndPlace_Feedback_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PickAndPlace_Feedback_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace mmr_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, mmr_interfaces, action, PickAndPlace_Feedback)() {
  return &::mmr_interfaces::action::rosidl_typesupport_c::PickAndPlace_Feedback_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "mmr_interfaces/action/detail/pick_and_place__struct.h"
// already included above
// #include "mmr_interfaces/action/detail/pick_and_place__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace mmr_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _PickAndPlace_SendGoal_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PickAndPlace_SendGoal_Request_type_support_ids_t;

static const _PickAndPlace_SendGoal_Request_type_support_ids_t _PickAndPlace_SendGoal_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _PickAndPlace_SendGoal_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PickAndPlace_SendGoal_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PickAndPlace_SendGoal_Request_type_support_symbol_names_t _PickAndPlace_SendGoal_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, mmr_interfaces, action, PickAndPlace_SendGoal_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mmr_interfaces, action, PickAndPlace_SendGoal_Request)),
  }
};

typedef struct _PickAndPlace_SendGoal_Request_type_support_data_t
{
  void * data[2];
} _PickAndPlace_SendGoal_Request_type_support_data_t;

static _PickAndPlace_SendGoal_Request_type_support_data_t _PickAndPlace_SendGoal_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PickAndPlace_SendGoal_Request_message_typesupport_map = {
  2,
  "mmr_interfaces",
  &_PickAndPlace_SendGoal_Request_message_typesupport_ids.typesupport_identifier[0],
  &_PickAndPlace_SendGoal_Request_message_typesupport_symbol_names.symbol_name[0],
  &_PickAndPlace_SendGoal_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t PickAndPlace_SendGoal_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PickAndPlace_SendGoal_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace mmr_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, mmr_interfaces, action, PickAndPlace_SendGoal_Request)() {
  return &::mmr_interfaces::action::rosidl_typesupport_c::PickAndPlace_SendGoal_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "mmr_interfaces/action/detail/pick_and_place__struct.h"
// already included above
// #include "mmr_interfaces/action/detail/pick_and_place__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace mmr_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _PickAndPlace_SendGoal_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PickAndPlace_SendGoal_Response_type_support_ids_t;

static const _PickAndPlace_SendGoal_Response_type_support_ids_t _PickAndPlace_SendGoal_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _PickAndPlace_SendGoal_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PickAndPlace_SendGoal_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PickAndPlace_SendGoal_Response_type_support_symbol_names_t _PickAndPlace_SendGoal_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, mmr_interfaces, action, PickAndPlace_SendGoal_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mmr_interfaces, action, PickAndPlace_SendGoal_Response)),
  }
};

typedef struct _PickAndPlace_SendGoal_Response_type_support_data_t
{
  void * data[2];
} _PickAndPlace_SendGoal_Response_type_support_data_t;

static _PickAndPlace_SendGoal_Response_type_support_data_t _PickAndPlace_SendGoal_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PickAndPlace_SendGoal_Response_message_typesupport_map = {
  2,
  "mmr_interfaces",
  &_PickAndPlace_SendGoal_Response_message_typesupport_ids.typesupport_identifier[0],
  &_PickAndPlace_SendGoal_Response_message_typesupport_symbol_names.symbol_name[0],
  &_PickAndPlace_SendGoal_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t PickAndPlace_SendGoal_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PickAndPlace_SendGoal_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace mmr_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, mmr_interfaces, action, PickAndPlace_SendGoal_Response)() {
  return &::mmr_interfaces::action::rosidl_typesupport_c::PickAndPlace_SendGoal_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "mmr_interfaces/action/detail/pick_and_place__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/service_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace mmr_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _PickAndPlace_SendGoal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PickAndPlace_SendGoal_type_support_ids_t;

static const _PickAndPlace_SendGoal_type_support_ids_t _PickAndPlace_SendGoal_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _PickAndPlace_SendGoal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PickAndPlace_SendGoal_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PickAndPlace_SendGoal_type_support_symbol_names_t _PickAndPlace_SendGoal_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, mmr_interfaces, action, PickAndPlace_SendGoal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mmr_interfaces, action, PickAndPlace_SendGoal)),
  }
};

typedef struct _PickAndPlace_SendGoal_type_support_data_t
{
  void * data[2];
} _PickAndPlace_SendGoal_type_support_data_t;

static _PickAndPlace_SendGoal_type_support_data_t _PickAndPlace_SendGoal_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PickAndPlace_SendGoal_service_typesupport_map = {
  2,
  "mmr_interfaces",
  &_PickAndPlace_SendGoal_service_typesupport_ids.typesupport_identifier[0],
  &_PickAndPlace_SendGoal_service_typesupport_symbol_names.symbol_name[0],
  &_PickAndPlace_SendGoal_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t PickAndPlace_SendGoal_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PickAndPlace_SendGoal_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace mmr_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, mmr_interfaces, action, PickAndPlace_SendGoal)() {
  return &::mmr_interfaces::action::rosidl_typesupport_c::PickAndPlace_SendGoal_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "mmr_interfaces/action/detail/pick_and_place__struct.h"
// already included above
// #include "mmr_interfaces/action/detail/pick_and_place__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace mmr_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _PickAndPlace_GetResult_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PickAndPlace_GetResult_Request_type_support_ids_t;

static const _PickAndPlace_GetResult_Request_type_support_ids_t _PickAndPlace_GetResult_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _PickAndPlace_GetResult_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PickAndPlace_GetResult_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PickAndPlace_GetResult_Request_type_support_symbol_names_t _PickAndPlace_GetResult_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, mmr_interfaces, action, PickAndPlace_GetResult_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mmr_interfaces, action, PickAndPlace_GetResult_Request)),
  }
};

typedef struct _PickAndPlace_GetResult_Request_type_support_data_t
{
  void * data[2];
} _PickAndPlace_GetResult_Request_type_support_data_t;

static _PickAndPlace_GetResult_Request_type_support_data_t _PickAndPlace_GetResult_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PickAndPlace_GetResult_Request_message_typesupport_map = {
  2,
  "mmr_interfaces",
  &_PickAndPlace_GetResult_Request_message_typesupport_ids.typesupport_identifier[0],
  &_PickAndPlace_GetResult_Request_message_typesupport_symbol_names.symbol_name[0],
  &_PickAndPlace_GetResult_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t PickAndPlace_GetResult_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PickAndPlace_GetResult_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace mmr_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, mmr_interfaces, action, PickAndPlace_GetResult_Request)() {
  return &::mmr_interfaces::action::rosidl_typesupport_c::PickAndPlace_GetResult_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "mmr_interfaces/action/detail/pick_and_place__struct.h"
// already included above
// #include "mmr_interfaces/action/detail/pick_and_place__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace mmr_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _PickAndPlace_GetResult_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PickAndPlace_GetResult_Response_type_support_ids_t;

static const _PickAndPlace_GetResult_Response_type_support_ids_t _PickAndPlace_GetResult_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _PickAndPlace_GetResult_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PickAndPlace_GetResult_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PickAndPlace_GetResult_Response_type_support_symbol_names_t _PickAndPlace_GetResult_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, mmr_interfaces, action, PickAndPlace_GetResult_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mmr_interfaces, action, PickAndPlace_GetResult_Response)),
  }
};

typedef struct _PickAndPlace_GetResult_Response_type_support_data_t
{
  void * data[2];
} _PickAndPlace_GetResult_Response_type_support_data_t;

static _PickAndPlace_GetResult_Response_type_support_data_t _PickAndPlace_GetResult_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PickAndPlace_GetResult_Response_message_typesupport_map = {
  2,
  "mmr_interfaces",
  &_PickAndPlace_GetResult_Response_message_typesupport_ids.typesupport_identifier[0],
  &_PickAndPlace_GetResult_Response_message_typesupport_symbol_names.symbol_name[0],
  &_PickAndPlace_GetResult_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t PickAndPlace_GetResult_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PickAndPlace_GetResult_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace mmr_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, mmr_interfaces, action, PickAndPlace_GetResult_Response)() {
  return &::mmr_interfaces::action::rosidl_typesupport_c::PickAndPlace_GetResult_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "mmr_interfaces/action/detail/pick_and_place__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/service_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace mmr_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _PickAndPlace_GetResult_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PickAndPlace_GetResult_type_support_ids_t;

static const _PickAndPlace_GetResult_type_support_ids_t _PickAndPlace_GetResult_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _PickAndPlace_GetResult_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PickAndPlace_GetResult_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PickAndPlace_GetResult_type_support_symbol_names_t _PickAndPlace_GetResult_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, mmr_interfaces, action, PickAndPlace_GetResult)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mmr_interfaces, action, PickAndPlace_GetResult)),
  }
};

typedef struct _PickAndPlace_GetResult_type_support_data_t
{
  void * data[2];
} _PickAndPlace_GetResult_type_support_data_t;

static _PickAndPlace_GetResult_type_support_data_t _PickAndPlace_GetResult_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PickAndPlace_GetResult_service_typesupport_map = {
  2,
  "mmr_interfaces",
  &_PickAndPlace_GetResult_service_typesupport_ids.typesupport_identifier[0],
  &_PickAndPlace_GetResult_service_typesupport_symbol_names.symbol_name[0],
  &_PickAndPlace_GetResult_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t PickAndPlace_GetResult_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PickAndPlace_GetResult_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace mmr_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, mmr_interfaces, action, PickAndPlace_GetResult)() {
  return &::mmr_interfaces::action::rosidl_typesupport_c::PickAndPlace_GetResult_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "mmr_interfaces/action/detail/pick_and_place__struct.h"
// already included above
// #include "mmr_interfaces/action/detail/pick_and_place__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace mmr_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _PickAndPlace_FeedbackMessage_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PickAndPlace_FeedbackMessage_type_support_ids_t;

static const _PickAndPlace_FeedbackMessage_type_support_ids_t _PickAndPlace_FeedbackMessage_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _PickAndPlace_FeedbackMessage_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PickAndPlace_FeedbackMessage_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PickAndPlace_FeedbackMessage_type_support_symbol_names_t _PickAndPlace_FeedbackMessage_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, mmr_interfaces, action, PickAndPlace_FeedbackMessage)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mmr_interfaces, action, PickAndPlace_FeedbackMessage)),
  }
};

typedef struct _PickAndPlace_FeedbackMessage_type_support_data_t
{
  void * data[2];
} _PickAndPlace_FeedbackMessage_type_support_data_t;

static _PickAndPlace_FeedbackMessage_type_support_data_t _PickAndPlace_FeedbackMessage_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PickAndPlace_FeedbackMessage_message_typesupport_map = {
  2,
  "mmr_interfaces",
  &_PickAndPlace_FeedbackMessage_message_typesupport_ids.typesupport_identifier[0],
  &_PickAndPlace_FeedbackMessage_message_typesupport_symbol_names.symbol_name[0],
  &_PickAndPlace_FeedbackMessage_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t PickAndPlace_FeedbackMessage_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PickAndPlace_FeedbackMessage_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace mmr_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, mmr_interfaces, action, PickAndPlace_FeedbackMessage)() {
  return &::mmr_interfaces::action::rosidl_typesupport_c::PickAndPlace_FeedbackMessage_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

#include "action_msgs/msg/goal_status_array.h"
#include "action_msgs/srv/cancel_goal.h"
#include "mmr_interfaces/action/pick_and_place.h"
// already included above
// #include "mmr_interfaces/action/detail/pick_and_place__type_support.h"

static rosidl_action_type_support_t _mmr_interfaces__action__PickAndPlace__typesupport_c;

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_action_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__ACTION_SYMBOL_NAME(
  rosidl_typesupport_c, mmr_interfaces, action, PickAndPlace)()
{
  // Thread-safe by always writing the same values to the static struct
  _mmr_interfaces__action__PickAndPlace__typesupport_c.goal_service_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(
    rosidl_typesupport_c, mmr_interfaces, action, PickAndPlace_SendGoal)();
  _mmr_interfaces__action__PickAndPlace__typesupport_c.result_service_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(
    rosidl_typesupport_c, mmr_interfaces, action, PickAndPlace_GetResult)();
  _mmr_interfaces__action__PickAndPlace__typesupport_c.cancel_service_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(
    rosidl_typesupport_c, action_msgs, srv, CancelGoal)();
  _mmr_interfaces__action__PickAndPlace__typesupport_c.feedback_message_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c, mmr_interfaces, action, PickAndPlace_FeedbackMessage)();
  _mmr_interfaces__action__PickAndPlace__typesupport_c.status_message_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c, action_msgs, msg, GoalStatusArray)();

  return &_mmr_interfaces__action__PickAndPlace__typesupport_c;
}

#ifdef __cplusplus
}
#endif
