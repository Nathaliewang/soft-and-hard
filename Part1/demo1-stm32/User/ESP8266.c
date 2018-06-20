#include "bsp_usart.h"
#include "ESP8266.h"
#include "bsp_GENERALTim.h" 
#include "Hal_led.h"
extern volatile uint32_t time; // ms 计时变量 
extern int LED1_Flag;
#include <stdio.h>	
#include <string.h>

int AT_Status;
char receiveStr[1024];
//向ESP8266发送数据 等于发 串口二 发送数据
//\x0d\x0a 是回车换行
//函数运行成功返回0，失败返回负值

void AT_Sent_init(void)
{
	memset(receiveStr,'\0',1024);//初始化字符串
	AT_Status = AT_STATUS_SEND;
}

//发送AT
int AT_Test(void)
{
	AT_Sent_init();
	Usart_SendString( DEBUG_USART2,"AT\x0d\x0a");
	if(Wait_OK()){
		printf("AT 测试失败请检查硬件连接\n");
		return -1;
	}
	else{
		printf("AT 测试成功\n");
		return 0;
	}

}

//设置对应的模式，AT固件1.6版本对应值如下
//1- AT_MODE_STATION	- station模式，（必须设置此模式才能连接上WIFI）
//2- AT_MODE_AP - AP模式
//3- AT_MODE_STATION_AP - 混合模式
int AT_Mode_Set(int mode)
{
	char sentStr[32];
	AT_Sent_init();
	sprintf(sentStr,"AT+CWMODE=%1d\x0d\x0a",mode);
	Usart_SendString( DEBUG_USART2,sentStr);
	if(Wait_OK()){
		printf("AT 设置模式失败\n");
		return -1;
	}
	else{
		printf("AT 设置模式成功\n");
		return 0;
	}
}

// 连接WIFI
int AT_connectWIFI(char *ssid,char *password)
{
	char sentStr[128];
	AT_Sent_init();
	sprintf(sentStr,"AT+CWJAP=\"%s\",\"%s\"\x0d\x0a",ssid,password);
	Usart_SendString(DEBUG_USART2,sentStr);
	if(Wait_OK()){
		printf("AT 连接WIFI失败\n");
		return -1;
	}
	else{
		printf("AT 连接WIFI成功\n");
		return 0;
	}
}

// 连接TCP
int AT_connectTCP(char *ip,int port)
{
	char sentStr[64];
	AT_Sent_init();
	sprintf(sentStr,"AT+CIPSTART=\"TCP\",\"%s\",%d\x0d\x0a",ip,port);
	Usart_SendString( DEBUG_USART2,sentStr);
	if(Wait_OK()){
		printf("AT 连接TCP失败\n");
		return -1;
	}
	else{
		printf("AT 连接TCP成功\n");
		return 0;
	}
}

// 发送TCP数据
void AT_Sent_TCP_Data(char *str)
{
	char sentStr[32];
	AT_Sent_init();
	sprintf(sentStr,"AT+CIPSEND=%d\x0d\x0a",strlen(str));
	Usart_SendString(DEBUG_USART2,sentStr);
	if(Wait_OK()){
		printf("AT 发送TCP数据失败\n");
	}
	else{
		Usart_SendString(DEBUG_USART2,str);
	}
}

// 检查TCP有没有传来数据
void AT_TCP_Receive(void)
{
	char *flag = strstr(receiveStr,"+IPD,");
	char *LED1_Open = strstr(receiveStr,"LED1:1");
	char *LED1_Close = strstr(receiveStr,"LED1:0");
	char *LED2_Open = strstr(receiveStr,"LED2:1");
	char *LED2_Close = strstr(receiveStr,"LED2:0");
	if(flag != NULL){
		//+IPD,7:LED2:1    向右偏移7个字节刚好得到完整数据
		printf("接收到TCP数据：%s\n",flag+7);
		if(LED1_Open != NULL){
			LED_ON(LED1);
			LED1_Flag = 1;
			AT_Sent_TCP_Data("LED1:1");
		} 
		if(LED1_Close != NULL){
			LED_OFF(LED1);
			LED1_Flag = 0;
			AT_Sent_TCP_Data("LED1:0");
		} 
		if(LED2_Open != NULL){
			LED_ON(LED2);
			AT_Sent_TCP_Data("LED2:1");
		} 
		if(LED2_Close != NULL){
			LED_OFF(LED2);
			AT_Sent_TCP_Data("LED2:0");
		} 
		
		memset(receiveStr,'\0',1024);//初始化字符串

	}


}

// 关闭TCP连接
void AT_Close_TCP(void)
{
	Usart_SendString( DEBUG_USART2,"AT+CIPCLOSE\x0d\x0a");
}

//根据字符串来改变状态
// 每次发送AT指令后 为AT_STATUS_SEND  - 0
// 收到字符串中含有OK ，切换状态为 AT_STATUS_OK - 1
// 收到字符串中含有ERROR,FAIL,切换状态为 AT_STATUS_ERROR - 2
void AT_Status_Check(char *str)
{
	char *ok = strstr(str,"OK");
	char *error = strstr(str,"ERROR");
	char *fail = strstr(str,"FAIL");
	
	if(ok != NULL){
		AT_Status = AT_STATUS_OK;
	}
	else if(error != NULL || fail != NULL){
		AT_Status = AT_STATUS_ERROR;
	}
}

// 10秒内 等待状态变成AT_STATUS_OK或AT_STATUS_ERROR
//为AT_STATUS_OK 返回 0
//为AT_STATUS_ERROR 或超时返回 -1
int Wait_OK(void)
{
	int i = 0;
	while(i <= 10){	
		if ( time == 1000 ) /* 1000 * 1 ms = 1s 时间到 */
    {
			i ++;
      time = 0;
			AT_Status_Check(receiveStr);
			if(AT_Status == AT_STATUS_OK){
				return 0;
			}
			else if(AT_Status == AT_STATUS_ERROR){
				return -1;
			}
    }        
	}
	// 超时
	return -1;
}


