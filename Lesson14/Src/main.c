#include "stm32f10x.h"

void InitGPIO (void);
void InitEncoder (void);

int main(void){		
	
	InitGPIO();
	InitEncoder();
	
	while(1)
	{
		
		if (TIM3->CNT <= 50)
		{
			GPIOC->BSRR |= GPIO_BSRR_BS8;
		}
		else
		{
			GPIOC->BSRR |= GPIO_BSRR_BR8;
		}
		
		if (TIM3->CNT > 50)
		{
			GPIOC->BSRR |= GPIO_BSRR_BS9;
		}
		else
		{
			GPIOC->BSRR |= GPIO_BSRR_BR9;
		}

	}
	
}

void InitGPIO (void) {

	RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;

	GPIOC->CRH &= ~GPIO_CRH_CNF8;
	GPIOC->CRH |= GPIO_CRH_MODE8_0;

	GPIOC->CRH &= ~GPIO_CRH_CNF9;
	GPIOC->CRH |= GPIO_CRH_MODE9_0;

}

void InitEncoder (void) {

	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;							// Enable clock port A
	RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;							// Enable clock TIM3

	GPIOA->CRL &= ~(GPIO_CRL_CNF6_0 | GPIO_CRL_CNF7_0);			// Setting PA6 and PA7 input pull-up
	GPIOA->CRL |= GPIO_CRL_CNF6_1 | GPIO_CRL_CNF7_1;
	GPIOA->ODR |= GPIO_ODR_ODR6 | GPIO_ODR_ODR7;

	TIM3->CCMR1 |= TIM_CCMR1_IC1F | TIM_CCMR1_IC2F;				// Set filter sampling
	TIM3->CCMR1 |= TIM_CCMR1_CC1S_0 | TIM_CCMR1_CC2S_0;			// Enable TI1 and TI2
	TIM3->CCER  &= ~(TIM_CCER_CC1P | TIM_CCER_CC2P); 			// Polarity front signal
	TIM3->SMCR  |= TIM_SMCR_SMS_0 | TIM_SMCR_SMS_1;				// Counter on both channel

	TIM3->ARR = 100;											// Period
	TIM3->CR1 |= TIM_CR1_CEN; 									// Enable counter

	TIM3->CNT = 0;

}


