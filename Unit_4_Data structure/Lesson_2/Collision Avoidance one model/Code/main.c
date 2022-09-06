/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Abotaleb
 */

#include "CA.h"

void setup()
{
	/********** init all driveres **********/

	/********** init IRQ ...... **********/

	/********** init HAL (US_driver - DC_motor driver) **********/

	/********** init Block **********/

	/********** Set states pointers for each block **********/
	CA_STATE=STATE_(CA_WAITING);
}

void main()
{
	uint32_t counter;
	setup();
	while(1)
	{
		/********** call state for each block**********/
		CA_STATE();
		for (counter=0;counter<2000;counter++); //######  delay ######
	}
}
