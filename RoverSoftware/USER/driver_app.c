#include "driver_app.h"

static Driver Driver_1 = {0x1, 0x0, Offline};
static Driver Driver_2 = {0x2, 0x1, Offline};

static uint8_t Driver_state = Offline;

static CANopenNodeSTM32 canOpenNodeSTM32;

static uint32_t detec_count = 0;

#if _Driver_ZLAC8030L
	static uint32_t rpdo_data[][3] = {
												{0x60ff,	0x00, DataType_U32}
	};

	static uint32_t tpdo_data[][3] = {
												{0x606c,	0x00, DataType_U32}
	};
#endif

#if _Driver_ZLAC8015L
	static uint32_t rpdo_data[][3] = {
												{0x60ff,	0x01, DataType_U32},
												{0x60ff,	0x02, DataType_U32},
	};

	static uint32_t tpdo_data[][3] = {
												{0x606c,	0x01, DataType_U32},
												{0x606c,	0x02, DataType_U32},
	};
#endif

uint8_t Driver_init(Driver* driver)
{
	uint8_t _id = driver->id;
	uint8_t _sdo = driver->sdo;
	uint8_t _state = driver->state;
	
	if(_state == Initialization){
	
		CO_NMT_sendCommand(canOpenNodeSTM32.canOpenStack->NMT,
			CO_NMT_ENTER_PRE_OPERATIONAL,
			_id
		);
		
			DriverSpeedMode(&canOpenNodeSTM32.canOpenStack->SDOclient[_sdo], 100, 100);
		
			DevicePDOConfiguration(
				&canOpenNodeSTM32.canOpenStack->SDOclient[_sdo], 0,
				OD_ENTRY_H1401_RPDOCommunicationParameter, OD_ENTRY_H1601_RPDOMappingParameter,
				rpdo_data, 1,
				PDO_Type_Event,0
			);
			DevicePDOConfiguration(
				&canOpenNodeSTM32.canOpenStack->SDOclient[_sdo], 0,
				OD_ENTRY_H1800_TPDOCommunicationParameter, OD_ENTRY_H1A00_TPDOMappingParameter,
				tpdo_data, 1,
				PDO_Type_Event,0
			);

		CO_NMT_sendCommand(canOpenNodeSTM32.canOpenStack->NMT,
			CO_NMT_ENTER_OPERATIONAL,
			_id
		);
		driver->state = Operation;
		return Success;
	}
	else
		return Non_Operation;
}

uint8_t driver_detectation(Driver * driver)
{
	uint16_t _id = 0;
	uint16_t _old_id = 0; 
#if _Driver_ZLAC8030L
		_old_id = 0x04;
#endif

#if _Driver_ZLAC8015L
		_old_id |= driver->id;
#endif
	
	uint8_t _sdo = driver->sdo;
	
	SDO_Read_16(
		&canOpenNodeSTM32.canOpenStack->SDOclient[_sdo],
		OD_ENTRY_H200D_CANID, 0, &_id
	);
	if(_old_id == _id)
	{
		return Initialization;
	}
	return Offline;
}


void driver_app(void)
{
  canOpenNodeSTM32.CANHandle = &hcan1;
  canOpenNodeSTM32.HWInitFunction = MX_CAN1_Init;
  canOpenNodeSTM32.timerHandle = &htim14;
  canOpenNodeSTM32.desiredNodeID = 6;
  canOpenNodeSTM32.baudrate = 500;
  canopen_app_init(&canOpenNodeSTM32);
	
	Driver_state = Prepare;
	
	for(;;)
	{
		switch(Driver_state){
			case Prepare: {
				
				if( Driver_1.state == Operation && Driver_2.state == Operation ){
					Driver_state = Operation;
					break;
				}
				else {
					
					if(Driver_1.state == Operation){
						;
					}
					else if(driver_detectation(&Driver_1) == Initialization){
						Driver_1.state = Initialization;
					}
					
					if(Driver_2.state == Operation){
						;
					}
					else if(driver_detectation(&Driver_2) == Initialization){
						Driver_2.state = Initialization;
					}
					
					if(Driver_1.state == Initialization 
						|| Driver_2.state == Initialization){
						Driver_state = Initialization;
					}
					Driver_Delay(1000);
					break;
				}
			}
			case Initialization: {
				if(Driver_1.state == Initialization){
					Driver_init(&Driver_1);
				}
				if(Driver_2.state == Initialization){
					Driver_init(&Driver_2);
				}
				
				if( Driver_1.state == Operation || Driver_2.state == Operation ){
					Driver_state = Operation;
				}
				else {
					Driver_Delay(1000);
				}
				break;
			}
			case Operation: {
				canopen_app_process();
			}
			default: {
				detec_count++;
				if(detec_count == 1000){
					detec_count = 0;
					if(driver_detectation(&Driver_1) == Offline 
						|| driver_detectation(&Driver_2) == Offline){
							Driver_state = Prepare;
							Driver_1.state = Offline;
							Driver_2.state = Offline;
					}
				}
			}
		}
		Driver_Delay(1);
	}
}


uint8_t get_Driver_state(void)
{
	return Driver_state;
}

uint8_t get_Driver_1_state(void)
{
	return Driver_1.state;
}

uint8_t get_Driver_2_state(void)
{
	return Driver_2.state;
}



