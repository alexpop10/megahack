/**************************************************************************************************
 * @file    log.h
 * @brief   Logging
 * @author  Control Data Systems, Andrei Rusu, Mircea Caprioru
 * @date    June 2014
 * @changes Created
**************************************************************************************************/
#ifndef _LOG_H_
#define _LOG_H_

#include "typedefs.h"

#define UART_LOG HAL_UART_0

/**************************************************************************************************
 * @author    Control Data Systems, Andrei Rusu, Mircea Caprioru
 * @brief     Writes data over an interface
 * @param[in] format Variable input
 * @remarks
**************************************************************************************************/
void Log(char *format, ...);

/**************************************************************************************************
 * @author    Control Data Systems, Andrei Rusu, Mircea Caprioru
 * @brief     Writes a string over a interface
 * @param[in] pucBuff The buffer to write
 * @remarks
**************************************************************************************************/
void puts(uint8_t *pucBuff);

/**************************************************************************************************
 * @author    Control Data Systems, Andrei Rusu, Mircea Caprioru
 * @brief     Writes a char over a interface
 * @param[in] pucBuff The buffer to write
 * @remarks
**************************************************************************************************/
void putc(uint8_t ucChar); 

/**************************************************************************************************
 * @author    Control Data Systems, Andrei Rusu, Mircea Caprioru
 * @brief     LOG initialization
 * @param[in] pucBuff The buffer to write
 * @remarks
**************************************************************************************************/
void LOG_Init();

void LogArray(uint8_t *p_ucData, uint8_t ucSize, uint8_t ucType);

#endif /* _LOG_H_ */
