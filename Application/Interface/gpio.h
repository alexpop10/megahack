/**************************************************************************************************
 * @file    gpio.h
 * @brief   Application GPIO interface
 * @author  Control Data Systems, Andrei Rusu
 * @date    October 2015
 * @changes Created
**************************************************************************************************/
#ifndef _GPIO_H_
#define _GPIO_H_

#include "typedefs.h"
#include "hal_gpio.h"

/* PA0 */
#define RDY_PORT        HAL_GPIO_0
#define RDY_PIN	        HAL_GPIO_PIN_0

/* PA1 */
#define WKU_PORT        HAL_GPIO_0
#define WKU_PIN     	HAL_GPIO_PIN_1

/* PB1 */
#define RTS_PORT	HAL_GPIO_1
#define RTS_PIN     	HAL_GPIO_PIN_1

/* PB13 */
#define CTS_PORT	HAL_GPIO_1
#define CTS_PIN     	HAL_GPIO_PIN_13

/* PB5 */
#define VN_RST_PORT     HAL_GPIO_1
#define VN_RST_PIN      HAL_GPIO_PIN_5

///* P1.7 */
//#define VN_STATUS_PORT	AP_GPIO_PORT_0
//#define VN_STATUS_PIN	AP_GPIO_PIN_7

#define ADC_BAT_PORT HAL_GPIO_2
#define ADC_BAT_PIN  HAL_GPIO_PIN_0

#define HART_LC_PORT HAL_GPIO_2
#define HART_LC_PIN  HAL_GPIO_PIN_1

#define MCU_ADC3_PORT HAL_GPIO_2
#define MCU_ADC3_PIN  HAL_GPIO_PIN_2

#define MCU_ADC4_PORT HAL_GPIO_2
#define MCU_ADC4_PIN  HAL_GPIO_PIN_3

#define MCU_GPIO6_PORT HAL_GPIO_2
#define MCU_GPIO6_PIN  HAL_GPIO_PIN_6

#define MCU_GPIO7_PORT HAL_GPIO_2
#define MCU_GPIO7_PIN  HAL_GPIO_PIN_7

#define MCU_GPIO8_PORT HAL_GPIO_2
#define MCU_GPIO8_PIN  HAL_GPIO_PIN_8

#define MCU_GPIO9_PORT HAL_GPIO_2
#define MCU_GPIO9_PIN  HAL_GPIO_PIN_9

#define MCU_GPIO10_PORT HAL_GPIO_2
#define MCU_GPIO10_PIN  HAL_GPIO_PIN_10

#define MCU_GPIO11_PORT HAL_GPIO_2
#define MCU_GPIO11_PIN  HAL_GPIO_PIN_11

extern uint8_t g_ucWkuPort;
extern uint8_t g_ucRdyPort;
extern uint8_t g_ucCtsPort;
extern uint8_t g_ucRtsPort;

extern uint8_t g_ucWkuPin;
extern uint8_t g_ucRdyPin;
extern uint8_t g_ucCtsPin;
extern uint8_t g_ucRtsPin;

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   GPIO port/pin initializations
 * @remarks
**************************************************************************************************/  
void HAL_GPIO_Init(void);

#endif /* _GPIO_H_ */
