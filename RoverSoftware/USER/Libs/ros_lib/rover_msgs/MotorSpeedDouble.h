#ifndef _ROS_rover_msgs_MotorSpeedDouble_h
#define _ROS_rover_msgs_MotorSpeedDouble_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rover_msgs
{

  class MotorSpeedDouble : public ros::Msg
  {
    public:
      typedef int32_t _MotorLeft_type;
      _MotorLeft_type MotorLeft;
      typedef int32_t _MotorRight_type;
      _MotorRight_type MotorRight;
      typedef uint32_t _Combination_type;
      _Combination_type Combination;

    MotorSpeedDouble():
      MotorLeft(0),
      MotorRight(0),
      Combination(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_MotorLeft;
      u_MotorLeft.real = this->MotorLeft;
      *(outbuffer + offset + 0) = (u_MotorLeft.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_MotorLeft.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_MotorLeft.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_MotorLeft.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->MotorLeft);
      union {
        int32_t real;
        uint32_t base;
      } u_MotorRight;
      u_MotorRight.real = this->MotorRight;
      *(outbuffer + offset + 0) = (u_MotorRight.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_MotorRight.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_MotorRight.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_MotorRight.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->MotorRight);
      *(outbuffer + offset + 0) = (this->Combination >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->Combination >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->Combination >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->Combination >> (8 * 3)) & 0xFF;
      offset += sizeof(this->Combination);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_MotorLeft;
      u_MotorLeft.base = 0;
      u_MotorLeft.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_MotorLeft.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_MotorLeft.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_MotorLeft.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->MotorLeft = u_MotorLeft.real;
      offset += sizeof(this->MotorLeft);
      union {
        int32_t real;
        uint32_t base;
      } u_MotorRight;
      u_MotorRight.base = 0;
      u_MotorRight.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_MotorRight.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_MotorRight.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_MotorRight.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->MotorRight = u_MotorRight.real;
      offset += sizeof(this->MotorRight);
      this->Combination =  ((uint32_t) (*(inbuffer + offset)));
      this->Combination |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->Combination |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->Combination |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->Combination);
     return offset;
    }

    virtual const char * getType() override { return "rover_msgs/MotorSpeedDouble"; };
    virtual const char * getMD5() override { return "2a72fddf385e7f23e8280c250c800526"; };

  };

}
#endif
