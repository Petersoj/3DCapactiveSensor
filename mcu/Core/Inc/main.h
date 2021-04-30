/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.h
 * @brief          : Header for main.c file.
 *                   This file contains the common defines of the application.
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/**
 * @brief  Sets 'number' inside 'to_set' at the bits defined by MSB and LSB
 * @param  to_set: a pointer to the bits to set
 * @param  number: the number to set inside 'to_set'
 * @param  msb: the MSB (0 - 31) (inclusive)
 * @param  lsb: the LSB (0 - 31) (inclusive)
 * @retval None
 * @author Jacob Peterson
 */
static inline void set_bits(volatile uint32_t *to_set, uint32_t number, uint8_t msb, uint8_t lsb);

/**
 * @brief  Sets 'bit' inside 'to_set' at index
 * @param  to_set: a pointer to the bits to set
 * @param  bit: the bit to set inside 'to_set'
 * @param  index: the index (0 - 31) (inclusive)
 * @retval None
 * @author Jacob Peterson
 */
static inline void set_bit(volatile uint32_t *to_set, uint32_t bit, uint8_t index);

/**
 * @brief  Gets the bits inside 'to_get' at the bits defined by MSB and LSB
 * @param  to_get: a pointer to the bits to get
 * @param  msb: the MSB (0 - 31) (inclusive)
 * @param  lsb: the LSB (0 - 31) (inclusive)
 * @retval None
 * @author Jacob Peterson
 */
static inline uint32_t get_bits(volatile uint32_t *to_get, uint8_t msb, uint8_t lsb);

/**
 * @brief  Gets the bit inside 'to_get' at the bits at the index
 * @param  to_get: a pointer to the bits to get
 * @param  index: the MSB (0 - 31)
 * @retval None
 * @author Jacob Peterson
 */
static inline uint32_t get_bit(volatile uint32_t *to_get, uint8_t index);

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
