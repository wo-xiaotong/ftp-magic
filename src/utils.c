#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int remove_reply_code(char* reply)
{
	int n=strlen(reply);
	if(n<4)return -1;
	int ret=atoi(reply);

	//remove \r\n
	if(n>=2 && reply[n-1]=='\n' && reply[n-2]=='\r'){
		reply[n-2]='\0';
		n=strlen(reply);
	}

	//remove reply code and space 
	for(int i=4;i<=n;++i){	
		reply[i-4]=reply[i];
	}

	return ret;
}

int split_list_info(char* reply)
{
	char *cp=strtok(reply,"\r\n");
	while(cp!=NULL){
		printf("%s\n",cp);
		cp=strtok(NULL,"\r\n");
	}

	return 0;
}

int get_pasv_port(char* reply)
{
	char* p=strtok(reply," ,.()");
	int cnt=7;
	while (cnt-- && p!=NULL){
		p=strtok (NULL," ,.()");
	}
	char* p1=strtok(NULL," ,.()");
	char* p2=strtok(NULL," ,.()");

	return atoi(p1)*256+atoi(p2);
}

int compare_reply_code(char * read_buf,const char* reply_code)
{
	if(strlen(read_buf)<3 || strlen(reply_code)<3){
		return -1;
	}

	return strncmp(read_buf,reply_code,3);
}

int get_reply_code(char* reply)
{
	if(strlen(reply)<3){
		return -1;
	}

	return atoi(reply);
}

void remove_space(char* para)
{
	int len=strlen(para);
	int not_space=0;
	for(;para[not_space]==' ' && not_space<len;++not_space);
	
	for(int i=0;not_space<len+1;){
		para[i++]=para[not_space++];
	}
}
