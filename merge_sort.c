#include<stdio.h>
#include<stdlib.h>

void create(int **,int);
void insert(int *, int);
void merge_sort(int *,int,int);
void merge(int *,int ,int,int);
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
        merge_sort(a,0,n-1);
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

void merge_sort(int *a,int p,int r)
{
	int q;
	if(p<r)
	{
		q=(p+r)/2;
		merge_sort(a,p,q);
		merge_sort(a,q+1,r);
		merge(a,p,q+1,r);
	}
	return;
}

void merge(int *a,int ls,int rs,int re)
{
	int k=-1,temp[100],i,j,le;
	le=rs-1;
	i=ls;
	j=rs;
	while((i<=le )&&( j<=re))
	{
		if(a[i]<a[j])
		{
			k=k+1;
			temp[k]=a[i];
			i=i+1;
		}
		else
		{
			k=k+1;
			temp[k]=a[j];
			j=j+1;
		}
	}
	while(i<=le)
	{
		k=k+1;
		temp[k]=a[i];
		i=i+1;
	}
	while(j<=re)
	{
		k=k+1;
		temp[k]=a[j];
		j=j+1;
	}
	for(i=0;i<=k;i++)
	{
	a[ls+i]=temp[i];
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
