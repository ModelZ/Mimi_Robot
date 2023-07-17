// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from mimi_head:msg/Movement.idl
// generated code does not contain a copyright notice
#include "mimi_head/msg/detail/movement__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "mimi_head/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "mimi_head/msg/detail/movement__struct.h"
#include "mimi_head/msg/detail/movement__functions.h"
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

#include "rosidl_runtime_c/string.h"  // pos_x, pos_z
#include "rosidl_runtime_c/string_functions.h"  // pos_x, pos_z

// forward declare type support functions


using _Movement__ros_msg_type = mimi_head__msg__Movement;

static bool _Movement__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _Movement__ros_msg_type * ros_message = static_cast<const _Movement__ros_msg_type *>(untyped_ros_message);
  // Field name: pos_x
  {
    const rosidl_runtime_c__String * str = &ros_message->pos_x;
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

  // Field name: pos_z
  {
    const rosidl_runtime_c__String * str = &ros_message->pos_z;
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

  return true;
}

static bool _Movement__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Movement__ros_msg_type * ros_message = static_cast<_Movement__ros_msg_type *>(untyped_ros_message);
  // Field name: pos_x
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->pos_x.data) {
      rosidl_runtime_c__String__init(&ros_message->pos_x);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->pos_x,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'pos_x'\n");
      return false;
    }
  }

  // Field name: pos_z
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->pos_z.data) {
      rosidl_runtime_c__String__init(&ros_message->pos_z);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->pos_z,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'pos_z'\n");
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_mimi_head
size_t get_serialized_size_mimi_head__msg__Movement(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Movement__ros_msg_type * ros_message = static_cast<const _Movement__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name pos_x
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->pos_x.size + 1);
  // field.name pos_z
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->pos_z.size + 1);

  return current_alignment - initial_alignment;
}

static uint32_t _Movement__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_mimi_head__msg__Movement(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_mimi_head
size_t max_serialized_size_mimi_head__msg__Movement(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: pos_x
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: pos_z
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  return current_alignment - initial_alignment;
}

static size_t _Movement__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_mimi_head__msg__Movement(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_Movement = {
  "mimi_head::msg",
  "Movement",
  _Movement__cdr_serialize,
  _Movement__cdr_deserialize,
  _Movement__get_serialized_size,
  _Movement__max_serialized_size
};

static rosidl_message_type_support_t _Movement__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Movement,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, mimi_head, msg, Movement)() {
  return &_Movement__type_support;
}

#if defined(__cplusplus)
}
#endif
