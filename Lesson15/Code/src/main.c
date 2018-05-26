#include "main.h"

int main (void) {

	StartInitClock();
	InitBaseGPIO();

	LED1(ON);

	InitTFTdisplay();

	while(1)
	{

	}
}
