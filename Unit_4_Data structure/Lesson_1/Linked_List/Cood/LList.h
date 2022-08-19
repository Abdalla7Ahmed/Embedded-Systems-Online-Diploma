/*
 * LList.h
 *
 *  Created on: 15/8/2022
 *      Author: Abdallah Abotaleb
 */
#ifndef LLIST_H_
#define LLIST_H_
#include <stdio.h>
#include "stdlib.h"
#include "string.h"
#include "conio.h"
#define DPRINTF(...)   {fflush(stdout);\
						fflush(stdin);\
						printf(__VA_ARGS__);\
						fflush(stdout);\
						fflush(stdin);}


typedef unsigned int uint32_t;
typedef unsigned char uint8_t;
typedef float float32_t;

struct Sdata
{
	uint32_t ID;
	uint8_t name[40];
	float32_t heigth;

};

struct SStudent
{
	struct Sdata Student;
	struct SStudent *PNextStudent;
};

/*********************** APIS ***********************/

void Add_student();
int Delete_student();
void View_all_students();
void Delete_all_student();
int Index_of_student();
int Length_of_list();
int Middle_students();
void Reverse_List();

#endif



