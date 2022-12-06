/*
 * I2C.c
 *
 * Created: 01/12/2022 04:42:11 م
 *  Author: Abotaleb
 */ 
#include "I2C.h"

void I2C_init_master(unsigned long SCL_Clock)
{
	TWBR = (unsigned char) ( ( (F_CPU/SCL_Clock) -16 ) / (2*prescaler));
 	switch(prescaler)
 	{
 		case 0:
 			CLEARBIT(TWSR,TWPS0);
 			CLEARBIT(TWSR,TWPS1);
 			break;
 		case 4:
 			SETBIT(TWSR,TWPS0);
 			CLEARBIT(TWSR,TWPS1);
 			break;
 		case 16:
 			CLEARBIT(TWSR,TWPS0);
 			SETBIT(TWSR,TWPS1);
 			break;
 		case 64:
 			SETBIT(TWSR,TWPS0);
 			SETBIT(TWSR,TWPS1);
 			break;	
 	}
 	SETBIT(TWCR,TWEN);	// Enable I2C
}

void I2C_init_Slave(uint8_t Slave_address)
{
	
	TWAR = (Slave_address);  // 0b(0000001)0   set the address , the last bit not including with the address bits
	SETBIT(TWCR,TWEN);	// Enable I2C
}
void I2C_start(void)
{
	SETBIT(TWCR,TWINT); // set interrupt flag with one to be low,This bit is set by hardware when the TWI has finished its current job
	SETBIT(TWCR,TWSTA);	// Start condition bit 
	SETBIT(TWCR,TWEN);	// Enable I2C 

	while( ( (TWCR &(1<<7)) ) == 0);      // interrupt flag will change from one to zero when finished its current job
	while((TWSR &0xF8)!=Start_ACK);		  // Wait until TWSR to be with value of Start Acknowledge 
	// in TWSR the first three bits not including for Acknowledge , we and 0b11111000 with TWSR 
}

void I2C_RepeatStart(void)
{
	SETBIT(TWCR,TWINT); // set interrupt flag with one to be low,This bit is set by hardware when the TWI has finished its current job
	SETBIT(TWCR,TWSTA);	// Start bit
	SETBIT(TWCR,TWEN);	// Enable TWI

	while( ( (TWCR &(1<<7)) ) == 0);        // interrupt flag will change from one to zero when finished its current job
	while((TWSR &0xF8)!=RepeatedStart_ACK); // Wait until TWSR be with value of repeated Start Acknowledge
}
void I2C_send_Slave_address(uint8_t slave_address,uint8_t command)
{
	TWDR =(slave_address);     //first bit is TWGCR
	if (command == Write)
	{
		SETBIT(TWCR,TWINT); // set interrupt flag with one to be low,This bit is set by hardware when the TWI has finished its current job
		SETBIT(TWCR,TWEN);	// Enable I2C
		while( ( (TWCR &(1<<7)) ) == 0);   // interrupt flag will change from one to zero when finished its current job
		while((TWSR &0xF8)!=Slave_WR_Send_ACK); // Wait until TWSR be with value of the Acknowledge
	}
	else if (command ==Read)
	{
		SETBIT(TWDR,0);               // read command
		SETBIT(TWCR,TWINT); // set interrupt flag with one to be low,This bit is set by hardware when the TWI has finished its current job
		SETBIT(TWCR,TWEN);	// Enable I2C
		while( ( (TWCR &(1<<7)) ) == 0);
		while((TWSR &0xF8)!=Slave_R_send_ACK);
	}
	

}

void I2C_Master_Write_byte(uint8_t Byte)
{
	TWDR=Byte;
	SETBIT(TWCR,TWINT); // set interrupt flag with one to be low,This bit is set by hardware when the TWI has finished its current job
	SETBIT(TWCR,TWEN);	// Enable I2C
	while( ( (TWCR &(1<<7)) ) == 0);   // interrupt flag will change from one to zero when finished its current job
	while((TWSR &0xF8)!=REC_Byte_ACK); // Wait until TWSR be with value of the Acknowledge
	// in TWSR the first three bits not including for Acknowledge , we and 0b11111000 with TWSR
}

uint8_t I2C_Master_read_byte(void)
{
	SETBIT(TWCR,TWINT); // set interrupt flag with one to be low,This bit is set by hardware when the TWI has finished its current job
	SETBIT(TWCR,TWEN);	// Enable I2C
	while( ( (TWCR &(1<<7)) ) == 0);   // interrupt flag will change from one to zero when finished its current job
	return TWDR;
}

void I2C_stop(void)
{
	TWCR =0x00;
	SETBIT(TWCR,TWINT); // set interrupt flag with one to be low,This bit is set by hardware when the TWI has finished its current job
	SETBIT(TWCR,TWSTO);	// Start condition bit
	SETBIT(TWCR,TWEN);	// Enable I2C
}

void I2C_Slave_Write_byte(uint8_t Byte)
{
	TWDR=Byte;
	SETBIT(TWCR,TWINT); // set interrupt flag with one to be low,This bit is set by hardware when the TWI has finished its current job
	SETBIT(TWCR,TWEN);	// Enable I2C
	while( ( (TWCR &(1<<7)) ) == 0);   // interrupt flag will change from one to zero when finished its current job
	while((TWSR &0xF8)!=Slave_Byte_Transmitted); // Wait until TWSR be with value of the Acknowledge
	// in TWSR the first three bits not including for Acknowledge , we and 0b11111000 with TWSR
}
uint8_t I2C_Slave_read_byte(void)
{
	SETBIT(TWCR,TWINT); // set interrupt flag with one to be low,This bit is set by hardware when the TWI has finished its current job
	SETBIT(TWCR,TWEA);
	SETBIT(TWCR,TWEN);	// Enable I2C
	while( ( (TWCR &(1<<7)) ) == 0);   // interrupt flag will change from one to zero when finished its current job
	while((TWSR &0xF8)!=0x60); // Wait until TWSR be with value of the Acknowledge
	SETBIT(TWCR,TWINT); // set interrupt flag with one to be low,This bit is set by hardware when the TWI has finished its current job
	SETBIT(TWCR,TWEA);
	SETBIT(TWCR,TWEN);	// Enable I2C
	while( ( (TWCR &(1<<7)) ) == 0);   // interrupt flag will change from one to zero when finished its current job
	while((TWSR &0xF8)!=Slave_Byte_received); // Wait until TWSR be with value of the Acknowledge
	// in TWSR the first three bits not including for Acknowledge , we and 0b11111000 with TWSR
	return TWDR;
}








