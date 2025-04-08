#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>
int main()
{
	int server_soc,client_soc;
	FILE *fp1;
	server_soc=socket(AF_INET,SOCK_STREAM,0);
	if(server_soc!=-1)
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
	
	//binding
	bind(server_soc,(struct sockaddr*)&server_address,sizeof(server_address));
	printf("bind done\n");
	//listen
	listen(server_soc,0);
	//accept
	client_soc=accept(server_soc,NULL,NULL);
	//set up storage
	char buffer[30];
	char msg[30];
	//msg receive
	recv(client_soc,buffer,sizeof(buffer),0);
	fp1=fopen("h.txt","w");
	fputs(buffer,fp1);
	//sending msg
	fclose(fp1);
	
	
	
	
}
