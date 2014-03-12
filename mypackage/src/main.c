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
	
	char buf[10];	
	char tmp[3];
	int i=0;
	int sleep_t=atoi(argv[3]);	
	while(1)
	{
		//i++;
		memset(buf,0,sizeof(buf));
		//memset(tmp,0,sizeof(tmp));
		strcpy(buf,argv[4]);
		//sprintf(tmp,"%d",i);
		//strcat(buf,tmp);		
		send(sk,buf,sizeof(buf),0);
		printf("******Send %s to IP %s\n",buf,argv[1]);	
		sleep(sleep_t);
	}
	close(sk);
	printf("******Close Socket************\n");
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
