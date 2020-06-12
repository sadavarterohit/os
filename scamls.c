#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
	execl("/bin/ls","ls","-l",NULL);
}
