#ifndef   __ESP8266_H__
#define   __ESP8266_H__

#include "stm32f1xx_hal.h"

#define  wifi8266_name_addr      0x800e410                      //57KÆ¬Çø         
#define  wifi8266_password_addr  0x800e440                      //57KÆ¬Çø
typedef struct {
	uint8_t  name[20];
  uint8_t  password[20];
  uint8_t  wifi_con[100];	
	uint8_t  wifi_con_len;
	uint8_t  wifi_state;
}wifi_type;
extern uint8_t atk_8266_send_cmd(uint8_t *cmd,uint8_t *ack,uint16_t waittime);

extern uint8_t* esp8266_Capture_data(uint8_t *rec_data,uint8_t *head_buf);


#endif

