/**************************************************************************************************
 * @file    uart.h
 * @brief   Application UART interface
 * @author  Control Data Systems, Andrei Rusu
 * @date    October 2015
 * @changes Created
**************************************************************************************************/
#ifndef _UART_H_
#define _UART_H_

#include "hal_uart.h"

#define API_UART HAL_UART_2
#define IRDA_UART HAL_UART_1

extern uint8_t g_aucUartRx[];
extern uint8_t g_aucUartTx[];
extern uint8_t g_ucMsgIdx;
extern uint8_t g_ucMsgSize;
extern uint8_t g_ucReceiving;
extern uint8_t g_ucReceived;

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   UART initializations
 * @remarks
**************************************************************************************************/
void HAL_UART_Init(void);

#endif /* _UART_H_ */
