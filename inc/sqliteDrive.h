#ifndef  SQLITE_DRIVE
#define  SQLITE_DRIVE


#include <unistd.h>
#include <stdio.h>
#include <sqlite3.h>


#define DB_FILE "dic.db"


int create_sqlite3(sqlite3 **ppsqlEngine);
int destory_sqlite3(sqlite3 **ppsqlEngine);


int init_database(sqlite3 *psqlengine);

int my_sqlite3_get_table(sqlite3 *db,const char *zSql,char ***pazResult,int *pnRow,int *pnColumn,char **pzErrmsg);
int my_sqlite3_exec(sqlite3* pdb, const char *sql, sqlite3_callback callback, void*para, char** errmsg);

#endif
