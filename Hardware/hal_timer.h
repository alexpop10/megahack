/**************************************************************************************************
 * @file    hal_timer.h
 * @brief   Microprocessor timer module
 * @author  Control Data Systems, Andrei Rusu
 * @date    September 2015
 * @changes Created
**************************************************************************************************/
#ifndef _HAL_TIMER_H_
#define _HAL_TIMER_H_

#include "typedefs.h"

enum HAL_TIMER
{
  HAL_TIMER_0 = ((uint8_t) 0x00), // TIM1
  HAL_TIMER_1,                    // TIM2
  HAL_TIMER_2,                    // TIM3
  HAL_TIMER_3,                    // TIM4
  HAL_TIMER_4,                    // TIM5
  HAL_TIMER_5,                    // TIM6
  HAL_TIMER_6,                    // TIM7
  HAL_TIMER_7,                    // TIM8
  HAL_TIMER_8,                    // TIM15
  HAL_TIMER_9,                    // TIM16
  HAL_TIMER_10,                   // TIM17
  
  HAL_TIMER_NO
};
 
#define HAL_TIMER_CLOCK__SYSTEM      ((uint8_t) 0x00)
#define HAL_TIMER_CLOCK__ALTERNATE   ((uint8_t) 0x01)

#define HAL_TIMER_DIRECTION__UP      ((uint8_t) 0x00)
#define HAL_TIMER_DIRECTION__DOWN    ((uint8_t) 0x01)

#define HAL_TIMER_INTERRUPT__DISABLE ((uint8_t) 0x00)
#define HAL_TIMER_INTERRUPT__CC1     ((uint8_t) 0x01)
#define HAL_TIMER_INTERRUPT__CC2     ((uint8_t) 0x02)
#define HAL_TIMER_INTERRUPT__CC3     ((uint8_t) 0x04)
#define HAL_TIMER_INTERRUPT__CC4     ((uint8_t) 0x08)
#define HAL_TIMER_INTERRUPT__UPDATE  ((uint8_t) 0x10)

typedef struct
{
	uint8_t m_ucPrePriority : 4;
	uint8_t m_ucSubPriority : 4;
}HAL_TIMER_Interrupt;

typedef struct
{
	uint16_t m_unPrescaler;
	uint16_t m_unCC0;
	uint16_t m_unCC1;
	uint16_t m_unCC2;
	uint16_t m_unCC3;
	uint16_t m_unCC4;
}HAL_TIMER_Compare;

typedef struct 
{
	uint8_t m_ucClock : 1;
	uint8_t m_ucDirection : 1;
	HAL_TIMER_Compare m_stCompare;
	HAL_TIMER_Interrupt m_stInterrupt;
}HAL_TIMER_Flags;

enum HAL_TIMER_Compares
{
	HAL_TIMER_UPDATE = ((uint8_t) 0x00),
	HAL_TIMER_COMPARE_1,
	HAL_TIMER_COMPARE_2,
	HAL_TIMER_COMPARE_3,
	HAL_TIMER_COMPARE_4
};

enum HAL_TIMER_States
{
	HAL_TIMER_DISABLE = ((uint8_t) 0x00),
	HAL_TIMER_ENABLE
};

/**************************************************************************************************
 * @author    Control Data Systems, Mircea Caprioru
 * @brief     Timer configuration
 * @param[in] ucModule - timer module
 * @param[in] stFlags - timer flags
 * @remarks
**************************************************************************************************/
void HAL_TIMER_Config(uint8_t ucModule, HAL_TIMER_Flags stFlags);

/**************************************************************************************************
 * @author    Control Data Systems, Andrei Rusu
 * @brief     Timer set state
 * @param[in] ucModule - timer module
 * @param[in] ucState - timer state ENABLE/DISABLE
 * @remarks
**************************************************************************************************/
void HAL_TIMER_SetState(uint8_t ucModule, uint8_t ucState);

/**************************************************************************************************
 * @author    Control Data Systems, Andrei Rusu
 * @brief     Timer set interrupt
 * @param[in] ucModule - timer module
 * @param[in] ucInterrupt - timer interrupt
 * @remarks
**************************************************************************************************/
void HAL_TIMER_SetInterrupt(uint8_t ucModule, uint8_t ucInterrupt);

/**************************************************************************************************
 * @author    Control Data Systems, Andrei Rusu
 * @brief     Timer get interrupt status
 * @param[in] ucModule - timer module
 * @param[in] ucInterrupt - timer interrupt
 * @return    Interrupt status
 * @remarks
**************************************************************************************************/
uint8_t HAL_TIMER_GetInterruptStatus(uint8_t ucModule, uint8_t ucInterrupt);

