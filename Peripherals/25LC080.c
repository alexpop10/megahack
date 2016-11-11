/**************************************************************************************************
* @file    25LC080.c
* @brief   Driver for the Microchip 25LC080 EEPROM
* @author  Control Data Systems, Andrei Rusu
* @date    September 2016
* @changes Created
**************************************************************************************************/
#include "25LC080.h"
#include "hal_gpio.h"
#include "hal_spi.h"

void EEPROM_Init(void)
{
	HAL_SPI_Flags l_stSPIFlags = {0};
	HAL_GPIO_Flags l_stGPIOFlags = {0};
	
	l_stSPIFlags.m_ucCLKPhase = HAL_SPI_1Edge;
	l_stSPIFlags.m_ucCLKPolarity = HAL_SPI_Low;
	l_stSPIFlags.m_ucFirstBit = HAL_SPI_MSB;
	l_stSPIFlags.m_ucMode = HAL_SPI_Master;
	
	HAL_SPI_Config(EEPROM_SPI, HAL_SPI_2_MHZ, l_stSPIFlags);
	HAL_SPI_SetState(EEPROM_SPI, HAL_SPI_ENABLE);
	
	l_stGPIOFlags.m_ucMode = HAL_GPIO_MODE__OUTPUT;
	l_stGPIOFlags.m_ucType = HAL_GPIO_TYPE__PP;
	l_stGPIOFlags.m_ucPull = HAL_GPIO_PULL__NO_PULL;
	l_stGPIOFlags.m_ucSpeed = HAL_GPIO_SPEED__HIGH;
	
	HAL_GPIO_Config(EEPROM_CS_PORT, EEPROM_CS_PIN, l_stGPIOFlags);
	HAL_GPIO_Write(EEPROM_CS_PORT, EEPROM_CS_PIN, HAL_GPIO_HIGH);
}

uint8_t EEPROM_ReadStatusRegister(void)
{
	uint8_t l_ucReturn;
	
	HAL_GPIO_Write(EEPROM_CS_PORT, EEPROM_CS_PIN, HAL_GPIO_LOW);
	
	(void)HAL_SPI_SendChar(EEPROM_SPI, RDSR);
	l_ucReturn = HAL_SPI_SendChar(EEPROM_SPI, 0x00);
	
	HAL_GPIO_Write(EEPROM_CS_PORT, EEPROM_CS_PIN, HAL_GPIO_HIGH);
	
	return l_ucReturn;
}

void EEPROM_WriteStatusRegister(uint8_t ucValue)
{
	HAL_GPIO_Write(EEPROM_CS_PORT, EEPROM_CS_PIN, HAL_GPIO_LOW);
	
	(void)HAL_SPI_SendChar(EEPROM_SPI, WRSR);
	(void)HAL_SPI_SendChar(EEPROM_SPI, ucValue);
	
	HAL_GPIO_Write(EEPROM_CS_PORT, EEPROM_CS_PIN, HAL_GPIO_HIGH);
}

void EEPROM_Read(uint16_t unAddress, uint8_t *pucBuff, uint16_t unSize)
{
	uint16_t l_unIndex;
	
	HAL_GPIO_Write(EEPROM_CS_PORT, EEPROM_CS_PIN, HAL_GPIO_LOW);
	
	(void)HAL_SPI_SendChar(EEPROM_SPI, READ);
	(void)HAL_SPI_SendChar(EEPROM_SPI, (uint8_t) ((unAddress >> 8) & 0x03));
	(void)HAL_SPI_SendChar(EEPROM_SPI, (uint8_t) (unAddress & 0xFF));
	
	for (l_unIndex = 0; l_unIndex < unSize; l_unIndex++)
	{
		pucBuff[l_unIndex] = HAL_SPI_SendChar(EEPROM_SPI, 0x00);
	}
	
	HAL_GPIO_Write(EEPROM_CS_PORT, EEPROM_CS_PIN, HAL_GPIO_HIGH);
}

void EEPROM_WriteEnable(void)
{
	HAL_GPIO_Write(EEPROM_CS_PORT, EEPROM_CS_PIN, HAL_GPIO_LOW);
	
	(void)HAL_SPI_SendChar(EEPROM_SPI, WREN);
	
	HAL_GPIO_Write(EEPROM_CS_PORT, EEPROM_CS_PIN, HAL_GPIO_HIGH);
}

void EEPROM_WriteDisable(void)
{
	HAL_GPIO_Write(EEPROM_CS_PORT, EEPROM_CS_PIN, HAL_GPIO_LOW);
	
	(void)HAL_SPI_SendChar(EEPROM_SPI, WRDI);
	
	HAL_GPIO_Write(EEPROM_CS_PORT, EEPROM_CS_PIN, HAL_GPIO_HIGH);
}

void EEPROM_WriteByte(uint16_t unAddress, uint8_t ucByte)
{
	EEPROM_WriteEnable();
	
	HAL_GPIO_Write(EEPROM_CS_PORT, EEPROM_CS_PIN, HAL_GPIO_LOW);
	
	(void)HAL_SPI_SendChar(EEPROM_SPI, WRITE);
	
	(void)HAL_SPI_SendChar(EEPROM_SPI, (uint8_t) ((unAddress >> 8) & 0x03));
	(void)HAL_SPI_SendChar(EEPROM_SPI, (uint8_t) (unAddress & 0xFF));
	
	(void)HAL_SPI_SendChar(EEPROM_SPI, ucByte);
	
	HAL_GPIO_Write(EEPROM_CS_PORT, EEPROM_CS_PIN, HAL_GPIO_HIGH);
	
	EEPROM_WriteDisable();
}

void EEPROM_WritePage(uint16_t unAddress, uint8_t *pucBuff, uint8_t ucSize)
{
	uint8_t l_ucIndex;
	
	if (ucSize > 16)
	{
		ucSize = 16;
	}
	
	EEPROM_WriteEnable();
	
	HAL_GPIO_Write(EEPROM_CS_PORT, EEPROM_CS_PIN, HAL_GPIO_LOW);
	
	(void)HAL_SPI_SendChar(EEPROM_SPI, WRITE);
	(void)HAL_SPI_SendChar(EEPROM_SPI, (uint8_t) ((unAddress >> 8) & 0x03));
	(void)HAL_SPI_SendChar(EEPROM_SPI, (uint8_t) (unAddress & 0xFF));
	
	for (l_ucIndex = 0; l_ucIndex < ucSize; l_ucIndex++)
	{
		(void)HAL_SPI_SendChar(EEPROM_SPI, pucBuff[l_ucIndex]);
	}
	
	HAL_GPIO_Write(EEPROM_CS_PORT, EEPROM_CS_PIN, HAL_GPIO_HIGH);
	
	EEPROM_WriteDisable();
}
