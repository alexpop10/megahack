/**************************************************************************************************
 * @file    hal_i2c.h
 * @brief   Microprocessor SPI module
 * @author  Control Data Systems, Stefan Vos
 * @date    September 2015
 * @changes Created
**************************************************************************************************/
#ifndef _HAL_I2C_H_
#define _HAL_I2C_H_

#include "typedefs.h"
#include "hal_gpio.h"

enum HAL_I2C_Module
{
  HAL_I2C_0 = 0, // I2C1
  HAL_I2C_1,     // I2C2
  HAL_I2C_2,     // I2C3
  
  HAL_I2C_NO
};

typedef struct
{
  uint8_t  m_ucSpeed:1;
  uint8_t  m_ucAddrMode:1;
  uint8_t  m_ucGeneralCall:1;
  uint16_t m_unOwnAddr; 
}HAL_I2C_Flags;

typedef enum
{
  HAL_I2C_Speed10kHz = 0,
  HAL_I2C_Speed100kHz,
  HAL_I2C_Speed400kHz,
  HAL_I2C_Speed1000kHz,
}HAL_I2C_Speed;


typedef enum 
{
  HAL_I2C_DISABLE = 0,
  HAL_I2C_ENABLE
}HAL_I2C_State;

enum HAL_I2C_Operation
{
	HAL_I2C_WRITE = ((uint8_t) 0x00),
	HAL_I2C_READ
};

extern I2C_TypeDef *g_apstHAL_I2C[HAL_I2C_NO];

#define HAL_I2C_GeneralCallEnabled  (uint8_t)0x1
#define HAL_I2C_GeneralCallDisabled (uint8_t)0x0
#define HAL_I2C_Addr7Bit            (uint8_t)0x0
#define HAL_I2C_Addr10Bit           (uint8_t)0x1

#define I2C_FLAG_MASK  ((uint32_t)0x0001FFFF)

/**************************************************************************************************
* @author  Control Data Systems, Stefan Vos
* @brief   I2C initializations
* @remarks
**************************************************************************************************/  
void HAL_I2C_Init(void);

/**************************************************************************************************
* @author    Control Data Systems, Stefan Vos
* @brief     I2C configuration
* @param[in] ucModule - the I2C module
* @param[in] unFlags - the flags (addr, etc ...)
* @remarks
**************************************************************************************************/ 
void HAL_I2C_Config(uint8_t ucModule, HAL_I2C_Flags stFlags);

/**************************************************************************************************
 * @author    Control Data Systems, Andrei Rusu
 * @brief     I2C generate start condition
 * @param[in] ucModule - the I2C module (e.g. HAL_I2C_0)
 * @param[in] ucAddress - the slave address
 * @param[in] ucOperation - the operation (e.g. HAL_I2C_READ)
 * @remarks
**************************************************************************************************/
void HAL_I2C_StartCondition(uint8_t ucModule, uint8_t ucAddress, uint8_t ucOperation);

/**************************************************************************************************
 * @author    Control Data Systems, Andrei Rusu
 * @brief     I2C write byte
 * @param[in] ucModule - the I2C module (e.g. HAL_I2C_0)
 * @param[in] ucByte - the byte to write
 * @remarks
**************************************************************************************************/
void HAL_I2C_WriteByte(uint8_t ucModule, uint8_t ucByte);

/**************************************************************************************************
 * @author    Control Data Systems, Andrei Rusu
 * @brief     I2C read byte
 * @param[in] ucModule - the I2C module (e.g. HAL_I2C_0)
 * @return    the read byte
 * @remarks
**************************************************************************************************/
uint8_t HAL_I2C_ReadByte(uint8_t ucModule);

/**************************************************************************************************
 * @author    Control Data Systems, Andrei Rusu
 * @brief     I2C set number of bytes to read/write
 * @param[in] ucModule - the I2C module (e.g. HAL_I2C_0)
 * @param[in] ucByte - the byte to write
 * @remarks
**************************************************************************************************/
void HAL_I2C_WriteNoBytes(uint8_t ucModule, uint8_t ucNoBytes);

