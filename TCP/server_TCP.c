#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<unistd.h>
int main()
{
     
	int server_soc,client_soc;
	char buffer[20];
	char msg[10];
	server_soc=socket(AF_INET,SOCK_STREAM,0);
		if(server_soc==-1)
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
		
		bind(server_soc,(struct sockaddr*)&server_address,sizeof(server_address));
		
		listen(server_soc,1);
		printf("socket listening..\n");	
			
		client_soc = accept(server_soc, NULL, NULL);
	     	printf("Client connected\n");
	while(1)
	{
		
		recv(client_soc,buffer,sizeof(buffer),0);
		printf("client says:%s\n",buffer);
		printf("entaer message:");
		scanf("%s",msg);
		send(client_soc,msg,strlen(msg)+1,0);
       }
	
	close(client_soc);
	close(server_soc);
	
}
