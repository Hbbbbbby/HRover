#ifndef SERVO_H_
#define SERVO_H_

#include "tim.h"
#include "gpio.h"
#include "main.h"

/** How to calculate the angle
***	2div: 0.9ms-->1o 9ms-->10o 81ms-->90o
*** the limitation is from -90 to 90o
**/

#define TIMER_Handle	htim9

#define Limited_num	240

#define SERVO_Clockwise						GPIO_PIN_RESET
#define SERVO_Coiunterclockwise		GPIO_PIN_SET

#define SERVO_Dir(rotation)			HAL_GPIO_WritePin(M2_DIR_MCU_GPIO_Port, M2_DIR_MCU_Pin, rotation)

#define SERVO_Start()		HAL_TIM_PWM_Start(&TIMER_Handle, TIM_CHANNEL_1)
#define SERVO_Stop()		HAL_TIM_PWM_Stop(&TIMER_Handle, TIM_CHANNEL_1)

#define SERVO_TurnLeft(num)			do{SERVO_Dir(SERVO_Clockwise);SERVO_Start();vTaskDelay(num);SERVO_Stop();}while(0)
#define SERVO_TurnRight(num)			do{SERVO_Dir(SERVO_Coiunterclockwise);SERVO_Start();vTaskDelay(num);SERVO_Stop();}while(0)

#ifdef __cplusplus
extern "C"
{
#endif

	static uint8_t servo_app(int32_t _num)
	{
		int32_t num = _num;
		if(num>0)
		{
			SERVO_TurnLeft(num);
			return 1;
		}
		else if(num<0)
		{
			SERVO_TurnRight((-num));
			return 1;
		}
		else 
		{
			SERVO_Stop();
			return 0;
		}
	}
	
#ifdef __cplusplus
}
#endif

#endif