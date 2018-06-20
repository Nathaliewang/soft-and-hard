#include "bsp_usart.h"
#include "ESP8266.h"
#include "bsp_GENERALTim.h" 
#include "Hal_led.h"
extern volatile uint32_t time; // ms ��ʱ���� 
extern int LED1_Flag;
#include <stdio.h>	
#include <string.h>

int AT_Status;
char receiveStr[1024];
//��ESP8266�������� ���ڷ� ���ڶ� ��������
//\x0d\x0a �ǻس�����
//�������гɹ�����0��ʧ�ܷ��ظ�ֵ

void AT_Sent_init(void)
{
	memset(receiveStr,'\0',1024);//��ʼ���ַ���
	AT_Status = AT_STATUS_SEND;
}

//����AT
int AT_Test(void)
{
	AT_Sent_init();
	Usart_SendString( DEBUG_USART2,"AT\x0d\x0a");
	if(Wait_OK()){
		printf("AT ����ʧ������Ӳ������\n");
		return -1;
	}
	else{
		printf("AT ���Գɹ�\n");
		return 0;
	}

}

//���ö�Ӧ��ģʽ��AT�̼�1.6�汾��Ӧֵ����
//1- AT_MODE_STATION	- stationģʽ�����������ô�ģʽ����������WIFI��
//2- AT_MODE_AP - APģʽ
//3- AT_MODE_STATION_AP - ���ģʽ
int AT_Mode_Set(int mode)
{
	char sentStr[32];
	AT_Sent_init();
	sprintf(sentStr,"AT+CWMODE=%1d\x0d\x0a",mode);
	Usart_SendString( DEBUG_USART2,sentStr);
	if(Wait_OK()){
		printf("AT ����ģʽʧ��\n");
		return -1;
	}
	else{
		printf("AT ����ģʽ�ɹ�\n");
		return 0;
	}
}

// ����WIFI
int AT_connectWIFI(char *ssid,char *password)
{
	char sentStr[128];
	AT_Sent_init();
	sprintf(sentStr,"AT+CWJAP=\"%s\",\"%s\"\x0d\x0a",ssid,password);
	Usart_SendString(DEBUG_USART2,sentStr);
	if(Wait_OK()){
		printf("AT ����WIFIʧ��\n");
		return -1;
	}
	else{
		printf("AT ����WIFI�ɹ�\n");
		return 0;
	}
}

// ����TCP
int AT_connectTCP(char *ip,int port)
{
	char sentStr[64];
	AT_Sent_init();
	sprintf(sentStr,"AT+CIPSTART=\"TCP\",\"%s\",%d\x0d\x0a",ip,port);
	Usart_SendString( DEBUG_USART2,sentStr);
	if(Wait_OK()){
		printf("AT ����TCPʧ��\n");
		return -1;
	}
	else{
		printf("AT ����TCP�ɹ�\n");
		return 0;
	}
}

// ����TCP����
void AT_Sent_TCP_Data(char *str)
{
	char sentStr[32];
	AT_Sent_init();
	sprintf(sentStr,"AT+CIPSEND=%d\x0d\x0a",strlen(str));
	Usart_SendString(DEBUG_USART2,sentStr);
	if(Wait_OK()){
		printf("AT ����TCP����ʧ��\n");
	}
	else{
		Usart_SendString(DEBUG_USART2,str);
	}
}

// ���TCP��û�д�������
void AT_TCP_Receive(void)
{
	char *flag = strstr(receiveStr,"+IPD,");
	char *LED1_Open = strstr(receiveStr,"LED1:1");
	char *LED1_Close = strstr(receiveStr,"LED1:0");
	char *LED2_Open = strstr(receiveStr,"LED2:1");
	char *LED2_Close = strstr(receiveStr,"LED2:0");
	if(flag != NULL){
		//+IPD,7:LED2:1    ����ƫ��7���ֽڸպõõ���������
		printf("���յ�TCP���ݣ�%s\n",flag+7);
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
		
		memset(receiveStr,'\0',1024);//��ʼ���ַ���

	}


}

// �ر�TCP����
void AT_Close_TCP(void)
{
	Usart_SendString( DEBUG_USART2,"AT+CIPCLOSE\x0d\x0a");
}

//�����ַ������ı�״̬
// ÿ�η���ATָ��� ΪAT_STATUS_SEND  - 0
// �յ��ַ����к���OK ���л�״̬Ϊ AT_STATUS_OK - 1
// �յ��ַ����к���ERROR,FAIL,�л�״̬Ϊ AT_STATUS_ERROR - 2
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

// 10���� �ȴ�״̬���AT_STATUS_OK��AT_STATUS_ERROR
//ΪAT_STATUS_OK ���� 0
//ΪAT_STATUS_ERROR ��ʱ���� -1
int Wait_OK(void)
{
	int i = 0;
	while(i <= 10){	
		if ( time == 1000 ) /* 1000 * 1 ms = 1s ʱ�䵽 */
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
	// ��ʱ
	return -1;
}


