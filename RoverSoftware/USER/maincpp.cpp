#include "maincpp.h"

#include "led.h"
#include "ros.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Twist.h"
#include "rover_msgs/Controlor.h"
#include "sensor_msgs/Imu.h"

static int32_t value_old_Motor_1_left = 0;
static int32_t value_old_Motor_1_right = 0;
static int32_t value_old_Motor_2_left = 0;
static int32_t value_old_Motor_2_right = 0;

ros::NodeHandle nh;

LEDClass sysled_0(SYS_LED_0_GPIO_Port, SYS_LED_0_Pin);

LEDClass sysled_1(SYS_LED_1_GPIO_Port, SYS_LED_1_Pin);

GPIOClass servo_dir(M2_DIR_MCU_GPIO_Port, M2_DIR_MCU_Pin);

static int32_t servo_num = 0;
static int32_t servo_num_old = 0;

sensor_msgs::Imu imu_msg;
ros::Publisher Pub_IMU("/Rover/Feedback/Imu", &imu_msg);

rover_msgs::Controlor feedback_speed;
ros::Publisher Pub_MotorSpeed("/Rover/Feedback/Speeds", &feedback_speed);

void DriverCallback(const rover_msgs::Controlor & cmd_msg){

	servo_num = cmd_msg.servo;
	if(servo_num>Limited_num)
	{
		servo_num=Limited_num;
	}
	else if(servo_num<(-Limited_num))
	{
		servo_num=(-Limited_num);
	}
	servo_num -= servo_num_old;
	servo_num_old = cmd_msg.servo;

#if _Driver_ZLAC8030L
	OD_PERSIST_COMM.x60FF_targetSpeed = -(cmd_msg.MotorLeft.MotorLeft);
	OD_PERSIST_COMM.x70FF_targetSpeed = cmd_msg.MotorLeft.MotorRight;

 	if(OD_PERSIST_COMM.x60FF_targetSpeed!=value_old_Motor_1_left){
		EventTrigger(OD_ENTRY_H60FF, 0);
		value_old_Motor_1_left=OD_PERSIST_COMM.x60FF_targetSpeed;
	}
	if(OD_PERSIST_COMM.x70FF_targetSpeed!=value_old_Motor_2_left){
		EventTrigger(OD_ENTRY_H70FF, 0);
		value_old_Motor_2_left=OD_PERSIST_COMM.x70FF_targetSpeed;
	}
#endif

#if _Driver_ZLAC8015L

	OD_PERSIST_COMM.x60FF_targetSpeed[0] = cmd_msg.MotorLeft.MotorLeft;
	OD_PERSIST_COMM.x60FF_targetSpeed[1] = cmd_msg.MotorLeft.MotorRight;
	OD_PERSIST_COMM.x70FF_targetSpeed[0] = cmd_msg.MotorRight.MotorLeft;
	OD_PERSIST_COMM.x70FF_targetSpeed[1] = cmd_msg.MotorRight.MotorRight;


 	if(OD_PERSIST_COMM.x60FF_targetSpeed[0]!=value_old_Motor_1_left){
		EventTrigger(OD_ENTRY_H60FF,1);
		value_old_Motor_1_left=OD_PERSIST_COMM.x60FF_targetSpeed[0];
	}
	
	if(OD_PERSIST_COMM.x60FF_targetSpeed[1]!=value_old_Motor_1_right){
		EventTrigger(OD_ENTRY_H60FF,2);
		value_old_Motor_1_right=OD_PERSIST_COMM.x60FF_targetSpeed[1];
	}
	
	if(OD_PERSIST_COMM.x70FF_targetSpeed[0]!=value_old_Motor_2_left){
		EventTrigger(OD_ENTRY_H70FF,1);
		value_old_Motor_2_left=OD_PERSIST_COMM.x70FF_targetSpeed[0];
	}
	
	if(OD_PERSIST_COMM.x70FF_targetSpeed[1]!=value_old_Motor_2_right){
		EventTrigger(OD_ENTRY_H70FF,2);
		value_old_Motor_2_right=OD_PERSIST_COMM.x70FF_targetSpeed[1];
	}
#endif

}
ros::Subscriber<rover_msgs::Controlor> Sub_Drivers("/Rover/drivers", DriverCallback);


void setup(void)
{
}

void StartSysLEDTask(void const *argument)
{
  /* USER CODE BEGIN StartSysTask */
	
  /* Infinite loop */
  for(;;)
  {
		switch(get_Driver_state()){
			case Operation: {
				sysled_0.toggle();
				vTaskDelay(1000);
				break;
			}
			case Initialization:{
				sysled_0.flashing(vTaskDelay, 100, 5);
				break;
			}
			default:
				sysled_0.flashing(vTaskDelay, 200, 2);
				
		}
		vTaskDelay(1000);
  }
  /* USER CODE END StartSysTask */
}

