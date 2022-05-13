#include "../../../inc/sqliteDrive.h"
#include <unistd.h>


int create_sqlite3(sqlite3 **ppsqlEngine){
	int ret = -1;
	ret = sqlite3_open(DB_FILE,ppsqlEngine);
	if(ret != SQLITE_OK)
	{
		printf("sqlite3_open failed:%s\n",sqlite3_errmsg(*ppsqlEngine));
		sqlite3_close(*ppsqlEngine);
		*ppsqlEngine = NULL;
		return 1;
	}
	return 0;
}


int init_database(sqlite3 *psqlengine){
	int ret = -1;
	int rows = 0;
	int cols = 0;
	char **ppret = NULL;
	char *perrmsg =NULL;
	char *sql;


	sql ="DROP TABLE IF EXISTS `user`; "\
		"CREATE TABLE IF NOT EXISTS `user`( "\
		"Id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, "\
		"name TEXT, "\
		"password TEXT, "\
		"loginStatus INTEGER "\
		"); "\
		"INSERT INTO `user` VALUES ('1', 'gao', '123','0'); "\
		"INSERT INTO `user` VALUES ('2', 'wang', '456','0'); "\
		""
		"DROP TABLE IF EXISTS `searchHistory`; "\
		"CREATE TABLE IF NOT EXISTS `searchHistory`( "\
		"Id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, "\
		"name TEXT, "\
		"searchWord TEXT, "\
		"time TEXT, "\
		"searchResult INTEGER "\
		"); "\
		"INSERT INTO `searchHistory` VALUES ('1', 'gao','abandon' ,'2022-0512-14','0') ";
	
	ret = sqlite3_get_table(psqlengine,sql,&ppret,&rows,&cols,&perrmsg);
	if(ret != SQLITE_OK)
	{
		printf("exec failed:%s\n",perrmsg);
		sqlite3_free(perrmsg);
		perrmsg = NULL;
		return -1;
	}
	else
	{
		printf("database init ok\n");
		sqlite3_free_table(ppret);
		ppret = NULL;
	}
	return 0;
}


int destory_sqlite3(sqlite3 **ppsqlEngine){
	sqlite3_close(*ppsqlEngine);
	*ppsqlEngine = NULL;
	return 0;
}


//safe mode do
int my_sqlite3_exec(sqlite3* pdb, const char *sql, sqlite3_callback callback, void*para, char** errmsg)
{
	int ret = 0;

	do
	{
		ret = sqlite3_exec( pdb , sql, callback , para , errmsg );

		if (ret == SQLITE_BUSY || ret == SQLITE_LOCKED)
		{
			usleep(30 * 1000);
			continue;
		}
		else
		{
			break;
		}
	} while(1);

	return ret;
}



int my_sqlite3_get_table(sqlite3 *db,const char *zSql,char ***pazResult,int *pnRow,int *pnColumn,char **pzErrmsg)
{
	int ret = 0;

	do
	{
		ret = sqlite3_get_table(db,zSql,pazResult,pnRow,pnColumn,pzErrmsg);

		if (ret == SQLITE_BUSY || ret == SQLITE_LOCKED)
		{
			usleep(30 * 1000);
			continue;
		}
		else
		{
			break;
		}
	} while(1);

	return ret;
}
