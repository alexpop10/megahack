/**************************************************************************************************
 * @file    uart.c
 * @brief   Application uart interface
 * @author  Control Data Systems, Andrei Rusu
 * @date    October 2015
 * @changes Created
**************************************************************************************************/
#include "uart.h"
#include "hal_lpm.h"
#include "timers.h"
#include "gpio.h"
#include "string.h"

#include "simple_api.h"

uint8_t g_aucUartRx[100];
uint8_t g_aucUartTx[100];
uint8_t g_ucMsgIdx;
uint8_t g_ucMsgSize;
uint8_t g_ucReceiving;
uint8_t g_ucReceived;

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   UART initializations
 * @remarks
**************************************************************************************************/
void HAL_UART_Init(void)
{
	HAL_UART_Flags l_stFlags = {0};
	
	l_stFlags.m_ucHwFlowCtl = HAL_UART_FLOWCONTROL_NONE;
	l_stFlags.m_ucIRDA = HAL_UART_IRDA_DISABLED;
	l_stFlags.m_ucParity = HAL_UART_PARITY_NONE;
	l_stFlags.m_ucStopBits = HAL_UART_STOPBITS_1;
	l_stFlags.m_ucWordLength = HAL_UART_WORDLENGTH_8;
	
	/* Configure the VN210 interface. */
	HAL_UART_Config(API_UART, (uint32_t) 38400, l_stFlags);
	HAL_UART_SetInterrupt(API_UART, HAL_UART_RX, HAL_UART_ENABLE);
	HAL_UART_SetState(API_UART, HAL_UART_ENABLE);
	
	//l_stFlags.m_ucIRDA = HAL_UART_IRDA_ENABLED;
	
	/* Configure the IrDA interface. */
	HAL_UART_Config(IRDA_UART, (uint32_t) 9600, l_stFlags);
	HAL_UART_SetInterrupt(IRDA_UART, HAL_UART_RX, HAL_UART_ENABLE);
	HAL_UART_SetState(IRDA_UART, HAL_UART_ENABLE);
}

/**************************************************************************************************
 * @author Control Data Systems, Andrei Rusu
 * @brief  HAL_UART_0 RX callback
 * @remarks
**************************************************************************************************/
void HAL_UART_0_RxCallback(void)
{
	//TODO: Add your code here.
}

/**************************************************************************************************
 * @author Control Data Systems, Andrei Rusu
 * @brief  HAL_UART_0 TX callback
 * @remarks
**************************************************************************************************/
void HAL_UART_0_TxCallback(void)
{
	//TODO: Add your code here.
}

/**************************************************************************************************
 * @author Control Data Systems, Andrei Rusu
 * @brief  HAL_UART_1 RX callback
 * @remarks
**************************************************************************************************/
void HAL_UART_1_RxCallback(void)
{
	//TODO: Add your code here.
}

/**************************************************************************************************
 * @author Control Data Systems, Andrei Rusu
 * @brief  HAL_UART_1 TX callback
 * @remarks
**************************************************************************************************/
void HAL_UART_1_TxCallback(void)
{
	//TODO: Add your code here.
}

/**************************************************************************************************
 * @author Control Data Systems, Andrei Rusu
 * @brief  HAL_UART_2 RX callback
 * @remarks
**************************************************************************************************/
void HAL_UART_2_RxCallback(void)
{
	//TODO: Add your code here.
	uint8_t l_ucRxByte;
	
	l_ucRxByte = HAL_UART_ReceiveChar(HAL_UART_2);
	
	if (g_ucReceiving)
	{		
		if (l_ucRxByte == CTX)
		{
			g_aucUartRx[g_ucMsgIdx] = l_ucRxByte;
			g_ucMsgIdx--;
		}
		else
		{
			if (l_ucRxByte == 0x0E)
			{
				if (g_aucUartRx[g_ucMsgIdx] == CTX)
				{
					g_aucUartRx[g_ucMsgIdx] = ~0x0E;
				}
				else
				{
					g_aucUartRx[g_ucMsgIdx] = l_ucRxByte;
				}
			}
			else
			{
				if (l_ucRxByte == 0x0D)
				{
					if (g_aucUartRx[g_ucMsgIdx] == CTX)
					{
						g_aucUartRx[g_ucMsgIdx] = ~0x0D;
					}
					else
					{
						g_aucUartRx[g_ucMsgIdx] = l_ucRxByte;
					}
				}
				else
				{
					g_aucUartRx[g_ucMsgIdx] = l_ucRxByte;
				}
			}
		}
		
		if (g_ucMsgIdx == 4)
		{
			g_ucMsgSize = g_aucUartRx[g_ucMsgIdx];
		}
		
		g_ucMsgIdx++;
		
		if (g_ucMsgIdx == (5 + g_ucMsgSize + 2))
		{
			g_ucReceived = 1;
			g_ucReceiving = 0;
			HAL_GPIO_Write(HAL_GPIO_1, HAL_GPIO_PIN_1, HAL_GPIO_HIGH);
		}
	}
	else
	{
		if (l_ucRxByte == STX)
		{
			g_ucReceiving = 1;
			g_ucMsgIdx = 0;
			g_aucUartRx[g_ucMsgIdx] = l_ucRxByte;
			g_ucMsgIdx++;
		}
	}
	
}

/**************************************************************************************************
 * @author Control Data Systems, Andrei Rusu
 * @brief  HAL_UART_2 TX callback
 * @remarks
**************************************************************************************************/
void HAL_UART_2_TxCallback(void)
{
  //TODO: Add your code here.
}

/**************************************************************************************************
 * @author Control Data Systems, Andrei Rusu
 * @brief  HAL_UART_3 RX callback
 * @remarks
**************************************************************************************************/
void HAL_UART_3_RxCallback(void)
{
  //TODO: Add your code here.
}

/**************************************************************************************************
 * @author Control Data Systems, Andrei Rusu
 * @brief  HAL_UART_3 TX callback
 * @remarks
**************************************************************************************************/
void HAL_UART_3_TxCallback(void)
{
  //TODO: Add your code here.
}

/**************************************************************************************************
 * @author Control Data Systems, Andrei Rusu
 * @brief  HAL_UART_4 RX callback
 * @remarks
**************************************************************************************************/
void HAL_UART_4_RxCallback(void)
{
  //TODO: Add your code here.
}

/**************************************************************************************************
 * @author Control Data Systems, Andrei Rusu
 * @brief  HAL_UART_4 TX callback
 * @remarks
**************************************************************************************************/
void HAL_UART_4_TxCallback(void)
{
  //TODO: Add your code here.
}
