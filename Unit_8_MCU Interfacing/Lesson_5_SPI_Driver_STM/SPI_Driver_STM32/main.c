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
#include "STM32F103C6.h"
#include "STM32F103C6_GPIO_Driver.h"
#include "STM32F103C6_EXTRI_Driver.h"
#include "STM32F103C6_USART_Driver.h"
#include "STM32F103C6_SPI_Driver.h"
// HAL includes
#include "lcd.h"
#include "Kaypad.h"
#include "Seven_Segment.h"



#define SPI_act_as_master
//#define SPI_act_as_slave



// configuration functions
void clock_init();
void USART_configuration(void);
void SPI_Configuration(void);
void GPIO_Master_Configuration(void);
void GPIO_Slave_Configuration(void);

// callback functions
void UART1_IRQ_Callback (void);
void SPI1_IRQ_Callback (IRQ_source IR_src);


// Generic variables
uint16_t ch ;
UART_Config USART_pin_config ;
SPI_Config SPI_pin_config;
GPIO_PinConfig_t GPIO_Pin_config;





// =================== Main Function ===================================

int main(void)
{
	clock_init();

	USART_configuration();

	SPI_Configuration();

	while (1)
	{

	}
}



// ===================================================================


void clock_init()
{
	// Enable clock GPIOA
	RCC_GPIOA_CLK_EN();
	// Enable clock GPIOB
	RCC_GPIOB_CLK_EN();
	// Enable clock AFIO
	RCC_AFIO_CLK_EN();
	// Enable clock SPI
	RCC_SPI1_CLK_EN();
}


void USART_configuration(void)
{
	USART_pin_config.Baud_rate = USART_BaudRate_115200;
	USART_pin_config.HWFlowCtrl = USART_FlowCtrl_NONE ;
	USART_pin_config.IRQ_Enable = USART_IRQ_Enable_RXNEIE;
	USART_pin_config.P_IRQ_CallBack = UART1_IRQ_Callback ;
	USART_pin_config.parity =USART_Paratiy_NONE ;
	USART_pin_config.PayLoad_Length = USART_Payload_Length_8B;
	USART_pin_config.stopBits = USART_StopBits_ONE;
	USART_pin_config.USART_Mode =USART_Mode_TX_RX ;
	MCAL_UART_Init(USART1,&USART_pin_config);
}
void SPI_Configuration(void)
{
	SPI_pin_config.CLK_Phase = SPI_CLK_Phase_capture_IN_second_edge;
	SPI_pin_config.CLK_Polarity = SPI_CLK_Polarity_1_When_Idle;
	SPI_pin_config.Communication_mode = SPI_Direction_2_line_unidirectional;
	SPI_pin_config.Data_size = SPI_Data_Size_8_Bits;
	SPI_pin_config.Frame_formate = SPI_Frame_formate_MSB_First;
	SPI_pin_config.Baud_rate = SPI_Baud_rate_Fpclk_Div_8;

#ifdef SPI_act_as_master
	SPI_pin_config.Device_mode=SPI_Device_Mode_Master;
	SPI_pin_config.IRQ_Enable = SPI_IRQ_Enable_NONE;
	SPI_pin_config.P_IRQ_CallBack = NULL;
	SPI_pin_config.NSS = SPI_NSS_SW_Set;

	// configure Nss as a Software by GPIO
	GPIO_Master_Configuration();
	// NSS always high when idle
	MCAL_GPIO_WRITE_PIN(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
#endif
#ifdef SPI_act_as_slave
	SPI_pin_config.Device_mode=SPI_Device_Mode_Slave;
	SPI_pin_config.IRQ_Enable = SPI_IRQ_Enable_RXNEIE;
	SPI_pin_config.P_IRQ_CallBack = SPI1_IRQ_Callback;
	SPI_pin_config.NSS = SPI_NSS_HW_slave;

	GPIO_Slave_Configuration();
#endif


	MCAL_SPI_Init(SPI1, &SPI_pin_config);

}


void GPIO_Master_Configuration(void)
{
	GPIO_Pin_config.GPIO_PinNumber = GPIO_PIN_4;
	GPIO_Pin_config.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	GPIO_Pin_config.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_SPEED_10M;
	MCAL_GPIO_INIT(GPIOA, &GPIO_Pin_config);
}


void GPIO_Slave_Configuration()
{
	GPIO_Pin_config.GPIO_PinNumber = GPIO_PIN_4;
	GPIO_Pin_config.GPIO_MODE = GPIO_MODE_FLOATINg_INPUT;
	MCAL_GPIO_INIT(GPIOA, &GPIO_Pin_config);
}

void UART1_IRQ_Callback (void)
{
#ifdef SPI_act_as_master
	// send from USART to MCU
	MCAL_UART_ReceiveData(USART1,&ch, Enable);
	// send from MCU to the USART
	MCAL_UART_SendData(USART1,&ch, Disable);
	// make NSS low when at the start of the transmission
	MCAL_GPIO_WRITE_PIN(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
	// send to the SPI
	MCAL_SPI_ReceiveANDTransmitData(SPI1, &ch, SPI_polling_Enable);
	// make NSS high at the end of the transmission
	MCAL_GPIO_WRITE_PIN(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
#endif

#ifdef SPI_act_as_slave
	// receive from SPI
	MCAL_SPI_ReceiveData(SPI1, &ch, SPI_polling_Enable);
	// send to USART
	MCAL_UART_SendData(USART1,&ch, Enable);
#endif
}




void SPI1_IRQ_Callback (IRQ_source IR_src)
{
#ifdef SPI_act_as_slave

	if(IR_src.RXNEI)
	{
		MCAL_SPI_ReceiveData(SPI1, &ch, SPI_polling_Disable);
		MCAL_UART_SendData(USART1, &ch, Enable);
	}

#endif

}
