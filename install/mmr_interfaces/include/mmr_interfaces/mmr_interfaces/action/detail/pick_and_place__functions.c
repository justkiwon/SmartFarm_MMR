// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from mmr_interfaces:action/PickAndPlace.idl
// generated code does not contain a copyright notice
#include "mmr_interfaces/action/detail/pick_and_place__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `pick_pose`
// Member `place_pose`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
mmr_interfaces__action__PickAndPlace_Goal__init(mmr_interfaces__action__PickAndPlace_Goal * msg)
{
  if (!msg) {
    return false;
  }
  // pick_pose
  if (!rosidl_runtime_c__double__Sequence__init(&msg->pick_pose, 0)) {
    mmr_interfaces__action__PickAndPlace_Goal__fini(msg);
    return false;
  }
  // place_pose
  if (!rosidl_runtime_c__double__Sequence__init(&msg->place_pose, 0)) {
    mmr_interfaces__action__PickAndPlace_Goal__fini(msg);
    return false;
  }
  return true;
}

void
mmr_interfaces__action__PickAndPlace_Goal__fini(mmr_interfaces__action__PickAndPlace_Goal * msg)
{
  if (!msg) {
    return;
  }
  // pick_pose
  rosidl_runtime_c__double__Sequence__fini(&msg->pick_pose);
  // place_pose
  rosidl_runtime_c__double__Sequence__fini(&msg->place_pose);
}

bool
mmr_interfaces__action__PickAndPlace_Goal__are_equal(const mmr_interfaces__action__PickAndPlace_Goal * lhs, const mmr_interfaces__action__PickAndPlace_Goal * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // pick_pose
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->pick_pose), &(rhs->pick_pose)))
  {
    return false;
  }
  // place_pose
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->place_pose), &(rhs->place_pose)))
  {
    return false;
  }
  return true;
}

bool
mmr_interfaces__action__PickAndPlace_Goal__copy(
  const mmr_interfaces__action__PickAndPlace_Goal * input,
  mmr_interfaces__action__PickAndPlace_Goal * output)
{
  if (!input || !output) {
    return false;
  }
  // pick_pose
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->pick_pose), &(output->pick_pose)))
  {
    return false;
  }
  // place_pose
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->place_pose), &(output->place_pose)))
  {
    return false;
  }
  return true;
}

mmr_interfaces__action__PickAndPlace_Goal *
mmr_interfaces__action__PickAndPlace_Goal__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mmr_interfaces__action__PickAndPlace_Goal * msg = (mmr_interfaces__action__PickAndPlace_Goal *)allocator.allocate(sizeof(mmr_interfaces__action__PickAndPlace_Goal), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(mmr_interfaces__action__PickAndPlace_Goal));
  bool success = mmr_interfaces__action__PickAndPlace_Goal__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
