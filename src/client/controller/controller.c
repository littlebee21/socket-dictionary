#include "../../../inc/controller.h"

#include  "../../../inc/dictolpublic.h"
#include  "../../../inc/dictolprotocol.h"
#include  "../../../inc/ClientView.h"


#include <string.h>



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


int wordSearch(int socketfd){
	struct WordData wordData;
	struct DictOLPDU * pWordSendPDU = NULL;
	struct DictOLPDU * pWordRecvPDU = NULL;
	int ret = -1;
	char buf[200] = "";

	getWordFromView(wordData.word);
	pWordSendPDU = CreateQueryWordREQPDU(wordData.word);
	if(pWordSendPDU == NULL){
		printf("CreateQueryWordREQPDU fail\n");
		return -1;
	}
	ret = SendPDU(socketfd,pWordSendPDU);
	if(ret != 0){
		printf("$$$$$$$$$，word send fail func = %s, line = %d $$$$$$$$$$$ \n", __func__, __LINE__); //test
	}
	pWordRecvPDU = RecvPDU(socketfd);
	strcpy(buf,pWordRecvPDU->buf);
	if(strcmp(buf,"none") == 0){
		printf("$$$$$$$$$，word search fail func = %s, line = %d $$$$$$$$$$$ \n", __func__, __LINE__); //test
		return -1;
	}
	printf("search success \n");
	printf("search result is %s \n",buf);
	return 0;
}

/*
struct DictOLPDU *CreateQueryWordREQPDU(char *word); 
int getWordFromView(char *word);

struct WordData{
	char word[WORD_LEN];
};

*/


