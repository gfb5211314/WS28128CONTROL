#include "bsp_rtc.h"
#include "stdlib.h"
#include "string.h"
#include <cstdlib>
#include <cstdio>
#include "bsp_lcd_gui.h"
extern RTC_HandleTypeDef hrtc;
RTC_TimeTypeDef control_time;
RTC_DateTypeDef control_date;

/* RTC init function */
void MX_RTC_Init(void)
{

  RTC_TimeTypeDef sTime;
  RTC_DateTypeDef DateToUpdate;

    /**Initialize RTC Only 
    */
  hrtc.Instance = RTC;
  hrtc.Init.AsynchPrediv = RTC_AUTO_1_SECOND;
  hrtc.Init.OutPut = RTC_OUTPUTSOURCE_ALARM;
  if (HAL_RTC_Init(&hrtc) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Initialize RTC and set the Time and Date 
    */
  if(HAL_RTCEx_BKUPRead(&hrtc, RTC_BKP_DR1) != 0x32F2){
  sTime.Hours = 0x11;
  sTime.Minutes = 0x50;
  sTime.Seconds = 0x0;

  if (HAL_RTC_SetTime(&hrtc, &sTime, RTC_FORMAT_BCD) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  DateToUpdate.WeekDay = RTC_WEEKDAY_TUESDAY;
  DateToUpdate.Month = RTC_MONTH_JUNE;
  DateToUpdate.Date = 0x1;
  DateToUpdate.Year = 0x19;

  if (HAL_RTC_SetDate(&hrtc, &DateToUpdate, RTC_FORMAT_BCD) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    HAL_RTCEx_BKUPWrite(&hrtc,RTC_BKP_DR1,0x32F2);
  }
}
  char str_time[40];
 
void get_timer()
{
	   memset(str_time, 0, sizeof(str_time)); 
	                
	if(HAL_RTC_GetDate(&hrtc,&control_date, RTC_FORMAT_BIN)==HAL_OK)
	{
//		 printf("/***************************************************/\r\n");
//	 printf("20%d年%d月%d日\r\n",control_date.Year,control_date.Month,control_date.Date);
		  
            char string[2];
		    sprintf(string,"%02d", control_date.Year);
		       strcpy (str_time,"20");
		       strcat (str_time,string);
	         strcat (str_time,"/");
		    sprintf(string, "%02d", control_date.Month);
		       strcat (str_time,string);
	         strcat (str_time,"/");
		    sprintf(string, "%02d", control_date.Date);
			     strcat (str_time,string);
	         strcat (str_time," ");

//   printf("string=%s\n",str_time);
 
  
//		  
//    strcpy (str,"these");
//    strcat (str,"strings ");
//    strcat (str,"are ");
//    strcat (str,"concatenated.");
//		printf("%s",str);
	}
 if(HAL_RTC_GetTime(&hrtc, &control_time, RTC_FORMAT_BIN)==HAL_OK)
 {
	 
	 
//	  printf("%d时%d分%d秒\r\n",control_time.Hours,control_time.Minutes,control_time.Seconds);
	     char string1[2];
		    sprintf(string1,"%02d", control_time.Hours);
		       strcat (str_time,string1);
	 strcat (str_time,":");
		    sprintf(string1, "%02d", control_time.Minutes);
		       strcat (str_time,string1);
	 strcat (str_time,":");
		    sprintf(string1, "%02d", control_time.Seconds);
			      strcat (str_time,string1);
	 //加个空格,可以去掉最后一位，当占位
//	          strcat (str_time," ");
//	 strcat (str_time,"");

 }
}
void set_time_data(uint16_t Year,uint16_t Month,uint16_t Date,uint16_t Hours, uint16_t Minutes ,uint16_t Seconds)
{
	  control_date.Year=Year;
	  control_date.Month=Month;
	  control_date.Date=Date;
	  control_time.Hours=Hours;
	  control_time.Minutes=Minutes;
	  control_time.Seconds=Seconds;
	 HAL_RTCEx_BKUPWrite(&hrtc, RTC_BKP_DR2,  control_date.Year);
   HAL_RTCEx_BKUPWrite(&hrtc, RTC_BKP_DR3, control_date.Month );
   HAL_RTCEx_BKUPWrite(&hrtc, RTC_BKP_DR4, control_date.Date);
	 HAL_RTC_SetDate(&hrtc,&control_date,RTC_FORMAT_BIN);
	 HAL_RTC_SetTime(&hrtc,&control_time,RTC_FORMAT_BIN);
}



