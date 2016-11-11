/** 
  ******************************************************************************
  * @file    GPIO/GPIO_IOToggle/Src/stm32l4xx_it.c
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    26-June-2015
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and
  *          peripherals interrupt service routine.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2015 STMicroelectronics</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32l4xx_it.h"
#include "hal_clock.h"
#include "hal_gpio.h"
#include "hal_timer.h"
#include "hal_uart.h"
#include "hal_spi.h"

/** @addtogroup STM32L4xx_HAL_Examples
  * @{
  */

/** @addtogroup GPIO_IOToggle
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M4 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief  This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval None
  */
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval None
  */
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval None
  */
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
void SVC_Handler(void)
{
}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval None
  */
void DebugMon_Handler(void)
{
}

/**
  * @brief  This function handles PendSVC exception.
  * @param  None
  * @retval None
  */
void PendSV_Handler(void)
{
}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{
  HAL_CLOCK_SysTick_Interrupt();
}

/******************************************************************************/
/*                 STM32L4xx Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32l4xx.s).                                               */
/******************************************************************************/

/**
  * @brief  This function handles PPP interrupt request.
  * @param  None
  * @retval None
  */
/*void PPP_IRQHandler(void)
{
}*/

/**
  * @brief  This function handles EXTI0 Handler.
  * @param  None
  * @retval None
  */
void EXTI0_IRQHandler(void)
{
  HAL_EXTI_0_Interrupt();
}

/**
  * @brief  This function handles EXTI1 Handler.
  * @param  None
  * @retval None
  */
void EXTI1_IRQHandler(void)
{
  HAL_EXTI_1_Interrupt();
}

/**
  * @brief  This function handles EXTI2 Handler.
  * @param  None
  * @retval None
  */
void EXTI2_IRQHandler(void)
{
  HAL_EXTI_2_Interrupt();
}

/**
  * @brief  This function handles EXTI9_5 Handler.
  * @param  None
  * @retval None
  */
void EXTI3_IRQHandler(void)
{
  HAL_EXTI_3_Interrupt();
}

/**
  * @brief  This function handles EXTI4 Handler.
  * @param  None
  * @retval None
  */
void EXTI4_IRQHandler(void)
{
  HAL_EXTI_4_Interrupt();
}

/**
  * @brief  This function handles EXTI9_5 Handler.
  * @param  None
  * @retval None
  */
void EXTI9_5_IRQHandler(void)
{
  HAL_EXTI_9_5_Interrupt();
}

/**
  * @brief  This function handles EXTI15_10 Handler.
  * @param  None
  * @retval None
  */
void EXTI15_10_IRQHandler(void)
{
  HAL_EXTI_15_10_Interrupt();
}

/**
  * @brief  This function handles TIM1_UP_TIM16 Handler.
  * @param  None
  * @retval None
  */
void TIM1_UP_TIM16_IRQHandler(void)
{
  HAL_TIMER_0_9_Interrupt();
}

/**
  * @brief  This function handles TIM1_CC Handler.
  * @param  None
  * @retval None
  */
void TIM1_CC_IRQHandler(void)
{
  HAL_TIMER_0_1_Interrupt();
}

/**
  * @brief  This function handles TIM2 Handler.
  * @param  None
  * @retval None
  */
void TIM2_IRQHandler(void)
{
  HAL_TIMER_1_Interrupt();
}

/**
  * @brief  This function handles TIM3 Handler.
  * @param  None
  * @retval None
  */
void TIM3_IRQHandler(void)
{
  HAL_TIMER_2_Interrupt();
}

/**
  * @brief  This function handles TIM4 Handler.
  * @param  None
  * @retval None
  */
void TIM4_IRQHandler(void)
{
  HAL_TIMER_3_Interrupt();
}

/**
  * @brief  This function handles TIM5 Handler.
  * @param  None
  * @retval None
  */
void TIM5_IRQHandler(void)
{
  HAL_TIMER_4_Interrupt();
}

/**
  * @brief  This function handles TIM6_DAC Handler.
  * @param  None
  * @retval None
  */
void TIM6_DAC_IRQHandler(void)
{
  HAL_TIMER_5_Interrupt();
}

/**
  * @brief  This function handles TIM7 Handler.
  * @param  None
  * @retval None
  */
void TIM7_IRQHandler(void)
{
  HAL_TIMER_6_Interrupt();
}

/**
  * @brief  This function handles TIM8_UP Handler.
  * @param  None
  * @retval None
  */
void TIM8_UP_IRQHandler(void)
{
  HAL_TIMER_7_0_Interrupt();
}

/**
  * @brief  This function handles TIM8_CC Handler.
  * @param  None
  * @retval None
  */
void TIM8_CC_IRQHandler(void)
{
  HAL_TIMER_7_1_Interrupt();
}

/**
  * @brief  This function handles TIM1_BRK_TIM15 Handler.
  * @param  None
  * @retval None
  */
void TIM1_BRK_TIM15_IRQHandler(void)
{
  HAL_TIMER_8_Interrupt();
}

/**
  * @brief  This function handles TIM1_TRG_COM_TIM17 Handler.
  * @param  None
  * @retval None
  */
void TIM1_TRG_COM_TIM17_IRQHandler(void)
{
  HAL_TIMER_9_Interrupt();
}

/**
  * @brief  This function handles USART1 Handler.
  * @param  None
  * @retval None
  */
void USART1_IRQHandler(void)
{
  HAL_UART_0_Interrupt();
}

/**
  * @brief  This function handles USART2 Handler.
  * @param  None
  * @retval None
  */
void USART2_IRQHandler(void)
{
  HAL_UART_1_Interrupt();
}

/**
  * @brief  This function handles USART3 Handler.
  * @param  None
  * @retval None
  */
void USART3_IRQHandler(void)
{
  HAL_UART_2_Interrupt();
}

/**
  * @brief  This function handles UART4 Handler.
  * @param  None
  * @retval None
  */
void UART4_IRQHandler(void)
{
  HAL_UART_3_Interrupt();
}

/**
  * @brief  This function handles UART5 Handler.
  * @param  None
  * @retval None
  */
void UART5_IRQHandler(void)
{
  HAL_UART_4_Interrupt();
}

/**
  * @brief  This function handles SPI1 Handler.
  * @param  None
  * @retval None
  */
void SPI1_IRQHandler(void)
{
  HAL_SPI_0_Interrupt();
}

/**
  * @brief  This function handles SPI2 Handler.
  * @param  None
  * @retval None
  */
void SPI2_IRQHandler(void)
{
  HAL_SPI_1_Interrupt();
}

/**
  * @brief  This function handles SPI3 Handler.
  * @param  None
  * @retval None
  */
void SPI3_IRQHandler(void)
{
  HAL_SPI_2_Interrupt();
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
