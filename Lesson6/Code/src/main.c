#include "stm32f10x.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

void RCC_Init (void);
void MCO_out (void);
void GPIO_Init (void);
void UART_Init (void);
void USART1_Send (char chr);
void USART1_Send_String (char* str);
void PWM_Init (void);

void vTaskButtonUser (void *argument);

int main(void){		
	
	RCC_Init();
	MCO_out();
	GPIO_Init();
	UART_Init();
	PWM_Init();
	
	xTaskCreate(vTaskButtonUser, "LED1", 32, NULL, 1, NULL);
	
	vTaskStartScheduler();
	
	while(1)
	{
				
	}
	
}

/*******************************************************************************************************/

void vTaskButtonUser (void *argument){
	
	uint16_t i;
	
	while(1)
	{
		
		TIM2->CCR2 = i;
		i++;
		vTaskDelay(10);
		
		if (i==500){i=0;}
		
	}
	
}

/*******************************************************************************************************/

void RCC_Init (void){
	
	RCC->CR |= ((uint32_t)RCC_CR_HSEON); 												// Enable HSE
	while (!(RCC->CR & RCC_CR_HSERDY));													// Ready start HSE		
	
	FLASH->ACR = FLASH_ACR_PRFTBE | FLASH_ACR_LATENCY;					// Cloclk Flash memory
	
	RCC->CFGR |= RCC_CFGR_HPRE_DIV1;														// AHB = SYSCLK/1
	RCC->CFGR |= RCC_CFGR_PPRE1_DIV1;														// APB1 = HCLK/1
	RCC->CFGR |= RCC_CFGR_PPRE2_DIV1;														// APB2 = HCLK/1
	
	RCC->CFGR &= ~RCC_CFGR_PLLMULL;               							// clear PLLMULL bits
	RCC->CFGR &= ~RCC_CFGR_PLLSRC;															// clearn PLLSRC bits
	RCC->CFGR &= ~RCC_CFGR_PLLXTPRE;														// clearn PLLXTPRE bits
	
	RCC->CFGR |= RCC_CFGR_PLLSRC_PREDIV1; 											// source HSE
	RCC->CFGR |= RCC_CFGR_PLLXTPRE_PREDIV1_Div2; 								// source HSE/2 = 4 MHz
	RCC->CFGR |= RCC_CFGR_PLLMULL6; 														// PLL x6: clock = 4 MHz * 6 = 24 MHz
	
	RCC->CR |= RCC_CR_PLLON;                      							// enable PLL
	while((RCC->CR & RCC_CR_PLLRDY) == 0) {}      							// wait till PLL is ready
	
	RCC->CFGR &= ~RCC_CFGR_SW;                   							 	// clear SW bits
  RCC->CFGR |= RCC_CFGR_SW_PLL;                 							// select source SYSCLK = PLL
	while((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_1) {} 			// wait till PLL is used
	
}

void MCO_out (void){
	
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;                       	// enable clock for port A
	
	GPIOA->CRH &= ~GPIO_CRH_CNF8_0;															// setting out alternative push-pull for PA8
	GPIOA->CRH |= GPIO_CRH_CNF8_1;
	GPIOA->CRH |= (GPIO_CRH_MODE8_0 | GPIO_CRH_MODE8_1);				// gpio speed 50 MHz
	
	RCC->CFGR |= RCC_CFGR_MCO_SYSCLK;														// select source clokc SYSCLK
	
}

void GPIO_Init (void){
	
	RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;                       	// enable clock for port A

	GPIOC->CRH &= ~GPIO_CRH_CNF8;
	GPIOC->CRH |= GPIO_CRH_MODE8_0;
	
	GPIOC->CRH &= ~GPIO_CRH_CNF9;
	GPIOC->CRH |= GPIO_CRH_MODE9_0;
	
	GPIOC->CRL &= ~GPIO_CRL_CNF0;
	GPIOC->CRL &= ~GPIO_CRL_MODE0;
	
}

void UART_Init (void){
	
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

void USART1_Send (char chr){
	
	while (!(USART1->SR & USART_SR_TC));
	USART1->DR = chr;
	
}

void USART1_Send_String (char* str){
	
	uint8_t i = 0;
	
	while(str[i])
	USART1_Send (str[i++]);
	
}

void USART1_IRQHandler (void){
	
	if (USART1->SR & USART_SR_RXNE){
		
		USART1->SR &= ~USART_SR_RXNE;
		
		if (USART1->DR == '0'){
			
			USART1_Send_String ("OFF\r\n");
			GPIOC->BSRR |= GPIO_BSRR_BR8;
			
		}
		
		if (USART1->DR == '1'){
			
			USART1_Send_String ("ON\r\n");
			GPIOC->BSRR |= GPIO_BSRR_BS8;
			
		}
		
	}
	
}

void PWM_Init (void){
	
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





