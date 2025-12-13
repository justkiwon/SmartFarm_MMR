// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from mmr_interfaces:srv/CaptureVision.idl
// generated code does not contain a copyright notice
#include "mmr_interfaces/srv/detail/capture_vision__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "mmr_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "mmr_interfaces/srv/detail/capture_vision__struct.h"
#include "mmr_interfaces/srv/detail/capture_vision__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/primitives_sequence.h"  // initial_pose
#include "rosidl_runtime_c/primitives_sequence_functions.h"  // initial_pose

// forward declare type support functions


using _CaptureVision_Request__ros_msg_type = mmr_interfaces__srv__CaptureVision_Request;

static bool _CaptureVision_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _CaptureVision_Request__ros_msg_type * ros_message = static_cast<const _CaptureVision_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: mode
  {
    cdr << ros_message->mode;
  }

  // Field name: initial_pose
  {
    size_t size = ros_message->initial_pose.size;
    auto array_ptr = ros_message->initial_pose.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  return true;
}

static bool _CaptureVision_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _CaptureVision_Request__ros_msg_type * ros_message = static_cast<_CaptureVision_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: mode
  {
    cdr >> ros_message->mode;
  }

  // Field name: initial_pose
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);

    // Check there are at least 'size' remaining bytes in the CDR stream before resizing
    auto old_state = cdr.getState();
    bool correct_size = cdr.jump(size);
    cdr.setState(old_state);
    if (!correct_size) {
      fprintf(stderr, "sequence size exceeds remaining buffer\n");
      return false;
    }

    if (ros_message->initial_pose.data) {
      rosidl_runtime_c__double__Sequence__fini(&ros_message->initial_pose);
    }
    if (!rosidl_runtime_c__double__Sequence__init(&ros_message->initial_pose, size)) {
      fprintf(stderr, "failed to create array for field 'initial_pose'");
      return false;
    }
    auto array_ptr = ros_message->initial_pose.data;
    cdr.deserializeArray(array_ptr, size);
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_mmr_interfaces
size_t get_serialized_size_mmr_interfaces__srv__CaptureVision_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _CaptureVision_Request__ros_msg_type * ros_message = static_cast<const _CaptureVision_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name mode
  {
    size_t item_size = sizeof(ros_message->mode);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name initial_pose
  {
    size_t array_size = ros_message->initial_pose.size;
    auto array_ptr = ros_message->initial_pose.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _CaptureVision_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_mmr_interfaces__srv__CaptureVision_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_mmr_interfaces
size_t max_serialized_size_mmr_interfaces__srv__CaptureVision_Request(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: mode
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: initial_pose
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = mmr_interfaces__srv__CaptureVision_Request;
    is_plain =
      (
      offsetof(DataType, initial_pose) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _CaptureVision_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_mmr_interfaces__srv__CaptureVision_Request(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_CaptureVision_Request = {
  "mmr_interfaces::srv",
  "CaptureVision_Request",
  _CaptureVision_Request__cdr_serialize,
  _CaptureVision_Request__cdr_deserialize,
  _CaptureVision_Request__get_serialized_size,
  _CaptureVision_Request__max_serialized_size
};

static rosidl_message_type_support_t _CaptureVision_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_CaptureVision_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, mmr_interfaces, srv, CaptureVision_Request)() {
  return &_CaptureVision_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "mmr_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "mmr_interfaces/srv/detail/capture_vision__struct.h"
// already included above
// #include "mmr_interfaces/srv/detail/capture_vision__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

// already included above
// #include "rosidl_runtime_c/primitives_sequence.h"  // poses_x, poses_y, poses_z
// already included above
// #include "rosidl_runtime_c/primitives_sequence_functions.h"  // poses_x, poses_y, poses_z
#include "rosidl_runtime_c/string.h"  // tags
#include "rosidl_runtime_c/string_functions.h"  // tags

// forward declare type support functions


using _CaptureVision_Response__ros_msg_type = mmr_interfaces__srv__CaptureVision_Response;

static bool _CaptureVision_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _CaptureVision_Response__ros_msg_type * ros_message = static_cast<const _CaptureVision_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: success
  {
    cdr << (ros_message->success ? true : false);
  }

  // Field name: num_objects
  {
    cdr << ros_message->num_objects;
  }

  // Field name: poses_x
  {
    size_t size = ros_message->poses_x.size;
    auto array_ptr = ros_message->poses_x.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: poses_y
  {
    size_t size = ros_message->poses_y.size;
    auto array_ptr = ros_message->poses_y.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: poses_z
  {
    size_t size = ros_message->poses_z.size;
    auto array_ptr = ros_message->poses_z.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: tags
  {
    size_t size = ros_message->tags.size;
    auto array_ptr = ros_message->tags.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      const rosidl_runtime_c__String * str = &array_ptr[i];
      if (str->capacity == 0 || str->capacity <= str->size) {
        fprintf(stderr, "string capacity not greater than size\n");
        return false;
      }
      if (str->data[str->size] != '\0') {
        fprintf(stderr, "string not null-terminated\n");
        return false;
      }
      cdr << str->data;
    }
  }

  return true;
}

static bool _CaptureVision_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _CaptureVision_Response__ros_msg_type * ros_message = static_cast<_CaptureVision_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: success
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->success = tmp ? true : false;
  }

  // Field name: num_objects
  {
    cdr >> ros_message->num_objects;
  }

  // Field name: poses_x
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);

    // Check there are at least 'size' remaining bytes in the CDR stream before resizing
    auto old_state = cdr.getState();
    bool correct_size = cdr.jump(size);
    cdr.setState(old_state);
    if (!correct_size) {
      fprintf(stderr, "sequence size exceeds remaining buffer\n");
      return false;
    }

    if (ros_message->poses_x.data) {
      rosidl_runtime_c__double__Sequence__fini(&ros_message->poses_x);
    }
    if (!rosidl_runtime_c__double__Sequence__init(&ros_message->poses_x, size)) {
      fprintf(stderr, "failed to create array for field 'poses_x'");
      return false;
    }
    auto array_ptr = ros_message->poses_x.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: poses_y
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);

    // Check there are at least 'size' remaining bytes in the CDR stream before resizing
    auto old_state = cdr.getState();
    bool correct_size = cdr.jump(size);
    cdr.setState(old_state);
    if (!correct_size) {
      fprintf(stderr, "sequence size exceeds remaining buffer\n");
      return false;
    }

    if (ros_message->poses_y.data) {
      rosidl_runtime_c__double__Sequence__fini(&ros_message->poses_y);
    }
    if (!rosidl_runtime_c__double__Sequence__init(&ros_message->poses_y, size)) {
      fprintf(stderr, "failed to create array for field 'poses_y'");
      return false;
    }
    auto array_ptr = ros_message->poses_y.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: poses_z
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);

    // Check there are at least 'size' remaining bytes in the CDR stream before resizing
    auto old_state = cdr.getState();
    bool correct_size = cdr.jump(size);
    cdr.setState(old_state);
    if (!correct_size) {
      fprintf(stderr, "sequence size exceeds remaining buffer\n");
      return false;
    }

    if (ros_message->poses_z.data) {
      rosidl_runtime_c__double__Sequence__fini(&ros_message->poses_z);
    }
    if (!rosidl_runtime_c__double__Sequence__init(&ros_message->poses_z, size)) {
      fprintf(stderr, "failed to create array for field 'poses_z'");
      return false;
    }
    auto array_ptr = ros_message->poses_z.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: tags
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);

    // Check there are at least 'size' remaining bytes in the CDR stream before resizing
    auto old_state = cdr.getState();
    bool correct_size = cdr.jump(size);
    cdr.setState(old_state);
    if (!correct_size) {
      fprintf(stderr, "sequence size exceeds remaining buffer\n");
      return false;
    }

    if (ros_message->tags.data) {
      rosidl_runtime_c__String__Sequence__fini(&ros_message->tags);
    }
    if (!rosidl_runtime_c__String__Sequence__init(&ros_message->tags, size)) {
      fprintf(stderr, "failed to create array for field 'tags'");
      return false;
    }
    auto array_ptr = ros_message->tags.data;
    for (size_t i = 0; i < size; ++i) {
      std::string tmp;
      cdr >> tmp;
      auto & ros_i = array_ptr[i];
      if (!ros_i.data) {
        rosidl_runtime_c__String__init(&ros_i);
      }
      bool succeeded = rosidl_runtime_c__String__assign(
        &ros_i,
        tmp.c_str());
      if (!succeeded) {
        fprintf(stderr, "failed to assign string into field 'tags'\n");
        return false;
      }
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_mmr_interfaces
size_t get_serialized_size_mmr_interfaces__srv__CaptureVision_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _CaptureVision_Response__ros_msg_type * ros_message = static_cast<const _CaptureVision_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name success
  {
    size_t item_size = sizeof(ros_message->success);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name num_objects
  {
    size_t item_size = sizeof(ros_message->num_objects);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name poses_x
  {
    size_t array_size = ros_message->poses_x.size;
    auto array_ptr = ros_message->poses_x.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name poses_y
  {
    size_t array_size = ros_message->poses_y.size;
    auto array_ptr = ros_message->poses_y.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name poses_z
  {
    size_t array_size = ros_message->poses_z.size;
    auto array_ptr = ros_message->poses_z.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name tags
  {
    size_t array_size = ros_message->tags.size;
    auto array_ptr = ros_message->tags.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        (array_ptr[index].size + 1);
    }
  }

  return current_alignment - initial_alignment;
}

static uint32_t _CaptureVision_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_mmr_interfaces__srv__CaptureVision_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_mmr_interfaces
size_t max_serialized_size_mmr_interfaces__srv__CaptureVision_Response(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: success
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: num_objects
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: poses_x
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: poses_y
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: poses_z
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: tags
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = mmr_interfaces__srv__CaptureVision_Response;
    is_plain =
      (
      offsetof(DataType, tags) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _CaptureVision_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_mmr_interfaces__srv__CaptureVision_Response(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_CaptureVision_Response = {
  "mmr_interfaces::srv",
  "CaptureVision_Response",
  _CaptureVision_Response__cdr_serialize,
  _CaptureVision_Response__cdr_deserialize,
  _CaptureVision_Response__get_serialized_size,
  _CaptureVision_Response__max_serialized_size
};

static rosidl_message_type_support_t _CaptureVision_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_CaptureVision_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, mmr_interfaces, srv, CaptureVision_Response)() {
  return &_CaptureVision_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "mmr_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "mmr_interfaces/srv/capture_vision.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t CaptureVision__callbacks = {
  "mmr_interfaces::srv",
  "CaptureVision",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, mmr_interfaces, srv, CaptureVision_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, mmr_interfaces, srv, CaptureVision_Response)(),
};

static rosidl_service_type_support_t CaptureVision__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &CaptureVision__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, mmr_interfaces, srv, CaptureVision)() {
  return &CaptureVision__handle;
}

#if defined(__cplusplus)
}
#endif
