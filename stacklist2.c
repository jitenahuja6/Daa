#include<stdio.h>
#include<stdlib.h>

typedef struct stk
{
	int info;
	struct stk *next;
}stack;
void push(stack**,int);
int pop(stack**);
main()
{
	stack *top=NULL;
	int ch,item;
	while(1)
	{
	printf("\n 1.push\n 2.pop\n0.exit\n Choice any:\n");
	scanf("%d",&ch);
	switch(ch)
	{
			case 1:printf("\nEnter item:");
                                scanf("%d",&item);
                                push(&top,item);
                                break;
                        case 2: item=pop(&top);
				if(item!=-9999)
				printf("\nPoped =%d",item);
                                break;
			case 0: exit(0);
	}
	}
}
int stackempty(stack **ps)
{
if(*ps==NULL)
	return 1;
else
	return 0;
}
void push(stack **ps,int item)
{
stack *newnode,*temp;
newnode=(stack*)malloc(sizeof(stack));
newnode->info=item;
newnode->next=*ps;
*ps=newnode;
}
int pop(stack **ps)
{
	int item;
	if(stackempty(ps))
	{
	printf("\n Underflow...");
	return(-9999);
	}
	stack *temp=*ps;
	*ps=temp->next;
	item=temp->info;
	temp->next=NULL;
	free(temp);
	return(item);
}

	
