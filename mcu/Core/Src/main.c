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

#define USART3_BAUD_RATE 115200

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

    // PINOUT:
    // PC0 = X Plate
    // PC2 = Y Plate
    // PA0 = Z Plate
    //
    // PC4 = STM32 TX / USB-UART RX
    // PC5 = STM32 RX / USB-UART TX

    configure_rcc();
    configure_usart3_tx();
    configure_gpio(GPIOC, 0);
    configure_gpio(GPIOC, 2);
    configure_gpio(GPIOA, 0);

    GPIOC->MODER |= (1 << 12);
    GPIOC->MODER &= ~(1 << 13);
    GPIOC->OTYPER &= ~(1 << 6);
    GPIOC->OSPEEDR &= ~(1 << 12);
    GPIOC->PUPDR &= ~((1 << 12) | (1 << 13));
    GPIOC->BSRR = (1 << 6);

    // General purpose output mode
    set_bits(&GPIOC->MODER, 0x1, 1, 0);
    // Push-pull output type
    set_bit(&GPIOC->MODER, 0x0, 0);
    // No pull-up, no pull-down resistors
    set_bits(&GPIOC->PUPDR, 0x0, 1, 0);
    // Output LOW
    GPIOC->BSRR = (1 << 0);

    configure_gpio(GPIOC, 6);

    /* USER CODE END 2 */

    /* Infinite loop */
    /* USER CODE BEGIN WHILE */
    while (1) {
        /* USER CODE END WHILE */

        int total = 0;
        int count = 0;
        while (total < 100) {
            gpio_pull_low(GPIOC, 6);
            gpio_configure_input(GPIOC, 6);
            while (gpio_get_input(GPIOC, 6) == 0) {
                count++;
            }
            total++;
        }

        char count_str[20];
        to_string((count << 7) / total, count_str, 10);
        usart3_transmit_string(count_str);
        usart3_transmit_newline(CRLF);

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

void configure_rcc(void) {
    // Enable GPIOA clock
    set_bit(&RCC->AHBENR, 1, RCC_AHBENR_GPIOAEN_Pos);
    // Enable GPIOC clock
    set_bit(&RCC->AHBENR, 1, RCC_AHBENR_GPIOCEN_Pos);
    // Enable the USART3 clock
    set_bit(&RCC->APB1ENR, 1, RCC_APB1ENR_USART3EN_Pos);
}

void configure_usart3_tx(void) {
    // Configure PC4 for USART3 Alternate Function
    set_bits(&GPIOC->MODER, 0x2, GPIO_MODER_MODER4_Pos + 1, GPIO_MODER_MODER4_Pos);
    // Configure PC5 for USART3 Alternate Function
    set_bits(&GPIOC->MODER, 0x2, GPIO_MODER_MODER5_Pos + 1, GPIO_MODER_MODER5_Pos);

    // Configure PC4 Alternate Function (AF) Low Register for AF1
    set_bits(&GPIOC->AFR[0], 0x1, GPIO_AFRL_AFSEL4_Pos + 3, GPIO_AFRL_AFSEL4_Pos);
    // Configure PC5 Alternate Function (AF) Low Register for AF1
    set_bits(&GPIOC->AFR[0], 0x1, GPIO_AFRL_AFSEL5_Pos + 3, GPIO_AFRL_AFSEL5_Pos);

    // Set the baud rate of USART3
    set_bits(&USART3->BRR, HAL_RCC_GetHCLKFreq() / USART3_BAUD_RATE, 15, 0);
    // Enable USART3 TX
    set_bit(&USART3->CR1, 1, USART_CR1_TE_Pos);
    // Enable USART3
    set_bit(&USART3->CR1, 1, USART_CR1_UE_Pos);
}

void configure_gpio(GPIO_TypeDef *gpio_pointer, uint8_t gpio_number) {
    // High output speed
    set_bits(&gpio_pointer->OSPEEDR, 0x3, gpio_number * 2 + 1, gpio_number * 2); // 0x3 = 0b11
}

void gpio_pull_low(GPIO_TypeDef *gpio_pointer, uint8_t gpio_number) {
    // General purpose output mode
    set_bits(&gpio_pointer->MODER, 0x1, gpio_number * 2 + 1, gpio_number * 2);
    // Push-pull output type
    set_bit(&gpio_pointer->MODER, 0x0, gpio_number);
    // No pull-up, no pull-down resistors
    set_bits(&gpio_pointer->PUPDR, 0x0, gpio_number * 2 + 1, gpio_number * 2);
    // Output LOW
    set_bit(&gpio_pointer->BSRR, 0x1, gpio_number + 16);
}

void gpio_configure_input(GPIO_TypeDef *gpio_pointer, uint8_t gpio_number) {
    // Input mode
    set_bits(&gpio_pointer->MODER, 0x0, gpio_number * 2 + 1, gpio_number * 2);
    // No pull-up, no pull-down resistors
    set_bits(&gpio_pointer->PUPDR, 0x0, gpio_number * 2 + 1, gpio_number * 2);
}

uint8_t gpio_get_input(GPIO_TypeDef *gpio_pointer, uint8_t gpio_number) {
    // Get value from input data register
    return get_bit(&gpio_pointer->IDR, gpio_number);
}

void usart3_transmit_char(char character) {
    // Busy wait while TX register is not empty
    while (get_bit(&USART3->ISR, USART_ISR_TXE_Pos) == 0) {
    }
    // Write 'character' to Transmit Data Register
    USART3->TDR = character;
}

void usart3_transmit_string(char string[]) {
    uint32_t index = 0;
    char character;
    // Transmit char until 0 is reached
    while ((character = string[index++]) != 0x0) {
        usart3_transmit_char(character);
    }
}

void usart3_transmit_newline(enum LineEnding lineEnding) {
    switch (lineEnding) {
        case CR:
            usart3_transmit_char('\r');
            break;
        case LF:
            usart3_transmit_char('\n');
            break;
        case CRLF:
            usart3_transmit_char('\r');
            usart3_transmit_char('\n');
            break;
    }
}

// (https://stackoverflow.com/a/23840699)
// Used instead of sprintf for performance.
char *to_string(int value, char *result, int base) {
    // Check that the base if valid
    if (base < 2 || base > 36) {
        *result = '\0';
        return result;
    }

    char *ptr = result, *ptr1 = result, tmp_char;
    int tmp_value;

    do {
        tmp_value = value;
        value /= base;
        *ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz"
            [35 + (tmp_value - value * base)];
    } while (value);

    // Apply negative sign
    if (tmp_value < 0)
        *ptr++ = '-';
    *ptr-- = '\0';
    while (ptr1 < ptr) {
        tmp_char = *ptr;
        *ptr-- = *ptr1;
        *ptr1++ = tmp_char;
    }
    return result;
}

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
