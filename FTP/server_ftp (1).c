//BEFORE USEING THE PROGRAM CREATE A FILE WHICH YOU NEED TO SEND IN THE SAME FOLDER AS IN CLIENT AND SERVER 
//ALSO IF THE FILE IS NOT PRESENT IT WOULD NO HANDLE SUCH CASE.THE PROGRAM IS IMPLEMENTED IN A SIMPLE WAY WITH MINIMAL ERROR CHECKING
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>
int main()
{
  
	int server_soc,client_soc;
	FILE *fp;
	server_soc=socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in server_address;
	server_address.sin_family=AF_INET;
	server_address.sin_port=htons(4000);
	server_address.sin_addr.s_addr=INADDR_ANY;
	//binding
	bind(server_soc,(struct sockaddr*)&server_address,sizeof(server_address));
	printf("bind ok\n");
	//listen
	listen(server_soc,1);
	printf("listening\n");
	//accept
	client_soc=accept(server_soc,NULL,NULL);
	printf("accepted\n");
	//recv msg
	char buffer[20];
	recv(client_soc,buffer,sizeof(buffer),0);
	//open file
	fp=fopen(buffer,"r");
	printf("client need contents of %s\n",buffer);
	//sending file
	char msg[20];
        fgets(msg,sizeof(msg),fp);
        send(client_soc,msg,strlen(msg)+1,0);
	printf("msg sent");
	fclose(fp);
	//closing
	close(client_soc);
	close(server_soc);
}
