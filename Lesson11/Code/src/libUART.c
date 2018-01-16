/*************************************************** Library ******************************************************************/

#include "libUART.h"

/************************************************ Use functions ***************************************************************/

void InitUART (void){
	
	InitUSART1();
	InitUSART2();
	
}

/**************************************************** USART1 ******************************************************************/

void InitUSART1 (void){
	
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

/**************************************************** USART2 ******************************************************************/

void InitUSART2 (void){
	
	RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;    
  RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;
	
	GPIOA->CRL |= GPIO_CRL_CNF2_1;
	GPIOA->CRL |= GPIO_CRL_MODE2;
	
	GPIOA->CRL |= GPIO_CRL_CNF3_0;
	GPIOA->CRL &= ~GPIO_CRL_MODE3;
	
	USART2->BRR = 0x9C4;
	
	USART2->CR1 |= USART_CR1_TE;
	USART2->CR1 |= USART_CR1_RE;
	USART2->CR1 |= USART_CR1_UE;
	
	USART2->CR1 |= USART_CR1_RXNEIE;	
	NVIC_EnableIRQ(USART2_IRQn);
	
}

void SendUSART2 (char chr){
	
	while (!(USART2->SR & USART_SR_TC));
	USART2->DR = chr;
	
}

void SendStringUSART2 (char* str){
	
	uint8_t i = 0;
	
	while(str[i])
	SendUSART2 (str[i++]);
	
}

void SendDataUSART2 (uint8_t data){

	while (!(USART2->SR & USART_SR_TC));
	USART2->DR = data;
	
}









