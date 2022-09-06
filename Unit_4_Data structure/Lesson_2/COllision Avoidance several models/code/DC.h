/*
 * CA.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Abotaleb
 */

#ifndef DC_H_
#define DC_H_
typedef unsigned int uint32_t;
#include "State.h"

enum
{
	DC_IDLE,
	DC_BUSY
}DC_STATE_id;

/************** Declare state function collision avoidance ****************/
STATE_define(DC_IDLE);                   //void ST_DC_IDLE();
STATE_define(DC_BUSY);                   //void ST_DC_BUSY();
void DC_init();

/***************** state pointer to function *********************/
extern void (*DC_STATE)();



#endif /* DC_H_ */
