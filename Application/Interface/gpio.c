/**************************************************************************************************
 * @file    gpio.c
 * @brief   Application GPIO interface
 * @author  Control Data Systems, Andrei Rusu
 * @date    October 2015
 * @changes Created
**************************************************************************************************/
#include "gpio.h"
#include "log.h"
#include "uart.h"
#include "lpm.h"
#include "simple_api.h"

uint8_t g_ucWkuPort = WKU_PORT;
uint8_t g_ucRdyPort = RDY_PORT;
uint8_t g_ucCtsPort = CTS_PORT;
uint8_t g_ucRtsPort = RTS_PORT;

uint8_t g_ucWkuPin = WKU_PIN;
uint8_t g_ucRdyPin = RDY_PIN;
uint8_t g_ucCtsPin = CTS_PIN;
uint8_t g_ucRtsPin = RTS_PIN;

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   GPIO port/pin initializations
 * @remarks
**************************************************************************************************/  
void HAL_GPIO_Init(void)
{  
	HAL_GPIO_Flags l_stFlags = {0};
	
	l_stFlags.m_ucMode = HAL_GPIO_MODE__OUTPUT;
	l_stFlags.m_ucType = HAL_GPIO_TYPE__PP;
	l_stFlags.m_ucSpeed = HAL_GPIO_SPEED__HIGH;
	l_stFlags.m_ucPull = HAL_GPIO_PULL__NO_PULL;
	l_stFlags.m_stInterrupt.m_ucIntType = HAL_GPIO_INTERRUPT__DISABLE;
	
	/* Init D3 */  
	HAL_GPIO_Config(HAL_GPIO_3, HAL_GPIO_PIN_2, l_stFlags);
	HAL_GPIO_Write(HAL_GPIO_3, HAL_GPIO_PIN_2, HAL_GPIO_LOW);
	
	/* Init D4 */
	HAL_GPIO_Config(HAL_GPIO_2, HAL_GPIO_PIN_12, l_stFlags);
	HAL_GPIO_Write(HAL_GPIO_2, HAL_GPIO_PIN_12, HAL_GPIO_LOW);
	
	/* Init IrDA SD */
	HAL_GPIO_Config(HAL_GPIO_1, HAL_GPIO_PIN_2, l_stFlags);
	HAL_GPIO_Write(HAL_GPIO_1, HAL_GPIO_PIN_2, HAL_GPIO_LOW);
	
	/* Init WKU */
	HAL_GPIO_Config(WKU_PORT, WKU_PIN, l_stFlags);
	HAL_GPIO_Write(WKU_PORT, WKU_PIN, HAL_GPIO_LOW);
	
	/* Init ExtRTS */
	HAL_GPIO_Config(RTS_PORT, RTS_PIN, l_stFlags);
	HAL_GPIO_Write(RTS_PORT, RTS_PIN, HAL_GPIO_HIGH);
	
	l_stFlags.m_ucType = HAL_GPIO_TYPE__OD;
		
	/* Init VN_RESET */
	HAL_GPIO_Config(VN_RST_PORT, VN_RST_PIN, l_stFlags);
	HAL_GPIO_Write(VN_RST_PORT, VN_RST_PIN, HAL_GPIO_LOW);
	
	l_stFlags.m_ucMode = HAL_GPIO_MODE__INPUT;
	l_stFlags.m_ucType = HAL_GPIO_TYPE__PP;
	l_stFlags.m_ucSpeed = HAL_GPIO_SPEED__HIGH;
	l_stFlags.m_ucPull = HAL_GPIO_PULL__NO_PULL;
	l_stFlags.m_stInterrupt.m_ucIntType = HAL_GPIO_INTERRUPT__FALLING;
	
	/* Init RDY */
	HAL_GPIO_Config(RDY_PORT, RDY_PIN, l_stFlags);
		
	/* Init ExtCTS */
	HAL_GPIO_Config(CTS_PORT, CTS_PIN, l_stFlags);
	
	l_stFlags.m_ucMode = HAL_GPIO_MODE__ANALOG;
	l_stFlags.m_ucType = HAL_GPIO_TYPE__PP;
	l_stFlags.m_ucSpeed = HAL_GPIO_SPEED__HIGH;
	
	/* Init ADC_BAT */
	HAL_GPIO_Config(ADC_BAT_PORT, ADC_BAT_PIN, l_stFlags);
	
	/* Init HART_LC */
	HAL_GPIO_Config(HART_LC_PORT, HART_LC_PIN, l_stFlags);
	
	/* Init MCU_ADC3 */
	HAL_GPIO_Config(MCU_ADC3_PORT, MCU_ADC3_PIN, l_stFlags);
	
	/* Init MCU_ADC4 */
	HAL_GPIO_Config(MCU_ADC4_PORT, MCU_ADC4_PIN, l_stFlags);
	
	l_stFlags.m_ucMode = HAL_GPIO_MODE__INPUT;
	l_stFlags.m_ucType = HAL_GPIO_TYPE__PP;
	l_stFlags.m_ucSpeed = HAL_GPIO_SPEED__HIGH;
	l_stFlags.m_ucPull = HAL_GPIO_PULL__NO_PULL;
	l_stFlags.m_stInterrupt.m_ucIntType = HAL_GPIO_INTERRUPT__DISABLE;
	
	/* Init MCU_GPIO6 */
	HAL_GPIO_Config(MCU_GPIO6_PORT, MCU_GPIO6_PIN, l_stFlags);
	
	/* Init MCU_GPIO7 */
	HAL_GPIO_Config(MCU_GPIO7_PORT, MCU_GPIO7_PIN, l_stFlags);
	
	/* Init MCU_GPIO8 */
	HAL_GPIO_Config(MCU_GPIO8_PORT, MCU_GPIO8_PIN, l_stFlags);
	
	/* Init MCU_GPIO9 */
	HAL_GPIO_Config(MCU_GPIO9_PORT, MCU_GPIO9_PIN, l_stFlags);
	
	/* Init MCU_GPIO10 */
	HAL_GPIO_Config(MCU_GPIO10_PORT, MCU_GPIO10_PIN, l_stFlags);
	
	/* Init MCU_GPIO11 */
	HAL_GPIO_Config(MCU_GPIO11_PORT, MCU_GPIO11_PIN, l_stFlags);
}

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_EXTI_0 callback
 * @remarks
