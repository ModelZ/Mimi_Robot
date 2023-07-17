// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from mimi_head:msg/Movement.idl
// generated code does not contain a copyright notice

#ifndef MIMI_HEAD__MSG__DETAIL__MOVEMENT__BUILDER_HPP_
#define MIMI_HEAD__MSG__DETAIL__MOVEMENT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "mimi_head/msg/detail/movement__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace mimi_head
{

namespace msg
{

namespace builder
{

class Init_Movement_pos_z
{
public:
  explicit Init_Movement_pos_z(::mimi_head::msg::Movement & msg)
  : msg_(msg)
  {}
  ::mimi_head::msg::Movement pos_z(::mimi_head::msg::Movement::_pos_z_type arg)
  {
    msg_.pos_z = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mimi_head::msg::Movement msg_;
};

class Init_Movement_pos_x
{
public:
  Init_Movement_pos_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Movement_pos_z pos_x(::mimi_head::msg::Movement::_pos_x_type arg)
  {
    msg_.pos_x = std::move(arg);
    return Init_Movement_pos_z(msg_);
  }

private:
  ::mimi_head::msg::Movement msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::mimi_head::msg::Movement>()
{
  return mimi_head::msg::builder::Init_Movement_pos_x();
}

}  // namespace mimi_head

#endif  // MIMI_HEAD__MSG__DETAIL__MOVEMENT__BUILDER_HPP_
