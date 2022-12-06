/*
 * UART.h
 *
 * Created: 24/09/2022 11:12:43 ص
 *  Author: Abotaleb
 */ 


#ifndef UART_H_
#define UART_H_
#include <avr/io.h>
#define F_CPU 1000000UL
#include<avr/io.h>
#include<util/delay.h>

#define FOSC  4000000       // clock speed
#define BAUD  9600
#define FinalUBRR		((FOSC /(16*BAUD)) -1)

#define defaultStop   '\r'   // ASCII code of Enter 

void _MCAL_UART_init(void);
void _MCAL_UART_send(uint8_t data);
uint8_t _MCAL_UART_receive(void);
void _MCAL_UART_send_string(uint8_t *string);
void _MCAL_UART_receive_string(uint8_t *buffer);
void _MCAL_UART_send_number(long long number);
void _MCAL_UART_receive_number(uint8_t *number);
uint8_t Receive_periodic_check(uint8_t *Pdata);





// search on synchronous and asynchronous function 
//synchronous function --> function do specific porpose and return somthimg
//asynchronous function --> function do  specific porpose in background like interrupt  
//asynchronous function --> doesn't enclude while or for loop
#endif /* UART_H_ */