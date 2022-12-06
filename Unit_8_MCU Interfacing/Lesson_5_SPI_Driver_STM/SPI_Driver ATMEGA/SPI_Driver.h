/*
 * SPI_Driver.h
 *
 * Created: 31/10/2022 12:13:45 م
 *  Author: Abotaleb
 */ 


#ifndef SPI_DRIVER_H_
#define SPI_DRIVER_H_

#define F_CPU 1000000UL
#include<avr/io.h>
#include<util/delay.h>
#include "../../Configuration/bit_configurations.h"

// Select clock Foosc devided by number
#define Fosc_D_B_4         0
#define Fosc_D_B_16        1
#define Fosc_D_B_64        2
#define Fosc_D_B_128       3
#define Fosc_D_B_2		   4
#define Fosc_D_B_8         5
#define Fosc_D_B_32        6


#define SS				4
#define MOSI			5
#define MISO			6
#define SCK				7
#define M_S_Control		DDRB
#define Data_CTRL		DDRA
#define Data_PORT       PORTA

#define Master          1
#define Slave           0
#define Mode_S			Slave 


// APIS
void SPI_INIT();
uint8_t SPI_SendReceive(uint8_t data);


#endif /* SPI_DRIVER_H_ */