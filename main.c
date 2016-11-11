/**************************************************************************************************
 * @file    main.c
 * @brief   STM32L486xx HAL main 
 * @author  Control Data Systems, Andrei Rusu
 * @date    September 2015
 * @changes Created
**************************************************************************************************/
#include "platform.h"
#include "log.h"
#include "hal_clock.h"
#include "gpio.h"
#include "timers.h"
#include "lpm.h"
#include "hal_flash.h"
#include "uart.h"
#include "SHT21.h"
#include "25LC080.h"
#include "simple_api.h"
#include "adc.h"

void main(void)
{
	PLATFORM_Init();
	HAL_CLOCK_Init();
	LOG_Init();
	HAL_GPIO_Init();
	HAL_UART_Init();
	
	HAL_ADC_Init();
		
	Log("CDS VS210 has started.\r\n");
	
	SHT21_Init();
	
	HAL_TIMER_Init();
	
	HAL_GPIO_Write(VN_RST_PORT, VN_RST_PIN, HAL_GPIO_HIGH);
	g_ucRadioReady = 0;
	
	while(1)
	{
		//TODO: Add your code here.
		API_Task();
		if (g_ucCanGoToSleep & !g_ucReceiving)
		{
			HAL_LPM_3_Enter();
		}
	}
}