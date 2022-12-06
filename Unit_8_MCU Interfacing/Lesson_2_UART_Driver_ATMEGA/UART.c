/*
 * UART.c
 *
 * Created: 24/09/2022 11:12:32 ص
 *  Author: Abotaleb
 */ 

#include "UART.h"	
#include "../SERVICES/Bit_Configuration.h"
static uint8_t *TX_str;
static uint8_t flag=1;
void _MCAL_UART_init(void)
{
	// Error .2% with Baud rate  9600
	UBRRL=51;
	//UBRRL =(uint8_t)(FinalUBRR);          // send the low 8 bits in register UBRRL
	//UBRRH =(uint8_t)(FinalUBRR >>8);	 // send the high 8 bits in register UBRRH
	
	
	
	// normal speed  divided by 16 
	CLEARBIT(UCSRA,U2X);   // by default equal 0
	
	
	
	/*===============frame================*/ 
	// Select Asynchronous mode
	CLEARBIT(UCSRC,UMSEL); // by default equal 0
	// Parity     // Disable the parity 
	CLEARBIT(UCSRC,UPM0); // by default equal 0
	CLEARBIT(UCSRC,UPM1); // by default equal 0
	// one bit for stop  
	CLEARBIT(UCSRC,USBS); // by default equal 0
	// send 8 effective data  
	SETBIT(UCSRC,UCSZ0); // by default equal 1
	SETBIT(UCSRC,UCSZ1); // by default equal 1
	CLEARBIT(UCSRB,UCSZ2); // by default equal 0
	
	/*===============Enable================*/
	//Enable Transmit
	SETBIT(UCSRB,TXEN);
	// Enable Receive
	SETBIT(UCSRB,RXEN);
}
void _MCAL_UART_send(uint8_t data)
{
	while (READBIT(UCSRA,UDRE)==0); // check if the buffer is empty or not 
	UDR=data;
}
uint8_t _MCAL_UART_receive(void)
{
	while(READBIT(UCSRA,RXC)==0);   // wait until receive is complete
	return UDR;	
}

void _MCAL_UART_send_string(uint8_t *string)
{
	uint8_t i=0;
	while(string[i] !=0)  _MCAL_UART_send(string[i++]);
}

void _MCAL_UART_receive_string(uint8_t *buffer)
{
	uint8_t i=0;
	buffer[i] = _MCAL_UART_receive();
	while(buffer[i] != defaultStop)
	{
		i++;
		buffer[i] = _MCAL_UART_receive();
	}
	buffer[i] ='\0';
}
void _MCAL_UART_receive_number(uint8_t *number)
{
	uint32_t counter=0;
	number[counter] = _MCAL_UART_receive();
	while(number[counter]!=defaultStop)
	{
		counter ++;
		number[counter] =_MCAL_UART_receive(); 
	}
	number[counter] = '\0';
}


void _MCAL_UART_send_number(long long number)
{
	uint8_t counter=0;
	uint8_t number_array[10];
	while(number != 0)
	{
		number_array[counter] = (number%10) +'0';
		number /=10;
		counter ++;
	}
	for(int i=counter-1;i>=0;i--)
	{
		_MCAL_UART_send(number_array[i]);
	}
	
}




uint8_t Receive_periodic_check(uint8_t *Pdata)
{
	if(READBIT(UCSRA,RXC)==1)   
	{
		*Pdata =UDR;
		return 1;
	} 
	return 0; 
	// after this function will out from it not run it again 
}




// internal APIS
/* there is a problem in interrupt */
void UART_sendNoBlock(uint8_t data)
{
	UDR=data;
}
uint8_t UART_ReceiveNoBlock()
{
	return UDR;
}
// enable transmission interrupt
void UART_TX_Interrupt_Enable(void)
{
	SETBIT(UCSRB,TXCIE);
}
// enable receiving interrupt
void UART_RX_Interrupt_Enable(void)
{
	SETBIT(UCSRB,RXCIE);
}
// disable transmission interrupt
void UART_TX_Interrupt_Disable(void)
{
	CLEARBIT(UCSRB,TXCIE);
}
// disable receiving interrupt
void UART_RX_Interrupt_Disable(void)
{
	CLEARBIT(UCSRB,RXCIE);
}

void UART_sendString_Asyn(uint8_t *str)
{
	if(flag ==1)
	{
		UART_TX_Interrupt_Enable();
		UART_sendNoBlock(str[0]);
		TX_str=str;
		flag =0;	
	}
}

// ISR(USART_RXC_vect)
// {
// 
// 	
// }
ISR(USART_TXC_vect)
{
	static uint8_t i=1;
	if(TX_str[i] !='\0')
	{
		UART_sendNoBlock(TX_str[i]);
		i++;
	}
	else 
	{
		i=1;
		flag =1;
	}

}
