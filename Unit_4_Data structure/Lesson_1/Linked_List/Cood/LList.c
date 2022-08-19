/*
 * LList.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Abotaleb
 */

#include "LList.h"

struct SStudent *gPFirstStudent=NULL;
void Add_student()
{
	struct SStudent *PNewStudent;
	struct SStudent *PLastStudent;
	uint8_t temp_text[40];
	if(gPFirstStudent==NULL)
	{
		PNewStudent=(struct SStudent *)malloc(sizeof(struct SStudent));
		gPFirstStudent=PNewStudent;
	}
	else
	{
		PLastStudent=gPFirstStudent;
		while(PLastStudent->PNextStudent)
		{
			PLastStudent=PLastStudent->PNextStudent;
		}
		PNewStudent=(struct SStudent *)malloc(sizeof(struct SStudent));
		PLastStudent->PNextStudent= PNewStudent;
	}
	/*********** fill new record  ***********/
	DPRINTF("Enter the ID : ");
	gets(temp_text);
	PNewStudent->Student.ID=atoi(temp_text);

	DPRINTF("Enter the name : ");
	gets(PNewStudent->Student.name);

	DPRINTF("Enter the heigth : ");
	gets(temp_text);
	PNewStudent->Student.heigth=atof(temp_text);
	DPRINTF("Add student done successfully  \n");
	/*********** set the next pointer ***********/
	PNewStudent->PNextStudent=NULL;
}
int Delete_student()
{

	uint8_t temp_text[40];
	uint32_t selected_id;

	DPRINTF("Enter the student ID to be deleted : \n");
	gets(temp_text);
	selected_id=atoi(temp_text);
	if (gPFirstStudent)
	{
		struct SStudent *PSelectedStudent=gPFirstStudent;
		struct SStudent *PPreviousStudent=NULL;

		while(PSelectedStudent)
		{
			if (PSelectedStudent->Student.ID==selected_id)
			{
				if(PPreviousStudent)
				{
					PPreviousStudent->PNextStudent=PSelectedStudent->PNextStudent;
				}
				else
				{
					gPFirstStudent=PSelectedStudent->PNextStudent;
				}
				free(PSelectedStudent);
				DPRINTF("Delete student done successfully  \n");
				return 1;

			}
			PPreviousStudent=PSelectedStudent;
			PSelectedStudent=PSelectedStudent->PNextStudent;
		}
	}
	else
	{
		DPRINTF("Failed !!! Wrong option \n");
		return 0;
	}
}
void View_all_students()
{
	DPRINTF("========== You records until now ==========\n ");
	uint32_t counter;
	struct SStudent *PCurrentStudent=gPFirstStudent;
	if(gPFirstStudent==NULL)
	{
		DPRINTF("Nothing to print !! read the list again to chose another option \n");
	}
	else
	{
		while (PCurrentStudent)
		{
			DPRINTF("####### record Number %d #######\n",counter+1);
			DPRINTF("# student ID : %d               \n",PCurrentStudent->Student.ID);
			DPRINTF("# student name : %s             \n",PCurrentStudent->Student.name);
			DPRINTF("# student heigth : %.2f         \n",PCurrentStudent->Student.heigth);
			DPRINTF("################################\n");
			PCurrentStudent=PCurrentStudent->PNextStudent;
			counter++;
		}
	}
	DPRINTF("========== printing students done successfully  ========== \n");
}
void Delete_all_student()
{
	struct SStudent *PCurrentStudent=gPFirstStudent;
	if(gPFirstStudent==NULL)
	{
		DPRINTF("Sorry !! the list is empty \n");
	}
	else
	{
		while (PCurrentStudent)
		{
			struct SStudent *PTempStudent=PCurrentStudent;
			PCurrentStudent=PCurrentStudent->PNextStudent;
			free(PTempStudent);
		}
		gPFirstStudent=NULL;
		DPRINTF("========== Delete all students done successfully  ========== ");
	}
}

