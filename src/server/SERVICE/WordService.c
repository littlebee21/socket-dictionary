#include "../../../inc/WordService.h"

#include <string.h>
#include <errno.h>



int searchByWord(char *word,char *returnWord){
	FILE *fp = NULL;
	char *pline = NULL;
	char *p = NULL;
	int len;
	int result;

    len = strlen(word);
    if ((fp = fopen("/mnt/f/codehub/tempcode/dictol_src_dir_ve/dictol_src_dir/src/server/dict.txt", "r")) == NULL)
    {
		printf("fopen dict.txt failed, errno = %d reson =%s \n",errno,strerror(errno));
		return -1;
    }

    printf("query word is %s\n",word);
	pline = MyReadLineFromTxt(fp,NULL);
	printf("$$$$$$$$$，pline get $$$$$$$ func = %s, line = %d $$$$$$$$$$$ \n", __func__, __LINE__); //test
    while (pline != NULL)
    {
        result = strncmp(word, pline, len);
        if (result > 0) 
		{
			free(pline);
			pline = NULL;
			pline = MyReadLineFromTxt(fp,NULL);
			continue;
		}

        if (result < 0 || pline[len] != ' ') 
		{
			free(pline);
			pline = NULL;
			break;
		}
		else
		{
			break;
		}
    }
    fclose(fp);
	fp = NULL;
	printf("$$$$$$$$$ fp close $$$$$$ ，func = %s, line = %d $$$$$$$$$$$ \n", __func__, __LINE__); //test

	if(pline != NULL)
	{
		p = pline + len;
		while(*p == ' ')
		{
			p++;
		}
	}
	printf("return returnWord is %s \n",p);  //test
	if(p != NULL)
	{
		strcpy(returnWord,p);
		printf("return returnWord is %s \n",returnWord);  //test
		free(pline);
		pline = NULL;
		p = NULL;
	}
	return 0;
}

