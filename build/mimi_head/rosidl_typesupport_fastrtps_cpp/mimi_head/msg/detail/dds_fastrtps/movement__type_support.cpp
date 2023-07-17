// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from mimi_head:msg/Movement.idl
// generated code does not contain a copyright notice
#include "mimi_head/msg/detail/movement__rosidl_typesupport_fastrtps_cpp.hpp"
#include "mimi_head/msg/detail/movement__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace mimi_head
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_mimi_head
cdr_serialize(
  const mimi_head::msg::Movement & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: pos_x
  cdr << ros_message.pos_x;
  // Member: pos_z
  cdr << ros_message.pos_z;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_mimi_head
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  mimi_head::msg::Movement & ros_message)
{
  // Member: pos_x
  cdr >> ros_message.pos_x;

  // Member: pos_z
  cdr >> ros_message.pos_z;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_mimi_head
get_serialized_size(
  const mimi_head::msg::Movement & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: pos_x
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.pos_x.size() + 1);
  // Member: pos_z
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.pos_z.size() + 1);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_mimi_head
max_serialized_size_Movement(
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


  // Member: pos_x
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

  // Member: pos_z
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

static bool _Movement__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const mimi_head::msg::Movement *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _Movement__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<mimi_head::msg::Movement *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _Movement__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const mimi_head::msg::Movement *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _Movement__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_Movement(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _Movement__callbacks = {
  "mimi_head::msg",
  "Movement",
  _Movement__cdr_serialize,
  _Movement__cdr_deserialize,
  _Movement__get_serialized_size,
  _Movement__max_serialized_size
};

static rosidl_message_type_support_t _Movement__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_Movement__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace mimi_head

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_mimi_head
const rosidl_message_type_support_t *
get_message_type_support_handle<mimi_head::msg::Movement>()
{
  return &mimi_head::msg::typesupport_fastrtps_cpp::_Movement__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, mimi_head, msg, Movement)() {
  return &mimi_head::msg::typesupport_fastrtps_cpp::_Movement__handle;
}

#ifdef __cplusplus
}
#endif
