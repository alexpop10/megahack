#include "adc.h"
#include "hal_gpio.h"
#include "hal_clock.h"
#include "log.h"
uint8_t g_ucCalibData;
uint16_t g_unVrefintCalData, g_unVrefint;
uint16_t g_unData = 1023;

fp32_t g_fpData;

#define VREF_CAL_DATA_ADDRESS 0x1FFF75AA

void HAL_ADC_Init(void)
{
	HAL_ADC_Flags l_stAdcFlags = {0};

	l_stAdcFlags.m_ucDataAlignment = HAL_ADC_ALIGN_RIGHT;
	l_stAdcFlags.m_ucResolution = HAL_ADC_RES12;
	l_stAdcFlags.m_ucSampleMode = HAL_ADC_CONV_SINGLE;
	
	HAL_ADC_Config(HAL_ADC_1, l_stAdcFlags);

	g_unVrefintCalData = *(__IO uint16_t*)(VREF_CAL_DATA_ADDRESS);
	g_unVrefint = HAL_ADC_ReadChannel(VREFINT_MODULE, VREFINT_CH);
	
	g_unData = HAL_ADC_ReadChannel(ADC_BAT_MODULE, ADC_BAT_CH);
	
	g_fpData = 3.0 * g_unVrefintCalData / g_unVrefint;
	g_fpData = g_fpData / 4096 * g_unData;
}

uint16_t ADC_ReadVrefInt(void)
{
	return HAL_ADC_ReadChannel(VREFINT_MODULE, VREFINT_CH);
}

//void ADC_Task(void)
//{
//	double l_ulData;
//	uint16_t l_unTickUs;
//
//	l_unTickUs = (uint16_t) (HAL_CLOCK_Get() / 1000000);
//	HAL_CLOCK_SysTickEnable(l_unTickUs * CAP_CHARGE_US);
//
//	while (!g_ucSysTick_Update)
//	{
//		/* Wait for cap. */
//	}
//	g_ucSysTick_Update = 0;
//
//	g_unData = HAL_ADC_ReadChannel(ADC_BAT_MODULE, ADC_BAT_CH);
//	l_ulData = (3.0 * g_unVrefintCalData * g_unData) / (ADC_ReadVrefInt() * MAX_RESOLUTION) * RAPORT;
//
//	Log("Battery voltage: %4.2f\r\n", l_ulData);
//
//	//TODO: Check for threshold, and act accordingly -> do not join network if battery is to low
//	if(l_ulData < BAT_LOW)
//	{
//
//	}
//}

fp32_t ADC_ReadBattery(void)
{
	fp32_t l_fpData;

	g_unData = HAL_ADC_ReadChannel(ADC_BAT_MODULE, ADC_BAT_CH);
	l_fpData = (3.0 * g_unVrefintCalData * g_unData) / (ADC_ReadVrefInt() * MAX_RESOLUTION);

	return l_fpData;
}

fp32_t ADC_ReadLoopCurrent(void)
{
	fp32_t l_fpData;
	
	g_unData = HAL_ADC_ReadChannel(HART_LC_MODULE, HART_LC_CH);
	l_fpData = (3.0 * g_unVrefintCalData * g_unData) / (ADC_ReadVrefInt() * MAX_RESOLUTION);
	
	return l_fpData;
}

fp32_t ADC_ReadChannel(uint8_t p_ucModule, uint8_t p_ucChannel)
{
	fp32_t l_fpData;
	
	g_unData = HAL_ADC_ReadChannel(p_ucModule, p_ucChannel);
	l_fpData = (3.0 * g_unVrefintCalData * g_unData) / (ADC_ReadVrefInt() * MAX_RESOLUTION);
	
	return l_fpData;
}
