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


void clock_init()
{
	// Enable clock GPIOA
	RCC_GPIOA_CLK_EN();
	// Enable clock GPIOB
	RCC_GPIOB_CLK_EN();
	// Enable clock AFIO
	RCC_AFIO_CLK_EN();
}
unsigned int flag =0;
int VAL1=0;
int VAL2 =3;


int VAL3 =3;
int VAL4 =7;
int VAL5 =0;


int CPU_Control_Register =0;
int CPU_IPSR_Register =0;

void EXTRIB09_CallBack(void)
{
	flag =1;

	// ========== Lab 6 ============
	// read the value of IPSR register in Handler mode
	__asm("MRS %[out],IPSR"
			:[out] "=r"(CPU_IPSR_Register));
	__asm("nop \t\n nop \t\n nop ");
}
int main(void)
{
	clock_init();

	EXTRI_PinConfig_t PinConfig;
	PinConfig.PIN_INPUT = EXTRI9PB9;
	PinConfig.EXTRI_Trigger_Case=EXTRI_Trigger_Rising;
	PinConfig.P_IRQ_CallBack=EXTRIB09_CallBack;
	PinConfig.IRQ_ENABLE=EXTRI_IRQ_Enable;
	MCAL_EXTRI_GPIO_INIT(&PinConfig);


	// ========== Lab 1 ===========
	__asm("nop \t\n nop \t\n nop"); // can be used to make a delay (one clock cycle for no operation )

	// ========== Lab 2 ============
	__asm("nop \t\n nop \t\n nop");
	__asm("MOV %0,#0xFF"
			:"=r"(VAL1));// first output parameter
	//(=) operand is write only by the assembler template , (r) one of the core registers
	__asm("nop \t\n nop \t\n nop");

	// ========== Lab 3 ============
	__asm("MOV R0,%0"
			:			 // first : output parameter
			:"r"(VAL2));// second : input parameter
	__asm("nop \t\n nop \t\n nop");


	// ========== Lab 4 ============
	//ADD VAL2 and VAL3 in VAL4
	__asm("ADD %0,%1,%2"
			:"=r"(VAL5)			 // first : output parameter
			 :"r" (VAL3),// second : input parameter
			  "r"(VAL4));// second : input parameter
	__asm("nop \t\n nop \t\n nop");
	// ========== To make the code more redable ============
	__asm("ADD %[Out0],%[in0],%[in1]"
			:[Out0] "=r"(VAL5)			 // first : output parameter
			 :[in0] "r" (VAL3),// second : input parameter
			  [in1] "r"(VAL4));// second : input parameter
	__asm("nop \t\n nop \t\n nop");


	// ========== Lab 5 ============
	//ADD VAL2 and VAL3 in VAL4
	__asm("ADD %[Out0],%[in0],%[in1]"
				:[Out0] "=r"(VAL5)			 // first : output parameter
				:[in0] "r" (VAL3),// second : input parameter
				  [in1] "r"(VAL4)// second : input parameter
				:"r3"); // reserved
	__asm("nop \t\n nop \t\n nop");
	// ========== Lab 6 ============
	// read the value of control register in thread mode
	__asm("MRS %[out],CONTROL"
			:[out] "=r"(CPU_Control_Register));
	__asm("nop \t\n nop \t\n nop ");
	flag=1;
	while (1)
	{
		if (flag)
		{
			LCD_clear_screen();
			flag =0;
		}
	}

}

