/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Abdallah Ahmed Mohammed
 * @brief          : Main program body
 * @LAb            : 1
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include "STM32F103C6.h"
#include "STM32F103C6_Driver.h"


void clock_init()
{
	// Enable clock GPIOA
	RCC_GPIOA_CLC_EN();
	// Enable clock GPIOB
	RCC_GPIOB_CLK_EN();
}

void GPIOA_init()
{
	GPIO_PinConfig_t GPIOAConfig;
	GPIOAConfig.GPIO_PinNumber=GPIO_PINS_1;
	GPIOAConfig.GPIO_MODE=GPIO_MODE_FLOATINg_INPUT;
	MCAL_GPIO_INIT(GPIOA, &GPIOAConfig);

	GPIOAConfig.GPIO_PinNumber=GPIO_PINS_13;
	GPIOAConfig.GPIO_MODE=GPIO_MODE_FLOATINg_INPUT;
	MCAL_GPIO_INIT(GPIOA, &GPIOAConfig);

}

void GPIOB_init()
{
	GPIO_PinConfig_t GPIOBConfig;
	GPIOBConfig.GPIO_PinNumber=GPIO_PINS_1;
	GPIOBConfig.GPIO_MODE=GPIO_MODE_OUTPUT_PP;
	GPIOBConfig.GPIO_OUTPUT_SPEED=GPIO_OUTPUT_SPEED_10M;
	MCAL_GPIO_INIT(GPIOB,&GPIOBConfig);

	GPIOBConfig.GPIO_PinNumber=GPIO_PINS_13;
	GPIOBConfig.GPIO_MODE=GPIO_MODE_OUTPUT_PP;
	GPIOBConfig.GPIO_OUTPUT_SPEED=GPIO_OUTPUT_SPEED_10M;
	MCAL_GPIO_INIT(GPIOB,&GPIOBConfig);
}

void delay(uint32_t time)
{
	uint32_t i,j;
	for(i=0;i<time;i++)
	{
		for (j = 0; j < 255;j++) ;
	}
}

int main(void)
{
	// clock Enable PORTA and PORTB
	clock_init();
	// Set GPIOA as an input
	GPIOA_init();
	// Set GPIOB as an output
	GPIOB_init();

	while(1)
	{
		if (MCAL_GPIO_READ_PIN(GPIOA,GPIO_PINS_1)==0)
		{
			// Toggle LED

			MCAL_GPIO_TOGGLE_PIN(GPIOB, GPIO_PINS_1);
			while (MCAL_GPIO_READ_PIN(GPIOA,GPIO_PINS_1)==0); //single press
		}
		if (MCAL_GPIO_READ_PIN(GPIOA,GPIO_PINS_13)==1)
		{
			// Toggle LED
			MCAL_GPIO_TOGGLE_PIN(GPIOB, GPIO_PINS_13);
			// multi press
		}
		delay(1);
	}
}

