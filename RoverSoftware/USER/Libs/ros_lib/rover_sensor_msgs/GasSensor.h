#ifndef _ROS_rover_sensor_msgs_GasSensor_h
#define _ROS_rover_sensor_msgs_GasSensor_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace rover_sensor_msgs
{

  class GasSensor : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _child_frame_id_type;
      _child_frame_id_type child_frame_id;
      typedef double _temperature_type;
      _temperature_type temperature;
      typedef double _temperature_variance_type;
      _temperature_variance_type temperature_variance;
      typedef double _humidity_type;
      _humidity_type humidity;
      typedef double _humidity_variance_type;
      _humidity_variance_type humidity_variance;
      typedef double _CO2_type;
      _CO2_type CO2;
      typedef double _CO2_variance_type;
      _CO2_variance_type CO2_variance;
      typedef double _PM1_0_type;
      _PM1_0_type PM1_0;
      typedef double _PM1_0_variance_type;
      _PM1_0_variance_type PM1_0_variance;
      typedef double _PM2_5_type;
      _PM2_5_type PM2_5;
      typedef double _PM2_5_variance_type;
      _PM2_5_variance_type PM2_5_variance;
      typedef double _PM10_type;
      _PM10_type PM10;
      typedef double _PM10_variance_type;
      _PM10_variance_type PM10_variance;
      typedef double _TVOC_type;
      _TVOC_type TVOC;
      typedef double _TVOC_variance_type;
      _TVOC_variance_type TVOC_variance;
      typedef double _formaldehyde_type;
      _formaldehyde_type formaldehyde;
      typedef double _formaldehyde_variance_type;
      _formaldehyde_variance_type formaldehyde_variance;

    GasSensor():
      header(),
      child_frame_id(""),
      temperature(0),
      temperature_variance(0),
      humidity(0),
      humidity_variance(0),
      CO2(0),
      CO2_variance(0),
      PM1_0(0),
      PM1_0_variance(0),
      PM2_5(0),
      PM2_5_variance(0),
      PM10(0),
      PM10_variance(0),
      TVOC(0),
      TVOC_variance(0),
      formaldehyde(0),
      formaldehyde_variance(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_child_frame_id = strlen(this->child_frame_id);
      varToArr(outbuffer + offset, length_child_frame_id);
      offset += 4;
      memcpy(outbuffer + offset, this->child_frame_id, length_child_frame_id);
      offset += length_child_frame_id;
      union {
        double real;
        uint64_t base;
      } u_temperature;
      u_temperature.real = this->temperature;
      *(outbuffer + offset + 0) = (u_temperature.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_temperature.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_temperature.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_temperature.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_temperature.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_temperature.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_temperature.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_temperature.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->temperature);
      union {
        double real;
        uint64_t base;
      } u_temperature_variance;
      u_temperature_variance.real = this->temperature_variance;
      *(outbuffer + offset + 0) = (u_temperature_variance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_temperature_variance.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_temperature_variance.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_temperature_variance.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_temperature_variance.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_temperature_variance.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_temperature_variance.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_temperature_variance.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->temperature_variance);
      union {
        double real;
        uint64_t base;
      } u_humidity;
      u_humidity.real = this->humidity;
      *(outbuffer + offset + 0) = (u_humidity.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_humidity.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_humidity.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_humidity.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_humidity.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_humidity.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_humidity.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_humidity.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->humidity);
      union {
        double real;
        uint64_t base;
      } u_humidity_variance;
      u_humidity_variance.real = this->humidity_variance;
      *(outbuffer + offset + 0) = (u_humidity_variance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_humidity_variance.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_humidity_variance.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_humidity_variance.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_humidity_variance.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_humidity_variance.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_humidity_variance.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_humidity_variance.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->humidity_variance);
      union {
        double real;
        uint64_t base;
      } u_CO2;
      u_CO2.real = this->CO2;
      *(outbuffer + offset + 0) = (u_CO2.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_CO2.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_CO2.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_CO2.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_CO2.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_CO2.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_CO2.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_CO2.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->CO2);
      union {
        double real;
        uint64_t base;
      } u_CO2_variance;
      u_CO2_variance.real = this->CO2_variance;
      *(outbuffer + offset + 0) = (u_CO2_variance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_CO2_variance.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_CO2_variance.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_CO2_variance.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_CO2_variance.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_CO2_variance.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_CO2_variance.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_CO2_variance.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->CO2_variance);
      union {
        double real;
        uint64_t base;
      } u_PM1_0;
      u_PM1_0.real = this->PM1_0;
      *(outbuffer + offset + 0) = (u_PM1_0.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_PM1_0.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_PM1_0.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_PM1_0.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_PM1_0.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_PM1_0.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_PM1_0.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_PM1_0.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->PM1_0);
      union {
        double real;
        uint64_t base;
      } u_PM1_0_variance;
      u_PM1_0_variance.real = this->PM1_0_variance;
      *(outbuffer + offset + 0) = (u_PM1_0_variance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_PM1_0_variance.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_PM1_0_variance.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_PM1_0_variance.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_PM1_0_variance.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_PM1_0_variance.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_PM1_0_variance.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_PM1_0_variance.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->PM1_0_variance);
      union {
        double real;
        uint64_t base;
      } u_PM2_5;
      u_PM2_5.real = this->PM2_5;
      *(outbuffer + offset + 0) = (u_PM2_5.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_PM2_5.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_PM2_5.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_PM2_5.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_PM2_5.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_PM2_5.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_PM2_5.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_PM2_5.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->PM2_5);
      union {
        double real;
        uint64_t base;
      } u_PM2_5_variance;
      u_PM2_5_variance.real = this->PM2_5_variance;
      *(outbuffer + offset + 0) = (u_PM2_5_variance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_PM2_5_variance.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_PM2_5_variance.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_PM2_5_variance.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_PM2_5_variance.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_PM2_5_variance.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_PM2_5_variance.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_PM2_5_variance.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->PM2_5_variance);
      union {
        double real;
        uint64_t base;
      } u_PM10;
      u_PM10.real = this->PM10;
      *(outbuffer + offset + 0) = (u_PM10.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_PM10.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_PM10.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_PM10.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_PM10.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_PM10.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_PM10.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_PM10.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->PM10);
      union {
        double real;
        uint64_t base;
      } u_PM10_variance;
      u_PM10_variance.real = this->PM10_variance;
      *(outbuffer + offset + 0) = (u_PM10_variance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_PM10_variance.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_PM10_variance.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_PM10_variance.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_PM10_variance.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_PM10_variance.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_PM10_variance.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_PM10_variance.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->PM10_variance);
      union {
        double real;
        uint64_t base;
      } u_TVOC;
      u_TVOC.real = this->TVOC;
      *(outbuffer + offset + 0) = (u_TVOC.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_TVOC.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_TVOC.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_TVOC.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_TVOC.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_TVOC.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_TVOC.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_TVOC.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->TVOC);
      union {
        double real;
        uint64_t base;
      } u_TVOC_variance;
      u_TVOC_variance.real = this->TVOC_variance;
      *(outbuffer + offset + 0) = (u_TVOC_variance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_TVOC_variance.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_TVOC_variance.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_TVOC_variance.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_TVOC_variance.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_TVOC_variance.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_TVOC_variance.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_TVOC_variance.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->TVOC_variance);
      union {
        double real;
        uint64_t base;
      } u_formaldehyde;
      u_formaldehyde.real = this->formaldehyde;
      *(outbuffer + offset + 0) = (u_formaldehyde.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_formaldehyde.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_formaldehyde.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_formaldehyde.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_formaldehyde.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_formaldehyde.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_formaldehyde.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_formaldehyde.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->formaldehyde);
      union {
        double real;
        uint64_t base;
      } u_formaldehyde_variance;
      u_formaldehyde_variance.real = this->formaldehyde_variance;
      *(outbuffer + offset + 0) = (u_formaldehyde_variance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_formaldehyde_variance.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_formaldehyde_variance.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_formaldehyde_variance.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_formaldehyde_variance.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_formaldehyde_variance.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_formaldehyde_variance.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_formaldehyde_variance.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->formaldehyde_variance);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_child_frame_id;
      arrToVar(length_child_frame_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_child_frame_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_child_frame_id-1]=0;
      this->child_frame_id = (char *)(inbuffer + offset-1);
      offset += length_child_frame_id;
      union {
        double real;
        uint64_t base;
      } u_temperature;
      u_temperature.base = 0;
      u_temperature.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_temperature.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_temperature.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_temperature.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_temperature.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_temperature.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_temperature.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_temperature.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->temperature = u_temperature.real;
      offset += sizeof(this->temperature);
      union {
        double real;
        uint64_t base;
      } u_temperature_variance;
      u_temperature_variance.base = 0;
      u_temperature_variance.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_temperature_variance.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_temperature_variance.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_temperature_variance.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_temperature_variance.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_temperature_variance.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_temperature_variance.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_temperature_variance.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->temperature_variance = u_temperature_variance.real;
      offset += sizeof(this->temperature_variance);
      union {
        double real;
        uint64_t base;
      } u_humidity;
      u_humidity.base = 0;
      u_humidity.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_humidity.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_humidity.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_humidity.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_humidity.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_humidity.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_humidity.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_humidity.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->humidity = u_humidity.real;
      offset += sizeof(this->humidity);
      union {
        double real;
        uint64_t base;
      } u_humidity_variance;
      u_humidity_variance.base = 0;
      u_humidity_variance.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_humidity_variance.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_humidity_variance.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_humidity_variance.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_humidity_variance.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_humidity_variance.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_humidity_variance.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_humidity_variance.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->humidity_variance = u_humidity_variance.real;
      offset += sizeof(this->humidity_variance);
      union {
        double real;
        uint64_t base;
      } u_CO2;
      u_CO2.base = 0;
      u_CO2.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_CO2.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_CO2.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_CO2.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_CO2.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_CO2.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_CO2.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_CO2.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->CO2 = u_CO2.real;
      offset += sizeof(this->CO2);
      union {
        double real;
        uint64_t base;
      } u_CO2_variance;
      u_CO2_variance.base = 0;
      u_CO2_variance.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_CO2_variance.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_CO2_variance.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_CO2_variance.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_CO2_variance.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_CO2_variance.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_CO2_variance.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_CO2_variance.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->CO2_variance = u_CO2_variance.real;
      offset += sizeof(this->CO2_variance);
      union {
        double real;
        uint64_t base;
      } u_PM1_0;
      u_PM1_0.base = 0;
      u_PM1_0.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_PM1_0.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_PM1_0.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_PM1_0.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_PM1_0.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_PM1_0.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_PM1_0.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_PM1_0.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->PM1_0 = u_PM1_0.real;
      offset += sizeof(this->PM1_0);
      union {
        double real;
        uint64_t base;
      } u_PM1_0_variance;
      u_PM1_0_variance.base = 0;
      u_PM1_0_variance.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_PM1_0_variance.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_PM1_0_variance.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_PM1_0_variance.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_PM1_0_variance.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_PM1_0_variance.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_PM1_0_variance.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_PM1_0_variance.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->PM1_0_variance = u_PM1_0_variance.real;
      offset += sizeof(this->PM1_0_variance);
      union {
        double real;
        uint64_t base;
      } u_PM2_5;
      u_PM2_5.base = 0;
      u_PM2_5.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_PM2_5.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_PM2_5.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_PM2_5.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_PM2_5.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_PM2_5.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_PM2_5.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_PM2_5.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->PM2_5 = u_PM2_5.real;
      offset += sizeof(this->PM2_5);
      union {
        double real;
        uint64_t base;
      } u_PM2_5_variance;
      u_PM2_5_variance.base = 0;
      u_PM2_5_variance.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_PM2_5_variance.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_PM2_5_variance.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_PM2_5_variance.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_PM2_5_variance.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_PM2_5_variance.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_PM2_5_variance.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_PM2_5_variance.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->PM2_5_variance = u_PM2_5_variance.real;
      offset += sizeof(this->PM2_5_variance);
      union {
        double real;
        uint64_t base;
      } u_PM10;
      u_PM10.base = 0;
      u_PM10.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_PM10.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_PM10.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_PM10.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_PM10.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_PM10.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_PM10.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_PM10.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->PM10 = u_PM10.real;
      offset += sizeof(this->PM10);
      union {
        double real;
        uint64_t base;
      } u_PM10_variance;
      u_PM10_variance.base = 0;
      u_PM10_variance.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_PM10_variance.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_PM10_variance.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_PM10_variance.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_PM10_variance.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_PM10_variance.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_PM10_variance.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_PM10_variance.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->PM10_variance = u_PM10_variance.real;
      offset += sizeof(this->PM10_variance);
      union {
        double real;
        uint64_t base;
      } u_TVOC;
      u_TVOC.base = 0;
      u_TVOC.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_TVOC.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_TVOC.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_TVOC.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_TVOC.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_TVOC.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_TVOC.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_TVOC.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->TVOC = u_TVOC.real;
      offset += sizeof(this->TVOC);
      union {
        double real;
        uint64_t base;
      } u_TVOC_variance;
      u_TVOC_variance.base = 0;
      u_TVOC_variance.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_TVOC_variance.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_TVOC_variance.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_TVOC_variance.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_TVOC_variance.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_TVOC_variance.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_TVOC_variance.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_TVOC_variance.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->TVOC_variance = u_TVOC_variance.real;
      offset += sizeof(this->TVOC_variance);
      union {
        double real;
        uint64_t base;
      } u_formaldehyde;
      u_formaldehyde.base = 0;
      u_formaldehyde.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_formaldehyde.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_formaldehyde.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_formaldehyde.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_formaldehyde.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_formaldehyde.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_formaldehyde.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_formaldehyde.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->formaldehyde = u_formaldehyde.real;
      offset += sizeof(this->formaldehyde);
      union {
        double real;
        uint64_t base;
      } u_formaldehyde_variance;
      u_formaldehyde_variance.base = 0;
      u_formaldehyde_variance.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_formaldehyde_variance.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_formaldehyde_variance.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_formaldehyde_variance.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_formaldehyde_variance.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_formaldehyde_variance.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_formaldehyde_variance.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_formaldehyde_variance.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->formaldehyde_variance = u_formaldehyde_variance.real;
      offset += sizeof(this->formaldehyde_variance);
     return offset;
    }

    virtual const char * getType() override { return "rover_sensor_msgs/GasSensor"; };
    virtual const char * getMD5() override { return "5277707407a5b52b337b922397933128"; };

  };

}
#endif
