/*************************************************** Library ******************************************************************/

#include "libPWM.h"

/************************************************ Use functions ***************************************************************/

void InitPWM (void){
	
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;   
  RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;	
	
	GPIOA->CRL &= ~GPIO_CRL_CNF1;
	GPIOA->CRL |= GPIO_CRL_CNF1_1;
	
	GPIOA->CRL &= ~GPIO_CRL_MODE1;
	GPIOA->CRL |= GPIO_CRL_MODE1;
	
	TIM2->PSC = 24 - 1;
	TIM2->ARR = 1000;
	TIM2->CCR2 = 0;
	
	TIM2->CCMR1 |= TIM_CCMR1_OC2M_1 | TIM_CCMR1_OC2M_2;
	TIM2->CCER |= TIM_CCER_CC2E;
	TIM2->CCER &= ~TIM_CCER_CC2P;
	
	TIM2->CR1 &= ~TIM_CR1_DIR;
	TIM2->CR1 |= TIM_CR1_CEN;
	
}
