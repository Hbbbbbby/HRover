#ifndef MAINCPP_H_
#define MAINCPP_H_

#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"
	
#include "CO_app_STM32.h"
#include "driver_app.h"
#include "can.h"
#include "tim.h"

#include "servo.h"

#include "icm20948_app.h"

#define PUB_TASK_1_Hz		()
#define PUB_TASK_2_Hz		()


#ifdef __cplusplus
extern "C" {
#endif
			
	extern osSemaphoreId IMUBinarySemHandle;
	
	void setup(void);
	void StartSysTask(void const * argument);
	
	void StartPublisher2Task(void const * argument);
	
	void StartServoTask(void const * argument);
	
	void StartSysLEDTask(void const * argument);
	
	void StartDriverTask(void const * argument);
	
	void StartIMUTask(void const * argument);
	
#ifdef __cplusplus
}

#endif
#endif