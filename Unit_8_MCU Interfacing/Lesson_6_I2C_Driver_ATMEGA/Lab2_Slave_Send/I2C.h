/*
 * I2C.h
 *
 * Created: 01/12/2022 04:42:22 م
 *  Author: Abotaleb
 */ 


#ifndef I2C_H_
#define I2C_H_
//#include "../SERVICES/Including_Services.h"
#define F_CPU 16000000UL
#include<avr/io.h>
#include<util/delay.h>
#include "../SERVICES/Bit_Configuration.h"
#define prescaler      1 // 2 , 4 , 16 ,64
// Acknowledge 
#define Start_ACK					0x08				// start Acknowledge 
#define RepeatedStart_ACK			0x10				// Repeated  start Acknowledge 
#define Slave_WR_Send_ACK			0x18				// Master transmit (slave address + Write request) Acknowledge 
#define Slave_WR_Send_NACK			0x20				// Master transmit (slave address + Write request)No Acknowledge 
#define REC_Byte_ACK				0x28				// master transmitted byte --> slave Acknowledge
#define REC_Byte_NACK				0x30				// master transmitted byte --> slave No Acknowledge
#define Arbitration_lost            0x38                // Arbitration lost in slave write Acknowledge
#define Slave_R_send_ACK			0x40				// Master transmit (slave address + read request) Acknowledge 
#define Slave_R_send_NACK			0x48				// Master transmit (slave address + read request) No Acknowledge 
#define Master_Received_Data_ACK	0x50				// Master received data with Acknowledge 
#define Master_Received_Data_NACK	0x58				// Master received data with No Acknowledge
#define Slave_Byte_received         0x80				// data has been received , slave read
#define Slave_Byte_Transmitted      0xC0                // Slave write , master No Acknowledge



#define Write                      0
#define Read                       1

void I2C_init_master(unsigned long SCL_Clock);
void I2C_init_Slave(uint8_t Slave_address);
void I2C_start(void);
void I2C_RepeatStart(void);
void I2C_send_Slave_address(uint8_t slave_address,uint8_t command);
void I2C_Master_Write_byte(uint8_t Byte);
uint8_t I2C_Master_read_byte(void);




#endif /* I2C_H_ */