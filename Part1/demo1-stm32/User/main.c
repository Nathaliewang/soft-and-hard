/**
软硬结合demo1-stm32
本代码复制粘贴了大量野火、机智云jason的代码，请勿直接用于商业用途。
搬运时请保留声明以尊重他人的劳动成果。
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


