/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Abdallah Ahmed Mohammed
 * @brief          : Main program body
 ******************************************************************************
 **/

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include "STM32F103C6.h"
#include "STM32F103C6_GPIO_Driver.h"
#include "STM32F103C6_EXTRI_Driver.h"
#include "lcd.h"
#include "Kaypad.h"
#include "Seven_Segment.h"



typedef enum
{
	Privileged,
	UnPrivileged
}Access_Level;
uint8_t IRQ_Flag =0,TaskA_Flag,TaskB_Flag;

EXTRI_PinConfig_t PinConfig;

#define TaskA_Stack_Size	100
#define TaskB_Stack_Size	100


#define OS_SET_PSP(address)				    __asm volatile("MOV R0 , %0 \n\t MSR PSP ,R0" : : "r" (address))

#define OS_Switch_SP_to_PSP			 		__asm volatile("MRS R0,CONTROL \n\t MOV R1 , #0x02 \n\t ORR R0,R0,R1 \n\t MSR CONTROL,R0")
#define OS_Switch_SP_to_MSP		 			__asm volatile("MRS R0,CONTROL \n\t MOV R1 , #0x05 \n\t AND R0,R0,R1 \n\t MSR CONTROL,R0")

#define OS_Generate_Exception     			__asm volatile("SVC #0x3")

#define Switch_To_Privileged_Access_Level	__asm("MRS R3,CONTROL \n\t LSR R3,R3,#0x1 \n\t LSL R3,R3,#0x1 \n\t MSR CONTROL,R3");
#define Switch_To_UnPrivileged_Access_Level	__asm("MRS R3,CONTROL \n\t ORR R3,R3,#0x1 \n\t  MSR CONTROL,R3");


extern int _estack ;

// Main Stack Pointer
unsigned int _S_MSP = &_estack;
unsigned int _E_MSP;

// PSP --> Task A
unsigned int _S_PSP_TA;
unsigned int _E_PSP_TA;


// PSP --> Task B
unsigned int _S_PSP_TB;
unsigned int _E_PSP_TB;

void Switch_Privileged_UnPrivileged(Access_Level Level);
void clock_init();
void EXTRIB09_CallBack(void);
void EXTRI_Configuration(void);
void MainOS();
uint32_t TaskA_Fun(uint32_t a,uint32_t b,uint32_t c);
uint32_t TaskB_Fun(uint32_t a,uint32_t b,uint32_t c,uint32_t d);



int main(void)
{
	clock_init();
	EXTRI_Configuration();

	MainOS();
	IRQ_Flag =1;
	while (1)
	{
		if (IRQ_Flag)
		{
			IRQ_Flag =0;
		}
	}

}








void EXTRI_Configuration(void)
{

	PinConfig.PIN_INPUT = EXTRI9PB9;
	PinConfig.EXTRI_Trigger_Case=EXTRI_Trigger_Rising;
	PinConfig.P_IRQ_CallBack=EXTRIB09_CallBack;
	PinConfig.IRQ_ENABLE=EXTRI_IRQ_Enable;
	MCAL_EXTRI_GPIO_INIT(&PinConfig);

}

void Switch_CPU_Access_Level(Access_Level Level)
{
	switch(Level)
	{
	case Privileged:
		__asm("mrs r3,CONTROL \n\t"
				"lsr r3,r3,#0x1 \n\t"
				"lsl r3,r3,#0x1 \n\t"
				"msr CONTROL,r3");
		break;
	case UnPrivileged :
		__asm("mrs r3,CONTROL \n\t"
				"orr r3,r3,#0x1 \n\t"
				"msr CONTROL,r3");
		break;

	}
}

void clock_init()
{
	// Enable clock GPIOA
	RCC_GPIOA_CLK_EN();
	// Enable clock GPIOB
	RCC_GPIOB_CLK_EN();
	// Enable clock AFIO
	RCC_AFIO_CLK_EN();
}


void SVC_Handler()
{
	Switch_To_Privileged_Access_Level;
}

void EXTRIB09_CallBack(void)
{
	if(IRQ_Flag ==0)
	{
		IRQ_Flag =1;
		TaskA_Flag =1;
	}
	else if(IRQ_Flag ==1)
	{
		IRQ_Flag =0;
		TaskB_Flag =1;
	}
}


uint32_t TaskA_Fun(uint32_t a,uint32_t b,uint32_t c)
{
	return a+b+c;
}
uint32_t TaskB_Fun(uint32_t a,uint32_t b,uint32_t c,uint32_t d)
{
	return a+b+c+d;
}
void MainOS()
{
	// Main Stack
	_E_MSP = (_S_MSP - 512);

	// Task A Process stack
	_S_PSP_TA = (_E_MSP - 8);
	_E_PSP_TA = (_S_PSP_TA - TaskA_Stack_Size);

	// Task B Process stack
	_S_PSP_TB = (_E_PSP_TA - 8);
	_E_PSP_TB = (_S_PSP_TB - TaskB_Stack_Size);


	while(1)
	{
		__asm("nop");

		if(TaskA_Flag ==1)
		{
			// set PSP register =_S_PSP_TA
			OS_SET_PSP(_S_PSP_TA);
			// SP point to PSP
			OS_Switch_SP_to_PSP;
			//Switch from Privileged to Unprivileged
			Switch_To_UnPrivileged_Access_Level;

			// |====================== Task A ========================|
			TaskA_Flag = TaskA_Fun(1, 2, 3);
			// |======================================================|

			// Thread mode --> handler mode , Switch from Unprivileged to Privileged
			OS_Generate_Exception;
			// SP point to MSP
			OS_Switch_SP_to_MSP;


		}
		else if(TaskB_Flag ==1)
		{
			// set PSP register =_S_PSP_TB
			OS_SET_PSP(_S_PSP_TB);
			// SP point to PSP
			OS_Switch_SP_to_PSP;
			//Switch from Unprivileged to Privileged
			Switch_To_UnPrivileged_Access_Level;


			// |====================== Task B ========================|
			TaskB_Flag = TaskB_Fun(1, 2, 3,4);
			// |======================================================|


			// Thread mode --> handler mode , Switch from Unprivileged to Privileged
			OS_Generate_Exception;
			// SP point to MSP
			OS_Switch_SP_to_MSP;

		}

	}

}
