/*
 * hal_adc.h
 *
 *  Created on: Dec 21, 2015
 *      Author: stefan.vos
 */

#ifndef HAL_ADC_H_
#define HAL_ADC_H_

#include "typedefs.h"

#define ADCVREG_STUP 20 // microseconds - page 153 datasheet

#define HAL_ADC123_PORT 2
#define HAL_ADC123_IN1  0
#define HAL_ADC123_IN2  1
#define HAL_ADC123_IN3  2
#define HAL_ADC123_IN4  3

#define HAL_ADC12_5_12_PORT   0
#define HAL_ADC12_13_14_PORT  2
#define HAL_ADC12_15_16_PORT  1
#define HAL_ADC12_IN5         0
#define HAL_ADC12_IN6         1
#define HAL_ADC12_IN7         2
#define HAL_ADC12_IN8         3
#define HAL_ADC12_IN9         4
#define HAL_ADC12_IN10        5
#define HAL_ADC12_IN11        6
#define HAL_ADC12_IN12        7
#define HAL_ADC12_IN13        4
#define HAL_ADC12_IN14        5
#define HAL_ADC12_IN15        0
#define HAL_ADC12_IN16        1

#define HAL_ADC3_PORT  5
#define HAL_ADC3_IN6   3
#define HAL_ADC3_IN7   4
#define HAL_ADC3_IN8   5
#define HAL_ADC3_IN9   6
#define HAL_ADC3_IN10  7
#define HAL_ADC3_IN11  8
#define HAL_ADC3_IN12  9
#define HAL_ADC3_IN13  10

enum HAL_ADC_Module
{
	HAL_ADC_1 = 0,
	HAL_ADC_2,
	HAL_ADC_3,
	
	HAL_ADC_NO
};// ADC modulues

typedef enum 
{
	HAL_ADC_CONV_SINGLE = 0,
	HAL_ADC_CONV_CONTINUOUS
}HAL_ADC_CONVERSION; // ADC Conversion mode

typedef enum 
{
	HAL_ADC_ALIGN_RIGHT = 0,
	HAL_ADC_ALIGN_LEFT
}HAL_ADC_ALIGN;

typedef enum 
{
	HAL_ADC_RES12 = 0,
	HAL_ADC_RES10,
	HAL_ADC_RES8,
	HAL_ADC_RES6
}HAL_ADC_RESOLUTIONS;// ADC res

typedef enum 
{
	HAL_ADC_IN0 = 0,
	HAL_ADC_IN1,
	HAL_ADC_IN2,
	HAL_ADC_IN3,
	HAL_ADC_IN4,
	HAL_ADC_IN5,
	HAL_ADC_IN6,
	HAL_ADC_IN7,
	HAL_ADC_IN8,
	HAL_ADC_IN9,
	HAL_ADC_IN10,
	HAL_ADC_IN11,
	HAL_ADC_IN12,
	HAL_ADC_IN13,
	HAL_ADC_IN14,
	HAL_ADC_IN15,
	HAL_ADC_IN16,
	HAL_ADC_IN17,
	HAL_ADC_IN18,
}HAL_ADC_INANNELS;

typedef struct
{
	uint8_t m_ucResolution;
	uint8_t m_ucDataAlignment;
	uint8_t m_ucSampleMode;
} HAL_ADC_Flags;

enum HAL_ADC_States
{
  HAL_ADC_DISABLE = ((uint8_t) 0x00),
  HAL_ADC_ENABLE
};

//void HAL_ADC_Init(void);

void HAL_ADC_Config(uint8_t p_ucModule, HAL_ADC_Flags p_stFlags);
void HAL_ADC_InjectCalibData(uint8_t p_ucModule, uint8_t p_ucCalibData);
uint16_t HAL_ADC_ReadChannel(uint8_t p_ucModule, uint8_t p_ucChannel);
void HAL_ADC_SetState(uint8_t ucModule, uint8_t ucState);
#endif /* HAL_ADC_H_ */
