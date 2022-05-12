#ifndef USER_SERVICE_H
#define USER_SERVICE_H

#include "../inc/UserDao.h"

int login(sqlite3 *psql, char *pname, char *ppassword);


#endif
