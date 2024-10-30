#ifndef _ROS_rover_msgs_Controlor_h
#define _ROS_rover_msgs_Controlor_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "rover_msgs/MotorSpeedDouble.h"

namespace rover_msgs
{

  class Controlor : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef int32_t _servo_type;
      _servo_type servo;
      typedef rover_msgs::MotorSpeedDouble _MotorLeft_type;
      _MotorLeft_type MotorLeft;
      typedef rover_msgs::MotorSpeedDouble _MotorRight_type;
      _MotorRight_type MotorRight;

    Controlor():
      header(),
      servo(0),
      MotorLeft(),
      MotorRight()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_servo;
      u_servo.real = this->servo;
      *(outbuffer + offset + 0) = (u_servo.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_servo.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_servo.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_servo.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->servo);
      offset += this->MotorLeft.serialize(outbuffer + offset);
      offset += this->MotorRight.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_servo;
      u_servo.base = 0;
      u_servo.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_servo.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_servo.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_servo.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->servo = u_servo.real;
      offset += sizeof(this->servo);
      offset += this->MotorLeft.deserialize(inbuffer + offset);
      offset += this->MotorRight.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "rover_msgs/Controlor"; };
    virtual const char * getMD5() override { return "04381b0b3275edd3d387038aa423b79b"; };

  };

}
#endif
