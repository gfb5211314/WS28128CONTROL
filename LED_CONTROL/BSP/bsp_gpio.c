#include     "bsp_gpio.h"
#include "stm32f1xx_hal.h"






/** Configure pins as 
        * Analog 
        * Input 
        * Output
        * EVENT_OUT
        * EXTI
*/
 void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct;

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, CS_LCD_Pin|SCL_LCD_Pin|CLK_LCD_Pin|SDA_LCD_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, RES_LCD_Pin|DC_LCD_Pin|wifi_led_Pin|R_LED_Pin 
                          |G_LED_Pin|B_LED_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : CS_LCD_Pin SCL_LCD_Pin CLK_LCD_Pin SDA_LCD_Pin */
  GPIO_InitStruct.Pin = CS_LCD_Pin|SCL_LCD_Pin|CLK_LCD_Pin|SDA_LCD_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : RES_LCD_Pin DC_LCD_Pin wifi_led_Pin R_LED_Pin 
                           G_LED_Pin B_LED_Pin */
  GPIO_InitStruct.Pin = RES_LCD_Pin|DC_LCD_Pin|wifi_led_Pin|R_LED_Pin 
                          |G_LED_Pin|B_LED_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
	


}
