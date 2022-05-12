#include "../../inc/ClientSocket.h"


int createClientSocket(struct sockaddr_in **clientAddr);
int destroyClientSocket(int sockfd,struct sockaddr_in **ppclientAddr);


int main(int argc,char *argv[])
{
	int sockfd = -1;
	struct sockaddr_in *clientAddr;
	char buf[8] = "";

	sockfd = createClientSocket(&clientAddr);



	write(sockfd,"hello",6);

	read(sockfd,buf,8);

	printf("Server say to me:%s\n",buf);

	close(sockfd);
	sockfd = -1;

	destroyClientSocket(sockfd,&clientAddr);
	return 0;
}



