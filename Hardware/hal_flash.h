/**************************************************************************************************
 * @file    hal_flash.h
 * @brief   Microprocessor flash module
 * @author  Control Data Systems, Andrei Rusu
 * @date    September 2015
 * @changes Created
**************************************************************************************************/
#ifndef _HAL_FLASH_H_
#define _HAL_FLASH_H_

#include "typedefs.h"

#define HAL_FLASH_KEY1 ((uint32_t) 0x45670123)
#define HAL_FLASH_KEY2 ((uint32_t) 0xCDEF89AB)

#define HAL_FLASH_OPTKEY1 ((uint32_t) 0x08192A3B)
#define HAL_FLASH_OPTKEY2 ((uint32_t) 0x4C5D6E7F)
#define HAL_FLASH_WORDLEN ((uint8_t) 8)

typedef union
{
uint8_t m_aucArray[8];
uint64_t m_llData;
}FLASH_BYTE;

enum HAL_FLASH_Banks
{
  HAL_FLASH_BANK_1 = ((uint8_t) 0x00),
  HAL_FLASH_BANK_2,
  HAL_FLASH_MASS
};

 enum BOR_LEVEL
{
	HAL_FLASH_BOR_1v7 = 0,
	HAL_FLASH_BOR_2v0,
	HAL_FLASH_BOR_2v2,
	HAL_FLASH_BOR_2v5,
	HAL_FLASH_BOR_2v8
};
/**************************************************************************************************
 * @author  Control Data Systems, Stefan Vos
 * @brief   Flash lock
 * @remarks
**************************************************************************************************/
void HAL_FLASH_Lock(void);
/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   Flash unlock
 * @remarks
**************************************************************************************************/
void HAL_FLASH_Unlock(void);
/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   Flash page erase
 * @remarks
**************************************************************************************************/
uint8_t HAL_FLASH_ErasePage(uint8_t ucBank, uint8_t ucPage);
/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   Flash bank erase
 * @remarks
**************************************************************************************************/
uint8_t HAL_FLASH_EraseBank(uint8_t ucBank);
/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   Flash double word program
 * @remarks
**************************************************************************************************/
uint8_t HAL_FLASH_Program(uint32_t ulAddress, uint64_t llData);
/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   Flash row fast program
 * @remarks
**************************************************************************************************/
void HAL_FLASH_FastProgram(uint32_t ulAddress, uint64_t *pulData);
/**************************************************************************************************
 * @author  Control Data Systems, Stefan Vos
 * @brief   Flash read function
 * @remarks
**************************************************************************************************/
void HAL_FLASH_Read(uint8_t *p_pucBuffer, uint32_t ulAddress, uint16_t p_unSize);
/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   Write BOR level
 * @remarks
**************************************************************************************************/
void HAL_FLASH_WriteBOR(uint8_t p_ucLevel);

#endif /* _HAL_FLASH_H_ */