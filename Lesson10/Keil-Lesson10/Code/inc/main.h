/*************************************************** Library ******************************************************************/

#include "stm32f10x.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

#include "sysInit.h"
#include "libUART.h"
#include "libPWM.h"
#include "libADC.h"

#include <stdio.h>

/************************************************** Defines *******************************************************************/

xQueueHandle SendDataADC;

/******************************************** Use tasks FreeRTOS **************************************************************/

void vTaskNextionHMI (void *argument);  
void vTaskConvADC (void *argument);
