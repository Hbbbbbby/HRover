#ifndef ROS_H_
#define ROS_H_

#include "ros/node_handle.h"
#include "stm32hardware.h"

namespace ros{
	typedef ros::NodeHandle_<STM32Hardware> NodeHandle;
}

#endif