# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_mimi_head_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED mimi_head_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(mimi_head_FOUND FALSE)
  elseif(NOT mimi_head_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(mimi_head_FOUND FALSE)
  endif()
  return()
endif()
set(_mimi_head_CONFIG_INCLUDED TRUE)

# output package information
if(NOT mimi_head_FIND_QUIETLY)
  message(STATUS "Found mimi_head: 0.0.0 (${mimi_head_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'mimi_head' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${mimi_head_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(mimi_head_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${mimi_head_DIR}/${_extra}")
endforeach()
