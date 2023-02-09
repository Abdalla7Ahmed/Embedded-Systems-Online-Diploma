/*
 * Seven_segment.h
 *
 * Created: 01/02/2023 11:46:23 ص
 *  Author: Abotaleb
 */ 


#ifndef SEVEN_SEGMENT_H_
#define SEVEN_SEGMENT_H_
#include "../../MCAL/Includes/Include_MCAL_files.h"

#define S_A					0
#define S_B					1	
#define S_C					2
#define S_D					3
#define S_E					4
#define S_F					5
#define S_G					6

void HAL_Seven_segment_Write_numbrer(Typdef_DIOx_t *DIOx,uint8_t number);
void HAL_Seven_segment_Write_Allnumbrer(Typdef_DIOx_t *DIOx);



#endif /* SEVEN_SEGMENT_H_ */