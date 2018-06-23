#include<stdio.h>
#include<stdlib.h>

typedef struct polynomial
{
	int expo;
	float coeff;
	struct polynomial *next;
}poly;

void create(poly **,int);
void add(poly *,poly *,poly **);
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
	add(h1,h2,&h3);
	printf("addition of(");
	display(h1);
	printf(")+(");
	display(h2);
	printf(")=(");
	display(h3);
	printf(")\n");
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
void add(poly *h1,poly *h2,poly **h3)
{
	poly *loc1,*loc2;
	float sum=0.0;
	loc1=h1;
	loc2=h2;
	while(loc1!=NULL && loc2!=NULL)
	{
		if(loc1->expo==loc2->expo)
		{
			sum=loc1->coeff + loc2->coeff;
			if(sum!=0)
				*h3=insert(*h3,sum,loc1->expo);
			loc1=loc1->next;
			loc2=loc2->next;
		}
		else if (loc1->expo>loc2->expo)
		{
			*h3=insert(*h3,loc1->coeff,loc1->expo);
			loc1=loc1->next;
		}
		else
		{
			*h3=insert(*h3,loc2->coeff,loc2->expo);
			loc2=loc2->next;
		}
	}
	while(loc1!=NULL)
	{
		*h3=insert(*h3,loc1->coeff,loc1->expo);
		loc1=loc1->next;
	}
	while(loc2!=NULL)
	{
		*h3=insert(*h3,loc2->coeff,loc2->expo);
		loc2=loc2->next;
	}
	return;
}
poly *insert(poly *head,float c,int e)
{
	poly *newnode,*loc;
	newnode=(poly *)malloc(sizeof(poly));
	newnode->coeff=c;
	newnode->expo=e;
	newnode->next=NULL;
	loc=head;
	if(loc==NULL)
		head=newnode;
	else
	{
		while(loc->next!=NULL)
			loc=loc->next;
		loc->next=newnode;
	}
	return(head);
}
void display(poly *head)
{
	poly *loc=head;
	while(loc!=NULL)
	{
		printf(" %gx^%d ",loc->coeff,loc->expo);
		loc=loc->next;
	}
}
