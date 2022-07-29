

#define RCC_BASE        0x40021000
#define GPIO_BASE       0x40010800


#define RCC_APB2ENR     *(vuint32_t *)(RCC_BASE+0x18)
#define RCC_CHR         *(vuint32_t *)(GPIO_BASE+0x04)
#define RCC_ODR         *(vuint32_t *)(GPIO_BASE+0x0C)


typedef union {
	vuint32_t ALL_PORTS;
	struct {
		vuint32_t reserved :13;
		vuint32_t pin13:1;
	}Pin;
}R_ODR_t;
volatile R_ODR_t *P_ODR =(volatile R_ODR_t *) (GPIO_BASE+0x0c);



