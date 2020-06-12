#include <stdio.h>
#include <semaphore.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>

sem_t wr,mutex;
int rc=0;

void *writer()
{
	while(1)
	{
		sem_wait(&wr);
		printf("writer writing\n");
		
		sem_post(&wr);
		sleep(1);
						//easiest function in entire process sync 	
		//quick tip, try sleeping after sem_post, you get better outputs
	}
	pthread_exit(0);
}

void *reader(void *arg)
{
	int i=(int *)arg;
	while(1)
	{
		sem_wait(&mutex);
		rc++;
		if(rc==1)
		{
			sem_wait(&wr);
		}
		sem_post(&mutex);

		printf("reader %d is reading\n",i);
			
		sem_wait(&mutex);
			sleep(1);
// 			sleep after it has finished reading also, this was just to make it look cuter 
		rc--;
		if(rc==0)
		{
			sem_post(&wr);
		}
		printf("reader %d finished reading\n",i);
		sem_post(&mutex);
		sleep(1);
	}
	pthread_exit(0);
}
		
int main()
{
	sem_init(&mutex,0,1);
	sem_init(&wr,0,1);


	pthread_t r1,r2,w;
	
	  pthread_create(&w,NULL,writer,NULL);

	pthread_create(&r1,NULL,reader,(void *)1);
	pthread_create(&r2,NULL,reader,(void *)2);
//	 pthread_create(&w,NULL,writer,NULL);

	 pthread_join(r1,NULL);
	 pthread_join(r2,NULL);
	 pthread_join(w,NULL);

}


