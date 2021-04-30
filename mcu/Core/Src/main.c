/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

void usart3_transmit_char(char character) {
    // Busy wait while TX register is not empty
    while (((USART3->ISR >> 7u) & 0x1u) == 0) {
    }
    // Write 'character' to Transmit Data Register
    USART3->TDR = character;
}

void usart3_transmit_string(char string[]) {
    uint32_t index = 0;
    char character;
    // Transmit char until 0 is reached
    while ((character = string[index++]) != 0x0u) {
        usart3_transmit_char(character);
    }
}

void usart3_transmit_newline() {
    usart3_transmit_char('\n'); // Line Feed/New Line
    usart3_transmit_char('\r'); // Carrage return
}

/* USER CODE END 0 */

/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void) {
    /* USER CODE BEGIN 1 */

    /* USER CODE END 1 */

    /* MCU Configuration--------------------------------------------------------*/

    /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
    HAL_Init();

    /* USER CODE BEGIN Init */

    /* USER CODE END Init */

    /* Configure the system clock */
    SystemClock_Config();

    /* USER CODE BEGIN SysInit */

    /* USER CODE END SysInit */

    /* Initialize all configured peripherals */
    /* USER CODE BEGIN 2 */

    // STM32 TX/USB-UART RX is on PC4
    // STM32 RX/USB-UART TX is on PC5

    // Enable GPIOC clock
    RCC->AHBENR |= (1 << 19u);
    // Enable the USART clock
    RCC->APB1ENR |= (1 << 18u);

    // Configure PC4 for USART3 Alternate Function
    GPIOC->MODER |= (1 << 9u);
    GPIOC->MODER &= ~(1 << 8u);
    // Configure PC5 for USART3 Alternate Function
    GPIOC->MODER |= (1 << 11u);
    GPIOC->MODER &= ~(1 << 10u);
    // Configure PC4 Alternate Function (AF) Low Register for AF1
    GPIOC->AFR[0] |= (1 << 16u);
    // Configure PC5 Alternate Function (AF) Low Register for AF1
    GPIOC->AFR[0] |= (1 << 20u);

    // Set the baud rate of USART3
    USART3->BRR = HAL_RCC_GetHCLKFreq() / 115200;
    // Enable USART3 TX
    USART3->CR1 |= (1 << 3u);
    // Enable USART3 RX
    USART3->CR1 |= (1 << 2u);
    // Enable USART3 Receive Register Not Empty Interrupt
    USART3->CR1 |= (1 << 5u);
    // Enable USART3
    USART3->CR1 |= (1 << 0u);

    usart3_transmit_string("Testing...");

    /* USER CODE END 2 */

    /* Infinite loop */
    /* USER CODE BEGIN WHILE */
    while (1) {
        /* USER CODE END WHILE */

        /* USER CODE BEGIN 3 */
    }
    /* USER CODE END 3 */
}

/**
 * @brief System Clock Configuration
 * @retval None
 */
void SystemClock_Config(void) {
    RCC_OscInitTypeDef RCC_OscInitStruct = {0};
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

    /** Initializes the RCC Oscillators according to the specified parameters
     * in the RCC_OscInitTypeDef structure.
     */
    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
    RCC_OscInitStruct.HSIState = RCC_HSI_ON;
    RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
        Error_Handler();
    }
    /** Initializes the CPU, AHB and APB buses clocks
     */
    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK) {
        Error_Handler();
    }
}

/* USER CODE BEGIN 4 */

static inline void set_bits(volatile uint32_t *to_set, uint32_t number, uint8_t msb, uint8_t lsb) {
    uint32_t temp = *to_set;
    uint32_t mask = (~0u << (msb + 1)) | ~(~0u << lsb);
    temp |= ~mask & (number << lsb);
    temp &= mask | (number << lsb);
    *to_set = temp;
}

static inline void set_bit(volatile uint32_t *to_set, uint32_t bit, uint8_t index) {
    set_bits(to_set, bit, index, index);
}

static inline uint32_t get_bits(volatile uint32_t *to_get, uint8_t msb, uint8_t lsb) {
    uint32_t mask = ~((~0u << (msb + 1)) | ~(~0u << lsb));
    return (*to_get & mask) >> lsb;
}

static inline uint32_t get_bit(volatile uint32_t *to_get, uint8_t index) {
    return get_bits(to_get, index, index);
}

/* USER CODE END 4 */

/**
 * @brief  This function is executed in case of error occurrence.
 * @retval None
 */
void Error_Handler(void) {
    /* USER CODE BEGIN Error_Handler_Debug */
    /* User can add his own implementation to report the HAL error return state */
    __disable_irq();
    while (1) {
    }
    /* USER CODE END Error_Handler_Debug */
}

#ifdef USE_FULL_ASSERT
/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 * @param  file: pointer to the source file name
 * @param  line: assert_param error line source number
 * @retval None
 */
void assert_failed(uint8_t *file, uint32_t line) {
    /* USER CODE BEGIN 6 */
    /* User can add his own implementation to report the file name and line number,
       ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
    /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
