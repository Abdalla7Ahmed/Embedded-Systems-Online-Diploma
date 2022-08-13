#include <stdio.h>

typedef volatile unsigned int vuint32_t;

#define SYSCTL_BASE                       0x400FE000
#define GPIO_BASE                         0x40025000


#define SYSCTL_RCGC2_R                    *((vuint32_t *)(SYSCTL_BASE+0x108))
#define GPIOF_DIR_R                       *((vuint32_t *)(GPIO_BASE+0x400))
#define GPIOF_DEN_R                       *((vuint32_t *)(GPIO_BASE+0x51C))
#define GPIOF_DATA_R                      *((vuint32_t *)(GPIO_BASE+0x3FC))

int main(void)
{
	volatile int counter_delay;
	/************ Enable GPIO PORT ************/
	SYSCTL_RCGC2_R =0x00000020;        
	for(counter_delay=0;counter_delay<200;counter_delay++);
	/************ Set PF3 as output ************/
	GPIOF_DIR_R |=1<<3;      
	/************ Enable GPIO PIN ************/                       
	GPIOF_DEN_R |=1<<3;               

	while(1)
	{
		/************ set PIN 3 ************/
		GPIOF_DATA_R |=1<<3;           
		for(counter_delay=0;counter_delay<200000;counter_delay++);
	    /************ clear PIN 3 ************/
		GPIOF_DATA_R &=~(1<<3);      
		for(counter_delay=0;counter_delay<200000;counter_delay++);
	}
	return 0;
}