/*
 * SPI_Driver_Master.c
 *
 * Created: 31/10/2022 01:21:47 م
 * Author : Abotaleb
 */ 

#include <avr/io.h>
#define F_CPU 1000000UL
#include<avr/io.h>
#include<util/delay.h>

#include "HAL/LCD_Driver/LCD_Driver.h"
#include "MCAL/SPI_Driver/SPI_Driver.h"

int main(void)
{
	LCD_INIT();
	SPI_INIT();
	uint8_t data='a',received_data,counter=0;
	
	LCD_WRITE_STRING("Slave ");
    while (1) 
    {
		received_data=SPI_SendReceive(data);
		data++;
		if (data =='z'+1) data='a';
		LCD_GOTO_XY(2,0);
		LCD_WRITE_CHAR(received_data);
		LCD_GOTO_XY(1,9);
		LCD_DISPLAY_NUMBER(counter);	
		_delay_ms(1000);
		counter++;
		if(counter == 10)   counter=0;
    }
}

