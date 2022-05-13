#include "../../../inc/controller.h"

#include  "../../../inc/dictolpublic.h"
#include  "../../../inc/dictolprotocol.h"
#include  "../../../inc/ClientView.h"



int login(int socketfd){
	struct LoginData loginData;
	struct  DictOLPDU * pLoginSendPDU = NULL;
	struct  DictOLPDU * pLoginRecvPDU = NULL;
	int ret  = -1;
	int response = -1;

	getnameAndPasswdFromView(loginData.name,loginData.password);
	pLoginSendPDU = CreateLoginREQPDU(loginData.name, loginData.password);
	if(pLoginSendPDU == NULL){
		printf("CreateLoginREQPDU fail \n");
		return -1;
	}

	ret = SendPDU(socketfd,pLoginSendPDU);
	if(ret != 0){
		printf("pdu send fail\n");
		return -1;
	}

	printf("pdu send  \n");  //test

	DestroyDictOLPDU(pLoginSendPDU);
	
	pLoginRecvPDU = RecvPDU(socketfd);
	response = *(int *)(pLoginRecvPDU->buf);
	if(response != LOGIN_SUCCESS){
		return -1;
	}
	printf("%d", response);   //test
	printf("login success\n");
	return 0;
}




