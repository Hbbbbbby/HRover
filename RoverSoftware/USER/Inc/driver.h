#ifndef DRIVER_H_
#define DRIVER_H_

#include "main.h"
#include "CO_app_STM32.h"
#include "DriverConfiguration.h"
#include "OD.h"

#define CiA402_SMC_Shutdown				(0x00)
#define CiA402_SMC_ReadySwitchOn		(0x06)
#define CiA402_SMC_SwitchOn				(0x07)
#define CiA402_SMC_OperationEnable		(0x0F)

#define CiA402_MotorMode_None			(0x00)
#define CiA402_MotorMode_Position		(0x01)
#define CiA402_MotorMode_Speed			(0x03)
#define CiA402_MotorMode_Torque			(0x04)

#define DataType_U8						(0x08)
#define DataType_U16					(0x10)
#define DataType_U32					(0x20)

#define PDO_Type_Event	(254)
#define PDO_Type_Timer	(255)

#define Diver_alive(id)		SDO

#define Set_Driver_State(SDO_C, state)	SDO_Write_16(SDO_C, OD_ENTRY_H6040_controlWord, 0x00, state)
#define Driver_Restart(SDO_C)	Set_Driver_State(SDO_C, CiA402_SMC_Shutdown)
#define Driver_Starup(SDO_C)	\
do{\
	Set_Driver_State(SDO_C, CiA402_SMC_ReadySwitchOn);\
	Set_Driver_State(SDO_C, CiA402_SMC_SwitchOn);\
	Set_Driver_State(SDO_C, CiA402_SMC_OperationEnable);\
}while(0)



#define Set_Motor_Mode(SDO_C, mode)	SDO_Write_8(SDO_C, OD_ENTRY_H6060_motionMode, 0x00, mode)

#if	_Driver_ZLAC8030L
	#define Set_Motor_STypeAccelerationTime(SDO_C, speed) SDO_Write_32(SDO_C, OD_ENTRY_H6083_STypeAccelerationTime, 0x00, speed)
	#define Set_Motor_STypeDecelerationTime(SDO_C, speed) SDO_Write_32(SDO_C, OD_ENTRY_H6084_STypeDecelerationTime, 0x00, speed)
	#define Set_Motor_TorqueSlope(SDO_C, time_ms)	SDO_Write_32(SDO_C, OD_ENTRY_H6087_torqueSlope, 0x00, time_ms)
#endif

#if	_Driver_ZLAC8015L
	#define Set_Motor_Sync(enable)	SDO_Write_16(SDO_C, OD_ENTRY_H200F_syncFlag, 0x00, enable)
	#define Set_Motor_STypeAccelerationTime(SDO_C, speed) \
	do{	\
		SDO_Write_32(SDO_C, OD_ENTRY_H6083_STypeAccelerationTime, 0x01, speed);	\
		SDO_Write_32(SDO_C, OD_ENTRY_H6083_STypeAccelerationTime, 0x02, speed);	\
	}while(0)

	#define Set_Motor_STypeDecelerationTime(SDO_C, speed)	\
	do{	\
		SDO_Write_32(SDO_C, OD_ENTRY_H6084_STypeDecelerationTime, 0x01, speed);	\
		SDO_Write_32(SDO_C, OD_ENTRY_H6084_STypeDecelerationTime, 0x02, speed);	\
	}while(0)
#endif


#define Clear_PDO_Mapping(SDO_C, PDO_Mapping) SDO_Write_8(SDO_C, PDO_Mapping, 0x00, 0x00)

#define Set_PDO_Mapping(SDO_C, PDO_Mapping, subIndex, Addr, subAddr, ValueType) \
	SDO_Write_32(SDO_C, PDO_Mapping, subIndex,	\
		(	\
				(	(	((uint32_t)(Addr)<<8) |((uint8_t)(subAddr))	) <<8)	|(uint8_t)ValueType	\
		)	\
	)


#define Start_PDO_Mapping(SDO_C, PDO_Mapping, subindex_counts)	SDO_Write_8(SDO_C, PDO_Mapping, 0x00, subindex_counts)


#define Set_PDO_Type_Event(SDO_C, PDO_Para) SDO_Write_8(SDO_C, PDO_Para, 0x02, PDO_Type_Event)
#define Set_PDO_Type_Timer(SDO_C, PDO_Para, Times) \
do{\
	SDO_Write_8(SDO_C, PDO_Para, 0x02, PDO_Type_Timer);\
	SDO_Write_16(SDO_C, PDO_Para, 0x05, Times);\
}while(0)
#define Set_PDO_Type_Sync(SDO_C, PDO_Para, Times) SDO_Write_8(SDO_C, PDO_Para, 0x02, Times)
#define Set_PDO_COBID(SDO_C, PDO_Para, COBID)	SDO_Write_32(SDO_C, PDO_Para, 0x01, COBID)




#ifdef __cplusplus
extern "C" {
#endif

void DriverSpeedMode(
	CO_SDOclient_t *SDO_C,
	uint32_t starSpeed, uint32_t stopSpeed
#if _Driver_ZLAC8015L
	,uint16_t sync
#endif
);

#if _Driver_ZLAC8030L
	void DriverTorqueMode(
		CO_SDOclient_t *SDO_C, 
		uint32_t DecelerationTime
	);
#endif
	
void DevicePDOConfiguration(
		CO_SDOclient_t *SDO_C, const uint32_t COBID, 
		const OD_entry_t *PDOPara_entry, const OD_entry_t *PDOMap_entry,
		const uint32_t Mapping_list[][3],	uint8_t M_counts,
		uint8_t mode, uint16_t timers
	);
	
#ifdef __cplusplus
}
#endif
#endif