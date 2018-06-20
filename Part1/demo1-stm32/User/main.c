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
#include "ESP8266.h" 
#include "bsp_adc.h"

#define 	WIFI_SSID 										"tp-link" //WIFI名 必须根据自己情况修改
#define 	WIFI_PASSWORD 								"12345678" // WIFI密码 必须根据自己情况修改
#define  	TCP_IP                   			"192.168.1.121"
#define  	TCP_PORT                   		2424


extern __IO uint16_t ADC_ConvertedValue;
// 局部变量，用于保存转换计算后的电压值 	 
float ADC_ConvertedValueLocal;      
int LED1_Flag;

uint32_t time = 0; // ms 计时变量 

int main(void)
{
	char adcValue[20];
	LED_GPIO_Init();
	// ADC 初始化
	ADCx_Init();
	LED_OFF(LED1);
	LED1_Flag = 0;
	LED_OFF(LED2);
	LED_OFF(LED3);
	LED_OFF(LED4);
	  /*初始化USART 配置模式为 115200 8-N-1，中断接收*/
  USART_Config();
	USART2_Config();
	GENERAL_TIM_Init();
	/* 发送一个字符串 */
//	Usart_SendString( DEBUG_USART1,"串口一通信验证\n");
//	Usart_SendString( DEBUG_USART2,"串口二通信验证\n");
	
	//通过AT设置模式并连接WIFI，连接TCP
	AT_Mode_Set(AT_MODE_STATION);
	AT_connectWIFI(WIFI_SSID,WIFI_PASSWORD);
	AT_connectTCP(TCP_IP,TCP_PORT);
	AT_Sent_TCP_Data("hello~");
	
  while(1)
	{	
		if ( time == 1000 ) /* 1000 * 1 ms = 1s 时间到 */
    {
			time = 0;
			//接收服务器的指令并根据指令开关LED
			AT_TCP_Receive();
			// 转换ADC1 的值
			ADC_ConvertedValueLocal =(float) ADC_ConvertedValue/4096*3.3; 
			
			//特别地，当ADC1的值低于1时关闭LED1
			if(ADC_ConvertedValueLocal <1.0 && LED1_Flag == 1){
				printf(" 当前ADC1：%.2f,关闭LED1\r\n", ADC_ConvertedValueLocal); 
				LED_OFF(LED1);
				LED1_Flag = 0;
				AT_Sent_TCP_Data("LED1:0");
			}
			//当ADC1的值高于3时开启LED1
			if(ADC_ConvertedValueLocal >3.0 && LED1_Flag == 0){
				printf(" 当前ADC1：%.2f,打开LED1\r\n", ADC_ConvertedValueLocal); 
				LED_ON(LED1);
				LED1_Flag = 1;
				AT_Sent_TCP_Data("LED1:1");
			}
			
			//发送当前 ADC1的值
			sprintf(adcValue,"ADC1:%.2f",ADC_ConvertedValueLocal);
			AT_Sent_TCP_Data(adcValue);				
    }        
	}	
	
}


