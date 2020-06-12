#include <stdio.h>
#include <sys/types.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>

#define size 5

int buff[size];
sem_t full,empty,mutex;

void *producer()
{

	printf("entered prod\n");
	int fo,i;
	for(int j=0;j<10;j++)
	{
		sem_wait(&full);
		sem_wait(&mutex);
		//produce
		fo=random()%100;
		sem_getvalue(&empty,&i);	
		buff[i]=fo;
		printf("%d has been produced \n",fo);
//		sleep(1);
		//produced
		//
	sem_post(&mutex);
		sem_post(&empty);
	}
	pthread_exit(0);
}


void *consumer()
{

	int fo,i;
	for(int j=0;j<10;j++)
	{	sem_wait(&empty);
		sem_wait(&mutex);
		//consume
		sem_getvalue(&empty,&i);
		fo=buff[i];
		printf("%d has been consumed \n",fo);
//		sleep(1);
		sem_post(&mutex);
		sem_post(&full);
	}
	pthread_exit(0);
}

int main()
{
	sem_init(&full,0,size-1);
	sem_init(&empty,0,0);
	sem_init(&mutex,0,1);
	pthread_t tid1, tid2;

	pthread_create(&tid1,NULL, producer,NULL);
	pthread_create(&tid2,NULL, consumer,NULL);

	pthread_join(tid1, NULL);
	pthread_join(tid2,NULL);

}
