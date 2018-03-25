#pragma once

#include "stm32f7xx.h"

/****************************************** Defines ********************************************/

#define ON		(uint8_t(0x01))
#define OFF		(uint8_t(0x00))

/**************************************** Used functions ***************************************/

void InitGpioLTDC (void);
void DisplayEnable (uint8_t status);
void DisplayLED (uint8_t status);
