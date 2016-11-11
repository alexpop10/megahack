/**************************************************************************************************
 * @file    hal_spi.h
 * @brief   Microprocessor SPI module
 * @author  Control Data Systems, Mircea Caprioru
 * @date    July 2014
 * @changes Created
**************************************************************************************************/
#ifndef _HAL_SPI_H_
#define _HAL_SPI_H_

#include "typedefs.h"
#include "hal_gpio.h"
#include "hal_clock.h"

enum HAL_SPI_Module
{
  HAL_SPI_0 = 0,
  HAL_SPI_1,
  HAL_SPI_2,
  
  HAL_SPI_NO
};

typedef struct
{
	uint8_t m_ucPrePriority : 4;
	uint8_t m_ucSubPriority : 4;
}HAL_SPI_Interrupt;

typedef struct
{
  uint8_t m_ucMode :1;
  uint8_t m_ucCLKPhase : 1;
  uint8_t m_ucCLKPolarity : 1;
  uint8_t m_ucFirstBit : 1;
  HAL_SPI_Interrupt m_stInterrupt;
}HAL_SPI_Flags;

#define HAL_SPI_Master (uint8_t)0x1  
#define HAL_SPI_Slave  (uint8_t)0x0
#define HAL_SPI_16b    (uint8_t)0x1 
#define HAL_SPI_8b     (uint8_t)0x0 
#define HAL_SPI_Low    (uint8_t)0x0              
#define HAL_SPI_High   (uint8_t)0x1   
#define HAL_SPI_1Edge  (uint8_t)0x0                
#define HAL_SPI_2Edge  (uint8_t)0x1                
#define HAL_SPI_MSB    (uint8_t)0x0              
#define HAL_SPI_LSB    (uint8_t)0x1  

#if (PLL_CLOCK == PLL_80_MHZ)

#define  HAL_SPI_40_MHZ    0x00
#define  HAL_SPI_20_MHZ    0x01
#define  HAL_SPI__MHZ      0x02
#define  HAL_SPI_5_MHZ     0x03
#define  HAL_SPI_2_5_MHZ   0x04
#define  HAL_SPI_1_25_MHZ  0x05
#define  HAL_SPI_625_KHZ   0x06
#define  HAL_SPI_312_5_KHZ 0x07

#elif (PLL_CLOCK == PLL_64_MHZ)

#define  HAL_SPI_32_MHZ  0x00
#define  HAL_SPI_16_MHZ  0x01
#define  HAL_SPI_8_MHZ   0x02
#define  HAL_SPI_4_MHZ   0x03
#define  HAL_SPI_2_MHZ   0x04
#define  HAL_SPI_1_MHZ   0x05
#define  HAL_SPI_500_KHZ 0x06
#define  HAL_SPI_250_KHZ 0x07

#else

#warning "Define new SPI speeds"

#endif /* PLL_CLOCK */

enum HAL_SPI_Interrupt 
{
  HAL_SPI_NONE = 0,
  HAL_SPI_RX,
  HAL_SPI_TX
};

enum HAL_SPI_State
{
  HAL_SPI_DISABLE = 0,
  HAL_SPI_ENABLE
};

/**************************************************************************************************
 * @author  Control Data Systems, Mircea Caprioru
 * @brief   SPI initializations
 * @remarks
**************************************************************************************************/  
void HAL_SPI_Init(void);

/**************************************************************************************************
 * @author    Control Data Systems, Mircea Caprioru
 * @brief     SPI configuration
 * @param[in] ucModule - the SPI module
 * @param[in] unFlags - the flags (master, slave, etc ...)
 * @remarks
**************************************************************************************************/  
void HAL_SPI_Config(uint8_t ucModule, uint8_t ucSpeed, HAL_SPI_Flags unFlags);

/**************************************************************************************************
 * @author    Control Data Systems, Andrei Rusu
 * @brief     SPI set state
 * @param[in] ucModule - SPI module
 * @param[in] ucState - SPI state ENABLE/DISABLE
 * @remarks
**************************************************************************************************/
void HAL_SPI_SetState(uint8_t ucModule, uint8_t ucState);

