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

// MCAL includes
#include "../MCAL/Inc/STM32F103C6.h"
#include "../MCAL/Inc/STM32F103C6_GPIO_Driver.h"
#include "../MCAL/Inc/STM32F103C6_EXTRI_Driver.h"
#include "../MCAL/Inc/STM32F103C6_USART_Driver.h"
// HAL includes
#include "lcd.h"
#include "Kaypad.h"
#include "Seven_Segment.h"


void clock_init();
void UART_IRQ_Callback (void);

uint16_t ch ;
UART_Config uartCFG ;


int main(void)
{
	clock_init();
	uartCFG.Baud_rate = USART_BaudRate_115200;
	uartCFG.HWFlowCtrl = USART_FlowCtrl_NONE ;
	uartCFG.IRQ_Enable = USART_IRQ_Enable_RXNEIE ;
	uartCFG.P_IRQ_CallBack = UART_IRQ_Callback ;
	uartCFG.parity =USART_Paratiy_NONE ;
	uartCFG.PayLoad_Length = USART_Payload_Length_8B;
	uartCFG.stopBits = USART_StopBits_ONE;
	uartCFG.USART_Mode =USART_Mode_TX_RX ;
	MCAL_UART_Init(USART1,&uartCFG);
	MCAL_UART_GPIO_set_pins(USART1);
	while (1)
	{

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
void UART_IRQ_Callback (void)
{
	MCAL_UART_ReceiveData(USART1,&ch, Disable);
	MCAL_UART_SendData(USART1,&ch, Enable);
}


