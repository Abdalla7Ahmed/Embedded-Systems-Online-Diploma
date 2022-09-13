/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Abdallah Ahmed Mohammed
 * @brief          : Main program body
 * @LAb            : 1
 ******************************************************************************
 */


#include<stdint.h>
#include<stdlib.h>
#include<stdio.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif



// register Base addresses
#define GPIOA_BASE  0x40010800
#define RCC_BASE    0x40021000
#define EXTI_BASE   0x40010400
#define AFIO_BASE   0x40010000




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

volatile STM32F103C6_t *GPIOA_CRL   =(volatile STM32F103C6_t *)(GPIOA_BASE+0x00);
volatile STM32F103C6_t *RCC_APB2ENR =(volatile STM32F103C6_t *)(RCC_BASE+0x18  );
volatile STM32F103C6_t *GPIOA_ODR   =(volatile STM32F103C6_t *)(GPIOA_BASE+0x0c);
volatile STM32F103C6_t *GPIOA_CRH   =(volatile STM32F103C6_t *)(GPIOA_BASE+0x04);
volatile STM32F103C6_t *EXTI_IMR    =(volatile STM32F103C6_t *)(EXTI_BASE +0x00);
volatile STM32F103C6_t *EXTI_RTSR   =(volatile STM32F103C6_t *)(EXTI_BASE +0x08);
volatile STM32F103C6_t *EXTI_PR     =(volatile STM32F103C6_t *)(EXTI_BASE +0x14);
volatile STM32F103C6_t *EXTICR1     =(volatile STM32F103C6_t *)(AFIO_BASE +0x08);
volatile STM32F103C6_t *NVIC_ISR0   =(volatile STM32F103C6_t *)(0xE000E100     );



void clock_init()
{
	// Enable clock GPIOA
	RCC_APB2ENR->PIN.Pin2=1;

	// Enable Alternate function IO clock
	RCC_APB2ENR->PIN.Pin0=1;
}
void GPIO_pin0_input_init()
{
	// pin 0 PORT A as an input
	//01: Floating input (reset state)
	GPIOA_CRL->PIN.Pin2=1;
	GPIOA_CRL->PIN.Pin3=0;

}
void GPIO_pin13_output_init()
{
	// pin 13 PORT A as an output
	GPIOA_CRH->PIN.Pin20=0;
	GPIOA_CRH->PIN.Pin21=1;
	GPIOA_CRH->PIN.Pin22=0;
	GPIOA_CRH->PIN.Pin23=0;

}



int main(void)
{
	 clock_init();
	 GPIO_pin0_input_init();
	 GPIO_pin13_output_init();

	 // EXTRI0 	--> PORTA0
	 EXTICR1->PIN.Pin0=0;
	 EXTICR1->PIN.Pin1=0;
	 EXTICR1->PIN.Pin2=0;
	 EXTICR1->PIN.Pin3=0;

	 // Enable rising trigger
	 EXTI_RTSR->PIN.Pin0=1;


	 // Enable EXTRI line 0 --> 1
	 EXTI_IMR->PIN.Pin0=1;

	 // Enable NVIC IRQ --> line 6
	 NVIC_ISR0->PIN.Pin6=1;


	while(1);
}


void EXTI0_IRQHandler (void)
{
	// IRQ is happened
	// toggle led PORT A pin 13
	if(GPIOA_ODR->PIN.Pin13==1)
	{
		GPIOA_ODR->PIN.Pin13=0;
	}
	else
	{
		GPIOA_ODR->PIN.Pin13=1;
	}

	// clear pending requist for line 0
	 EXTI_PR->PIN.Pin0=1;
}
