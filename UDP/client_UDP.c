#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
int main()
{
	int server_soc;
	char buffer[20],msg[20];
	int client_soc;
	client_soc=socket(AF_INET,SOCK_DGRAM,0);
	if(client_soc==-1)
	{
		printf("error");
	}
	else
	{
		printf("socket created.\n");
	}
	//initialization
	struct sockaddr_in server_address;
	struct sockaddr_in client_address;
	server_address.sin_family=AF_INET;
	server_address.sin_port=htons(4000);
	server_address.sin_addr.s_addr=INADDR_ANY;
	bind(server_soc,(struct sockaddr*)&server_address,sizeof(server_address));
	printf("bind ok..\n");
	
	//sending message to client
	socklen_t server_len = sizeof(server_address);
	printf("enetr msg to be sent:");
	scanf("%s",msg);
	sendto(client_soc,msg,strlen(msg)+1,0,(struct sockaddr*)&server_address,server_len);
	printf("msg sent\n");
	//receving message from client
	recvfrom(client_soc,buffer,sizeof(buffer),0,(struct sockaddr*)&server_address,&server_len);
	printf("server  says:%s\n",buffer);
	//closing
	close(client_soc);
}
