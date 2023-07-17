cmake_minimum_required(VERSION 3.8)
project(mimi_head)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(OpenCV REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(rosidl_default_generators REQUIRED)

# Add the pigpio library
find_library(PIGPIO_LIBRARY pigpio)

# add custom interfaces
rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/Movement.msg"
)

# add support for using custom interfaces in C++ from this package
rosidl_get_typesupport_target(cpp_typesupport_target "${PROJECT_NAME}" "rosidl_typesupport_cpp")

# complier
add_executable(mimi_camera src/mimi_camera.cpp)
ament_target_dependencies(mimi_camera rclcpp sensor_msgs OpenCV cv_bridge)
# add target link library (only use when create custom interface within same package)
target_link_libraries(mimi_camera "${cpp_typesupport_target}")

add_executable(mimi_monitor src/mimi_monitor.cpp)
ament_target_dependencies(mimi_monitor rclcpp sensor_msgs OpenCV cv_bridge)

add_executable(mimi_head_movement src/mimi_head_movement.cpp)
ament_target_dependencies(mimi_head_movement rclcpp)
# add target link library (only use when create custom interface within same package)
target_link_libraries(mimi_head_movement "${cpp_typesupport_target}" "${PIGPIO_LIBRARY}")

install(
  TARGETS mimi_camera mimi_monitor mimi_head_movement
  DESTINATION lib/${PROJECT_NAME} 
)

install( 
  DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}/
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
