/*
 * main.c
 *
 *  Created on: 14/8/2022
 *      Author: Abdallah Abotaleb
 */
#include <stdio.h>
#include "stdlib.h"
#include "lifo.h"
#include "stdint.h"
#define length 5
uint32_t buffer1[length];

int main()
{
	uint32_t i,temp=0;

	/************ static allocation ************/
	LIFO_BUFF_t UART_LIFO,I2C_LIFO;
	if (LIFO_init(&UART_LIFO,buffer1,length)==LIFO_no_error)
	{
		printf("\n=====LIFO initialization done successfully ======\n");
	}

	/************ dynamic allocation ************/
	uint32_t *buffer2=(uint32_t*)malloc(5*sizeof(uint32_t));
	LIFO_init(&I2C_LIFO,buffer2,length);


	/************ PUSH items ************/
	printf("\n**************** PUSH items **************** \n\n");
	for (i=0;i<7;i++)
	{
		if(LIFO_PUSH_item(&UART_LIFO,i)== LIFO_no_error)
		{
			printf("UART lifo add : %d \n",i);
		}

		else if (LIFO_PUSH_item(&UART_LIFO,i)== LIFO_Full)
		{
			printf("There is no enough size to store item : %d \n",i);
		}
		else if (LIFO_PUSH_item(&UART_LIFO,i)== LIFO_NULL)
		{
			printf("There is no UART_LIFO\n");
		}
	}
	/************ POP items ************/
	printf("\n**************** POP items **************** \n\n");
	for (i=0;i<7;i++)
	{
		if(LIFO_POP_item(&UART_LIFO,&temp)==LIFO_no_error)
		{
			printf("uart lifo get:  %d \n",temp);
		}
		else if (LIFO_POP_item(&UART_LIFO,&temp)== LIFO_empty)
		{
			printf("There is no item stored \n");
		}
		else if (LIFO_POP_item(&UART_LIFO,&temp)== LIFO_NULL)
		{
			printf("There is no UART_LIFO\n");
		}

	}
	return 0;
}

