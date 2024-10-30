#ifndef __LED_H__
#define __LED_H__


#include "main.h"
#include "gpio.h"

class GPIOClass{
	private:
		uint16_t pin;
		GPIO_TypeDef* port;
	
	public:
		GPIOClass(GPIO_TypeDef* port, uint16_t pin);
		~GPIOClass();
	
		void high(){HAL_GPIO_WritePin(this->port, this->pin, GPIO_PIN_SET);}
		void low(){HAL_GPIO_WritePin(this->port, this->pin, GPIO_PIN_RESET);}
		void toggle(){HAL_GPIO_TogglePin(this->port, this->pin);}
		
		GPIO_TypeDef* get_port(){return this->port;}
		uint16_t get_pin(){return this->pin;}
	
};


class LEDClass : public GPIOClass{
	private:
		
	public:
		using GPIOClass::GPIOClass;
		
		void flashing( void(*delay)(uint32_t), uint16_t duration, uint8_t times){
			this->off();
			while(times--){
				this->on();
				delay(duration/2);
				this->off();
				delay(duration/2);
			}
		}
		void breathing();
	
		void on(){this->low();}
		void off(){this->high();}
};

GPIOClass::GPIOClass(GPIO_TypeDef* port, uint16_t pin)
{
	this->port = port;
	this->pin = pin;
}

GPIOClass::~GPIOClass()
{

}

#endif