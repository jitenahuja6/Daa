#include<stdio.h>
#include<stdlib.h>
#define maxsize 5
typedef struct stack{
		int arr[maxsize],top;
	} stk;
void push(stk *,int);
void pop(stk *);
int isfull(stk *);
int isempty(stk *);
int display(stk *);
main()
{
	int item,ch;
	stk s,*sp;
	sp=&s;
	sp->top=-1;
	while(1)
	{
		printf("\n1.Push\n2.Pop\n3.Display\n0.Exit\n Choose any::\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("\nEnter item:");
				scanf("%d",&item);
				push(sp,item);
				break;
			case 2:
				pop(sp);
				break;
			case 3:display(sp);
				break;
			case 0: exit (0);
		}
	}
}
int isfull(stk *sp)
{
	if(sp->top==maxsize-1)
		return 1;
	else
		return 0;
}
int isempty(stk *sp)
{
if(sp->top==-1)
	return 1;
else
	return 0;
}
void push(stk *sp,int item)
{
	if(isfull(sp))
	{
		printf("\nOver flow");
		return;
	}
	sp->top=sp->top+1;
	sp->arr[sp->top]=item;
	return;
}
void pop(stk *sp)
{
int item;
if(isempty(sp))
{
	printf("\nStack is Empty");
	return;
}
item=sp->arr[sp->top];
(sp->top)--;
printf("\n Deleted item is %d..",item);
}
int display(stk *sp)
{
	int i;
	for(i=0;i<=sp->top;i++)
	printf("%d\n",sp->arr[i]);
	return;
}
