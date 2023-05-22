// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from mimi_head:msg/Angle.idl
// generated code does not contain a copyright notice
#include "mimi_head/msg/detail/angle__rosidl_typesupport_fastrtps_cpp.hpp"
#include "mimi_head/msg/detail/angle__struct.hpp"

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
  const mimi_head::msg::Angle & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: angle_x
  cdr << ros_message.angle_x;
  // Member: angle_z
  cdr << ros_message.angle_z;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_mimi_head
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  mimi_head::msg::Angle & ros_message)
{
  // Member: angle_x
  cdr >> ros_message.angle_x;

  // Member: angle_z
  cdr >> ros_message.angle_z;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_mimi_head
get_serialized_size(
  const mimi_head::msg::Angle & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: angle_x
  {
    size_t item_size = sizeof(ros_message.angle_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: angle_z
  {
    size_t item_size = sizeof(ros_message.angle_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_mimi_head
max_serialized_size_Angle(
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


  // Member: angle_x
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: angle_z
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static bool _Angle__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const mimi_head::msg::Angle *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _Angle__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<mimi_head::msg::Angle *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _Angle__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const mimi_head::msg::Angle *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _Angle__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_Angle(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _Angle__callbacks = {
  "mimi_head::msg",
  "Angle",
  _Angle__cdr_serialize,
  _Angle__cdr_deserialize,
  _Angle__get_serialized_size,
  _Angle__max_serialized_size
};

static rosidl_message_type_support_t _Angle__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_Angle__callbacks,
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
get_message_type_support_handle<mimi_head::msg::Angle>()
{
  return &mimi_head::msg::typesupport_fastrtps_cpp::_Angle__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, mimi_head, msg, Angle)() {
  return &mimi_head::msg::typesupport_fastrtps_cpp::_Angle__handle;
}

#ifdef __cplusplus
}
#endif
