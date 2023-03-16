/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Abdallah Ahmed Mohammed
 * @brief          : Main program body
 ******************************************************************************
 **/

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include "STM32F103C6.h"
#include "STM32F103C6_GPIO_Driver.h"
#include "STM32F103C6_EXTRI_Driver.h"
#include "lcd.h"
#include "Kaypad.h"
#include "Seven_Segment.h"

typedef enum
{
	Privileged,
	UnPrivileged
}Access_Level;

void Switch_Privileged_UnPrivileged(Access_Level Level)
{
	switch(Level)
	{
	case Privileged:
		__asm("mrs r3,CONTROL \n\t"
				"lsr r3,r3,#0x1 \n\t"
				"lsl r3,r3,#0x1 \n\t"
				"msr CONTROL,r3");
		break;
	case UnPrivileged :
		__asm("mrs r3,CONTROL \n\t"
				"orr r3,r3,#0x1 \n\t"
				"msr CONTROL,r3");
		break;

	}
}

void clock_init()
{
	// Enable clock GPIOA
	RCC_GPIOA_CLK_EN();
	// Enable clock GPIOB
	RCC_GPIOB_CLK_EN();
	// Enable clock AFIO
	RCC_AFIO_CLK_EN();
}
unsigned int flag =0;

void Reset_Handler()
{

}
void NMI_Handler()
{

}

void HardFault_Handler()
{

}
void MemManage_Handler()
{

}
void BusFault_Handler()
{

}
void UsageFault_Handler()
{

}


void EXTRIB09_CallBack(void)
{
	flag =1;
	Switch_Privileged_UnPrivileged(Privileged);

}
int main(void)
{
	clock_init();

	Switch_Privileged_UnPrivileged(UnPrivileged);

	EXTRI_PinConfig_t PinConfig;
	PinConfig.PIN_INPUT = EXTRI9PB9;
	PinConfig.EXTRI_Trigger_Case=EXTRI_Trigger_Rising;
	PinConfig.P_IRQ_CallBack=EXTRIB09_CallBack;
	PinConfig.IRQ_ENABLE=EXTRI_IRQ_Enable;
	MCAL_EXTRI_GPIO_INIT(&PinConfig);

	flag=1;




	while (1)
	{
		if (flag)
		{
			flag =0;
		}
	}

}

