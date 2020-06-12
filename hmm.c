#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
int sum;
void* runner (void *jj)
{
	int i=atoi(jj);
	sum=i*i;
	pthread_exit(0);
}
int main(int argc,char *argv[])
{
	printf("hi");
	pthread_t tid;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_create(&tid,&attr,runner,argv[1]);
	pthread_join(tid,NULL);
	printf("square is %d",sum);
	return 0;
}