/**************************************************************************************************
 * @author    Control Data Systems, Andrei Rusu
 * @brief     I2C generate stop condition
 * @param[in] ucModule - the I2C module (e.g. HAL_I2C_0)
 * @remarks
**************************************************************************************************/
void HAL_I2C_StopCondition(uint8_t ucModule);

/**************************************************************************************************
* @author    Control Data Systems, Vos Stefan
* @brief     I2C master transmit
* @param[in] p_ucModule - i2c module
* @param[in] p_unSlaveAddress - the slave address
* @param[in] p_pucData - the data to be transmitted
* @param[in] p_ucDatasize - size of p_pucData
* @return    none 
* @remarks
**************************************************************************************************/
void HAL_I2C_MasterTransmit(uint8_t p_ucModule, uint16_t p_unSlaveAddress, uint8_t *p_pucData, uint8_t p_ucDatasize);

/**************************************************************************************************
* @author    Control Data Systems, Vos Stefan
* @brief     I2C master receive
* @param[in] p_ucModule - i2c module
* @param[in] p_unSlaveAddress - the slave address
* @param[in] p_pucData - the data to be transmitted
* @param[in] p_ucDatasize - size of p_pucData
* @return    none 
* @remarks
**************************************************************************************************/
void HAL_I2C_MasterReceive(uint8_t p_ucModule, uint16_t p_unSlaveAddress, uint8_t *p_pucData, uint8_t *p_pucDatasize);

/**************************************************************************************************
* @author    Control Data Systems, Vos Stefan
* @brief     I2C set interrupt
* @param[in] p_ucModule - the I2C module
* @param[in] p_ucInterrupt - specify which interrupt to enable 
params can be: I2C_CR1_TXIE,
I2C_CR1_RXIE,
I2C_CR1_ADDRIE,
I2C_CR1_NACKIE,
I2C_CR1_STOPIE,
I2C_CR1_TCIE,
I2C_CR1_ERRIE
or any combination
* @param[in] p_ucState - enable or disable interrupt
* @remarks
**************************************************************************************************/
void HAL_I2C_SetInterrupt(uint8_t p_ucModule, uint8_t p_ucInterrupt, uint8_t p_ucState);

/**************************************************************************************************
* @author    Control Data Systems, Stefan Vos
* @brief     HAL_I2C_0_EV interrupt
* @remarks
**************************************************************************************************/ 
void HAL_I2C_0_EV_Interrupt(void);

/**************************************************************************************************
* @author    Control Data Systems, Stefan Vos
* @brief     HAL_I2C_0_ER interrupt
* @remarks
**************************************************************************************************/ 
void HAL_I2C_0_ER_Interrupt(void);

/**************************************************************************************************
* @author    Control Data Systems, Stefan Vos
* @brief     HAL_I2C_0_EV interrupt
* @remarks
**************************************************************************************************/ 
void HAL_I2C_1_EV_Interrupt(void);

/**************************************************************************************************
* @author    Control Data Systems, Stefan Vos
* @brief     HAL_I2C_1_ER interrupt
* @remarks
**************************************************************************************************/ 
void HAL_I2C_1_ER_Interrupt(void);
/**************************************************************************************************
* @author    Control Data Systems, Stefan Vos
* @brief     HAL_I2C_2_EV interrupt
* @remarks
**************************************************************************************************/ 
void HAL_I2C_2_EV_Interrupt(void);

/**************************************************************************************************
* @author    Control Data Systems, Stefan Vos
* @brief     HAL_I2C_2_ER interrupt
* @remarks
**************************************************************************************************/ 
void HAL_I2C_2_ER_Interrupt(void);

#endif /* _HAL_I2C_H_ */



