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



#define SETBIT(register,bit)     (register |= (1<<bit))

#define CLEARBIT(register,bit)   (register &= ~(1<<bit))

#define TOGGLEBIT(register,bit)  (register ^= (1<<bit))

#define READBIT(register,bit)    ((register>>bit)&1)


int main(void)
{
		SETBIT(DDRD,4);
		SETBIT(DDRD,5);
		SETBIT(DDRD,6);
		SETBIT(DDRD,7);	
		uint32_t counter ;
	while (1)
	{
		for (counter=7;counter>=4;counter--)
		{
			SETBIT(PORTD,counter);
			_delay_ms(5000);
			CLEARBIT(PORTD,counter);
		}

	}

}

