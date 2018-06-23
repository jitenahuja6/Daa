#include<stdio.h>
#include<stdlib.h>

void create(int **,int);
void insert(int *, int);
void sort(int *,int);
void display(int *,int);
void binary_search(int *, int);
int n;
int main()
{
	int *a,i,item;
	printf("\n Enter the no of terms:\t");
	scanf("%d",&n);
	create(&a,n);
	insert(a,n);
	printf("\nBefore\n");
	display(a,n);
	sort(a,n);
	printf("\n Enter the item to be searched:\t");
	scanf("%d",&item);
	binary_search(a,item);
	printf("\nAfter\n");
	display(a,n);
	return(0);
}


void create(int **a,int n)
{	
	*a=(int *)calloc(n,sizeof(int));
	return;
}

void insert(int *a, int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("\n Enter element at pos %d:\t",i+1);
		scanf("%d",(a+i));
	}
	return;
}

void sort(int *a,int n)
{
	int i, j, temp;

	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	return;
}


void display(int *a,int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%d ",*(a+i));
	return;
}

void binary_search(int *a, int item)
{	
	int LB=0,beg,mid,UB=n,end,j=0;
	beg=LB;
	end=UB;
	while(beg<=end && j==0)
	{	mid=(beg+end)/2;
		if(*(a+mid)==item)
			j=mid;

		else if(item<*(a+mid))
			end=mid-1;

		else
			beg=mid+1;
	}
	if(j==0)  
	{      
	       printf("\nitem not found");
	}        
	else
	{
                printf("\n The item is found at %d",j+1);
	}
	return;
}
