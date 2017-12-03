/*************************************************** Library ******************************************************************/

#include "libUART.h"

/************************************************ Use functions ***************************************************************/

void InitUART (void){
	
	RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;    
  RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;
	
	GPIOA->CRH |= GPIO_CRH_CNF9_1;
	GPIOA->CRH |= GPIO_CRH_MODE9;
	
	GPIOA->CRH |= GPIO_CRH_CNF10_0;
	GPIOA->CRH &= ~GPIO_CRH_MODE10;
	
	USART1->BRR = 0x9C4;
	
	USART1->CR1 |= USART_CR1_TE;
	USART1->CR1 |= USART_CR1_RE;
	USART1->CR1 |= USART_CR1_UE;
	
	USART1->CR1 |= USART_CR1_RXNEIE;	
	NVIC_EnableIRQ(USART1_IRQn);
	
}

void SendUSART1 (char chr){
	
	while (!(USART1->SR & USART_SR_TC));
	USART1->DR = chr;
	
}

void SendStringUSART1 (char* str){
	
	uint8_t i = 0;
	
	while(str[i])
	SendUSART1 (str[i++]);
	
}

void SendDataUSART1 (uint8_t data){

	while (!(USART1->SR & USART_SR_TC));
	USART1->DR = data;
	
}
