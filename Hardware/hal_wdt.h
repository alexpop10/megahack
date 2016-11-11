/*
 * hal_wdt.h
 *
 *  Created on: Nov 5, 2015
 *      Author: stefan.vos
 */

#ifndef HAL_WDT_H_
#define HAL_WDT_H_

#include "typedefs.h"

typedef enum
{
HAL_WDT_PRE_0_5s = 0,
HAL_WDT_PRE_1s,
HAL_WDT_PRE_2s,
HAL_WDT_PRE_4s,
HAL_WDT_PRE_8s,
HAL_WDT_PRE_16s,
HAL_WDT_PRE_32s
}HAL_WDT_PRESCALER;

typedef struct
{
 uint8_t m_ucPrescaler;
 uint16_t m_ucWindow;

}HAL_WDT_Flags;

void HAL_WDT_Init(void);
void HAL_WDT_Config(HAL_WDT_Flags p_stConfig);
void HAL_WDT_Refresh(void);
void HAL_WDT_Disable(void);
void HAL_WDT_Enable(void);
#endif /* HAL_WDT_H_ */
