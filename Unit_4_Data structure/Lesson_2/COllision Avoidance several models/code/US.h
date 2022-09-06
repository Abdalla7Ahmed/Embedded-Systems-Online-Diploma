/*
 * CA.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Abotaleb
 */

#ifndef US_H_
#define US_H_
#include "State.h"

enum
{
	US_BUSY
}US_STATE_id;

/************** Declare state function collision avoidance ****************/

STATE_define(US_BUSY);                   //void ST_US_BUSY();
void US_init();

/***************** state pointer to function *********************/
extern void (*US_STATE)();

#endif /* US_H_ */
