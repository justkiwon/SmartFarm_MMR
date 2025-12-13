// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from mmr_interfaces:srv/CaptureVision.idl
// generated code does not contain a copyright notice
#include "mmr_interfaces/srv/detail/capture_vision__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `initial_pose`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
mmr_interfaces__srv__CaptureVision_Request__init(mmr_interfaces__srv__CaptureVision_Request * msg)
{
  if (!msg) {
    return false;
  }
  // mode
  // initial_pose
  if (!rosidl_runtime_c__double__Sequence__init(&msg->initial_pose, 0)) {
    mmr_interfaces__srv__CaptureVision_Request__fini(msg);
    return false;
  }
  return true;
}

void
mmr_interfaces__srv__CaptureVision_Request__fini(mmr_interfaces__srv__CaptureVision_Request * msg)
{
  if (!msg) {
    return;
  }
  // mode
  // initial_pose
  rosidl_runtime_c__double__Sequence__fini(&msg->initial_pose);
}

bool
mmr_interfaces__srv__CaptureVision_Request__are_equal(const mmr_interfaces__srv__CaptureVision_Request * lhs, const mmr_interfaces__srv__CaptureVision_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // mode
  if (lhs->mode != rhs->mode) {
    return false;
  }
  // initial_pose
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->initial_pose), &(rhs->initial_pose)))
  {
    return false;
  }
  return true;
}

bool
mmr_interfaces__srv__CaptureVision_Request__copy(
  const mmr_interfaces__srv__CaptureVision_Request * input,
  mmr_interfaces__srv__CaptureVision_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // mode
  output->mode = input->mode;
  // initial_pose
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->initial_pose), &(output->initial_pose)))
  {
    return false;
  }
  return true;
}

mmr_interfaces__srv__CaptureVision_Request *
mmr_interfaces__srv__CaptureVision_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mmr_interfaces__srv__CaptureVision_Request * msg = (mmr_interfaces__srv__CaptureVision_Request *)allocator.allocate(sizeof(mmr_interfaces__srv__CaptureVision_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(mmr_interfaces__srv__CaptureVision_Request));
  bool success = mmr_interfaces__srv__CaptureVision_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
mmr_interfaces__srv__CaptureVision_Request__destroy(mmr_interfaces__srv__CaptureVision_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    mmr_interfaces__srv__CaptureVision_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
mmr_interfaces__srv__CaptureVision_Request__Sequence__init(mmr_interfaces__srv__CaptureVision_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mmr_interfaces__srv__CaptureVision_Request * data = NULL;

  if (size) {
    data = (mmr_interfaces__srv__CaptureVision_Request *)allocator.zero_allocate(size, sizeof(mmr_interfaces__srv__CaptureVision_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = mmr_interfaces__srv__CaptureVision_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        mmr_interfaces__srv__CaptureVision_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
mmr_interfaces__srv__CaptureVision_Request__Sequence__fini(mmr_interfaces__srv__CaptureVision_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      mmr_interfaces__srv__CaptureVision_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

mmr_interfaces__srv__CaptureVision_Request__Sequence *
mmr_interfaces__srv__CaptureVision_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mmr_interfaces__srv__CaptureVision_Request__Sequence * array = (mmr_interfaces__srv__CaptureVision_Request__Sequence *)allocator.allocate(sizeof(mmr_interfaces__srv__CaptureVision_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = mmr_interfaces__srv__CaptureVision_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
mmr_interfaces__srv__CaptureVision_Request__Sequence__destroy(mmr_interfaces__srv__CaptureVision_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    mmr_interfaces__srv__CaptureVision_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
mmr_interfaces__srv__CaptureVision_Request__Sequence__are_equal(const mmr_interfaces__srv__CaptureVision_Request__Sequence * lhs, const mmr_interfaces__srv__CaptureVision_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!mmr_interfaces__srv__CaptureVision_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
mmr_interfaces__srv__CaptureVision_Request__Sequence__copy(
  const mmr_interfaces__srv__CaptureVision_Request__Sequence * input,
  mmr_interfaces__srv__CaptureVision_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(mmr_interfaces__srv__CaptureVision_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    mmr_interfaces__srv__CaptureVision_Request * data =
      (mmr_interfaces__srv__CaptureVision_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!mmr_interfaces__srv__CaptureVision_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          mmr_interfaces__srv__CaptureVision_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!mmr_interfaces__srv__CaptureVision_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `poses_x`
// Member `poses_y`
// Member `poses_z`
// already included above
// #include "rosidl_runtime_c/primitives_sequence_functions.h"
// Member `tags`
#include "rosidl_runtime_c/string_functions.h"

bool
mmr_interfaces__srv__CaptureVision_Response__init(mmr_interfaces__srv__CaptureVision_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // num_objects
  // poses_x
  if (!rosidl_runtime_c__double__Sequence__init(&msg->poses_x, 0)) {
    mmr_interfaces__srv__CaptureVision_Response__fini(msg);
    return false;
  }
  // poses_y
  if (!rosidl_runtime_c__double__Sequence__init(&msg->poses_y, 0)) {
    mmr_interfaces__srv__CaptureVision_Response__fini(msg);
    return false;
  }
  // poses_z
  if (!rosidl_runtime_c__double__Sequence__init(&msg->poses_z, 0)) {
    mmr_interfaces__srv__CaptureVision_Response__fini(msg);
    return false;
  }
  // tags
  if (!rosidl_runtime_c__String__Sequence__init(&msg->tags, 0)) {
    mmr_interfaces__srv__CaptureVision_Response__fini(msg);
    return false;
  }
  return true;
}

void
mmr_interfaces__srv__CaptureVision_Response__fini(mmr_interfaces__srv__CaptureVision_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
  // num_objects
  // poses_x
  rosidl_runtime_c__double__Sequence__fini(&msg->poses_x);
  // poses_y
  rosidl_runtime_c__double__Sequence__fini(&msg->poses_y);
  // poses_z
  rosidl_runtime_c__double__Sequence__fini(&msg->poses_z);
  // tags
  rosidl_runtime_c__String__Sequence__fini(&msg->tags);
}

bool
mmr_interfaces__srv__CaptureVision_Response__are_equal(const mmr_interfaces__srv__CaptureVision_Response * lhs, const mmr_interfaces__srv__CaptureVision_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  // num_objects
  if (lhs->num_objects != rhs->num_objects) {
    return false;
  }
  // poses_x
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->poses_x), &(rhs->poses_x)))
  {
    return false;
  }
  // poses_y
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->poses_y), &(rhs->poses_y)))
  {
    return false;
  }
  // poses_z
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->poses_z), &(rhs->poses_z)))
  {
    return false;
  }
  // tags
  if (!rosidl_runtime_c__String__Sequence__are_equal(
      &(lhs->tags), &(rhs->tags)))
  {
    return false;
  }
  return true;
}

bool
mmr_interfaces__srv__CaptureVision_Response__copy(
  const mmr_interfaces__srv__CaptureVision_Response * input,
  mmr_interfaces__srv__CaptureVision_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  // num_objects
  output->num_objects = input->num_objects;
  // poses_x
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->poses_x), &(output->poses_x)))
  {
    return false;
  }
  // poses_y
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->poses_y), &(output->poses_y)))
  {
    return false;
  }
  // poses_z
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->poses_z), &(output->poses_z)))
  {
    return false;
  }
  // tags
  if (!rosidl_runtime_c__String__Sequence__copy(
      &(input->tags), &(output->tags)))
  {
    return false;
  }
  return true;
}

