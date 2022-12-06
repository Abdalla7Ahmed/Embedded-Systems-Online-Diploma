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
#define SCK				7
#define M_S_Control		DDRB
#define Data_CTRL		DDRA
#define Data_PORT       PORTA

void SPI_Slave_INIT(void)
{
	// Set MISO output 
	M_S_Control |=(1<<MISO);
	// Set MOSI as input
	M_S_Control &=~(1<<MOSI) & ~(1<<SCK) & ~(1<<SS);
	
	SPCR |=1<<SPE;    // Enable SPI
}

uint8_t SPI_Slave_Receive(uint8_t data)
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
	SPI_Slave_INIT();
	int32_t counter=255;
    while (counter>=0) 
    {
		_delay_ms(1000);
		PORTA=SPI_Slave_Receive(counter--);
    }
}

