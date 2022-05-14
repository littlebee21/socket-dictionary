#ifndef USER_DAO
#define USER_DAO


#include "../inc/sqliteDrive.h"
#include "stdio.h"


int get_User_realpassword_by_name(sqlite3 *psqlengine,char *pname,char *realpassword);

#endif