/**************************************************************************************************
 * @author    Control Data Systems, Andrei Rusu
 * @brief     Timer set counter
 * @param[in] ucModule - timer module
 * @param[in] unCounter - timer counter value 
 * @remarks
**************************************************************************************************/
void HAL_TIMER_SetCounter(uint8_t ucModule, uint16_t unCounter);

/**************************************************************************************************
 * @author    Control Data Systems, Andrei Rusu
 * @brief     Timer get counter
 * @param[in] ucModule - timer module
 * @return    The timer counter
 * @remarks
**************************************************************************************************/
uint16_t HAL_TIMER_GetCounter(uint8_t ucModule);

/**************************************************************************************************
 * @author    Control Data Systems, Andrei Rusu
 * @brief     Timer set capture/compare
 * @param[in] ucModule - timer module
 * @param[in] ucCCx - capture compare register
 * @param[in] unValue - capture compare value
 * @remarks
**************************************************************************************************/
void HAL_TIMER_SetCompare(uint8_t ucModule, uint8_t ucCompare, uint16_t unValue);

/**************************************************************************************************
 * @author  Control Data Systems, Mircea Caprioru
 * @brief   HAL_TIMER_0_0 interrupt
 * @remarks HAL_TIMER_0 Update Interrupt
**************************************************************************************************/
void HAL_TIMER_0_0_Interrupt(void);

/**************************************************************************************************
 * @author  Control Data Systems, Mircea Caprioru
 * @brief   HAL_TIMER_0_1 interrupt
 * @remarks HAL_TIMER_0 Capture/Compare Interrupt
**************************************************************************************************/
void HAL_TIMER_0_1_Interrupt(void);

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_0 Update Callback
 * @remarks
**************************************************************************************************/
extern void HAL_TIMER_0_UpdateCallback(void);

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_0 Compare 1 Callback
 * @remarks
**************************************************************************************************/
extern void HAL_TIMER_0_Compare1Callback(void);

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_0 Compare 2 Callback
 * @remarks
**************************************************************************************************/
extern void HAL_TIMER_0_Compare2Callback(void);

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_0 Compare 3 Callback
 * @remarks
**************************************************************************************************/
extern void HAL_TIMER_0_Compare3Callback(void);

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_0 Compare 4 Callback
 * @remarks
**************************************************************************************************/
extern void HAL_TIMER_0_Compare4Callback(void);

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_1 interrupt
 * @remarks
**************************************************************************************************/
void HAL_TIMER_1_Interrupt(void);

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_1 Update Callback
 * @remarks
**************************************************************************************************/
extern void HAL_TIMER_1_UpdateCallback(void);

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_1 Compare 1 Callback
 * @remarks
**************************************************************************************************/
extern void HAL_TIMER_1_Compare1Callback(void);

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_1 Compare 2 Callback
 * @remarks
**************************************************************************************************/
extern void HAL_TIMER_1_Compare2Callback(void);

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_1 Compare 3 Callback
 * @remarks
**************************************************************************************************/
extern void HAL_TIMER_1_Compare3Callback(void);

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_1 Compare 4 Callback
 * @remarks
**************************************************************************************************/
extern void HAL_TIMER_1_Compare4Callback(void);

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_2 interrupt
 * @remarks
**************************************************************************************************/
void HAL_TIMER_2_Interrupt(void);

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_2 Update Callback
 * @remarks
**************************************************************************************************/
extern void HAL_TIMER_2_UpdateCallback(void);

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_2 Compare 1 Callback
 * @remarks
**************************************************************************************************/
extern void HAL_TIMER_2_Compare1Callback(void);

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_2 Compare 2 Callback
 * @remarks
**************************************************************************************************/
extern void HAL_TIMER_2_Compare2Callback(void);

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_2 Compare 3 Callback
 * @remarks
**************************************************************************************************/
extern void HAL_TIMER_2_Compare3Callback(void);

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_2 Compare 4 Callback
 * @remarks
**************************************************************************************************/
extern void HAL_TIMER_2_Compare4Callback(void);

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_3 interrupt
 * @remarks
**************************************************************************************************/
void HAL_TIMER_3_Interrupt(void);

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_3 Update Callback
 * @remarks
**************************************************************************************************/
extern void HAL_TIMER_3_UpdateCallback(void);

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_3 Compare 1 Callback
 * @remarks
**************************************************************************************************/
extern void HAL_TIMER_3_Compare1Callback(void);

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_3 Compare 2 Callback
 * @remarks
**************************************************************************************************/
extern void HAL_TIMER_3_Compare2Callback(void);

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_3 Compare 3 Callback
 * @remarks
