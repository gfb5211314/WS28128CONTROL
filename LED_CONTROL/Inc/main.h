/**
  ******************************************************************************
  * File Name          : main.hpp
  * Description        : This file contains the common defines of the application
  ******************************************************************************
  * This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * Copyright (c) 2019 STMicroelectronics International N.V. 
  * All rights reserved.
  *
  * Redistribution and use in source and binary forms, with or without 
  * modification, are permitted, provided that the following conditions are met:
  *
  * 1. Redistribution of source code must retain the above copyright notice, 
  *    this list of conditions and the following disclaimer.
  * 2. Redistributions in binary form must reproduce the above copyright notice,
  *    this list of conditions and the following disclaimer in the documentation
  *    and/or other materials provided with the distribution.
  * 3. Neither the name of STMicroelectronics nor the names of other 
  *    contributors to this software may be used to endorse or promote products 
  *    derived from this software without specific written permission.
  * 4. This software, including modifications and/or derivative works of this 
  *    software, must execute solely and exclusively on microcontroller or
  *    microprocessor devices manufactured by or for STMicroelectronics.
  * 5. Redistribution and use of this software other than as permitted under 
  *    this license is void and will automatically terminate your rights under 
  *    this license. 
  *
  * THIS SOFTWARE IS PROVIDED BY STMICROELECTRONICS AND CONTRIBUTORS "AS IS" 
  * AND ANY EXPRESS, IMPLIED OR STATUTORY WARRANTIES, INCLUDING, BUT NOT 
  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
  * PARTICULAR PURPOSE AND NON-INFRINGEMENT OF THIRD PARTY INTELLECTUAL PROPERTY
  * RIGHTS ARE DISCLAIMED TO THE FULLEST EXTENT PERMITTED BY LAW. IN NO EVENT 
  * SHALL STMICROELECTRONICS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, 
  * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H
  /* Includes ------------------------------------------------------------------*/

/* Includes ------------------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private define ------------------------------------------------------------*/

#define WS2812_OutPut_Pin GPIO_PIN_0
#define WS2812_OutPut_GPIO_Port GPIOA
#define U2_Tx_Pin GPIO_PIN_2
#define U2_Tx_GPIO_Port GPIOA
#define U2_Rx_Pin GPIO_PIN_3
#define U2_Rx_GPIO_Port GPIOA
#define CS_LCD_Pin GPIO_PIN_4
#define CS_LCD_GPIO_Port GPIOA
#define SCL_LCD_Pin GPIO_PIN_5
#define SCL_LCD_GPIO_Port GPIOA
#define CLK_LCD_Pin GPIO_PIN_6
#define CLK_LCD_GPIO_Port GPIOA
#define SDA_LCD_Pin GPIO_PIN_7
#define SDA_LCD_GPIO_Port GPIOA
#define RES_LCD_Pin GPIO_PIN_0
#define RES_LCD_GPIO_Port GPIOB
#define DC_LCD_Pin GPIO_PIN_1
#define DC_LCD_GPIO_Port GPIOB
#define Wifi_Tx_Pin GPIO_PIN_10
#define Wifi_Tx_GPIO_Port GPIOB
#define Wifi_Rx_Pin GPIO_PIN_11
#define Wifi_Rx_GPIO_Port GPIOB
#define Debug_Tx_Pin GPIO_PIN_9
#define Debug_Tx_GPIO_Port GPIOA
#define Debug_Rx_Pin GPIO_PIN_10
#define Debug_Rx_GPIO_Port GPIOA
#define wifi_led_Pin GPIO_PIN_4
#define wifi_led_GPIO_Port GPIOB
#define R_LED_Pin GPIO_PIN_5
#define R_LED_GPIO_Port GPIOB
#define G_LED_Pin GPIO_PIN_6
#define G_LED_GPIO_Port GPIOB
#define B_LED_Pin GPIO_PIN_7
#define B_LED_GPIO_Port GPIOB

/* ########################## Assert Selection ############################## */
/**
  * @brief Uncomment the line below to expanse the "assert_param" macro in the 
  *        HAL drivers code
  */
/* #define USE_FULL_ASSERT    1U */

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
 extern "C" {
#endif
void _Error_Handler(char *, int);

#define Error_Handler() _Error_Handler(__FILE__, __LINE__)
#ifdef __cplusplus
}
#endif

/**
  * @}
  */ 

/**
  * @}
*/ 

#endif /* __MAIN_H */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
