/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Abotaleb
 */
#include "US.h"
#include "CA.h"
#include "DC.h"

void setup()
{
	/********** init all driveres **********/

	/********** init IRQ ...... **********/

	/********** init HAL (US_driver - DC_motor driver) **********/

	/********** init Block **********/
	US_init();
	DC_init();
	/********** Set states pointers for each block **********/
	CA_STATE=STATE_(CA_WAITING);
	US_STATE=STATE_(US_BUSY);
	DC_STATE=STATE_(DC_IDLE);
}

void main()
{
	uint32_t counter;
	setup();
	while(1)
	{
		/********** call state for each block**********/
		US_STATE();
		CA_STATE();
		DC_STATE();
		printf("################################################\n");
		for (counter=0;counter<2000;counter++); //######  delay #######
	}
}
