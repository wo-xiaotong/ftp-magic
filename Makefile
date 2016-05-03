CC=gcc
CFLAGS=-g 

ftp_magic : ftp_main.o connect_func.o log_manage.o ftp_func.o
	$(CC) $(CFLAGS) -o ftp_magic ftp_main.o connect_func.o log_manage.o ftp_func.o

ftp_func.o: ftp_func.c connect_func.h log_manage.h ftp_func.h
	$(CC) $(CFLAGS) -c ftp_func.c
connect_func.o: connect_func.c connect_func.h log_manage.h
	$(CC) $(CFLAGS) -c connect_func.c
log_manage.o: log_manage.c log_manage.h
	$(CC) $(CFLAGS) -c log_manage.c
ftp_main.o: ftp_main.c ftp_func.h
	$(CC) $(CFLAGS) -c ftp_main.c

clean:
	-rm ftp_magic ftp_main.o connect_func.o log_manage.o ftp_func.o

.PHONY:clean

