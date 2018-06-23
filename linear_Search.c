#include<stdio.h>

int linear_search(int);
int n,a[25];
int main()
{
	int key,i,b;
        printf("\n Enter no of elements:\t");
        scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("\n Enter element at position %d :",i+1);
		scanf("%d",&a[i]);
	}
	printf("\nEnter the search Element:\t");
        scanf("%d",&key);
	b=linear_search(key);
	if(b==0)
                printf("\n The item does not exist");
        else
                printf("%d is at position no %d",key,b);

        return(0);
}
int linear_search (int key)
{
	
	int i,loc=0;
        for(i=1;i<=n;i++)
	{
		
		if(key==a[i])		
		{
			loc=i;
			break;
		}
	
	}
	return(loc);
}
