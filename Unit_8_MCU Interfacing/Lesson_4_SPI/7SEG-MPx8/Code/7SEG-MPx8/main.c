/* ========================================================
 * 7SEG-MPX8.c
 * Created: 29/10/2022 08:33:41 م
 * Author : Abdallah Ahmed
 ========================================================*/ 


#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>

#define Chip_select			4
#define MOSI				5
#define CLK					7
#define Master_Control		DDRB


void SPI_MasterInit(void)
{
	// Set SS , MOSI , SCL as output
	Master_Control |=(1<<MOSI)|(1<<Chip_select) |(1<<CLK) ;
	// Set MISO as input
	
	SPCR |=1<<MSTR;   // Enable Master
	SPCR |=1<<SPE;    // Enable SPI
	SPCR |=1<<SPR0;   // Set clock rate focs/16
}

void execute(uint8_t CMD,uint8_t Data)
{
	//In MAX7221, data packets are 16 bits long (two bytes)
	//You should first make CS low before transmitting
	PORTB &=~(1<<Chip_select);
	//then you transmit two bytes of data
	// transmit command
	SPDR=CMD;
	// wait to complete the transmission
	while (!(SPSR & (1 << SPIF)));
	// transmit data
	SPDR =Data;
	// wait to complete the transmission
	while (!(SPSR & (1 << SPIF)));
	//terminate the transmission by making CS high.
	PORTB |=(1<<Chip_select);
}

void MAX7221_init(void)
{
	execute(0x09,0xFF);   // decode all display    
	execute(0x0A,0xFF);   // max intensity
	execute(0x0B,0xF7);   // set scan limit (digit0 to digit7)  on the screen  doing the all segments work 
	execute(0x0C,0x01);   // turn on display normal mood
}
int main(void)
{
	SPI_MasterInit();
	MAX7221_init();
	uint8_t counter=0;
	uint8_t index_display;
    while (1) 
    {
		for(index_display=1;index_display<9;index_display++)
			execute(index_display,counter++); // write on Led (index_display) value (counter)
		_delay_ms(1000);
    }
}

