/**************************************************************************************************
 * @file    hal_aes.h
 * @brief   Microprocessor encryption module
 * @author  Control Data Systems, Andrei Rusu
 * @date    September 2015
 * @changes Created
**************************************************************************************************/
#ifndef _HAL_AES_H_
#define _HAL_AES_H_

#include "typedefs.h"

enum HAL_AES_Chain_Modes
{
  HAL_AES_CHAIN__ECB  = ((uint8_t) 0x00),
  HAL_AES_CHAIN__CBC,
  HAL_AES_CHAIN__CTR,
  HAL_AES_CHAIN__GCM,
  HAL_AES_CHAIN__CMAC,
};

/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   AES initialization
 * @remarks
**************************************************************************************************/
void HAL_AES_Init(void);
/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   AES set key
 * @remarks
**************************************************************************************************/
void HAL_AES_SetKey(uint8_t *pucKey);
/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   AES set mode
 * @remarks
**************************************************************************************************/
void HAL_AES_SetMode(uint8_t ucMode);
/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   AES encrypt
 * @remarks
**************************************************************************************************/
void HAL_AES_Encrypt(uint8_t *pucData, uint8_t *pucResult);
/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   AES rotate bytes
 * @remarks
**************************************************************************************************/
void HAL_AES_RotateToUint32(uint8_t *pucData, uint32_t *pucResult);
   /**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   AES rotate bytes
 * @remarks
**************************************************************************************************/
void HAL_AES_RotateToUint8(uint32_t *pucData, uint8_t *pucResult);
/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   AES clear initialization vector
 * @remarks
**************************************************************************************************/
void HAL_AES_ClearVector(void);
/**************************************************************************************************
 * @author  Control Data Systems, Andrei Rusu
 * @brief   AES XOR
 * @remarks
**************************************************************************************************/
void HAL_AES_Xor(uint8_t * p_ucCrypted, uint8_t * p_ucPlain, uint8_t * p_ucResult);

#endif /* _HAL_AES_H_ */