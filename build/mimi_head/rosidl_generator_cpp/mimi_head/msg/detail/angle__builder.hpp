// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from mimi_head:msg/Angle.idl
// generated code does not contain a copyright notice

#ifndef MIMI_HEAD__MSG__DETAIL__ANGLE__BUILDER_HPP_
#define MIMI_HEAD__MSG__DETAIL__ANGLE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "mimi_head/msg/detail/angle__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace mimi_head
{

namespace msg
{

namespace builder
{

class Init_Angle_angle_z
{
public:
  explicit Init_Angle_angle_z(::mimi_head::msg::Angle & msg)
  : msg_(msg)
  {}
  ::mimi_head::msg::Angle angle_z(::mimi_head::msg::Angle::_angle_z_type arg)
  {
    msg_.angle_z = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mimi_head::msg::Angle msg_;
};

class Init_Angle_angle_x
{
public:
  Init_Angle_angle_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Angle_angle_z angle_x(::mimi_head::msg::Angle::_angle_x_type arg)
  {
    msg_.angle_x = std::move(arg);
    return Init_Angle_angle_z(msg_);
  }

private:
  ::mimi_head::msg::Angle msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::mimi_head::msg::Angle>()
{
  return mimi_head::msg::builder::Init_Angle_angle_x();
}

}  // namespace mimi_head

#endif  // MIMI_HEAD__MSG__DETAIL__ANGLE__BUILDER_HPP_
