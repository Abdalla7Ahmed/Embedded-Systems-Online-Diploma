/*
 * Assignment_1.c
 *
 * Created: 11/09/2022 05:23:31 ص
 * Author : Abotaleb
 */ 

#define F_CPU 1000000ul
#include "util/delay.h"
#include <avr/io.h>
#include <avr/interrupt.h>

#define SETBIT(register,bit)     (register |=(1<<bit))

#define CLEARBIT(register,bit)   (register &=~(1<<bit))

#define TOGGLEBIT(register,bit)  (register ^=(1<<bit))

#define READBIT(register,bit)    ((register>>bit)&1)



void PORTA_init()
{
		// set IODD pins in PORTD as an Output
		SETBIT(DDRA,0);
		SETBIT(DDRA,1);
		SETBIT(DDRA,2);
		SETBIT(DDRA,3);
		SETBIT(DDRA,4);
		SETBIT(DDRA,5);
		SETBIT(DDRA,6);
		SETBIT(DDRA,7);
}
int main(void)
{
    PORTA_init();

    while (1) 
    {
		SETBIT(PORTA,0);
		_delay_ms(100);
		SETBIT(PORTA,1);
		_delay_ms(100);
		SETBIT(PORTA,2);
		_delay_ms(100);
		SETBIT(PORTA,3);
		_delay_ms(100);
		SETBIT(PORTA,4);
		_delay_ms(100);
		SETBIT(PORTA,5);
		_delay_ms(100);
		SETBIT(PORTA,6);
		_delay_ms(100);
		SETBIT(PORTA,7);
		_delay_ms(500);

		CLEARBIT(PORTA,7);
		_delay_ms(100);
		CLEARBIT(PORTA,6);
		_delay_ms(100);
		CLEARBIT(PORTA,5);
		_delay_ms(100);
		CLEARBIT(PORTA,4);
		_delay_ms(100);
		CLEARBIT(PORTA,3);
		_delay_ms(100);
		CLEARBIT(PORTA,2);
		_delay_ms(100);
		CLEARBIT(PORTA,1);
		_delay_ms(100);
		CLEARBIT(PORTA,0);
		_delay_ms(500);
	}

}

