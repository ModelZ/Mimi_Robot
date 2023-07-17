// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from mimi_head:msg/Movement.idl
// generated code does not contain a copyright notice

#ifndef MIMI_HEAD__MSG__DETAIL__MOVEMENT__STRUCT_HPP_
#define MIMI_HEAD__MSG__DETAIL__MOVEMENT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__mimi_head__msg__Movement __attribute__((deprecated))
#else
# define DEPRECATED__mimi_head__msg__Movement __declspec(deprecated)
#endif

namespace mimi_head
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Movement_
{
  using Type = Movement_<ContainerAllocator>;

  explicit Movement_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->pos_x = "";
      this->pos_z = "";
    }
  }

  explicit Movement_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pos_x(_alloc),
    pos_z(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->pos_x = "";
      this->pos_z = "";
    }
  }

  // field types and members
  using _pos_x_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _pos_x_type pos_x;
  using _pos_z_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _pos_z_type pos_z;

  // setters for named parameter idiom
  Type & set__pos_x(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->pos_x = _arg;
    return *this;
  }
  Type & set__pos_z(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->pos_z = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    mimi_head::msg::Movement_<ContainerAllocator> *;
  using ConstRawPtr =
    const mimi_head::msg::Movement_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<mimi_head::msg::Movement_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<mimi_head::msg::Movement_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      mimi_head::msg::Movement_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<mimi_head::msg::Movement_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      mimi_head::msg::Movement_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<mimi_head::msg::Movement_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<mimi_head::msg::Movement_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<mimi_head::msg::Movement_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__mimi_head__msg__Movement
    std::shared_ptr<mimi_head::msg::Movement_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__mimi_head__msg__Movement
    std::shared_ptr<mimi_head::msg::Movement_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Movement_ & other) const
  {
    if (this->pos_x != other.pos_x) {
      return false;
    }
    if (this->pos_z != other.pos_z) {
      return false;
    }
    return true;
  }
  bool operator!=(const Movement_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Movement_

// alias to use template instance with default allocator
using Movement =
  mimi_head::msg::Movement_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace mimi_head

#endif  // MIMI_HEAD__MSG__DETAIL__MOVEMENT__STRUCT_HPP_
