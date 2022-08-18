/*
 * main.c
 *
 *  Created on: 15/8/2022
 *      Author: Abdallah Abotaleb
 */

#include "fifo.h"
void main()
{
	FIFO_BUFF_t Uart_fifo;
	Element_type counter ,temp=0;


	if (fifo_init(&Uart_fifo ,buffer,buffer_length)==FIFO_no_error)
	{
		printf("******** FIFO initialization done successfully ********\n\n");
	}
	printf("############## PUSH items ############## \n");
	for (counter=0;counter<7;counter++)
	{
		printf("FIFO enqueue : (%d) ========= ",counter);


		if(PUSH_item(&Uart_fifo,counter)==FIFO_no_error)
		{
			printf("Done \n");
		}
		else if(PUSH_item(&Uart_fifo,counter)==FIFO_full)
		{
			printf("Failed !! sorry Fifo is full \n");
		}
		else if(PUSH_item(&Uart_fifo,counter)==FIFO_NULL)
		{
			printf("Failed !! sorry there is no FIFO  \n");
		}

	}

	fifo_print(&Uart_fifo);

	printf("############## POP items ############## \n");
	for (counter=0;counter<7;counter++)
	{
		if(POP_item(&Uart_fifo,&temp)==FIFO_no_error)
		{
			printf("FIFO dequeue : (%d) ========= Done \n",temp);
		}
		else if(POP_item(&Uart_fifo,&temp)==FIFO_empty)
		{
			printf("FIFO dequeue : ========= Sorry FIFO is empty \n");
		}
		else if(POP_item(&Uart_fifo,&temp)==FIFO_NULL)
		{
			printf("Failed !! sorry there is no FIFO  \n");
		}
	}
	fifo_print(&Uart_fifo);
}

