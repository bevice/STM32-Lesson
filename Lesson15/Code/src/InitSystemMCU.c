#include "InitSystemMCU.h"

/******************************* RCC ********************************/

void StartInitClock (void) {

	RCC->CR |= RCC_CR_HSEON; 																				// Enable HSE
	while (!(RCC->CR & RCC_CR_HSERDY));

	FLASH->ACR |= FLASH_ACR_LATENCY_5WS;

	RCC->PLLCFGR = 0x00;
	RCC->PLLCFGR |= RCC_PLLCFGR_PLLM_0 | RCC_PLLCFGR_PLLM_3 | RCC_PLLCFGR_PLLM_4; 							// Div for HSE = 25
	RCC->PLLCFGR |= RCC_PLLCFGR_PLLN_4 | RCC_PLLCFGR_PLLN_5 | RCC_PLLCFGR_PLLN_7 | RCC_PLLCFGR_PLLN_8;		// PLL mult x432
	RCC->PLLCFGR |= RCC_PLLCFGR_PLLSRC;																		// Source HSE

	RCC->CR |= RCC_CR_PLLON;
	while((RCC->CR & RCC_CR_PLLRDY) == 0){}

	RCC->CFGR &= ~RCC_CFGR_SW;
	RCC->CFGR |= RCC_CFGR_SW_PLL; 																			// Select source SYSCLK = PLL
	while((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_1) {} 													// Wait till PLL is used

	RCC->PLLSAICFGR |= RCC_PLLSAICFGR_PLLSAIN_6 | RCC_PLLSAICFGR_PLLSAIN_7;									// PLLSAI mult = 192
	RCC->PLLSAICFGR |= RCC_PLLSAICFGR_PLLSAIR_0 | RCC_PLLSAICFGR_PLLSAIR_2;									// PLLSAI Div = 5
	RCC->DCKCFGR1 	|= RCC_DCKCFGR1_PLLSAIDIVR_0;															// LTDC Div = 4
	RCC->DCKCFGR1 	&= ~RCC_DCKCFGR1_PLLSAIDIVR_1;

	RCC->CR |= RCC_CR_PLLSAION;
	while ((RCC->CR & RCC_CR_PLLSAIRDY) == 0) {}

}

void EnableOutputMCO (void) {

	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;						// Enable clock port I

	GPIOA->MODER   &= ~GPIO_MODER_MODER8;
	GPIOA->MODER   |= GPIO_MODER_MODER8_1;						// Alternative PP
	GPIOA->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR8;					// Very high speed

	RCC->CFGR |= RCC_CFGR_MCO1;									// Source PLL
	RCC->CFGR &= ~RCC_CFGR_MCO1PRE_0;							// Div = 4
	RCC->CFGR |= RCC_CFGR_MCO1PRE_1 | RCC_CFGR_MCO1PRE_2;

}

/******************************* GPIO *******************************/

void InitBaseGPIO (void) {

	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOIEN;		// Enable clock port I

/***************** PI1 -> LED1 ******************/

	GPIOI->MODER &= ~GPIO_MODER_MODER1;
	GPIOI->MODER |= GPIO_MODER_MODER1_0;		// Output PP

}

void LED1 (uint8_t status) {

	if (status != 0)
	{
		GPIOI->BSRR |= GPIO_BSRR_BS_1;
	}
	else
	{
		GPIOI->BSRR |= GPIO_BSRR_BR_1;
	}
}











