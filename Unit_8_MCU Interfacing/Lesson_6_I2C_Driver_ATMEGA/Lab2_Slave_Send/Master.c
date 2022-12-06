/*
 * ATMEG32_Drivers.c
 *
 * Created: 24/09/2022 11:06:07 AM
 * Author : Abdallah Ahmed Mohammed
 */ 
#include "SERVICES/Including_Services.h"
#include "MCAL/Including_MCAL_files.h"
#include "HAL/Including_HAL_files.h"
/* ======================== Master ========================= */
int main(void)
{
	DDRA = 0xFF;
	uint8_t ch=0;
	I2C_init_master(0x48);
	while (1)
	{
		_delay_ms(200);
		I2C_start();              
		I2C_send_Slave_address(0b11010000,Read);
		ch=I2C_Master_read_byte();
		I2C_stop();                
		PORTA=ch;
	}
}

