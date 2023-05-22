// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from mimi_head:msg/Angle.idl
// generated code does not contain a copyright notice

#ifndef MIMI_HEAD__MSG__DETAIL__ANGLE__STRUCT_HPP_
#define MIMI_HEAD__MSG__DETAIL__ANGLE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__mimi_head__msg__Angle __attribute__((deprecated))
#else
# define DEPRECATED__mimi_head__msg__Angle __declspec(deprecated)
#endif

namespace mimi_head
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Angle_
{
  using Type = Angle_<ContainerAllocator>;

  explicit Angle_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->angle_x = 0l;
      this->angle_z = 0l;
    }
  }

  explicit Angle_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->angle_x = 0l;
      this->angle_z = 0l;
    }
  }

  // field types and members
  using _angle_x_type =
    int32_t;
  _angle_x_type angle_x;
  using _angle_z_type =
    int32_t;
  _angle_z_type angle_z;

  // setters for named parameter idiom
  Type & set__angle_x(
    const int32_t & _arg)
  {
    this->angle_x = _arg;
    return *this;
  }
  Type & set__angle_z(
    const int32_t & _arg)
  {
    this->angle_z = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    mimi_head::msg::Angle_<ContainerAllocator> *;
  using ConstRawPtr =
    const mimi_head::msg::Angle_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<mimi_head::msg::Angle_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<mimi_head::msg::Angle_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      mimi_head::msg::Angle_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<mimi_head::msg::Angle_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      mimi_head::msg::Angle_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<mimi_head::msg::Angle_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<mimi_head::msg::Angle_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<mimi_head::msg::Angle_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__mimi_head__msg__Angle
    std::shared_ptr<mimi_head::msg::Angle_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__mimi_head__msg__Angle
    std::shared_ptr<mimi_head::msg::Angle_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Angle_ & other) const
  {
    if (this->angle_x != other.angle_x) {
      return false;
    }
    if (this->angle_z != other.angle_z) {
      return false;
    }
    return true;
  }
  bool operator!=(const Angle_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Angle_

// alias to use template instance with default allocator
using Angle =
  mimi_head::msg::Angle_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace mimi_head

#endif  // MIMI_HEAD__MSG__DETAIL__ANGLE__STRUCT_HPP_
