/*
 * CA.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Abotaleb
 */

#ifndef CA_H_
#define CA_H_
#include "State.h"

enum
{
	CA_WAITING,
	CA_DRIVING
}CA_STATE_id;

/************** Declare state function collision avoidance ****************/

STATE_define(CA_WAITING);                   //void ST_CA_WAITING();
STATE_define(CA_DRIVING);                   //void ST_CA_DRIVING();
int GET_distance_random(uint32_t start ,uint32_t end,uint32_t step);

/***************** state pointer to function *********************/
extern void (*CA_STATE)();

#endif /* CA_H_ */