int Index_of_student()
{
	uint8_t temp_text[40];
	uint32_t selected_index;
	uint32_t counter=1;

	DPRINTF("Enter the student index : \n");
	gets(temp_text);
	selected_index=atoi(temp_text);
	if (gPFirstStudent)
	{
		struct SStudent *PCurrentStudent=gPFirstStudent;
		while(PCurrentStudent)
		{
			if (counter==selected_index)
			{
				DPRINTF("your entered index : %d \n",counter);
				DPRINTF(" student ID : %d \n",PCurrentStudent->Student.ID);
				DPRINTF(" student name : %s \n",PCurrentStudent->Student.name);
				DPRINTF(" student heigth : %.2f \n",PCurrentStudent->Student.heigth);
				return 1;
			}
			PCurrentStudent=PCurrentStudent->PNextStudent;
			counter++;
		}
	}
	else
	{
		DPRINTF("Failed !!! Wrong option \n");
		return 0;
	}

}
//int Length_of_list()
//{
//	uint32_t counter=0;
//	struct SStudent *PCurrentStudent=gPFirstStudent;
//	if (!gPFirstStudent)
//	{
//		return 0;
//	}
//	else
//	{
//		PCurrentStudent=PCurrentStudent->PNextStudent;
//		return 1+Length_of_list();
//
//	}
//	DPRINTF("You record until now %d student(s)\n",counter);
//	return 1;
//}

int Length_of_list()
{
	uint32_t counter=0;
	if (gPFirstStudent)
	{
		struct SStudent *PCurrentStudent=gPFirstStudent;
		while(PCurrentStudent)
		{
			PCurrentStudent=PCurrentStudent->PNextStudent;
			counter++;
		}
	}
	DPRINTF("You record until now %d student(s)\n",counter);
	return 1;
}
int Middle_students()
{
	uint32_t counter=0,Middle_number;
	if (gPFirstStudent)
	{
		struct SStudent *PCurrentStudent=gPFirstStudent;

		while(PCurrentStudent)
		{
			PCurrentStudent=PCurrentStudent->PNextStudent;
			counter++;
		}
		/********** middle of numbers **********/
		Middle_number=counter/2;
		DPRINTF("=====You record until now %d student(s)=====\n",counter);
		if (counter==1)
		{
			DPRINTF("You record only one student \n");
		}
		else if (counter==2)
		{
			DPRINTF("the middle of your records is :%d \n",Middle_number);
		}
		else
		{
			DPRINTF("the middle of your records is :%d\n",++Middle_number);
		}
		/********** printing the middle student **********/
		counter=1;
		PCurrentStudent=gPFirstStudent;
		while(PCurrentStudent)
		{
			if (counter==Middle_number)
			{
				DPRINTF(" student ID : %d \n",PCurrentStudent->Student.ID);
				DPRINTF(" student name : %s \n",PCurrentStudent->Student.name);
				DPRINTF(" student heigth : %.2f \n",PCurrentStudent->Student.heigth);
				return 1;
			}
			PCurrentStudent=PCurrentStudent->PNextStudent;
			counter++;
		}
	}
	else
	{
		DPRINTF("=====Your list is empty=====\n");
		return 0;
	}

}
void Reverse_List()
{
	struct SStudent *PCurrentStudent=gPFirstStudent;
	struct SStudent *P_Next = NULL;
	struct SStudent *P_Previous = NULL;
	if(gPFirstStudent)
	{
		while(PCurrentStudent)
		{
			P_Next=(PCurrentStudent->PNextStudent);
			PCurrentStudent->PNextStudent = P_Previous;
			P_Previous=PCurrentStudent;
			PCurrentStudent=P_Next;
		}
		gPFirstStudent=P_Previous;
		DPRINTF("=====Reverse list done sucsessfully pres (3) to view the new order =====\n");

	}
	else
	{
		DPRINTF("=====Your list is empty=====\n");
	}
}
