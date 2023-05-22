// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from mimi_head:msg/Angle.idl
// generated code does not contain a copyright notice

#ifndef MIMI_HEAD__MSG__DETAIL__ANGLE__TRAITS_HPP_
#define MIMI_HEAD__MSG__DETAIL__ANGLE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "mimi_head/msg/detail/angle__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace mimi_head
{

namespace msg
{

inline void to_flow_style_yaml(
  const Angle & msg,
  std::ostream & out)
{
  out << "{";
  // member: angle_x
  {
    out << "angle_x: ";
    rosidl_generator_traits::value_to_yaml(msg.angle_x, out);
    out << ", ";
  }

  // member: angle_z
  {
    out << "angle_z: ";
    rosidl_generator_traits::value_to_yaml(msg.angle_z, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Angle & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: angle_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "angle_x: ";
    rosidl_generator_traits::value_to_yaml(msg.angle_x, out);
    out << "\n";
  }

  // member: angle_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "angle_z: ";
    rosidl_generator_traits::value_to_yaml(msg.angle_z, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Angle & msg, bool use_flow_style = false)
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
  const mimi_head::msg::Angle & msg,
  std::ostream & out, size_t indentation = 0)
{
  mimi_head::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use mimi_head::msg::to_yaml() instead")]]
inline std::string to_yaml(const mimi_head::msg::Angle & msg)
{
  return mimi_head::msg::to_yaml(msg);
}

template<>
inline const char * data_type<mimi_head::msg::Angle>()
{
  return "mimi_head::msg::Angle";
}

template<>
inline const char * name<mimi_head::msg::Angle>()
{
  return "mimi_head/msg/Angle";
}

template<>
struct has_fixed_size<mimi_head::msg::Angle>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<mimi_head::msg::Angle>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<mimi_head::msg::Angle>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MIMI_HEAD__MSG__DETAIL__ANGLE__TRAITS_HPP_
