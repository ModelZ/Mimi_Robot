// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from mimi_head:msg/Movement.idl
// generated code does not contain a copyright notice

#ifndef MIMI_HEAD__MSG__DETAIL__MOVEMENT__FUNCTIONS_H_
#define MIMI_HEAD__MSG__DETAIL__MOVEMENT__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "mimi_head/msg/rosidl_generator_c__visibility_control.h"

#include "mimi_head/msg/detail/movement__struct.h"

/// Initialize msg/Movement message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * mimi_head__msg__Movement
 * )) before or use
 * mimi_head__msg__Movement__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_mimi_head
bool
mimi_head__msg__Movement__init(mimi_head__msg__Movement * msg);

/// Finalize msg/Movement message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mimi_head
void
mimi_head__msg__Movement__fini(mimi_head__msg__Movement * msg);

/// Create msg/Movement message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * mimi_head__msg__Movement__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_mimi_head
mimi_head__msg__Movement *
mimi_head__msg__Movement__create();

/// Destroy msg/Movement message.
/**
 * It calls
 * mimi_head__msg__Movement__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mimi_head
void
mimi_head__msg__Movement__destroy(mimi_head__msg__Movement * msg);

/// Check for msg/Movement message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_mimi_head
bool
mimi_head__msg__Movement__are_equal(const mimi_head__msg__Movement * lhs, const mimi_head__msg__Movement * rhs);

/// Copy a msg/Movement message.
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
ROSIDL_GENERATOR_C_PUBLIC_mimi_head
bool
mimi_head__msg__Movement__copy(
  const mimi_head__msg__Movement * input,
  mimi_head__msg__Movement * output);

/// Initialize array of msg/Movement messages.
/**
 * It allocates the memory for the number of elements and calls
 * mimi_head__msg__Movement__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_mimi_head
bool
mimi_head__msg__Movement__Sequence__init(mimi_head__msg__Movement__Sequence * array, size_t size);

/// Finalize array of msg/Movement messages.
/**
 * It calls
 * mimi_head__msg__Movement__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mimi_head
void
mimi_head__msg__Movement__Sequence__fini(mimi_head__msg__Movement__Sequence * array);

/// Create array of msg/Movement messages.
/**
 * It allocates the memory for the array and calls
 * mimi_head__msg__Movement__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_mimi_head
mimi_head__msg__Movement__Sequence *
mimi_head__msg__Movement__Sequence__create(size_t size);

/// Destroy array of msg/Movement messages.
/**
 * It calls
 * mimi_head__msg__Movement__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mimi_head
void
mimi_head__msg__Movement__Sequence__destroy(mimi_head__msg__Movement__Sequence * array);

/// Check for msg/Movement message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_mimi_head
bool
mimi_head__msg__Movement__Sequence__are_equal(const mimi_head__msg__Movement__Sequence * lhs, const mimi_head__msg__Movement__Sequence * rhs);

/// Copy an array of msg/Movement messages.
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
ROSIDL_GENERATOR_C_PUBLIC_mimi_head
bool
mimi_head__msg__Movement__Sequence__copy(
  const mimi_head__msg__Movement__Sequence * input,
  mimi_head__msg__Movement__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // MIMI_HEAD__MSG__DETAIL__MOVEMENT__FUNCTIONS_H_
