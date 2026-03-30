// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from carbot_patrol_interfaces:srv/Speech.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "carbot_patrol_interfaces/srv/speech.h"


#ifndef CARBOT_PATROL_INTERFACES__SRV__DETAIL__SPEECH__STRUCT_H_
#define CARBOT_PATROL_INTERFACES__SRV__DETAIL__SPEECH__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'text'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/Speech in the package carbot_patrol_interfaces.
typedef struct carbot_patrol_interfaces__srv__Speech_Request
{
  rosidl_runtime_c__String text;
} carbot_patrol_interfaces__srv__Speech_Request;

// Struct for a sequence of carbot_patrol_interfaces__srv__Speech_Request.
typedef struct carbot_patrol_interfaces__srv__Speech_Request__Sequence
{
  carbot_patrol_interfaces__srv__Speech_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} carbot_patrol_interfaces__srv__Speech_Request__Sequence;

// Constants defined in the message

/// Struct defined in srv/Speech in the package carbot_patrol_interfaces.
typedef struct carbot_patrol_interfaces__srv__Speech_Response
{
  bool result;
} carbot_patrol_interfaces__srv__Speech_Response;

// Struct for a sequence of carbot_patrol_interfaces__srv__Speech_Response.
typedef struct carbot_patrol_interfaces__srv__Speech_Response__Sequence
{
  carbot_patrol_interfaces__srv__Speech_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} carbot_patrol_interfaces__srv__Speech_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  carbot_patrol_interfaces__srv__Speech_Event__request__MAX_SIZE = 1
};
// response
enum
{
  carbot_patrol_interfaces__srv__Speech_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/Speech in the package carbot_patrol_interfaces.
typedef struct carbot_patrol_interfaces__srv__Speech_Event
{
  service_msgs__msg__ServiceEventInfo info;
  carbot_patrol_interfaces__srv__Speech_Request__Sequence request;
  carbot_patrol_interfaces__srv__Speech_Response__Sequence response;
} carbot_patrol_interfaces__srv__Speech_Event;

// Struct for a sequence of carbot_patrol_interfaces__srv__Speech_Event.
typedef struct carbot_patrol_interfaces__srv__Speech_Event__Sequence
{
  carbot_patrol_interfaces__srv__Speech_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} carbot_patrol_interfaces__srv__Speech_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CARBOT_PATROL_INTERFACES__SRV__DETAIL__SPEECH__STRUCT_H_
