/**
��Ӳ���demo1-stm32
��Ӳ��ϡ���д��Ӳ����������ʦ��ȫջ����ʵս��https://github.com/alwxkxk/soft-and-hard
�����Ѿ�д�õĴ����Ҿ�ֱ�Ӱ���ʹ���ˣ������˷�ʱ���ظ������ˡ�
�����븴��ճ���˴���Ұ�𡢻�����jason�Ĵ��룬����ֱ��������ҵ��;��
����ʱ�뱣���������������˵��Ͷ��ɹ���
*/


#include "stm32f10x.h"   
#include "Hal_led.h"
#include "bsp_usart.h"
#include "bsp_GENERALTim.h" 
#include "ESP8266.h" 
#include "bsp_adc.h"

#define 	WIFI_SSID 										"tp-link" //WIFI�� ��������Լ�����޸�
#define 	WIFI_PASSWORD 								"12345678" // WIFI���� ��������Լ�����޸�
#define  	TCP_IP                   			"127.0.0.1"
#define  	TCP_PORT                   		2424


extern __IO uint16_t ADC_ConvertedValue;
// �ֲ����������ڱ���ת�������ĵ�ѹֵ 	 
float ADC_ConvertedValueLocal;      
int LED1_Flag;

uint32_t time = 0; // ms ��ʱ���� 

int main(void)
{
	char adcValue[20];
	LED_GPIO_Init();
	// ADC ��ʼ��
	ADCx_Init();
	LED_OFF(LED1);
	LED1_Flag = 0;
	LED_OFF(LED2);
	LED_OFF(LED3);
	LED_OFF(LED4);
	  /*��ʼ��USART ����ģʽΪ 115200 8-N-1���жϽ���*/
  USART_Config();
	USART2_Config();
	GENERAL_TIM_Init();
	/* ����һ���ַ��� */
//	Usart_SendString( DEBUG_USART1,"����һͨ����֤\n");
//	Usart_SendString( DEBUG_USART2,"���ڶ�ͨ����֤\n");
	
	//ͨ��AT����ģʽ������WIFI������TCP
	AT_Mode_Set(AT_MODE_STATION);
	AT_connectWIFI(WIFI_SSID,WIFI_PASSWORD);
	AT_connectTCP(TCP_IP,TCP_PORT);
	AT_Sent_TCP_Data("hello~");
	
  while(1)
	{	
		if ( time == 1000 ) /* 1000 * 1 ms = 1s ʱ�䵽 */
    {
			time = 0;
			//���շ�������ָ�����ָ���LED
			AT_TCP_Receive();
			// ת��ADC1 ��ֵ
			ADC_ConvertedValueLocal =(float) ADC_ConvertedValue/4096*3.3; 
			
			//�ر�أ���ADC1��ֵ����1ʱ�ر�LED1
			if(ADC_ConvertedValueLocal <1.0 && LED1_Flag == 1){
				printf(" ��ǰADC1��%.2f,�ر�LED1\r\n", ADC_ConvertedValueLocal); 
				LED_OFF(LED1);
				LED1_Flag = 0;
				AT_Sent_TCP_Data("LED1:0");
			}
			//��ADC1��ֵ����3ʱ����LED1
			if(ADC_ConvertedValueLocal >3.0 && LED1_Flag == 0){
				printf(" ��ǰADC1��%.2f,��LED1\r\n", ADC_ConvertedValueLocal); 
				LED_ON(LED1);
				LED1_Flag = 1;
				AT_Sent_TCP_Data("LED1:1");
			}
			
			//���͵�ǰ ADC1��ֵ
			sprintf(adcValue,"ADC1:%.2f",ADC_ConvertedValueLocal);
			AT_Sent_TCP_Data(adcValue);				
    }        
	}	
	
}


