/*
 ******************************************************************************
 * @file           : main.c
 * @author         : Abdallah Ahmed Mohammed
 * @brief          : Main program body
 ******************************************************************************
 */
#include<stdint.h>
#include<stdlib.h>
#include<stdio.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

// register Base addresses
#define GPIOA_BASE 0x40010800
#define RCC_BASE 0x40021000

// register offset addresses
#define RCC_APB2ENR  *(volatile uint32_t *)(RCC_BASE + 0x18)
#define GPIOA_CRH    *(volatile uint32_t *)(GPIOA_BASE + 0x04)
#define GPIOA_ODR    *(volatile uint32_t *)(GPIOA_BASE + 0x0C)


typedef union {
	uint32_t all_port;
	struct {
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
	}PIN;

}ODR_t;

volatile ODR_t *PODR=(volatile ODR_t *)(GPIOA_BASE+0x0c);



int main(void)
{
	RCC_APB2ENR |= (1<<2);
	GPIOA_CRH &= 0xFF0FFFFF;
	GPIOA_CRH |= 0x00200000;

	while(1)
	{
		PODR->PIN.Pin13=1;
		for(int i=0; i<1000;i++);
		PODR->PIN.Pin13=0;
		for(int i=0;i<1000;i++);
	}
}
