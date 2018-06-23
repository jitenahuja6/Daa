#include<stdio.h>
#include<stdlib.h>

int col[8];
void queen(int,int);
int main()
{
	int k,n;
	printf("\nEnter the no. of rows:");
	scanf("%d",&n);
	queen(n,0);
	printf("\n");
	return(0);
}
void queen(int n,int k)
{
	int i,j,legal,r;
	static int cnt;
	for(j=0;j<n;j++)
	{
		legal=1;
		for(i=0;i<=k-1;i++)
		{
			if((col[i]==j)||abs(col[i]-j)==abs(i-k))
			{
				legal=0;
				break;
			}
		}
		if(legal==1)
		{
			col[k]=j;
			if(k==n-1)
			{
				printf("\n Possible %d placement:",++cnt);
				for(r=0;r<n;r++)
				{
					printf("%d ",col[r]);
				}
			}
			else
			{
				queen(n,k+1);
			}
		}
		
	}
	return;
}
			
	

