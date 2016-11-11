/**************************************************************************************************
 * @file    hal_lpm.h
 * @brief   Microcontroller low-power mode module
 * @author  Control Data Systems, Andrei Rusu
 * @date    September 2015
 * @changes Created
**************************************************************************************************/
#ifndef _HAL_LPM_H_
#define _HAL_LPM_H_

#include "typedefs.h"

enum HAL_LPM
{
	HAL_LPM_0 = ((uint8_t) 0x00), // Low-power run mode
	HAL_LPM_1,                    // Sleep mode
	HAL_LPM_2,                    // Low-power sleep mode
	HAL_LPM_3,                    // Stop 1 mode
	HAL_LPM_4,                    // Stop 2 mode
	HAL_LPM_5,                    // Standby mode
	HAL_LPM_6,                    // Shutdown mode

	HAL_LPM_NO
};

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   Enter HAL_LPM_0
 * @remarks
**************************************************************************************************/
extern void HAL_LPM_0_Enter(void);

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_LPM_0 Enter Callback
 * @remarks
**************************************************************************************************/
extern void HAL_LPM_0_EnterCallback();

/**************************************************************************************************
* @author  Control Data Systems, Andrei Rusu
* @brief   Exit HAL_LPM_0
* @remarks
**************************************************************************************************/
extern void HAL_LPM_0_Exit(void);

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_LPM_0 Exit Callback
 * @remarks
**************************************************************************************************/
extern void HAL_LPM_0_ExitCallback();

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   Enter HAL_LPM_1
 * @remarks
**************************************************************************************************/
extern void HAL_LPM_1_Enter(void);

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_LPM_1 Enter Callback
 * @remarks
**************************************************************************************************/
extern void HAL_LPM_1_EnterCallback();

/**************************************************************************************************
* @author  Control Data Systems, Andrei Rusu
* @brief   Exit HAL_LPM_1
* @remarks
**************************************************************************************************/
extern void HAL_LPM_1_Exit(void);

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_LPM_1 Exit Callback
 * @remarks
**************************************************************************************************/
extern void HAL_LPM_1_ExitCallback();

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   Enter HAL_LPM_2
 * @remarks
**************************************************************************************************/
extern void HAL_LPM_2_Enter(void);

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_LPM_2 Enter Callback
 * @remarks
**************************************************************************************************/
extern void HAL_LPM_2_EnterCallback();

/**************************************************************************************************
* @author  Control Data Systems, Andrei Rusu
* @brief   Exit HAL_LPM_2
* @remarks
**************************************************************************************************/
extern void HAL_LPM_2_Exit(void);

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_LPM_2 Exit Callback
 * @remarks
**************************************************************************************************/
extern void HAL_LPM_2_ExitCallback();

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   Enter HAL_LPM_3
 * @remarks
**************************************************************************************************/
extern void HAL_LPM_3_Enter(void);

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_LPM_3 Enter Callback
 * @remarks
**************************************************************************************************/
extern void HAL_LPM_3_EnterCallback();

/**************************************************************************************************
* @author  Control Data Systems, Andrei Rusu
* @brief   Exit HAL_LPM_3
* @remarks
**************************************************************************************************/
extern void HAL_LPM_3_Exit(void);

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_LPM_3 Exit Callback
 * @remarks
**************************************************************************************************/
extern void HAL_LPM_3_ExitCallback();

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   Enter HAL_LPM_4
 * @remarks
**************************************************************************************************/
extern void HAL_LPM_4_Enter(void);

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_LPM_4 Enter Callback
 * @remarks
**************************************************************************************************/
extern void HAL_LPM_4_EnterCallback();

/**************************************************************************************************
* @author  Control Data Systems, Andrei Rusu
* @brief   Exit HAL_LPM_4
* @remarks
**************************************************************************************************/
extern void HAL_LPM_4_Exit(void);

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_LPM_4 Exit Callback
 * @remarks
**************************************************************************************************/
extern void HAL_LPM_4_ExitCallback();

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   Enter HAL_LPM_5
 * @remarks
**************************************************************************************************/
extern void HAL_LPM_5_Enter(void);

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_LPM_5 Enter Callback
 * @remarks
**************************************************************************************************/
extern void HAL_LPM_5_EnterCallback();

/**************************************************************************************************
* @author  Control Data Systems, Andrei Rusu
* @brief   Exit HAL_LPM_5
* @remarks
**************************************************************************************************/
extern void HAL_LPM_5_Exit(void);

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_LPM_5 Exit Callback
 * @remarks
**************************************************************************************************/
extern void HAL_LPM_5_ExitCallback();

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   Enter HAL_LPM_6
 * @remarks
**************************************************************************************************/
extern void HAL_LPM_6_Enter(void);

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_LPM_6 Enter Callback
 * @remarks
**************************************************************************************************/
extern void HAL_LPM_6_EnterCallback();

/**************************************************************************************************
* @author  Control Data Systems, Andrei Rusu
* @brief   Exit HAL_LPM_6
* @remarks
**************************************************************************************************/
extern void HAL_LPM_6_Exit(void);

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_LPM_6 Exit Callback
 * @remarks
**************************************************************************************************/
extern void HAL_LPM_6_ExitCallback();

void HAL_LPM_Enter(uint8_t p_ucLpmMode);
void HAL_On_Lpm_Exit(void);
#endif /*_HAL_LPM_H_*/
