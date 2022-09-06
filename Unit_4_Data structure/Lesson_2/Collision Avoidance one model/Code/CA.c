/*
 * CA.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Abotaleb
 */

#include "CA.h"

/***************** variables *********************/
static uint32_t CA_speed=0;
static uint32_t CA_distance=0;
static uint32_t CA_threshold=50;



/***************** state pointer to function *********************/
void (*CA_STATE)();

STATE_define(CA_WAITING)
{
	/***************** State name *********************/
	CA_STATE_id=CA_WAITING;
	/***************** State action *********************/
	CA_speed=0;
	/***************** Event check *********************/
	CA_distance=GET_distance_random(45,55,1);
	if (CA_distance<=CA_threshold)
	{
		CA_STATE=STATE_(CA_WAITING);
	}
	else
	{
		CA_STATE=STATE_(CA_DRIVING);
	}
	// (CA_distance<=CA_threshold)?CA_STATE=STATE_define(CA_DRIVING):CA_STATE=STATE_define(CA_DRIVING);
	printf("CA_WAITING state : distance = %d , speed = %d \n",CA_distance,CA_speed);
}

STATE_define(CA_DRIVING)
{
	/***************** State name *********************/
	CA_STATE_id=CA_DRIVING;
	/***************** State action *********************/
	CA_speed=30;
	/***************** Event check *********************/
	CA_distance=GET_distance_random(45,55,1);
	if (CA_distance<=CA_threshold)
	{
		CA_STATE=STATE_(CA_WAITING);
	}
	else
	{
		CA_STATE=STATE_(CA_DRIVING);
	}
	printf("CA_DRIVING state : distance = %d , speed = %d \n",CA_distance,CA_speed);
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
