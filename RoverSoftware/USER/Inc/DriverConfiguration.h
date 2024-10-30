#ifndef DRIVERCONFIGURATION_H_
#define DRIVERCONFIGURATION_H_

#include "OD.h"

#define _Driver_ZLAC8030L	1

#if !_Driver_ZLAC8030L
	#define _Driver_ZLAC8015L	1
#endif

#define MappingNum	2


static OD_extension_t LinkingMappedVariable_Extension_List[MappingNum];
static OD_entry_t *LinkingMappedVariable_Entry_List[MappingNum];

static void EventTPDO_Init(void)
{
	LinkingMappedVariable_Entry_List[0] = OD_ENTRY_H60FF_targetSpeed;
	LinkingMappedVariable_Entry_List[1] = OD_ENTRY_H70FF_targetSpeed;

	for(uint8_t i = 0; i<MappingNum; i++)
	{
		LinkingMappedVariable_Extension_List[i].read = OD_readOriginal;
		LinkingMappedVariable_Extension_List[i].write = OD_writeOriginal;
		OD_extension_init(
			LinkingMappedVariable_Entry_List[i],
			&LinkingMappedVariable_Extension_List[i]
		);
	}
}

#define EventTrigger(entry,flagbit)	OD_requestTPDO(OD_getFlagsPDO((entry)), (flagbit))	


static void canopen_app_EventTPDO_process(void)
{
//	static int32_t value_old_1 = 0;
//	EventTrigger(OD_ENTRY_H60FF_targetSpeed, OD_PERSIST_COMM.x60FF_targetSpeed[2], value_old_1, 3);
		
}


#endif