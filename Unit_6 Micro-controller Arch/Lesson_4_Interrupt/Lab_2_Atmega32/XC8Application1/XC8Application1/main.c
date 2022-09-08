/*
==================================================================================
*@ File  : main.c
*@ Date  : Created: 9/8/2022 2:33:54 AM
*@ Author: Abdallah Ahmed Mohammed
==================================================================================
 */ 


/*
==================================================================================
External Interrupt 0 (INT0)-PD2. >> irqoccur when “any logical change”
External Interrupt 1 (INT1)-PD3. >> irqoccur when “rising edge”
External Interrupt 2 (INT2)-PB2. >> irqoccur when “Falling edge”
==================================================================================
*/

#define F_CPU 1000000ul
#include "util/delay.h"
#include <avr/io.h>
#include <avr/interrupt.h>

#define IO_BASE 0x20


typedef union 
{
	uint8_t all_port;
	struct 
	{
		uint8_t Pin0:1;
		uint8_t Pin1:1;
		uint8_t Pin2:1;
		uint8_t Pin3:1;
		uint8_t Pin4:1;
		uint8_t Pin5:1;
		uint8_t Pin6:1;
		uint8_t Pin7:1;
		}PIN;
}atmega32_t;

volatile atmega32_t *PMCUCR  = (volatile atmega32_t *)(IO_BASE+0x35);
volatile atmega32_t *PMCUCSR = (volatile atmega32_t *)(IO_BASE+0x34);
volatile atmega32_t *PGICR   = (volatile atmega32_t *)(IO_BASE+0x3B);
volatile atmega32_t *PGIFR   = (volatile atmega32_t *)(IO_BASE+0x3A);
volatile atmega32_t *PSREG   = (volatile atmega32_t *)(IO_BASE+0x3F);
volatile atmega32_t *PPORTD  = (volatile atmega32_t *)(IO_BASE+0x12);
volatile atmega32_t *PDDRD   = (volatile atmega32_t *)(IO_BASE+0x11);


int main(void)
{
	// Set pin 5,6,7 as an output in PORTD
	PDDRD->PIN.Pin5=1;
	PDDRD->PIN.Pin6=1;
	PDDRD->PIN.Pin7=1;

	
	// External Interrupt 0 (INT0)-PD2. >> irqoccur when “any logical change”
	PMCUCR->PIN.Pin0=1;
	PMCUCR->PIN.Pin1=0;
	
    //External Interrupt 1 (INT1)-PD3. >> irqoccur when “rising edge”
	PMCUCR->PIN.Pin2=1;
	PMCUCR->PIN.Pin3=1;
	
	//External Interrupt 2 (INT2)-PB2. >> irqoccur when “Falling edge”
	PMCUCSR->PIN.Pin6=0;
	
   // Enable INT0 , INT1 , INT2
	PGICR->PIN.Pin5=1;
	PGICR->PIN.Pin6=1;
	PGICR->PIN.Pin7=1;
	
	// Enable Global interrupt
	sei();
	//PSREG->PIN.Pin7=1; 
	// we can also enable global interrupt by using function sei();
	// sei(); --> to set 
	// cli(); --> to clear 
	


    while(1)
    {
		// Reset all LEd 
		PPORTD->PIN.Pin5=0;
		PPORTD->PIN.Pin6=0;
		PPORTD->PIN.Pin7=0;
    }
}
ISR(INT0_vect)
{
	PPORTD->PIN.Pin5=1;
	_delay_ms(1000);
}
ISR(INT1_vect)
{
	PPORTD->PIN.Pin6=1;
	_delay_ms(1000);

}
ISR(INT2_vect)
{
	PPORTD->PIN.Pin7=1;
	_delay_ms(1000);
}