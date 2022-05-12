#include "../../inc/ClientSocket.h"
#include  "../../inc/dictolpublic.h"


int createClientSocket(struct sockaddr_in **clientAddr);
int destroyClientSocket(int sockfd,struct sockaddr_in **ppclientAddr);


int main(int argc,char *argv[])
{
	int sockfd = -1;
	struct sockaddr_in *clientAddr;
	char sendBuf[20] = "in hao";
	char receviveBuf[20] = "";
	int ret = -1;

	sockfd = createClientSocket(&clientAddr);


/*
	write(sockfd,"hello",6);

	read(sockfd,buf,8);

	printf("Server say to me:%s\n",buf);
*/
	ret = MyWrite(sockfd,(void *)sendBuf,sizeof(sendBuf));
	if(ret <= 0){
		printf("client write fail \n");
		return -1;
	}

	MyRead(sockfd,(void *)receviveBuf,sizeof(receviveBuf));
	printf("Sever say to me: %s \n",receviveBuf);

	close(sockfd);
	sockfd = -1;

	destroyClientSocket(sockfd,&clientAddr);
	return 0;
}




