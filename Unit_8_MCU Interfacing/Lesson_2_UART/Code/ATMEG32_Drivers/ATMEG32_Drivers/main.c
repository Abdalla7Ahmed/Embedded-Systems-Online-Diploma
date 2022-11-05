/*
 * ATMEG32_Drivers.c
 *
 * Created: 24/09/2022 11:06:07 AM
 * Author : Abdallah Ahmed Mohammed
 */ 


#include "HAL/lcd.h"
#include "MCAL/UART.h"


int main(void)
{
	uint8_t Received_data;
	LCD_INIT();
	UART_INIT();
	LCD_GOTO_XY(0,0);
	LCD_WRITE_CHAR('A');
	UART_SEND_BYTE('A');
	UART_SEND_BYTE('b');
    while (1) 
    {
		LCD_GOTO_XY(1,0);
		Received_data=UART_RECIVE_BYTE();
		LCD_WRITE_CHAR(Received_data);
    }
}

