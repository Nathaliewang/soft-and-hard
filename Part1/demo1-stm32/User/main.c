/**
软硬结合demo1-stm32
软硬结合——写给硬件开发工程师的全栈入门实战。https://github.com/alwxkxk/soft-and-hard
别人已经写好的代码我就直接搬运使用了，不再浪费时间重复做功了。
本代码复制粘贴了大量野火、机智云jason的代码，请勿直接用于商业用途。
搬运时请保留声明以尊重他人的劳动成果。
*/


#include "stm32f10x.h"   
#include "Hal_led.h"
#include "bsp_usart.h"
#include "bsp_GENERALTim.h" 

uint32_t time = 0; // ms 计时变量 

int main(void)
{
	LED_GPIO_Init();
	LED_ON(LED1);
	LED_OFF(LED2);
	LED_ON(LED3);
	LED_OFF(LED4);
	  /*初始化USART 配置模式为 115200 8-N-1，中断接收*/
  USART_Config();
	USART2_Config();
	GENERAL_TIM_Init();
	/* 发送一个字符串 */
	Usart_SendString( DEBUG_USART1,"串口一通信验证\n");
	Usart_SendString( DEBUG_USART2,"串口二通信验证\n");

  while(1)
	{	
		if ( time == 1000 ) /* 1000 * 1 ms = 1s 时间到 */
    {
      time = 0;
			Usart_SendString( DEBUG_USART2,"串口二\n");
			printf("欢迎发板\n");
    }        
	}	
	
}


