#include<stdio.h>
#include<stdlib.h>
void display (int*,int);
void insert(int*,int*,int,int);
void delete(int*,int*,int);

int main()
{
	int arr[50];
	int n,i,p,c,item;
	printf("\n Enter no. of elements:");
	scanf("%d",&n);
	printf("\n Enter %d Elements\n ",n);
	for(i=1;i<=n;i++)
	{
	scanf("%d",&arr[i]);
	}
	printf("\n %d elements in the array:",n);
	display(arr,n);
	while(1)
	{
	printf("\n 1.Insert\n 2.Delete\n 0.Exit\n Choice::");
	scanf("%d",&c);
	
	switch(c)
	{
	case 0: exit(0);
	case 1:printf("\n Enter the position:");
		scanf("%d",&p);
		printf("\n Enter the elements to be inserted:");
		scanf("%d",&item);
		insert(arr,&n,p,item);
		printf("%d elements in the array after insertion\n",item);
		display(arr,n);
		break;
	case 2:printf("\n Enter the position:");
		scanf("%d",&p);
		delete(arr,&n,p);
		printf("\n Delete item in %d ",item);
		printf("\n %d elements in array after deletion\n",n);
		display(arr,n);
		break;
	default:printf("\n Wrong choice....:");
	}
return(0);
}
}
void display(int *a, int n)
	{
	int i;
	for(i=1;i<=n;i++)
	printf("%d\n",a[i]);
	}
void insert(int*a,int*n,int p,int item)
	{
	int i;
	for(i=*n;i>=p;i--)
	a[i+1]=a[i];
	a[p]=item;
	(*n)++;
	return;
	}
void delete(int *a,int*n,int p)
	{
	int i;
	for(i=p;i<=*n-1;i++)
	a[i]=a[i+1];
	(*n)--;
	return;
	}

