// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from mimi_head:msg/Angle.idl
// generated code does not contain a copyright notice
#include "mimi_head/msg/detail/angle__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
mimi_head__msg__Angle__init(mimi_head__msg__Angle * msg)
{
  if (!msg) {
    return false;
  }
  // angle_x
  // angle_z
  return true;
}

void
mimi_head__msg__Angle__fini(mimi_head__msg__Angle * msg)
{
  if (!msg) {
    return;
  }
  // angle_x
  // angle_z
}

bool
mimi_head__msg__Angle__are_equal(const mimi_head__msg__Angle * lhs, const mimi_head__msg__Angle * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // angle_x
  if (lhs->angle_x != rhs->angle_x) {
    return false;
  }
  // angle_z
  if (lhs->angle_z != rhs->angle_z) {
    return false;
  }
  return true;
}

bool
mimi_head__msg__Angle__copy(
  const mimi_head__msg__Angle * input,
  mimi_head__msg__Angle * output)
{
  if (!input || !output) {
    return false;
  }
  // angle_x
  output->angle_x = input->angle_x;
  // angle_z
  output->angle_z = input->angle_z;
  return true;
}

mimi_head__msg__Angle *
mimi_head__msg__Angle__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mimi_head__msg__Angle * msg = (mimi_head__msg__Angle *)allocator.allocate(sizeof(mimi_head__msg__Angle), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(mimi_head__msg__Angle));
  bool success = mimi_head__msg__Angle__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
mimi_head__msg__Angle__destroy(mimi_head__msg__Angle * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    mimi_head__msg__Angle__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
mimi_head__msg__Angle__Sequence__init(mimi_head__msg__Angle__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mimi_head__msg__Angle * data = NULL;

  if (size) {
    data = (mimi_head__msg__Angle *)allocator.zero_allocate(size, sizeof(mimi_head__msg__Angle), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = mimi_head__msg__Angle__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        mimi_head__msg__Angle__fini(&data[i - 1]);
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
mimi_head__msg__Angle__Sequence__fini(mimi_head__msg__Angle__Sequence * array)
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
      mimi_head__msg__Angle__fini(&array->data[i]);
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

mimi_head__msg__Angle__Sequence *
mimi_head__msg__Angle__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mimi_head__msg__Angle__Sequence * array = (mimi_head__msg__Angle__Sequence *)allocator.allocate(sizeof(mimi_head__msg__Angle__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = mimi_head__msg__Angle__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
mimi_head__msg__Angle__Sequence__destroy(mimi_head__msg__Angle__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    mimi_head__msg__Angle__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
mimi_head__msg__Angle__Sequence__are_equal(const mimi_head__msg__Angle__Sequence * lhs, const mimi_head__msg__Angle__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!mimi_head__msg__Angle__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
mimi_head__msg__Angle__Sequence__copy(
  const mimi_head__msg__Angle__Sequence * input,
  mimi_head__msg__Angle__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(mimi_head__msg__Angle);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    mimi_head__msg__Angle * data =
      (mimi_head__msg__Angle *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!mimi_head__msg__Angle__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          mimi_head__msg__Angle__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!mimi_head__msg__Angle__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
