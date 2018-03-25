#include "DisplayLTDC.h"

/******************************************************************************************************/
/****************************************** Base init LTDC ********************************************/

void InitGpioLTDC (void) {

	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;		// Enable clock port A
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;		// Enable clock port B
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;		// Enable clock port C
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;		// Enable clock port D
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN;		// Enable clock port E
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOFEN;		// Enable clock port F
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOGEN;		// Enable clock port G
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOHEN;		// Enable clock port H
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOJEN;		// Enable clock port J
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOKEN;		// Enable clock port K


/***************** PE4 -> LTDC B0 *****************/

	GPIOE->MODER   &= ~GPIO_MODER_MODER4;
	GPIOE->MODER   |= GPIO_MODER_MODER4_1;		// Alternative PP
	GPIOE->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR4;	// Very high speed

/***************** PJ13 -> LTDC B1 ****************/

	GPIOJ->MODER   &= ~GPIO_MODER_MODER13;
	GPIOJ->MODER   |= GPIO_MODER_MODER13_1;		// Alternative PP
	GPIOJ->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR13;	// Very high speed

/***************** PJ14 -> LTDC B2 *****************/

	GPIOJ->MODER   &= ~GPIO_MODER_MODER14;
	GPIOJ->MODER   |= GPIO_MODER_MODER14_1;		// Alternative PP
	GPIOJ->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR14;	// Very high speed

/***************** PJ15 -> LTDC B3 *****************/

	GPIOJ->MODER   &= ~GPIO_MODER_MODER15;
	GPIOJ->MODER   |= GPIO_MODER_MODER15_1;		// Alternative PP
	GPIOJ->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR15;	// Very high speed

/***************** PG12 -> LTDC B4 *****************/

	GPIOG->MODER   &= ~GPIO_MODER_MODER12;
	GPIOG->MODER   |= GPIO_MODER_MODER12_1;		// Alternative PP
	GPIOG->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR12;	// Very high speed

/***************** PK4 -> LTDC B5 *****************/

	GPIOK->MODER   &= ~GPIO_MODER_MODER4;
	GPIOK->MODER   |= GPIO_MODER_MODER4_1;		// Alternative PP
	GPIOK->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR4;	// Very high speed

/***************** PK5 -> LTDC B6 *****************/

	GPIOK->MODER   &= ~GPIO_MODER_MODER5;
	GPIOK->MODER   |= GPIO_MODER_MODER5_1;		// Alternative PP
	GPIOK->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR5;	// Very high speed

/***************** PK6 -> LTDC B7 *****************/

	GPIOK->MODER   &= ~GPIO_MODER_MODER6;
	GPIOK->MODER   |= GPIO_MODER_MODER6_1;		// Alternative PP
	GPIOK->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR6;	// Very high speed

/***********************************************************************************/
/***********************************************************************************/

/***************** PI15 -> LTDC R0 *****************/

	GPIOI->MODER   &= ~GPIO_MODER_MODER15;
	GPIOI->MODER   |= GPIO_MODER_MODER15_1;		// Alternative PP
	GPIOI->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR15;	// Very high speed

/***************** PJ0 -> LTDC R1 *****************/

	GPIOJ->MODER   &= ~GPIO_MODER_MODER0;
	GPIOJ->MODER   |= GPIO_MODER_MODER0_1;		// Alternative PP
	GPIOJ->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR0;	// Very high speed

/***************** PJ1 -> LTDC R2 *****************/

	GPIOJ->MODER   &= ~GPIO_MODER_MODER1;
	GPIOJ->MODER   |= GPIO_MODER_MODER1_1;		// Alternative PP
	GPIOJ->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR1;	// Very high speed

/***************** PJ2 -> LTDC R3 *****************/

	GPIOJ->MODER   &= ~GPIO_MODER_MODER2;
	GPIOJ->MODER   |= GPIO_MODER_MODER2_1;		// Alternative PP
	GPIOJ->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR2;	// Very high speed

/***************** PJ3 -> LTDC R4 *****************/

	GPIOJ->MODER   &= ~GPIO_MODER_MODER3;
	GPIOJ->MODER   |= GPIO_MODER_MODER3_1;		// Alternative PP
	GPIOJ->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR3;	// Very high speed

/***************** PJ4 -> LTDC R5 *****************/

	GPIOJ->MODER   &= ~GPIO_MODER_MODER4;
	GPIOJ->MODER   |= GPIO_MODER_MODER4_1;		// Alternative PP
	GPIOJ->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR4;	// Very high speed

/***************** PJ5 -> LTDC R6 *****************/

	GPIOJ->MODER   &= ~GPIO_MODER_MODER5;
	GPIOJ->MODER   |= GPIO_MODER_MODER5_1;		// Alternative PP
	GPIOJ->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR5;	// Very high speed

/***************** PJ6 -> LTDC R7 *****************/

	GPIOJ->MODER   &= ~GPIO_MODER_MODER6;
	GPIOJ->MODER   |= GPIO_MODER_MODER6_1;		// Alternative PP
	GPIOJ->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR6;	// Very high speed

/***********************************************************************************/
/***********************************************************************************/

/***************** PJ7 -> LTDC G0 *****************/

	GPIOJ->MODER   &= ~GPIO_MODER_MODER7;
	GPIOJ->MODER   |= GPIO_MODER_MODER7_1;		// Alternative PP
	GPIOJ->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR7;	// Very high speed

/***************** PJ8 -> LTDC G1 *****************/

	GPIOJ->MODER   &= ~GPIO_MODER_MODER8;
	GPIOJ->MODER   |= GPIO_MODER_MODER8_1;		// Alternative PP
	GPIOJ->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR8;	// Very high speed

/***************** PJ9 -> LTDC G2 *****************/

	GPIOJ->MODER   &= ~GPIO_MODER_MODER9;
	GPIOJ->MODER   |= GPIO_MODER_MODER9_1;		// Alternative PP
	GPIOJ->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR9;	// Very high speed

/***************** PJ10 -> LTDC G3 *****************/

	GPIOJ->MODER   &= ~GPIO_MODER_MODER10;
	GPIOJ->MODER   |= GPIO_MODER_MODER10_1;		// Alternative PP
	GPIOJ->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR10;	// Very high speed

/***************** PJ11 -> LTDC G4 *****************/

	GPIOJ->MODER   &= ~GPIO_MODER_MODER11;
	GPIOJ->MODER   |= GPIO_MODER_MODER11_1;		// Alternative PP
	GPIOJ->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR11;	// Very high speed

/***************** PK0 -> LTDC G5 *****************/

	GPIOK->MODER   &= ~GPIO_MODER_MODER0;
	GPIOK->MODER   |= GPIO_MODER_MODER0_1;		// Alternative PP
	GPIOK->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR0;	// Very high speed

/***************** PK1 -> LTDC G6 *****************/

	GPIOK->MODER   &= ~GPIO_MODER_MODER1;
	GPIOK->MODER   |= GPIO_MODER_MODER1_1;		// Alternative PP
	GPIOK->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR1;	// Very high speed

/***************** PK2 -> LTDC G7 *****************/

	GPIOK->MODER   &= ~GPIO_MODER_MODER2;
	GPIOK->MODER   |= GPIO_MODER_MODER2_1;		// Alternative PP
	GPIOK->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR2;	// Very high speed

/***********************************************************************************/
/***********************************************************************************/

/***************** PI9 -> LTDC VSYNC *****************/

	GPIOI->MODER   &= ~GPIO_MODER_MODER9;
	GPIOI->MODER   |= GPIO_MODER_MODER9_1;		// Alternative PP
	GPIOI->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR9;	// Very high speed

/***************** PI10 -> LTDC HSYNC *****************/

	GPIOI->MODER   &= ~GPIO_MODER_MODER10;
	GPIOI->MODER   |= GPIO_MODER_MODER10_1;		// Alternative PP
	GPIOI->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR10;	// Very high speed

/***************** PI14 -> LTDC CLK *****************/

	GPIOI->MODER   &= ~GPIO_MODER_MODER14;
	GPIOI->MODER   |= GPIO_MODER_MODER14_1;		// Alternative PP
	GPIOI->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR14;	// Very high speed

/***************** PK7 -> LTDC DE *****************/

	GPIOK->MODER   &= ~GPIO_MODER_MODER0;
	GPIOK->MODER   |= GPIO_MODER_MODER0_1;		// Alternative PP
	GPIOK->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR0;	// Very high speed

/***********************************************************************************/
/***********************************************************************************/

/***************** PK3 -> LTDC LED *****************/

	GPIOK->MODER &= ~GPIO_MODER_MODER3;
	GPIOK->MODER |= GPIO_MODER_MODER3_0;		// Output PP

/***************** PI12 -> LTDC DISP *****************/

	GPIOI->MODER &= ~GPIO_MODER_MODER12;
	GPIOI->MODER |= GPIO_MODER_MODER12_0;		// Output PP

}

void DisplayEnable (uint8_t status) {

	if (status != 0)
	{
		GPIOI->BSRR |= GPIO_BSRR_BS_12;
	}
	else
	{
		GPIOI->BSRR |= GPIO_BSRR_BR_12;
	}

}

void DisplayLED (uint8_t status) {

	if (status != 0)
	{
		GPIOK->BSRR |= GPIO_BSRR_BS_3;
	}
	else
	{
		GPIOK->BSRR |= GPIO_BSRR_BR_3;
	}

}

/******************************************************************************************************/
/******************************************************************************************************/






