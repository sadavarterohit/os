#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>

static char x[10]="rwxrwxrwx";

int main(int argc, char *argv[])
{
	struct stat s;
	struct group *grp;
	struct passwd *p;
	int i,j;


	if(lstat(argv[1],&s)==-1)
	{
		printf("error in lstat");
		exit(0);
	}

	int mode;
	mode=s.st_mode;

	switch(mode&S_IFMT){
	case S_IFDIR :printf("d"); break;
	case S_IFREG: printf("-"); break;
	case S_IFLNK: printf("l"); break;
	}
	char amode[10];
	for (i=0, j=(1<<8);i<9;i++, j>>=1)
		amode[i]=(j&mode)? x[i]:'-';
	amode[10]='\0';

	printf("%s ",amode);

	printf("%d ",(int)s.st_nlink);
	grp=getgrgid(s.st_gid);
	p=getpwuid(s.st_uid);
	printf("%s ",p->pw_name);
	printf("%s ",grp->gr_name);
	printf("%d ",(int)s.st_size);
	printf("%s\n",argv[1]);
}
