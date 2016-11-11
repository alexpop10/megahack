/**************************************************************************************************
 * @file    hal_gpio.h
 * @brief   Microprocessor GPIO module
 * @author  Control Data Systems, Mircea Caprioru
 * @date    July 2014
 * @changes Created
**************************************************************************************************/
#ifndef _HAL_GPIO_H_
#define _HAL_GPIO_H_

#include "typedefs.h"

enum HAL_GPIO
{
  HAL_GPIO_0 = ((uint8_t) 0x00),
  HAL_GPIO_1,
  HAL_GPIO_2,
  HAL_GPIO_3,
  HAL_GPIO_4,
  HAL_GPIO_5,
  HAL_GPIO_6,
  HAL_GPIO_7,
  
  HAL_GPIO_NO
};

enum HAL_GPIO_PIN
{
  HAL_GPIO_PIN_0 = ((uint8_t) 0x00),
  HAL_GPIO_PIN_1,
  HAL_GPIO_PIN_2,
  HAL_GPIO_PIN_3,
  HAL_GPIO_PIN_4,
  HAL_GPIO_PIN_5,
  HAL_GPIO_PIN_6,
  HAL_GPIO_PIN_7,
  HAL_GPIO_PIN_8,
  HAL_GPIO_PIN_9,
  HAL_GPIO_PIN_10,
  HAL_GPIO_PIN_11,
  HAL_GPIO_PIN_12,
  HAL_GPIO_PIN_13,
  HAL_GPIO_PIN_14,
  HAL_GPIO_PIN_15,
  
  HAL_GPIO_PIN_NO
};

#define HAL_GPIO_MODE__INPUT    ((uint8_t) 0x00)
#define HAL_GPIO_MODE__OUTPUT   ((uint8_t) 0x01)
#define HAL_GPIO_MODE__FUNCTION ((uint8_t) 0x02)
#define HAL_GPIO_MODE__ANALOG   ((uint8_t) 0x03)

#define HAL_GPIO_TYPE__PP ((uint8_t) 0x00)
#define HAL_GPIO_TYPE__OD ((uint8_t) 0x01)

#define HAL_GPIO_SPEED__LOW    ((uint8_t) 0x00)
#define HAL_GPIO_SPEED__MEDIUM ((uint8_t) 0x01)
#define HAL_GPIO_SPEED__FAST   ((uint8_t) 0x02)
#define HAL_GPIO_SPEED__HIGH   ((uint8_t) 0x03)

#define HAL_GPIO_PULL__NO_PULL ((uint8_t) 0x00)
#define HAL_GPIO_PULL__UP      ((uint8_t) 0x01)
#define HAL_GPIO_PULL__DOWN    ((uint8_t) 0x02)

#define HAL_GPIO_FUNCTION__0  ((uint8_t) 0x00)
#define HAL_GPIO_FUNCTION__1  ((uint8_t) 0x01)
#define HAL_GPIO_FUNCTION__2  ((uint8_t) 0x02)
#define HAL_GPIO_FUNCTION__3  ((uint8_t) 0x03)
#define HAL_GPIO_FUNCTION__4  ((uint8_t) 0x04)
#define HAL_GPIO_FUNCTION__5  ((uint8_t) 0x05)
#define HAL_GPIO_FUNCTION__6  ((uint8_t) 0x06)
#define HAL_GPIO_FUNCTION__7  ((uint8_t) 0x07)
#define HAL_GPIO_FUNCTION__8  ((uint8_t) 0x08)
#define HAL_GPIO_FUNCTION__9  ((uint8_t) 0x09)
#define HAL_GPIO_FUNCTION__10 ((uint8_t) 0x0A)
#define HAL_GPIO_FUNCTION__11 ((uint8_t) 0x0B)
#define HAL_GPIO_FUNCTION__12 ((uint8_t) 0x0C)
#define HAL_GPIO_FUNCTION__13 ((uint8_t) 0x0D)
#define HAL_GPIO_FUNCTION__14 ((uint8_t) 0x0E)
#define HAL_GPIO_FUNCTION__15 ((uint8_t) 0x0F)

#define HAL_GPIO_INTERRUPT__DISABLE ((uint8_t) 0x00)
#define HAL_GPIO_INTERRUPT__RISING  ((uint8_t) 0x01)
#define HAL_GPIO_INTERRUPT__FALLING ((uint8_t) 0x02)

#define HAL_GPIO_PIN_CLEAR ((uint8_t) 0x03)

typedef struct
{
  uint8_t m_ucIntType : 2;
  uint8_t m_ucPrePriority : 4;
  uint8_t m_ucSubPriority : 4;
}HAL_GPIO_Interrupt;

typedef struct
{
  uint8_t m_ucMode : 2;
  uint8_t m_ucType : 1;
  uint8_t m_ucSpeed : 2;
  uint8_t m_ucPull : 2;
  uint8_t m_ucFunction : 4;
  HAL_GPIO_Interrupt m_stInterrupt;
}HAL_GPIO_Flags;