mmr_interfaces__srv__CaptureVision_Response *
mmr_interfaces__srv__CaptureVision_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mmr_interfaces__srv__CaptureVision_Response * msg = (mmr_interfaces__srv__CaptureVision_Response *)allocator.allocate(sizeof(mmr_interfaces__srv__CaptureVision_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(mmr_interfaces__srv__CaptureVision_Response));
  bool success = mmr_interfaces__srv__CaptureVision_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
mmr_interfaces__srv__CaptureVision_Response__destroy(mmr_interfaces__srv__CaptureVision_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    mmr_interfaces__srv__CaptureVision_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
mmr_interfaces__srv__CaptureVision_Response__Sequence__init(mmr_interfaces__srv__CaptureVision_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mmr_interfaces__srv__CaptureVision_Response * data = NULL;

  if (size) {
    data = (mmr_interfaces__srv__CaptureVision_Response *)allocator.zero_allocate(size, sizeof(mmr_interfaces__srv__CaptureVision_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = mmr_interfaces__srv__CaptureVision_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        mmr_interfaces__srv__CaptureVision_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
mmr_interfaces__srv__CaptureVision_Response__Sequence__fini(mmr_interfaces__srv__CaptureVision_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      mmr_interfaces__srv__CaptureVision_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

mmr_interfaces__srv__CaptureVision_Response__Sequence *
mmr_interfaces__srv__CaptureVision_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mmr_interfaces__srv__CaptureVision_Response__Sequence * array = (mmr_interfaces__srv__CaptureVision_Response__Sequence *)allocator.allocate(sizeof(mmr_interfaces__srv__CaptureVision_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = mmr_interfaces__srv__CaptureVision_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
mmr_interfaces__srv__CaptureVision_Response__Sequence__destroy(mmr_interfaces__srv__CaptureVision_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    mmr_interfaces__srv__CaptureVision_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
mmr_interfaces__srv__CaptureVision_Response__Sequence__are_equal(const mmr_interfaces__srv__CaptureVision_Response__Sequence * lhs, const mmr_interfaces__srv__CaptureVision_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!mmr_interfaces__srv__CaptureVision_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
mmr_interfaces__srv__CaptureVision_Response__Sequence__copy(
  const mmr_interfaces__srv__CaptureVision_Response__Sequence * input,
  mmr_interfaces__srv__CaptureVision_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(mmr_interfaces__srv__CaptureVision_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    mmr_interfaces__srv__CaptureVision_Response * data =
      (mmr_interfaces__srv__CaptureVision_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!mmr_interfaces__srv__CaptureVision_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          mmr_interfaces__srv__CaptureVision_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!mmr_interfaces__srv__CaptureVision_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
