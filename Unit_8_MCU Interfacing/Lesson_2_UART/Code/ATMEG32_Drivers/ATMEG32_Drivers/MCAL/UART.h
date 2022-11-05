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

void UART_INIT(void);
void UART_SEND_BYTE(uint8_t data);
uint8_t UART_RECIVE_BYTE(void);

#endif /* UART_H_ */