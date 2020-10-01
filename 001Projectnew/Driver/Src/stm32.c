/*
 * stm32f07xx_gpio_driver.c
 *
 *  Created on: 30-Sep-2020
 *      Author: Training
 */
#include "stm32.h"
#include "stm32hxx.h"

/*@read discription
 *
 *
 *
 *
 *@function
 *
 *
 *
 *
 *@Param1-
 *
 *
 *
 *@Param2-
 *
 *
 *
 *@Param3-
 *
 *
 *
 *@Definition
 *
 *
 *@Design by -
 *
 *
 *
 *@dATE and time
 *
 *
 *
 *
 *
 */
void GPIO_PeriClkCntrl(GPIO_REGDEF_t *pGPIOx, uint8_t EnorDi)
{
if(EnorDi == ENABLE)
{
if(pGPIOx == GPIOA)
{
GPIOA_PCLK_EN();
}
else if(pGPIOx==GPIOB)
{
GPIOB_PCLK_EN();
}
else if(pGPIOx==GPIOC)
{
GPIOC_PCLK_EN();
}
else if(pGPIOx==GPIOD)
{
GPIOD_PCLK_EN();
}
else if(pGPIOx==GPIOE)
{
GPIOE_PCLK_EN();
}
else if(pGPIOx==GPIOF)
{
GPIOF_PCLK_EN();
}
else if(pGPIOx==GPIOG)
{
GPIOG_PCLK_EN();
}
else if(pGPIOx==GPIOH)
{
GPIOH_PCLK_EN();
}
else if(pGPIOx==GPIOI)
{
GPIOI_PCLK_EN();
}
}
else
{
if(pGPIOx == GPIOA)
{
GPIOA_PCLK_DI();
}
else if(pGPIOx==GPIOB)
{
GPIOB_PCLK_DI();
}
else if(pGPIOx==GPIOC)
{
GPIOC_PCLK_DI();
}
else if(pGPIOx==GPIOD)
{
GPIOD_PCLK_DI();
}
else if(pGPIOx==GPIOE)
{
GPIOE_PCLK_DI();
}
else if(pGPIOx==GPIOF)
{
GPIOF_PCLK_DI();
}
else if(pGPIOx==GPIOG)
{
GPIOG_PCLK_DI();
}
else if(pGPIOx==GPIOH)
{
GPIOH_PCLK_DI();
}
else if(pGPIOx==GPIOI)
{
GPIOI_PCLK_DI();
}
}

}

void GPIO_Init(GPIO_Handle_t *GPIOHandle)
{


// Intialise Mode
uint32_t temp=0;
temp = (GPIOHandle->GPIO_PinConfig.GPIO_PinMode << (2*GPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
GPIOHandle->pGPIOx-> MODER &=~(0X3<<GPIOHandle ->GPIO_PinConfig.GPIO_PinNumber );
GPIOHandle->pGPIOx-> MODER |= temp;



// Configure speed
temp=0;
temp =(GPIOHandle->GPIO_PinConfig.GPIO_PinSpeed << (2*GPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
GPIOHandle->pGPIOx-> OSPEEDR &=~(0X3<<GPIOHandle ->GPIO_PinConfig.GPIO_PinNumber );
GPIOHandle->pGPIOx-> OSPEEDR |= temp;
//Configure Pull up or pull down
temp=0;
temp =(GPIOHandle->GPIO_PinConfig.GPIO_PinPuPdControl << (2*GPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
GPIOHandle->pGPIOx-> PUPDR &=~(0X3<<GPIOHandle ->GPIO_PinConfig.GPIO_PinNumber );
GPIOHandle->pGPIOx-> PUPDR |= temp;

// configure output type

temp=0;
temp =(GPIOHandle->GPIO_PinConfig.GPIO_PinOPtype << (2*GPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
GPIOHandle->pGPIOx-> OTYPER &=~(0X3<<GPIOHandle ->GPIO_PinConfig.GPIO_PinNumber );
GPIOHandle->pGPIOx-> OTYPER |= temp;

// Configure alternating function

temp=0;
uint8_t temp1 =0 , temp2 = 0;
if(GPIOHandle->GPIO_PinConfig.GPIO_PinMode==GPIO_MODE_AFN)
{

temp1 = (GPIOHandle -> GPIO_PinConfig.GPIO_PinNumber)/8;
temp2 = (GPIOHandle -> GPIO_PinConfig.GPIO_PinNumber)%8;
GPIOHandle->pGPIOx->AFR[temp1] &= ~ (0XF<<temp2);
GPIOHandle->pGPIOx->AFR[temp1] = (GPIOHandle->GPIO_PinConfig.GPIO_PinAltFunMode<<(4*temp2));

}
}

void GPIO_DInit(GPIO_REGDEF_t *pGPIOx)
{
	if(pGPIOx==GPIOA)
	{

		GPIOA_REG_RESET();

	}
	if(pGPIOx==GPIOB)
		{

			GPIOB_REG_RESET();

		}
	if(pGPIOx==GPIOC)
		{

			GPIOC_REG_RESET();

		}
	if(pGPIOx==GPIOD)
		{

			GPIOD_REG_RESET();

		}
	if(pGPIOx==GPIOE)
		{

			GPIOE_REG_RESET();

		}
	if(pGPIOx==GPIOF)
		{

			GPIOF_REG_RESET();

		}
	if(pGPIOx==GPIOG)
		{

			GPIOG_REG_RESET();

		}
	if(pGPIOx==GPIOH)
		{

			GPIOH_REG_RESET();

		}
	if(pGPIOx==GPIOI)
		{

			GPIOI_REG_RESET();

		}

}



uint8_t GPIO_ReadFromInputPin(GPIO_REGDEF_t *pGPIOx, uint8_t PinNo)
 {


   uint8_t val = 0;
   val = (uint8_t)(pGPIOx-> IDR>>PinNo)&(0x00000001);
   return val;

  }

uint16_t GPIO_ReadFromInputPort(GPIO_REGDEF_t *pGPIOx)
 {

  uint16_t val = 0;
  val = (uint16_t)(pGPIOx->IDR);
  return val;

  }

void GPIO_WriteToOutputPin(GPIO_REGDEF_t *pGPIOx, uint8_t PinNo, uint8_t value)
{

   if (value ==GPIO_Pin_Set)
   {
	   pGPIOx->ODR |=(1<<PinNo);

   }
   else
   {
	   pGPIOx->ODR &=~(1<<PinNo);
   }

}

void GPIO_WriteToOutputPort(GPIO_REGDEF_t *pGPIOx, uint16_t value)
{


 pGPIOx -> ODR = value;


}

void GPIO_ToggleOutputPin(GPIO_REGDEF_t *pGPIOx, uint8_t PinNo)
{

 pGPIOx ->ODR ^=(1<<PinNo);

}
