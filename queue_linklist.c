#include<stdio.h>
#include<stdlib.h>

typedef struct stk
{
	int info;
	struct stk *next;
}queue;
void enqueue(queue **,queue **,int );
int dequeue(queue **,queue**);
int peek(queue *);
int main()
{
queue*front=NULL;
queue*rear=NULL;
int ch, item,p;
while(1)
{
	printf("\n1.Enqueue\n2.Dequeue\n3.peek\n 0.Exit\n Enter your choice......");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:printf("\n Enter Element:");
			scanf("%d",&item);
			enqueue(&front,&rear,item);
			break;
		case 2:item=dequeue(&front,&rear);
			if(item!=-9999)
			printf("\nDequeued item=%d",item);
			break;
		case 3: item=peek(front);
			if(item!=-9999)
			printf("\n first Element=%d",front->info);
			break;
		case 0 :exit(0);
		default:printf("\n Wrong choice....>>>>");
			break;
	}
}
return(0);
}
void enqueue(queue **front,queue **rear,int item)
{
	queue *newnode;
	newnode=(queue*)malloc(sizeof(queue));
	newnode->info=item;
	newnode->next=NULL;
	if((*front)==NULL)
	{
		*front=newnode;
	}
	else
	{
	(*rear)->next=newnode;
	}
	*rear=newnode;
	return;
}
int dequeue(queue **front,queue **rear)
{
	queue *temp;
	int item;
	if((*front)==NULL && (*rear==NULL))
	{
	printf("\n UNDERFLOW");
	return(-9999);
	}
	item=(*front)->info;
	temp=*front;
	*front=temp->next;
	temp->next=NULL;

	if(temp==(*rear))
	{
	*rear=NULL;
	}
	free(temp);
	return(item);
}
int peek(queue *front)
{
	if(front==NULL)
	{
	printf("\n UNDERFLOW");
	return(-9999);
	}
	else
	return(front->info);
}


