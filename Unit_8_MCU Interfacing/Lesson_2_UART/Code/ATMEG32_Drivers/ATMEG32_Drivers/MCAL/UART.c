/*
 * UART.c
 *
 * Created: 24/09/2022 11:12:32 ص
 *  Author: Abotaleb
 */ 

#include "UART.h"	
#include "../SERVICES/Bit_Configuration.h"

void UART_INIT(void)
{
	// Error .2% with Baud rate  9600
	UBRRL=51;
	// normal speed  divided by 16 
	CLEARBIT(UCSRA,U2X);   // by default equal 0
	
	
	
	/*===============frame================*/ 
	// Select Asynchronous mode
	//CLEARBIT(UCSRC,UMSEL); // by default equal 0
	// Parity     // Disable the parity 
	//CLEARBIT(UCSRC,UPM0); // by default equal 0
	//CLEARBIT(UCSRC,UPM1); // by default equal 0
	// one bit for stop  
	//CLEARBIT(UCSRC,USBS); // by default equal 0
	// send 8 effective bits  
	//SETBIT(UCSRC,UCSZ0); // by default equal 1
	//SETBIT(UCSRC,UCSZ1); // by default equal 1
	//CLEARBIT(UCSRB,UCSZ2); // by default equal 0
	
	/*===============Enable================*/
	//Enable Transmit
	SETBIT(UCSRB,TXEN);
	// Enable Receive
	SETBIT(UCSRB,RXEN);
	 
	
}
void UART_SEND_BYTE(uint8_t data)
{
	while (READBIT(UCSRA,UDRE)==0); // check if the buffer is empty or not 
	UDR=data;
	
}
uint8_t UART_RECIVE_BYTE(void)
{
	while(READBIT(UCSRA,RXC)==0);
	//uint8_t data=UDR;
	return UDR;
	
}