**************************************************************************************************/
void HAL_EXTI_0_Callback(void)
{
	//TODO: Add your code here.
	g_ucRadioReady = 1;
	//HAL_GPIO_Write(HAL_GPIO_0, HAL_GPIO_PIN_1, HAL_GPIO_LOW);
}

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_EXTI_1 callback
 * @remarks
**************************************************************************************************/
void HAL_EXTI_1_Callback(void)
{
  //TODO: Add your code here.
}

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_EXTI_2 callback
 * @remarks
**************************************************************************************************/
void HAL_EXTI_2_Callback(void)
{
  //TODO: Add your code here.
}

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_EXTI_3 callback
 * @remarks
**************************************************************************************************/
void HAL_EXTI_3_Callback(void)
{
  //TODO: Add your code here.
}

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_EXTI_4 callback
 * @remarks
**************************************************************************************************/
void HAL_EXTI_4_Callback(void)
{
  //TODO: Add your code here.
}

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_EXTI_5 callback
 * @remarks
**************************************************************************************************/
void HAL_EXTI_5_Callback(void)
{
  //TODO: Add your code here.
}

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_EXTI_6 callback
 * @remarks
**************************************************************************************************/
void HAL_EXTI_6_Callback(void)
{
  //TODO: Add your code here.
}

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_EXTI_7 callback
 * @remarks
**************************************************************************************************/
void HAL_EXTI_7_Callback(void)
{
  //TODO: Add your code here.
}

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_EXTI_8 callback
 * @remarks
**************************************************************************************************/
void HAL_EXTI_8_Callback(void)
{
  //TODO: Add your code here.
}

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_EXTI_9 callback
 * @remarks
**************************************************************************************************/
void HAL_EXTI_9_Callback(void)
{
  //TODO: Add your code here.
}

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_EXTI_10 callback
 * @remarks
**************************************************************************************************/
void HAL_EXTI_10_Callback(void)
{
  //TODO: Add your code here.
}

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_EXTI_11 callback
 * @remarks
**************************************************************************************************/
void HAL_EXTI_11_Callback(void)
{
  //TODO: Add your code here.
}

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_EXTI_12 callback
 * @remarks
**************************************************************************************************/
void HAL_EXTI_12_Callback(void)
{
  //TODO: Add your code here.
}

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_EXTI_13 callback
 * @remarks
**************************************************************************************************/
void HAL_EXTI_13_Callback(void)
{
	//TODO: Add your code here.
	HAL_LPM_3_Exit();
	g_ucCanGoToSleep = 0;
	HAL_GPIO_Write(HAL_GPIO_1, HAL_GPIO_PIN_1, HAL_GPIO_LOW);
}

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_EXTI_14 callback
 * @remarks
**************************************************************************************************/
void HAL_EXTI_14_Callback(void)
{
  //TODO: Add your code here.
}

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_EXTI_15 callback
 * @remarks
**************************************************************************************************/
void HAL_EXTI_15_Callback(void)
{
  //TODO: Add your code here.
}
