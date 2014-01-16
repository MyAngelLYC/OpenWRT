#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <time.h>
int main(int argc,char** argv)
{
	/*
	FILE *f;
	f=fopen("/etc/config/myconfig/interrupt_string","r");
	char buf[50];
	memset(buf,0,sizeof(buf));
	fread(buf,sizeof(char),50,f);
  	printf("LYC-SocketPackage is running!******Read file:%s********\n",buf);
	fclose(f);
	*/
	int sk;
	struct sockaddr_in servaddr;

	sk=socket(AF_INET,SOCK_STREAM,0);

	memset(&servaddr,0,sizeof(servaddr));
	servaddr.sin_family=AF_INET;
	servaddr.sin_port=htons(atoi(argv[2]));
	inet_pton(AF_INET,argv[1],&servaddr.sin_addr);

	printf("******Connect to IP %s\n",argv[1]);
	connect(sk,(struct sockaddr*)&servaddr,sizeof(servaddr));	

	close(sk);
	printf("******Close Socket************\n");
		
	while(1)
	{		
		send(sk,"Hello",5,0);
		printf("******Send to IP %s\n",argv[1]);	
		sleep(atoi(argv[3]));
	}
	/*
	int i=0;
	int j=0;
	double time1=clock()/CLOCKS_PER_SEC*1000*1000*1000;
	for(j=0;j<1000;j++)
	{
		for(i=0;i<1000;i++);		
	}
	double time2=clock()/CLOCKS_PER_SEC*1000*1000*1000;
	printf("**********Time1 = %f************\n",time1);
	printf("**********Time2 = %f************\n",time2);
	printf("Execute 1000*1000 instructions use time %f\n",time2-time1);
	*/	
}
