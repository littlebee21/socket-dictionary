#include "../../inc/ClientSocket.h"
#include  "../../inc/dictolpublic.h"
#include "../../inc/dictolprotocol.h"
#include "../../inc/ClientView.h"
#include "../../inc/controller.h"


int createClientSocket(struct sockaddr_in **clientAddr);
int destroyClientSocket(int sockfd,struct sockaddr_in **ppclientAddr);


int main(int argc,char *argv[])
{
	int sockfd = -1;
	struct sockaddr_in *clientAddr;
	int op = 0;
	int exitflag = 0;


	sockfd = createClientSocket(&clientAddr);
	while(1){
		op = display_main_ui();
		switch(op)
        {
            case 1: 
                break;
            case 2:
				login(sockfd);
                break;
            case 3:
				wordSearch(sockfd);
                break;
            case 4:
                break;
            case 0:
                exitflag = 1;
                break;
        }
        if(exitflag)
        {
            break;
        }
	}

	close(sockfd);
	sockfd = -1;

	destroyClientSocket(sockfd,&clientAddr);
	return 0;
}




