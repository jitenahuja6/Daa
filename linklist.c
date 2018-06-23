#include<stdio.h>
#include<stdlib.h>
 
struct list
{
 int info;
 struct list*next;
};
void create(struct list**,int);
void traverse(struct list*);
void insertfirst(struct list**,int);
void insertlast(struct list**,int);
void count(struct list*);
void delete_first(struct list**);
void delete_last(struct list**);
void reverse(struct list**);
void delete_element(struct list**,int);
void insert_after(struct list**,int,int);
void insert_before(struct list**,int,int);
int main()
{
	int num,ch,item,item1,item2;
	struct list*head=NULL;
	while(1)
	{
		printf("\n 1. Create\n 2.Traverse\n 3.Insert-first\n 4.Insert-last\n 5.Count\n 6.delete-first\n 7.Delete last\n 8.Reverse\n 9.Delete any element\n10.Insert after any Element\n11.Insert before any element\n 0.Exit\n Your Choice :");
		scanf("%d",&ch);
		switch(ch)
			{
				case 1: printf("\n Enter the number of nodes:");
					scanf("%d",&num);
					create(&head,num);
					break;
				case 2: traverse(head);
					break;
				case 3: printf("\n Enter the new node to insert at first:");
					scanf("%d",&item);
					insertfirst(&head,item);
					break;
				case 4:printf("\n Enter new node to insert at last:");
					scanf("%d",&item);
					insertlast(&head,item);	
					break;
				case 5:count(head);
					break;
				case 6:delete_first(&head);
					break;
				case 7:delete_last(&head);
					break;
				case 8:reverse(&head);
					break;
				case 9:printf("\n Enter any node to delete:");
					scanf("%d",&item);
					delete_element(&head,item);
				break;
				case 10:printf("\n Enter any node to insert node after it:");
					scanf("%d",&item1);
					printf("\n Enter new node to insert:");
					scanf("%d",&item2);
					insert_after(&head,item1,item2);
					break;
				case 11:printf("\n Enter any node to insert before it:");
					scanf("%d",&item1);
					printf("\n Enter new node to insert:");
					scanf("%d",&item2);
					insert_before(&head,item1,item2);
					break;
				case 0: exit (0);
					break;
				default:printf("\n Wrong Choice .....");
			}
	}
}
void create( struct list**head,int num)
{
int item,i;
struct list *newnode,*temp;
if(*head!=NULL)
{
printf("\n List Already Exist...");
return;
}
for(i=1;i<=num;i++)
{
	printf("\n Enter The number:");
	scanf("%d",&item);
	newnode=(struct list*)malloc(sizeof(struct list*));
	newnode->info=item;
	newnode->next=NULL;
	if(*head==NULL)
	 	*head=newnode;
	else
		temp->next=newnode;
	temp=newnode;
}
return;
}
void traverse(struct list *head)
{
	struct list *loc=head;
	while(loc!=NULL)
	{
		printf("\n %d",loc->info);
		loc=loc->next;
	}
return;
}
void insertfirst(struct list **head,int item)
{
	struct list *newnode;
	newnode=(struct list*)malloc(sizeof(struct list));
	newnode->info=item;
	newnode->next=*head;
	*head=newnode;
	return;
}
void insertlast(struct list **head,int item)
{
	struct list *newnode,*loc=*head;
	while(loc->next!=NULL)
		loc=loc->next;
	newnode=(struct list*)malloc(sizeof(struct list));
	newnode->info=item;
	newnode->next=NULL;
	loc->next=newnode;
	return;
}
void count(struct list*head)
{
	struct list *loc=head;
	int ct=0;
	while(loc!=NULL)
	{
		ct++;
		loc=loc->next;
	}
	printf("\nNo. of nodes: %d",ct);
return;
}
void delete_first(struct list**head)
{
	if(*head==NULL)
	{
	printf("\n Empty list...");
		return;
	}
	struct list*temp=*head;
	*head=(*head)->next;
	printf("\n Deleting node containing info %d...",temp->info);
	temp->info;
	temp->next=NULL;
	free(temp);
	return;
}
void delete_last(struct list**head)
{
	struct list *loc,*locp;
	if(*head==NULL)
	{
		printf("\n Empty list....");
		return;
	}
	loc=*head;
	while(loc->next!=NULL)
	{
		locp=loc;
		loc=loc->next;
	}
	if(*head==loc)
	{
	*head=NULL;
	}
	else
	{
		locp->next=NULL;
	}
	printf("deleting node containing info %d..",loc->info);
	free(loc);
}
void reverse(struct list**head)
{
	struct list *loc,*locp,*locn;
	if(*head==NULL||(*head)->next==NULL)
	{
	return;
	}
	loc=*head;
	locp=NULL;
	while(loc!=NULL)
	{
		locn=loc->next;
		loc->next=locp;
		locp=loc;
		loc=locn;
	}
	*head=locp;
	return;
}
void delete_element(struct list**head,int item)
{
	struct list *loc=*head,*locp;
	if(*head==NULL)
	{
		printf("\n Empty List...");
		return;
	}
	loc=*head;

	while(loc!=NULL&& loc->info!=item)
	{
	locp=loc;
	loc=loc->next;
	}
	if(loc==NULL)
	{
		printf("\n %d not found",item);
		return;
	}
	locp->next=loc->next;
	printf("\n Deleting node with info %d ",item);
	loc->next=NULL;
	free(loc);
}
void insert_after(struct list**head,int item1,int item2)
{
struct list *loc=*head,*locp,*newnode;
while(*head==NULL)
{
	printf("\n Empty list....");
	return;
}
while(loc!=NULL&&loc->info!=item1)
{
	
	loc=loc->next;
}
if(loc==NULL)
{
	printf("\n %d not found",item1);
	return;
}
newnode=(struct list*)malloc(sizeof(struct list));
newnode->info=item2;
newnode->next=loc->next;
loc->next=newnode;

}
void insert_before(struct list **head,int item1,int item2)
{
struct list *loc=*head,*newnode,*locp;
while(*head==NULL)
{
	printf("\n Empty list....");
	return;
}

while(loc!=NULL&&loc->info!=item1)
{
	locp=loc;	
	loc=loc->next;
}
if(loc==NULL)
{
        printf("\n %d not found",item1);
        return;
}
newnode=(struct list*)malloc(sizeof(struct list));
newnode->info=item2;
if(loc==*head)
{
newnode->next=loc;
*head=newnode;
return;
}
locp->next=newnode;
newnode->next=loc;
return;
}

