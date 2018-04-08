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

	GPIOE->AFR[0] &= ~GPIO_AFRL_AFRL4_0;
	GPIOE->AFR[0] |= GPIO_AFRL_AFRL4_1 | GPIO_AFRL_AFRL4_2 | GPIO_AFRL_AFRL4_3;		// Alternative function AF14 - LTDC

/***************** PJ13 -> LTDC B1 ****************/

	GPIOJ->MODER   &= ~GPIO_MODER_MODER13;
	GPIOJ->MODER   |= GPIO_MODER_MODER13_1;		// Alternative PP
	GPIOJ->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR13;	// Very high speed

	GPIOJ->AFR[1] &= ~GPIO_AFRH_AFRH5_0;
	GPIOJ->AFR[1] |= GPIO_AFRH_AFRH5_1 | GPIO_AFRH_AFRH5_2 | GPIO_AFRH_AFRH5_3;		// Alternative function AF14 - LTDC

/***************** PJ14 -> LTDC B2 *****************/

	GPIOJ->MODER   &= ~GPIO_MODER_MODER14;
	GPIOJ->MODER   |= GPIO_MODER_MODER14_1;		// Alternative PP
	GPIOJ->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR14;	// Very high speed

	GPIOJ->AFR[1] &= ~GPIO_AFRH_AFRH6_0;
	GPIOJ->AFR[1] |= GPIO_AFRH_AFRH6_1 | GPIO_AFRH_AFRH6_2 | GPIO_AFRH_AFRH6_3;		// Alternative function AF14 - LTDC

/***************** PJ15 -> LTDC B3 *****************/

	GPIOJ->MODER   &= ~GPIO_MODER_MODER15;
	GPIOJ->MODER   |= GPIO_MODER_MODER15_1;		// Alternative PP
	GPIOJ->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR15;	// Very high speed

	GPIOJ->AFR[1] &= ~GPIO_AFRH_AFRH7_0;
	GPIOJ->AFR[1] |= GPIO_AFRH_AFRH7_1 | GPIO_AFRH_AFRH7_2 | GPIO_AFRH_AFRH7_3;		// Alternative function AF14 - LTDC

/***************** PG12 -> LTDC B4 *****************/

	GPIOG->MODER   &= ~GPIO_MODER_MODER12;
	GPIOG->MODER   |= GPIO_MODER_MODER12_1;		// Alternative PP
	GPIOG->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR12;	// Very high speed

	GPIOG->AFR[1] &= ~(GPIO_AFRH_AFRH5_1 | GPIO_AFRH_AFRH5_2);
	GPIOG->AFR[1] |= GPIO_AFRH_AFRH5_0 | GPIO_AFRH_AFRH5_3;							// Alternative function AF9 - LTDC

/***************** PK4 -> LTDC B5 *****************/

	GPIOK->MODER   &= ~GPIO_MODER_MODER4;
	GPIOK->MODER   |= GPIO_MODER_MODER4_1;		// Alternative PP
	GPIOK->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR4;	// Very high speed

	GPIOK->AFR[0] &= ~GPIO_AFRL_AFRL4_0;
	GPIOK->AFR[0] |= GPIO_AFRL_AFRL4_1 | GPIO_AFRL_AFRL4_2 | GPIO_AFRL_AFRL4_3;		// Alternative function AF14 - LTDC

/***************** PK5 -> LTDC B6 *****************/

	GPIOK->MODER   &= ~GPIO_MODER_MODER5;
	GPIOK->MODER   |= GPIO_MODER_MODER5_1;		// Alternative PP
	GPIOK->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR5;	// Very high speed

	GPIOK->AFR[0] &= ~GPIO_AFRL_AFRL5_0;
	GPIOK->AFR[0] |= GPIO_AFRL_AFRL5_1 | GPIO_AFRL_AFRL5_2 | GPIO_AFRL_AFRL5_3;		// Alternative function AF14 - LTDC

