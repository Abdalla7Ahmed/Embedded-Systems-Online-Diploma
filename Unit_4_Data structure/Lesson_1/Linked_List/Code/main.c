/*
 * main.c
 *
 *  Created on: 15/8/2022
 *      Author: Abdallah Abotaleb
 */

#include <stdio.h>
#include "stdlib.h"
#include "string.h"
#include "conio.h"
#include "LList.h"
void main()
{
	uint8_t text_temp[40];
	while(1)
	{
		DPRINTF("\n =======================");
		DPRINTF("\n\t Choose one from the following options ");
		DPRINTF("\n 1: Add student ");
		DPRINTF("\n 2: Delete student");
		DPRINTF("\n 3: View all students");
		DPRINTF("\n 4: Delete all students");
		DPRINTF("\n 5: Index of student ");
		DPRINTF("\n 6: Length_of_list ");
		DPRINTF("\n 7: the middle of your records");
		DPRINTF("\n 8: Reverse the list ");
		DPRINTF("\n\t Enter option number\n");
		gets(text_temp);
		DPRINTF("===============================\n");
		switch(atoi(text_temp))
		{
		case 1:
			Add_student();
			break;
		case 2:
			Delete_student();
			break;
		case 3:
			View_all_students();
			break;
		case 4:
			Delete_all_student();
			break;
		case 5:
			Index_of_student();
			break;
		case 6:
			Length_of_list();
			break;
		case 7:
			Middle_students();
			break;
		case 8:
			Reverse_List();
			break;
		default :
			DPRINTF("Wrong option");
			break;
		}
	}
}
