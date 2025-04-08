#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>
int main()
{
  
	int client_soc;
	client_soc=socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in server_address;
	struct sockaddr_in client_address;
	server_address.sin_family=AF_INET;
	server_address.sin_port=htons(4000);
	server_address.sin_addr.s_addr=INADDR_ANY;
	//binding
	connect(client_soc,(struct sockaddr*)&server_address,sizeof(server_address));
	printf("connected\n");
	//send file name
	char msg[20];
	printf("enter file:");
	scanf("%s",msg);
	send(client_soc,msg,strlen(msg)+1,0);
	//recevie file
	char buffer[20];
	recv(client_soc,buffer,sizeof(buffer),0);
	printf("file contains:%s",buffer);
	close(client_soc);
	
	
	
}
