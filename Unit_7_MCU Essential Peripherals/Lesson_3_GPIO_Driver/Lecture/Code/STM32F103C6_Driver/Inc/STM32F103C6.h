/*
 * STM32F103C6.h
 *
 *  Created on: Sep 15, 2022
 *      Author: Abotaleb
 */

#ifndef GPIO_DRIVERS_INCLUDE_STM32F103C6_H_
#define GPIO_DRIVERS_INCLUDE_STM32F103C6_H_
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// --------------------------------------------------
//Includes
// --------------------------------------------------
#include <stdio.h>
#include <stdint.h>
//@@@@@@@@@@@@@@@@ @@@@@@@@@@@@@@@@@@@@@

// --------------------------------------------------
//Base addresses for memories
// --------------------------------------------------
#define FLASH_MEMORY_BASE            	        0x08000000UL
#define SYSTEM_MEMORY_BASE           		    0x1FFFF000UL
#define SRAM_MEMORY_BASE             		    0x20000000UL
#define PERIEPHERALS_BASE            		    0x40000000UL
#define CORTEX_M3_INTERNAL_PERIEPHERALS_BASE    0xE0000000UL
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

// --------------------------------------------------
//Base addresses for AHB Peripherals
// --------------------------------------------------
#define RCC_BASE                              	0x40021000UL

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

// --------------------------------------------------
//Base addresses for ABB1 Peripherals
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


// --------------------------------------------------
//Base addresses for ABB2 Peripherals
// --------------------------------------------------
#define GPIOA_BASE                             0x40010800UL    	// GPIOA fully included in LQFP48 Package
#define GPIOB_BASE                             0x40010C00UL      // GPIOB fully included in LQFP48 Package
#define GPIOC_BASE                             0x40011000UL       // GPIOC Partial included in LQFP48 Package
#define GPIOD_BASE                             0x40011400UL      // GPIOD Partial included in LQFP48 Package
#define GPIOE_BASE                             0x40011800UL      // GPIOE not include in LQFP48 Package

#define EXTI_BASE                              0x40010400UL
#define AFIO_BASE                              0x40010000UL
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


// =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
// Peripheral registers
// =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
// GPIO Peripheral
typedef struct
{
	volatile uint32_t CRL  ;
	volatile uint32_t CRH  ;
	volatile uint32_t IDR  ;
	volatile uint32_t ODR  ;
	volatile uint32_t BSRR ;
	volatile uint32_t BRR  ;
	volatile uint32_t LCKR ;
}GPIO_TypeDef;

// AFIO Peripheral
typedef struct
{
	volatile uint32_t EVCR    ;
	volatile uint32_t MAPR    ;
	volatile uint32_t EXTICR1 ;
	volatile uint32_t EXTICR2 ;
	volatile uint32_t EXTICR3 ;
	volatile uint32_t EXTICR4 ;
	volatile uint32_t Reserved;
	volatile uint32_t MAPR2   ;
}AFIO_TypeDef;

// EXTRI Peripheral
typedef struct
{
	volatile uint32_t IMR   ;
	volatile uint32_t EMR   ;
	volatile uint32_t RTSR  ;
	volatile uint32_t FTSR  ;
	volatile uint32_t SWIER ;
	volatile uint32_t PR    ;
}EXTRI_TypeDef;

// RCC Peripheral
typedef struct
{
	volatile uint32_t CR       ;
	volatile uint32_t CFGR     ;
	volatile uint32_t CIR      ;
	volatile uint32_t APB2RSTR ;
	volatile uint32_t APB1RSTR ;
	volatile uint32_t AHBENR   ;
	volatile uint32_t APB2ENR  ;
	volatile uint32_t APB1ENR  ;
	volatile uint32_t BDCR     ;
	volatile uint32_t CSR      ;
}RCC_TypeDef;

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
// Peripheral Instants
// =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
#define GPIOA          (( GPIO_TypeDef *)GPIOA_BASE)
#define GPIOB          (( GPIO_TypeDef *)GPIOB_BASE)
#define GPIOC          (( GPIO_TypeDef *)GPIOC_BASE)
#define GPIOD          (( GPIO_TypeDef *)GPIOD_BASE)
#define GPIOE          (( GPIO_TypeDef *)GPIOE_BASE)


#define RCC           (( RCC_TypeDef  *)RCC_BASE )

#define AFIO          (( AFIO_TypeDef *)GPIOG_BASE)

#define EXTRI         (( EXTRI_TypeDef*)GPIOG_BASE)
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


// =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*
// Clock Enable Macros
// =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*

#define RCC_AFIO_CLK_EN()      (RCC->APB2ENR |=1<<0)
#define RCC_GPIOA_CLC_EN()     (RCC->APB2ENR |=1<<2)
#define RCC_GPIOB_CLK_EN()     (RCC->APB2ENR |=1<<3)
#define RCC_GPIOC_CLK_EN()     (RCC->APB2ENR |=1<<4)
#define RCC_GPIOD_CLK_EN()     (RCC->APB2ENR |=1<<5)
#define RCC_GPIOE_CLK_EN()     (RCC->APB2ENR |=1<<6)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


#endif /* GPIO_DRIVERS_INCLUDE_STM32F103C6_H_ */
