#include<stdio.h>
#include<stdlib.h>

typedef struct circular
{
	int info;
	struct circular *next;
}clist;

void create(clist **,int);
void traverse(clist **);
void insert_first(clist **,int);
void insert_end(clist **,int);
void delete_first(clist **);
void delete_end(clist **);
void insert_after_address(clist *,int);
void delete_address(clist **,clist *);
int count(clist **);
int main()
{
	int ch,item,item1,item2,item3,cnt;
	clist *head=NULL,*ptr;
	while(1)
	{
	printf("\n 1.CREATE\n2.TRAVERSE\n3.INSERT FIRST\n4.INSERT END\n5.DELETE FIRST\n6.DELETE END\n7.INSERT AFTER ADDRESS\n8.DELETE ADDRESS\n9.COUNT\n0.EXIT\n......\n Choose your option:");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:printf("\n Enter no.of nodes:");
			scanf("%d",&item);
			create(&head,item);
			break;
		case 2:printf("\n Your list is :");
			traverse(&head);
			break;
		case 3:printf("\n Enter Element to insert at first");
			scanf("%d",&item1);
			insert_first(&head,item1);
			break;
		case 4:printf("\n Enter Element to insert at end");
                        scanf("%d",&item2);
                        insert_end(&head,item2);
			break;
		case 5:delete_first(&head);
			break;
		case 6:delete_end(&head);
			break;
		case 7:printf("\n Enter Element to insert :");
			scanf("%d",&item3);
			printf("\nEnter Addres :");
			scanf("%u",&ptr);
			insert_after_address(ptr,item3);
			break;
		case 8:printf("Enter Address to delete:");
			scanf("%d",&ptr);
			delete_address(&head,ptr);
			break;
		case 9:printf("number of nodes in the list are:");
			cnt= count(&head);
			 printf("%d",cnt);
			break;
		default :printf("\n wrong choice...");
			break;
		case 0:exit(0);
	}
}return;
}
void create(clist **head,int num)
{
clist *newnode,*temp;
int item,i;

if (*head!=NULL)
{
	printf("\n Already created...");
	return;
}
for(i=1;i<=num;i++)
{
	printf("\n enter item to insert:");
	scanf("%d",&item);
	newnode=(clist *)malloc(sizeof(clist));
	newnode->info=item;
	if(*head==NULL)
	{
		*head=newnode;
	}
	else 
	{
		temp->next=newnode;
	}
	temp=newnode;
}
newnode->next=*head;
return;
}

void traverse(clist ** head)
{
	clist *loc;
	if(*head==NULL)
	{
		printf("\n Empty List....");
		return;
	}
		loc=*head;
	do
	{
		printf("%d(%u)\t",loc->info,loc);
		loc=loc->next;
	}while(loc!=*head);
	return;
}
void insert_first(clist **head,int item)
{
	clist *newnode,*loc;
	loc=*head;
	while((loc->next)!=*head)
	{
		loc=loc->next;
	}
	newnode=(clist *)malloc(sizeof(clist));
	newnode->info=item;
	newnode->next=*head;	
	loc->next=newnode;
	*head=newnode;
	return;
}
void insert_end(clist **head,int item)
{
	clist *newnode,*loc;
	loc=*head;
	while((loc->next)!=*head)
        {
	        loc=loc->next;
        }
	newnode=(clist *)malloc(sizeof(clist));
        newnode->info=item;
        newnode->next=*head;
        loc->next=newnode;
        return;
}
void delete_first(clist **head)
{
	clist *loc,*temp;
	loc=*head;
	while((loc->next)!=*head)
        {
 	     	  loc=loc->next;
        }
	temp=*head;
	if(loc==*head)
	{
		*head=NULL;
	}
	else
	{
		*head=temp->next;
		loc->next=*head;
	}
	temp->next=NULL;
	free(temp);
	return;
}
void delete_end(clist **head)
{
	clist *locp,*loc;
	loc=*head;
	while((loc->next)!=*head)
        {
		locp=loc;
	        loc=loc->next;
        }
	if(loc==*head)
	{
		*head=NULL;
	}
	else
	{
		locp->next=*head;
	}
	loc->next=NULL;
	free(loc);
	return;
}
void insert_after_address(clist *ptr,int item)
{
	clist *newnode;
	newnode=(clist *)malloc(sizeof(clist));
	newnode->info=item;
	newnode->next=ptr->next;
	ptr->next=newnode;
	return;
}
void delete_address(clist **head,clist *ptr)
{
	clist *locp;
	locp=ptr;
	while((locp->next)!=ptr)
	{
		locp=locp->next;
	}
	if(locp==ptr)
	{
		*head=NULL;
	}
	else if(ptr==*head)
	{
		locp->next=ptr->next;
		*head=ptr->next;
	}
	else
	{
		locp->next=ptr->next;
	}
	ptr->next=NULL;
	free(ptr);
	return;
}
int count(clist **head)
{
	int cnt=0;
	clist *loc;
	if(*head==NULL)
	{
		return(cnt);


	}
	loc=*head;
	do
	{
		loc=loc->next;
		cnt=cnt+1;

	}while(loc!=*head);

	return(cnt);
}
	
