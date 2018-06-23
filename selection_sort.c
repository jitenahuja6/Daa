#include<stdio.h>
#include<stdlib.h>

void create(int **,int);
void insert(int *, int);
void selection_sort(int *,int);
void display(int *,int);
int n;
int main()
{
        int *a,i,item;
        printf("\n Enter the no of terms:\t");
        scanf("%d",&n);
        create(&a,n);
        insert(a,n);
        printf("\nbefore\n");
        display(a,n);
        selection_sort(a,n);
        printf("\nAfter Sorting\n");
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

void selection_sort(int *a,int n)
{
        int i,j,temp,loc;

        for(i=0;i<n-1;i++)
        {
		loc=i;
                for(j=i+1;j<n;j++)
                {
			
                        if(a[j]<a[loc])
			{
			loc=j;
              		}
		}
		if(loc!=i)
		{
		temp=a[i];
		a[i]=a[loc];
		a[loc]=temp;
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
         
