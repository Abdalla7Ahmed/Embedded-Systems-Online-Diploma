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
#include "STM32F103C6_Driver.h"
#include "lcd.h"
#include "Kaypad.h"
#include "Seven_Segment.h"


void clock_init()
{
	// Enable clock GPIOA
	RCC_GPIOA_CLC_EN();
	// Enable clock GPIOB
	RCC_GPIOB_CLK_EN();
}


void Main_SetUP()
{
	clock_init();
	LCD_INIT();
	Seven_Segment_Init();
	uint32_t count;
	unsigned char LCD_DISPLAY [11] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
	unsigned char Seven_Segment_DISPLAY [11] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, ZERO};
	for(count=0;count<11;count++)
	{
		LCD_WRITE_CHAR(LCD_DISPLAY[count]);
		MCAL_GPIO_WRITE_PORT(Seven_segment_Port,Seven_Segment_DISPLAY[count] << 9);
		Wait_m(500);
	}
	LCD_clear_screen();
	LCD_WRITE_STRING("KeyPad is ready");
	Wait_m(1000);
	LCD_clear_screen();
}

int main(void)
{
	Main_SetUP();

	KAYPAD_INIT();
	uint8_t Pressed_kay;
	while(1)
	{
		Pressed_kay =GET_CHARACTER();
		switch(Pressed_kay)
		{
		case 'C':
			LCD_clear_screen();
			break;
		case 'N' :
			break;
		default:
			LCD_WRITE_CHAR(Pressed_kay);
			break;
		}

	}
}

