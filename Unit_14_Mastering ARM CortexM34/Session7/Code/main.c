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
#include "core_cm3.h"


int result ;



uint32_t OS_SVC_Set(uint32_t Number1,uint32_t Number2,uint32_t SVC_ID);



int main(void)
{
	result =OS_SVC_Set(3,3,1); //add
	result =OS_SVC_Set(3,3,2); // sub
	result =OS_SVC_Set(3,3,3); // mult
	// lab 2
	OS_SVC_Set(3,3,4);
	while (1)
	{

	}

}

void PendSV_Handler ()
{
	// clear pendSV
	SCB->ICSR |= SCB_ICSR_PENDSVCLR_Msk ; // bit 27 in ICSR

}

void OS_SVC_Services(uint32_t *StackFramPointer)
{
	unsigned char SVC_Number;
	unsigned int Number1,Number2;
	SVC_Number = *((unsigned char *)(((unsigned char *)StackFramPointer[6])-2));
	Number1 = StackFramPointer[0];
	Number2 = StackFramPointer[1];
	switch (SVC_Number)
	{
	case 1 : StackFramPointer[0] = Number1 + Number2 ; break;
	case 2 : StackFramPointer[0] = Number1 - Number2 ; break;
	case 3 : StackFramPointer[0] = Number1 * Number2 ; break;
	case 4 : SCB->ICSR |= SCB_ICSR_PENDSVSET_Msk	 ; break; // bit 28 in ICSR
	default: StackFramPointer[0] = 0 				 ; break;
	}


}
__attribute ((naked)) void SVC_Handler()
{
	__asm("TST LR,#4");
	__asm("ITE EQ"); 		/*if then equal*/
	__asm("MRSEQ R0,MSP");	/*Main stack pointer*/
	__asm("MRSNE R0,PSP"); /*Process stack pointer*/
	__asm("B OS_SVC_Services");

}

uint32_t OS_SVC_Set(uint32_t Number1,uint32_t Number2,uint32_t SVC_ID)
{
	uint32_t result ;
	switch(SVC_ID)
	{
	case 1: __asm("SVC #0x1"); break ;
	case 2: __asm("SVC #0x2"); break ;
	case 3: __asm("SVC #0x3"); break ;
	case 4: __asm("SVC #0x4"); break ;
	}
	__asm("MOV %[out] , R0 " : [out] "=r"(result));
	return result;
}
