/*
 * Bit_Configuration.h
 *
 * Created: 24/09/2022 12:21:03 م
 *  Author: Abotaleb
 */ 


#ifndef BIT_CONFIGURATION_H_
#define BIT_CONFIGURATION_H_


#define SETBIT(register,bit)     (register |=(1<<bit))

#define CLEARBIT(register,bit)   (register &=~(1<<bit))

#define TOGGLEBIT(register,bit)  (register ^=(1<<bit))

#define READBIT(register,bit)    ((register>>bit)&1)


#endif /* BIT_CONFIGURATION_H_ */