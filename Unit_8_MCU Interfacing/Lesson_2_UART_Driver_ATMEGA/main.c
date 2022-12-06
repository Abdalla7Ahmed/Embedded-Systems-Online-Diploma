/*
 * ATMEG32_Drivers.c
 *
 * Created: 24/09/2022 11:06:07 AM
 * Author : Abdallah Ahmed Mohammed
 */ 


#include "HAL/lcd.h"
#include "MCAL/UART.h"
#include "MCAL/DIO.h"
#include "SERVICES/Bit_Configuration.h"
#include "SERVICES/MemoryMap.h"
#include "MCAL/SPI.h"

int main(void)
{
	LCD_INIT();
	_MCAL_UART_init();
	uint8_t receive_string[20];
	uint32_t receive_number[20];
	uint8_t Z=0,counter=0;
	long long send_number=1212354654;
	 /*============ send string ============*/
	//uint8_t *string="Abdallah Ahmed ";
	//_MCAL_UART_send_string(string);
	
	/*============ send number ============*/
	//_MCAL_UART_send_number(send_number);
	
	
	LCD_WRITE_STRING("UART send ");
 	LCD_GOTO_XY(1,0);
	LCD_WRITE_STRING("CPU Count ");	
	while (1)
	{
		/*============ receive string ============*/
		//_MCAL_UART_receive_string(receive_string);
		//LCD_WRITE_STRING(receive_string);
		
		/*============ receive number ============*/
		//_MCAL_UART_receive_number(receive_number);
		//LCD_WRITE_STRING(receive_number);
		
		
		/*the problem is when we send from UART to LCD the processor will wait
		until you write again (the CPU will stuck in this loop while(READBIT(UCSRA,RXC)==0))
		and will not do anything else 
		the solution --> we will use 1-the periodic check(polling)  2- interrupt 
		the idea here we will check if the UART send any thing or not 
		if UART send we will store the data in the buffer else will out of the function 
		and not stuck  */
		
		// we will make a counter from 0 to 9 and we will check if UART send or not 
		if (Receive_periodic_check(&Z))
		{
			LCD_GOTO_XY(0,12);
			LCD_Send_A_Character(Z);
		}
		LCD_GOTO_XY(1,12);
		LCD_display_number(counter++);
		if(counter == 9)   counter =0;
		_delay_ms(3000);
	
		/* we also have problem here !!!!
		when we send to fast the Data overrun will happen 
		the CPU will not read this data because we send new data over the old one
		and the CPU will read the last data (new) */  	
		// the solution is the interrupt 
	}
}


