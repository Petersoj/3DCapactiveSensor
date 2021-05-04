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

char set_min_bool = 1;
char calibration_done = 0;
uint32_t plate_capacitance_min_counts[3] = {0};
uint32_t plate_capacitance_max_counts[3] = {0};

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
    // PC6 = X Plate
    // PC7 = Y Plate
    // PC8 = Z Plate
    //
    // PC4 = STM32 TX / USB-UART RX
    // PC5 = STM32 RX / USB-UART TX

    configure_rcc();
    configure_usart3_tx();
    configure_gpio(GPIOC, 6);
    configure_gpio(GPIOC, 7);
    configure_gpio(GPIOC, 8);

    // Configure PA0 (User Button) as input
    // set_bits(&GPIOA->MODER, 0x0, GPIO_MODER_MODER0_Pos + 1, GPIO_MODER_MODER0_Pos);
    // set_bits(&GPIOA->PUPDR, 0x2, GPIO_PUPDR_PUPDR0_Pos + 1, GPIO_PUPDR_PUPDR0_Pos);
    RCC->AHBENR |= RCC_AHBENR_GPIOAEN; // Enable peripheral clock to GPIOA
    GPIOA->MODER &= ~(GPIO_MODER_MODER0_0 | GPIO_MODER_MODER0_1);           // Set PA0 to input
    GPIOC->OSPEEDR &= ~(GPIO_OSPEEDR_OSPEEDR0_0 | GPIO_OSPEEDR_OSPEEDR0_1); // Set to low speed
    GPIOC->PUPDR |= GPIO_PUPDR_PUPDR0_1;                                    // Set to pull-down

    uint8_t button_debouncer = 0;

    /* USER CODE END 2 */

    /* Infinite loop */
    /* USER CODE BEGIN WHILE */
    while (1) {
        /* USER CODE END WHILE */

        /* USER CODE BEGIN 3 */
        uint32_t x_capacitance = poll_capacitance(GPIOC, 6);
        uint32_t y_capacitance = poll_capacitance(GPIOC, 7);
        uint32_t z_capacitance = poll_capacitance(GPIOC, 8);

        uint8_t user_button = GPIOA->IDR & (1 << 0);
        if (user_button) {
            button_debouncer = 1;
        }
        if (button_debouncer == 1 && user_button == 0) {
            button_debouncer = 0;
            if (set_min_bool) {
                plate_capacitance_min_counts[0] = x_capacitance;
                plate_capacitance_min_counts[1] = y_capacitance;
                plate_capacitance_min_counts[2] = z_capacitance;
                set_min_bool = 0;
            } else {
                plate_capacitance_max_counts[0] = x_capacitance;
                plate_capacitance_max_counts[1] = y_capacitance;
                plate_capacitance_max_counts[2] = z_capacitance;

                char buffer[20];
                // Transmit formatted min and max to client
                usart3_transmit_string("min,");
                to_string(plate_capacitance_min_counts[0], buffer, 10);
                usart3_transmit_string(buffer);
                usart3_transmit_char(',');
                to_string(plate_capacitance_min_counts[1], buffer, 10);
                usart3_transmit_string(buffer);
                usart3_transmit_char(',');
                to_string(plate_capacitance_min_counts[2], buffer, 10);
                usart3_transmit_string(buffer);
                usart3_transmit_newline(CRLF);

                usart3_transmit_string("max,");
                to_string(plate_capacitance_max_counts[0], buffer, 10);
                usart3_transmit_string(buffer);
                usart3_transmit_char(',');
                to_string(plate_capacitance_max_counts[1], buffer, 10);
                usart3_transmit_string(buffer);
                usart3_transmit_char(',');
                to_string(plate_capacitance_max_counts[2], buffer, 10);
                usart3_transmit_string(buffer);
                usart3_transmit_newline(CRLF);

                set_min_bool = 1;
                calibration_done = 1;
            }
        }

        if (calibration_done) {
            char buffer[20];
            to_string(x_capacitance, buffer, 10);
            usart3_transmit_string(buffer);
            usart3_transmit_string(",");
            to_string(y_capacitance, buffer, 10);
            usart3_transmit_string(buffer);
            usart3_transmit_string(",");
            to_string(z_capacitance, buffer, 10);
            usart3_transmit_string(buffer);
            usart3_transmit_newline(CRLF);
        }
        /*

                usart3_transmit_newline(CRLF);
char string[20];
to_string(plate_capacitance_min_counts[0], string, 10);
usart3_transmit_string(string);
usart3_transmit_char(',');
to_string(plate_capacitance_min_counts[1], string, 10);
usart3_transmit_string(string);
usart3_transmit_char(',');
to_string(plate_capacitance_min_counts[2], string, 10);
usart3_transmit_string(string);

usart3_transmit_newline(CRLF);

to_string(plate_capacitance_max_counts[0], string, 10);
usart3_transmit_string(string);
usart3_transmit_char(',');
to_string(plate_capacitance_max_counts[1], string, 10);
usart3_transmit_string(string);
usart3_transmit_char(',');
to_string(plate_capacitance_max_counts[2], string, 10);
usart3_transmit_string(string);*/
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
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
    RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
    RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL6;
    RCC_OscInitStruct.PLL.PREDIV = RCC_PREDIV_DIV1;
    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
        Error_Handler();
    }
    /** Initializes the CPU, AHB and APB buses clocks
     */
    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK) {
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

uint32_t poll_capacitance(GPIO_TypeDef *gpio_pointer, uint8_t gpio_number) {
    int total = 0, count = 0;
    // This while loop is to average several low 'count' samples
    // to get a more accurate reading.
    while (total < 1000) {
        gpio_pull_low(gpio_pointer, gpio_number);        // Discharges plate capacitor
        gpio_configure_input(gpio_pointer, gpio_number); // Sets GPIO as high impedance
        // Loop until GPIO pin positive edge (plate capacitor charging)
        while (gpio_get_input(gpio_pointer, gpio_number) == 0) {
            count++;
        }
        total++;
    }
    return (count << 12) / total;
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
