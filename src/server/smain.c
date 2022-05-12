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
	struct sockaddr_un *servaddr;

	//init
	sockfd = createServerSocket(&servaddr);


	mainloop(sockfd);

	//end
	destroyServerSocket(sockfd,&servaddr);
	return 0;
}

int mainloop(int sockfd){
	int datafd = -1;
	char buf[8] = "";
	while(1){
		datafd = createServerSocketData(sockfd);
		read(datafd,buf,8);

		printf("Client say to me:%s\n",buf);

		write(datafd,buf,strlen(buf) + 1);

		destroyServerSocketData(datafd);
	}
	return 0;
}

