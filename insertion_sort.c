#include<stdio.h>
#include<stdlib.h>

void create(int **,int);
void insert(int *, int);
void insertion_sort(int *,int);
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
        insertion_sort(a,n);
        printf("\nafter Sorting\n");
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

void insertion_sort(int *a,int n)
{
        int i, j, temp;

        for(i=1;i<n;i++)
        {
		temp=a[i];
		j=i-1;
		while(j>=0 && a[j]>temp)
		{
			a[j+1]=a[j];
			j=j-1;
		}
                a[j+1]=temp;       
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
