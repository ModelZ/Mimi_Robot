// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from mimi_head:msg/Movement.idl
// generated code does not contain a copyright notice
#include "mimi_head/msg/detail/movement__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `pos_x`
// Member `pos_z`
#include "rosidl_runtime_c/string_functions.h"

bool
mimi_head__msg__Movement__init(mimi_head__msg__Movement * msg)
{
  if (!msg) {
    return false;
  }
  // pos_x
  if (!rosidl_runtime_c__String__init(&msg->pos_x)) {
    mimi_head__msg__Movement__fini(msg);
    return false;
  }
  // pos_z
  if (!rosidl_runtime_c__String__init(&msg->pos_z)) {
    mimi_head__msg__Movement__fini(msg);
    return false;
  }
  return true;
}

void
mimi_head__msg__Movement__fini(mimi_head__msg__Movement * msg)
{
  if (!msg) {
    return;
  }
  // pos_x
  rosidl_runtime_c__String__fini(&msg->pos_x);
  // pos_z
  rosidl_runtime_c__String__fini(&msg->pos_z);
}

bool
mimi_head__msg__Movement__are_equal(const mimi_head__msg__Movement * lhs, const mimi_head__msg__Movement * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // pos_x
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->pos_x), &(rhs->pos_x)))
  {
    return false;
  }
  // pos_z
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->pos_z), &(rhs->pos_z)))
  {
    return false;
  }
  return true;
}

bool
mimi_head__msg__Movement__copy(
  const mimi_head__msg__Movement * input,
  mimi_head__msg__Movement * output)
{
  if (!input || !output) {
    return false;
  }
  // pos_x
  if (!rosidl_runtime_c__String__copy(
      &(input->pos_x), &(output->pos_x)))
  {
    return false;
  }
  // pos_z
  if (!rosidl_runtime_c__String__copy(
      &(input->pos_z), &(output->pos_z)))
  {
    return false;
  }
  return true;
}

mimi_head__msg__Movement *
mimi_head__msg__Movement__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mimi_head__msg__Movement * msg = (mimi_head__msg__Movement *)allocator.allocate(sizeof(mimi_head__msg__Movement), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(mimi_head__msg__Movement));
  bool success = mimi_head__msg__Movement__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
mimi_head__msg__Movement__destroy(mimi_head__msg__Movement * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    mimi_head__msg__Movement__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
mimi_head__msg__Movement__Sequence__init(mimi_head__msg__Movement__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mimi_head__msg__Movement * data = NULL;

  if (size) {
    data = (mimi_head__msg__Movement *)allocator.zero_allocate(size, sizeof(mimi_head__msg__Movement), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = mimi_head__msg__Movement__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        mimi_head__msg__Movement__fini(&data[i - 1]);
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
mimi_head__msg__Movement__Sequence__fini(mimi_head__msg__Movement__Sequence * array)
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
      mimi_head__msg__Movement__fini(&array->data[i]);
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

mimi_head__msg__Movement__Sequence *
mimi_head__msg__Movement__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mimi_head__msg__Movement__Sequence * array = (mimi_head__msg__Movement__Sequence *)allocator.allocate(sizeof(mimi_head__msg__Movement__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = mimi_head__msg__Movement__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
mimi_head__msg__Movement__Sequence__destroy(mimi_head__msg__Movement__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    mimi_head__msg__Movement__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
mimi_head__msg__Movement__Sequence__are_equal(const mimi_head__msg__Movement__Sequence * lhs, const mimi_head__msg__Movement__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!mimi_head__msg__Movement__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
mimi_head__msg__Movement__Sequence__copy(
  const mimi_head__msg__Movement__Sequence * input,
  mimi_head__msg__Movement__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(mimi_head__msg__Movement);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    mimi_head__msg__Movement * data =
      (mimi_head__msg__Movement *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!mimi_head__msg__Movement__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          mimi_head__msg__Movement__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!mimi_head__msg__Movement__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
