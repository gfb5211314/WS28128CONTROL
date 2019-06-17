#ifndef __BSP_UPDATE_H__
#define __BSP_UPDATE_H__

#include "stm32f1xx_hal.h"





typedef struct
{
    uint8_t defat;    //Ĭ��ģʽ������ϵͳws2812���ݰ�
    uint8_t set_shade;    //����ģʽ 1. ����  2.��������  3.�������
    uint8_t oneline_shade; //���ߵ���ÿ�ν���Ч��
    uint8_t oneline_all; //���ߵ���229����Ч��
	  uint8_t pattern_flay;
} system_mode_type;



extern void  Usart_Logo_data(uint8_t * p_buf,uint8_t * tep_buf,uint16_t r_buf_lenght);


extern void flash_data_to_color_data(void);


#endif

