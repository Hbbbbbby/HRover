#include "icm20948_app.h"

static uint8_t dmp3_image[] = {
 #include "Invn/Images/icm20948_img.dmp3a.h"
};

static inv_device_icm20948_t device_icm20948; 
static inv_device_t * device;

static float32_t _accelerometer[3];
static float32_t _gyroscope[3];
static float32_t _magnetometer[3];
static float32_t _ref_quat[4];

int my_serif_open_read_reg(void * context, uint8_t reg, uint8_t * rbuffer, uint32_t rlen)
{
	return HAL_I2C_Mem_Read(&hi2c1, DeviceADD, reg, 1, rbuffer, rlen, 10);
}

int my_serif_open_write_reg(void * context, uint8_t reg, const uint8_t * wbuffer, uint32_t wlen)
{
	return HAL_I2C_Mem_Write(&hi2c1, DeviceADD, reg, 1, (uint8_t *)wbuffer, wlen, 10);
}

const inv_serif_hal_t my_serif_instance = {
	my_serif_open_read_reg,  /* callback to read_reg low level method */
	my_serif_open_write_reg, /* callback to read_reg low level method */
	128,                     /* maximum number of bytes allowed per read transaction,
															(limitation can come from internal buffer in the system driver) */
	128,                     /* maximum number of bytes allowed per write transaction,
															(limitation can come from internal buffer in the system driver) */
	INV_SERIF_HAL_TYPE_I2C,  /* type of the serial interface (between SPI or I2C) */
	(void *)0xDEAD           /* some context pointer passed to read_reg/write_reg callbacks */
};

void icm20948_delay_us(int nus)
{
	uint32_t ticks;
	uint32_t told,tnow,tcnt=0;
	uint32_t reload=SysTick->LOAD;					   	 
	ticks=nus*(SystemCoreClock/16000000);  		 
	tcnt=0;
	vTaskSuspendAll();								
	told=SysTick->VAL;        				
	while(1)
	{
		tnow=SysTick->VAL;	
		if(tnow!=told)
		{	    
			if(tnow<told)tcnt+=told-tnow;	
			else tcnt+=reload-tnow+told;	    
			told=tnow;
			if(tcnt>=ticks)break;					
		}  
	};
	xTaskResumeAll();	
}

void inv_icm20948_sleep_us(int us)
{
	icm20948_delay_us(us);
}

uint64_t inv_icm20948_get_time_us(void)
{
	return __HAL_TIM_GET_COUNTER(&htim14);
}



static void sensor_event_cb(const inv_sensor_event_t * event, void * arg)
{
        /* arg will contained the value provided at init time */
        (void)arg;
        /* ... do something with event */
	if(event->status == INV_SENSOR_STATUS_DATA_UPDATED){
		switch(INV_SENSOR_ID_TO_TYPE(event->sensor)){
			case INV_SENSOR_TYPE_ACCELEROMETER:
				memcpy(_accelerometer, event->data.acc.vect, sizeof(event->data.acc.vect));
				break;
			case INV_SENSOR_TYPE_GYROSCOPE:
				memcpy(_gyroscope, event->data.gyr.vect, sizeof(event->data.gyr.vect));
				break;
			case INV_SENSOR_TYPE_MAGNETOMETER:
				memcpy(_magnetometer, event->data.mag.vect, sizeof(event->data.mag.vect));
				break;
			case INV_SENSOR_TYPE_GAME_ROTATION_VECTOR:
				memcpy(_ref_quat, event->data.quaternion.quat, sizeof(event->data.quaternion.quat));
				break;
			default:
				break;
		}
	}
}

float32_t get_accelerometer(uint8_t num)
{
	return _accelerometer[num];
}

float32_t get_gyroscope(uint8_t num)
{
	return _gyroscope[num];
}

float32_t get_magnetometer(uint8_t num)
{
	return _magnetometer[num];
}

float32_t get_ref_quat(uint8_t num)
{
	return _ref_quat[num];
}


static inv_sensor_listener_t sensor_listener = {
        sensor_event_cb, /* callback that will receive sensor events */
        (void *)0xDEAD   /* some pointer passed to the callback */
};

//void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
//{
//	if(GPIO_Pin == IMU_INT1_Pin){
//		osSemaphoreRelease(IMUBinarySemHandle);
//	}
//}


int icm20948_init(void)
{
	int rc = 0;
	uint8_t whoami;
	
	inv_device_icm20948_init2(
		&device_icm20948, &my_serif_instance, &sensor_listener,
		dmp3_image, sizeof(dmp3_image)
	);
	
	device = inv_device_icm20948_get_base(&device_icm20948);
	rc += inv_device_whoami(device, &whoami);
	rc += inv_device_setup(device);
	
	uint64_t available_sensor_mask; /* To keep track of available sensors*/
	unsigned i = 0;
	/*
	 * Check sensor availibitlity
	 * if rc value is 0, it means sensor is available,
	 * if rc value is INV_ERROR or INV_ERROR_BAD_ARG, sensor is NA
	 */
	available_sensor_mask = 0;
	for(i = 0; i < sizeof(sensor_list)/sizeof(sensor_list[0]); ++i) {
		const int rc = inv_device_ping_sensor(device, sensor_list[i].type);
		if(rc == 0) {
			available_sensor_mask |= (1ULL << sensor_list[i].type);
		}
	}
	
	/*
	 * Start all available sensors from the sensor list
	 */
	for(i = 0; i < sizeof(sensor_list)/sizeof(sensor_list[0]); ++i) {
		if(available_sensor_mask & (1ULL << sensor_list[i].type)) {
			rc  = inv_device_set_sensor_period_us(device, sensor_list[i].type, sensor_list[i].period_us);
			rc += inv_device_start_sensor(device, sensor_list[i].type);
		}
	}
	return rc;
}

// Freertos task entry
void icm20948_app(void)
{
	inv_device_poll(device);
}
