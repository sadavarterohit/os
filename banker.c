#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define p 5
#define r 3

//played with em too much, pls edit
int alloc[p][r]={{0,1,0},{2,0,0},{3,0,2},{2,1,1},{3,3,2}};
int max[p][r]={{7,2,3},{3,2,2},{9,0,2},{2,2,2},{4,3,3}};
int avail[r]={0,0,2};
int need[p][r];
int f[p];
int safe[p];


void setneed()
{	
	int i,j;
	for(i=0;i<p;i++)
	{
		for (j=0;j<r;j++)
		{
			need[i][j]=max[i][j]-alloc[i][j];
			if(need[i][j]<0)
			{
				printf("Negative value of need check again \n");
				exit(0);
			}
		}
	}
}

void finish()
{
	int i;
	for (i=0;i<p;i++)
		f[i]=0;
}

void findsafe()
{

	int c1=0,c2=0,flag=0,i,j,k=0,c=0;
	while(c1<p)
	{
		c2=c1;
		for(i=0;i<p;i++)

		{	
			
			for(j=0;j<r;j++)
			{
				if(need[i][j]<=avail[j])
					k++;
			}
			if(k==r && f[i]==0)
			{
				
				for(j=0;j<r;j++)
					avail[j]=avail[j]+alloc[i][j];

				f[i]=1;
		//		printf("hihi%d",i);
				safe[c++]=i;
				c1++;
			}
			k=0;
		}
		
		if(c1==c2)
		{	
		//	for(j=0;j<p;j++)
                      //  printf("p%d\t",safe[i]);
			printf("\n");
			printf("deadlock");
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		printf("safe sequence\n");
		for(i=0;i<p;i++)
			printf("p%d\t",safe[i]);
	}
}

void main()
{
	setneed();
	finish();
	findsafe();

	//so in exam they will ask you what if P(i) asks for more resources, write one more function that simply adds those more resources to allocated ka process row
	//and subtracts from available pls call if you need more help
}
					

