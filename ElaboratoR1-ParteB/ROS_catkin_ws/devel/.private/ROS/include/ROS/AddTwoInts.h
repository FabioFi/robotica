// Generated by gencpp from file ROS/AddTwoInts.msg
// DO NOT EDIT!


#ifndef ROS_MESSAGE_ADDTWOINTS_H
#define ROS_MESSAGE_ADDTWOINTS_H

#include <ros/service_traits.h>


#include <ROS/AddTwoIntsRequest.h>
#include <ROS/AddTwoIntsResponse.h>


namespace ROS
{

struct AddTwoInts
{

typedef AddTwoIntsRequest Request;
typedef AddTwoIntsResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct AddTwoInts
} // namespace ROS


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::ROS::AddTwoInts > {
  static const char* value()
  {
    return "6a2e34150c00229791cc89ff309fff21";
  }

  static const char* value(const ::ROS::AddTwoInts&) { return value(); }
};

template<>
struct DataType< ::ROS::AddTwoInts > {
  static const char* value()
  {
    return "ROS/AddTwoInts";
  }

  static const char* value(const ::ROS::AddTwoInts&) { return value(); }
};


// service_traits::MD5Sum< ::ROS::AddTwoIntsRequest> should match 
// service_traits::MD5Sum< ::ROS::AddTwoInts > 
template<>
struct MD5Sum< ::ROS::AddTwoIntsRequest>
{
  static const char* value()
  {
    return MD5Sum< ::ROS::AddTwoInts >::value();
  }
  static const char* value(const ::ROS::AddTwoIntsRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::ROS::AddTwoIntsRequest> should match 
// service_traits::DataType< ::ROS::AddTwoInts > 
template<>
struct DataType< ::ROS::AddTwoIntsRequest>
{
  static const char* value()
  {
    return DataType< ::ROS::AddTwoInts >::value();
  }
  static const char* value(const ::ROS::AddTwoIntsRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::ROS::AddTwoIntsResponse> should match 
// service_traits::MD5Sum< ::ROS::AddTwoInts > 
template<>
struct MD5Sum< ::ROS::AddTwoIntsResponse>
{
  static const char* value()
  {
    return MD5Sum< ::ROS::AddTwoInts >::value();
  }
  static const char* value(const ::ROS::AddTwoIntsResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::ROS::AddTwoIntsResponse> should match 
// service_traits::DataType< ::ROS::AddTwoInts > 
template<>
struct DataType< ::ROS::AddTwoIntsResponse>
{
  static const char* value()
  {
    return DataType< ::ROS::AddTwoInts >::value();
  }
  static const char* value(const ::ROS::AddTwoIntsResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // ROS_MESSAGE_ADDTWOINTS_H
