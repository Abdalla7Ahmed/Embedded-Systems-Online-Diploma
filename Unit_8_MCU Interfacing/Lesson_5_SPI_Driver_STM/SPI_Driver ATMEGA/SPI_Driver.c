/*
 * SPI_Driver.c
 *
 * Created: 31/10/2022 12:13:28 م
 *  Author: Abotaleb
 */ 

#include "SPI_Driver.h"
void SPI_INIT()
{
	#if (Mode_S == Master)
	// Set SS , MOSI , SCL as output
	SETBIT(M_S_Control,SS);
	SETBIT(M_S_Control,MOSI);
	SETBIT(M_S_Control,SCK);
	
	
	SETBIT(SPCR,MSTR); // Enable Master
	SETBIT(SPCR,SPR0); // Set clock rate focs/16
	CLEARBIT(SPCR,SPR1); // Set clock rate focs/16
	
	// Set MISO as input
	CLEARBIT(M_S_Control,MISO);
	
	#elif (Mode_S == Slave)
	// Set MISO output
	SETBIT(M_S_Control,MISO);
	// Set MOSI ,as input
	CLEARBIT(M_S_Control,SS);
	CLEARBIT(M_S_Control,MOSI);
	CLEARBIT(M_S_Control,SCK);
	
	// Enable Slave mode
	CLEARBIT(SPCR,MSTR);
	#endif
	// enable SPI
	SETBIT(SPCR,SPE);  // Enable SPI
}
uint8_t SPI_SendReceive(uint8_t data)
{
	/* Start transmission */
	SPDR = data;
	/* Wait for transmission complete */
	while(!(SPSR & (1<<SPIF)));
	return SPDR;
}