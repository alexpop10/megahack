/**************************************************************************************************
 * @file    hal_clock.h
 * @brief   Microprocessor clock module
 * @author  Control Data Systems, Mircea Caprioru
 * @date    September 2015
 * @changes Created
**************************************************************************************************/
#ifndef _HAL_CLOCK_H_
#define _HAL_CLOCK_H_

#include "typedefs.h"

#define HSE_CLOCK ((uint32_t) 24000000)

#define PLL_80_MHZ 0
#define PLL_64_MHZ 1

#if (PLL_CLOCK == PLL_80_MHZ)

#define HAL_RCC_PLLM 3U
#define HAL_RCC_PLLN 20U
#define HAL_RCC_PLLR 2U
#define HAL_RCC_PLLP 7U
#define HAL_RCC_PLLQ 2U

#elif (PLL_CLOCK == PLL_64_MHZ)

#define HAL_RCC_PLLM 3U
#define HAL_RCC_PLLN 16U
#define HAL_RCC_PLLR 2U
#define HAL_RCC_PLLP 7U
#define HAL_RCC_PLLQ 2U

#else

#warning "Define new clock configuration"

#endif /* PLL_CLOCK */

#define HAL_RCC_PLLM_OFFSET 4U
#define HAL_RCC_PLLN_OFFSET 8U
#define HAL_RCC_PLLR_OFFSET 25U
#define HAL_RCC_PLLP_OFFSET 17U
#define HAL_RCC_PLLQ_OFFSET 21U

enum HAL_CLOCK_Sources
{
  HAL_CLOCK_SOURCE__PLL = ((uint8_t) 0x00),
  HAL_CLOCK_SOURCE__HSI,
  HAL_CLOCK_SOURCE__MSI
};

extern uint8_t g_ucSysTick_Update;

/**************************************************************************************************
 * @author  Control Data Systems, Mircea Caprioru
 * @brief   Clock initialization
 * @remarks
**************************************************************************************************/
void HAL_CLOCK_Init(void);
/**************************************************************************************************
 * @author    Control Data Systems, Andrei Rusu
 * @brief     Clock update
 * @param[in] ucClockSource - the new clock source (e.g. HAL_CLOCK_SOURCE__PLL)
 * @remarks
**************************************************************************************************/
void HAL_CLOCK_Update(uint8_t ucClockSource);
/**************************************************************************************************
 * @author    Control Data Systems, Andrei Rusu
 * @brief     Enable the SysTick timer
 * @param[in] ulTicks - the number of ticks for the overflow interrupt
 * @remarks
**************************************************************************************************/
void HAL_CLOCK_SysTickEnable(uint32_t ulTicks);
/**************************************************************************************************
 * @author    Control Data Systems, Andrei Rusu
 * @brief     Disable the SysTick timer
 * @param[in] ulTicks - the number of ticks for the overflow interrupt
 * @remarks
**************************************************************************************************/
void HAL_CLOCK_SysTickDisable(void);
/**************************************************************************************************
 * @author    Control Data Systems, Andrei Rusu
 * @brief     SysTick timer interrupt
 * @remarks
**************************************************************************************************/
void HAL_CLOCK_SysTick_Interrupt(void);
/**************************************************************************************************
 * @author    Control Data Systems, Andrei Rusu
 * @brief     Clock get
 * @return    The system clock in Hz
 * @remarks
**************************************************************************************************/
uint32_t HAL_CLOCK_Get(void);
#endif /* _HAL_CLOCK_H_ */
