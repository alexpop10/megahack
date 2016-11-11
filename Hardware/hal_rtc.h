/**************************************************************************************************
 * @file    hal_rtc.h
 * @brief   Microprocessor RTC module
 * @author  Control Data Systems, Mircea Caprioru
 * @date    January 2015
 * @changes Created
**************************************************************************************************/
#ifndef _HAL_RTC_H_
#define _HAL_RTC_H_

#include "typedefs.h"

#define RTC_TR_RESERVED_MASK    ((uint32_t)0x007F7F7F)
#define RTC_DR_RESERVED_MASK    ((uint32_t)0x00FFFF3F) 
#define RTC_INIT_MASK           ((uint32_t)0xFFFFFFFF)  
#define RTC_RSF_MASK            ((uint32_t)0xFFFFFF5F)


#define RTC_EXTI_ALARMS 18
#define RTC_EXTI_TAMPER_TIMESTAMP 19
#define RTC_EXTI_WAKEUP 20

#define FORMAT_12H 1
#define FORMAT_24H 0

typedef enum
{

  HAL_RTC_Mode_Calendar = 1,
  HAL_RTC_Mode_AlarmA = 2,
  HAL_RTC_Mode_AlarmB = 4,
  HAL_RTC_Mode_Wakeup =8
  
} HAL_RTC_Mode;

typedef enum
{
	HAL_RTC_Disable = 0,
	HAL_RTC_Enable
} HAL_RTC_IntMode;
typedef enum
{
	HAL_RTC_WakeupInt = 0,
	HAL_RTC_AlarmAInt,
	HAL_RTC_AlarmBInt,
	HAL_RTC_TamperInt
} HAL_RTC_Interrupts;
typedef struct
{
  uint8_t m_uc;
}HAL_RTC_Alarm;

typedef struct
{
	uint16_t m_unPeriod;
}HAL_RTC_Wakeup;

typedef struct
{
  /* Date */
	uint8_t  m_ucWeekDay;
	uint8_t  m_ucMonth;
	uint8_t  m_ucDate;
	uint8_t  m_ucYear;
  /* Time */
	uint8_t  m_ucHours;
	uint8_t  m_ucMinutes;
	uint8_t  m_ucSeconds;
	uint8_t  m_ucTimeFormat;
  uint32_t m_ulSubSeconds;
  uint32_t m_ulSecondFraction;
}HAL_RTC_Calendar;

typedef struct
{
  uint8_t m_ucPrePriority : 4;
  uint8_t m_ucSubPriority : 4;
}HAL_RTC_Interrupt;

typedef struct
{
	uint8_t            m_ucAsyncPrescaler;
  uint16_t           m_unSyncPrescaler : 15;
  uint8_t            m_ucMode;
  HAL_RTC_Alarm    m_stAlarm;
  HAL_RTC_Wakeup   m_stWakeup;
  HAL_RTC_Calendar m_stCalendar;
  HAL_RTC_Interrupt m_stInterrupt;
}HAL_RTC_Flags;

extern RTC_TypeDef *g_pstHAL_RTC;

void HAL_RTC_DisableProtection(void);

void HAL_RTC_EnableProtection(void);
void HAL_RTC_SetWkuTimerPeriod(uint16_t p_unPeriod);
/**************************************************************************************************
 * @author  Control Data Systems, Mircea Caprioru
 * @brief   RTC configuration
 * @remarks
**************************************************************************************************/
void HAL_RTC_Config(HAL_RTC_Flags p_stFlags);
/**************************************************************************************************
 * @author  Control Data Systems, Mircea Caprioru
 * @brief   RTC alarm configuration function
 * @remarks
**************************************************************************************************/
void HAL_RTC_AlarmConfig(void);
/**************************************************************************************************
 * @author  Control Data Systems, Mircea Caprioru
 * @brief   RTC interrupt Wakeup
 * @remarks
**************************************************************************************************/
void HAL_RTC_WakeUp_Interrupt(void);
/**************************************************************************************************
* @author  Control Data Systems, Stefan Vos
* @brief   RTC interrupt Alarms
* @remarks
**************************************************************************************************/
void HAL_RTC_Alarms_Interrupt(void);
/**************************************************************************************************
* @author  Control Data Systems, Stefan Vos
* @brief   RTC interrupt Tamper
* @remarks
**************************************************************************************************/
void HAL_RTC_Tamper_Interrupt(void);
/**************************************************************************************************
 * @author  Control Data Systems, Vos Stefan
 * @brief   Converts Bcd to Byte
 * @remarks
**************************************************************************************************/
uint8_t HAL_RTC_Bcd2Byte(uint8_t p_ucValue);
/**************************************************************************************************
 * @author  Control Data Systems, Vos Stefan
 * @brief   Converts Byte to Bcd
 * @remarks
**************************************************************************************************/
uint8_t HAL_RTC_Byte2Bcd(uint8_t p_ucValue);
/**************************************************************************************************
 * @author  Control Data Systems, Vos Stefan
 * @brief   Returns time and Date
 * @remarks
**************************************************************************************************/
void HAL_RTC_GetTimeDate(HAL_RTC_Calendar *p_pstDateTime);
/**************************************************************************************************
 * @author  Control Data Systems, Vos Stefan
 * @brief   Sets time and Date
 * @remarks
**************************************************************************************************/
void HAL_RTC_SetTimeDate(HAL_RTC_Calendar p_pstDateTime);
/**************************************************************************************************
 * @author  Control Data Systems, Vos Stefan
 * @brief   Sets/resets interrupt
 * @remarks
**************************************************************************************************/
void HAL_RTC_SetInterrupt(uint8_t p_ucInterrupt, uint8_t p_ucMode);
/**************************************************************************************************
 * @author  Control Data Systems, Vos Stefan
 * @brief   Sets time and Date for Alarm
 * @remarks
**************************************************************************************************/
void HAL_RTC_SetAlarm(HAL_RTC_Calendar p_pstDateTime);
/**************************************************************************************************
* @author  Control Data Systems, Stefan Vos
* @brief   RTC Alarm Callback
* @remarks
**************************************************************************************************/
extern void HAL_RTC_AlarmsCallback(void);
/**************************************************************************************************
* @author  Control Data Systems, Andrei Rusu
* @brief   RTC Wakeup Callback
* @remarks
**************************************************************************************************/
extern void HAL_RTC_WakeupCallback(void);
#endif /* _HAL_RTC_H_ */
