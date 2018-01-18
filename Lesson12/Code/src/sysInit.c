/*************************************************** Library ******************************************************************/

#include "sysInit.h"

/************************************************ Use functions ***************************************************************/

void InitRCC (void){
	
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

void GenMCO (void){
	
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;                       	// enable clock for port A
	
	GPIOA->CRH &= ~GPIO_CRH_CNF8_0;															// setting out alternative push-pull for PA8
	GPIOA->CRH |= GPIO_CRH_CNF8_1;
	GPIOA->CRH |= (GPIO_CRH_MODE8_0 | GPIO_CRH_MODE8_1);				// gpio speed 50 MHz
	
	RCC->CFGR |= RCC_CFGR_MCO_SYSCLK;														// select source clokc SYSCLK
	
}

void InitGPIO (void){
	
	RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;                       	// enable clock for port A

	GPIOC->CRH &= ~GPIO_CRH_CNF8;
	GPIOC->CRH |= GPIO_CRH_MODE8_0;
	
	GPIOC->CRH &= ~GPIO_CRH_CNF9;
	GPIOC->CRH |= GPIO_CRH_MODE9_0;
	
	GPIOC->CRL &= ~GPIO_CRL_CNF0;
	GPIOC->CRL &= ~GPIO_CRL_MODE0;
	
}

/************************************************ Flash memory ***************************************************************/

void flashUnlock (void){
	
	FLASH->KEYR = INT_FLASH_KEY1;
	FLASH->KEYR = INT_FLASH_KEY2;
	
}

void flashLock (void){
	
	FLASH->CR |= FLASH_CR_LOCK;
	
}

void flashAllErase (void){
	
	FLASH->CR |= FLASH_CR_MER;
	FLASH->CR |= FLASH_CR_STRT;
	
}

uint32_t flashReadData (uint32_t address){
	
	return (*(__IO uint32_t*) address);
	
}

void flashWriteData(uint32_t address, uint32_t data) {

	FLASH->CR |= FLASH_CR_PG;

	while((FLASH->SR & FLASH_SR_BSY)!=0);

	*(__IO uint16_t*)address = (uint16_t)data;

	while((FLASH->SR & FLASH_SR_BSY)!=0);

	address+=2;
	data>>=16;

	*(__IO uint16_t*)address = (uint16_t)data;

	while((FLASH->SR & FLASH_SR_BSY)!=0);

	FLASH->CR &= ~(FLASH_CR_PG);

}

