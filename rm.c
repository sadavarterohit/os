
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	if(unlink(argv[1])==0)
		printf("success");
	else
		printf("unsucess");
}
