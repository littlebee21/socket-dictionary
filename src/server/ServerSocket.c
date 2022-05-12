#include "../../inc/serverSocket.h"
//sockfd
int createServerSocket(struct sockaddr_in **ppservaddr){
	int sockfd = -1;
	int ret = -1;
	*ppservaddr = (struct sockaddr_in *)malloc(sizeof(struct sockaddr_in));
	
	sockfd = socket(AF_INET,SOCK_STREAM,0);

	bzero(*ppservaddr,sizeof(**ppservaddr));
	(*ppservaddr)->sin_family = AF_INET;
	(*ppservaddr)->sin_port = htons(3456);
	inet_aton("127.0.0.1",&(*ppservaddr)->sin_addr);

	ret = bind(sockfd,(struct sockaddr *)(*ppservaddr),sizeof(**ppservaddr));
	ret += listen(sockfd,6);
	if(ret < 0)
	{
		close(sockfd);
		sockfd = -1;
		free(*ppservaddr);
		*ppservaddr = NULL;
		perror("bind or listen failed:");
		return 1;
	}
	return sockfd;
}

//sockfd
int destroyServerSocket(int sockfd,struct sockaddr_in **servaddr){
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