void StartSysTask(void const * argument)
{
  /* USER CODE BEGIN StartSysTask */
	nh.initNode();
	nh.advertise(Pub_MotorSpeed);
	nh.advertise(Pub_IMU);
	nh.subscribe(Sub_Drivers);
  /* Infinite loop */
  for(;;)
  {
	nh.spinOnce();
    vTaskDelay(pdMS_TO_TICKS(1));
  }
  /* USER CODE END StartSysTask */
}

void StartServoTask(void const * argument)
{
	uint8_t servo_flag = 0;
	for(;;)
	{		
		servo_flag = servo_app(servo_num);
		if(servo_flag) servo_num = 0;
		vTaskDelay(pdMS_TO_TICKS(10));
	}
}

void StartPublisher2Task(void const * argument)
{
	for(;;)
	{
		switch(get_Driver_state())
		{
			case Operation: 
			{
#if _Driver_ZLAC8030L
				if(get_Driver_1_state() == Operation){
					feedback_speed.MotorLeft.MotorLeft = OD_PERSIST_COMM.x606C_currentSpeedFeedBack;
					feedback_speed.MotorLeft.MotorRight = OD_PERSIST_COMM.x606C_currentSpeedFeedBack;
				}
				else{
					feedback_speed.MotorLeft.MotorLeft = 999;
					feedback_speed.MotorLeft.MotorRight = 999;
				}
				if(get_Driver_2_state() == Operation){
					feedback_speed.MotorRight.MotorLeft = OD_PERSIST_COMM.x706C_currentSpeedFeedBack;
					feedback_speed.MotorRight.MotorRight = OD_PERSIST_COMM.x706C_currentSpeedFeedBack;
				}
				else{
					feedback_speed.MotorRight.MotorLeft = 999;
					feedback_speed.MotorRight.MotorRight = 999;
				}
#endif
#if _Driver_ZLAC8015L
				if(get_Driver_1_state() == Operation){
					feedback_speed.MotorLeft.MotorLeft = OD_PERSIST_COMM.x606C_currentSpeedFeedBack[0];
					feedback_speed.MotorLeft.MotorRight = OD_PERSIST_COMM.x606C_currentSpeedFeedBack[1];
				}
				else{
					feedback_speed.MotorLeft.MotorLeft = 999;
					feedback_speed.MotorLeft.MotorRight = 999;
				}
				if(get_Driver_2_state() == Operation){
					feedback_speed.MotorRight.MotorLeft = OD_PERSIST_COMM.x706C_currentSpeedFeedBack[0];
					feedback_speed.MotorRight.MotorRight = OD_PERSIST_COMM.x706C_currentSpeedFeedBack[1];
				}
				else{
					feedback_speed.MotorRight.MotorLeft = 999;
					feedback_speed.MotorRight.MotorRight = 999;
				}
#endif
				Pub_MotorSpeed.publish( &feedback_speed );
				vTaskDelay(100);	
				break;
			}
			default:
				vTaskDelay(10);
		}
	}
}

void StartIMUTask(void const * argument)
{
  /* USER CODE BEGIN StartSysTask */
	icm20948_init();
	HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);
	
  /* Infinite loop */
  for(;;)
  {
		if(osSemaphoreWait(IMUBinarySemHandle, 10)==osOK){
			
			icm20948_app();
			
			imu_msg.angular_velocity.x = get_gyroscope(0);
			imu_msg.angular_velocity.y = get_gyroscope(1);
			imu_msg.angular_velocity.z = get_gyroscope(2);
			
			imu_msg.linear_acceleration.x = get_accelerometer(0);
			imu_msg.linear_acceleration.y = get_accelerometer(1);
			imu_msg.linear_acceleration.z = get_accelerometer(2);
			
			imu_msg.orientation.w = get_ref_quat(0);
			imu_msg.orientation.x = get_ref_quat(1);
			imu_msg.orientation.y = get_ref_quat(2);
			imu_msg.orientation.z = get_ref_quat(3);
			

			imu_msg.header.frame_id = "rover_link";
			imu_msg.header.stamp = nh.now();
			
			Pub_IMU.publish( &imu_msg );
			sysled_1.toggle();
		}
    vTaskDelay(10);
  }
  /* USER CODE END StartSysTask */
}


void StartDriverTask(void const * argument)
{
	for(;;)
	{
		driver_app();
		vTaskDelay(1);
	}
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if(GPIO_Pin == IMU_INT1_Pin){
		osSemaphoreRelease(IMUBinarySemHandle);
	}
}

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart){
	nh.getHardware()->flush();
}
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
	nh.getHardware()->reset_rbuf();
}