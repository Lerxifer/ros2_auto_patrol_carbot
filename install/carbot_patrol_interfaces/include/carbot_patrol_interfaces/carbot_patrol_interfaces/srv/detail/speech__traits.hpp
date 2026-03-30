// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from carbot_patrol_interfaces:srv/Speech.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "carbot_patrol_interfaces/srv/speech.hpp"


#ifndef CARBOT_PATROL_INTERFACES__SRV__DETAIL__SPEECH__TRAITS_HPP_
#define CARBOT_PATROL_INTERFACES__SRV__DETAIL__SPEECH__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "carbot_patrol_interfaces/srv/detail/speech__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace carbot_patrol_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Speech_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: text
  {
    out << "text: ";
    rosidl_generator_traits::value_to_yaml(msg.text, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Speech_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: text
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "text: ";
    rosidl_generator_traits::value_to_yaml(msg.text, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Speech_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace carbot_patrol_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use carbot_patrol_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const carbot_patrol_interfaces::srv::Speech_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  carbot_patrol_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use carbot_patrol_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const carbot_patrol_interfaces::srv::Speech_Request & msg)
{
  return carbot_patrol_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<carbot_patrol_interfaces::srv::Speech_Request>()
{
  return "carbot_patrol_interfaces::srv::Speech_Request";
}

template<>
inline const char * name<carbot_patrol_interfaces::srv::Speech_Request>()
{
  return "carbot_patrol_interfaces/srv/Speech_Request";
}

template<>
struct has_fixed_size<carbot_patrol_interfaces::srv::Speech_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<carbot_patrol_interfaces::srv::Speech_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<carbot_patrol_interfaces::srv::Speech_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace carbot_patrol_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Speech_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: result
  {
    out << "result: ";
    rosidl_generator_traits::value_to_yaml(msg.result, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Speech_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result: ";
    rosidl_generator_traits::value_to_yaml(msg.result, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Speech_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace carbot_patrol_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use carbot_patrol_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const carbot_patrol_interfaces::srv::Speech_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  carbot_patrol_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use carbot_patrol_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const carbot_patrol_interfaces::srv::Speech_Response & msg)
{
  return carbot_patrol_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<carbot_patrol_interfaces::srv::Speech_Response>()
{
  return "carbot_patrol_interfaces::srv::Speech_Response";
}

template<>
inline const char * name<carbot_patrol_interfaces::srv::Speech_Response>()
{
  return "carbot_patrol_interfaces/srv/Speech_Response";
}

template<>
struct has_fixed_size<carbot_patrol_interfaces::srv::Speech_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<carbot_patrol_interfaces::srv::Speech_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<carbot_patrol_interfaces::srv::Speech_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace carbot_patrol_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Speech_Event & msg,
  std::ostream & out)
{
  out << "{";
  // member: info
  {
    out << "info: ";
    to_flow_style_yaml(msg.info, out);
    out << ", ";
  }

  // member: request
  {
    if (msg.request.size() == 0) {
      out << "request: []";
    } else {
      out << "request: [";
      size_t pending_items = msg.request.size();
      for (auto item : msg.request) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: response
  {
    if (msg.response.size() == 0) {
      out << "response: []";
    } else {
      out << "response: [";
      size_t pending_items = msg.response.size();
      for (auto item : msg.response) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Speech_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: info
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "info:\n";
    to_block_style_yaml(msg.info, out, indentation + 2);
  }

  // member: request
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.request.size() == 0) {
      out << "request: []\n";
    } else {
      out << "request:\n";
      for (auto item : msg.request) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: response
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.response.size() == 0) {
      out << "response: []\n";
    } else {
      out << "response:\n";
      for (auto item : msg.response) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Speech_Event & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace carbot_patrol_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use carbot_patrol_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const carbot_patrol_interfaces::srv::Speech_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  carbot_patrol_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use carbot_patrol_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const carbot_patrol_interfaces::srv::Speech_Event & msg)
{
  return carbot_patrol_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<carbot_patrol_interfaces::srv::Speech_Event>()
{
  return "carbot_patrol_interfaces::srv::Speech_Event";
}

template<>
inline const char * name<carbot_patrol_interfaces::srv::Speech_Event>()
{
  return "carbot_patrol_interfaces/srv/Speech_Event";
}

template<>
struct has_fixed_size<carbot_patrol_interfaces::srv::Speech_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<carbot_patrol_interfaces::srv::Speech_Event>
  : std::integral_constant<bool, has_bounded_size<carbot_patrol_interfaces::srv::Speech_Request>::value && has_bounded_size<carbot_patrol_interfaces::srv::Speech_Response>::value && has_bounded_size<service_msgs::msg::ServiceEventInfo>::value> {};

template<>
struct is_message<carbot_patrol_interfaces::srv::Speech_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<carbot_patrol_interfaces::srv::Speech>()
{
  return "carbot_patrol_interfaces::srv::Speech";
}

template<>
inline const char * name<carbot_patrol_interfaces::srv::Speech>()
{
  return "carbot_patrol_interfaces/srv/Speech";
}

template<>
struct has_fixed_size<carbot_patrol_interfaces::srv::Speech>
  : std::integral_constant<
    bool,
    has_fixed_size<carbot_patrol_interfaces::srv::Speech_Request>::value &&
    has_fixed_size<carbot_patrol_interfaces::srv::Speech_Response>::value
  >
{
};

template<>
struct has_bounded_size<carbot_patrol_interfaces::srv::Speech>
  : std::integral_constant<
    bool,
    has_bounded_size<carbot_patrol_interfaces::srv::Speech_Request>::value &&
    has_bounded_size<carbot_patrol_interfaces::srv::Speech_Response>::value
  >
{
};

template<>
struct is_service<carbot_patrol_interfaces::srv::Speech>
  : std::true_type
{
};

template<>
struct is_service_request<carbot_patrol_interfaces::srv::Speech_Request>
  : std::true_type
{
};

template<>
struct is_service_response<carbot_patrol_interfaces::srv::Speech_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // CARBOT_PATROL_INTERFACES__SRV__DETAIL__SPEECH__TRAITS_HPP_
