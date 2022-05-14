#include  "../../../inc/ServerController.h"

#include "../../../inc/dictolprotocol.h"
#include <string.h>
#include  "../../../inc/UserService.h"
#include  "../../../inc/WordService.h"


int HandleLogin(int fd,sqlite3 *pdb,struct DictOLPDU *recvpdu){
	struct LoginData *pLoginData = NULL;
	struct DictOLPDU *pSendPDU = NULL;
	int ret = -1;
	pLoginData = (struct LoginData *)(recvpdu->buf);

	//printf("recvpdu %s \n",pLoginData->name);  //test
	//printf("recvpdu %s \n",pLoginData->password);  //test

	//ret = strcmp(pLoginData->name,"gao");   //test
	//ret = strcmp(pLoginData->password,"123");   //test
	//printf("%d ret is \n",ret );  //test
	ret = login(pdb, pLoginData->name, pLoginData->password);
	if(ret != 0){
		printf("login failed");
		pSendPDU = CreateLoginRSPPDU(LOGIN_FAIL);
		SendPDU(fd,pSendPDU);
		DestroyDictOLPDU(pSendPDU);
		return -1;
	}
	printf("login success");
	pSendPDU = CreateLoginRSPPDU(LOGIN_SUCCESS);
	SendPDU(fd,pSendPDU);
	DestroyDictOLPDU(pSendPDU);
	return 0;
}

int HandleQueryWord(int fd,sqlite3 *pdb,struct DictOLPDU *recvpdu,char *username){
	struct DictOLPDU *pSendPDU = NULL;
	struct WordData *pWordData = NULL;
	struct ReturnWordData returnWordData;

	int ret = -1;
	pWordData = (struct WordData *)(recvpdu->buf);

	//is login todo 
	
	ret = searchByWord(pWordData->word,returnWordData.word);
	printf("%s $$$$$$$$$，func = %s, line = %d $$$$$$$$$$$ \n", returnWordData.word,__func__, __LINE__); //test
	printf("%d  \n",ret);
	if(ret != 0){
		printf("search fail");
		pSendPDU = CreateQueryWordRSPPDU("none");
		SendPDU(fd,pSendPDU);
		DestroyDictOLPDU(pSendPDU);
		return -1;
	}
	printf("search success\n");
	pSendPDU = CreateQueryWordRSPPDU(returnWordData.word);
	SendPDU(fd,pSendPDU);
	DestroyDictOLPDU(pSendPDU);
	return 0;
 }

