/*
 * CA.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Abotaleb
 */

#include "DC.h"

/***************** variables *********************/
static uint32_t DC_speed=0;

/***************** state pointer to function *********************/
void (*DC_STATE)();
void DC_init()
{
	printf("Init DC_motor \n");
}
DC_motor(uint32_t s)
{
	DC_speed=s;
	printf("CA send to DC_motor , speed = %d\n" ,DC_speed);
	if (DC_speed==30)
	{
		DC_STATE=STATE_(DC_BUSY);
	}
	else
	{
		DC_STATE=STATE_(DC_IDLE);
	}

}
STATE_define(DC_IDLE)
{
	/***************** State name *********************/
	DC_STATE_id=DC_IDLE;
	/***************** State action *********************/
	printf("DC_IDLE state : speed = %d \n",DC_speed);

}
STATE_define(DC_BUSY)
{
	/***************** State name *********************/
	DC_STATE_id=DC_BUSY;
	/***************** State action *********************/
	printf("DC_BUSY state : speed = %d \n",DC_speed);
}
