/*
 * 001LedToggle.c
 *
 *  Created on: 01-Oct-2020
 *      Author: Training
 */

#include "stm32hxx.h"
#include "stm32.h"
void delay(void);

int main(void)
{

   GPIO_Handle_t GPIOLed;
   GPIOLed.pGPIOx = GPIOD;
   GPIOLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_Pin_No_12;
   GPIOLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
   GPIOLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_HIGH;
   GPIOLed.GPIO_PinConfig.GPIO_PinOPtype = GPIO_OP_TYPE_PP;
   GPIOLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
   GPIO_PeriClkCntrl(GPIOLed,ENABLE);
   GPIO_Init(&GPIOLed);
   while(1)
   {
	   GPIO_ToggleOutputPin(GPIOLed,GPIO_Pin_No_12);
	   delay();
   }

   return 0;

}


void delay(void)
{
	for(uint32_t i = 0; i<=50000; i++);

}
