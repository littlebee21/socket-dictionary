#include "../../../inc/ClientView.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *mygets(char *pout,int size)
{
	char *p = NULL;
	fgets(pout,size,stdin);
	p = pout + strlen(pout) - 1;

	if(*p == '\n')
	{
		*p = '\0';
	}
	else
	{
		while(getchar() != '\n')
		{
		}
	}
	return pout;
}


int display_main_ui(){
	int op = -1;
	printf("\n");
    printf("Please select your operation:\n");
    printf("1. register\n");
    printf("2. login\n");
    printf("3. query word\n");
    printf("4. query history\n");
    printf("0. Exit\n");
    scanf("%d",&op);

    while(getchar()!='\n')
    {
    }
	printf("op get\n");
    return op;
}

struct LoginData{
	char name[30];
	char password[30];
};

int getnameAndPasswdFromView(char *name,char * password){
	printf("Please input your name:\n");
	strcpy(name,"gao");
	printf("PLease input your password\n");
	strcpy(password,"123");
	printf("name password get\n");
	return 0;
}


int getWordFromView(char *word){
	printf("Please input your word:\n");
	scanf("%s",word);

	while(getchar()!='\n')
	{        
	}
	return 0;
}


int getnameFromView(char *name){
	printf("Please input your word:\n");
	scanf("%s",name);

	while(getchar()!='\n')
	{        
	}
	return 0;
}
