/*
 * fifo.h
 *
 *  Created on: 15/8/2022
 *      Author: Abdallah Abotaleb
 */

#ifndef FIFO_H_
#define FIFO_H_
#include "stdio.h"
#include "stdint.h"
#define Element_type uint8_t
#define buffer_length 5
Element_type buffer[buffer_length];
typedef struct
{
	uint32_t      length;
	uint32_t      count;
	Element_type *base;
	Element_type *head;
	Element_type *tail;
}FIFO_BUFF_t;

typedef enum
{
	FIFO_no_error,
	FIFO_full,
	FIFO_empty,
	FIFO_NULL
}FIFO_STATUS_t;

/********************** APIS **********************/
FIFO_STATUS_t fifo_init(FIFO_BUFF_t *fifo_buff ,Element_type *buffer,uint32_t length);
FIFO_STATUS_t PUSH_item(FIFO_BUFF_t *fifo_buff ,Element_type item);
FIFO_STATUS_t POP_item(FIFO_BUFF_t *fifo_buff ,Element_type *item);
FIFO_STATUS_t fifo_full(FIFO_BUFF_t *fifo_buff );
FIFO_STATUS_t fifo_empty(FIFO_BUFF_t *fifo_buff );
FIFO_STATUS_t fifo_null(FIFO_BUFF_t *fifo_buff );
void fifo_print(FIFO_BUFF_t *fifo_buff );

#endif
