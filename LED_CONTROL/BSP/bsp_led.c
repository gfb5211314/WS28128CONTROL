#include  "bsp_led.h"
#include "stm32f1xx_hal.h"



void system_mode_led(uint8_t mode)
{
	 if(mode==1)
	{
		  HAL_GPIO_WritePin(GPIOB, R_LED_Pin,GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOB, G_LED_Pin|B_LED_Pin,GPIO_PIN_SET);
	}
	else if(mode==2)
	{
		
		  HAL_GPIO_WritePin(GPIOB, G_LED_Pin , GPIO_PIN_RESET);
		 HAL_GPIO_WritePin(GPIOB, R_LED_Pin|B_LED_Pin,GPIO_PIN_SET);
	}
	else if(mode==3)
	{
		
		
		  HAL_GPIO_WritePin(GPIOB,B_LED_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, R_LED_Pin|G_LED_Pin,GPIO_PIN_SET);
	}
	
}


void wifi_state_led(uint8_t state)
{
		   if(state==0)
	{
		  HAL_GPIO_WritePin(GPIOB, wifi_led_Pin,GPIO_PIN_RESET);
		 
	}
	else if(state==1)
	{
		 HAL_GPIO_WritePin(GPIOB, wifi_led_Pin,GPIO_PIN_SET);
		 
	}
}
