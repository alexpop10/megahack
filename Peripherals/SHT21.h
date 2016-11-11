#include "stdint.h"
#include "typedefs.h"

#define SHT21_I2C HAL_I2C_0

#define SHT21_POWERUP 15 //INFO: SHT21 power-up time in milliseconds, page 7
#define SHT21_WAIT    20 //INFO: SHT21 wait before stop in microseconds, page 8

#define SHT21_ADDR       0x40
#define SHT21_T_HOLD     0xE3
#define SHT21_RH_HOLD    0xE5
#define SHT21_T_NO_HOLD  0xF3
#define SHT21_RH_NO_HOLD 0xF5
#define SHT21_WRITE_REG  0xE6
#define SHT21_READ_REG   0xE7
#define SHT21_SOFT_RESET 0xFE

enum SHT21_DATA_TYPE
{
    SHT21_DATA_TYPE__HUMIDITY = ((uint8_t) 0x00),
    SHT21_DATA_TYPE__TEMPERATURE
};

void SHT21_Init(void);
fp32_t SHT21_ReadData(uint8_t ucDataType);
uint8_t SHT21_ReadUserRegister(void);
void SHT21_WriteUserRegister(uint8_t ucValue);