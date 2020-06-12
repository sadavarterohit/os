#include<stdio.h>
#include<stdlib.h>
// this might take some time to understand properly, think trees trees trees 
// remember there are 6 fns 2 int 2 void 1 main and 1 node type
struct node
{
	int size;
	int status;
	// 0 if unallocated 1 if allocated 2 if divided  
	struct node *l;
	struct node *r;
};

struct node *getnode(int size, int status)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->l=NULL;
	temp->r=NULL;
	temp->size=size;
	temp->status=status;
}

void display(struct node *head)
{
	if(head->status==2)
	{
		display(head->l);
		display(head->r);
	}
	else
		printf("%d:%d\t",head->size,head->status);
}


void check(struct node *head)
{
	if(head->status==1|| head->status==0)
		return;
	
	check(head->l);
	check(head->r);

	if(head->l->status==0&&head->r->status==0)
	{
		struct node *temp;
		temp=head->l;
		free(temp);
		temp=head->r;
		free(temp);
		head->status=0;
	}
}



int alloc(struct node *head,int size)
{
	if(size>(head->size))
		return 0;
	if(head->status==0)
	{	
		if((head->size)/2>=size)
		{
			head->l=getnode((head->size)/2,0);
			head->r=getnode((head->size)/2,0);
			head->status=2;
			return alloc(head->l,size);
			
		}
		else
		{
			head->status=1;
			return 1;
		}
	}
	else if (head->status==1)
	{
		return 0;
	}
	else 
	{
		if(alloc(head->l,size))
			return 1;
		return alloc(head->r,size);
	}
	return 0;
}


int dealloc(struct node *head, int size)
{
	if(head->status==1)
	{
		if(size == head->size)
		{
			head->status=0;
			return 1;
		}
	}
	else if(head->status ==2)
	{
		if(dealloc(head->l,size))
			return 1;
		else return (dealloc(head->r,size));
	}
	return 0;
}





int main()
{	int size;	
	while(1){
	printf("enter suze\n");
	
	scanf("%d",&size);
	if(size&(size-1))
			{
			continue;
			}
	else break;
	}
	struct node* head=getnode(size,0);
	int a,b,c,d;
	while(1)
	{	
		display(head);
		printf("\n\n1 allocate, 2 dealloc 3 exit\n\n");
		scanf("%d",&c);
		switch (c)
		{
			case 1 :
				printf("enter size\n");
				scanf("%d",&a);
				b=alloc(head,a);
				if(b)
					printf("success\n");
				else 
					printf("fail\n");
				break;
			case 2:
				printf("enter size to delete \n");
				scanf("%d",&a);
				b=dealloc(head,a);
				if(b)
					printf("success\n");
				else
				
					printf("nope \n");
				check(head);
				break;
			case 3:
				exit(0);
				break;
			default :
				printf("invalid input\n");
		}
	}
	return 0;




}
