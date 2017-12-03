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
	
	vTaskStartScheduler();
	
	while(1)
	{
				
	}
	
}

/*********************************************** Use tasks FreeRTOS ***********************************************************/

void vTaskButtonUser (void *argument){
	
	while(1)
	{
		
		if ((GPIOA->IDR & GPIO_IDR_IDR0) != 0){
			
			vTaskDelay(100);			
			SendStringUSART1 ("bt0.val=1");
		
			SendDataUSART1 (0xFF);
			SendDataUSART1 (0xFF);
			SendDataUSART1 (0xFF);
			
		}	
		
		vTaskDelay(200);
		
	}
	
}

void vTaskPWMgen (void *argument){
	
	uint16_t i;
	
	while(1)
	{
		
		TIM2->CCR2 = i;                            
		i++;
		vTaskDelay(10);
		
		if (i==500){i=0;}
		
	}
	
}

/*************************************************** Interrupt ****************************************************************/

void USART1_IRQHandler (void){
	
	if (USART1->SR & USART_CR1_RXNEIE){
		
		USART1->SR &= ~USART_CR1_RXNEIE;
		
		if (USART1->DR == 0x01){GPIOC->BSRR |= GPIO_BSRR_BS8;}
		if (USART1->DR == 0x02){GPIOC->BSRR |= GPIO_BSRR_BR8;}
		
		if (USART1->DR == 0x03){GPIOC->BSRR |= GPIO_BSRR_BS9;}
		if (USART1->DR == 0x04){GPIOC->BSRR |= GPIO_BSRR_BR9;}
		
	}
	
}







