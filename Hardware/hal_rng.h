/**************************************************************************************************
 * @file    hal_rng.h
 * @brief   Microprocessor Random Number Generator module
 * @author  Control Data Systems, Stefan Vos
 * @date    October 2015
 * @changes Created
 **************************************************************************************************/
#ifndef _HAL_RNG_H_
#define _HAL_RNG_H_

#include "typedefs.h"

/**************************************************************************************************
 * @author   Control Data Systems, Stefan Vos
 * @brief    Random Number Generator initialization
 * @remarks
 **************************************************************************************************/
void HAL_RNG_Init(void);

/**************************************************************************************************
 * @author  Control Data Systems, Stefan Vos
 * @brief   Random Number Generator get value
 * @return  The random value 
 * @remarks
 **************************************************************************************************/
uint32_t HAL_RNG_GetValue(void);

#endif /* _HAL_RNG_H_ */

