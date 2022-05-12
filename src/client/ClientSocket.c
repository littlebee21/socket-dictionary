#include "../../inc/ClientSocket.h"


int createClientSocket(struct sockaddr_in **ppclientAddr){
	int sockfd = -1;
	int ret = -1;
	*ppclientAddr = (struct sockaddr_in *)malloc(sizeof(struct sockaddr_in));

	sockfd = socket(AF_INET,SOCK_STREAM,0);	

	bzero(*ppclientAddr,sizeof(**ppclientAddr));
	(*ppclientAddr)->sin_family = AF_INET;
	(*ppclientAddr)->sin_port = htons(3456);
	inet_aton("127.0.0.1",&((*ppclientAddr)->sin_addr));

	ret = connect(sockfd,(struct sockaddr *)(*ppclientAddr),sizeof(**ppclientAddr));
	if(ret < 0)
	{
		close(sockfd);
		sockfd = -1;
		free(*ppclientAddr);
		*ppclientAddr = NULL;
		perror("connect server failed:");
		return 1;
	}
	return sockfd;
}


int destroyClientSocket(int sockfd,struct sockaddr_in **ppclientAddr){
	free(*ppclientAddr);
	*ppclientAddr = NULL;
	close(sockfd);
	sockfd = -1;
	return 0;
}
