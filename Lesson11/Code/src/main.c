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
	InitDAC();
	
	xTaskCreate(vTaskNextionHMI, "HMI", 128, NULL, 1, NULL);
	xTaskCreate(vTaskConvADC, "ADC", 128, NULL, 1, NULL);
	xTaskCreate(vTaskDACout, "DAC", 32, NULL, 1, NULL);
	
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

void vTaskDACout (void *argument){
	
	const uint16_t sin[32] = {
	0, 38, 155, 344, 599, 909, 1263, 1647, 2047, 2447, 2831, 3185, 3498, 3750, 3939, 4056,
	4095, 4056, 3939, 3750, 3495, 3185, 2831, 2447, 2047, 1647, 1263, 909, 599, 344, 155, 38 };
	
	uint16_t i;
	
	while(1)
	{
		
		writeDAC(sin[i++]);
		
		if (i==32){i=0;}
		vTaskDelay(1);
		
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







