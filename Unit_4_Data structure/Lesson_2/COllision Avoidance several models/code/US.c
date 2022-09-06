/*
 * CA.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Abotaleb
 */

#include "US.h"

/***************** Generate random number *********************/
int GET_distance_random(uint32_t start ,uint32_t end,uint32_t step);

/***************** variables *********************/
static uint32_t US_distance=0;


/***************** state pointer to function *********************/
void (*US_STATE)();

void US_init()
{
	printf("US_init\n");
}

STATE_define(US_BUSY)
{
	/***************** State name *********************/
	US_STATE_id=US_BUSY;

	/***************** State action *********************/
	US_distance=GET_distance_random(45,55,1);
	printf("US_BUSY state : distance = %d \n",US_distance);
	US_set_distance(US_distance);
	US_STATE=STATE_(US_BUSY) ;
}

int GET_distance_random(uint32_t start ,uint32_t end,uint32_t step)
{
	uint32_t counter;
	for(counter=0;counter<step;counter++)
	{
		uint32_t rand_num=(rand()%(end-start+1))+ start;
		return rand_num;
	}
}

