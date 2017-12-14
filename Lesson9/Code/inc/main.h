/*************************************************** Library ******************************************************************/

#include "stm32f10x.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

#include "sysInit.h"
#include "libUART.h"
#include "libPWM.h"

/************************************************** Defines *******************************************************************/

xQueueHandle SendData;

/******************************************** Use tasks FreeRTOS **************************************************************/

void vTaskPWMgen (void *argument);
void vTaskButtonUser (void *argument);  
