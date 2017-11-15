#include "stm32f10x.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

void GPIO_Init (void);

void vTaskLed1 (void *argument);
void vTaskLed2 (void *argument);

int main(void){		
	
	GPIO_Init();
	
	xTaskCreate(vTaskLed1, "LED1", 32, NULL, 1, NULL);
	xTaskCreate(vTaskLed2, "LED2", 32, NULL, 1, NULL);
	
	vTaskStartScheduler();
	
	while(1)
	{
				
	}
	
}

/*******************************************************************************************************/

void GPIO_Init (void){
	
	RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;

	GPIOC->CRH &= ~GPIO_CRH_CNF8;
	GPIOC->CRH |= GPIO_CRH_MODE8_0;
	
	GPIOC->CRH &= ~GPIO_CRH_CNF9;
	GPIOC->CRH |= GPIO_CRH_MODE9_0;
	
}

void vTaskLed1 (void *argument){
	
	while(1)
	{
		
		GPIOC->BSRR |= GPIO_BSRR_BS8;
		vTaskDelay(1000);
		GPIOC->BSRR |= GPIO_BSRR_BR8;
		vTaskDelay(1000);
		
	}
	
}

void vTaskLed2 (void *argument){
	
	while(1)
	{
	
		GPIOC->BSRR |= GPIO_BSRR_BR9;
		vTaskDelay(1000);
		GPIOC->BSRR |= GPIO_BSRR_BS9;
		vTaskDelay(1000);
		
	}
	
}