/***************** PK6 -> LTDC B7 *****************/

	GPIOK->MODER   &= ~GPIO_MODER_MODER6;
	GPIOK->MODER   |= GPIO_MODER_MODER6_1;		// Alternative PP
	GPIOK->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR6;	// Very high speed

	GPIOK->AFR[0] &= ~GPIO_AFRL_AFRL6_0;
	GPIOK->AFR[0] |= GPIO_AFRL_AFRL6_1 | GPIO_AFRL_AFRL6_2 | GPIO_AFRL_AFRL6_3;		// Alternative function AF14 - LTDC

/***********************************************************************************/
/***********************************************************************************/

/***************** PI15 -> LTDC R0 *****************/

	GPIOI->MODER   &= ~GPIO_MODER_MODER15;
	GPIOI->MODER   |= GPIO_MODER_MODER15_1;		// Alternative PP
	GPIOI->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR15;	// Very high speed

	GPIOI->AFR[1] &= ~GPIO_AFRH_AFRH7_0;
	GPIOI->AFR[1] |= GPIO_AFRH_AFRH7_1 | GPIO_AFRH_AFRH7_2 | GPIO_AFRH_AFRH7_3;		// Alternative function AF14 - LTDC

/***************** PJ0 -> LTDC R1 *****************/

	GPIOJ->MODER   &= ~GPIO_MODER_MODER0;
	GPIOJ->MODER   |= GPIO_MODER_MODER0_1;		// Alternative PP
	GPIOJ->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR0;	// Very high speed

	GPIOJ->AFR[0] &= ~GPIO_AFRL_AFRL0_0;
	GPIOJ->AFR[0] |= GPIO_AFRL_AFRL0_1 | GPIO_AFRL_AFRL0_2 | GPIO_AFRL_AFRL0_3;		// Alternative function AF14 - LTDC

/***************** PJ1 -> LTDC R2 *****************/

	GPIOJ->MODER   &= ~GPIO_MODER_MODER1;
	GPIOJ->MODER   |= GPIO_MODER_MODER1_1;		// Alternative PP
	GPIOJ->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR1;	// Very high speed

	GPIOJ->AFR[0] &= ~GPIO_AFRL_AFRL1_0;
	GPIOJ->AFR[0] |= GPIO_AFRL_AFRL1_1 | GPIO_AFRL_AFRL1_2 | GPIO_AFRL_AFRL1_3;		// Alternative function AF14 - LTDC

/***************** PJ2 -> LTDC R3 *****************/

	GPIOJ->MODER   &= ~GPIO_MODER_MODER2;
	GPIOJ->MODER   |= GPIO_MODER_MODER2_1;		// Alternative PP
	GPIOJ->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR2;	// Very high speed

	GPIOJ->AFR[0] &= ~GPIO_AFRL_AFRL2_0;
	GPIOJ->AFR[0] |= GPIO_AFRL_AFRL2_1 | GPIO_AFRL_AFRL2_2 | GPIO_AFRL_AFRL2_3;		// Alternative function AF14 - LTDC

/***************** PJ3 -> LTDC R4 *****************/

	GPIOJ->MODER   &= ~GPIO_MODER_MODER3;
	GPIOJ->MODER   |= GPIO_MODER_MODER3_1;		// Alternative PP
	GPIOJ->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR3;	// Very high speed

	GPIOJ->AFR[0] &= ~GPIO_AFRL_AFRL3_0;
	GPIOJ->AFR[0] |= GPIO_AFRL_AFRL3_1 | GPIO_AFRL_AFRL3_2 | GPIO_AFRL_AFRL3_3;		// Alternative function AF14 - LTDC

/***************** PJ4 -> LTDC R5 *****************/

	GPIOJ->MODER   &= ~GPIO_MODER_MODER4;
	GPIOJ->MODER   |= GPIO_MODER_MODER4_1;		// Alternative PP
	GPIOJ->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR4;	// Very high speed

	GPIOJ->AFR[0] &= ~GPIO_AFRL_AFRL4_0;
	GPIOJ->AFR[0] |= GPIO_AFRL_AFRL4_1 | GPIO_AFRL_AFRL4_2 | GPIO_AFRL_AFRL4_3;		// Alternative function AF14 - LTDC

