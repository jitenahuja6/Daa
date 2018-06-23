#include<stdio.h>
#include<stdlib.h>

void create(int **,int);
void insert(int *, int);
void bubble_sort(int *,int);
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
        bubble_sort(a,n);
        printf("\nafter\n");
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

void bubble_sort(int *a,int n)
{
        int i,j,temp;

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
         
