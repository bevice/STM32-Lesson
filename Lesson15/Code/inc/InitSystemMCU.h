#include "stm32f7xx.h"

/****************************************** Defines ********************************************/

#define ON		((uint8_t)0x01)
#define OFF		((uint8_t)0x00)

/**************************************** Used function ****************************************/

void StartInitClock (void);
void EnableOutputMCO (void);

void InitBaseGPIO (void);
void LED1 (uint8_t status);

