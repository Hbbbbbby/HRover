#ifndef DRIVER_APP_H_
#define DRIVER_APP_H_

#include "driver.h"

#define Driver_Delay(num) osDelay(num)

typedef struct {
	uint8_t id;
	uint8_t sdo;
	uint16_t state;
}Driver;

enum Driver_State{
	Offline	= 0,
	Prepare,
	Initialization,
	Operation,
};

enum Driver_Init_Error{
	Success	= 0,
	Non_Operation
};

#ifdef __cplusplus
extern "C" {
#endif

	void driver_app(void);
//	uint8_t driver_detectation(Driver * driver);
	uint8_t get_Driver_state(void);
	uint8_t get_Driver_1_state(void);
	uint8_t get_Driver_2_state(void);
	
#ifdef __cplusplus
}
#endif
#endif