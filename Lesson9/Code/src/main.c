/*************************************************** Library ******************************************************************/

#include "main.h"

/***************************************************** Main *******************************************************************/

int main(void){		
	
	InitRCC();
	GenMCO();
	InitGPIO();
	InitUART();
	InitPWM();
	
	xTaskCreate(vTaskButtonUser, "LED1", 32, NULL, 1, NULL);
	xTaskCreate(vTaskPWMgen, "PWM", 32, NULL, 1, NULL);
	
	SendData = xQueueCreate(5, sizeof(uint8_t));
	
	vTaskStartScheduler();
	
	while(1)
	{
				
	}
	
}

/*********************************************** Use tasks FreeRTOS ***********************************************************/

void vTaskButtonUser (void *argument){
	
	uint8_t data;
	
	while(1)
	{
		
		if ((GPIOA->IDR & GPIO_IDR_IDR0) != 0){
			
			vTaskDelay(100);			
			
		}	
		
		if (uxQueueMessagesWaiting(SendData) != 0){
			
			xQueueReceive(SendData, &data, 0);
			SendDataUSART2(data);
			
		}
		
		vTaskDelay(100);
		
	}
	
}

void vTaskPWMgen (void *argument){
	
	uint16_t i = 30;
	
	while(1)
	{
		
		i++;
		xQueueSend(SendData, &i, 0);
		vTaskDelay(1000);
		
	}
	
}

/*************************************************** Interrupt ****************************************************************/

void USART1_IRQHandler (void){
	
	if (USART1->SR & USART_SR_RXNE){
		
		USART1->SR &= ~USART_SR_RXNE;
		
		if (USART1->DR == 0x01){GPIOC->BSRR |= GPIO_BSRR_BS8;}
		if (USART1->DR == 0x02){GPIOC->BSRR |= GPIO_BSRR_BR8;}
		
		if (USART1->DR == 0x03){GPIOC->BSRR |= GPIO_BSRR_BS9;}
		if (USART1->DR == 0x04){GPIOC->BSRR |= GPIO_BSRR_BR9;}
		
	}
	
}







