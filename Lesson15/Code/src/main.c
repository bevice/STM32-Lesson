#include "main.h"

int main (void) {

	StartInitClock();
	InitBaseGPIO();

	EnableOutputMCO();
	LED1(ON);

	while(1)
	{

	}
}
