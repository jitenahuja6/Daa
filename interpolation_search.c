#include<stdio.h>
#include<stdlib.h>

void create(int **,int);

void insert(int *, int);

void sort(int *,int);

void display(int *,int);

int interp_search(int *, int);


int n;

int main()
{
        int *a,i,item,j;
        printf("\n Enter the no of terms:\t");
        scanf("%d",&n);
        create(&a,n);
        insert(a,n);
        printf("\nbefore\n");
        display(a,n);
        sort(a,n);
        printf("\n Enter the item to be searched:\t");
        scanf("%d",&item);
        j=interp_search(a,item);
	if(j==-1)
		printf("\n Item not found:");
	else
		printf("\n Item found at %d",j+1);

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


int interp_search(int *a, int item)
{       int lb=0,beg,mid,ub=n-1,end,j=-1,pos;
        beg=lb;
        end=ub;
         
       if(item<*(a+beg)|| item>*(a+end))
                        return(j);

     	while(beg<=end && j==-1)
	{
		pos=beg+(item-*(a+beg)*(end-beg))/(*(a+end)-*(a+beg));
		
		if(item==*(a+pos))
			j=pos;
		
		else if(item<*(a+pos))
			end=pos-1;
		
		else
			beg=pos+1;
	}

	return(j);
}

void display(int *a,int n)
{
        int i;
        for(i=0;i<n;i++)
                printf("%d ",*(a+i));
        return;
}

