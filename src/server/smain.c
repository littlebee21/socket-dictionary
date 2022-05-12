#include <stdio.h>

#include "../../inc/dictolprotocol.h"
#include "../../inc/dictolpublic.h"


#include  "../../inc/serverSocket.h"


//define
int mainloop(int sockfd);



int main(int argc,char *argv[])
{
	//create
	int sockfd = -1;
	struct sockaddr_in *servaddr;

	//init
	sockfd = createServerSocket(&servaddr);
	if(sockfd == -1){
		printf("server sockfd dont create");
		printf("sockf is %d",sockfd);
		return -1;
	}

	mainloop(sockfd);

	//end
	destroyServerSocket(sockfd,&servaddr);
	return 0;
}

int mainloop(int sockfd){
	int datafd = -1;
	char receviveBuf[20] = "";
	while(1){
		datafd = createServerSocketData(sockfd);
		/*
		read(datafd,buf,8);

		printf("Client say to me:%s\n",buf);

		write(datafd,buf,strlen(buf) + 1);
		*/

		MyRead(datafd,(void *)receviveBuf,sizeof(receviveBuf));
		printf("client  say to me: %s \n",receviveBuf);

		MyWrite(datafd,(void *)receviveBuf,sizeof(receviveBuf));

		destroyServerSocketData(datafd);
	}
	return 0;
}

