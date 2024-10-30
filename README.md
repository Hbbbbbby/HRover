# HRover

## Summary
This project provides a set of **STM32 software** to drive a rover that is able to finish intelligent tasks such as tracking objects, SLAM, and so forth. It is a bit complicated, mainly involving [**ROS(Robot Operation System)**][ROS], [**CANopen**][CANopen] and [**FreeRTOS**][FreeRTOS], which are helpful in constructing a flexible and developer-friendly rover. 
<!-- links -->
[ROS]: https://www.ros.org
[CANopen]: https://www.can-cia.org
[FreeRTOS]: https://www.freertos.org

The rover containing wheels, motors and various sensors is just similar to average cars but installs a Raspberry Pi computer more. To manage those components effectively, they are abstracted into ROS nodes respectively. And ROS is deployed into STM23 software via a ROS package, namely [***rosserial***][ROS_rosserial], also as a bridge from STM32 to Raspberry Pi.
<!-- links -->
[ROS_rosserial]:https://wiki.ros.org/rosserial

More specifically, the wheels of this rover are driven by the CANopen drivers that communicate with the microchip with CANopen in terms of easier control and monitoring their states comprehensively. For sensors like IMU, it is a vital part of SLAM.

At the end of the day, the project is so rough that it is hard to understand so if any questions, please ask me directly by email. And of course I will complete it gradually, teaching followers to set it up step by step.
### Specially Thanks
The project refers lots of great works which can be found by following links,
- [ROS][ROS_github]
- [rosserial_stm32][rosserial_stm32_github]
- [CANopenNode STM32][CANopen_github]
<!-- links -->
[ROS_github]: https://github.com/ros/ros
[CANopen_github]: https://github.com/CANopenNode/CanOpenSTM32
[rosserial_stm32_github]: https://github.com/yoneken/rosserial_stm32


## System Architecture

- ___RoverSoftware/User___ : contain driver files and libraries.
  - _driver.c_ 
  - _driver.cpp_
  - _icm20948_app.c_
  - _maincpp.cpp_
- ___RoverSoftware___ : to be produced automatically with STM32CUBEMX
  - _CMakeFiles_
  - _Core_
  - _Drivers_
  - _Middleswares_
  - _CMakeLists.txt_
  - _RoverConfiguration.ioc_
  - _startup_stm32f407xx.s_
  - _STM32F407VETx_FLASH.ld_


## Requirements
|Sorfware   |   Version    
|:---        |   :---      
|Ubuntu Mate|   20.04  
|ROS        |   noetic     
|VS code    |
|STM32CUBEMX|
|Toolchain  | STM32CUBECLT 1.16.0
|Cmake      |
---
|Hardware   |   Version    
|:---        |   :---        
|Microchip  |   STM32F407VETx
|IMU        |   ICM20948
|RaspberryPi|   4B+    


## How to Use
First of all, you should add CANopenNode into RoverSoftware/USER/Libs/CanOpenSTM32
```
  git clone https://github.com/CANopenNode/CANopenNode.git
```
And then, return the RoverSoftware file and compile it by cmake. 

---
To run it, 
1. STM32 terminal connects Raspberry Pi with USART. After which, in Raspberry Pi, performing the following commands, 

2. change the access permission of the USART device,
    ```
    sudo chmod 777 /dev/ttyUSBx
3. start the rosserial node up,
    ```
    rosrun roscore
    rosrun rosserial_python serial_node.py _port:=/dev/ttyUSBx _baud:=115200
    ```
4. if start up sucessfully, run 
    ```
    rostopic list
    ``` 
---