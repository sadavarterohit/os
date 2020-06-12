#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int fd1,fd2;
	if((fd1=open(argv[1],O_RDONLY))==-1)
	{
		printf("error opening input file");
			exit(0);
	}

	if((fd2=open(argv[2],O_CREAT|O_WRONLY))==-1)
	{
		printf("error opening output file ");
		exit(0);

	}
	int n; 
	char buff[20];
	while((n=read(fd1,buff,20))!=0)
		write(fd2,buff,n);

	close(fd1);

	close(fd2);
}
