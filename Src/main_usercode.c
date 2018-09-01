#include "main.h"
#include "stm32f4xx_hal.h"
#include <string.h>
#include <stdio.h>
#include "uart.h"


extern UART_HandleTypeDef huart1; /*declared in main.c*/

void main_usercode()
{
  static unsigned int loc_time = 0;
  static char loc_buff[200];

  HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_5);
  HAL_Delay(300);
  loc_time++;

 
  if(loc_time == 1)
  {
    uart_PrintfBuildVersion(&huart1);
  }
  else
  {
    /*nothing to do*/
  }

  sprintf(loc_buff,"time=%d\n\r",loc_time);
  uart_Printf(&huart1,loc_buff);
	
  return;
}
