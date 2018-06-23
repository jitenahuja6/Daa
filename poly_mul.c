#include<stdio.h>
#include<stdlib.h>

typedef struct polynomial
{
	int expo;
	float coeff;
	struct polynomial *next;
}poly;

void create(poly **,int);
void multiply(poly *,poly *,poly **);
poly *insert(poly *,float,int);
void display(poly *);

int main()
{
	int item1,item2,ch;
	poly *h1=NULL,*h2=NULL,*h3=NULL;
	system("clear");
	printf("\nEnter the no. of term of first expression:");
	scanf("%d",&item1);
	create(&h1,item1);
	printf("\n Enter the no of term of second expression:"); 
	scanf("%d",&item2);
	create(&h2,item2);
	multiply(h1,h2,&h3);
	printf("multiplication of(");
	display(h1);
	printf(")*(");
	display(h2);
	printf(")=(");
	display(h3);
	printf(")");
	return(0);
}
void create(poly **head,int n)
{
	poly *newnode,*temp;
	int e,i;
	float c;
	if(*head!=NULL)
	{
		return;
	}
	for(i=1;i<=n;i++)
	{
		printf("\n Enter cofficient:");
		scanf("%f",&c);
		printf("\n Enter Exponent:");
		scanf("%d",&e);
		newnode=(poly *)malloc(sizeof(poly));
		newnode->coeff=c;
		newnode->expo=e;
		newnode->next=NULL;
		if(*head==NULL )
			*head=newnode;
		else
			temp->next=newnode;
		temp=newnode;
	}
	return;
}
void multiply(poly *h1,poly *h2,poly **h3)
{
	poly *loc1,*loc2;
	int c,e;
	if(h1==NULL||h2==NULL)
	{
	printf("\n Multiplication is not possible...");
	return;
	}
	loc1=h1;
	while(loc1!=NULL)
	{
		loc2=h2;
		while(loc2!=NULL)
		{
			c=loc1->coeff * loc2->coeff;
			e=loc1->expo + loc2->expo;
			*h3=insert(*h3,c,e);
			loc2=loc2->next;
		}
		loc1=loc1->next;
	}
return;
}
poly *insert(poly *head,float c,int e)
{
	poly *newnode,*loc,*locp;
	loc=head;
	locp=NULL;
	while(loc!=NULL&& loc->expo<e)
	{
		locp=loc;
		loc=loc->next;
	}
	if(loc!=NULL && loc->expo==e)
	{
		loc->coeff=loc->coeff +c;
		return(head);
	}
	newnode=(poly *)malloc(sizeof(poly));
	newnode->coeff=c;
	newnode->expo=e;
	if(head==loc)
	{
		newnode->next=head;
		head=newnode;
	}
	else
	{
		newnode->next=locp->next;
		locp->next=newnode;
	}
return(head);
}
void display(poly *head)
{
	poly *loc=head;
	while(loc!=NULL)
	{
		printf(" %gx^%d +",loc->coeff,loc->expo);
		loc=loc->next;
	}
	printf("\b\b");
	return;
}
