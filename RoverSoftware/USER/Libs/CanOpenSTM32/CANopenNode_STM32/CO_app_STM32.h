/*
 * CO_app_STM32.h
 *
 *  Created on: Aug 7, 2022
 *      Author: hamed
 */

#ifndef CANOPENSTM32_CO_APP_STM32_H_
#define CANOPENSTM32_CO_APP_STM32_H_

#include "CANopen.h"
#include "main.h"
#include "maincpp.h"

/* CANHandle : Pass in the CAN Handle to this function and it wil be used for all CAN Communications. It can be FDCan or CAN
 * and CANOpenSTM32 Driver will take of care of handling that
 * HWInitFunction : Pass in the function that initialize the CAN peripheral, usually MX_CAN_Init
 * timerHandle : Pass in the timer that is going to be used for generating 1ms interrupt for tmrThread function,
 * please note that CANOpenSTM32 Library will override HAL_TIM_PeriodElapsedCallback function, if you also need this function
 * in your codes, please take required steps

 */

#ifdef __cplusplus
extern "C" {
#endif


typedef struct {
    uint8_t
        desiredNodeID; /*This is the Node ID that you ask the CANOpen stack to assign to your device, although it might not always
	 * be the final NodeID, after calling canopen_app_init() you should check ActiveNodeID of CANopenNodeSTM32 structure for assigned Node ID.
	 */
    uint8_t activeNodeID; /* Assigned Node ID */
    uint16_t baudrate;     /* This is the baudrate you've set in your CubeMX Configuration */
    TIM_HandleTypeDef*
        timerHandle; /*Pass in the timer that is going to be used for generating 1ms interrupt for tmrThread function,
	 * please note that CANOpenSTM32 Library will override HAL_TIM_PeriodElapsedCallback function, if you also need this function in your codes, please take required steps
	 */

    /* Pass in the CAN Handle to this function and it wil be used for all CAN Communications. It can be FDCan or CAN
	 * and CANOpenSTM32 Driver will take of care of handling that*/
#ifdef CO_STM32_FDCAN_Driver
    FDCAN_HandleTypeDef* CANHandle;
#else
    CAN_HandleTypeDef* CANHandle;
#endif

    void (*HWInitFunction)(); /* Pass in the function that initialize the CAN peripheral, usually MX_CAN_Init */

    uint8_t outStatusLEDGreen; // This will be updated by the stack - Use them for the LED management
    uint8_t outStatusLEDRed;   // This will be updated by the stack - Use them for the LED management
    CO_t* canOpenStack;

} CANopenNodeSTM32;


// In order to use CANOpenSTM32, you'll have it have a canopenNodeSTM32 structure somewhere in your codes, it is usually residing in CO_app_STM32.c
extern CANopenNodeSTM32* canopenNodeSTM32;


/* This function will initialize the required CANOpen Stack objects, allocate the memory and prepare stack for communication reset*/
int canopen_app_init(CANopenNodeSTM32* canopenSTM32);
/* This function will reset the CAN communication periperhal and also the CANOpen stack variables */
int canopen_app_resetCommunication();
/* This function will check the input buffers and any outstanding tasks that are not time critical, this function should be called regurarly from your code (i.e from your while(1))*/
void canopen_app_process();
/* Thread function executes in constant intervals, this function can be called from FreeRTOS tasks or Timers ********/
void canopen_app_interrupt(void);

CO_SDO_abortCode_t read_SDO(CO_SDOclient_t *SDO_C, uint8_t nodeId,
                            uint16_t index, uint8_t subIndex,
                            uint8_t *buf, size_t bufSize, size_t *readSize);

CO_SDO_abortCode_t write_SDO(CO_SDOclient_t *SDO_C, uint8_t nodeId,
                             uint16_t index, uint8_t subIndex,
                             uint8_t *data, size_t dataSize);

void SDO_Write_32(CO_SDOclient_t *SDO_C, const OD_entry_t *entry, uint8_t subindex, uint32_t data);
void SDO_Write_16(CO_SDOclient_t *SDO_C, const OD_entry_t *entry, uint8_t subindex, uint16_t data);
void SDO_Write_8(CO_SDOclient_t *SDO_C, const OD_entry_t *entry, uint8_t subindex, uint8_t data);

void SDO_Read_32(CO_SDOclient_t *SDO_C, const OD_entry_t *entry, uint8_t subindex, uint32_t * data);
void SDO_Read_16(CO_SDOclient_t *SDO_C, const OD_entry_t *entry, uint8_t subindex, uint16_t * data);
void SDO_Read_8(CO_SDOclient_t *SDO_C, const OD_entry_t *entry, uint8_t subindex, uint8_t * data);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CANOPENSTM32_CO_APP_STM32_H_ */
