/**************************************************************************************************
 * @file    hal_lptim.h
 * @brief   Microprocessor low-power timer module
 * @author  Control Data Systems, Andrei Rusu
 * @date    December 2015
 * @changes Created
**************************************************************************************************/
#ifndef _HAL_LPTIM_H_
#define _HAL_LPTIM_H_

#include "typedefs.h"

enum HAL_LPTIM
{
    HAL_LPTIM_0 = ((uint8_t) 0x00), // LPTIM1
    HAL_LPTIM_1,                    // LPTIM2
    
    HAL_LPTIM_NO
};

#define HAL_LPTIM_INTERRUPT__DISABLE ((uint8_t) 0x00)
#define HAL_LPTIM_INTERRUPT__CC      ((uint8_t) 0x01)
#define HAL_LPTIM_INTERRUPT__UPDATE  ((uint8_t) 0x02)

typedef struct
{
    uint8_t m_ucPrePriority : 4;
    uint8_t m_ucSubPriority : 4;
}HAL_LPTIM_Interrupt;

typedef struct
{
    uint16_t m_unCC0;
    uint16_t m_unCC1;
}HAL_LPTIM_Compare;

typedef struct
{
    HAL_LPTIM_Compare m_stCompare;
    HAL_LPTIM_Interrupt m_stInterrupt;
}HAL_LPTIM_Flags;

enum HAL_LPTIM_Compares
{
    HAL_LPTIM_COMPARE = ((uint8_t) 0x00),
    HAL_LPTIM_UPDATE
};

enum HAL_LPTIM_States
{
    HAL_LPTIM_DISABLE = ((uint8_t) 0x00),
    HAL_LPTIM_ENABLE
};

/**************************************************************************************************
 * @author    Control Data Systems, Andrei Rusu
 * @brief     Low-power timer configuration
 * @param[in] ucModule - low-power timer module
 * @param[in] unFlags - low-power timer flags
 * @remarks
**************************************************************************************************/
void HAL_LPTIM_Config(uint8_t ucModule, HAL_LPTIM_Flags unFlags);

/**************************************************************************************************
 * @author    Control Data Systems, Andrei Rusu
 * @brief     Low-power timer set state
 * @param[in] ucModule - low-power timer module
 * @param[in] ucState - low-power timer flags
 * @remarks
**************************************************************************************************/
void HAL_LPTIM_SetState(uint8_t ucModule, uint8_t ucState);

/**************************************************************************************************
 * @author    Control Data Systems, Andrei Rusu
 * @brief     Low-power timer set interrupt
 * @param[in] ucModule - low-power timer module
 * @param[in] ucInterrupt - low-power timer interrupt
 * @remarks
**************************************************************************************************/
void HAL_LPTIM_SetInterrupt(uint8_t ucModule, uint8_t ucInterrupt);

/**************************************************************************************************
 * @author    Control Data Systems, Andrei Rusu
 * @brief     Low-power timer get interrupt status
 * @param[in] ucModule - timer module
 * @param[in] ucInterrupt - timer interrupt
 * @return    Interrupt status
 * @remarks
**************************************************************************************************/
uint8_t HAL_LPTIM_GetInterruptStatus(uint8_t ucModule, uint8_t ucInterrupt);

/**************************************************************************************************
 * @author    Control Data Systems, Andrei Rusu
 * @brief     Low-power timer get counter
 * @param[in] ucModule - low-power timer module
 * @return	  the low-power timer counter
 * @remarks
**************************************************************************************************/
uint16_t HAL_LPTIM_GetCounter(uint8_t ucModule);

/**************************************************************************************************
 * @author    Control Data Systems, Andrei Rusu
 * @brief     Low-power timer get counter
 * @param[in] ucModule - low-power timer module
 * @param[in] ucCompare - low-power timer compare
 * @param[in] unValue - low-power timer compare value
 * @return	  the low-power timer counter
 * @remarks
**************************************************************************************************/
void HAL_LPTIM_SetCompare(uint8_t ucModule, uint8_t ucCompare, uint16_t unValue);

/**************************************************************************************************
 * @author    Control Data Systems, Andrei Rusu
 * @brief     HAL_LPTIM_0 Interrupt
 * @remarks
**************************************************************************************************/
void HAL_LPTIM_0_Interrupt(void);

/**************************************************************************************************
 * @author    Control Data Systems, Andrei Rusu
 * @brief     HAL_LPTIM_0 Update Callback
 * @remarks
**************************************************************************************************/
extern void HAL_LPTIM_0_UpdateCallback(void);

/**************************************************************************************************
 * @author    Control Data Systems, Andrei Rusu
 * @brief     HAL_LPTIM_0 Compare Callback
 * @remarks
**************************************************************************************************/
extern void HAL_LPTIM_0_CompareCallback(void);

/**************************************************************************************************
 * @author    Control Data Systems, Andrei Rusu
 * @brief     HAL_LPTIM_1 Interrupt
 * @remarks
**************************************************************************************************/
void HAL_LPTIM_1_Interrupt(void);

/**************************************************************************************************
 * @author    Control Data Systems, Andrei Rusu
 * @brief     HAL_LPTIM_1 Update Callback
 * @remarks
**************************************************************************************************/
extern void HAL_LPTIM_1_UpdateCallback(void);

/**************************************************************************************************
 * @author    Control Data Systems, Andrei Rusu
 * @brief     HAL_LPTIM_1 Compare Callback
 * @remarks
**************************************************************************************************/
extern void HAL_LPTIM_1_CompareCallback(void);


#endif /* HAL_LPTIM_H_ */
