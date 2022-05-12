#ifndef SOCKET_SERVER_H
#define SOCKET_SERVER_H

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <arpa/inet.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>

int createServerSocketData(int sockfd);
int destroyServerSocketData(int datafd);


int createServerSocket(struct sockaddr_un **servaddr);
int destroyServerSocket(int sockfd,struct sockaddr_un **servaddr);





#endif
