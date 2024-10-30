#ifndef ROS_STM32HARDWARE_H_
#define ROS_STM32HARDWARE_H_


#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_uart.h"


extern UART_HandleTypeDef huart1;

class STM32Hardware {
  protected:
    UART_HandleTypeDef *huart;

    const static uint16_t rbuflen = 512;
    uint8_t rbuf[rbuflen];
    uint32_t rind;
    inline uint32_t getRdmaInd(void){ return (rbuflen - __HAL_DMA_GET_COUNTER(huart->hdmarx)) & (rbuflen - 1); }

    const static uint16_t tbuflen = 512;
    uint8_t tbuf[tbuflen];
    uint32_t twind, tfind;

  public:
    STM32Hardware():
      huart(&huart1), rind(0), twind(0), tfind(0){
    }

    STM32Hardware(UART_HandleTypeDef *huart_):
      huart(huart_), rind(0), twind(0), tfind(0){
    }
  
    void init(){
      reset_rbuf();
    }

    void reset_rbuf(void){
      HAL_UART_Receive_DMA(huart, rbuf, rbuflen);
    }

    int read(){
      int c = -1;
      if(rind != getRdmaInd()){
        c = rbuf[rind++];
        rind &= rbuflen - 1;
      }
      return c;
    }

    void flush(void){
      static bool mutex = false;

      if((huart->gState == HAL_UART_STATE_READY) && !mutex){
        mutex = true;

        if(twind != tfind){
          uint16_t len = tfind < twind ? twind - tfind : tbuflen - tfind;
          HAL_UART_Transmit_DMA(huart, &(tbuf[tfind]), len);
          tfind = (tfind + len) & (tbuflen - 1);
        }
        mutex = false;
      }
    }

    void write(uint8_t* data, int length){
      int n = length;
      n = n <= tbuflen ? n : tbuflen;

      int n_tail = n <= tbuflen - twind ? n : tbuflen - twind;
      memcpy(&(tbuf[twind]), data, n_tail);
      twind = (twind + n) & (tbuflen - 1);

      if(n != n_tail){
        memcpy(tbuf, &(data[n_tail]), n - n_tail);
      }

      flush();
    }

    unsigned long time(){ return HAL_GetTick();; }

  protected:
};

#endif