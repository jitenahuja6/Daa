#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define MAX 25 

typedef struct stk
{
	int arr[MAX];
	int top;
}stack;

void push(stack * , int);
int pop(stack *);
void calculate(stack *,char);

int main()
{
	stack s, *ps;
	int i ,a,b;
	int item , n ;
	char ch ;
	char exp[100];

	ps=&s;
	ps->top=-1;
	system("clear");
	printf("\n Enter postfix Expression : ");
	gets(exp);
	for( i=0; exp[i] != '\0'; i++ )
	{
		ch=exp[i];
		if(isdigit(ch))
			push(ps,(ch-'0'));	
		else
			calculate(ps,ch);
	} 
	printf("\nResult: %d \n",pop(ps));
	return(0);
}							
	
void calculate(stack *ps,char ch)
{
	int a,b,n;
	a=pop(ps);
	b=pop(ps);
	switch(ch)
	{
		case '*' : n = b*a; 
			   push(ps,n);
		           break;
		case '+' : n = b+a;
			   push(ps,n);
			   break;
		case '-' : n = b-a;
			   push(ps, n);
			   break;
		case '/' : n = b/a;
			   push(ps,n);
			   break;
		case '^' : n = pow(b,a);
			   push(ps,n);
			   break;
	}
}
	
void push(stack *ps, int item)
{
	ps->top=ps->top+1;
	ps->arr[ps->top]=item;
	return;
}

int pop(stack *ps)
{
	int item;
	item=ps->arr[ps->top];
	ps->top=ps->top-1;
	return item;
}

