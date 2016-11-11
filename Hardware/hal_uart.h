/**************************************************************************************************
 * @file    hal_uart.h
 * @brief   Microprocessor UART module
 * @author  Control Data Systems, Mircea Caprioru
 * @date    July 2014
 * @changes Created
**************************************************************************************************/
#ifndef _HAL_UART_H_
#define _HAL_UART_H_

#include "typedefs.h"
#include "hal_gpio.h"

enum HAL_UART
{
  HAL_UART_0 = 0, 
  HAL_UART_1, 
  HAL_UART_2, 
  HAL_UART_3, 
  HAL_UART_4, 
  
  HAL_UART_NO
};

#define HAL_UART_BAUD_9600    9600U
#define HAL_UART_BAUD_19200   19200U
#define HAL_UART_BAUD_38400   38400U
#define HAL_UART_BAUD_57600   57600U
#define HAL_UART_BAUD_115200  115200U
#define HAL_UART_BAUD_230400  230400U
#define HAL_UART_BAUD_460800  460800U
#define HAL_UART_BAUD_921600  921600U

typedef struct
{
	uint8_t m_ucPrePriority : 4;
	uint8_t m_ucSubPriority : 4;
}HAL_UART_Interrupt;

typedef struct
{
	uint8_t m_ucWordLength : 2;
	uint8_t m_ucStopBits : 2;
	uint8_t m_ucParity : 1;
	uint8_t m_ucHwFlowCtl : 2;
	uint8_t m_ucIRDA : 1;
	HAL_UART_Interrupt m_stInterrupt;
}HAL_UART_Flags; 

#define HAL_UART_WORDLENGTH_7          0x2 // 7-bit long UART frame 
#define HAL_UART_WORDLENGTH_8          0x0 // 8-bit long UART frame 
#define HAL_UART_WORDLENGTH_9          0x1 // 9-bit long UART frame 

#define HAL_UART_PARITY_EVEN           0x2 // Even parity   
#define HAL_UART_PARITY_ODD            0x3 // Odd parity 
#define HAL_UART_PARITY_NONE           0x0 // No parity  

#define HAL_UART_STOPBITS_1            0x0 // 1 stop bit
#define HAL_UART_STOPBITS_2            0x2 // 2 stop bits
#define HAL_UART_STOPBITS_1_5          0x3 // 1.5 stop bits

#define HAL_UART_IRDA_ENABLED          0x1 // IrDA enabled
#define HAL_UART_IRDA_DISABLED         0x0 // IrDA disabled 

#define HAL_UART_FLOWCONTROL_NONE      0x0 // Flow control disabled
#define HAL_UART_FLOWCONTROL_RTS       0x1 // RTS mode enabled
#define HAL_UART_FLOWCONTROL_CTS       0x2 // CTS mode enabled
#define HAL_UART_FLOWCONTROL_RTS_CTS   0x3 // RTS-CTS mode enabled

enum HAL_UART_Interrupt
{
	HAL_UART_NONE = 0,
	HAL_UART_RX,
	HAL_UART_TX
};

enum HAL_UART_State
{
	HAL_UART_DISABLE = 0,
	HAL_UART_ENABLE
};

