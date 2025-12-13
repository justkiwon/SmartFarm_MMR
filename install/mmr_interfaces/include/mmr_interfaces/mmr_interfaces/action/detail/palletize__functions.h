// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from mmr_interfaces:action/Palletize.idl
// generated code does not contain a copyright notice

#ifndef MMR_INTERFACES__ACTION__DETAIL__PALLETIZE__FUNCTIONS_H_
#define MMR_INTERFACES__ACTION__DETAIL__PALLETIZE__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "mmr_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "mmr_interfaces/action/detail/palletize__struct.h"

/// Initialize action/Palletize message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * mmr_interfaces__action__Palletize_Goal
 * )) before or use
 * mmr_interfaces__action__Palletize_Goal__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
bool
mmr_interfaces__action__Palletize_Goal__init(mmr_interfaces__action__Palletize_Goal * msg);

/// Finalize action/Palletize message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
void
mmr_interfaces__action__Palletize_Goal__fini(mmr_interfaces__action__Palletize_Goal * msg);

/// Create action/Palletize message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * mmr_interfaces__action__Palletize_Goal__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
mmr_interfaces__action__Palletize_Goal *
mmr_interfaces__action__Palletize_Goal__create();

/// Destroy action/Palletize message.
/**
 * It calls
 * mmr_interfaces__action__Palletize_Goal__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
void
mmr_interfaces__action__Palletize_Goal__destroy(mmr_interfaces__action__Palletize_Goal * msg);

/// Check for action/Palletize message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
bool
mmr_interfaces__action__Palletize_Goal__are_equal(const mmr_interfaces__action__Palletize_Goal * lhs, const mmr_interfaces__action__Palletize_Goal * rhs);

/// Copy a action/Palletize message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
bool
mmr_interfaces__action__Palletize_Goal__copy(
  const mmr_interfaces__action__Palletize_Goal * input,
  mmr_interfaces__action__Palletize_Goal * output);

/// Initialize array of action/Palletize messages.
/**
 * It allocates the memory for the number of elements and calls
 * mmr_interfaces__action__Palletize_Goal__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
bool
mmr_interfaces__action__Palletize_Goal__Sequence__init(mmr_interfaces__action__Palletize_Goal__Sequence * array, size_t size);

/// Finalize array of action/Palletize messages.
/**
 * It calls
 * mmr_interfaces__action__Palletize_Goal__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
void
mmr_interfaces__action__Palletize_Goal__Sequence__fini(mmr_interfaces__action__Palletize_Goal__Sequence * array);

/// Create array of action/Palletize messages.
/**
 * It allocates the memory for the array and calls
 * mmr_interfaces__action__Palletize_Goal__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
mmr_interfaces__action__Palletize_Goal__Sequence *
mmr_interfaces__action__Palletize_Goal__Sequence__create(size_t size);

/// Destroy array of action/Palletize messages.
/**
 * It calls
 * mmr_interfaces__action__Palletize_Goal__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
void
mmr_interfaces__action__Palletize_Goal__Sequence__destroy(mmr_interfaces__action__Palletize_Goal__Sequence * array);

/// Check for action/Palletize message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
bool
mmr_interfaces__action__Palletize_Goal__Sequence__are_equal(const mmr_interfaces__action__Palletize_Goal__Sequence * lhs, const mmr_interfaces__action__Palletize_Goal__Sequence * rhs);

/// Copy an array of action/Palletize messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
bool
mmr_interfaces__action__Palletize_Goal__Sequence__copy(
  const mmr_interfaces__action__Palletize_Goal__Sequence * input,
  mmr_interfaces__action__Palletize_Goal__Sequence * output);

/// Initialize action/Palletize message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * mmr_interfaces__action__Palletize_Result
 * )) before or use
 * mmr_interfaces__action__Palletize_Result__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
bool
mmr_interfaces__action__Palletize_Result__init(mmr_interfaces__action__Palletize_Result * msg);

/// Finalize action/Palletize message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
void
mmr_interfaces__action__Palletize_Result__fini(mmr_interfaces__action__Palletize_Result * msg);

/// Create action/Palletize message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * mmr_interfaces__action__Palletize_Result__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
mmr_interfaces__action__Palletize_Result *
mmr_interfaces__action__Palletize_Result__create();

/// Destroy action/Palletize message.
/**
 * It calls
 * mmr_interfaces__action__Palletize_Result__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
void
mmr_interfaces__action__Palletize_Result__destroy(mmr_interfaces__action__Palletize_Result * msg);

/// Check for action/Palletize message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
bool
mmr_interfaces__action__Palletize_Result__are_equal(const mmr_interfaces__action__Palletize_Result * lhs, const mmr_interfaces__action__Palletize_Result * rhs);

/// Copy a action/Palletize message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
bool
mmr_interfaces__action__Palletize_Result__copy(
  const mmr_interfaces__action__Palletize_Result * input,
  mmr_interfaces__action__Palletize_Result * output);

/// Initialize array of action/Palletize messages.
/**
 * It allocates the memory for the number of elements and calls
 * mmr_interfaces__action__Palletize_Result__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
bool
mmr_interfaces__action__Palletize_Result__Sequence__init(mmr_interfaces__action__Palletize_Result__Sequence * array, size_t size);

/// Finalize array of action/Palletize messages.
/**
 * It calls
 * mmr_interfaces__action__Palletize_Result__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
void
mmr_interfaces__action__Palletize_Result__Sequence__fini(mmr_interfaces__action__Palletize_Result__Sequence * array);

/// Create array of action/Palletize messages.
/**
 * It allocates the memory for the array and calls
 * mmr_interfaces__action__Palletize_Result__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
mmr_interfaces__action__Palletize_Result__Sequence *
mmr_interfaces__action__Palletize_Result__Sequence__create(size_t size);

/// Destroy array of action/Palletize messages.
/**
 * It calls
 * mmr_interfaces__action__Palletize_Result__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
void
mmr_interfaces__action__Palletize_Result__Sequence__destroy(mmr_interfaces__action__Palletize_Result__Sequence * array);

/// Check for action/Palletize message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
bool
mmr_interfaces__action__Palletize_Result__Sequence__are_equal(const mmr_interfaces__action__Palletize_Result__Sequence * lhs, const mmr_interfaces__action__Palletize_Result__Sequence * rhs);

/// Copy an array of action/Palletize messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
bool
mmr_interfaces__action__Palletize_Result__Sequence__copy(
  const mmr_interfaces__action__Palletize_Result__Sequence * input,
  mmr_interfaces__action__Palletize_Result__Sequence * output);

/// Initialize action/Palletize message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * mmr_interfaces__action__Palletize_Feedback
 * )) before or use
 * mmr_interfaces__action__Palletize_Feedback__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
bool
mmr_interfaces__action__Palletize_Feedback__init(mmr_interfaces__action__Palletize_Feedback * msg);

/// Finalize action/Palletize message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
void
mmr_interfaces__action__Palletize_Feedback__fini(mmr_interfaces__action__Palletize_Feedback * msg);

/// Create action/Palletize message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * mmr_interfaces__action__Palletize_Feedback__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
mmr_interfaces__action__Palletize_Feedback *
mmr_interfaces__action__Palletize_Feedback__create();

/// Destroy action/Palletize message.
/**
 * It calls
 * mmr_interfaces__action__Palletize_Feedback__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
void
mmr_interfaces__action__Palletize_Feedback__destroy(mmr_interfaces__action__Palletize_Feedback * msg);

/// Check for action/Palletize message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
bool
mmr_interfaces__action__Palletize_Feedback__are_equal(const mmr_interfaces__action__Palletize_Feedback * lhs, const mmr_interfaces__action__Palletize_Feedback * rhs);

/// Copy a action/Palletize message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
bool
mmr_interfaces__action__Palletize_Feedback__copy(
  const mmr_interfaces__action__Palletize_Feedback * input,
  mmr_interfaces__action__Palletize_Feedback * output);

/// Initialize array of action/Palletize messages.
/**
 * It allocates the memory for the number of elements and calls
 * mmr_interfaces__action__Palletize_Feedback__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
bool
mmr_interfaces__action__Palletize_Feedback__Sequence__init(mmr_interfaces__action__Palletize_Feedback__Sequence * array, size_t size);

/// Finalize array of action/Palletize messages.
/**
 * It calls
 * mmr_interfaces__action__Palletize_Feedback__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
void
mmr_interfaces__action__Palletize_Feedback__Sequence__fini(mmr_interfaces__action__Palletize_Feedback__Sequence * array);

/// Create array of action/Palletize messages.
/**
 * It allocates the memory for the array and calls
 * mmr_interfaces__action__Palletize_Feedback__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
mmr_interfaces__action__Palletize_Feedback__Sequence *
mmr_interfaces__action__Palletize_Feedback__Sequence__create(size_t size);

/// Destroy array of action/Palletize messages.
/**
 * It calls
 * mmr_interfaces__action__Palletize_Feedback__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
void
mmr_interfaces__action__Palletize_Feedback__Sequence__destroy(mmr_interfaces__action__Palletize_Feedback__Sequence * array);

/// Check for action/Palletize message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
bool
mmr_interfaces__action__Palletize_Feedback__Sequence__are_equal(const mmr_interfaces__action__Palletize_Feedback__Sequence * lhs, const mmr_interfaces__action__Palletize_Feedback__Sequence * rhs);

/// Copy an array of action/Palletize messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
bool
mmr_interfaces__action__Palletize_Feedback__Sequence__copy(
  const mmr_interfaces__action__Palletize_Feedback__Sequence * input,
  mmr_interfaces__action__Palletize_Feedback__Sequence * output);

/// Initialize action/Palletize message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * mmr_interfaces__action__Palletize_SendGoal_Request
 * )) before or use
 * mmr_interfaces__action__Palletize_SendGoal_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
bool
mmr_interfaces__action__Palletize_SendGoal_Request__init(mmr_interfaces__action__Palletize_SendGoal_Request * msg);

/// Finalize action/Palletize message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
void
mmr_interfaces__action__Palletize_SendGoal_Request__fini(mmr_interfaces__action__Palletize_SendGoal_Request * msg);

/// Create action/Palletize message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * mmr_interfaces__action__Palletize_SendGoal_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
mmr_interfaces__action__Palletize_SendGoal_Request *
mmr_interfaces__action__Palletize_SendGoal_Request__create();

/// Destroy action/Palletize message.
/**
 * It calls
 * mmr_interfaces__action__Palletize_SendGoal_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
void
mmr_interfaces__action__Palletize_SendGoal_Request__destroy(mmr_interfaces__action__Palletize_SendGoal_Request * msg);

/// Check for action/Palletize message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
bool
mmr_interfaces__action__Palletize_SendGoal_Request__are_equal(const mmr_interfaces__action__Palletize_SendGoal_Request * lhs, const mmr_interfaces__action__Palletize_SendGoal_Request * rhs);

/// Copy a action/Palletize message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
bool
mmr_interfaces__action__Palletize_SendGoal_Request__copy(
  const mmr_interfaces__action__Palletize_SendGoal_Request * input,
  mmr_interfaces__action__Palletize_SendGoal_Request * output);

/// Initialize array of action/Palletize messages.
/**
 * It allocates the memory for the number of elements and calls
 * mmr_interfaces__action__Palletize_SendGoal_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
bool
mmr_interfaces__action__Palletize_SendGoal_Request__Sequence__init(mmr_interfaces__action__Palletize_SendGoal_Request__Sequence * array, size_t size);

/// Finalize array of action/Palletize messages.
/**
 * It calls
 * mmr_interfaces__action__Palletize_SendGoal_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
void
mmr_interfaces__action__Palletize_SendGoal_Request__Sequence__fini(mmr_interfaces__action__Palletize_SendGoal_Request__Sequence * array);

/// Create array of action/Palletize messages.
/**
 * It allocates the memory for the array and calls
 * mmr_interfaces__action__Palletize_SendGoal_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
mmr_interfaces__action__Palletize_SendGoal_Request__Sequence *
mmr_interfaces__action__Palletize_SendGoal_Request__Sequence__create(size_t size);

/// Destroy array of action/Palletize messages.
/**
 * It calls
 * mmr_interfaces__action__Palletize_SendGoal_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
void
mmr_interfaces__action__Palletize_SendGoal_Request__Sequence__destroy(mmr_interfaces__action__Palletize_SendGoal_Request__Sequence * array);

/// Check for action/Palletize message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
bool
mmr_interfaces__action__Palletize_SendGoal_Request__Sequence__are_equal(const mmr_interfaces__action__Palletize_SendGoal_Request__Sequence * lhs, const mmr_interfaces__action__Palletize_SendGoal_Request__Sequence * rhs);

/// Copy an array of action/Palletize messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
bool
mmr_interfaces__action__Palletize_SendGoal_Request__Sequence__copy(
  const mmr_interfaces__action__Palletize_SendGoal_Request__Sequence * input,
  mmr_interfaces__action__Palletize_SendGoal_Request__Sequence * output);

/// Initialize action/Palletize message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * mmr_interfaces__action__Palletize_SendGoal_Response
 * )) before or use
 * mmr_interfaces__action__Palletize_SendGoal_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
bool
mmr_interfaces__action__Palletize_SendGoal_Response__init(mmr_interfaces__action__Palletize_SendGoal_Response * msg);

/// Finalize action/Palletize message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
void
mmr_interfaces__action__Palletize_SendGoal_Response__fini(mmr_interfaces__action__Palletize_SendGoal_Response * msg);

/// Create action/Palletize message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * mmr_interfaces__action__Palletize_SendGoal_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
mmr_interfaces__action__Palletize_SendGoal_Response *
mmr_interfaces__action__Palletize_SendGoal_Response__create();

/// Destroy action/Palletize message.
/**
 * It calls
 * mmr_interfaces__action__Palletize_SendGoal_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
void
mmr_interfaces__action__Palletize_SendGoal_Response__destroy(mmr_interfaces__action__Palletize_SendGoal_Response * msg);

/// Check for action/Palletize message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
bool
mmr_interfaces__action__Palletize_SendGoal_Response__are_equal(const mmr_interfaces__action__Palletize_SendGoal_Response * lhs, const mmr_interfaces__action__Palletize_SendGoal_Response * rhs);

/// Copy a action/Palletize message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
bool
mmr_interfaces__action__Palletize_SendGoal_Response__copy(
  const mmr_interfaces__action__Palletize_SendGoal_Response * input,
  mmr_interfaces__action__Palletize_SendGoal_Response * output);

/// Initialize array of action/Palletize messages.
/**
 * It allocates the memory for the number of elements and calls
 * mmr_interfaces__action__Palletize_SendGoal_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
bool
mmr_interfaces__action__Palletize_SendGoal_Response__Sequence__init(mmr_interfaces__action__Palletize_SendGoal_Response__Sequence * array, size_t size);

/// Finalize array of action/Palletize messages.
/**
 * It calls
 * mmr_interfaces__action__Palletize_SendGoal_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
void
mmr_interfaces__action__Palletize_SendGoal_Response__Sequence__fini(mmr_interfaces__action__Palletize_SendGoal_Response__Sequence * array);

/// Create array of action/Palletize messages.
/**
 * It allocates the memory for the array and calls
 * mmr_interfaces__action__Palletize_SendGoal_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
mmr_interfaces__action__Palletize_SendGoal_Response__Sequence *
mmr_interfaces__action__Palletize_SendGoal_Response__Sequence__create(size_t size);

/// Destroy array of action/Palletize messages.
/**
 * It calls
 * mmr_interfaces__action__Palletize_SendGoal_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
void
mmr_interfaces__action__Palletize_SendGoal_Response__Sequence__destroy(mmr_interfaces__action__Palletize_SendGoal_Response__Sequence * array);

/// Check for action/Palletize message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
bool
mmr_interfaces__action__Palletize_SendGoal_Response__Sequence__are_equal(const mmr_interfaces__action__Palletize_SendGoal_Response__Sequence * lhs, const mmr_interfaces__action__Palletize_SendGoal_Response__Sequence * rhs);

/// Copy an array of action/Palletize messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
bool
mmr_interfaces__action__Palletize_SendGoal_Response__Sequence__copy(
  const mmr_interfaces__action__Palletize_SendGoal_Response__Sequence * input,
  mmr_interfaces__action__Palletize_SendGoal_Response__Sequence * output);

/// Initialize action/Palletize message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * mmr_interfaces__action__Palletize_GetResult_Request
 * )) before or use
 * mmr_interfaces__action__Palletize_GetResult_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
bool
mmr_interfaces__action__Palletize_GetResult_Request__init(mmr_interfaces__action__Palletize_GetResult_Request * msg);

/// Finalize action/Palletize message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
void
mmr_interfaces__action__Palletize_GetResult_Request__fini(mmr_interfaces__action__Palletize_GetResult_Request * msg);

/// Create action/Palletize message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * mmr_interfaces__action__Palletize_GetResult_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
mmr_interfaces__action__Palletize_GetResult_Request *
mmr_interfaces__action__Palletize_GetResult_Request__create();

/// Destroy action/Palletize message.
/**
 * It calls
 * mmr_interfaces__action__Palletize_GetResult_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
void
mmr_interfaces__action__Palletize_GetResult_Request__destroy(mmr_interfaces__action__Palletize_GetResult_Request * msg);

/// Check for action/Palletize message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
bool
mmr_interfaces__action__Palletize_GetResult_Request__are_equal(const mmr_interfaces__action__Palletize_GetResult_Request * lhs, const mmr_interfaces__action__Palletize_GetResult_Request * rhs);

/// Copy a action/Palletize message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
bool
mmr_interfaces__action__Palletize_GetResult_Request__copy(
  const mmr_interfaces__action__Palletize_GetResult_Request * input,
  mmr_interfaces__action__Palletize_GetResult_Request * output);

/// Initialize array of action/Palletize messages.
/**
 * It allocates the memory for the number of elements and calls
 * mmr_interfaces__action__Palletize_GetResult_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
bool
mmr_interfaces__action__Palletize_GetResult_Request__Sequence__init(mmr_interfaces__action__Palletize_GetResult_Request__Sequence * array, size_t size);

/// Finalize array of action/Palletize messages.
/**
 * It calls
 * mmr_interfaces__action__Palletize_GetResult_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
void
mmr_interfaces__action__Palletize_GetResult_Request__Sequence__fini(mmr_interfaces__action__Palletize_GetResult_Request__Sequence * array);

/// Create array of action/Palletize messages.
/**
 * It allocates the memory for the array and calls
 * mmr_interfaces__action__Palletize_GetResult_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
mmr_interfaces__action__Palletize_GetResult_Request__Sequence *
mmr_interfaces__action__Palletize_GetResult_Request__Sequence__create(size_t size);

/// Destroy array of action/Palletize messages.
/**
 * It calls
 * mmr_interfaces__action__Palletize_GetResult_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
void
mmr_interfaces__action__Palletize_GetResult_Request__Sequence__destroy(mmr_interfaces__action__Palletize_GetResult_Request__Sequence * array);

/// Check for action/Palletize message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
bool
mmr_interfaces__action__Palletize_GetResult_Request__Sequence__are_equal(const mmr_interfaces__action__Palletize_GetResult_Request__Sequence * lhs, const mmr_interfaces__action__Palletize_GetResult_Request__Sequence * rhs);

/// Copy an array of action/Palletize messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
bool
mmr_interfaces__action__Palletize_GetResult_Request__Sequence__copy(
  const mmr_interfaces__action__Palletize_GetResult_Request__Sequence * input,
  mmr_interfaces__action__Palletize_GetResult_Request__Sequence * output);

/// Initialize action/Palletize message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * mmr_interfaces__action__Palletize_GetResult_Response
 * )) before or use
 * mmr_interfaces__action__Palletize_GetResult_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
bool
mmr_interfaces__action__Palletize_GetResult_Response__init(mmr_interfaces__action__Palletize_GetResult_Response * msg);

/// Finalize action/Palletize message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
void
mmr_interfaces__action__Palletize_GetResult_Response__fini(mmr_interfaces__action__Palletize_GetResult_Response * msg);

/// Create action/Palletize message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * mmr_interfaces__action__Palletize_GetResult_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
mmr_interfaces__action__Palletize_GetResult_Response *
mmr_interfaces__action__Palletize_GetResult_Response__create();

/// Destroy action/Palletize message.
/**
 * It calls
 * mmr_interfaces__action__Palletize_GetResult_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
void
mmr_interfaces__action__Palletize_GetResult_Response__destroy(mmr_interfaces__action__Palletize_GetResult_Response * msg);

/// Check for action/Palletize message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
bool
mmr_interfaces__action__Palletize_GetResult_Response__are_equal(const mmr_interfaces__action__Palletize_GetResult_Response * lhs, const mmr_interfaces__action__Palletize_GetResult_Response * rhs);

/// Copy a action/Palletize message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
bool
mmr_interfaces__action__Palletize_GetResult_Response__copy(
  const mmr_interfaces__action__Palletize_GetResult_Response * input,
  mmr_interfaces__action__Palletize_GetResult_Response * output);

/// Initialize array of action/Palletize messages.
/**
 * It allocates the memory for the number of elements and calls
 * mmr_interfaces__action__Palletize_GetResult_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
bool
mmr_interfaces__action__Palletize_GetResult_Response__Sequence__init(mmr_interfaces__action__Palletize_GetResult_Response__Sequence * array, size_t size);

/// Finalize array of action/Palletize messages.
/**
 * It calls
 * mmr_interfaces__action__Palletize_GetResult_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
void
mmr_interfaces__action__Palletize_GetResult_Response__Sequence__fini(mmr_interfaces__action__Palletize_GetResult_Response__Sequence * array);

/// Create array of action/Palletize messages.
/**
 * It allocates the memory for the array and calls
 * mmr_interfaces__action__Palletize_GetResult_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
mmr_interfaces__action__Palletize_GetResult_Response__Sequence *
mmr_interfaces__action__Palletize_GetResult_Response__Sequence__create(size_t size);

/// Destroy array of action/Palletize messages.
/**
 * It calls
 * mmr_interfaces__action__Palletize_GetResult_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
void
mmr_interfaces__action__Palletize_GetResult_Response__Sequence__destroy(mmr_interfaces__action__Palletize_GetResult_Response__Sequence * array);

/// Check for action/Palletize message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
bool
mmr_interfaces__action__Palletize_GetResult_Response__Sequence__are_equal(const mmr_interfaces__action__Palletize_GetResult_Response__Sequence * lhs, const mmr_interfaces__action__Palletize_GetResult_Response__Sequence * rhs);

/// Copy an array of action/Palletize messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
bool
mmr_interfaces__action__Palletize_GetResult_Response__Sequence__copy(
  const mmr_interfaces__action__Palletize_GetResult_Response__Sequence * input,
  mmr_interfaces__action__Palletize_GetResult_Response__Sequence * output);

/// Initialize action/Palletize message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * mmr_interfaces__action__Palletize_FeedbackMessage
 * )) before or use
 * mmr_interfaces__action__Palletize_FeedbackMessage__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
bool
mmr_interfaces__action__Palletize_FeedbackMessage__init(mmr_interfaces__action__Palletize_FeedbackMessage * msg);

/// Finalize action/Palletize message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
void
mmr_interfaces__action__Palletize_FeedbackMessage__fini(mmr_interfaces__action__Palletize_FeedbackMessage * msg);

/// Create action/Palletize message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * mmr_interfaces__action__Palletize_FeedbackMessage__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
mmr_interfaces__action__Palletize_FeedbackMessage *
mmr_interfaces__action__Palletize_FeedbackMessage__create();

/// Destroy action/Palletize message.
/**
 * It calls
 * mmr_interfaces__action__Palletize_FeedbackMessage__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
void
mmr_interfaces__action__Palletize_FeedbackMessage__destroy(mmr_interfaces__action__Palletize_FeedbackMessage * msg);

/// Check for action/Palletize message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
bool
mmr_interfaces__action__Palletize_FeedbackMessage__are_equal(const mmr_interfaces__action__Palletize_FeedbackMessage * lhs, const mmr_interfaces__action__Palletize_FeedbackMessage * rhs);

/// Copy a action/Palletize message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
bool
mmr_interfaces__action__Palletize_FeedbackMessage__copy(
  const mmr_interfaces__action__Palletize_FeedbackMessage * input,
  mmr_interfaces__action__Palletize_FeedbackMessage * output);

/// Initialize array of action/Palletize messages.
/**
 * It allocates the memory for the number of elements and calls
 * mmr_interfaces__action__Palletize_FeedbackMessage__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
bool
mmr_interfaces__action__Palletize_FeedbackMessage__Sequence__init(mmr_interfaces__action__Palletize_FeedbackMessage__Sequence * array, size_t size);

/// Finalize array of action/Palletize messages.
/**
 * It calls
 * mmr_interfaces__action__Palletize_FeedbackMessage__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
void
mmr_interfaces__action__Palletize_FeedbackMessage__Sequence__fini(mmr_interfaces__action__Palletize_FeedbackMessage__Sequence * array);

/// Create array of action/Palletize messages.
/**
 * It allocates the memory for the array and calls
 * mmr_interfaces__action__Palletize_FeedbackMessage__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
mmr_interfaces__action__Palletize_FeedbackMessage__Sequence *
mmr_interfaces__action__Palletize_FeedbackMessage__Sequence__create(size_t size);

/// Destroy array of action/Palletize messages.
/**
 * It calls
 * mmr_interfaces__action__Palletize_FeedbackMessage__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
void
mmr_interfaces__action__Palletize_FeedbackMessage__Sequence__destroy(mmr_interfaces__action__Palletize_FeedbackMessage__Sequence * array);

/// Check for action/Palletize message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
bool
mmr_interfaces__action__Palletize_FeedbackMessage__Sequence__are_equal(const mmr_interfaces__action__Palletize_FeedbackMessage__Sequence * lhs, const mmr_interfaces__action__Palletize_FeedbackMessage__Sequence * rhs);

/// Copy an array of action/Palletize messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_mmr_interfaces
bool
mmr_interfaces__action__Palletize_FeedbackMessage__Sequence__copy(
  const mmr_interfaces__action__Palletize_FeedbackMessage__Sequence * input,
  mmr_interfaces__action__Palletize_FeedbackMessage__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // MMR_INTERFACES__ACTION__DETAIL__PALLETIZE__FUNCTIONS_H_
