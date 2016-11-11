/**************************************************************************************************
 * @file    timers.c
 * @brief   Application low-power mode interface
 * @author  Control Data Systems, Andrei Rusu
 * @date    October 2015
 * @changes Created
**************************************************************************************************/
#include "lpm.h"
#include "hal_lpm.h"
#include "hal_clock.h"
#include "hal_gpio.h"

uint8_t g_ucCanGoToSleep = 1;

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_LPM_0 Enter Callback
 * @remarks
**************************************************************************************************/
void HAL_LPM_0_EnterCallback()
{
	//TODO: Add your code here.
}

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_LPM_0 Exit Callback
 * @remarks
**************************************************************************************************/
void HAL_LPM_0_ExitCallback()
{
	//TODO: Add your code here.
}

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_LPM_1 Enter Callback
 * @remarks
**************************************************************************************************/
void HAL_LPM_1_EnterCallback()
{
	//TODO: Add your code here.
}

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_LPM_1 Exit Callback
 * @remarks
**************************************************************************************************/
void HAL_LPM_1_ExitCallback()
{
	//TODO: Add your code here.
}

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_LPM_2 Enter Callback
 * @remarks
**************************************************************************************************/
void HAL_LPM_2_EnterCallback()
{
	//TODO: Add your code here.
}

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_LPM_2 Exit Callback
 * @remarks
**************************************************************************************************/
void HAL_LPM_2_ExitCallback()
{
	//TODO: Add your code here.
}

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_LPM_3 Enter Callback
 * @remarks
**************************************************************************************************/
void HAL_LPM_3_EnterCallback()
{
	//TODO: Add your code here.
	HAL_GPIO_Write(HAL_GPIO_3, HAL_GPIO_PIN_2, HAL_GPIO_LOW);
}

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_LPM_3 Exit Callback
 * @remarks
**************************************************************************************************/
void HAL_LPM_3_ExitCallback()
{
	//TODO: Add your code here.
	HAL_CLOCK_Update(HAL_CLOCK_SOURCE__PLL);
	
	RCC->CR |= RCC_CR_HSION;
	while(RCC->CR & RCC_CR_HSIRDY == 0);
	
	HAL_GPIO_Write(HAL_GPIO_3, HAL_GPIO_PIN_2, HAL_GPIO_HIGH);
}

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_LPM_4 Enter Callback
 * @remarks
**************************************************************************************************/
void HAL_LPM_4_EnterCallback()
{
	//TODO: Add your code here.
}

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_LPM_4 Exit Callback
 * @remarks
**************************************************************************************************/
void HAL_LPM_4_ExitCallback()
{
	//TODO: Add your code here.
}

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_LPM_5 Enter Callback
 * @remarks
**************************************************************************************************/
void HAL_LPM_5_EnterCallback()
{
	//TODO: Add your code here.
}

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_LPM_5 Exit Callback
 * @remarks
**************************************************************************************************/
void HAL_LPM_5_ExitCallback()
{
	//TODO: Add your code here.
}

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_LPM_6 Enter Callback
 * @remarks
**************************************************************************************************/
void HAL_LPM_6_EnterCallback()
{
	//TODO: Add your code here.
}

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_LPM_6 Exit Callback
 * @remarks
**************************************************************************************************/
void HAL_LPM_6_ExitCallback()
{
	//TODO: Add your code here.
}
