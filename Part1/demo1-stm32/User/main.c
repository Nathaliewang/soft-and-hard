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

uint32_t time = 0; // ms ��ʱ���� 

int main(void)
{
	LED_GPIO_Init();
	LED_ON(LED1);
	LED_OFF(LED2);
	LED_ON(LED3);
	LED_OFF(LED4);
	  /*��ʼ��USART ����ģʽΪ 115200 8-N-1���жϽ���*/
  USART_Config();
	USART2_Config();
	GENERAL_TIM_Init();
	/* ����һ���ַ��� */
	Usart_SendString( DEBUG_USART1,"����һͨ����֤\n");
	Usart_SendString( DEBUG_USART2,"���ڶ�ͨ����֤\n");

  while(1)
	{	
		if ( time == 1000 ) /* 1000 * 1 ms = 1s ʱ�䵽 */
    {
      time = 0;
			Usart_SendString( DEBUG_USART2,"���ڶ�\n");
			printf("��ӭ����\n");
    }        
	}	
	
}


