/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Abdallah Ahmed Mohammed
 * @brief          : Main program body
 * @LAb            : 1
 ******************************************************************************
 */


#include<stdint.h>
#include<stdio.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif


typedef union {
	uint32_t all_fiels;
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

}STM32F103C6_t;

// register Base addresses
#define GPIOA_BASE  0x40010800
#define GPIOB_BASE  0x40010C00
#define RCC_BASE    0x40021000



// Registers of Port A
volatile STM32F103C6_t *GPIOA_CRL   =(volatile STM32F103C6_t *)(GPIOA_BASE+0x00);
volatile STM32F103C6_t *GPIOA_CRH   =(volatile STM32F103C6_t *)(GPIOA_BASE+0x04);
volatile STM32F103C6_t *GPIOA_IDR   =(volatile STM32F103C6_t *)(GPIOA_BASE+0x08);
volatile STM32F103C6_t *GPIOA_ODR   =(volatile STM32F103C6_t *)(GPIOA_BASE+0x0c);

// Registers of Port B
volatile STM32F103C6_t *GPIOB_CRL   =(volatile STM32F103C6_t *)(GPIOB_BASE+0x00);
volatile STM32F103C6_t *GPIOB_CRH   =(volatile STM32F103C6_t *)(GPIOB_BASE+0x04);
volatile STM32F103C6_t *GPIOB_IDR   =(volatile STM32F103C6_t *)(GPIOB_BASE+0x08);
volatile STM32F103C6_t *GPIOB_ODR   =(volatile STM32F103C6_t *)(GPIOB_BASE+0x0c);
// Registers of RCC
volatile STM32F103C6_t *RCC_APB2ENR =(volatile STM32F103C6_t *)(RCC_BASE+0x18  );




void clock_init()
{
	// Enable clock GPIOA
	RCC_APB2ENR->PIN.Pin2=1;

	// Enable clock GPIOB
	RCC_APB2ENR->PIN.Pin3=1;
}

void GPIOA_init()
{
	// set as an input floating
	// mode 1 input
	GPIOA_CRL->PIN.Pin4=0;
	GPIOA_CRL->PIN.Pin5=0;
	// CNF 1 floating
	GPIOA_CRL->PIN.Pin6=1;
	GPIOA_CRL->PIN.Pin7=0;

	// mode 13 input
	GPIOA_CRH->PIN.Pin20=0;
	GPIOA_CRH->PIN.Pin21=0;
	// CNF 13 floating
	GPIOA_CRH->PIN.Pin22=1;
	GPIOA_CRH->PIN.Pin23=0;
}

void GPIOB_init()
{
	// set as an output
	// mode 1 as output max speed 10 MHZ
	GPIOB_CRL->PIN.Pin4=1;
	GPIOB_CRL->PIN.Pin5=0;
	// CNF 1 GPIO Push-Pull
	GPIOB_CRL->PIN.Pin6=0;
	GPIOB_CRL->PIN.Pin7=0;

	// mode 13 as output max speed 10 MHZ
	GPIOB_CRH->PIN.Pin20=1;
	GPIOB_CRH->PIN.Pin21=0;
	// CNF 13 GPIO Push-Pull
	GPIOB_CRH->PIN.Pin22=0;
	GPIOB_CRH->PIN.Pin23=0;

}

void delay(uint32_t x)
{
	uint32_t i;
	for(i=0;i<x;i++);
}

int main(void)
{
	// clock Enable PORTA and PORTB
	clock_init();
	// Set GPIOA as an input
	GPIOA_init();
	// Set GPIOB as an output
	GPIOB_init();

	while(1)
	{
		if (GPIOA_IDR->PIN.Pin1==0)
		{
			// Toggle LED
			if (GPIOB_ODR->PIN.Pin1==0)
			{
				GPIOB_ODR->PIN.Pin1=1;
			}
			else
			{
				GPIOB_ODR->PIN.Pin1=0;
			}
			while (GPIOA_IDR->PIN.Pin1==0); //single press
		}
		if (GPIOA_IDR->PIN.Pin13==1)
		{
			// Toggle LED
			if (GPIOB_ODR->PIN.Pin13==0)
			{
				GPIOB_ODR->PIN.Pin13=1;
			}
			else
			{
				GPIOB_ODR->PIN.Pin13=0;
			}
			// multi press
		}
		delay(1000);
	}
}

