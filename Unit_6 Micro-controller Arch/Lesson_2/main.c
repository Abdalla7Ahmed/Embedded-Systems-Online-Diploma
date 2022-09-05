/*
 * ===========================================================
 * main.c
 *  Created on: 3/9/2022
 *      Author: Abdallah Ahmed
 *
 * ============= Write (1) on pit (16) on ODR register by ==================
 * 1] --> Using numeric memory address directly
 * 2] --> Casting an address to a pointer
 * 3] --> Casting to a pointer and then dereferencing it
 * 4] --> use structure, union and pointer for one register
 * 5] --> use structures and pointers for all registers in a GPIO peripheral
 * =========================================================================
 */

#include <stdio.h>
#include "stdint.h"

/*==============================================================================*/

// 1 Using numeric memory address directly
uint32_t GPIO_ODR1=0;
#define GPIO1 &GPIO_ODR1

/*==============================================================================*/

// 2 Casting an address to a pointer
uint32_t GPIO_ODR2=0;
#define GPIO2 ((volatile uint32_t *)(&GPIO_ODR2))

/*==============================================================================*/

// 3 Casting to a pointer and then dereferencing it
uint32_t GPIO_ODR3=0;
#define GPIO3 *((volatile uint32_t *)(&GPIO_ODR3))

/*==============================================================================*/
// 4 use structure, union and pointer for one register
uint32_t GPIO_ODR4=0;
typedef struct
{
	uint32_t Pin0:1;
	uint32_t Pin1:1;
	uint32_t Pin2:1;
	uint32_t Pin3:1;
	uint32_t Pin4:1;
	uint32_t Pin5:1;
	uint32_t Pin6:1;
	uint32_t Pin7:1;
	uint32_t Pin8:1;
	uint32_t Pin9:1;
	uint32_t Pin10:1;
	uint32_t Pin11:1;
	uint32_t Pin12:1;
	uint32_t Pin13:1;
	uint32_t Pin14:1;
	uint32_t Pin15:1;
	uint32_t Pin16:1;
	uint32_t Pin17:1;
	uint32_t Pin18:1;
	uint32_t Pin19:1;
	uint32_t Pin20:1;
	uint32_t Pin21:1;
	uint32_t Pin22:1;
	uint32_t Pin23:1;
	uint32_t Pin24:1;
	uint32_t Pin25:1;
	uint32_t Pin26:1;
	uint32_t Pin27:1;
	uint32_t Pin28:1;
	uint32_t Pin29:1;
	uint32_t Pin30:1;
	uint32_t Pin31:1;
} GPIO_PIN_t;

typedef union
{
	uint32_t all_port;
	GPIO_PIN_t PIN;
}GPIO;
volatile GPIO *GPIO4=(volatile GPIO *)(&GPIO_ODR4);

/*==============================================================================*/
// 5 use structures and pointers for all registers in a GPIO peripheral
uint32_t GPIO_ODR5[4]={0};
typedef struct
{
	volatile uint32_t Modern;
	volatile uint32_t ODR;
	volatile uint32_t ASCR;
	volatile uint32_t IDR;
}SGPIO;

//#define GPIOA (volatile uint32_t*)(0x48000000)
//#define GPIOB (volatile uint32_t*)(0x48000400)
//#define GPIOC (volatile uint32_t*)(0x48000800)

volatile SGPIO* GPIO5=(volatile SGPIO*)(&GPIO_ODR5[0]);


/*==============================================================================*/

// How to swap nibbles in byte by macro
#define SeapN(data) ((data&(0x0f))<<4)|((data&(0xf0))>>4)

// How to swap 2 Byte by macro
#define SeapB(data) ((data&(0x00ff))<<8)|((data&(0xff00))>>8)


// How to convert between little endian and big endian by macro
#define Convert(data) ((data&(0x000000ff))<<24)|(data&(0x0000ff00)<<8)|(data&(0x00ff0000)>>8)|(data&(0xff000000)>>24)
void main ()
{

	// 1 Using numeric memory address directly
	*((volatile uint32_t *)(GPIO1))|= 1UL<<16;
	printf("First method output = 0x%X\n",GPIO_ODR1);


	// 2 Casting an address to a pointer
	*GPIO2 |=1UL<<16;
	printf("second method output = 0x%X\n",GPIO_ODR2);

	// 3 Casting to a pointer and then dereferencing it
	GPIO3 |=1UL<<16;
	printf("Third method output = 0x%X\n",GPIO_ODR3);

	// 4 use structure, union and pointer for one register
	GPIO_ODR2=GPIO4->PIN.Pin16=1;
	printf("Fourth method output = 0x%X\n",GPIO_ODR4);


	// 5 use structures and pointers for all registers in a GPIO peripheral
	GPIO5->ODR=(1UL<<16);
	printf("fifth method output = 0x%X\n",GPIO_ODR5[1]);

	printf("================================================\n");

	//  swap nibbles in byte
	printf("Before swapping the two nible : %x\n",0x5C);
	printf("After swapping the two nible : %x\n",SeapN(0x5C));


	//  swap 2 byte
	printf("Before swapping the two byte : %x\n",0xAD5C);
	printf("After swapping the two byte : %x\n",SeapB(0xAD5C));

	// convert between little endian and big endian
	printf("Before converting : %x\n",0xAD5C45ED);
	printf("After swapping converting : %x\n",Convert(0xAD5C45ED));

}

