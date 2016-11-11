#include "simple_api.h"
#include "string.h"
#include "stdlib.h"
#include "uart.h"
#include "log.h"
#include "adc.h"
#include "SHT21.h"
#include "gpio.h"
#include "lpm.h"
#include "hal_clock.h"
#include "hal_timer.h"

uint8_t g_ucRadioReady;
MESSAGE *g_pstFirst = NULL;
MESSAGE *g_pstLast = NULL;

void API_ParseMessage(uint8_t *p_ucMessage)
{
	uint16_t l_unChecksum = API_ComputeCRC(p_ucMessage, 4 + p_ucMessage[4], 1);
	
	if (l_unChecksum == (uint16_t) (p_ucMessage[5 + p_ucMessage[4]] << 8) + p_ucMessage[5 + p_ucMessage[4] + 1])
	{
		if (g_pstFirst == NULL)
		{
			g_pstFirst = (MESSAGE *) calloc(1, sizeof(MESSAGE));
			
			g_pstFirst->m_stMessageHeader.m_ucMessageClass = p_ucMessage[1] >> 4;
			g_pstFirst->m_stMessageHeader.m_ucIsRsp =  (p_ucMessage[1] & 0x08) >> 3;
			g_pstFirst->m_ucMessageType = p_ucMessage[2];
			g_pstFirst->m_ucMessageID = p_ucMessage[3];
			g_pstFirst->m_ucMessageSize = p_ucMessage[4];
			memcpy(g_pstFirst->m_aucMessageData, &p_ucMessage[5], g_pstFirst->m_ucMessageSize);
			
			g_pstLast = g_pstFirst;
			g_pstFirst->m_pstNext = NULL;
			g_pstFirst->m_pstPrev = NULL;
		}
		else
		{
			g_pstLast->m_pstPrev = (MESSAGE *) calloc(1, sizeof(MESSAGE));
			
			g_pstLast->m_pstPrev->m_stMessageHeader.m_ucMessageClass = p_ucMessage[1] >> 4;
			g_pstLast->m_pstPrev->m_stMessageHeader.m_ucIsRsp =  (p_ucMessage[1] & 0x08) >> 3;
			g_pstLast->m_pstPrev->m_ucMessageType = p_ucMessage[2];
			g_pstLast->m_pstPrev->m_ucMessageID = p_ucMessage[3];
			g_pstLast->m_pstPrev->m_ucMessageSize = p_ucMessage[4];
			memcpy(g_pstLast->m_pstPrev->m_aucMessageData, &p_ucMessage[5], g_pstLast->m_pstPrev->m_ucMessageSize);
			
			g_pstLast->m_pstPrev->m_pstNext = g_pstLast;
			g_pstLast->m_pstPrev->m_pstPrev = NULL;
			g_pstLast = g_pstLast->m_pstPrev;
		}
	}
	else
	{
		//INFO: Bad CRC.
	}
}

void API_HandleMessage(void)
{
	LogArray(g_aucUartRx, 5 + g_aucUartRx[4] + 2, 1);
		
	switch (g_pstFirst->m_stMessageHeader.m_ucMessageClass)
	{
		case DATA_PASSTHROUGH:
		{
			API_OnRcvDataPassTrough();
			break;
		}
		case API_COMMANDS:
		{
			
			break;
		}
	}
	
	if (g_pstFirst->m_pstPrev != NULL)
	{
		g_pstFirst = g_pstFirst->m_pstPrev;
		free(g_pstFirst->m_pstNext);
		g_pstFirst->m_pstNext = NULL;
	}
	else
	{
		g_pstLast = NULL;
		free(g_pstFirst);
		g_pstFirst = NULL;
	}
}

uint16_t API_ComputeCRC(uint8_t *pucData, uint8_t ucSize, uint8_t unStartIdx)
{
	uint16_t unHelpValue;
	uint16_t unCRCValue = 0xFFFF;
	uint16_t unCRCPoly = 0x1021;
	
	uint8_t l_ucByteIndex = unStartIdx;
	uint8_t l_ucBitIdx;
	
	while (ucSize-- > 0)
	{		
		unCRCValue ^= (uint16_t)((pucData[l_ucByteIndex++]) << 8);
		
		for (l_ucBitIdx = 0; l_ucBitIdx < 8; l_ucBitIdx++)
		{
			
			if ((unCRCValue & (uint16_t)0x8000) > 0)
			{
				unCRCValue = (uint16_t)((unCRCValue << 1) ^ unCRCPoly);
			}
			else
			{
				unCRCValue <<= 1;
			}
		}
	}
	
	unHelpValue = unCRCValue;
	unCRCValue = 0xFFFF;
	
	return unHelpValue;
}

void API_OnRcvDataPassTrough(void)
{
	API_ComposeReadDataResponse();
	
	LogArray(g_aucUartTx, 5 + g_aucUartTx[4] + 2, 0);
}

void API_ComposeReadDataResponse(void)
{
	//INFO: Compose the read data response message.
}

void SendMessage(uint8_t *pucData, uint8_t ucSize)
{
	uint8_t l_ucMsgIdx;
	uint16_t l_unTickUs = (uint16_t) (HAL_CLOCK_Get() / 1000000);
	
	HAL_GPIO_Write(WKU_PORT, WKU_PIN, HAL_GPIO_HIGH);
	
	HAL_CLOCK_SysTickEnable(l_unTickUs * 2000);
	while (!g_ucSysTick_Update)
	{
		/* Wait for VN210. */
	}
	g_ucSysTick_Update = 0;
	
	HAL_UART_SendChar(API_UART, pucData[0]);
	
	for (l_ucMsgIdx = 1; l_ucMsgIdx < ucSize; l_ucMsgIdx++)
	{
		switch (pucData[l_ucMsgIdx])
		{
			case STX:
			{
				HAL_UART_SendChar(API_UART, CTX);
				HAL_UART_SendChar(API_UART, (uint8_t) ~STX);
				
				break;
			}
			case CTX:
			{
				HAL_UART_SendChar(API_UART, CTX);
				HAL_UART_SendChar(API_UART, (uint8_t) ~CTX);
				
				break;
			}
			default: 
			{
				HAL_UART_SendChar(API_UART, pucData[l_ucMsgIdx]);
				
				break;
			}
		}	
	}
	
	while (!(USART3->ISR & USART_ISR_TC))
	{
		
	}
	
	HAL_GPIO_Write(WKU_PORT, WKU_PIN, HAL_GPIO_LOW);
}

void API_Task(void)
{
	if (g_ucReceived)
	{
		g_ucReceived = 0;
		
		API_ParseMessage(g_aucUartRx);
	}
	
	if (g_pstFirst != NULL)
	{
		API_HandleMessage();
		
		while (!(USART1->ISR & USART_ISR_TC))
		{
			
		}
		g_ucCanGoToSleep = 1;
	}
}