/**************************************************************************************************
 * @author    Control Data Systems, Mircea Caprioru
 * @brief     SPI send char
 * @param[in] ucChar - represents the byte to be sent
 * @return    Received data from SPI 
 * @remarks
**************************************************************************************************/
uint8_t HAL_SPI_SendChar(uint8_t ucModule, uint8_t ucChar);

/**************************************************************************************************
 * @author    Control Data Systems, Mircea Caprioru
 * @brief     SPI configuration with DMA
 * @param[in] ucModule - the GPIO module
 * @param[in] ucSpeed - the set SPI speed value
 * @remarks
**************************************************************************************************/
void HAL_SPI_DMA_Config(uint8_t ucModule, uint8_t ucSpeed);

/**************************************************************************************************
 * @author    Control Data Systems, Mircea Caprioru
 * @brief     SPI send buffer with DMA
 * @param[in] ucModule - the GPIO module
 * @param[in] ucSendBuff - the buffer to send
 * @param[in] ucReceiveBuff - for storing received data
 * @param[in] ucBuffSize size of buffers
 * @remarks
**************************************************************************************************/  
void HAL_SPI_DMA_SendBuff(uint8_t ucModule, uint8_t *pucSendBuff, uint8_t *pucReceiveBuff, uint16_t ucBuffSize);

/**************************************************************************************************
 * @author    Control Data Systems, Mircea Caprioru
 * @brief     SPI get interrupt status
 * @param[in] ucModule - the UART module
 * @param[in] ucInterrupt - which interrupt status to receive
 * @return    Interrupt status
 * @remarks
**************************************************************************************************/
uint8_t HAL_SPI_GetInterruptStatus(uint8_t ucModule, uint8_t ucInterrupt);

/**************************************************************************************************
 * @author    Control Data Systems, Andrei Rusu
 * @brief     SPI set interrupt
 * @param[in] ucModule - the SPI module
 * @param[in] ucInterrupt - specify which interrupt to enable
 * @param[in] ucState - enable or disable interrupt
 * @remarks
**************************************************************************************************/
void HAL_SPI_SetInterrupt(uint8_t ucModule, uint8_t ucInterrupt, uint8_t ucState);

/**************************************************************************************************
 * @author    Control Data Systems, Andrei Rusu
 * @brief     HAL_SPI_0 interrupt
 * @remarks
**************************************************************************************************/ 
void HAL_SPI_0_Interrupt(void);

/**************************************************************************************************
 * @author    Control Data Systems, Andrei Rusu
 * @brief     HAL_SPI_0 RX callback
 * @remarks
 **************************************************************************************************/
extern void HAL_SPI_0_RxCallback(void);

/**************************************************************************************************
 * @author    Control Data Systems, Andrei Rusu
 * @brief     HAL_SPI_0 TX callback
 * @remarks
 **************************************************************************************************/
extern void HAL_SPI_0_TxCallback(void);

/**************************************************************************************************
 * @author    Control Data Systems, Andrei Rusu
 * @brief     HAL_SPI_1 interrupt
 * @remarks
**************************************************************************************************/ 
void HAL_SPI_1_Interrupt(void);
/**************************************************************************************************
 * @author    Control Data Systems, Andrei Rusu
 * @brief     HAL_SPI_1 RX callback
 * @remarks
 **************************************************************************************************/
extern void HAL_SPI_1_RxCallback(void);

/**************************************************************************************************
 * @author    Control Data Systems, Andrei Rusu
 * @brief     HAL_SPI_1 TX callback
 * @remarks
 **************************************************************************************************/
extern void HAL_SPI_1_TxCallback(void);

/**************************************************************************************************
 * @author    Control Data Systems, Andrei Rusu
 * @brief     HAL_SPI_2 interrupt
 * @remarks
**************************************************************************************************/ 
void HAL_SPI_2_Interrupt(void);

/**************************************************************************************************
 * @author    Control Data Systems, Andrei Rusu
 * @brief     HAL_SPI_2 RX callback
 * @remarks
 **************************************************************************************************/
extern void HAL_SPI_2_RxCallback(void);

/**************************************************************************************************
 * @author    Control Data Systems, Andrei Rusu
 * @brief     HAL_SPI_2 TX callback
 * @remarks
 **************************************************************************************************/
extern void HAL_SPI_2_TxCallback(void);

#endif /* _HAL_SPI_H_ */
