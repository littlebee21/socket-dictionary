#include  "../../../inc/ServerController.h"

#include "../../../inc/dictolprotocol.h"
#include <string.h>

int HandleLogin(int fd,sqlite3 *pdb,struct DictOLPDU *recvpdu){
	struct LoginData *pLoginData = NULL;
	struct DictOLPDU *pSendPDU = NULL;
	int ret = -1;
	pLoginData = (struct LoginData *)(recvpdu->buf);

	printf("recvpdu %s \n",pLoginData->name);  //test
	printf("recvpdu %s \n",pLoginData->password);  //test

	ret = strcmp(pLoginData->name,"gao");
	ret = strcmp(pLoginData->password,"123");
	printf("%d ret is \n",ret );  //test
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


