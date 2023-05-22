// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from mimi_head:msg/Angle.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "mimi_head/msg/detail/angle__rosidl_typesupport_introspection_c.h"
#include "mimi_head/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "mimi_head/msg/detail/angle__functions.h"
#include "mimi_head/msg/detail/angle__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void mimi_head__msg__Angle__rosidl_typesupport_introspection_c__Angle_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  mimi_head__msg__Angle__init(message_memory);
}

void mimi_head__msg__Angle__rosidl_typesupport_introspection_c__Angle_fini_function(void * message_memory)
{
  mimi_head__msg__Angle__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember mimi_head__msg__Angle__rosidl_typesupport_introspection_c__Angle_message_member_array[2] = {
  {
    "angle_x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(mimi_head__msg__Angle, angle_x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "angle_z",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(mimi_head__msg__Angle, angle_z),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers mimi_head__msg__Angle__rosidl_typesupport_introspection_c__Angle_message_members = {
  "mimi_head__msg",  // message namespace
  "Angle",  // message name
  2,  // number of fields
  sizeof(mimi_head__msg__Angle),
  mimi_head__msg__Angle__rosidl_typesupport_introspection_c__Angle_message_member_array,  // message members
  mimi_head__msg__Angle__rosidl_typesupport_introspection_c__Angle_init_function,  // function to initialize message memory (memory has to be allocated)
  mimi_head__msg__Angle__rosidl_typesupport_introspection_c__Angle_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t mimi_head__msg__Angle__rosidl_typesupport_introspection_c__Angle_message_type_support_handle = {
  0,
  &mimi_head__msg__Angle__rosidl_typesupport_introspection_c__Angle_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_mimi_head
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mimi_head, msg, Angle)() {
  if (!mimi_head__msg__Angle__rosidl_typesupport_introspection_c__Angle_message_type_support_handle.typesupport_identifier) {
    mimi_head__msg__Angle__rosidl_typesupport_introspection_c__Angle_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &mimi_head__msg__Angle__rosidl_typesupport_introspection_c__Angle_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
