/**************************************************************************************************
 * @file    platform.c
 * @brief   Platform related
 * @author  Control Data Systems, Andrei Rusu
 * @date    November 2015
 * @changes Created
**************************************************************************************************/
#include "platform.h"

void PLATFORM_Init(void)
{
  /* Set the priority grouping. */
  NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);
}
