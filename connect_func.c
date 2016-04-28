#include<netinet/in.h>
#include "connect_func.h"


int init_socket(const char* ip,const int port)
{
	struct sockaddr_in serv_addr;
	int sockfd=socket(AF_INET,SOCK_STREAM,0);
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_addr.s_addr=inet_addr(ip);
	serv_addr.sin_port=htons(port);

	int ret=connect(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
	if(ret==-1){
		perror("connect failed\n");
		return -1;
	}
	
	return sockfd;
}

int close_socket(int socket_fd)
{
	return close(socket_fd);
}