/***************** PJ5 -> LTDC R6 *****************/

	GPIOJ->MODER   &= ~GPIO_MODER_MODER5;
	GPIOJ->MODER   |= GPIO_MODER_MODER5_1;		// Alternative PP
	GPIOJ->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR5;	// Very high speed

	GPIOJ->AFR[0] &= ~GPIO_AFRL_AFRL5_0;
	GPIOJ->AFR[0] |= GPIO_AFRL_AFRL5_1 | GPIO_AFRL_AFRL5_2 | GPIO_AFRL_AFRL5_3;		// Alternative function AF14 - LTDC

/***************** PJ6 -> LTDC R7 *****************/

	GPIOJ->MODER   &= ~GPIO_MODER_MODER6;
	GPIOJ->MODER   |= GPIO_MODER_MODER6_1;		// Alternative PP
	GPIOJ->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR6;	// Very high speed

	GPIOJ->AFR[0] &= ~GPIO_AFRL_AFRL6_0;
	GPIOJ->AFR[0] |= GPIO_AFRL_AFRL6_1 | GPIO_AFRL_AFRL6_2 | GPIO_AFRL_AFRL6_3;		// Alternative function AF14 - LTDC

/***********************************************************************************/
/***********************************************************************************/

/***************** PJ7 -> LTDC G0 *****************/

	GPIOJ->MODER   &= ~GPIO_MODER_MODER7;
	GPIOJ->MODER   |= GPIO_MODER_MODER7_1;		// Alternative PP
	GPIOJ->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR7;	// Very high speed

	GPIOJ->AFR[0] &= ~GPIO_AFRL_AFRL7_0;
	GPIOJ->AFR[0] |= GPIO_AFRL_AFRL7_1 | GPIO_AFRL_AFRL7_2 | GPIO_AFRL_AFRL7_3;		// Alternative function AF14 - LTDC

/***************** PJ8 -> LTDC G1 *****************/

	GPIOJ->MODER   &= ~GPIO_MODER_MODER8;
	GPIOJ->MODER   |= GPIO_MODER_MODER8_1;		// Alternative PP
	GPIOJ->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR8;	// Very high speed

	GPIOJ->AFR[1] &= ~GPIO_AFRH_AFRH0_0;
	GPIOJ->AFR[1] |= GPIO_AFRH_AFRH0_1 | GPIO_AFRH_AFRH0_2 | GPIO_AFRH_AFRH0_3;		// Alternative function AF14 - LTDC

/***************** PJ9 -> LTDC G2 *****************/

	GPIOJ->MODER   &= ~GPIO_MODER_MODER9;
	GPIOJ->MODER   |= GPIO_MODER_MODER9_1;		// Alternative PP
	GPIOJ->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR9;	// Very high speed

	GPIOJ->AFR[1] &= ~GPIO_AFRH_AFRH1_0;
	GPIOJ->AFR[1] |= GPIO_AFRH_AFRH1_1 | GPIO_AFRH_AFRH1_2 | GPIO_AFRH_AFRH1_3;		// Alternative function AF14 - LTDC

/***************** PJ10 -> LTDC G3 *****************/

	GPIOJ->MODER   &= ~GPIO_MODER_MODER10;
	GPIOJ->MODER   |= GPIO_MODER_MODER10_1;		// Alternative PP
	GPIOJ->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR10;	// Very high speed

	GPIOJ->AFR[1] &= ~GPIO_AFRH_AFRH2_0;
	GPIOJ->AFR[1] |= GPIO_AFRH_AFRH2_1 | GPIO_AFRH_AFRH2_2 | GPIO_AFRH_AFRH2_3;		// Alternative function AF14 - LTDC

/***************** PJ11 -> LTDC G4 *****************/

	GPIOJ->MODER   &= ~GPIO_MODER_MODER11;
	GPIOJ->MODER   |= GPIO_MODER_MODER11_1;		// Alternative PP
	GPIOJ->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR11;	// Very high speed

	GPIOJ->AFR[1] &= ~GPIO_AFRH_AFRH3_0;
	GPIOJ->AFR[1] |= GPIO_AFRH_AFRH3_1 | GPIO_AFRH_AFRH3_2 | GPIO_AFRH_AFRH3_3;		// Alternative function AF14 - LTDC

