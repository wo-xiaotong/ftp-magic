#include<stdio.h>
#include "ftp_func.h"

int control_fd;
int data_fd;

#define IP "127.0.0.1"
#define C_PORT 21

int main(int argc,const char* argv[])
{

	control_fd=ftp_login(IP,C_PORT,"ftpuser","ftptest");
	print_working_dir(control_fd);

/*	int data_port=goto_PASV(control_fd);
	data_fd=connect_data(IP,data_port);
	close_data(data_fd);

	
	print_sysinfo(control_fd);
	logout_ftp(control_fd);


	ftp_mkdir(control_fd,"hello");
	ftp_cwd(control_fd,"hello");
	ftp_cwd(control_fd,"he2dfsdllo");
	ftp_cdup(control_fd,"hello");
	ftp_cdup(control_fd,"hecscllo");
	*/
	
	ftp_noop(control_fd);
	return 0;
}

