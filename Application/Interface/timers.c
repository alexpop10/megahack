/**************************************************************************************************
 * @file    timers.c
 * @brief   Application timers interface
 * @author  Control Data Systems, Andrei Rusu
 * @date    October 2015
 * @changes Created
**************************************************************************************************/
#include "timers.h"
#include "hal_timer.h"
#include "hal_lptim.h"
#include "hal_gpio.h"
#include "hal_lpm.h"
#include "gpio.h"
#include "log.h"

/*timer notification flags*/
uint8_t g_ucTimerIntervalFlag;
uint8_t g_ucTimer250MsFlag;

/**************************************************************************************************
 * @author  Control Data Systems, Mircea Caprioru
 * @brief   Timer initializations
 * @remarks
**************************************************************************************************/
void HAL_TIMER_Init(void)
{
//    HAL_TIMER_Flags l_stFlags = {0};
//    
//    l_stFlags.m_ucClock = HAL_TIMER_CLOCK__SYSTEM;
//    l_stFlags.m_ucDirection = HAL_TIMER_DIRECTION__UP;
//    l_stFlags.m_stCompare.m_unPrescaler = 59999;
//    l_stFlags.m_stCompare.m_unCC0 = 999;
//    l_stFlags.m_stInterrupt.m_ucPrePriority = 15;
//    l_stFlags.m_stInterrupt.m_ucSubPriority = 15;
//    
//    HAL_TIMER_Config(HAL_TIMER_0, l_stFlags);
//    HAL_TIMER_SetInterrupt(HAL_TIMER_0, HAL_TIMER_INTERRUPT__UPDATE);
//    HAL_TIMER_SetState(HAL_TIMER_0, HAL_TIMER_ENABLE);
//    
//    l_stFlags.m_ucClock = HAL_TIMER_CLOCK__ALTERNATE;
//    l_stFlags.m_ucDirection = HAL_TIMER_DIRECTION__UP;
//	l_stFlags.m_stCompare.m_unPrescaler = 0;
//    l_stFlags.m_stCompare.m_unCC0 = 0x1FFF;
//    l_stFlags.m_stInterrupt.m_ucPrePriority = 15;
//    l_stFlags.m_stInterrupt.m_ucSubPriority = 15;
//    
//    HAL_TIMER_Config(HAL_TIMER_1, l_stFlags);
//    HAL_TIMER_SetInterrupt(HAL_TIMER_1, HAL_TIMER_INTERRUPT__DISABLE);
//	HAL_TIMER_SetState(HAL_TIMER_1, HAL_TIMER_ENABLE);
}

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   Low-power timer initializations
 * @remarks
**************************************************************************************************/
void HAL_LPTIM_Init(void)
{
//    HAL_LPTIM_Flags l_stFlags = {0};
//    
//    l_stFlags.m_stCompare.m_unCC0 = 0x1FFF;
//    l_stFlags.m_stCompare.m_unCC0 = 0x0333;
//    l_stFlags.m_stInterrupt.m_ucPrePriority = 2;
//    l_stFlags.m_stInterrupt.m_ucSubPriority = 0;
//    
//    HAL_LPTIM_Config(HAL_LPTIM_0, l_stFlags);
//    HAL_LPTIM_SetInterrupt(HAL_LPTIM_0, HAL_LPTIM_INTERRUPT__UPDATE + HAL_LPTIM_INTERRUPT__CC);
//    
//    l_stFlags.m_stCompare.m_unCC0 = 0x1FFF;
//    l_stFlags.m_stCompare.m_unCC0 = 0x0333;
//    l_stFlags.m_stInterrupt.m_ucPrePriority = 2;
//    l_stFlags.m_stInterrupt.m_ucSubPriority = 0;
//    
//    HAL_LPTIM_Config(HAL_LPTIM_1, l_stFlags);
//    HAL_LPTIM_SetInterrupt(HAL_LPTIM_1, HAL_LPTIM_INTERRUPT__UPDATE + HAL_LPTIM_INTERRUPT__CC);
}

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_0 Update Callback
 * @remarks
