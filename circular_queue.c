#include<stdio.h>
#include<stdlib.h>

typedef struct circular
{
        int info;
	struct circular *next;
}cqueue;

void enqueue(cqueue **,int);
int dequeue(cqueue **);
int main()
{
	cqueue *rear=NULL;
	int ch,item;
	while(1)
	{

		printf("\n1.Enqueue\n2.Dequeue\n0.exit\n enter your choice");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:printf("\n Enter element to enqueue:");
			scanf("%d",&item);
			enqueue(&rear,item);
			break;
		case 2:item=dequeue(&rear);
			if(item !=-9999)
			printf("\ndeleted item is %d",item);
			break;
 		case 0:exit(0);
		default:printf("\n Wrong Option....");
			break;
		}
	}
return(0);
}
void enqueue(cqueue **rear,int item)
{
	cqueue *newnode;
	newnode=(cqueue *)malloc(sizeof(cqueue));
	if(newnode==NULL)
	{
		printf("\n Overflow");
		return;
	}
	newnode->info=item;
	if(*rear==NULL)
	{
		*rear=newnode;
		newnode->next=newnode;
	}
	else
	{
	newnode->next=(*rear)->next;
	(*rear)->next=newnode;
	*rear=newnode;
	}
return;
}
int dequeue(cqueue **rear)
{
	cqueue *front;
	int item;

	if(*rear==NULL)
	{
		printf("\n Under Flow");
		return(-9999);
	}
	front=(*rear)->next;
	item=front->info;
	if(front==*rear)
	{
	*rear=NULL;
	}
	else
	{
	(*rear)->next=front->next;
	}
	front->next=NULL;
	free(front);
return(item);
}

