// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from carbot_patrol_interfaces:srv/Speech.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "carbot_patrol_interfaces/srv/detail/speech__functions.h"
#include "carbot_patrol_interfaces/srv/detail/speech__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace carbot_patrol_interfaces
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _Speech_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Speech_Request_type_support_ids_t;

static const _Speech_Request_type_support_ids_t _Speech_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Speech_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Speech_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Speech_Request_type_support_symbol_names_t _Speech_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, carbot_patrol_interfaces, srv, Speech_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, carbot_patrol_interfaces, srv, Speech_Request)),
  }
};

typedef struct _Speech_Request_type_support_data_t
{
  void * data[2];
} _Speech_Request_type_support_data_t;

static _Speech_Request_type_support_data_t _Speech_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Speech_Request_message_typesupport_map = {
  2,
  "carbot_patrol_interfaces",
  &_Speech_Request_message_typesupport_ids.typesupport_identifier[0],
  &_Speech_Request_message_typesupport_symbol_names.symbol_name[0],
  &_Speech_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Speech_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Speech_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &carbot_patrol_interfaces__srv__Speech_Request__get_type_hash,
  &carbot_patrol_interfaces__srv__Speech_Request__get_type_description,
  &carbot_patrol_interfaces__srv__Speech_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace carbot_patrol_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<carbot_patrol_interfaces::srv::Speech_Request>()
{
  return &::carbot_patrol_interfaces::srv::rosidl_typesupport_cpp::Speech_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, carbot_patrol_interfaces, srv, Speech_Request)() {
  return get_message_type_support_handle<carbot_patrol_interfaces::srv::Speech_Request>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "carbot_patrol_interfaces/srv/detail/speech__functions.h"
// already included above
// #include "carbot_patrol_interfaces/srv/detail/speech__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace carbot_patrol_interfaces
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _Speech_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Speech_Response_type_support_ids_t;

static const _Speech_Response_type_support_ids_t _Speech_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Speech_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Speech_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Speech_Response_type_support_symbol_names_t _Speech_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, carbot_patrol_interfaces, srv, Speech_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, carbot_patrol_interfaces, srv, Speech_Response)),
  }
};

typedef struct _Speech_Response_type_support_data_t
{
  void * data[2];
} _Speech_Response_type_support_data_t;

static _Speech_Response_type_support_data_t _Speech_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Speech_Response_message_typesupport_map = {
  2,
  "carbot_patrol_interfaces",
  &_Speech_Response_message_typesupport_ids.typesupport_identifier[0],
  &_Speech_Response_message_typesupport_symbol_names.symbol_name[0],
  &_Speech_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Speech_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Speech_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &carbot_patrol_interfaces__srv__Speech_Response__get_type_hash,
  &carbot_patrol_interfaces__srv__Speech_Response__get_type_description,
  &carbot_patrol_interfaces__srv__Speech_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace carbot_patrol_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<carbot_patrol_interfaces::srv::Speech_Response>()
{
  return &::carbot_patrol_interfaces::srv::rosidl_typesupport_cpp::Speech_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, carbot_patrol_interfaces, srv, Speech_Response)() {
  return get_message_type_support_handle<carbot_patrol_interfaces::srv::Speech_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "carbot_patrol_interfaces/srv/detail/speech__functions.h"
// already included above
// #include "carbot_patrol_interfaces/srv/detail/speech__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace carbot_patrol_interfaces
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _Speech_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Speech_Event_type_support_ids_t;

static const _Speech_Event_type_support_ids_t _Speech_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Speech_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Speech_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Speech_Event_type_support_symbol_names_t _Speech_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, carbot_patrol_interfaces, srv, Speech_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, carbot_patrol_interfaces, srv, Speech_Event)),
  }
};

typedef struct _Speech_Event_type_support_data_t
{
  void * data[2];
} _Speech_Event_type_support_data_t;

static _Speech_Event_type_support_data_t _Speech_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Speech_Event_message_typesupport_map = {
  2,
  "carbot_patrol_interfaces",
  &_Speech_Event_message_typesupport_ids.typesupport_identifier[0],
  &_Speech_Event_message_typesupport_symbol_names.symbol_name[0],
  &_Speech_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Speech_Event_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Speech_Event_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &carbot_patrol_interfaces__srv__Speech_Event__get_type_hash,
  &carbot_patrol_interfaces__srv__Speech_Event__get_type_description,
  &carbot_patrol_interfaces__srv__Speech_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace carbot_patrol_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<carbot_patrol_interfaces::srv::Speech_Event>()
{
  return &::carbot_patrol_interfaces::srv::rosidl_typesupport_cpp::Speech_Event_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, carbot_patrol_interfaces, srv, Speech_Event)() {
  return get_message_type_support_handle<carbot_patrol_interfaces::srv::Speech_Event>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "carbot_patrol_interfaces/srv/detail/speech__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace carbot_patrol_interfaces
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _Speech_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Speech_type_support_ids_t;

static const _Speech_type_support_ids_t _Speech_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Speech_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Speech_type_support_symbol_names_t;
#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Speech_type_support_symbol_names_t _Speech_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, carbot_patrol_interfaces, srv, Speech)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, carbot_patrol_interfaces, srv, Speech)),
  }
};

typedef struct _Speech_type_support_data_t
{
  void * data[2];
} _Speech_type_support_data_t;

static _Speech_type_support_data_t _Speech_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Speech_service_typesupport_map = {
  2,
  "carbot_patrol_interfaces",
  &_Speech_service_typesupport_ids.typesupport_identifier[0],
  &_Speech_service_typesupport_symbol_names.symbol_name[0],
  &_Speech_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t Speech_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Speech_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
  ::rosidl_typesupport_cpp::get_message_type_support_handle<carbot_patrol_interfaces::srv::Speech_Request>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<carbot_patrol_interfaces::srv::Speech_Response>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<carbot_patrol_interfaces::srv::Speech_Event>(),
  &::rosidl_typesupport_cpp::service_create_event_message<carbot_patrol_interfaces::srv::Speech>,
  &::rosidl_typesupport_cpp::service_destroy_event_message<carbot_patrol_interfaces::srv::Speech>,
  &carbot_patrol_interfaces__srv__Speech__get_type_hash,
  &carbot_patrol_interfaces__srv__Speech__get_type_description,
  &carbot_patrol_interfaces__srv__Speech__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace carbot_patrol_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<carbot_patrol_interfaces::srv::Speech>()
{
  return &::carbot_patrol_interfaces::srv::rosidl_typesupport_cpp::Speech_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_cpp, carbot_patrol_interfaces, srv, Speech)() {
  return ::rosidl_typesupport_cpp::get_service_type_support_handle<carbot_patrol_interfaces::srv::Speech>();
}

#ifdef __cplusplus
}
#endif
