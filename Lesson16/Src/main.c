#include "stm32f10x.h"

void InitGPIO (void);
void InitTIM2 (void);

int main(void){		
	
	InitGPIO();
	InitTIM2();
	
	while(1)
	{
		
	}
	
}

void InitGPIO (void) {

	RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;

	GPIOC->CRH &= ~GPIO_CRH_CNF8;
	GPIOC->CRH |= GPIO_CRH_MODE8_0;

	GPIOC->CRH &= ~GPIO_CRH_CNF9;
	GPIOC->CRH |= GPIO_CRH_MODE9_0;

}

void InitTIM2 (void) {

	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;							// Enable clock TIM2

	TIM2->PSC = 8000-1;											// Prescaler
	TIM2->ARR = 1000-1;											// Period

	TIM2->DIER |= TIM_DIER_UIE;									// Enable interrupt
	TIM2->CR1  |= TIM_CR1_CEN;									// Enable counter

	NVIC_EnableIRQ(TIM2_IRQn);									// Interrupt

}

void TIM2_IRQHandler (void) {

	TIM2->SR &= ~TIM_SR_UIF;

	GPIOC->ODR  ^= ~GPIO_ODR_ODR9;

}


