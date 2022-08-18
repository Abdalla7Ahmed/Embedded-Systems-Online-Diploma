/*
 * fifi.c
 *
 *  Created on: 15/8/2022
 *      Author: Abdallah Abotaleb
 */
#include "fifo.h"
FIFO_STATUS_t fifo_init(FIFO_BUFF_t *fifo_buff ,Element_type *buffer,uint32_t length)
{
	if (buffer==NULL)
	{
		return FIFO_NULL;
	}
	fifo_buff->base   = buffer;
	fifo_buff->head   = buffer;
	fifo_buff->tail   = buffer;
	fifo_buff->length = length;
	fifo_buff->count  = 0;
	return FIFO_no_error;
}
FIFO_STATUS_t PUSH_item(FIFO_BUFF_t *fifo_buff ,Element_type item)
{
	if (fifo_null(fifo_buff)==FIFO_NULL)
	{
		return FIFO_NULL;
	}
	else if(fifo_full(fifo_buff)==FIFO_full)
	{
		return FIFO_full;
	}
	else if (fifo_full(fifo_buff )==FIFO_no_error&&fifo_null(fifo_buff)==FIFO_no_error)
	{
		*(fifo_buff->head)=item;
		fifo_buff->count++;
		if(fifo_buff->head==(fifo_buff->base+(fifo_buff->length*sizeof(Element_type))))
		{
			fifo_buff->head=fifo_buff->base;
		}
		else
		{
			fifo_buff->head++;
		}
		return FIFO_no_error;
	}
}
FIFO_STATUS_t POP_item(FIFO_BUFF_t *fifo_buff ,Element_type *item)
{
	if (fifo_null(fifo_buff)==FIFO_NULL)
	{
		return FIFO_NULL;
	}
	if (fifo_empty(fifo_buff)==FIFO_empty)
	{
		return FIFO_empty;
	}
	else if (fifo_empty(fifo_buff)==FIFO_no_error&&fifo_null(fifo_buff )==FIFO_no_error)
	{
		*item=*(fifo_buff->tail);
		fifo_buff->count--;

		if(fifo_buff->tail==(fifo_buff->base+(fifo_buff->length*sizeof(Element_type))))
		{
			fifo_buff->tail=fifo_buff->base;
		}
		else
		{
			fifo_buff->tail++;
		}
		return FIFO_no_error;

	}
}

FIFO_STATUS_t fifo_full(FIFO_BUFF_t *fifo_buff )
{
	if (!fifo_buff->base||!fifo_buff->head||!fifo_buff->tail)
	{
		return FIFO_NULL;
	}
	else if (fifo_buff->count==fifo_buff->length)
	{
		return FIFO_full;
	}
	else
	{
		return FIFO_no_error;
	}
}
FIFO_STATUS_t fifo_empty(FIFO_BUFF_t *fifo_buff)
{
	if (fifo_buff->count==0)
	{
		return FIFO_empty;
	}
	else
	{
		return FIFO_no_error;
	}

}
FIFO_STATUS_t fifo_null(FIFO_BUFF_t *fifo_buff )
{
	if (!fifo_buff->base||!fifo_buff->head||!fifo_buff->tail)
	{
		return FIFO_NULL;
	}
	else
	{
		return FIFO_no_error;
	}
}

void fifo_print(FIFO_BUFF_t *fifo_buff )
{
	Element_type *temp,*counter;
	uint8_t i;
	printf("\n=========== Now FIFO includes =========== \n");
	if (fifo_buff->count == 0)
	{
		printf("nothing to print \n");
	}
	else
	{
		temp=fifo_buff->tail;
		for(i=0;i<fifo_buff->count;i++)
		{
			printf(" element number %d is %d \n",i+1,*temp);
			temp++;
			counter++;
		}
	}
	printf("========= print elements is finished ========= \n\n\n");
}
