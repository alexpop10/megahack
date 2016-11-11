/*
 * adc.h
 *
 *  Created on: Ian 7, 2016
 *      Author: stefan.vos
 */

#ifndef _ADC_H_
#define _ADC_H_

#include "hal_adc.h"

#define REF_VOLTAGE    3.3
#define MAX_RESOLUTION 4095

#define RAPORT 5
#define BAT_LOW 3.5

#define CAP_CHARGE_US 1000000

#define HART_LC_MODULE HAL_ADC_1
#define HART_LC_CH     HAL_ADC_IN2

#define ADC_BAT_MODULE HAL_ADC_1
#define ADC_BAT_CH     HAL_ADC_IN1

#define VREFINT_MODULE HAL_ADC_1
#define VREFINT_CH     HAL_ADC_IN0

#define MCU_ADC3_MODULE HAL_ADC_1
#define MCU_ADC3_CH     HAL_ADC_IN3

#define MCU_ADC4_MODULE HAL_ADC_1
#define MCU_ADC4_CH     HAL_ADC_IN4

extern uint8_t g_ucCalibData;

void HAL_ADC_Init(void);
uint16_t ADC_ReadVrefInt(void);
fp32_t ADC_ReadBattery(void);
fp32_t ADC_ReadLoopCurrent(void);
fp32_t ADC_ReadChannel(uint8_t p_ucModule, uint8_t p_ucChannel);
#endif /* _ADC_H_ */
