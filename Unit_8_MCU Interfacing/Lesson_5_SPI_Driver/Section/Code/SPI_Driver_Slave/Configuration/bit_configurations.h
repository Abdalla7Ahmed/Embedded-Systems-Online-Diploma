/*
 * bit_configurations.h
 *
 * Created: 27/10/2022 05:41:38 م
 *  Author: Abotaleb
 */ 


#ifndef BIT_CONFIGURATIONS_H_
#define BIT_CONFIGURATIONS_H_


/*======================= Bit Configration ======================*/
#define SETBIT(register,bit)     (register |=(1<<bit))

#define CLEARBIT(register,bit)   (register &=~(1<<bit))

#define TOGGLEBIT(register,bit)  (register ^=(1<<bit))

#define READBIT(register,bit)    ((register>>bit)&1)

#define SET_PORT(register)		(register |=0xFF)

#define CLEAR_PORT(register)		(register &=0x00)
/*=================================================================*/


#endif /* BIT_CONFIGURATIONS_H_ */