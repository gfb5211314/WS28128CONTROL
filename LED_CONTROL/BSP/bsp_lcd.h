#ifndef __BSP_LCD_H__
#define __BSP_LCD_H__
#include "main.h"
#include "stm32f1xx_hal.h"

 #define LCD_RS_CLR   HAL_GPIO_WritePin(GPIOB,DC_LCD_Pin,GPIO_PIN_RESET);         
 #define LCD_RS_SET   HAL_GPIO_WritePin(GPIOB,DC_LCD_Pin,GPIO_PIN_SET); 

 #define LCD_RST_CLR   HAL_GPIO_WritePin(GPIOB,RES_LCD_Pin,GPIO_PIN_RESET);         
 #define LCD_RST_SET   HAL_GPIO_WritePin(GPIOB,RES_LCD_Pin,GPIO_PIN_SET); 






#endif 