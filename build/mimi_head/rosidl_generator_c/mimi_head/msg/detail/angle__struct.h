// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from mimi_head:msg/Angle.idl
// generated code does not contain a copyright notice

#ifndef MIMI_HEAD__MSG__DETAIL__ANGLE__STRUCT_H_
#define MIMI_HEAD__MSG__DETAIL__ANGLE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Angle in the package mimi_head.
typedef struct mimi_head__msg__Angle
{
  int32_t angle_x;
  int32_t angle_z;
} mimi_head__msg__Angle;

// Struct for a sequence of mimi_head__msg__Angle.
typedef struct mimi_head__msg__Angle__Sequence
{
  mimi_head__msg__Angle * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mimi_head__msg__Angle__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MIMI_HEAD__MSG__DETAIL__ANGLE__STRUCT_H_
