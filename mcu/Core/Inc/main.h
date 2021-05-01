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

/**
 * @brief Represents a type of line ending.
 */
enum LineEnding {
    /** @brief '\r' */
    CR,

    /** @brief '\n' */
    LF,

    /** @brief '\r\n' */
    CRLF
};

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/**
 * @brief Configures the RCC.
 */
void configure_rcc(void);

/**
 * @brief Configures and sets up the ADC.
 * @param channel_select_positions: array of bytes specifying enabled ADC channels
 * @param channel_select_positions_length: length of channel_select_positions array
 */
void configure_and_setup_adc(uint8_t *channel_select_positions,
                             uint8_t channel_select_positions_length);

/**
 * @brief Configures the USART3 peripheral for transmission.
 */
void configure_usart3_tx(void);

/**
 * @brief Pulls a GPIO pin low.
 * @param gpio_pointer: a pointer to the GPIO_TypeDef struct base
 * @param gpio_number: the GPIO port number
 */
void gpio_pull_low(GPIO_TypeDef *gpio_pointer, uint8_t gpio_number);

/**
 * @brief Configures a GPIO pin to interally connect to its ADC channel.
 * @param gpio_pointer: a pointer to the GPIO_TypeDef struct base
 * @param gpio_number: the GPIO port number
 */
void gpio_configure_adc_function(GPIO_TypeDef *gpio_pointer, uint8_t gpio_number);

/**
 * @brief Starts an ADC conversion/sample sequence.
 * @param channel_select_data: an array to be filled by select channel data
 * @param channel_select_data_length: length of channel_select_data
 */
void gpio_start_adc_sample_sequence(uint8_t *channel_select_data,
                                    uint8_t channel_select_data_length);

/**
 * @brief Transmits a character on the USART3 peripheral. This is a blocking call.
 * @param character: the character
 */
void usart3_transmit_char(char character);

/**
 * @brief Transmits a string on the USART3 peripheral. This is a blocking call.
 * @param string: the string
 */
void usart3_transmit_string(char string[]);

/**
 * @brief Transmits a new line on the USART3 peripheral.
 * @param lineEnding: the type of line ending
 */
void usart3_transmit_newline(enum LineEnding lineEnding);

/**
 * @brief C++ version 0.4 char* style "itoa":
 * Written by Lukas Chmela (https://stackoverflow.com/a/23840699)
 * Released under GPLv3.
 * @retval the converted ASCII character
 */
char *to_string(int value, char *result, int base);

/**
 * @brief  Sets 'number' inside 'to_set' at the bits defined by MSB and LSB.
 * @param  to_set: a pointer to the bits to set
 * @param  number: the number to set inside 'to_set'
 * @param  msb: the MSB (0 - 31) (inclusive)
 * @param  lsb: the LSB (0 - 31) (inclusive)
 * @author Jacob Peterson
 */
static inline void set_bits(volatile uint32_t *to_set, uint32_t number, uint8_t msb, uint8_t lsb);

/**
 * @brief  Sets 'bit' inside 'to_set' at index.
 * @param  to_set: a pointer to the bits to set
 * @param  bit: the bit to set inside 'to_set'
 * @param  index: the index (0 - 31) (inclusive)
 * @author Jacob Peterson
 */
static inline void set_bit(volatile uint32_t *to_set, uint32_t bit, uint8_t index);

/**
 * @brief  Gets the bits inside 'to_get' at the bits defined by MSB and LSB.
 * @param  to_get: a pointer to the bits to get
 * @param  msb: the MSB (0 - 31) (inclusive)
 * @param  lsb: the LSB (0 - 31) (inclusive)
 * @retval the bits
 * @author Jacob Peterson
 */
static inline uint32_t get_bits(volatile uint32_t *to_get, uint8_t msb, uint8_t lsb);

/**
 * @brief  Gets the bit inside 'to_get' at the bits at the index.
 * @param  to_get: a pointer to the bits to get
 * @param  index: the MSB (0 - 31)
 * @retval the bit
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