**************************************************************************************************/
void HAL_TIMER_0_UpdateCallback(void)
{
	//TODO: Add your code here.
}

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_0 Compare 1 Callback
 * @remarks
**************************************************************************************************/
void HAL_TIMER_0_Compare1Callback(void)
{
	//TODO: Add your code here.
}

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_0 Compare 2 Callback
 * @remarks
**************************************************************************************************/
void HAL_TIMER_0_Compare2Callback(void)
{
	//TODO: Add your code here.
}

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_0 Compare 3 Callback
 * @remarks
**************************************************************************************************/
void HAL_TIMER_0_Compare3Callback(void)
{
	//TODO: Add your code here.
}

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_0 Compare 4 Callback
 * @remarks
**************************************************************************************************/
void HAL_TIMER_0_Compare4Callback(void)
{
	//TODO: Add your code here.
}

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_1 Update Callback
 * @remarks
**************************************************************************************************/
void HAL_TIMER_1_UpdateCallback(void)
{
    //TODO: Add your code here.
}

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_1 Compare 1 Callback
 * @remarks
**************************************************************************************************/
void HAL_TIMER_1_Compare1Callback(void)
{
    //TODO: Add your code here.
}

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_1 Compare 2 Callback
 * @remarks
**************************************************************************************************/
void HAL_TIMER_1_Compare2Callback(void)
{
	//TODO: Add your code here.
}

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_1 Compare 3 Callback
 * @remarks
**************************************************************************************************/
void HAL_TIMER_1_Compare3Callback(void)
{
	//TODO: Add your code here.
}

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_1 Compare 4 Callback
 * @remarks
**************************************************************************************************/
void HAL_TIMER_1_Compare4Callback(void)
{
	//TODO: Add your code here.
}

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_2 Update Callback
 * @remarks
**************************************************************************************************/
void HAL_TIMER_2_UpdateCallback(void)
{
	//TODO: Add your code here.
}

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_2 Compare 1 Callback
 * @remarks
**************************************************************************************************/
void HAL_TIMER_2_Compare1Callback(void)
{
	//TODO: Add your code here.
}

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_2 Compare 2 Callback
 * @remarks
**************************************************************************************************/
void HAL_TIMER_2_Compare2Callback(void)
{
	//TODO: Add your code here.
}

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_2 Compare 3 Callback
 * @remarks
**************************************************************************************************/
void HAL_TIMER_2_Compare3Callback(void)
{
	//TODO: Add your code here.
}

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_2 Compare 4 Callback
 * @remarks
**************************************************************************************************/
void HAL_TIMER_2_Compare4Callback(void)
{
	//TODO: Add your code here.
}

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_3 Update Callback
 * @remarks
**************************************************************************************************/
void HAL_TIMER_3_UpdateCallback(void)
{
	//TODO: Add your code here.
}

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_3 Compare 1 Callback
 * @remarks
**************************************************************************************************/
void HAL_TIMER_3_Compare1Callback(void)
{
	//TODO: Add your code here.
}

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_3 Compare 2 Callback
 * @remarks
**************************************************************************************************/
void HAL_TIMER_3_Compare2Callback(void)
{
	//TODO: Add your code here.
}

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_3 Compare 3 Callback
 * @remarks
**************************************************************************************************/
void HAL_TIMER_3_Compare3Callback(void)
{
	//TODO: Add your code here.
}

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_3 Compare 4 Callback
 * @remarks
**************************************************************************************************/
void HAL_TIMER_3_Compare4Callback(void)
{
	//TODO: Add your code here.
}

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_4 Update Callback
 * @remarks
**************************************************************************************************/
void HAL_TIMER_4_UpdateCallback(void)
{
	//TODO: Add your code here.
}

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_4 Compare 1 Callback
 * @remarks
**************************************************************************************************/
void HAL_TIMER_4_Compare1Callback(void)
{
	//TODO: Add your code here.
}

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_4 Compare 2 Callback
 * @remarks
