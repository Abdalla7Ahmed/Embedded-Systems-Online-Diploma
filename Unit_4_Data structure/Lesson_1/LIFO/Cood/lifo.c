/*
 * lifo.c
 *
 *  Created on: 14/8/2022
 *      Author: Abdallah Abotaleb
 */

#include "lifo.h"
#include "stdio.h"

LIFO_Status_t LIFO_init(LIFO_BUFF_t *lifo_buff,uint32_t *buffer,uint32_t length)
{
	/******************** check if buffer is exist or not  ********************/
	if (Check_for_null(lifo_buff)==LIFO_NULL)
	{
		return LIFO_NULL;
	}
	/******************** if no problems ********************/
	else{
		lifo_buff->base = buffer;
		lifo_buff->head = buffer;
		lifo_buff->length = length;
		lifo_buff->count = 0;
		return LIFO_no_error;
	}
}
LIFO_Status_t LIFO_PUSH_item(LIFO_BUFF_t *lifo_buff,uint32_t item)
{
	/******************** check if LIFO is exist or not  ********************/
	if (Check_for_null(lifo_buff)==LIFO_NULL)
	{
		return LIFO_NULL;
	}
	/******************** check if LIFO is overflow ********************/
	else if (Check_for_full(lifo_buff)==LIFO_Full)
	{
		return LIFO_Full;
	}
	/******************** if no problems ********************/
	else if (Check_for_null(lifo_buff)==LIFO_no_error&&Check_for_full(lifo_buff)==LIFO_no_error)
	{
		*(lifo_buff->head++) = item;
		lifo_buff->count++;
		return LIFO_no_error;
	}
}
LIFO_Status_t LIFO_POP_item(LIFO_BUFF_t *lifo_buff,uint32_t *item)
{
	/******************** check if LIFO is exist or not  ********************/
	if (Check_for_null(lifo_buff)==LIFO_NULL)
	{
		return LIFO_NULL;
	}
	/******************** check if LIFO is empty ********************/
	else if (Check_for_empty(lifo_buff)==LIFO_empty)
	{
		return LIFO_empty;
	}
	/******************** if no problems ********************/
	else if (Check_for_null(lifo_buff)==LIFO_no_error&&Check_for_empty(lifo_buff)==LIFO_no_error)
	{
		*item = *(--lifo_buff->head);
		lifo_buff->count--;
		return LIFO_no_error;
	}
}
LIFO_Status_t Check_for_null(LIFO_BUFF_t *lifo_buff)
{
	if (!lifo_buff->base||!lifo_buff->head)
	{
		return LIFO_NULL;
	}
	else
	{
		return LIFO_no_error;
	}
}
LIFO_Status_t Check_for_full(LIFO_BUFF_t *lifo_buff)
{
	if (!lifo_buff->base||!lifo_buff->head)
	{
		return LIFO_NULL;
	}
	else if (lifo_buff->count==lifo_buff->length)
	{
		return LIFO_Full;
	}
	else
	{
		return LIFO_no_error;
	}
}
LIFO_Status_t Check_for_empty(LIFO_BUFF_t *lifo_buff)
{
	if (!lifo_buff->base||!lifo_buff->head)
	{
		return LIFO_NULL;
	}
	else if (lifo_buff->count==0)
	{
		return LIFO_empty;
	}
	else
	{
		return LIFO_no_error;
	}
}


