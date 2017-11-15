#include "stm32f10x.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

void RCC_Init (void);
void MCO_out (void);
void GPIO_Init (void);

void vTaskLed1 (void *argument);
void vTaskLed2 (void *argument);

int main(void){		
	
	RCC_Init();
	MCO_out();
	GPIO_Init();
	
	xTaskCreate(vTaskLed1, "LED1", 32, NULL, 1, NULL);
	xTaskCreate(vTaskLed2, "LED2", 32, NULL, 1, NULL);
	
	vTaskStartScheduler();
	
	while(1)
	{
				
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

	GPIOC->CRH &= ~GPIO_CRH_CNF8;
	GPIOC->CRH |= GPIO_CRH_MODE8_0;
	
	GPIOC->CRH &= ~GPIO_CRH_CNF9;
	GPIOC->CRH |= GPIO_CRH_MODE9_0;
	
}

void vTaskLed1 (void *argument){
	
	while(1)
	{
		
		GPIOC->BSRR |= GPIO_BSRR_BS8;
		vTaskDelay(1000);
		GPIOC->BSRR |= GPIO_BSRR_BR8;
		vTaskDelay(1000);
		
	}
	
}

void vTaskLed2 (void *argument){
	
	while(1)
	{
	
		GPIOC->BSRR |= GPIO_BSRR_BR9;
		vTaskDelay(1000);
		GPIOC->BSRR |= GPIO_BSRR_BS9;
		vTaskDelay(1000);
		
	}
	
}






