/**************************************************************************************************
 * @file    log.c
 * @brief   Logging
 * @author  Control Data Systems, Andrei Rusu, Mircea Caprioru
 * @date    June 2014
 * @changes Created
**************************************************************************************************/
#include "stdarg.h"
#include "hal_uart.h"
#include "log.h"  
 
static const unsigned long dv[] = {
  //  4294967296      // 32 bit unsigned max
  1000000000,// +0
  100000000, // +1
  10000000, // +2
  1000000, // +3
  100000, // +4
  //       65535      // 16 bit unsigned max
  10000, // +5
  1000, // +6
  100, // +7
  10, // +8
  1, // +9
};

/**************************************************************************************************
 * @author    Control Data Systems, Andrei Rusu, Mircea Caprioru
 * @brief     Coverts an integer to ASCII
 * @remarks
**************************************************************************************************/
static void xtoa(unsigned long x, const unsigned long *dp) {
	char c;
	unsigned long d;
	if (x) {
		while (x < *dp)
			++dp;
		do {
			d = *dp++;
			c = '0';
			while (x >= d)
				++c, x -= d;
			putc(c);
		} while (!(d & 1));
	} else
		putc('0');
}

/**************************************************************************************************
 * @author    Control Data Systems, Andrei Rusu, Mircea Caprioru
 * @brief     Coverts an integer to hex
 * @param[in] n The integer
 * @remarks
**************************************************************************************************/
static void puth(unsigned n) {
	static const char hex[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8',
			'9', 'A', 'B', 'C', 'D', 'E', 'F' };
	putc(hex[n & 15]);
}

/**************************************************************************************************
 * @author    Control Data Systems, Andrei Rusu, Mircea Caprioru
 * @brief     Writes data over an interface
 * @param[in] format Variable input
 * @remarks
**************************************************************************************************/
void Log(char *format, ...)
{
	char c;
	int i;
	long n;

	va_list a;
	va_start(a, format);
	while(c = *format++) {
		if(c == '%') {
			switch(c = *format++) {
				case 's': // String
					puts(va_arg(a, unsigned char*));
					break;
				case 'c':// Char
					putc(va_arg(a, int));
				break;
				case 'i':// 16 bit Integer
				case 'u':// 16 bit Unsigned
					i = va_arg(a, int);
					if(c == 'i' && i < 0) i = -i, putc('-');
					xtoa((unsigned)i, dv + 5);
				break;
				case 'l':// 32 bit Long
				case 'n':// 32 bit uNsigned loNg
					n = va_arg(a, long);
					if(c == 'l' && n < 0) n = -n, putc('-');
					xtoa((unsigned long)n, dv);
				break;
				case 'x':// 16 bit heXadecimal
					i = va_arg(a, int);
//					puth(i >> 12);
//					puth(i >> 8);
					puth(i >> 4);
					puth(i);
				break;
				case 0: return;
				default: goto bad_fmt;
			}
		} else
			bad_fmt: putc(c);
	}
	va_end(a);
}

/**************************************************************************************************
 * @author    Control Data Systems, Andrei Rusu, Mircea Caprioru
 * @brief     Writes a string over a interface
 * @param[in] pucBuff The buffer to write
 * @remarks
**************************************************************************************************/
void puts(uint8_t *pucBuff) 
{
  char c;
  
  // Loops through each character in string 's'
  while (c = *pucBuff++) 
  {
   HAL_UART_SendChar(UART_LOG, c);
  }
}

/**************************************************************************************************
 * @author    Control Data Systems, Andrei Rusu, Mircea Caprioru
 * @brief     Writes a char over a interface
 * @param[in] pucBuff The buffer to write
 * @remarks
**************************************************************************************************/
void putc(uint8_t ucChar) 
{
  HAL_UART_SendChar(UART_LOG, ucChar);
}

/**************************************************************************************************
 * @author    Control Data Systems, Andrei Rusu, Mircea Caprioru
 * @brief     LOG initialization
 * @param[in] pucBuff The buffer to write
 * @remarks
**************************************************************************************************/
void LOG_Init(void)
{ 
	HAL_UART_Flags l_stFlags = {0};
	
	l_stFlags.m_ucHwFlowCtl = HAL_UART_FLOWCONTROL_NONE;
	l_stFlags.m_ucIRDA = HAL_UART_IRDA_DISABLED;
	l_stFlags.m_ucParity = HAL_UART_PARITY_NONE;
	l_stFlags.m_ucStopBits = HAL_UART_STOPBITS_1;
	l_stFlags.m_ucWordLength = HAL_UART_WORDLENGTH_8;
	
	HAL_UART_Config(UART_LOG, (uint32_t) 921600, l_stFlags);
	HAL_UART_SetState(UART_LOG, HAL_UART_ENABLE);
}

void LogArray(uint8_t *p_ucData, uint8_t ucSize, uint8_t ucType)
{
  uint8_t l_ucIndex;
  
  if (ucType == 0)
  {
    Log("<- | ");
  }
  else
  {
    if (ucType == 1)
    {
      Log("-> | ");
    }
    else
    {
      //INFO: 
    }
  }
  
  for (l_ucIndex = 0; l_ucIndex < ucSize; l_ucIndex++)
  {
    Log("%x ", p_ucData[l_ucIndex]);
  }
  
  Log("\r\n");
}