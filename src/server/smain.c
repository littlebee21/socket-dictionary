#include <stdio.h>

#include "../../inc/dictolprotocol.h"
#include "../../inc/dictolpublic.h"


#include  "../../inc/serverSocket.h"
#include   "../../inc/UserService.h"
#include  "../../inc/sqliteDrive.h"
#include   "../../inc/dictolprotocol.h"
#include   "../../inc/ServerController.h"




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

	//test
	if(0){
		ret = login(psqlEngine, "gao", "123");
		if(ret == 0){
			printf("test success");
		}
	}

	//loop
	mainloop(sockfd,psqlEngine);

	//end
	destory_sqlite3(&psqlEngine);
	destroyServerSocket(sockfd,&servaddr);
	return 0;
}



int mainloop(int sockfd, sqlite3 *psqlEngine){
	int datafd = -1;
	struct DictOLPDU * pRecPDU = NULL;
	


	while(1){
		datafd = createServerSocketData(sockfd);
		//printf("nothing wait \n");  //test
		pRecPDU = RecvPDU(datafd);
		//printf("pRecPDU rece size is %d \n",pRecPDU->size);  //test

		switch(pRecPDU->type)
		{
			case DICTOL_PDU_TYPE_REG_REQ:
				break;
			case DICTOL_PDU_TYPE_LOGIN_REQ:
				//printf("case login \n");  //test
				HandleLogin(datafd,psqlEngine,pRecPDU);
				break;
			case DICTOL_PDU_TYPE_QUERYWORD_REQ:
				HandleQueryWord(datafd,psqlEngine,pRecPDU,"gao");   //is login todo
				break;
			case DICTOL_PDU_TYPE_HISTORY_REQ:
				break;
			default:
				DestroyDictOLPDU(pRecPDU);
				break;
		}
		destroyServerSocketData(datafd);
	}
	return 0;
}

