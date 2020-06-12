#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>


int main(int argc, char *argv[])
{
	int fd;
	struct flock f;

	if((fd=open(argv[1],O_RDWR))==0)
	{
		printf("opening error \n");
		return -1;
	}

	f.l_type=F_WRLCK;
	f.l_whence=0;
	f.l_start=0;
	f.l_len=100;

	if((fcntl(fd,F_SETLK,&f))==0)
	{
		sleep(1);
	}

	else
	{
		fcntl(fd,F_GETLK,&f);
		printf("locked by %d\n",f.l_pid);
		return -1;
	}

	printf("enter to release\n");
	getchar();

	f.l_type=F_UNLCK;

	if((fcntl(fd,F_UNLCK,&f))==-1)
	{
		printf("error released\n");
		return -1;
	}
		printf(" released\n");
	

	close(fd);
return 0;

}


