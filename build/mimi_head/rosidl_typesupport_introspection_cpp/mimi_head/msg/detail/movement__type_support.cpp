// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from mimi_head:msg/Movement.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "mimi_head/msg/detail/movement__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace mimi_head
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void Movement_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) mimi_head::msg::Movement(_init);
}

void Movement_fini_function(void * message_memory)
{
  auto typed_message = static_cast<mimi_head::msg::Movement *>(message_memory);
  typed_message->~Movement();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Movement_message_member_array[2] = {
  {
    "pos_x",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(mimi_head::msg::Movement, pos_x),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "pos_z",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(mimi_head::msg::Movement, pos_z),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Movement_message_members = {
  "mimi_head::msg",  // message namespace
  "Movement",  // message name
  2,  // number of fields
  sizeof(mimi_head::msg::Movement),
  Movement_message_member_array,  // message members
  Movement_init_function,  // function to initialize message memory (memory has to be allocated)
  Movement_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Movement_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Movement_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace mimi_head


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<mimi_head::msg::Movement>()
{
  return &::mimi_head::msg::rosidl_typesupport_introspection_cpp::Movement_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, mimi_head, msg, Movement)() {
  return &::mimi_head::msg::rosidl_typesupport_introspection_cpp::Movement_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
