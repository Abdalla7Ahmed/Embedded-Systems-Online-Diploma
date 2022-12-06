/*
 * ATMEG32_Drivers.c
 *
 * Created: 24/09/2022 11:06:07 AM
 * Author : Abdallah Ahmed Mohammed
 */ 
#include "SERVICES/Including_Services.h"
#include "MCAL/Including_MCAL_files.h"
#include "HAL/Including_HAL_files.h"
/*================================= Slave ===========================*/
int main(void)
{
	DDRA = 0xFF;
	I2C_init_Slave(0b11010000);
	while (1)
	{
		PORTA=I2C_Slave_read_byte();
	}

}


