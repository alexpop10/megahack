/**************************************************************************************************
* @file    25LC080.h
* @brief   Driver for the Microchip 25LC080 EEPROM
* @author  Control Data Systems, Andrei Rusu
* @date    September 2016
* @changes Created
**************************************************************************************************/
#ifndef _25LC0808_H_
#define _25LC0808_H_

#include "typedefs.h"

#define EEPROM_SPI HAL_SPI_0
#define EEPROM_CS_PORT HAL_GPIO_0
#define EEPROM_CS_PIN HAL_GPIO_PIN_4

enum EEPROM_Instructions
{
	WRSR = ((uint8_t) 0x01), // Write status register
	WRITE,                   // Write data to memory array beginning at selected address
	READ,                    // Read data from memory aray beginning at selected address
	WRDI,                    // Reset the write enable latch (disable write operations)
	RDSR,                    // Read status register
	WREN                     // Set the write enable latch (enable write operations)
};

void EEPROM_Init(void);

uint8_t EEPROM_ReadStatusRegister(void);

void EEPROM_WriteStatusRegister(uint8_t ucValue);

void EEPROM_Read(uint16_t unAddress, uint8_t *pucBuff, uint16_t unSize);

void EEPROM_WriteEnable(void);

void EEPROM_WriteDisable(void);

void EEPROM_WriteByte(uint16_t unAddress, uint8_t ucByte);

void EEPROM_WritePage(uint16_t unAddress, uint8_t *pucBuff, uint8_t ucSize);


#endif /* _25LC0808_H_ */
