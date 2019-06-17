/**
  ******************************************************************************
  * File Name          : main.c
  * Description        : Main program body
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

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f1xx_hal.h"
#include "cmsis_os.h"

/* USER CODE BEGIN Includes */
#include "bsp_usart.h"
#include "bsp_rtc.h"
#include "string.h"
#include  "ws2812_app.h"
#include  "bsp_ws2812.h"
#include <stdlib.h>
#include "string.h"
#include   "bsp_ws2812.h"
#include "stm32f1xx_hal.h"
#include  "math.h"
#include   "bsp_dma.h"
#include "string.h"
#include <stdlib.h>
#include "FreeRTOS.h"
#include "cmsis_os.h"
#include "bsp_tim.h"
#include "bsp_update.h"
/* USER CODE END Includes */

/* Private variables ---------------------------------------------------------*/
RTC_HandleTypeDef hrtc;

TIM_HandleTypeDef htim2;
DMA_HandleTypeDef hdma_tim2_ch1;

UART_HandleTypeDef huart1;
UART_HandleTypeDef huart2;
UART_HandleTypeDef huart3;
DMA_HandleTypeDef hdma_usart3_rx;
DMA_HandleTypeDef hdma_usart3_tx;

osThreadId defaultTaskHandle;
osThreadId systemHandle;
osThreadId myTask03Handle;

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
//void SystemClock_Config(void);
//static void MX_GPIO_Init(void);
//static void MX_DMA_Init(void);
//static void MX_TIM2_Init(void);
//static void MX_USART2_UART_Init(void);
//static void MX_USART1_UART_Init(void);
//static void MX_USART3_UART_Init(void);
//static void MX_RTC_Init(void);
//void StartDefaultTask(void const * argument);
//void SystemTask(void const * argument);
//void Ws2812task(void const * argument);
//                                    
//void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);
                                

/* USER CODE BEGIN PFP */
/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
void MX_GPIO_Init(void);
void MX_DMA_Init(void);
void MX_TIM2_Init(void);
void MX_USART2_UART_Init(void);
void MX_USART1_UART_Init(void);
void MX_USART3_UART_Init(void);
void MX_RTC_Init(void);
void StartDefaultTask(void const * argument);
void SystemTask(void const * argument);
void Ws2812task(void const * argument);
                                    
void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

extern USART_RECEIVETYPE  UsartType3;
extern system_mode_type system_mode;
/* USER CODE END PFP */

/* USER CODE BEGIN 0 */
 uint8_t shade_60_buf_1[6]={52,204,204,241,216,128};
 uint8_t shade_60_buf_2[6]={59,93,170,52,204,204};
 uint8_t shade_60_buf_3[6]={249,5,86,59,93,170};
 uint8_t shade_60_buf_4[6]={241,216,128,249,5,86};
 uint8_t onecolor_buf_1[3]={52,204,204};
 uint8_t onecolor_buf_2[3]={59,93,170};
 uint8_t onecolor_buf_3[3]={249,5,86};
 uint8_t onecolor_buf_4[3]={241,216,128};
/* USER CODE END 0 */

int main(void)
{

  /* USER CODE BEGIN 1 */
SCB->VTOR = 0x8000000 | (0x2000 & (uint32_t)0x1FFFFF80);
  /* USER CODE END 1 */

  /* MCU Configuration----------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_TIM2_Init();
  MX_USART2_UART_Init();
  MX_USART1_UART_Init();
  MX_USART3_UART_Init();
  MX_RTC_Init();

  /* USER CODE BEGIN 2 */
set_time_data(19,6,11,17, 46 ,50);

  DMA_USART_IDLE_INIT();
  /* USER CODE END 2 */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* Create the thread(s) */
  /* definition and creation of defaultTask */
  osThreadDef(defaultTask, StartDefaultTask, osPriorityNormal, 0, 128);
  defaultTaskHandle = osThreadCreate(osThread(defaultTask), NULL);

  /* definition and creation of system */
  osThreadDef(system, SystemTask, osPriorityIdle, 0, 128);
  systemHandle = osThreadCreate(osThread(system), NULL);

  /* definition and creation of myTask03 */
  osThreadDef(myTask03, Ws2812task, osPriorityIdle, 0, 128);
  myTask03Handle = osThreadCreate(osThread(myTask03), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */
 

  /* Start scheduler */
  osKernelStart();
  
  /* We should never get here as control is now taken by the scheduler */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
  /* USER CODE END WHILE */

  /* USER CODE BEGIN 3 */

//		 printf("nihao");
  
  }
  /* USER CODE END 3 */

}

/** System Clock Configuration
*/
void SystemClock_Config(void)
{

  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_PeriphCLKInitTypeDef PeriphClkInit;

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE|RCC_OSCILLATORTYPE_LSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.LSEState = RCC_LSE_ON;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_RTC;
  PeriphClkInit.RTCClockSelection = RCC_RTCCLKSOURCE_LSE;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Configure the Systick interrupt time 
    */
  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

    /**Configure the Systick 
    */
  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, 15, 0);
}





