#ifndef __ESP8266_H
#define	__ESP8266_H

#define 	AT_STATUS_SEND 								0
#define 	AT_STATUS_OK 									1
#define 	AT_STATUS_ERROR 							2

#define 	AT_MODE_STATION								1
#define 	AT_MODE_AP										2
#define 	AT_MODE_STATION_AP						3

int AT_Test(void);
int AT_Mode_Set(int mode);
int AT_connectWIFI(char *ssid,char *password);
int AT_connectTCP(char *ip,int port);
void AT_Sent_TCP_Data(char *str);
void AT_Status_Check(char *str);
int Wait_OK(void);
void AT_TCP_Receive(void);
#endif /* __ESP8266_H */
