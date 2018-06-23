#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

typedef struct stk{
	int arr[SIZE];
	int front,rear;
}queue;
int queue_empty(queue *);
int queue_full(queue *);
void enqueue(queue *,int);
int dequeue(queue *);

int main()
{
	queue q,*pq;
	pq=&q;
	pq->front=-1;
	pq->rear=-1;
	int item,ch,p;
	while(1)
	{
	printf(" \n1.Enqueue\n2.Dequeue\n0.Exit\n Enter your choice....\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1 :printf("\n Enter item:");
			scanf("%d",&item);
			enqueue(pq,item);
			break;
		case 2: p= dequeue(pq);
			if(p!=-9999)
			printf("\n Dequed item is %d",p);
			break;
		case 0: exit(0);
		default : printf("\n Wrong Choice you can try Again :)");
	}
	}
	return(0);
}
int queue_empty(queue *pq)
{
	if((pq->front==-1) &&( pq-> rear==-1))
	return(1);
	else
	return(0);
}
int queue_full(queue *pq)
{
	if((pq->front==0) &&(pq->rear==SIZE-1)||(pq->front==pq->rear+1))
	return(1);
	else
	return(0);
}
void enqueue(queue *p,int item)
{
	if(queue_full(p))
	{
	printf("\n OVERFLOW");
	return;
	}
	if(queue_empty (p))
	{
	p->front=p->rear=0;
	}
	else if (p->rear==SIZE-1)
	p->rear=0;
	else
	p->rear=p->rear+1;
	p->arr[p->rear]=item;
	return;
}
int dequeue(queue *p)
{
	int item;
	if(queue_empty(p))
	{
	printf("\n UNDERFLOW");
	return(-9999);
	}
	item=p->arr[p->front];
	if(p->front==p->rear)
	{
	p->front=-1;
	p->rear=-1;
	}
	else if(p->front==SIZE-1)
	p->front=0;
	else
	p->front=p->front+1;
	
	return(item);
}

