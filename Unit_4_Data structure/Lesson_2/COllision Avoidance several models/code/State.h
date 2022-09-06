/*
 * State.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Abotaleb
 */

#ifndef STATE_H_
#define STATE_H_
#include "stdio.h"
#include "stdlib.h"
typedef unsigned int uint32_t;
/************** Automatic state function generated  ****************/
#define STATE_define(_statefunc_) void ST_##_statefunc_()
#define STATE_(_statefunc_) ST_##_statefunc_

/************** states connections ****************/
void US_set_distance(uint32_t d);
void DC_motor(uint32_t s);
#endif /* STATE_H_ */
