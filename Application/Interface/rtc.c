/**************************************************************************************************
 * @file    rtc.c
 * @brief   Application RTC interface
 * @author  Control Data Systems, Andrei Rusu
 * @date    December 2015
 * @changes Created
**************************************************************************************************/
#include "rtc.h"
#include "hal_rtc.h"
#include "hal_gpio.h"

void HAL_RTC_Init(void)
{
  HAL_RTC_Flags l_stFlags;

  l_stFlags.m_ucAsyncPrescaler = 0;
  l_stFlags.m_unSyncPrescaler = 0x7FFF; // This will result in a 1 Hz freq with LSE - 32768 Hz
  l_stFlags.m_stCalendar.m_ucYear = 0x15;
  l_stFlags.m_stCalendar.m_ucMonth = 9;
  l_stFlags.m_stCalendar.m_ucDate = 0x24;
  l_stFlags.m_stCalendar.m_ucWeekDay = 4;
  l_stFlags.m_stCalendar.m_ucHours = 0x17;
  l_stFlags.m_stCalendar.m_ucMinutes = 0x50;
  l_stFlags.m_stCalendar.m_ucSeconds = 0x00;
  l_stFlags.m_stCalendar.m_ucTimeFormat = FORMAT_24H;

  l_stFlags.m_stWakeup.m_unPeriod = 0x0FFF; // 250 ms
  l_stFlags.m_ucMode = HAL_RTC_Mode_Calendar | HAL_RTC_Mode_Wakeup;

  l_stFlags.m_stInterrupt.m_ucPrePriority = 2;
  l_stFlags.m_stInterrupt.m_ucSubPriority = 0;

  HAL_RTC_Config(l_stFlags);
}

/**************************************************************************************************
* @author  Control Data Systems, Andrei Rusu
* @brief   RTC Wakeup Callback
* @remarks
**************************************************************************************************/
void HAL_RTC_WakeupCallback(void)
{
	//TODO: Add your code here.
}
