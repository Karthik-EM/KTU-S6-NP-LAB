#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
int main()
{
	int server_soc;
	char buffer[20],msg[20];
	server_soc=socket(AF_INET,SOCK_DGRAM,0);
	if(server_soc==-1)
	{
		printf("error");
	}
	else
	{
		printf("socket created.\n");
	}
	
	struct sockaddr_in server_address;
	struct sockaddr_in client_address;
	server_address.sin_family=AF_INET;
	server_address.sin_port=htons(4000);
	server_address.sin_addr.s_addr=INADDR_ANY;
	bind(server_soc,(struct sockaddr*)&server_address,sizeof(server_address));
	printf("bind ok..\n");
	//receving message from client
	socklen_t client_len = sizeof(client_address);
	recvfrom(server_soc,buffer,sizeof(buffer),0,(struct sockaddr*)&client_address,&client_len);
	printf("client says:%s\n",buffer);
	//sending message to client
	printf("enetr msg to be sent:");
	scanf("%s",msg);
	sendto(server_soc,msg,strlen(msg)+1,0,(struct sockaddr*)&client_address,client_len);
	printf("msg sent\n");
}
