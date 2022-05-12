#ifndef SOCKET_CLIENT_H
#define SOCKET_CLIENT_H

#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <sys/un.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>


int createClientSocket(struct sockaddr_in **clientAddr);
int destroyClientSocket(int sockfd,struct sockaddr_in **ppclientAddr);

#endif
