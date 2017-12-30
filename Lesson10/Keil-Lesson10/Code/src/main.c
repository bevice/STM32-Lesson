/*************************************************** Library ******************************************************************/

#include "main.h"

/***************************************************** Main *******************************************************************/

int main(void){		
	
	InitRCC();
	GenMCO();
	InitGPIO();
	InitUART();
	InitPWM();
	InitADC();
	
	xTaskCreate(vTaskNextionHMI, "HMI", 128, NULL, 1, NULL);
	xTaskCreate(vTaskConvADC, "ADC", 128, NULL, 1, NULL);
	
	SendDataADC = xQueueCreate(5, sizeof(uint16_t));
	
	vTaskStartScheduler();
	
	while(1)
	{
				
	}
	
}

/*********************************************** Use tasks FreeRTOS ***********************************************************/

void vTaskNextionHMI (void *argument){
	
	uint16_t adcResult;
	char adcResultStr[4];
	
	float stepADC = 0.000732;
	float adcVoltage;
	char adcVoltageStr[5];
	
	char adcValueStr[2];
	
	
	while(1)
	{

		
		if (uxQueueMessagesWaiting(SendDataADC) != 0){
			
			xQueueReceive(SendDataADC, &adcResult, 0);
			
/************************** Send ADC result *********************************/
			
			sprintf(adcResultStr, "%u", adcResult);
	
			SendStringUSART1("t0.txt=\"");
			SendStringUSART1(adcResultStr);
			SendStringUSART1("\"");
			
			SendDataUSART1(0xFF);
			SendDataUSART1(0xFF);
			SendDataUSART1(0xFF);
			
/*************************** Send voltage ***********************************/
			
			adcVoltage = stepADC * (float)adcResult;
			sprintf(adcVoltageStr, "%.3f", adcVoltage);
	
			SendStringUSART1("t1.txt=\"");
			SendStringUSART1(adcVoltageStr);
			SendStringUSART1(" V\"");
			
			SendDataUSART1(0xFF);
			SendDataUSART1(0xFF);
			SendDataUSART1(0xFF);
			
			
/**************************** Send value ************************************/

			sprintf(adcValueStr, "%u", adcResult/41);
	
			SendStringUSART1("j0.val=");
			SendStringUSART1(adcValueStr);
			
			SendDataUSART1(0xFF);
			SendDataUSART1(0xFF);
			SendDataUSART1(0xFF);
			
		}
		
		vTaskDelay(100);
		
	}
	
}

void vTaskConvADC (void *argument){
	
	uint16_t adcResult;
	
	while(1)
	{
		
		adcResult = StartConvADC();
		
		xQueueSend(SendDataADC, &adcResult, 0);
		
		GPIOC->ODR ^= GPIO_ODR_ODR8;
		vTaskDelay(200);
		
	}
	
}

/*************************************************** Interrupt ****************************************************************/

void USART1_IRQHandler (void){
	
	if (USART1->SR & USART_SR_RXNE){
		
		USART1->SR &= ~USART_SR_RXNE;
		
	}
	
}

void USART2_IRQHandler (void){
	
	if (USART2->SR & USART_SR_RXNE){
		
		USART2->SR &= ~USART_SR_RXNE;
		
	}
	
}







