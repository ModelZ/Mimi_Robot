// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from mimi_head:msg/Movement.idl
// generated code does not contain a copyright notice

#ifndef MIMI_HEAD__MSG__DETAIL__MOVEMENT__TRAITS_HPP_
#define MIMI_HEAD__MSG__DETAIL__MOVEMENT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "mimi_head/msg/detail/movement__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace mimi_head
{

namespace msg
{

inline void to_flow_style_yaml(
  const Movement & msg,
  std::ostream & out)
{
  out << "{";
  // member: pos_x
  {
    out << "pos_x: ";
    rosidl_generator_traits::value_to_yaml(msg.pos_x, out);
    out << ", ";
  }

  // member: pos_z
  {
    out << "pos_z: ";
    rosidl_generator_traits::value_to_yaml(msg.pos_z, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Movement & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: pos_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pos_x: ";
    rosidl_generator_traits::value_to_yaml(msg.pos_x, out);
    out << "\n";
  }

  // member: pos_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pos_z: ";
    rosidl_generator_traits::value_to_yaml(msg.pos_z, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Movement & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace mimi_head

namespace rosidl_generator_traits
{

[[deprecated("use mimi_head::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const mimi_head::msg::Movement & msg,
  std::ostream & out, size_t indentation = 0)
{
  mimi_head::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use mimi_head::msg::to_yaml() instead")]]
inline std::string to_yaml(const mimi_head::msg::Movement & msg)
{
  return mimi_head::msg::to_yaml(msg);
}

template<>
inline const char * data_type<mimi_head::msg::Movement>()
{
  return "mimi_head::msg::Movement";
}

template<>
inline const char * name<mimi_head::msg::Movement>()
{
  return "mimi_head/msg/Movement";
}

template<>
struct has_fixed_size<mimi_head::msg::Movement>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<mimi_head::msg::Movement>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<mimi_head::msg::Movement>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MIMI_HEAD__MSG__DETAIL__MOVEMENT__TRAITS_HPP_
