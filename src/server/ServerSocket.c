#include "../../inc/serverSocket.h"
//sockfd
int createServerSocket(struct sockaddr_un **servaddr){
	int sockfd = -1;
	int ret = -1;
	struct sockaddr_un *pservaddr = *servaddr;
	*servaddr = (struct sockaddr_un *)malloc(sizeof(struct sockaddr_un));
	

	sockfd = socket(AF_UNIX,SOCK_STREAM,0);

	bzero(servaddr,sizeof(*servaddr));
	pservaddr->sun_family = AF_UNIX;
	strcpy(pservaddr->sun_path,"/tmp/myxyz");   ////gao2022-0511-21

	ret = bind(sockfd,(struct sockaddr *)pservaddr,sizeof(*pservaddr));
	ret += listen(sockfd,6);
	if(ret < 0)
	{
		close(sockfd);
		sockfd = -1;
		free(pservaddr);
		pservaddr = NULL;
		perror("bind or listen failed:");
		return 1;
	}
	return sockfd;
}

//sockfd
int destroyServerSocket(int sockfd,struct sockaddr_un **servaddr){
	free(*servaddr);
	*servaddr = NULL;
	close(sockfd);
	sockfd = -1;
	return 0;
}


//datafd 
int createServerSocketData(int sockfd){
	int datafd = -1;
	while(1){
		datafd = accept(sockfd,NULL,NULL);
		if(datafd < 0)
		{
			if(errno == EINTR)
			{
				continue;
			}
			else
			{
				perror("accept failed:");
				return -1;
				break;
			}
		}
		break;
	}
	return datafd;
}

//datafd
int destroyServerSocketData(int datafd){
	close(datafd);
	datafd = -1;
	return 0;
}



