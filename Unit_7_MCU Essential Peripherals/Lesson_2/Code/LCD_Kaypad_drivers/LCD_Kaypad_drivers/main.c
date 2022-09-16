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
	char Pressed_Kay;
	int flag=0;
	unsigned short number,counter=0;
	int temp1,temp2;
	char Operation;
	double calc;

	while (1)
	{
		Pressed_Kay=GET_CHARACTER();

		if (Pressed_Kay >= '0' && Pressed_Kay <='9')
		{
			LCD_WRITE_CHAR(Pressed_Kay);
			number = Pressed_Kay - '0';
			counter++;
			switch(counter)
			{
			case 1 :
				temp1= number;
				break;
			case 2:
				temp1=temp1*10 + number;
				break;
			case 3 :
				temp1=temp1*100+number;
				break;
			case 4 :
				temp1=temp1*1000+number;
				break;
			case 5 :
				temp1=temp1*10000+number;
				break;
			}
		}

		switch(Pressed_Kay)
		{
		case '*':
			LCD_WRITE_CHAR(Pressed_Kay);
			counter=0;
			temp2 =temp1;
			Operation = Pressed_Kay;
			break;
		case '+':
			LCD_WRITE_CHAR(Pressed_Kay);
			counter=0;
			temp2 =temp1;
			Operation = Pressed_Kay;
			break;
		case '-':
			LCD_WRITE_CHAR(Pressed_Kay);
			counter=0;
			temp2 =temp1;
			Operation = Pressed_Kay;
			break;
		case '/':
			LCD_WRITE_CHAR(Pressed_Kay);
			counter=0;
			temp2 =temp1;
			Operation = Pressed_Kay;
			break;
		case '=':
			LCD_WRITE_CHAR(Pressed_Kay);
			counter = 0;
			if (Operation=='*')	calc=temp1*temp2;
			else if (Operation == '+') calc=temp1+temp2;
			else if (Operation == '-') calc = temp2-temp1;
			else if (Operation == '/') calc = temp2 / temp1;
			if (Operation == '/' && temp1 ==0)
			{
				LCD_GOTO_XY(2,0);
				LCD_WRITE_STRING("ERROR");
			}
			else
			{
				LCD_GOTO_XY(2,0);
				LCD_DISPLAY_REAL_NUMBER(calc);
			}
			break;
		case 'C':
			counter = 0;
			LCD_clear_screen();
			break;
		}

	}

}