/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/* StartDefaultTask function */
void StartDefaultTask(void const * argument)
{

  /* USER CODE BEGIN 5 */
//	atk_8266_send_cmd("AT+CWMODE=2\r\n","OK",10);
printf("����1");	
//	atk_8266_send_cmd("AT+CWSAP=\"ESPaa\",\"1234567890\",5,3,5\r\n","OK",10);
//	atk_8266_send_cmd("AT+CIPMUX=1\r\n","OK",10);
//	atk_8266_send_cmd("AT+CIPSERVER=1,80\r\n","OK",10);
  /* Infinite loop */
  for(;;)
  {
//				get_timer();
		 if(system_mode.pattern_flay==2)
				{
					
					      
           system_mode_led(2);
					if(system_mode.set_shade==1)
					{
					
						DMA_WS2812_shade_light(LED_MAX);
						//�켣һ
					    
				
//					    DMA_WS2812_shade_logo_all(track_2_color_1);
//						  DMA_WS2812_shade_logo_all(track_2_color_2);
//						  DMA_WS2812_shade_logo_all(track_2_color_3);
//						  DMA_WS2812_shade_logo_all(track_2_color_4);
//						  DMA_WS2812_shade_logo_all(track_2_color_5);

//					    DMA_WS2812_shade_logo_all(track_3_color_1);
//						  DMA_WS2812_shade_logo_all(track_3_color_2);
//						  DMA_WS2812_shade_logo_all(track_3_color_3);
//						  DMA_WS2812_shade_logo_all(track_3_color_4);
//						  DMA_WS2812_shade_logo_all(track_3_color_5);

//					    DMA_WS2812_shade_logo_all(track_4_color_1);
//						  DMA_WS2812_shade_logo_all(track_4_color_2);
//						  DMA_WS2812_shade_logo_all(track_4_color_3);
//						  DMA_WS2812_shade_logo_all(track_4_color_4);
//						  DMA_WS2812_shade_logo_all(track_4_color_5);

//					    DMA_WS2812_shade_logo_all(track_5_color_1);
//						  DMA_WS2812_shade_logo_all(track_5_color_2);
//						  DMA_WS2812_shade_logo_all(track_5_color_3);
//						  DMA_WS2812_shade_logo_all(track_5_color_4);
//						  DMA_WS2812_shade_logo_all(track_5_color_5);
					}
					
				}
			  else if(system_mode.pattern_flay==3)
				{
//					
					    // system_mode_led(3);
					   DMA_WS2812_shade_light(LED_MAX);
					
				}
				else if(system_mode.pattern_flay==4)
				{
					   system_mode_led(3);
//					   reset_led_light(); 
					   DMA_WS2812_shade_light(LED_MAX);
					
				}
    osDelay(1);
  }
  /* USER CODE END 5 */ 
}

/* SystemTask function */
void SystemTask(void const * argument)
{
  /* USER CODE BEGIN SystemTask */
  /* Infinite loop */
  for(;;)
  {
		  
	//	arrange_display_two_run(10);
		Usart_Logo_data(UsartType3.tem_RX_pData,UsartType3.RX_pData,UsartType3.RX_Size);
    osDelay(1);
  }
  /* USER CODE END SystemTask */
}

/* Ws2812task function */
void Ws2812task(void const * argument)
{
	 
  /* USER CODE BEGIN Ws2812task */
	
	reset_led_light();
	 read_mode_start();
	printf("system_mode.pattern_flay=%d\r\n",system_mode.pattern_flay);

		
	
	
	flash_data_to_color_data();	//
  /* Infinite loop */
  for(;;)
  {
		 if(system_mode.pattern_flay==1)
				{
	DMA_WS2812_Ramp(LED_MAX, 255, 1);
  DMA_WS2812_Ramp(LED_MAX, 255, 2);
  DMA_WS2812_Ramp(LED_MAX, 255, 3);
	DMA_WS2812_Rampping(LED_MAX, 255, 2);				   
//	DMA_WS2812_Rampping_1(LED_MAX, 255, 1);
//	DMA_WS2812_one_light_run(2, 2);	
  DMA_WS2812_Run(LED_MAX );	
	DMA_WS2812_Running(LED_MAX);
  DMA_WS2812_Running_more(LED_MAX, 720);		
  arrange_display(LED_MAX);	
 	arrange_display_two(LED_MAX);
	ws2812_rand_light(LED_MAX);
  DMA_WS2812_circulation(LED_MAX);
	DMA_WS2812_circulation_more(LED_MAX,0);
  DMA_WS2812_circulation_more(LED_MAX,1);
	DMA_WS2812_circulation_more(LED_MAX,2);			
  DMA_WS2812_shade_60_run(LED_MAX,shade_60_buf_1);	
		osDelay(500);
  DMA_WS2812_shade_60_run(LED_MAX,shade_60_buf_2);
		osDelay(500);
  DMA_WS2812_shade_60_run(LED_MAX,shade_60_buf_3);
		osDelay(500);
	DMA_WS2812_shade_60_run(LED_MAX,shade_60_buf_4);	
		osDelay(500);
  ws28128_one_color_circulation_run(LED_MAX,onecolor_buf_1);
    osDelay(500);
  ws28128_one_color_circulation_run(LED_MAX,onecolor_buf_2);
    osDelay(500);
  ws28128_one_color_circulation_run(LED_MAX,onecolor_buf_3);
    osDelay(500);
  ws28128_one_color_circulation_run(LED_MAX,onecolor_buf_4);
    osDelay(500);
				}     
    osDelay(1);
  }
  /* USER CODE END Ws2812task */
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  None
  * @retval None
  */
void _Error_Handler(char * file, int line)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  while(1) 
  {
  }
  /* USER CODE END Error_Handler_Debug */ 
}

#ifdef USE_FULL_ASSERT

/**
   * @brief Reports the name of the source file and the source line number
   * where the assert_param error has occurred.
   * @param file: pointer to the source file name
   * @param line: assert_param error line source number
   * @retval None
   */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
    ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */

}

#endif

/**
  * @}
  */ 

/**
  * @}
*/ 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/