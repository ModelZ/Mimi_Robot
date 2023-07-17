// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from mimi_head:msg/Movement.idl
// generated code does not contain a copyright notice

#ifndef MIMI_HEAD__MSG__DETAIL__MOVEMENT__STRUCT_H_
#define MIMI_HEAD__MSG__DETAIL__MOVEMENT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'pos_x'
// Member 'pos_z'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/Movement in the package mimi_head.
/**
  * msg for servo movement
 */
typedef struct mimi_head__msg__Movement
{
  rosidl_runtime_c__String pos_x;
  rosidl_runtime_c__String pos_z;
} mimi_head__msg__Movement;

// Struct for a sequence of mimi_head__msg__Movement.
typedef struct mimi_head__msg__Movement__Sequence
{
  mimi_head__msg__Movement * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mimi_head__msg__Movement__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MIMI_HEAD__MSG__DETAIL__MOVEMENT__STRUCT_H_
