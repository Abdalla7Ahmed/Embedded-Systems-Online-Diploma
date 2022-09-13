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

void PORTD_init()
{
		// set IODD pin 0,1,2 as an input
		CLEARBIT(DDRD,0);
		CLEARBIT(DDRD,1);
		CLEARBIT(DDRD,2);
		
		// set IODD pin 4,5,6,7 as an Output
		SETBIT(DDRD,4);
		SETBIT(DDRD,5);
		SETBIT(DDRD,6);
		SETBIT(DDRD,7);
}
int main(void)
{
    PORTD_init();
	uint32_t flag=0;
	while (1)
	{
		if (READBIT(PIND,0)==1)
		{
			if (flag==1)
			{
       			SETBIT(PORTD,5);
				_delay_ms(5000);
				while(READBIT(PIND,0)==1);
			}
			else if(flag==2)
			{
				SETBIT(PORTD,6);
				_delay_ms(5000);
				while(READBIT(PIND,0)==1);
			}
		    else if(flag==3)
			{
				SETBIT(PORTD,7);
				_delay_ms(5000);
				while(READBIT(PIND,0)==1);
			}
		    else if(flag==4)
		    {
			    SETBIT(PORTD,4);
				_delay_ms(5000);
				while(READBIT(PIND,0)==1);
		    }
			else if (flag==5)
			{
				CLEARBIT(PORTD,4);
				CLEARBIT(PORTD,7);
				CLEARBIT(PORTD,6);
				CLEARBIT(PORTD,5);
				while(READBIT(PIND,0)==1);
			}
			else 
			{
				flag=0;
				while(READBIT(PIND,0)==1);
			}
		}
		else
		{
			flag++;
			while(READBIT(PIND,0)==0);
		}
	}

}