**************************************************************************************************/
extern void HAL_TIMER_3_Compare3Callback(void);

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_3 Compare 4 Callback
 * @remarks
**************************************************************************************************/
extern void HAL_TIMER_3_Compare4Callback(void);

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_4 interrupt
 * @remarks
**************************************************************************************************/
void HAL_TIMER_4_Interrupt(void);

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_4 Update Callback
 * @remarks
**************************************************************************************************/
extern void HAL_TIMER_4_UpdateCallback(void);

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_4 Compare 1 Callback
 * @remarks
**************************************************************************************************/
extern void HAL_TIMER_4_Compare1Callback(void);

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_4 Compare 2 Callback
 * @remarks
**************************************************************************************************/
extern void HAL_TIMER_4_Compare2Callback(void);

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_4 Compare 3 Callback
 * @remarks
**************************************************************************************************/
extern void HAL_TIMER_4_Compare3Callback(void);

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_4 Compare 4 Callback
 * @remarks
**************************************************************************************************/
extern void HAL_TIMER_4_Compare4Callback(void);

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_5 interrupt
 * @remarks
**************************************************************************************************/
void HAL_TIMER_5_Interrupt(void);

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_5 Update Callback
 * @remarks
**************************************************************************************************/
extern void HAL_TIMER_5_UpdateCallback(void);

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_6 interrupt
 * @remarks
**************************************************************************************************/
void HAL_TIMER_6_Interrupt(void);

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_6 Update Callback
 * @remarks
**************************************************************************************************/
extern void HAL_TIMER_6_UpdateCallback(void);

/**************************************************************************************************
 * @author  Control Data Systems, Mircea Caprioru
 * @brief   HAL_TIMER_7_0 interrupt
 * @remarks HAL_TIMER_7 Update Interrupt
**************************************************************************************************/
void HAL_TIMER_7_0_Interrupt(void);

/**************************************************************************************************
 * @author  Control Data Systems, Mircea Caprioru
 * @brief   HAL_TIMER_7_1 interrupt
 * @remarks HAL_TIMER_7 Update Interrupt
**************************************************************************************************/
void HAL_TIMER_7_1_Interrupt(void);

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_7 Update Callback
 * @remarks
**************************************************************************************************/
extern void HAL_TIMER_7_UpdateCallback(void);

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_7 Compare 1 Callback
 * @remarks
**************************************************************************************************/
extern void HAL_TIMER_7_Compare1Callback(void);

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_7 Compare 2 Callback
 * @remarks
**************************************************************************************************/
extern void HAL_TIMER_7_Compare2Callback(void);

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_7 Compare 3 Callback
 * @remarks
**************************************************************************************************/
extern void HAL_TIMER_7_Compare3Callback(void);

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_7 Compare 4 Callback
 * @remarks
**************************************************************************************************/
extern void HAL_TIMER_7_Compare4Callback(void);

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_8 interrupt
 * @remarks
**************************************************************************************************/
void HAL_TIMER_8_Interrupt(void);

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_8 Update Callback
 * @remarks
**************************************************************************************************/
extern void HAL_TIMER_8_UpdateCallback(void);

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_8 Compare 1 Callback
 * @remarks
**************************************************************************************************/
extern void HAL_TIMER_8_Compare1Callback(void);

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_8 Compare 2 Callback
 * @remarks
**************************************************************************************************/
extern void HAL_TIMER_8_Compare2Callback(void);

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_8 Compare 3 Callback
 * @remarks
**************************************************************************************************/
extern void HAL_TIMER_8_Compare3Callback(void);

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_9 interrupt
 * @remarks
**************************************************************************************************/
void HAL_TIMER_9_Interrupt(void);

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_9 Update Callback
 * @remarks
**************************************************************************************************/
extern void HAL_TIMER_9_UpdateCallback(void);

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_9 Compare 1 Callback
 * @remarks
**************************************************************************************************/
extern void HAL_TIMER_9_Compare1Callback(void);

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_10 interrupt
 * @remarks
**************************************************************************************************/
void HAL_TIMER_10_Interrupt(void);

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_10 Update Callback
 * @remarks
**************************************************************************************************/
extern void HAL_TIMER_10_UpdateCallback(void);

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_10 Compare 1 Callback
 * @remarks
**************************************************************************************************/
extern void HAL_TIMER_10_Compare1Callback(void);

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_0_9 interrupt
 * @remarks HAL_TIMER_0 Update Interrupt and HAL_TIMER_9 Global Interrupt
**************************************************************************************************/
void HAL_TIMER_0_9_Interrupt(void);

#endif /* _HAL_TIMER_H_ */