**************************************************************************************************/
void HAL_TIMER_4_Compare2Callback(void)
{
	//TODO: Add your code here.
}

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_4 Compare 3 Callback
 * @remarks
**************************************************************************************************/
void HAL_TIMER_4_Compare3Callback(void)
{
	//TODO: Add your code here.
}

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_4 Compare 4 Callback
 * @remarks
**************************************************************************************************/
void HAL_TIMER_4_Compare4Callback(void)
{
	//TODO: Add your code here.
}

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_5 Update Callback
 * @remarks
**************************************************************************************************/
void HAL_TIMER_5_UpdateCallback(void)
{
	//TODO: Add your code here.
}

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_6 Update Callback
 * @remarks
**************************************************************************************************/
void HAL_TIMER_6_UpdateCallback(void)
{
	//TODO: Add your code here.
}

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_7 Update Callback
 * @remarks
**************************************************************************************************/
void HAL_TIMER_7_UpdateCallback(void)
{
	//TODO: Add your code here.
}

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_7 Compare 1 Callback
 * @remarks
**************************************************************************************************/
void HAL_TIMER_7_Compare1Callback(void)
{
	//TODO: Add your code here.
}

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_7 Compare 2 Callback
 * @remarks
**************************************************************************************************/
void HAL_TIMER_7_Compare2Callback(void)
{
	//TODO: Add your code here.
}

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_7 Compare 3 Callback
 * @remarks
**************************************************************************************************/
void HAL_TIMER_7_Compare3Callback(void)
{
	//TODO: Add your code here.
}

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_7 Compare 4 Callback
 * @remarks
**************************************************************************************************/
void HAL_TIMER_7_Compare4Callback(void)
{
	//TODO: Add your code here.
}

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_8 Update Callback
 * @remarks
**************************************************************************************************/
void HAL_TIMER_8_UpdateCallback(void)
{
	//TODO: Add your code here.
}

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_8 Compare 1 Callback
 * @remarks
**************************************************************************************************/
void HAL_TIMER_8_Compare1Callback(void)
{
	//TODO: Add your code here.
}

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_8 Compare 2 Callback
 * @remarks
**************************************************************************************************/
void HAL_TIMER_8_Compare2Callback(void)
{
	//TODO: Add your code here.
}

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_8 Compare 3 Callback
 * @remarks
**************************************************************************************************/
void HAL_TIMER_8_Compare3Callback(void)
{
	//TODO: Add your code here.
}

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_9 Update Callback
 * @remarks
**************************************************************************************************/
void HAL_TIMER_9_UpdateCallback(void)
{
	//TODO: Add your code here.
}

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_9 Compare 1 Callback
 * @remarks
**************************************************************************************************/
void HAL_TIMER_9_Compare1Callback(void)
{
	//TODO: Add your code here.
}

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_10 Update Callback
 * @remarks
**************************************************************************************************/
void HAL_TIMER_10_UpdateCallback(void)
{
	//TODO: Add your code here.
}

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_TIMER_10 Compare 1 Callback
 * @remarks
**************************************************************************************************/
void HAL_TIMER_10_Compare1Callback(void)
{
	//TODO: Add your code here.
}

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_LPTIM_0 Update Callback
 * @remarks
**************************************************************************************************/
void HAL_LPTIM_0_UpdateCallback(void)
{
    //TODO: Add your code here.
}

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_LPTIM_0 Compare Callback
 * @remarks
**************************************************************************************************/
void HAL_LPTIM_0_CompareCallback(void)
{
    //TODO: Add your code here.
}

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_LPTIM_1 Update Callback
 * @remarks
**************************************************************************************************/
void HAL_LPTIM_1_UpdateCallback(void)
{
	//TODO: Add your code here.
}

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_LPTIM_1 Compare Callback
 * @remarks
**************************************************************************************************/
void HAL_LPTIM_1_CompareCallback(void)
{
	//TODO: Add your code here.
}
