#pragma once

#include "stm32f7xx.h"

/****************************************** Defines ********************************************/

#define ON		((uint8_t)0x01)
#define OFF		((uint8_t)0x00)

#define DISPLAY_WIDTH 			((uint16_t)480)
#define DISPLAY_HEIGHT			((uint16_t)272)

#define PIXEL_SIZE 				((uint16_t)4)

/**************************************** Timing display ***************************************/

#define  DISPLAY_HSYNC            ((uint16_t)30)   		// Horizontal synchronization
#define  DISPLAY_HBP              ((uint16_t)13)   		// Horizontal back porch
#define  DISPLAY_HFP              ((uint16_t)32)   		// Horizontal front porch
#define  DISPLAY_VSYNC            ((uint16_t)10)   		// Vertical synchronization
#define  DISPLAY_VBP              ((uint16_t)2)    		// Vertical back porch
#define  DISPLAY_VFP              ((uint16_t)2)    		// Vertical front porch

/**************************************** Used functions ***************************************/

void InitGpioLTDC (void);
void DisplayEnable (uint8_t status);
void DisplayLED (uint8_t status);
void InitDisplayLTDC (void);
void InitTFTdisplay (void);
