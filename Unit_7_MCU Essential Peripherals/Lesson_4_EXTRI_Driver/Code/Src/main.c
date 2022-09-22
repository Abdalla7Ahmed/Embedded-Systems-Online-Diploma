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


void clock_init()
{
	// Enable clock GPIOA
	RCC_GPIOA_CLK_EN();
	// Enable clock GPIOB
	RCC_GPIOB_CLK_EN();
	// Enable clock AFIO
	RCC_AFIO_CLK_EN();
}
int flag =0;
void EXTRIB09_CallBack(void)
{
	flag =1;
	LCD_WRITE_STRING("IRQ EXTRI9 is happend -| ");
	Wait_m(1000);
	LCD_clear_screen();
}
int main(void)
{
	clock_init();
	LCD_INIT();
	LCD_clear_screen();
	EXTRI_PinConfig_t PinConfig;
	PinConfig.PIN_INPUT = EXTRI9PB9;
	PinConfig.EXTRI_Trigger_Case=EXTRI_Trigger_Failing;
	PinConfig.P_IRQ_CallBack=EXTRIB09_CallBack;
	PinConfig.IRQ_ENABLE=EXTRI_IRQ_Enable;
	MCAL_EXTRI_GPIO_INIT(&PinConfig);
	flag=1;
	while (1)
	{
		if (flag)
		{
			LCD_clear_screen();
			flag =0;
		}
	}

}

