/***************************************************************************
* I2C SHT21 Sensor
****************************************************************************/
#include "SHT21.h"
#include "hal_i2c.h"
#include "hal_clock.h"

uint16_t g_ucSHT21Address = 0x80;
int16_t g_SHT21Temperature;
uint16_t g_unSHT21Humidity;

void SHT21_Init(void)
{
	HAL_I2C_Flags l_stFlags = {0};
    
    l_stFlags.m_ucAddrMode = HAL_I2C_Addr7Bit;
    l_stFlags.m_ucGeneralCall = HAL_I2C_GeneralCallDisabled;
    l_stFlags.m_ucSpeed = HAL_I2C_Speed100kHz;
    l_stFlags.m_unOwnAddr = 0x75;
    
    HAL_I2C_Config(SHT21_I2C, l_stFlags);   
}

uint8_t SHT21_ReadUserRegister(void)
{
	//INFO: Use the HAL I2C functions to read the user register.
}

void SHT21_WriteUserRegister(uint8_t ucValue)
{
	//INFO: Use the HAL I2C functions to read the user register.
}

fp32_t SHT21_ReadData(uint8_t ucDataType)
{
	//INFO: Use the HAL I2C functions to read the data from the sensor and compute the temperature and humidity.
	//INFO: Formulas cand be found in the SHT21 datasheet.
}