mmr_interfaces__action__PickAndPlace_Goal__destroy(mmr_interfaces__action__PickAndPlace_Goal * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    mmr_interfaces__action__PickAndPlace_Goal__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
mmr_interfaces__action__PickAndPlace_Goal__Sequence__init(mmr_interfaces__action__PickAndPlace_Goal__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mmr_interfaces__action__PickAndPlace_Goal * data = NULL;

  if (size) {
    data = (mmr_interfaces__action__PickAndPlace_Goal *)allocator.zero_allocate(size, sizeof(mmr_interfaces__action__PickAndPlace_Goal), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = mmr_interfaces__action__PickAndPlace_Goal__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        mmr_interfaces__action__PickAndPlace_Goal__fini(&data[i - 1]);
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
mmr_interfaces__action__PickAndPlace_Goal__Sequence__fini(mmr_interfaces__action__PickAndPlace_Goal__Sequence * array)
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
      mmr_interfaces__action__PickAndPlace_Goal__fini(&array->data[i]);
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

mmr_interfaces__action__PickAndPlace_Goal__Sequence *
mmr_interfaces__action__PickAndPlace_Goal__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mmr_interfaces__action__PickAndPlace_Goal__Sequence * array = (mmr_interfaces__action__PickAndPlace_Goal__Sequence *)allocator.allocate(sizeof(mmr_interfaces__action__PickAndPlace_Goal__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = mmr_interfaces__action__PickAndPlace_Goal__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
mmr_interfaces__action__PickAndPlace_Goal__Sequence__destroy(mmr_interfaces__action__PickAndPlace_Goal__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    mmr_interfaces__action__PickAndPlace_Goal__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
mmr_interfaces__action__PickAndPlace_Goal__Sequence__are_equal(const mmr_interfaces__action__PickAndPlace_Goal__Sequence * lhs, const mmr_interfaces__action__PickAndPlace_Goal__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!mmr_interfaces__action__PickAndPlace_Goal__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
mmr_interfaces__action__PickAndPlace_Goal__Sequence__copy(
  const mmr_interfaces__action__PickAndPlace_Goal__Sequence * input,
  mmr_interfaces__action__PickAndPlace_Goal__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(mmr_interfaces__action__PickAndPlace_Goal);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    mmr_interfaces__action__PickAndPlace_Goal * data =
      (mmr_interfaces__action__PickAndPlace_Goal *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!mmr_interfaces__action__PickAndPlace_Goal__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          mmr_interfaces__action__PickAndPlace_Goal__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!mmr_interfaces__action__PickAndPlace_Goal__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `message`
#include "rosidl_runtime_c/string_functions.h"

bool
mmr_interfaces__action__PickAndPlace_Result__init(mmr_interfaces__action__PickAndPlace_Result * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    mmr_interfaces__action__PickAndPlace_Result__fini(msg);
    return false;
  }
  return true;
}

void
mmr_interfaces__action__PickAndPlace_Result__fini(mmr_interfaces__action__PickAndPlace_Result * msg)
{
  if (!msg) {
    return;
  }
  // success
  // message
  rosidl_runtime_c__String__fini(&msg->message);
}

bool
mmr_interfaces__action__PickAndPlace_Result__are_equal(const mmr_interfaces__action__PickAndPlace_Result * lhs, const mmr_interfaces__action__PickAndPlace_Result * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->message), &(rhs->message)))
  {
    return false;
  }
  return true;
}

bool
mmr_interfaces__action__PickAndPlace_Result__copy(
  const mmr_interfaces__action__PickAndPlace_Result * input,
  mmr_interfaces__action__PickAndPlace_Result * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  // message
  if (!rosidl_runtime_c__String__copy(
      &(input->message), &(output->message)))
  {
    return false;
  }
  return true;
}

mmr_interfaces__action__PickAndPlace_Result *
mmr_interfaces__action__PickAndPlace_Result__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mmr_interfaces__action__PickAndPlace_Result * msg = (mmr_interfaces__action__PickAndPlace_Result *)allocator.allocate(sizeof(mmr_interfaces__action__PickAndPlace_Result), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(mmr_interfaces__action__PickAndPlace_Result));
  bool success = mmr_interfaces__action__PickAndPlace_Result__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
mmr_interfaces__action__PickAndPlace_Result__destroy(mmr_interfaces__action__PickAndPlace_Result * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    mmr_interfaces__action__PickAndPlace_Result__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
mmr_interfaces__action__PickAndPlace_Result__Sequence__init(mmr_interfaces__action__PickAndPlace_Result__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mmr_interfaces__action__PickAndPlace_Result * data = NULL;

  if (size) {
    data = (mmr_interfaces__action__PickAndPlace_Result *)allocator.zero_allocate(size, sizeof(mmr_interfaces__action__PickAndPlace_Result), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = mmr_interfaces__action__PickAndPlace_Result__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        mmr_interfaces__action__PickAndPlace_Result__fini(&data[i - 1]);
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
mmr_interfaces__action__PickAndPlace_Result__Sequence__fini(mmr_interfaces__action__PickAndPlace_Result__Sequence * array)
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
      mmr_interfaces__action__PickAndPlace_Result__fini(&array->data[i]);
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

mmr_interfaces__action__PickAndPlace_Result__Sequence *
mmr_interfaces__action__PickAndPlace_Result__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mmr_interfaces__action__PickAndPlace_Result__Sequence * array = (mmr_interfaces__action__PickAndPlace_Result__Sequence *)allocator.allocate(sizeof(mmr_interfaces__action__PickAndPlace_Result__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = mmr_interfaces__action__PickAndPlace_Result__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
mmr_interfaces__action__PickAndPlace_Result__Sequence__destroy(mmr_interfaces__action__PickAndPlace_Result__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    mmr_interfaces__action__PickAndPlace_Result__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
mmr_interfaces__action__PickAndPlace_Result__Sequence__are_equal(const mmr_interfaces__action__PickAndPlace_Result__Sequence * lhs, const mmr_interfaces__action__PickAndPlace_Result__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!mmr_interfaces__action__PickAndPlace_Result__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
mmr_interfaces__action__PickAndPlace_Result__Sequence__copy(
  const mmr_interfaces__action__PickAndPlace_Result__Sequence * input,
  mmr_interfaces__action__PickAndPlace_Result__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(mmr_interfaces__action__PickAndPlace_Result);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    mmr_interfaces__action__PickAndPlace_Result * data =
      (mmr_interfaces__action__PickAndPlace_Result *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!mmr_interfaces__action__PickAndPlace_Result__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          mmr_interfaces__action__PickAndPlace_Result__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!mmr_interfaces__action__PickAndPlace_Result__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `status`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

bool
mmr_interfaces__action__PickAndPlace_Feedback__init(mmr_interfaces__action__PickAndPlace_Feedback * msg)
{
  if (!msg) {
    return false;
  }
  // progress
  // status
  if (!rosidl_runtime_c__String__init(&msg->status)) {
    mmr_interfaces__action__PickAndPlace_Feedback__fini(msg);
    return false;
  }
  return true;
}

void
mmr_interfaces__action__PickAndPlace_Feedback__fini(mmr_interfaces__action__PickAndPlace_Feedback * msg)
{
  if (!msg) {
    return;
  }
  // progress
  // status
  rosidl_runtime_c__String__fini(&msg->status);
}

bool
mmr_interfaces__action__PickAndPlace_Feedback__are_equal(const mmr_interfaces__action__PickAndPlace_Feedback * lhs, const mmr_interfaces__action__PickAndPlace_Feedback * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // progress
  if (lhs->progress != rhs->progress) {
    return false;
  }
  // status
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->status), &(rhs->status)))
  {
    return false;
  }
  return true;
}

bool
mmr_interfaces__action__PickAndPlace_Feedback__copy(
  const mmr_interfaces__action__PickAndPlace_Feedback * input,
  mmr_interfaces__action__PickAndPlace_Feedback * output)
{
  if (!input || !output) {
    return false;
  }
  // progress
  output->progress = input->progress;
  // status
  if (!rosidl_runtime_c__String__copy(
      &(input->status), &(output->status)))
  {
    return false;
  }
  return true;
}

mmr_interfaces__action__PickAndPlace_Feedback *
mmr_interfaces__action__PickAndPlace_Feedback__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mmr_interfaces__action__PickAndPlace_Feedback * msg = (mmr_interfaces__action__PickAndPlace_Feedback *)allocator.allocate(sizeof(mmr_interfaces__action__PickAndPlace_Feedback), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(mmr_interfaces__action__PickAndPlace_Feedback));
  bool success = mmr_interfaces__action__PickAndPlace_Feedback__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
mmr_interfaces__action__PickAndPlace_Feedback__destroy(mmr_interfaces__action__PickAndPlace_Feedback * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    mmr_interfaces__action__PickAndPlace_Feedback__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
mmr_interfaces__action__PickAndPlace_Feedback__Sequence__init(mmr_interfaces__action__PickAndPlace_Feedback__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mmr_interfaces__action__PickAndPlace_Feedback * data = NULL;

  if (size) {
    data = (mmr_interfaces__action__PickAndPlace_Feedback *)allocator.zero_allocate(size, sizeof(mmr_interfaces__action__PickAndPlace_Feedback), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = mmr_interfaces__action__PickAndPlace_Feedback__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        mmr_interfaces__action__PickAndPlace_Feedback__fini(&data[i - 1]);
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
mmr_interfaces__action__PickAndPlace_Feedback__Sequence__fini(mmr_interfaces__action__PickAndPlace_Feedback__Sequence * array)
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
      mmr_interfaces__action__PickAndPlace_Feedback__fini(&array->data[i]);
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

mmr_interfaces__action__PickAndPlace_Feedback__Sequence *
mmr_interfaces__action__PickAndPlace_Feedback__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mmr_interfaces__action__PickAndPlace_Feedback__Sequence * array = (mmr_interfaces__action__PickAndPlace_Feedback__Sequence *)allocator.allocate(sizeof(mmr_interfaces__action__PickAndPlace_Feedback__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = mmr_interfaces__action__PickAndPlace_Feedback__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
mmr_interfaces__action__PickAndPlace_Feedback__Sequence__destroy(mmr_interfaces__action__PickAndPlace_Feedback__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    mmr_interfaces__action__PickAndPlace_Feedback__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
mmr_interfaces__action__PickAndPlace_Feedback__Sequence__are_equal(const mmr_interfaces__action__PickAndPlace_Feedback__Sequence * lhs, const mmr_interfaces__action__PickAndPlace_Feedback__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!mmr_interfaces__action__PickAndPlace_Feedback__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
mmr_interfaces__action__PickAndPlace_Feedback__Sequence__copy(
  const mmr_interfaces__action__PickAndPlace_Feedback__Sequence * input,
  mmr_interfaces__action__PickAndPlace_Feedback__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(mmr_interfaces__action__PickAndPlace_Feedback);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    mmr_interfaces__action__PickAndPlace_Feedback * data =
      (mmr_interfaces__action__PickAndPlace_Feedback *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!mmr_interfaces__action__PickAndPlace_Feedback__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          mmr_interfaces__action__PickAndPlace_Feedback__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!mmr_interfaces__action__PickAndPlace_Feedback__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `goal`
// already included above
// #include "mmr_interfaces/action/detail/pick_and_place__functions.h"

bool
mmr_interfaces__action__PickAndPlace_SendGoal_Request__init(mmr_interfaces__action__PickAndPlace_SendGoal_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    mmr_interfaces__action__PickAndPlace_SendGoal_Request__fini(msg);
    return false;
  }
  // goal
  if (!mmr_interfaces__action__PickAndPlace_Goal__init(&msg->goal)) {
    mmr_interfaces__action__PickAndPlace_SendGoal_Request__fini(msg);
    return false;
  }
  return true;
}

void
mmr_interfaces__action__PickAndPlace_SendGoal_Request__fini(mmr_interfaces__action__PickAndPlace_SendGoal_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // goal
  mmr_interfaces__action__PickAndPlace_Goal__fini(&msg->goal);
}

bool
mmr_interfaces__action__PickAndPlace_SendGoal_Request__are_equal(const mmr_interfaces__action__PickAndPlace_SendGoal_Request * lhs, const mmr_interfaces__action__PickAndPlace_SendGoal_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // goal
  if (!mmr_interfaces__action__PickAndPlace_Goal__are_equal(
      &(lhs->goal), &(rhs->goal)))
  {
    return false;
  }
  return true;
}

bool
mmr_interfaces__action__PickAndPlace_SendGoal_Request__copy(
  const mmr_interfaces__action__PickAndPlace_SendGoal_Request * input,
  mmr_interfaces__action__PickAndPlace_SendGoal_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // goal
  if (!mmr_interfaces__action__PickAndPlace_Goal__copy(
      &(input->goal), &(output->goal)))
  {
    return false;
  }
  return true;
}

mmr_interfaces__action__PickAndPlace_SendGoal_Request *
mmr_interfaces__action__PickAndPlace_SendGoal_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mmr_interfaces__action__PickAndPlace_SendGoal_Request * msg = (mmr_interfaces__action__PickAndPlace_SendGoal_Request *)allocator.allocate(sizeof(mmr_interfaces__action__PickAndPlace_SendGoal_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(mmr_interfaces__action__PickAndPlace_SendGoal_Request));
  bool success = mmr_interfaces__action__PickAndPlace_SendGoal_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
mmr_interfaces__action__PickAndPlace_SendGoal_Request__destroy(mmr_interfaces__action__PickAndPlace_SendGoal_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    mmr_interfaces__action__PickAndPlace_SendGoal_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
mmr_interfaces__action__PickAndPlace_SendGoal_Request__Sequence__init(mmr_interfaces__action__PickAndPlace_SendGoal_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mmr_interfaces__action__PickAndPlace_SendGoal_Request * data = NULL;

  if (size) {
    data = (mmr_interfaces__action__PickAndPlace_SendGoal_Request *)allocator.zero_allocate(size, sizeof(mmr_interfaces__action__PickAndPlace_SendGoal_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = mmr_interfaces__action__PickAndPlace_SendGoal_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        mmr_interfaces__action__PickAndPlace_SendGoal_Request__fini(&data[i - 1]);
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
mmr_interfaces__action__PickAndPlace_SendGoal_Request__Sequence__fini(mmr_interfaces__action__PickAndPlace_SendGoal_Request__Sequence * array)
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
      mmr_interfaces__action__PickAndPlace_SendGoal_Request__fini(&array->data[i]);
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

mmr_interfaces__action__PickAndPlace_SendGoal_Request__Sequence *
mmr_interfaces__action__PickAndPlace_SendGoal_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mmr_interfaces__action__PickAndPlace_SendGoal_Request__Sequence * array = (mmr_interfaces__action__PickAndPlace_SendGoal_Request__Sequence *)allocator.allocate(sizeof(mmr_interfaces__action__PickAndPlace_SendGoal_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = mmr_interfaces__action__PickAndPlace_SendGoal_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
mmr_interfaces__action__PickAndPlace_SendGoal_Request__Sequence__destroy(mmr_interfaces__action__PickAndPlace_SendGoal_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    mmr_interfaces__action__PickAndPlace_SendGoal_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
mmr_interfaces__action__PickAndPlace_SendGoal_Request__Sequence__are_equal(const mmr_interfaces__action__PickAndPlace_SendGoal_Request__Sequence * lhs, const mmr_interfaces__action__PickAndPlace_SendGoal_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!mmr_interfaces__action__PickAndPlace_SendGoal_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
mmr_interfaces__action__PickAndPlace_SendGoal_Request__Sequence__copy(
  const mmr_interfaces__action__PickAndPlace_SendGoal_Request__Sequence * input,
  mmr_interfaces__action__PickAndPlace_SendGoal_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(mmr_interfaces__action__PickAndPlace_SendGoal_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    mmr_interfaces__action__PickAndPlace_SendGoal_Request * data =
      (mmr_interfaces__action__PickAndPlace_SendGoal_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!mmr_interfaces__action__PickAndPlace_SendGoal_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          mmr_interfaces__action__PickAndPlace_SendGoal_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!mmr_interfaces__action__PickAndPlace_SendGoal_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
mmr_interfaces__action__PickAndPlace_SendGoal_Response__init(mmr_interfaces__action__PickAndPlace_SendGoal_Response * msg)
{
  if (!msg) {
    return false;
  }
  // accepted
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    mmr_interfaces__action__PickAndPlace_SendGoal_Response__fini(msg);
    return false;
  }
  return true;
}

void
mmr_interfaces__action__PickAndPlace_SendGoal_Response__fini(mmr_interfaces__action__PickAndPlace_SendGoal_Response * msg)
{
  if (!msg) {
    return;
  }
  // accepted
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
}

bool
mmr_interfaces__action__PickAndPlace_SendGoal_Response__are_equal(const mmr_interfaces__action__PickAndPlace_SendGoal_Response * lhs, const mmr_interfaces__action__PickAndPlace_SendGoal_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // accepted
  if (lhs->accepted != rhs->accepted) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->stamp), &(rhs->stamp)))
  {
    return false;
  }
  return true;
}

bool
mmr_interfaces__action__PickAndPlace_SendGoal_Response__copy(
  const mmr_interfaces__action__PickAndPlace_SendGoal_Response * input,
  mmr_interfaces__action__PickAndPlace_SendGoal_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // accepted
  output->accepted = input->accepted;
  // stamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->stamp), &(output->stamp)))
  {
    return false;
  }
  return true;
}

mmr_interfaces__action__PickAndPlace_SendGoal_Response *
mmr_interfaces__action__PickAndPlace_SendGoal_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mmr_interfaces__action__PickAndPlace_SendGoal_Response * msg = (mmr_interfaces__action__PickAndPlace_SendGoal_Response *)allocator.allocate(sizeof(mmr_interfaces__action__PickAndPlace_SendGoal_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(mmr_interfaces__action__PickAndPlace_SendGoal_Response));
  bool success = mmr_interfaces__action__PickAndPlace_SendGoal_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
mmr_interfaces__action__PickAndPlace_SendGoal_Response__destroy(mmr_interfaces__action__PickAndPlace_SendGoal_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    mmr_interfaces__action__PickAndPlace_SendGoal_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
mmr_interfaces__action__PickAndPlace_SendGoal_Response__Sequence__init(mmr_interfaces__action__PickAndPlace_SendGoal_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mmr_interfaces__action__PickAndPlace_SendGoal_Response * data = NULL;

  if (size) {
    data = (mmr_interfaces__action__PickAndPlace_SendGoal_Response *)allocator.zero_allocate(size, sizeof(mmr_interfaces__action__PickAndPlace_SendGoal_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = mmr_interfaces__action__PickAndPlace_SendGoal_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        mmr_interfaces__action__PickAndPlace_SendGoal_Response__fini(&data[i - 1]);
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
mmr_interfaces__action__PickAndPlace_SendGoal_Response__Sequence__fini(mmr_interfaces__action__PickAndPlace_SendGoal_Response__Sequence * array)
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
      mmr_interfaces__action__PickAndPlace_SendGoal_Response__fini(&array->data[i]);
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

mmr_interfaces__action__PickAndPlace_SendGoal_Response__Sequence *
mmr_interfaces__action__PickAndPlace_SendGoal_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mmr_interfaces__action__PickAndPlace_SendGoal_Response__Sequence * array = (mmr_interfaces__action__PickAndPlace_SendGoal_Response__Sequence *)allocator.allocate(sizeof(mmr_interfaces__action__PickAndPlace_SendGoal_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = mmr_interfaces__action__PickAndPlace_SendGoal_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
mmr_interfaces__action__PickAndPlace_SendGoal_Response__Sequence__destroy(mmr_interfaces__action__PickAndPlace_SendGoal_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    mmr_interfaces__action__PickAndPlace_SendGoal_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
mmr_interfaces__action__PickAndPlace_SendGoal_Response__Sequence__are_equal(const mmr_interfaces__action__PickAndPlace_SendGoal_Response__Sequence * lhs, const mmr_interfaces__action__PickAndPlace_SendGoal_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!mmr_interfaces__action__PickAndPlace_SendGoal_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
mmr_interfaces__action__PickAndPlace_SendGoal_Response__Sequence__copy(
  const mmr_interfaces__action__PickAndPlace_SendGoal_Response__Sequence * input,
  mmr_interfaces__action__PickAndPlace_SendGoal_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(mmr_interfaces__action__PickAndPlace_SendGoal_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    mmr_interfaces__action__PickAndPlace_SendGoal_Response * data =
      (mmr_interfaces__action__PickAndPlace_SendGoal_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!mmr_interfaces__action__PickAndPlace_SendGoal_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          mmr_interfaces__action__PickAndPlace_SendGoal_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!mmr_interfaces__action__PickAndPlace_SendGoal_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"

bool
mmr_interfaces__action__PickAndPlace_GetResult_Request__init(mmr_interfaces__action__PickAndPlace_GetResult_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    mmr_interfaces__action__PickAndPlace_GetResult_Request__fini(msg);
    return false;
  }
  return true;
}

void
mmr_interfaces__action__PickAndPlace_GetResult_Request__fini(mmr_interfaces__action__PickAndPlace_GetResult_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
}

bool
mmr_interfaces__action__PickAndPlace_GetResult_Request__are_equal(const mmr_interfaces__action__PickAndPlace_GetResult_Request * lhs, const mmr_interfaces__action__PickAndPlace_GetResult_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  return true;
}

bool
mmr_interfaces__action__PickAndPlace_GetResult_Request__copy(
  const mmr_interfaces__action__PickAndPlace_GetResult_Request * input,
  mmr_interfaces__action__PickAndPlace_GetResult_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  return true;
}

mmr_interfaces__action__PickAndPlace_GetResult_Request *
mmr_interfaces__action__PickAndPlace_GetResult_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mmr_interfaces__action__PickAndPlace_GetResult_Request * msg = (mmr_interfaces__action__PickAndPlace_GetResult_Request *)allocator.allocate(sizeof(mmr_interfaces__action__PickAndPlace_GetResult_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(mmr_interfaces__action__PickAndPlace_GetResult_Request));
  bool success = mmr_interfaces__action__PickAndPlace_GetResult_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
mmr_interfaces__action__PickAndPlace_GetResult_Request__destroy(mmr_interfaces__action__PickAndPlace_GetResult_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    mmr_interfaces__action__PickAndPlace_GetResult_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
mmr_interfaces__action__PickAndPlace_GetResult_Request__Sequence__init(mmr_interfaces__action__PickAndPlace_GetResult_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mmr_interfaces__action__PickAndPlace_GetResult_Request * data = NULL;

  if (size) {
    data = (mmr_interfaces__action__PickAndPlace_GetResult_Request *)allocator.zero_allocate(size, sizeof(mmr_interfaces__action__PickAndPlace_GetResult_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = mmr_interfaces__action__PickAndPlace_GetResult_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        mmr_interfaces__action__PickAndPlace_GetResult_Request__fini(&data[i - 1]);
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
mmr_interfaces__action__PickAndPlace_GetResult_Request__Sequence__fini(mmr_interfaces__action__PickAndPlace_GetResult_Request__Sequence * array)
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
      mmr_interfaces__action__PickAndPlace_GetResult_Request__fini(&array->data[i]);
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

mmr_interfaces__action__PickAndPlace_GetResult_Request__Sequence *
mmr_interfaces__action__PickAndPlace_GetResult_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mmr_interfaces__action__PickAndPlace_GetResult_Request__Sequence * array = (mmr_interfaces__action__PickAndPlace_GetResult_Request__Sequence *)allocator.allocate(sizeof(mmr_interfaces__action__PickAndPlace_GetResult_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = mmr_interfaces__action__PickAndPlace_GetResult_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
mmr_interfaces__action__PickAndPlace_GetResult_Request__Sequence__destroy(mmr_interfaces__action__PickAndPlace_GetResult_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    mmr_interfaces__action__PickAndPlace_GetResult_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
mmr_interfaces__action__PickAndPlace_GetResult_Request__Sequence__are_equal(const mmr_interfaces__action__PickAndPlace_GetResult_Request__Sequence * lhs, const mmr_interfaces__action__PickAndPlace_GetResult_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!mmr_interfaces__action__PickAndPlace_GetResult_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
mmr_interfaces__action__PickAndPlace_GetResult_Request__Sequence__copy(
  const mmr_interfaces__action__PickAndPlace_GetResult_Request__Sequence * input,
  mmr_interfaces__action__PickAndPlace_GetResult_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(mmr_interfaces__action__PickAndPlace_GetResult_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    mmr_interfaces__action__PickAndPlace_GetResult_Request * data =
      (mmr_interfaces__action__PickAndPlace_GetResult_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!mmr_interfaces__action__PickAndPlace_GetResult_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          mmr_interfaces__action__PickAndPlace_GetResult_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!mmr_interfaces__action__PickAndPlace_GetResult_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `result`
// already included above
// #include "mmr_interfaces/action/detail/pick_and_place__functions.h"

bool
mmr_interfaces__action__PickAndPlace_GetResult_Response__init(mmr_interfaces__action__PickAndPlace_GetResult_Response * msg)
{
  if (!msg) {
    return false;
  }
  // status
  // result
  if (!mmr_interfaces__action__PickAndPlace_Result__init(&msg->result)) {
    mmr_interfaces__action__PickAndPlace_GetResult_Response__fini(msg);
    return false;
  }
  return true;
}

void
mmr_interfaces__action__PickAndPlace_GetResult_Response__fini(mmr_interfaces__action__PickAndPlace_GetResult_Response * msg)
{
  if (!msg) {
    return;
  }
  // status
  // result
  mmr_interfaces__action__PickAndPlace_Result__fini(&msg->result);
}

bool
mmr_interfaces__action__PickAndPlace_GetResult_Response__are_equal(const mmr_interfaces__action__PickAndPlace_GetResult_Response * lhs, const mmr_interfaces__action__PickAndPlace_GetResult_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // status
  if (lhs->status != rhs->status) {
    return false;
  }
  // result
  if (!mmr_interfaces__action__PickAndPlace_Result__are_equal(
      &(lhs->result), &(rhs->result)))
  {
    return false;
  }
  return true;
}

bool
mmr_interfaces__action__PickAndPlace_GetResult_Response__copy(
  const mmr_interfaces__action__PickAndPlace_GetResult_Response * input,
  mmr_interfaces__action__PickAndPlace_GetResult_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // status
  output->status = input->status;
  // result
  if (!mmr_interfaces__action__PickAndPlace_Result__copy(
      &(input->result), &(output->result)))
  {
    return false;
  }
  return true;
}

mmr_interfaces__action__PickAndPlace_GetResult_Response *
mmr_interfaces__action__PickAndPlace_GetResult_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mmr_interfaces__action__PickAndPlace_GetResult_Response * msg = (mmr_interfaces__action__PickAndPlace_GetResult_Response *)allocator.allocate(sizeof(mmr_interfaces__action__PickAndPlace_GetResult_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(mmr_interfaces__action__PickAndPlace_GetResult_Response));
  bool success = mmr_interfaces__action__PickAndPlace_GetResult_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
mmr_interfaces__action__PickAndPlace_GetResult_Response__destroy(mmr_interfaces__action__PickAndPlace_GetResult_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    mmr_interfaces__action__PickAndPlace_GetResult_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
mmr_interfaces__action__PickAndPlace_GetResult_Response__Sequence__init(mmr_interfaces__action__PickAndPlace_GetResult_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mmr_interfaces__action__PickAndPlace_GetResult_Response * data = NULL;

  if (size) {
    data = (mmr_interfaces__action__PickAndPlace_GetResult_Response *)allocator.zero_allocate(size, sizeof(mmr_interfaces__action__PickAndPlace_GetResult_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = mmr_interfaces__action__PickAndPlace_GetResult_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        mmr_interfaces__action__PickAndPlace_GetResult_Response__fini(&data[i - 1]);
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
mmr_interfaces__action__PickAndPlace_GetResult_Response__Sequence__fini(mmr_interfaces__action__PickAndPlace_GetResult_Response__Sequence * array)
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
      mmr_interfaces__action__PickAndPlace_GetResult_Response__fini(&array->data[i]);
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

mmr_interfaces__action__PickAndPlace_GetResult_Response__Sequence *
mmr_interfaces__action__PickAndPlace_GetResult_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mmr_interfaces__action__PickAndPlace_GetResult_Response__Sequence * array = (mmr_interfaces__action__PickAndPlace_GetResult_Response__Sequence *)allocator.allocate(sizeof(mmr_interfaces__action__PickAndPlace_GetResult_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = mmr_interfaces__action__PickAndPlace_GetResult_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
mmr_interfaces__action__PickAndPlace_GetResult_Response__Sequence__destroy(mmr_interfaces__action__PickAndPlace_GetResult_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    mmr_interfaces__action__PickAndPlace_GetResult_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
mmr_interfaces__action__PickAndPlace_GetResult_Response__Sequence__are_equal(const mmr_interfaces__action__PickAndPlace_GetResult_Response__Sequence * lhs, const mmr_interfaces__action__PickAndPlace_GetResult_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!mmr_interfaces__action__PickAndPlace_GetResult_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
mmr_interfaces__action__PickAndPlace_GetResult_Response__Sequence__copy(
  const mmr_interfaces__action__PickAndPlace_GetResult_Response__Sequence * input,
  mmr_interfaces__action__PickAndPlace_GetResult_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(mmr_interfaces__action__PickAndPlace_GetResult_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    mmr_interfaces__action__PickAndPlace_GetResult_Response * data =
      (mmr_interfaces__action__PickAndPlace_GetResult_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!mmr_interfaces__action__PickAndPlace_GetResult_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          mmr_interfaces__action__PickAndPlace_GetResult_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!mmr_interfaces__action__PickAndPlace_GetResult_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `feedback`
// already included above
// #include "mmr_interfaces/action/detail/pick_and_place__functions.h"

bool
mmr_interfaces__action__PickAndPlace_FeedbackMessage__init(mmr_interfaces__action__PickAndPlace_FeedbackMessage * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    mmr_interfaces__action__PickAndPlace_FeedbackMessage__fini(msg);
    return false;
  }
  // feedback
  if (!mmr_interfaces__action__PickAndPlace_Feedback__init(&msg->feedback)) {
    mmr_interfaces__action__PickAndPlace_FeedbackMessage__fini(msg);
    return false;
  }
  return true;
}

void
mmr_interfaces__action__PickAndPlace_FeedbackMessage__fini(mmr_interfaces__action__PickAndPlace_FeedbackMessage * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // feedback
  mmr_interfaces__action__PickAndPlace_Feedback__fini(&msg->feedback);
}

bool
mmr_interfaces__action__PickAndPlace_FeedbackMessage__are_equal(const mmr_interfaces__action__PickAndPlace_FeedbackMessage * lhs, const mmr_interfaces__action__PickAndPlace_FeedbackMessage * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // feedback
  if (!mmr_interfaces__action__PickAndPlace_Feedback__are_equal(
      &(lhs->feedback), &(rhs->feedback)))
  {
    return false;
  }
  return true;
}

bool
mmr_interfaces__action__PickAndPlace_FeedbackMessage__copy(
  const mmr_interfaces__action__PickAndPlace_FeedbackMessage * input,
  mmr_interfaces__action__PickAndPlace_FeedbackMessage * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // feedback
  if (!mmr_interfaces__action__PickAndPlace_Feedback__copy(
      &(input->feedback), &(output->feedback)))
  {
    return false;
  }
  return true;
}

mmr_interfaces__action__PickAndPlace_FeedbackMessage *
mmr_interfaces__action__PickAndPlace_FeedbackMessage__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mmr_interfaces__action__PickAndPlace_FeedbackMessage * msg = (mmr_interfaces__action__PickAndPlace_FeedbackMessage *)allocator.allocate(sizeof(mmr_interfaces__action__PickAndPlace_FeedbackMessage), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(mmr_interfaces__action__PickAndPlace_FeedbackMessage));
  bool success = mmr_interfaces__action__PickAndPlace_FeedbackMessage__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
mmr_interfaces__action__PickAndPlace_FeedbackMessage__destroy(mmr_interfaces__action__PickAndPlace_FeedbackMessage * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    mmr_interfaces__action__PickAndPlace_FeedbackMessage__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
mmr_interfaces__action__PickAndPlace_FeedbackMessage__Sequence__init(mmr_interfaces__action__PickAndPlace_FeedbackMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mmr_interfaces__action__PickAndPlace_FeedbackMessage * data = NULL;

  if (size) {
    data = (mmr_interfaces__action__PickAndPlace_FeedbackMessage *)allocator.zero_allocate(size, sizeof(mmr_interfaces__action__PickAndPlace_FeedbackMessage), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = mmr_interfaces__action__PickAndPlace_FeedbackMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        mmr_interfaces__action__PickAndPlace_FeedbackMessage__fini(&data[i - 1]);
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
mmr_interfaces__action__PickAndPlace_FeedbackMessage__Sequence__fini(mmr_interfaces__action__PickAndPlace_FeedbackMessage__Sequence * array)
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
      mmr_interfaces__action__PickAndPlace_FeedbackMessage__fini(&array->data[i]);
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

mmr_interfaces__action__PickAndPlace_FeedbackMessage__Sequence *
mmr_interfaces__action__PickAndPlace_FeedbackMessage__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mmr_interfaces__action__PickAndPlace_FeedbackMessage__Sequence * array = (mmr_interfaces__action__PickAndPlace_FeedbackMessage__Sequence *)allocator.allocate(sizeof(mmr_interfaces__action__PickAndPlace_FeedbackMessage__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = mmr_interfaces__action__PickAndPlace_FeedbackMessage__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
mmr_interfaces__action__PickAndPlace_FeedbackMessage__Sequence__destroy(mmr_interfaces__action__PickAndPlace_FeedbackMessage__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    mmr_interfaces__action__PickAndPlace_FeedbackMessage__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
mmr_interfaces__action__PickAndPlace_FeedbackMessage__Sequence__are_equal(const mmr_interfaces__action__PickAndPlace_FeedbackMessage__Sequence * lhs, const mmr_interfaces__action__PickAndPlace_FeedbackMessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!mmr_interfaces__action__PickAndPlace_FeedbackMessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
mmr_interfaces__action__PickAndPlace_FeedbackMessage__Sequence__copy(
  const mmr_interfaces__action__PickAndPlace_FeedbackMessage__Sequence * input,
  mmr_interfaces__action__PickAndPlace_FeedbackMessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(mmr_interfaces__action__PickAndPlace_FeedbackMessage);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    mmr_interfaces__action__PickAndPlace_FeedbackMessage * data =
      (mmr_interfaces__action__PickAndPlace_FeedbackMessage *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!mmr_interfaces__action__PickAndPlace_FeedbackMessage__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          mmr_interfaces__action__PickAndPlace_FeedbackMessage__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!mmr_interfaces__action__PickAndPlace_FeedbackMessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
