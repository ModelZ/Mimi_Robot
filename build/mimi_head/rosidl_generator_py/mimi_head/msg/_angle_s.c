// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from mimi_head:msg/Angle.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "mimi_head/msg/detail/angle__struct.h"
#include "mimi_head/msg/detail/angle__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool mimi_head__msg__angle__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[27];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("mimi_head.msg._angle.Angle", full_classname_dest, 26) == 0);
  }
  mimi_head__msg__Angle * ros_message = _ros_message;
  {  // angle_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "angle_x");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->angle_x = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // angle_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "angle_z");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->angle_z = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * mimi_head__msg__angle__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of Angle */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("mimi_head.msg._angle");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "Angle");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  mimi_head__msg__Angle * ros_message = (mimi_head__msg__Angle *)raw_ros_message;
  {  // angle_x
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->angle_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "angle_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // angle_z
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->angle_z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "angle_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
