#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<unistd.h>
int main()
{
	int server_soc,client_soc;
		char buffer[20];
		char msg[20];
	//creating socket
	client_soc=socket(AF_INET,SOCK_STREAM,0);
		if(client_soc==-1)
		{
			printf("error");
		}
		else
		{
			printf("created\n");
		}
		struct sockaddr_in server_address;
		server_address.sin_family=AF_INET;
		server_address.sin_port=htons(4000);
		server_address.sin_addr.s_addr=INADDR_ANY;
		connect(client_soc,(struct sockaddr*)&server_address,sizeof(server_address));
		printf("client connected to server\n");
	while(1)
	{
		
		printf("enter message:");
		scanf("%s",msg);
		send(client_soc,msg,strlen(msg)+1,0);
		recv(client_soc,buffer,sizeof(buffer),0);
		printf("sever says:%s\n",buffer);
        }
	
	
	close(client_soc);
	
	
}
