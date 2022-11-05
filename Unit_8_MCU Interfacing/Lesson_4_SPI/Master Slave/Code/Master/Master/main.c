/*
 * Master.c
 *
 * Created: 29/10/2022 04:02:37 م
 * Author : Abotaleb
 */ 

#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>

#define SS				4
#define MOSI			5
#define MISO			6
#define CLK				7
#define M_S_Control		DDRB
#define Data_CTRL		DDRA
#define Data_PORT       PORTA

void MASTER_INIT(void)
{
	// Set SS , MOSI , SCL as output
	M_S_Control |=(1<<SS) | (1<<MOSI) |(1<<CLK) ;
	// Set MISO as input
	M_S_Control &=~(1<<MISO);
	
	SPCR |=1<<SPE;    // Enable SPI
	SPCR |=1<<MSTR;   // Enable Master
	SPCR |=1<<SPR0;   // Set clock rate focs/16	
}

uint8_t SPI_MasterTransmit(uint8_t data)
{
	/* Start transmission */
	SPDR = data;
	/* Wait for transmission complete */
	while(!(SPSR & (1<<SPIF)));
	return SPDR;
}



int main(void)
{
	// Set PORTA as an output
	Data_CTRL =0xFF;
	MASTER_INIT();
	int32_t counter=0;
    while (counter<=255) 
    {
		_delay_ms(1000);
		PORTA=SPI_MasterTransmit(counter++);
    }
}

