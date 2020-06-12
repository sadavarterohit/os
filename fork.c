#include<stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
	printf("%d\n",atoi(argv[1]));
	pid_t pid;
	pid =fork();
	if(pid==0)
	{
		printf("child process %d\n",getpid());
		sleep(1);
		exit(0);
	}

	else
	{
		printf(" parent process waiting \n");
		wait();
		printf("child over\n");

		exit(0);
	}
}
