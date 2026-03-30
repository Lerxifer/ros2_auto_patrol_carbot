// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from carbot_patrol_interfaces:srv/Speech.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "carbot_patrol_interfaces/srv/detail/speech__rosidl_typesupport_introspection_c.h"
#include "carbot_patrol_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "carbot_patrol_interfaces/srv/detail/speech__functions.h"
#include "carbot_patrol_interfaces/srv/detail/speech__struct.h"


// Include directives for member types
// Member `text`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void carbot_patrol_interfaces__srv__Speech_Request__rosidl_typesupport_introspection_c__Speech_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  carbot_patrol_interfaces__srv__Speech_Request__init(message_memory);
}

void carbot_patrol_interfaces__srv__Speech_Request__rosidl_typesupport_introspection_c__Speech_Request_fini_function(void * message_memory)
{
  carbot_patrol_interfaces__srv__Speech_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember carbot_patrol_interfaces__srv__Speech_Request__rosidl_typesupport_introspection_c__Speech_Request_message_member_array[1] = {
  {
    "text",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(carbot_patrol_interfaces__srv__Speech_Request, text),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers carbot_patrol_interfaces__srv__Speech_Request__rosidl_typesupport_introspection_c__Speech_Request_message_members = {
  "carbot_patrol_interfaces__srv",  // message namespace
  "Speech_Request",  // message name
  1,  // number of fields
  sizeof(carbot_patrol_interfaces__srv__Speech_Request),
  false,  // has_any_key_member_
  carbot_patrol_interfaces__srv__Speech_Request__rosidl_typesupport_introspection_c__Speech_Request_message_member_array,  // message members
  carbot_patrol_interfaces__srv__Speech_Request__rosidl_typesupport_introspection_c__Speech_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  carbot_patrol_interfaces__srv__Speech_Request__rosidl_typesupport_introspection_c__Speech_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t carbot_patrol_interfaces__srv__Speech_Request__rosidl_typesupport_introspection_c__Speech_Request_message_type_support_handle = {
  0,
  &carbot_patrol_interfaces__srv__Speech_Request__rosidl_typesupport_introspection_c__Speech_Request_message_members,
  get_message_typesupport_handle_function,
  &carbot_patrol_interfaces__srv__Speech_Request__get_type_hash,
  &carbot_patrol_interfaces__srv__Speech_Request__get_type_description,
  &carbot_patrol_interfaces__srv__Speech_Request__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_carbot_patrol_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, carbot_patrol_interfaces, srv, Speech_Request)() {
  if (!carbot_patrol_interfaces__srv__Speech_Request__rosidl_typesupport_introspection_c__Speech_Request_message_type_support_handle.typesupport_identifier) {
    carbot_patrol_interfaces__srv__Speech_Request__rosidl_typesupport_introspection_c__Speech_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &carbot_patrol_interfaces__srv__Speech_Request__rosidl_typesupport_introspection_c__Speech_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "carbot_patrol_interfaces/srv/detail/speech__rosidl_typesupport_introspection_c.h"
// already included above
// #include "carbot_patrol_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "carbot_patrol_interfaces/srv/detail/speech__functions.h"
// already included above
// #include "carbot_patrol_interfaces/srv/detail/speech__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void carbot_patrol_interfaces__srv__Speech_Response__rosidl_typesupport_introspection_c__Speech_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  carbot_patrol_interfaces__srv__Speech_Response__init(message_memory);
}

void carbot_patrol_interfaces__srv__Speech_Response__rosidl_typesupport_introspection_c__Speech_Response_fini_function(void * message_memory)
{
  carbot_patrol_interfaces__srv__Speech_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember carbot_patrol_interfaces__srv__Speech_Response__rosidl_typesupport_introspection_c__Speech_Response_message_member_array[1] = {
  {
    "result",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(carbot_patrol_interfaces__srv__Speech_Response, result),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers carbot_patrol_interfaces__srv__Speech_Response__rosidl_typesupport_introspection_c__Speech_Response_message_members = {
  "carbot_patrol_interfaces__srv",  // message namespace
  "Speech_Response",  // message name
  1,  // number of fields
  sizeof(carbot_patrol_interfaces__srv__Speech_Response),
  false,  // has_any_key_member_
  carbot_patrol_interfaces__srv__Speech_Response__rosidl_typesupport_introspection_c__Speech_Response_message_member_array,  // message members
  carbot_patrol_interfaces__srv__Speech_Response__rosidl_typesupport_introspection_c__Speech_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  carbot_patrol_interfaces__srv__Speech_Response__rosidl_typesupport_introspection_c__Speech_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t carbot_patrol_interfaces__srv__Speech_Response__rosidl_typesupport_introspection_c__Speech_Response_message_type_support_handle = {
  0,
  &carbot_patrol_interfaces__srv__Speech_Response__rosidl_typesupport_introspection_c__Speech_Response_message_members,
  get_message_typesupport_handle_function,
  &carbot_patrol_interfaces__srv__Speech_Response__get_type_hash,
  &carbot_patrol_interfaces__srv__Speech_Response__get_type_description,
  &carbot_patrol_interfaces__srv__Speech_Response__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_carbot_patrol_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, carbot_patrol_interfaces, srv, Speech_Response)() {
  if (!carbot_patrol_interfaces__srv__Speech_Response__rosidl_typesupport_introspection_c__Speech_Response_message_type_support_handle.typesupport_identifier) {
    carbot_patrol_interfaces__srv__Speech_Response__rosidl_typesupport_introspection_c__Speech_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &carbot_patrol_interfaces__srv__Speech_Response__rosidl_typesupport_introspection_c__Speech_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "carbot_patrol_interfaces/srv/detail/speech__rosidl_typesupport_introspection_c.h"
// already included above
// #include "carbot_patrol_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "carbot_patrol_interfaces/srv/detail/speech__functions.h"
// already included above
// #include "carbot_patrol_interfaces/srv/detail/speech__struct.h"


// Include directives for member types
// Member `info`
#include "service_msgs/msg/service_event_info.h"
// Member `info`
#include "service_msgs/msg/detail/service_event_info__rosidl_typesupport_introspection_c.h"
// Member `request`
// Member `response`
#include "carbot_patrol_interfaces/srv/speech.h"
// Member `request`
// Member `response`
// already included above
// #include "carbot_patrol_interfaces/srv/detail/speech__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void carbot_patrol_interfaces__srv__Speech_Event__rosidl_typesupport_introspection_c__Speech_Event_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  carbot_patrol_interfaces__srv__Speech_Event__init(message_memory);
}

void carbot_patrol_interfaces__srv__Speech_Event__rosidl_typesupport_introspection_c__Speech_Event_fini_function(void * message_memory)
{
  carbot_patrol_interfaces__srv__Speech_Event__fini(message_memory);
}

size_t carbot_patrol_interfaces__srv__Speech_Event__rosidl_typesupport_introspection_c__size_function__Speech_Event__request(
  const void * untyped_member)
{
  const carbot_patrol_interfaces__srv__Speech_Request__Sequence * member =
    (const carbot_patrol_interfaces__srv__Speech_Request__Sequence *)(untyped_member);
  return member->size;
}

const void * carbot_patrol_interfaces__srv__Speech_Event__rosidl_typesupport_introspection_c__get_const_function__Speech_Event__request(
  const void * untyped_member, size_t index)
{
  const carbot_patrol_interfaces__srv__Speech_Request__Sequence * member =
    (const carbot_patrol_interfaces__srv__Speech_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void * carbot_patrol_interfaces__srv__Speech_Event__rosidl_typesupport_introspection_c__get_function__Speech_Event__request(
  void * untyped_member, size_t index)
{
  carbot_patrol_interfaces__srv__Speech_Request__Sequence * member =
    (carbot_patrol_interfaces__srv__Speech_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void carbot_patrol_interfaces__srv__Speech_Event__rosidl_typesupport_introspection_c__fetch_function__Speech_Event__request(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const carbot_patrol_interfaces__srv__Speech_Request * item =
    ((const carbot_patrol_interfaces__srv__Speech_Request *)
    carbot_patrol_interfaces__srv__Speech_Event__rosidl_typesupport_introspection_c__get_const_function__Speech_Event__request(untyped_member, index));
  carbot_patrol_interfaces__srv__Speech_Request * value =
    (carbot_patrol_interfaces__srv__Speech_Request *)(untyped_value);
  *value = *item;
}

void carbot_patrol_interfaces__srv__Speech_Event__rosidl_typesupport_introspection_c__assign_function__Speech_Event__request(
  void * untyped_member, size_t index, const void * untyped_value)
{
  carbot_patrol_interfaces__srv__Speech_Request * item =
    ((carbot_patrol_interfaces__srv__Speech_Request *)
    carbot_patrol_interfaces__srv__Speech_Event__rosidl_typesupport_introspection_c__get_function__Speech_Event__request(untyped_member, index));
  const carbot_patrol_interfaces__srv__Speech_Request * value =
    (const carbot_patrol_interfaces__srv__Speech_Request *)(untyped_value);
  *item = *value;
}

bool carbot_patrol_interfaces__srv__Speech_Event__rosidl_typesupport_introspection_c__resize_function__Speech_Event__request(
  void * untyped_member, size_t size)
{
  carbot_patrol_interfaces__srv__Speech_Request__Sequence * member =
    (carbot_patrol_interfaces__srv__Speech_Request__Sequence *)(untyped_member);
  carbot_patrol_interfaces__srv__Speech_Request__Sequence__fini(member);
  return carbot_patrol_interfaces__srv__Speech_Request__Sequence__init(member, size);
}

size_t carbot_patrol_interfaces__srv__Speech_Event__rosidl_typesupport_introspection_c__size_function__Speech_Event__response(
  const void * untyped_member)
{
  const carbot_patrol_interfaces__srv__Speech_Response__Sequence * member =
    (const carbot_patrol_interfaces__srv__Speech_Response__Sequence *)(untyped_member);
  return member->size;
}

const void * carbot_patrol_interfaces__srv__Speech_Event__rosidl_typesupport_introspection_c__get_const_function__Speech_Event__response(
  const void * untyped_member, size_t index)
{
  const carbot_patrol_interfaces__srv__Speech_Response__Sequence * member =
    (const carbot_patrol_interfaces__srv__Speech_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void * carbot_patrol_interfaces__srv__Speech_Event__rosidl_typesupport_introspection_c__get_function__Speech_Event__response(
  void * untyped_member, size_t index)
{
  carbot_patrol_interfaces__srv__Speech_Response__Sequence * member =
    (carbot_patrol_interfaces__srv__Speech_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void carbot_patrol_interfaces__srv__Speech_Event__rosidl_typesupport_introspection_c__fetch_function__Speech_Event__response(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const carbot_patrol_interfaces__srv__Speech_Response * item =
    ((const carbot_patrol_interfaces__srv__Speech_Response *)
    carbot_patrol_interfaces__srv__Speech_Event__rosidl_typesupport_introspection_c__get_const_function__Speech_Event__response(untyped_member, index));
  carbot_patrol_interfaces__srv__Speech_Response * value =
    (carbot_patrol_interfaces__srv__Speech_Response *)(untyped_value);
  *value = *item;
}

void carbot_patrol_interfaces__srv__Speech_Event__rosidl_typesupport_introspection_c__assign_function__Speech_Event__response(
  void * untyped_member, size_t index, const void * untyped_value)
{
  carbot_patrol_interfaces__srv__Speech_Response * item =
    ((carbot_patrol_interfaces__srv__Speech_Response *)
    carbot_patrol_interfaces__srv__Speech_Event__rosidl_typesupport_introspection_c__get_function__Speech_Event__response(untyped_member, index));
  const carbot_patrol_interfaces__srv__Speech_Response * value =
    (const carbot_patrol_interfaces__srv__Speech_Response *)(untyped_value);
  *item = *value;
}

bool carbot_patrol_interfaces__srv__Speech_Event__rosidl_typesupport_introspection_c__resize_function__Speech_Event__response(
  void * untyped_member, size_t size)
{
  carbot_patrol_interfaces__srv__Speech_Response__Sequence * member =
    (carbot_patrol_interfaces__srv__Speech_Response__Sequence *)(untyped_member);
  carbot_patrol_interfaces__srv__Speech_Response__Sequence__fini(member);
  return carbot_patrol_interfaces__srv__Speech_Response__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember carbot_patrol_interfaces__srv__Speech_Event__rosidl_typesupport_introspection_c__Speech_Event_message_member_array[3] = {
  {
    "info",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(carbot_patrol_interfaces__srv__Speech_Event, info),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "request",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(carbot_patrol_interfaces__srv__Speech_Event, request),  // bytes offset in struct
    NULL,  // default value
    carbot_patrol_interfaces__srv__Speech_Event__rosidl_typesupport_introspection_c__size_function__Speech_Event__request,  // size() function pointer
    carbot_patrol_interfaces__srv__Speech_Event__rosidl_typesupport_introspection_c__get_const_function__Speech_Event__request,  // get_const(index) function pointer
    carbot_patrol_interfaces__srv__Speech_Event__rosidl_typesupport_introspection_c__get_function__Speech_Event__request,  // get(index) function pointer
    carbot_patrol_interfaces__srv__Speech_Event__rosidl_typesupport_introspection_c__fetch_function__Speech_Event__request,  // fetch(index, &value) function pointer
    carbot_patrol_interfaces__srv__Speech_Event__rosidl_typesupport_introspection_c__assign_function__Speech_Event__request,  // assign(index, value) function pointer
    carbot_patrol_interfaces__srv__Speech_Event__rosidl_typesupport_introspection_c__resize_function__Speech_Event__request  // resize(index) function pointer
  },
  {
    "response",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(carbot_patrol_interfaces__srv__Speech_Event, response),  // bytes offset in struct
    NULL,  // default value
    carbot_patrol_interfaces__srv__Speech_Event__rosidl_typesupport_introspection_c__size_function__Speech_Event__response,  // size() function pointer
    carbot_patrol_interfaces__srv__Speech_Event__rosidl_typesupport_introspection_c__get_const_function__Speech_Event__response,  // get_const(index) function pointer
    carbot_patrol_interfaces__srv__Speech_Event__rosidl_typesupport_introspection_c__get_function__Speech_Event__response,  // get(index) function pointer
    carbot_patrol_interfaces__srv__Speech_Event__rosidl_typesupport_introspection_c__fetch_function__Speech_Event__response,  // fetch(index, &value) function pointer
    carbot_patrol_interfaces__srv__Speech_Event__rosidl_typesupport_introspection_c__assign_function__Speech_Event__response,  // assign(index, value) function pointer
    carbot_patrol_interfaces__srv__Speech_Event__rosidl_typesupport_introspection_c__resize_function__Speech_Event__response  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers carbot_patrol_interfaces__srv__Speech_Event__rosidl_typesupport_introspection_c__Speech_Event_message_members = {
  "carbot_patrol_interfaces__srv",  // message namespace
  "Speech_Event",  // message name
  3,  // number of fields
  sizeof(carbot_patrol_interfaces__srv__Speech_Event),
  false,  // has_any_key_member_
  carbot_patrol_interfaces__srv__Speech_Event__rosidl_typesupport_introspection_c__Speech_Event_message_member_array,  // message members
  carbot_patrol_interfaces__srv__Speech_Event__rosidl_typesupport_introspection_c__Speech_Event_init_function,  // function to initialize message memory (memory has to be allocated)
  carbot_patrol_interfaces__srv__Speech_Event__rosidl_typesupport_introspection_c__Speech_Event_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t carbot_patrol_interfaces__srv__Speech_Event__rosidl_typesupport_introspection_c__Speech_Event_message_type_support_handle = {
  0,
  &carbot_patrol_interfaces__srv__Speech_Event__rosidl_typesupport_introspection_c__Speech_Event_message_members,
  get_message_typesupport_handle_function,
  &carbot_patrol_interfaces__srv__Speech_Event__get_type_hash,
  &carbot_patrol_interfaces__srv__Speech_Event__get_type_description,
  &carbot_patrol_interfaces__srv__Speech_Event__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_carbot_patrol_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, carbot_patrol_interfaces, srv, Speech_Event)() {
  carbot_patrol_interfaces__srv__Speech_Event__rosidl_typesupport_introspection_c__Speech_Event_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, service_msgs, msg, ServiceEventInfo)();
  carbot_patrol_interfaces__srv__Speech_Event__rosidl_typesupport_introspection_c__Speech_Event_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, carbot_patrol_interfaces, srv, Speech_Request)();
  carbot_patrol_interfaces__srv__Speech_Event__rosidl_typesupport_introspection_c__Speech_Event_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, carbot_patrol_interfaces, srv, Speech_Response)();
  if (!carbot_patrol_interfaces__srv__Speech_Event__rosidl_typesupport_introspection_c__Speech_Event_message_type_support_handle.typesupport_identifier) {
    carbot_patrol_interfaces__srv__Speech_Event__rosidl_typesupport_introspection_c__Speech_Event_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &carbot_patrol_interfaces__srv__Speech_Event__rosidl_typesupport_introspection_c__Speech_Event_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "carbot_patrol_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "carbot_patrol_interfaces/srv/detail/speech__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers carbot_patrol_interfaces__srv__detail__speech__rosidl_typesupport_introspection_c__Speech_service_members = {
  "carbot_patrol_interfaces__srv",  // service namespace
  "Speech",  // service name
  // the following fields are initialized below on first access
  NULL,  // request message
  // carbot_patrol_interfaces__srv__detail__speech__rosidl_typesupport_introspection_c__Speech_Request_message_type_support_handle,
  NULL,  // response message
  // carbot_patrol_interfaces__srv__detail__speech__rosidl_typesupport_introspection_c__Speech_Response_message_type_support_handle
  NULL  // event_message
  // carbot_patrol_interfaces__srv__detail__speech__rosidl_typesupport_introspection_c__Speech_Response_message_type_support_handle
};


static rosidl_service_type_support_t carbot_patrol_interfaces__srv__detail__speech__rosidl_typesupport_introspection_c__Speech_service_type_support_handle = {
  0,
  &carbot_patrol_interfaces__srv__detail__speech__rosidl_typesupport_introspection_c__Speech_service_members,
  get_service_typesupport_handle_function,
  &carbot_patrol_interfaces__srv__Speech_Request__rosidl_typesupport_introspection_c__Speech_Request_message_type_support_handle,
  &carbot_patrol_interfaces__srv__Speech_Response__rosidl_typesupport_introspection_c__Speech_Response_message_type_support_handle,
  &carbot_patrol_interfaces__srv__Speech_Event__rosidl_typesupport_introspection_c__Speech_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    carbot_patrol_interfaces,
    srv,
    Speech
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    carbot_patrol_interfaces,
    srv,
    Speech
  ),
  &carbot_patrol_interfaces__srv__Speech__get_type_hash,
  &carbot_patrol_interfaces__srv__Speech__get_type_description,
  &carbot_patrol_interfaces__srv__Speech__get_type_description_sources,
};

// Forward declaration of message type support functions for service members
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, carbot_patrol_interfaces, srv, Speech_Request)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, carbot_patrol_interfaces, srv, Speech_Response)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, carbot_patrol_interfaces, srv, Speech_Event)(void);

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_carbot_patrol_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, carbot_patrol_interfaces, srv, Speech)(void) {
  if (!carbot_patrol_interfaces__srv__detail__speech__rosidl_typesupport_introspection_c__Speech_service_type_support_handle.typesupport_identifier) {
    carbot_patrol_interfaces__srv__detail__speech__rosidl_typesupport_introspection_c__Speech_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)carbot_patrol_interfaces__srv__detail__speech__rosidl_typesupport_introspection_c__Speech_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, carbot_patrol_interfaces, srv, Speech_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, carbot_patrol_interfaces, srv, Speech_Response)()->data;
  }
  if (!service_members->event_members_) {
    service_members->event_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, carbot_patrol_interfaces, srv, Speech_Event)()->data;
  }

  return &carbot_patrol_interfaces__srv__detail__speech__rosidl_typesupport_introspection_c__Speech_service_type_support_handle;
}
