#include "../../../inc/UserService.h"
#include "string.h"


/*
int is_login(sqlites *psql, char *pname){
	get_User_password_by_name()
}
*/


int login(sqlite3 *psql, char *pname, char *ppassword){
	int ret = 0;
	char realPassword[30] = "";
	ret = get_User_password_by_name(psql,pname,realPassword);
	if(ret != 0){
		printf("get ppassword fail ");
		return -1;
	}
	ret = strcmp(ppassword,realPassword);
	if(ret != 0){
		printf("ppassword is not righrt");
		return -1;
	}
	printf("%s login in success",pname);
	return 0;
}



