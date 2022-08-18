/*
 * lifo.h
 *
 *  Created on: 14/8/2022
 *      Author: Abdallah Abotaleb
 */

#ifndef LIFO_H_
#define LIFO_H_

typedef unsigned int uint32_t;


// type defination
typedef struct {
	uint32_t length;
	uint32_t count;
	uint32_t *base;
	uint32_t *head;
}LIFO_BUFF_t;

typedef enum {
	LIFO_no_error,
	LIFO_Full,
	LIFO_empty,
	LIFO_NULL
}LIFO_Status_t;

// APIS

LIFO_Status_t LIFO_init(LIFO_BUFF_t *lifo_buff,uint32_t *buffer,uint32_t length);
LIFO_Status_t LIFO_PUSH_item(LIFO_BUFF_t *lifo_buff,uint32_t itema);
LIFO_Status_t LIFO_POP_item(LIFO_BUFF_t *lifo_buff,uint32_t *item);
LIFO_Status_t Check_for_null(LIFO_BUFF_t *lifo_buff);
LIFO_Status_t Check_for_full(LIFO_BUFF_t *lifo_buff);
LIFO_Status_t Check_for_empty(LIFO_BUFF_t *lifo_buff);

#endif

