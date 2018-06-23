#include<stdio.h>
#include<stdlib.h>

void create(int **,int);
void insert(int *, int);
void quick_sort(int *,int,int);
int partition(int *,int ,int);
void display(int *,int);
int main()
{
        int *a,i,item;
	int n;
        printf("\n Enter the no of terms:\t");
        scanf("%d",&n);
        create(&a,n);
        insert(a,n);
        printf("\nbefore\n");
        display(a,n);
        quick_sort(a,0,n-1);
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

void quick_sort(int *a,int p,int r)
{
	int q;
	if(p<r)
	{
		q=partition(a,p,r);
		quick_sort(a,p,q-1);
		quick_sort(a,q+1,r);
	}
	return;
}

int partition(int *a,int p,int r)
{
	int x,s,temp,q;
	x=a[p];
	q=p;
	for(s=p+1;s<=r;s++)
	{
		if((a[s])<x)
		{
			q=q+1;
			temp=a[q];
			a[q]=a[s];
			a[s]=temp;
		}
	}
	temp=a[p];
        a[p]=a[q];
        a[q]=temp;
	return(q);
}

void display(int *a,int n)
{
        int i;
        for(i=0;i<n;i++)
                printf("%d ",*(a+i));
        return;
}
