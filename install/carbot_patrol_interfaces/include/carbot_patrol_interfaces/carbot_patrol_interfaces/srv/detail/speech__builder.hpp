// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from carbot_patrol_interfaces:srv/Speech.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "carbot_patrol_interfaces/srv/speech.hpp"


#ifndef CARBOT_PATROL_INTERFACES__SRV__DETAIL__SPEECH__BUILDER_HPP_
#define CARBOT_PATROL_INTERFACES__SRV__DETAIL__SPEECH__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "carbot_patrol_interfaces/srv/detail/speech__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace carbot_patrol_interfaces
{

namespace srv
{

namespace builder
{

class Init_Speech_Request_text
{
public:
  Init_Speech_Request_text()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::carbot_patrol_interfaces::srv::Speech_Request text(::carbot_patrol_interfaces::srv::Speech_Request::_text_type arg)
  {
    msg_.text = std::move(arg);
    return std::move(msg_);
  }

private:
  ::carbot_patrol_interfaces::srv::Speech_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::carbot_patrol_interfaces::srv::Speech_Request>()
{
  return carbot_patrol_interfaces::srv::builder::Init_Speech_Request_text();
}

}  // namespace carbot_patrol_interfaces


namespace carbot_patrol_interfaces
{

namespace srv
{

namespace builder
{

class Init_Speech_Response_result
{
public:
  Init_Speech_Response_result()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::carbot_patrol_interfaces::srv::Speech_Response result(::carbot_patrol_interfaces::srv::Speech_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::carbot_patrol_interfaces::srv::Speech_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::carbot_patrol_interfaces::srv::Speech_Response>()
{
  return carbot_patrol_interfaces::srv::builder::Init_Speech_Response_result();
}

}  // namespace carbot_patrol_interfaces


namespace carbot_patrol_interfaces
{

namespace srv
{

namespace builder
{

class Init_Speech_Event_response
{
public:
  explicit Init_Speech_Event_response(::carbot_patrol_interfaces::srv::Speech_Event & msg)
  : msg_(msg)
  {}
  ::carbot_patrol_interfaces::srv::Speech_Event response(::carbot_patrol_interfaces::srv::Speech_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::carbot_patrol_interfaces::srv::Speech_Event msg_;
};

class Init_Speech_Event_request
{
public:
  explicit Init_Speech_Event_request(::carbot_patrol_interfaces::srv::Speech_Event & msg)
  : msg_(msg)
  {}
  Init_Speech_Event_response request(::carbot_patrol_interfaces::srv::Speech_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_Speech_Event_response(msg_);
  }

private:
  ::carbot_patrol_interfaces::srv::Speech_Event msg_;
};

class Init_Speech_Event_info
{
public:
  Init_Speech_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Speech_Event_request info(::carbot_patrol_interfaces::srv::Speech_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_Speech_Event_request(msg_);
  }

private:
  ::carbot_patrol_interfaces::srv::Speech_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::carbot_patrol_interfaces::srv::Speech_Event>()
{
  return carbot_patrol_interfaces::srv::builder::Init_Speech_Event_info();
}

}  // namespace carbot_patrol_interfaces

#endif  // CARBOT_PATROL_INTERFACES__SRV__DETAIL__SPEECH__BUILDER_HPP_
