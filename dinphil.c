#include <stdio.h>
#include <semaphore.h>
#include <sys/types.h>
#include <pthread.h>

#define size 5
sem_t m1,m2,chop[size];


void *philo(void *i)
{
	int iden=(int *)i;
	int ov1=0,ov2=0;
	for(i=0;i<10;i++)  //while (1)
				// use while (1) and not for loop cuz well it's gotta be kinda infinite no?
	{
	
		sem_wait(&m1);
	// so down here i check if left and right chopsticks are free if yes, i put a wait on those chopsticks and make him eat  
	
		while(ov1!=1 || ov2!=1)
		{
			sem_getvalue(chop+iden,&ov1);
			sem_getvalue(chop+(iden+1)%size,&ov2);
		}
		sem_wait(chop+iden);
		sem_wait(chop+(iden+1)%size);
		printf("%d is eating with two chops\n", iden);
	//sleep(1);
		sem_post(&m1);
		sleep(1);	

		sem_wait(&m2);
		printf("\t%d is putting down sticks\n",iden);
	//sleep(1);
	//he finished, so post means he is putting down chopsticks (don't use this sleep lmao it's messed up)
		sem_post(chop+iden);
		sem_post(chop+(iden+1)%size);
		sem_post(&m2);
		

	}
	pthread_exit(0);
}



int main()
{
	int i;
	sem_init(&m1,0,1);
	sem_init(&m2,0,1);
	for ( i=0;i<size;i++)
		sem_init(chop+i,0,1);
	
	pthread_t phil[size];
	for(i=0;i<size;i++)
		pthread_create(phil+i,NULL,philo,(void *)i);
	
	for(i=0;i<size;i++)
		pthread_join(phil[i],NULL);
	
}	
