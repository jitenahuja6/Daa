#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define MAX 30

typedef struct stk{
int info[MAX];
int top;
}stack;
int precedence(char);
int empty(stack *);
char pop(stack *);
void push(stack *,char);
char top(stack *);

int main()
{
stack s,*ps;
ps=&s;
ps->top=-1;
char x[MAX],c;
int i;
printf("\n Enter Infix Expression :");
gets(x);
for(i=0;x[i]!='\0';i++)
{
	if(isdigit(x[i]))
	printf("%c",x[i]);
	else if (x[i]=='(')
	push(ps,'(');
	else
	{
	if(x[i]==')')
	while((c=pop(ps))!='(')
	printf("%c",c);
	else
	{
	while((precedence (x[i]))<=precedence(top(ps)) && empty(ps))
	{ 
	c=pop(ps);
	printf("%c",c);
	}
	push(ps,x[i]);
	}
	}
   }
	return(0);
}
int precedence(char x) 
{
	if(x=='(')
	return(0);
	if(x=='+'||x=='-')
	return(1);
	if(x=='*'||x=='/'||x=='%')
	return(2);	
	return(3);
}
int empty (stack *ps)
{
	if(ps->top==-1)
	return(1);
	else
	return(0);
}
void push (stack *ps,char x)
{
ps->top=ps->top+1;
ps->info[ps->top]=x;
}
char pop(stack *ps)
{
int x;
x=ps->info[ps->top];
ps->top=ps->top-1;
return(x);
}
char top(stack *ps)
{
return(ps->info[ps->top]);
}

