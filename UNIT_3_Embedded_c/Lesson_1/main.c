
#include<stdio.h>
#include"Platform_types.h"
#include"Stm32f103CX.h"

int main()
{
	RCC_APB2ENR |= 1<<2;
	RCC_CHR     &= 0xFF0FFFFF;
	RCC_CHR     &= 0x00200000;

	while(1)
	{
	P_ODR->Pin.pin13=1;      // set pin 13
  //GPIOA_ODR |= 1<<13;
	for(int i=0;i<5000;i++);    //  delay
	P_ODR->Pin.pin13=0;      // clear pin 13
  //GPIOA_ODR &= ~(1<<13);
	for(int i=0;i<5000;i++);
	}

	return 0;
}
