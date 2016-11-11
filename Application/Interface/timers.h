/**************************************************************************************************
 * @file    timers.h
 * @brief   Application timers interface
 * @author  Control Data Systems, Andrei Rusu
 * @date    October 2015
 * @changes Created
**************************************************************************************************/
#ifndef _TIMERS_H_
#define _TIMERS_H_

#include "typedefs.h"

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   Timer initializations
 * @remarks
**************************************************************************************************/
void HAL_TIMER_Init(void);

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   Low-power timer initializations
 * @remarks
**************************************************************************************************/
void HAL_LPTIM_Init(void);

#endif /* _TIMERS_H_ */
