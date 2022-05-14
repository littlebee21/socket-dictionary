#ifndef SERVER_CONTROLLER
#define SERVER_CONTROLLER

#include "../inc/sqliteDrive.h"
#include "../inc/dictolpublic.h"
#include "../inc/dictolpublic.h"
#include "../inc/WordService.h"


//int HandleReg(int fd,sqlite3 *pdb,struct DictOLPDU *recvpdu);    
int HandleLogin(int fd,sqlite3 *pdb,struct DictOLPDU *recvpdu);
int HandleQueryWord(int fd,sqlite3 *pdb,struct DictOLPDU *recvpdu,char *username);
//int HandleQueryHistory(int fd,sqlite3 *pdb,struct DictOLPDU *recvpdu,char *username);


#endif
