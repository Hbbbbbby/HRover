#include "driver.h"

void DriverSpeedMode(
	CO_SDOclient_t *SDO_C,
	uint32_t starSpeed, uint32_t stopSpeed
#if _Driver_ZLAC8015L
	,uint16_t sync
#endif
)
{
	Driver_Restart(SDO_C);
	Set_Motor_STypeAccelerationTime(SDO_C, starSpeed);
	Set_Motor_STypeDecelerationTime(SDO_C, stopSpeed);
	Set_Motor_Mode(SDO_C, CiA402_MotorMode_Speed);
	
#if _Driver_ZLAC8015L
	Set_Motor_Sync(sync);
#endif	

	Driver_Starup(SDO_C);
}


void DriverTorqueMode(
	CO_SDOclient_t *SDO_C, 
	uint32_t DecelerationTime
)
{
//	Driver_Restart(SDO_C);
//	(SDO_C, CiA402_MotorMode_Torque);
//	Driver_Starup(SDO_C);
}

// if mode = Set_PDO_Type_Event, timers parameter does nothing. 
void DevicePDOConfiguration(
	CO_SDOclient_t *SDO_C, const uint32_t COBID,
	const OD_entry_t *PDOPara_entry, const OD_entry_t *PDOMap_entry,
	const uint32_t Mapping_list[][3], uint8_t M_counts,
	uint8_t mode, uint16_t timers
)
{
	Clear_PDO_Mapping(SDO_C, PDOMap_entry);
	
	for(uint8_t i = 1; i<=M_counts; i++)
		Set_PDO_Mapping(SDO_C, PDOMap_entry, i, Mapping_list[i-1][0],  Mapping_list[i-1][1], Mapping_list[i-1][2]);
	
	if(COBID!=0)
		Set_PDO_COBID(SDO_C, PDOPara_entry, COBID);
	
	if(mode == PDO_Type_Event)
		Set_PDO_Type_Event(SDO_C, PDOPara_entry); 
	else if(mode == PDO_Type_Timer)
		Set_PDO_Type_Timer(SDO_C, PDOPara_entry, timers);
	else
	{;}
	
	Start_PDO_Mapping(SDO_C, PDOMap_entry, M_counts);
}




