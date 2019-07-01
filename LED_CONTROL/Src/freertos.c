/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
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
#include "FreeRTOS.h"
#include "task.h"

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
#include  "esp8266.h"
#include "bsp_lcd_gui.h"
//#include "bsp_lcd_font.h"
/* USER CODE END Includes */



/* Variables -----------------------------------------------------------------*/

/* USER CODE BEGIN Variables */
extern USART_RECEIVETYPE  UsartType3;
extern system_mode_type system_mode;
extern osThreadId defaultTaskHandle;
extern osThreadId systemHandle;
extern osThreadId myTask03Handle; 
extern wifi_type   wifi8266;
extern char str_time[40]; 

/* USER CODE END Variables */

/* Function prototypes -------------------------------------------------------*/

/* USER CODE BEGIN FunctionPrototypes */
/* StartDefaultTask function */
void StartDefaultTask(void const * argument)
{
	

	
	 Lcd_Init();		
	  Lcd_Clear(0xffff) ;
	 Gui_DrawFont_GBK16(35,20,BLUE,GRAY0,"wifi已断开");
	Gui_DrawFont_GBK16(40,40,RED,GRAY0,"系统时间");
	HAL_Delay(500);
  /* USER CODE BEGIN 5 */
	atk_8266_send_cmd("AT+CWMODE=3\r\n","OK",10);
	if(wifi8266.wifi_con_len!=255)
	{
//			atk_8266_send_cmd(wifi8266.wifi_con,"OK",10);
	}
	else
	{
	atk_8266_send_cmd("AT+CWSAP=\"ESPaa\",\"1234567890\",5,3\r\n","OK",10);
	}
	atk_8266_send_cmd("AT+CIPMUX=1\r\n","OK",10);
	atk_8266_send_cmd("AT+CIPSERVER=1,80\r\n","OK",10);
		reset_led_light();
	
	flash_data_to_color_data();	//

  /* Infinite loop */
  for(;;)
  {
//		 	Lcd_Clear(WHITE);
// Lcd_Clear(GRAY0);
		Gui_DrawFont_GBK16(5,60,BLUE,GRAY0,str_time);
	
//		Redraw_Mainmenu();
//		LCD_ShowNumTES();
		if(wifi8266.wifi_state==1)
		{
			 Gui_DrawFont_GBK16(35,20,BLUE,GRAY0,"wifi已连接");
			
		}
		else
		{
					 Gui_DrawFont_GBK16(35,20,BLUE,GRAY0,"wifi已断开");
			
		}
		 if(system_mode.pattern_flay==2)
				{
					
//         printf("进入moshi 2");
           system_mode_led(2);
						Gui_DrawFont_GBK16(50,0,RED,GRAY0,"模式二");
					if(system_mode.set_shade==1)
					{
					
						DMA_WS2812_shade_light(LED_MAX);
						//轨迹一
					    
				
//					    DMA_WS2812_shade_logo_all(track_2_color_1);

					}
					
				}
			  else if(system_mode.pattern_flay==3)
				{
//		
					    // system_mode_led(3);
					   DMA_WS2812_shade_light(LED_MAX);
						system_mode_led(3);
						Gui_DrawFont_GBK16(50,0,RED,GRAY0,"模式三");
//									 printf("进入moshi 3");
				}
				else if(system_mode.pattern_flay==4)
				{
//									 printf("进入moshi 3");
					   system_mode_led(3);
//					   reset_led_light(); 
					   DMA_WS2812_shade_light(LED_MAX);
									Gui_DrawFont_GBK16(50,0,BLUE,GRAY0,"模式三");
				}
					else if(system_mode.pattern_flay==1||system_mode.pattern_flay==255||system_mode.pattern_flay==0)
				{
						Gui_DrawFont_GBK16(50,0,RED,GRAY0,"模式一");
					
					system_mode_led(1);
				}
//				printf("进入StartDefaultTask\r\n");
    osDelay(1);
  }
  /* USER CODE END 5 */ 
}

/* SystemTask function */
void SystemTask(void const * argument)
{

  /* USER CODE BEGIN SystemTask */
//  UBaseType_t uxHighWaterMark;
//	UBaseType_t uxHighWaterMark1;
//	UBaseType_t uxHighWaterMar2;
  /* Infinite loop */
  for(;;)
  {
	  get_timer();
		 
//Gui_DrawFont_GBK16(30,60,RED,GRAY0,"系统时间");
	//	arrange_display_two_run(10);
//		printf("bihao");
		
//		uxHighWaterMark=uxTaskGetStackHighWaterMark( defaultTaskHandle );
//   printf("StartDefaultTask剩余栈空间是多少：%d.\r\n",uxHighWaterMark);
//				uxHighWaterMark1=uxTaskGetStackHighWaterMark( systemHandle );
//   printf("SystemTask剩余栈空间是多少：%d.\r\n",uxHighWaterMark1);
//				uxHighWaterMar2=uxTaskGetStackHighWaterMark( myTask03Handle );
//   printf("Ws2812task剩余栈空间是多少：%d.\r\n",uxHighWaterMar2);
	Usart_Logo_data(UsartType3.tem_RX_pData,UsartType3.RX_pData,UsartType3.RX_Size);
//					printf("SystemTask\r\n");
    osDelay(1);
  }
  /* USER CODE END SystemTask */
}

/* Ws2812task function */
void Ws2812task(void const * argument)
{
  /* USER CODE BEGIN Ws2812task */
//	 Lcd_Init();	

  /* Infinite loop */
  for(;;)
  {
			 
//				printf("Ws2812task\r\n");	
		 if(system_mode.pattern_flay==1||system_mode.pattern_flay==255||system_mode.pattern_flay==0)
				{
//					 printf("进入moshi 1");
					system_mode_led(1);
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
//  DMA_WS2812_shade_60_run(LED_MAX,shade_60_buf_1);	
//		osDelay(500);
//  DMA_WS2812_shade_60_run(LED_MAX,shade_60_buf_2);
//		osDelay(500);
//  DMA_WS2812_shade_60_run(LED_MAX,shade_60_buf_3);
//		osDelay(500);
//	DMA_WS2812_shade_60_run(LED_MAX,shade_60_buf_4);	
//		osDelay(500);
//  ws28128_one_color_circulation_run(LED_MAX,onecolor_buf_1);
//    osDelay(500);
//  ws28128_one_color_circulation_run(LED_MAX,onecolor_buf_2);
//    osDelay(500);
//  ws28128_one_color_circulation_run(LED_MAX,onecolor_buf_3);
//    osDelay(500);
//  ws28128_one_color_circulation_run(LED_MAX,onecolor_buf_4);
//    osDelay(500);
				} 
//		printf("Ws2812task\r\n");				
    osDelay(1);
  }
  /* USER CODE END Ws2812task */
}
/* USER CODE END FunctionPrototypes */

/* Hook prototypes */

/* USER CODE BEGIN Application */
     
/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
