/**
��Ӳ���demo1-stm32
�����븴��ճ���˴���Ұ�𡢻�����jason�Ĵ��룬����ֱ��������ҵ��;��
����ʱ�뱣���������������˵��Ͷ��ɹ���
*/


#include "stm32f10x.h"   
#include "Hal_led.h"
int main(void)
{
	LED_GPIO_Init();
	LED_ON(LED1);
	LED_OFF(LED2);
	LED_ON(LED3);
	LED_OFF(LED4);
	
}


