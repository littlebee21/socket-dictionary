#ifndef USER_DAO
#define USER_DAO


#include "../inc/sqliteDrive.h"
#include "stdio.h"


int get_User_password_by_name(sqlite3 *psql,char *pname,char *password);

#endif
