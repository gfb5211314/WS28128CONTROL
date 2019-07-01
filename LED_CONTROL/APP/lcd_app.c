#include  "lcd_app.h"
#include "stm32f1xx_hal.h"
#include "bsp_lcd_gui.h"
#include  "bsp_lcd.h"
typedef   uint8_t u8;
typedef   uint16_t u16;
typedef   uint32_t u32;
void LCD_ShowNumTES(void)
{
	u8 i=0;
	Lcd_Clear(GRAY0);
	Gui_DrawFont_GBK16(8,20,RED,GRAY0,"SHOW_Num");
	osDelay(1000);
	Lcd_Clear(GRAY0);

	for(i=0;i<255;i++)
	{
			LCD_ShowNum(35,0,i,3);
			LCD_ShowNum(35,20,i,3);
	    LCD_ShowNum(35,40,i,3);
			LCD_ShowNum(35,60,i,3);


	osDelay(10);
	}
	
}


void showimage(const unsigned char *p) //显示40*40 QQ图片
{
  	int i,j,k; 
	unsigned char picH,picL;
	Lcd_Clear(WHITE); //清屏  
	
	for(k=0;k<2;k++)
	{
	   	for(j=0;j<4;j++)
		{	
			Lcd_SetRegion(40*j,40*k,40*j+39,40*k+39);		//坐标设置
		    for(i=0;i<40*40;i++)
			 {	
			 	picL=*(p+i*2);	//数据低位在前
				picH=*(p+i*2+1);				
				LCD_WriteData_16Bit(picH<<8|picL);  						
			 }	
		 }
	}		
}
void Redraw_Mainmenu(void)
{

//	Lcd_Clear(GRAY0);
	
	Gui_DrawFont_GBK16(50,0,BLUE,GRAY0,"模式一");
	Gui_DrawFont_GBK16(50,20,RED,GRAY0,"模式二");

//	DisplayButtonUp(0,38,80,58); //x1,y1,x2,y2
	Gui_DrawFont_GBK16(50,40,BLUE,GRAY0,"模式三");

//	DisplayButtonUp(0,68,80,88); //x1,y1,x2,y2
	 Gui_DrawFont_GBK16(50,60,BLUE,GRAY0,"连接");



}