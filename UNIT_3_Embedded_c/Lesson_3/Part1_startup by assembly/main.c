#include<stdint.h>

typedef  volatile unsigned int vuint32_t;


#define RCC_BASE       0x40021000
#define GPIOA_BASE     0x40010800
#define RCC_PB2ENR     *((vuint32_t * )( RCC_BASE + 0x18 ))
#define GPIOA_CRH      *((vuint32_t * )( GPIOA_BASE + 0x04 ))
#define GPIOA_ODR      *((vuint32_t * )( GPIOA_BASE + 0x0c ))





typedef union
{
	vuint32_t all_fields ;
	struct
	{
		vuint32_t  reseved:13;
		vuint32_t  P_13:1;

	}PIN;

}R_ODR_t;

volatile R_ODR_t* R_ODR = (volatile R_ODR_t*)(GPIOA_BASE + 0x0c);



int main(void)
{
	int counter;
	RCC_PB2ENR |= 1<<2;
	GPIOA_CRH &= (0xff0fffff);
	GPIOA_CRH |= (0x00200000);
	while(1)
	{	
			R_ODR->PIN.P_13 = 1;	
		for(counter = 0 ;counter<500 ;counter++ );
			R_ODR->PIN.P_13 = 0;
		for(counter = 0 ;counter<500 ;counter++ );
	}
}