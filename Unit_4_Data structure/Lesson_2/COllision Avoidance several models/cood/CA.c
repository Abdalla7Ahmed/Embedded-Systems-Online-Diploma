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

void US_set_distance(uint32_t d)
{
	CA_distance=d;
	/***************** Event check *********************/
	if (CA_distance<=CA_threshold)
	{
		CA_STATE=STATE_(CA_WAITING);
	}
	else
	{
		CA_STATE=STATE_(CA_DRIVING);
	}
	// (CA_distance<=CA_threshold)?CA_STATE=STATE_define(CA_DRIVING):CA_STATE=STATE_define(CA_DRIVING);
	printf("US send to CA distance : %d\n" ,CA_distance);
}
STATE_define(CA_WAITING)
{
	/***************** State name *********************/
	CA_STATE_id=CA_WAITING;
	printf("CA_WAITING state : distance = %d , speed = %d \n",CA_distance,CA_speed);

	/***************** State action *********************/
	CA_speed=0;
	DC_motor(CA_speed);
}

STATE_define(CA_DRIVING)
{
	/***************** State name *********************/
	CA_STATE_id=CA_DRIVING;
	printf("CA_DRIVING state : distance = %d , speed = %d \n",CA_distance,CA_speed);
	/***************** State action *********************/
	CA_speed=30;
	DC_motor(CA_speed);
}