/***************** PK0 -> LTDC G5 *****************/

	GPIOK->MODER   &= ~GPIO_MODER_MODER0;
	GPIOK->MODER   |= GPIO_MODER_MODER0_1;		// Alternative PP
	GPIOK->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR0;	// Very high speed

	GPIOK->AFR[0] &= ~GPIO_AFRL_AFRL0_0;
	GPIOK->AFR[0] |= GPIO_AFRL_AFRL0_1 | GPIO_AFRL_AFRL0_2 | GPIO_AFRL_AFRL0_3;		// Alternative function AF14 - LTDC

/***************** PK1 -> LTDC G6 *****************/

	GPIOK->MODER   &= ~GPIO_MODER_MODER1;
	GPIOK->MODER   |= GPIO_MODER_MODER1_1;		// Alternative PP
	GPIOK->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR1;	// Very high speed

	GPIOK->AFR[0] &= ~GPIO_AFRL_AFRL1_0;
	GPIOK->AFR[0] |= GPIO_AFRL_AFRL1_1 | GPIO_AFRL_AFRL1_2 | GPIO_AFRL_AFRL1_3;		// Alternative function AF14 - LTDC

/***************** PK2 -> LTDC G7 *****************/

	GPIOK->MODER   &= ~GPIO_MODER_MODER2;
	GPIOK->MODER   |= GPIO_MODER_MODER2_1;		// Alternative PP
	GPIOK->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR2;	// Very high speed

	GPIOK->AFR[0] &= ~GPIO_AFRL_AFRL2_0;
	GPIOK->AFR[0] |= GPIO_AFRL_AFRL2_1 | GPIO_AFRL_AFRL2_2 | GPIO_AFRL_AFRL2_3;		// Alternative function AF14 - LTDC

/***********************************************************************************/
/***********************************************************************************/

/***************** PI9 -> LTDC VSYNC *****************/

	GPIOI->MODER   &= ~GPIO_MODER_MODER9;
	GPIOI->MODER   |= GPIO_MODER_MODER9_1;		// Alternative PP
	GPIOI->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR9;	// Very high speed

	GPIOI->AFR[1] &= ~GPIO_AFRH_AFRH1_0;
	GPIOI->AFR[1] |= GPIO_AFRH_AFRH1_1 | GPIO_AFRH_AFRH1_2 | GPIO_AFRH_AFRH1_3;		// Alternative function AF14 - LTDC

/***************** PI10 -> LTDC HSYNC *****************/

	GPIOI->MODER   &= ~GPIO_MODER_MODER10;
	GPIOI->MODER   |= GPIO_MODER_MODER10_1;		// Alternative PP
	GPIOI->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR10;	// Very high speed

	GPIOI->AFR[1] &= ~GPIO_AFRH_AFRH2_0;
	GPIOI->AFR[1] |= GPIO_AFRH_AFRH2_1 | GPIO_AFRH_AFRH2_2 | GPIO_AFRH_AFRH2_3;		// Alternative function AF14 - LTDC

/***************** PI14 -> LTDC CLK *****************/

	GPIOI->MODER   &= ~GPIO_MODER_MODER14;
	GPIOI->MODER   |= GPIO_MODER_MODER14_1;		// Alternative PP
	GPIOI->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR14;	// Very high speed

	GPIOI->AFR[1] &= ~GPIO_AFRH_AFRH7_0;
	GPIOI->AFR[1] |= GPIO_AFRH_AFRH7_1 | GPIO_AFRH_AFRH7_2 | GPIO_AFRH_AFRH7_3;		// Alternative function AF14 - LTDC

/***************** PK7 -> LTDC DE *****************/

	GPIOK->MODER   &= ~GPIO_MODER_MODER0;
	GPIOK->MODER   |= GPIO_MODER_MODER0_1;		// Alternative PP
	GPIOK->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR0;	// Very high speed

	GPIOK->AFR[0] &= ~GPIO_AFRL_AFRL7_0;
	GPIOK->AFR[0] |= GPIO_AFRL_AFRL7_1 | GPIO_AFRL_AFRL7_2 | GPIO_AFRL_AFRL7_3;		// Alternative function AF14 - LTDC

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






