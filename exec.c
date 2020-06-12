#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	printf("hi exec \n");
	execlp("./fork","fork", argv[1], NULL);
	printf("bye exc\n");
}
