/*
 * LCD_Kaypad_drivers.c
 *
 * Created: 13/09/2022 05:24:07 ص
 * Author : Abotaleb
 */

#include <avr/io.h>
#include "LCD_driver/LCD.h"
#include "Kaypad_driver/Kaypad.h"
int main(void)
{
	LCD_INIT();
	KAYPAD_INIT();
	char Pressed_kay;

	while (1)
	{
			//LCD_WRITE_STRING("Abdallah Ahmed ");
			//_delay_ms(300);
			//LCD_clear_screen();
			//LCD_WRITE_STRING("Embedded Systems Engineer");
			//LCD_clear_screen();
			//_delay_ms(300);
			//LCD_WRITE_STRING("Age : ");
			//LCD_DISPLAY_NUMBER(22);
			//_delay_ms(300);
			//LCD_clear_screen();
			//LCD_WRITE_STRING("third year ");
			//_delay_ms(300);
			//LCD_clear_screen();
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

