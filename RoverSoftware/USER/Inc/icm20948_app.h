#ifndef ICM20948_APP_H_
#define ICM20948_APP_H_

#include "main.h"
#include "maincpp.h"
#include "i2c.h"

#include "Invn/InvExport.h"
#include "Invn/Devices/SerifHal.h"
#include "Invn/Devices/SensorTypes.h"
#include "Invn/Devices/DeviceIcm20948.h"

#define ICM_Delay(us) vTaskDelay(us)
#define DeviceADD			(0x68<<1)

#define USE_RAW_ACC 0
#define USE_RAW_GYR 0
#define USE_GRV     1
#define USE_CAL_ACC 1
#define USE_CAL_GYR 1
#define USE_CAL_MAG 1
#define USE_UCAL_GYR 0
#define USE_UCAL_MAG 0
#define USE_RV      1    /* requires COMPASS*/
#define USE_GEORV   1    /* requires COMPASS*/
#define USE_ORI     1    /* requires COMPASS*/
#define USE_STEPC   0
#define USE_STEPD   0
#define USE_SMD     0
#define USE_BAC     0
#define USE_TILT    0
#define USE_PICKUP  0
#define USE_GRAVITY 1
#define USE_LINACC  0
#define USE_B2S     0

static const struct {
	uint8_t  type;
	uint32_t period_us;
} sensor_list[] = {
#if USE_RAW_ACC
	{ INV_SENSOR_TYPE_RAW_ACCELEROMETER, 50000 /* 20 Hz */ },
#endif
#if USE_RAW_GYR
	{ INV_SENSOR_TYPE_RAW_GYROSCOPE,     50000 /* 20 Hz */ },
#endif
#if USE_CAL_ACC
	{ INV_SENSOR_TYPE_ACCELEROMETER, 50000 /* 20 Hz */ },
#endif
#if USE_CAL_GYR
	{ INV_SENSOR_TYPE_GYROSCOPE, 50000 /* 20 Hz */ },
#endif
#if USE_CAL_MAG
	{ INV_SENSOR_TYPE_MAGNETOMETER, 50000 /* 20 Hz */ },
#endif
#if USE_UCAL_GYR
	{ INV_SENSOR_TYPE_UNCAL_GYROSCOPE, 50000 /* 20 Hz */ },
#endif
#if USE_UCAL_MAG
	{ INV_SENSOR_TYPE_UNCAL_MAGNETOMETER, 50000 /* 20 Hz */ },
#endif
#if USE_GRV
	{ INV_SENSOR_TYPE_GAME_ROTATION_VECTOR, 50000 /* 20 Hz */ },
#endif
#if USE_RV
	{ INV_SENSOR_TYPE_ROTATION_VECTOR, 50000 /* 20 Hz */ },
#endif
#if USE_GEORV
	{ INV_SENSOR_TYPE_GEOMAG_ROTATION_VECTOR, 50000 /* 20 Hz */ },
#endif
#if USE_ORI
	{ INV_SENSOR_TYPE_ORIENTATION, 50000 /* 20 Hz */ },
#endif
#if USE_STEPC
	{ INV_SENSOR_TYPE_STEP_COUNTER, ODR_NONE },
#endif
#if USE_STEPD
	{ INV_SENSOR_TYPE_STEP_DETECTOR, ODR_NONE},
#endif
#if USE_SMD
	{ INV_SENSOR_TYPE_SMD, ODR_NONE},
#endif
#if USE_BAC
	{ INV_SENSOR_TYPE_BAC, ODR_NONE},
#endif
#if USE_TILT
	{ INV_SENSOR_TYPE_TILT_DETECTOR, ODR_NONE},
#endif
#if USE_PICKUP
	{ INV_SENSOR_TYPE_PICK_UP_GESTURE, ODR_NONE},
#endif
#if USE_GRA
	{ INV_SENSOR_TYPE_GRAVITY, 50000 /* 20 Hz */},
#endif
#if USE_LINACC
	{ INV_SENSOR_TYPE_LINEAR_ACCELERATION, 50000 /* 20 Hz */},
#endif
#if USE_B2S
	{ INV_SENSOR_TYPE_B2S, ODR_NONE},
#endif
};

#define imu_iqr_en() HAL_NVIC_EnableIRQ(EXTI9_5_IRQn)
#define imu_iqr_disen() HAL_NVIC_DisableIRQ(EXTI9_5_IRQn)


#ifdef __cplusplus
extern "C"{
#endif
	
	float32_t get_accelerometer(uint8_t num);
	float32_t get_gyroscope(uint8_t num);
	float32_t get_magnetometer(uint8_t num);
	float32_t get_ref_quat(uint8_t num);
	
	int icm20948_init(void);
	void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);
	void icm20948_app(void);
	
	
	
#ifdef __cplusplus
}
#endif
	
#endif