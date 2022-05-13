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
	/*
	printf("loginData is %s \n",loginData.name);  //test
	printf("loginData is %s \n",loginData.password);  //test
	*/

	pLoginSendPDU = CreateLoginREQPDU(loginData.name,loginData.password);
	/*
	printf("in PDU \n");
	printf("pdu size %ld \n",sizeof(*(pLoginSendPDU->buf)));  //test
	printf("pdu send %s \n",((struct LoginData *)(pLoginSendPDU->buf))->name);  //test
	printf("pdu send %s \n",((struct LoginData *)(pLoginSendPDU->buf))->password);  //test
	printf("pdu send %d \n",pLoginSendPDU->type);  //test
	printf("pdu send %d \n",pLoginSendPDU->size);  //test
	*/
	if(pLoginSendPDU == NULL){
		printf("CreateLoginREQPDU fail \n");
		return -1;
	}

	ret = SendPDU(socketfd,pLoginSendPDU);
	if(ret != 0){
		printf("pdu send fail\n");
		return -1;
	}

	//printf("pdu send  \n");  //test
	DestroyDictOLPDU(pLoginSendPDU);
	
	pLoginRecvPDU = RecvPDU(socketfd);
	response = *(int *)(pLoginRecvPDU->buf);
	if(response != LOGIN_SUCCESS){
		printf("%d login fail", response);   //test
		return -1;
	}
	printf("%d login success", response);   //test
	return 0;
}