enum HAL_GPIO_PIN_STATE
{
  HAL_GPIO_LOW = ((uint8_t) 0x00),
  HAL_GPIO_HIGH,
  HAL_GPIO_TOGGLE,
  HAL_GPIO_PULSE
};

enum HAL_GPIO_States
{
  HAL_GPIO_DISABLE = ((uint8_t) 0x00),
  HAL_GPIO_ENABLE
};

/**************************************************************************************************
 * @author    Control Data Systems, Mircea Caprioru
 * @brief     GPIO port/pin configuration
 * @param[in] ucModule - the GPIO module
 * @param[in] ucPin - the GPIO pin
 * @param[in] unFlags - the flags (input, output, etc ...)
 * @remarks
**************************************************************************************************/  
void HAL_GPIO_Config(uint8_t ucModule, uint8_t ucPin, HAL_GPIO_Flags stFlags);
/**************************************************************************************************
 * @author    Control Data Systems, Mircea Caprioru
 * @brief     GPIO port/pin read
 * @param[in] ucModule - the GPIO module
 * @param[in] ucPin - the GPIO pin
 * @return    The pin state
 * @remarks
**************************************************************************************************/  
uint8_t HAL_GPIO_Read(uint8_t ucModule, uint8_t ucPin);

/**************************************************************************************************
 * @author    Control Data Systems, Mircea Caprioru
 * @brief     GPIO port/pin write
 * @param[in] ucModule - the GPIO module
 * @param[in] ucPin - the GPIO pin
 * @param[in] ucState - the pin state to be written
 * @remarks
**************************************************************************************************/  
void HAL_GPIO_Write(uint8_t ucModule, uint8_t ucPin, uint8_t ucState);

/**************************************************************************************************
 * @author    Control Data Systems, Mircea Caprioru
 * @brief     GPIO get interrupt status
 * @param[in] ucModule - the GPIO module
 * @param[in] ucPin - the GPIO pin
 * @return    The interrupt status
 * @remarks
**************************************************************************************************/
uint8_t HAL_GPIO_GetInterruptStatus(uint8_t ucModule, uint8_t ucPin);

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_EXTI_0 interrupt
 * @remarks
**************************************************************************************************/
void HAL_EXTI_0_Interrupt(void);
/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_EXTI_0 callback
 * @remarks
 **************************************************************************************************/
extern void HAL_EXTI_0_Callback(void);

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_EXTI_1 interrupt
 * @remarks
**************************************************************************************************/
void HAL_EXTI_1_Interrupt(void);
/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_EXTI_1 callback
 * @remarks
 **************************************************************************************************/
extern void HAL_EXTI_1_Callback(void);

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_EXTI_2 interrupt
 * @remarks
**************************************************************************************************/
void HAL_EXTI_2_Interrupt(void);
/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_EXTI_2 callback
 * @remarks
 **************************************************************************************************/
extern void HAL_EXTI_2_Callback(void);

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_EXTI_3 interrupt
 * @remarks
**************************************************************************************************/
void HAL_EXTI_3_Interrupt(void);
/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_EXTI_3 callback
 * @remarks
 **************************************************************************************************/
extern void HAL_EXTI_3_Callback(void);

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_EXTI_4 interrupt
 * @remarks
**************************************************************************************************/
void HAL_EXTI_4_Interrupt(void);
/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_EXTI_4 callback
 * @remarks
 **************************************************************************************************/
extern void HAL_EXTI_4_Callback(void);

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_EXTI_9_5 interrupt
 * @remarks
**************************************************************************************************/
void HAL_EXTI_9_5_Interrupt(void);
/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_EXTI_5 callback
 * @remarks
 **************************************************************************************************/
extern void HAL_EXTI_5_Callback(void);

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_EXTI_6 callback
 * @remarks
 **************************************************************************************************/
extern void HAL_EXTI_6_Callback(void);

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_EXTI_7 callback
 * @remarks
 **************************************************************************************************/
extern void HAL_EXTI_7_Callback(void);

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_EXTI_8 callback
 * @remarks
 **************************************************************************************************/
extern void HAL_EXTI_8_Callback(void);

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_EXTI_9 callback
 * @remarks
 **************************************************************************************************/
extern void HAL_EXTI_9_Callback(void);

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_EXTI_15_10 interrupt
 * @remarks
**************************************************************************************************/
void HAL_EXTI_15_10_Interrupt(void);

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_EXTI_10 callback
 * @remarks
 **************************************************************************************************/
extern void HAL_EXTI_10_Callback(void);

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_EXTI_11 callback
 * @remarks
 **************************************************************************************************/
extern void HAL_EXTI_11_Callback(void);

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_EXTI_12 callback
 * @remarks
 **************************************************************************************************/
extern void HAL_EXTI_12_Callback(void);

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_EXTI_13 callback
 * @remarks
 **************************************************************************************************/
extern void HAL_EXTI_13_Callback(void);

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_EXTI_14 callback
 * @remarks
 **************************************************************************************************/
extern void HAL_EXTI_14_Callback(void);

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   HAL_EXTI_15 callback
 * @remarks
 **************************************************************************************************/
extern void HAL_EXTI_15_Callback(void);

#endif /* _HAL_GPIO_H_ */ 
