#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>
int main()
{
	int client_soc;
	client_soc=socket(AF_INET,SOCK_STREAM,0);
	if(client_soc!=-1)
	{
		printf("socket created\n");
	}
	else
	{
		printf("eror");
	}
	
	struct sockaddr_in server_address;
	server_address.sin_family=AF_INET;
	server_address.sin_port=htons(4000);
	server_address.sin_addr.s_addr=INADDR_ANY;
	
	//connecting
	connect(client_soc,(struct sockaddr*)&server_address,sizeof(server_address));
	printf("connected\n");
	
	//set up storage
	char buffer[30];
	char msg[30];
	//msg send
	printf("enter msg to be sent:");
	scanf("%s",msg);
	send(client_soc,msg,strlen(msg)+1,0);
	printf("msg sent\n");
	recv(client_soc,buffer,sizeof(buffer),0);
	printf("file contains:%s",buffer);
	
}
