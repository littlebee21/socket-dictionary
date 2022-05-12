#include "../../../inc/UserDao.h"

int get_User_password_by_name(sqlite3 *psqlengine,char *pname,char *password){
	int ret = -1;
	int rows = 0;
	int cols = 0;
	char **ppret = NULL;
	char sqlstr[80] = "";
	char *perrmsg =NULL;

	//sprintf(sqlstr,"SELECT password FROM user WHERE name=\"%s\";",pname);
	sprintf(sqlstr,"SELECT * FROM user;");

	ret = sqlite3_get_table(psqlengine,sqlstr,&ppret,&rows,&cols,&perrmsg);
	if(ret != SQLITE_OK)
	{
		printf("exec %s failed:%s\n",sqlstr,perrmsg);
		sqlite3_free(perrmsg);
		perrmsg = NULL;
		return -1;
	}
	else
	{
		int i = 0;
		int j = 0;

		printf("rows=%d,cols=%d\n",rows,cols);

		for(j = 0;j < cols;j++)
		{
			printf("%-12s",*(ppret+j));
		}
		printf("\n");

		for(i = 1;i <= rows;i++)
		{
			for(j = 0;j < cols;j++)
			{
				printf("%-12s",*(ppret + i * cols + j));
			}
			printf("\n");
		}
		sqlite3_free_table(ppret);
		ppret = NULL;
	}
	return 0;
}