/**************************************************************************************************
 * @author    Control Data Systems, Mircea Caprioru
 * @brief     UART configuration
 * @param[in] ucModule - the UART module
 * @param[in] ulBaud - the baud rate for UART
 * @param[in] unFlags - the flags (input, output, etc ...)
 * @remarks
**************************************************************************************************/
void HAL_UART_Config(uint8_t ucModule, uint32_t ulBaud, HAL_UART_Flags stFlags);
/**************************************************************************************************
 * @author    Control Data Systems, Andrei Rusu
 * @brief     UART set state
 * @param[in] ucModule - UART module
 * @param[in] ucState - UART state ENABLE/DISABLE
 * @remarks
**************************************************************************************************/
void HAL_UART_SetState(uint8_t ucModule, uint8_t ucState);
/**************************************************************************************************
 * @author    Control Data Systems, Mircea Caprioru
 * @brief     UART set interrupt
 * @param[in] ucModule The UART module
 * @param[in] ucInterrupt - spicify which interrupt to enable
 * @param[in] ucState - enable or disable interrupt
 * @remarks
**************************************************************************************************/
void HAL_UART_SetInterrupt(uint8_t ucModule, uint8_t ucInterrupt, uint8_t ucState);
/**************************************************************************************************
 * @author    Control Data Systems, Mircea Caprioru
 * @brief     UART get interrupt status
 * @param[in] ucModule - the UART module
 * @param[in] ucInterrupt - which interrupt status to receive
 * @return    Interrupt status
 * @remarks
**************************************************************************************************/
uint8_t HAL_UART_GetInterruptStatus(uint8_t ucModule, uint8_t ucInterrupt);
/**************************************************************************************************
 * @author    Control Data Systems, Mircea Caprioru
 * @brief     UART send char
 * @param[in] ucModule - select the UART module
 * @param[in] ucChar - char to send over UART
 * @remarks
**************************************************************************************************/
void HAL_UART_SendChar(uint8_t ucModule, uint8_t ucChar);
/**************************************************************************************************
 * @author    Control Data Systems, Mircea Caprioru
 * @brief     UART receive char
 * @param[in] ucModule - select the UART module
 * @return    the received char
 * @remarks
**************************************************************************************************/
uint8_t HAL_UART_ReceiveChar(uint8_t ucModule);
/**************************************************************************************************
 * @author    Control Data Systems, Mircea Caprioru
 * @brief     UART send buffer 
 * @param[in] ucModule - select the UART module
 * @param[in] pucBuff - buffer to send over UART
 * @param[in] ucSize - size of buffer
 * @remarks
**************************************************************************************************/
void HAL_UART_SendBuff(uint8_t ucModule, uint8_t *pucBuff, uint16_t unSize);
/**************************************************************************************************
 * @author Control Data Systems, Andrei Rusu
 * @brief  HAL_UART_0 interrupt
 * @remarks
**************************************************************************************************/
void HAL_UART_0_Interrupt(void);
/**************************************************************************************************
 * @author Control Data Systems, Andrei Rusu
 * @brief  HAL_UART_0 RX callback
 * @remarks
 **************************************************************************************************/
extern void HAL_UART_0_RxCallback(void);

/**************************************************************************************************
 * @author Control Data Systems, Andrei Rusu
 * @brief  HAL_UART_0 TX callback
 * @remarks
 **************************************************************************************************/
extern void HAL_UART_0_TxCallback(void);

/**************************************************************************************************
 * @author Control Data Systems, Andrei Rusu
 * @brief  HAL_UART_1 interrupt
 * @remarks
**************************************************************************************************/
void HAL_UART_1_Interrupt(void);
/**************************************************************************************************
 * @author Control Data Systems, Andrei Rusu
 * @brief  HAL_UART_1 RX callback
 * @remarks
 **************************************************************************************************/
extern void HAL_UART_1_RxCallback(void);

/**************************************************************************************************
 * @author Control Data Systems, Andrei Rusu
 * @brief  HAL_UART_1 TX callback
 * @remarks
 **************************************************************************************************/
extern void HAL_UART_1_TxCallback(void);

/**************************************************************************************************
 * @author Control Data Systems, Andrei Rusu
 * @brief  HAL_UART_2 interrupt
 * @remarks
**************************************************************************************************/
void HAL_UART_2_Interrupt(void);
/**************************************************************************************************
 * @author Control Data Systems, Andrei Rusu
 * @brief  HAL_UART_2 RX callback
 * @remarks
**************************************************************************************************/
extern void HAL_UART_2_RxCallback(void);
/**************************************************************************************************
 * @author Control Data Systems, Andrei Rusu
 * @brief  HAL_UART_2 TX callback
 * @remarks
**************************************************************************************************/
extern void HAL_UART_2_TxCallback(void);
/**************************************************************************************************
 * @author Control Data Systems, Andrei Rusu
 * @brief  HAL_UART_3 interrupt
 * @remarks
**************************************************************************************************/
void HAL_UART_3_Interrupt(void);
/**************************************************************************************************
 * @author Control Data Systems, Andrei Rusu
 * @brief  HAL_UART_3 RX callback
 * @remarks
 **************************************************************************************************/
extern void HAL_UART_3_RxCallback(void);

/**************************************************************************************************
 * @author Control Data Systems, Andrei Rusu
 * @brief  HAL_UART_3 TX callback
 * @remarks
 **************************************************************************************************/
extern void HAL_UART_3_TxCallback(void);

/**************************************************************************************************
 * @author Control Data Systems, Andrei Rusu
 * @brief  HAL_UART_4 interrupt
 * @remarks
**************************************************************************************************/
void HAL_UART_4_Interrupt(void);
/**************************************************************************************************
 * @author Control Data Systems, Andrei Rusu
 * @brief  HAL_UART_4 RX callback
 * @remarks
 **************************************************************************************************/
extern void HAL_UART_4_RxCallback(void);

/**************************************************************************************************
 * @author Control Data Systems, Andrei Rusu
 * @brief  HAL_UART_4 TX callback
 * @remarks
 **************************************************************************************************/
extern void HAL_UART_4_TxCallback(void);

#endif /* _HAL_UART_H_ */
