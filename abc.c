
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#define random(x) (rand()%x)
#define MAX 100

int pid[MAX],mainpid,printpid,status;

void childprocess(int k){
  int pid=getpid();
	printf("start:%d\n",pid);
	sleep(k);
	printf("end:%d\n",pid);
	
	kill(mainpid,40);
	exit(0);
}

int main(int argc,const char * argv[]){
	
	int n = atoi(argv[1]);//传入参数 n
	int t,k;

	mainpid=getpid();
	
	for(t=0;t<n;t++){
		k = random(10);// 时间间隔随机数 k
		
		if(fork()==0){
			childprocess(k);
		}		
		
	}
	for(t=0;t<n-3;t++){
		wait(&status);	
	}
	printpid=wait(&status);
	
	printf("倒数第三个结束的进程是:%d\n",printpid);
	wait(&status);
	wait(&status);
	printf("over\n");
	exit(0);
}

