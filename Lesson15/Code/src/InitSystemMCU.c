#include "InitSystemMCU.h"

/******************************* RCC ********************************/

/******************************* GPIO *******************************/

void InitBaseGPIO (void) {

	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOIEN;		// Enable clock port I

/***************** PI1 -> LED1 ******************/

	GPIOI->MODER &= ~GPIO_MODER_MODER1;
	GPIOI->MODER |= GPIO_MODER_MODER1_0;		// Output PP

}


