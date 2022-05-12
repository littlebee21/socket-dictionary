#include <stdio.h>

#include "../../inc/dictolprotocol.h"
#include "../../inc/dictolpublic.h"


#include  "../../inc/serverSocket.h"
#include   "../../inc/UserService.h"
#include  "../../inc/sqliteDrive.h"



//define
int mainloop(int sockfd, sqlite3 *psqlEngine);



int main(int argc,char *argv[])
{
	//create
	int ret = -1;
	int sockfd = -1;
	struct sockaddr_in *servaddr;
	sqlite3 *psqlEngine = NULL;

	//init
	sockfd = createServerSocket(&servaddr);
	if(sockfd == -1){
		printf("server sockfd dont create");
		printf("sockf is %d",sockfd);
		return -1;
	}
	ret = create_sqlite3(&psqlEngine);
	if(ret != 0){
		printf("sqlite3 create fail");
		return -1;
	}
	init_database(psqlEngine);



	//loop
	mainloop(sockfd,psqlEngine);

	//end
	destory_sqlite3(&psqlEngine);
	destroyServerSocket(sockfd,&servaddr);
	return 0;
}

int mainloop(int sockfd, sqlite3 *psqlEngine){
	int datafd = -1;
	char receviveBuf[20] = "";
	int ret = -1;

	//test
	ret = login(psqlEngine, "gao", "123");
	if(ret == 0){
		printf("test success");
	}


	while(1){
		datafd = createServerSocketData(sockfd);

		MyRead(datafd,(void *)receviveBuf,sizeof(receviveBuf));
		printf("client  say to me: %s \n",receviveBuf);

		MyWrite(datafd,(void *)receviveBuf,sizeof(receviveBuf));

		destroyServerSocketData(datafd);
	}
	return 0;
}

