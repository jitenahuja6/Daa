#include<stdio.h>
int fibonacci(int);
int main()
{
	int n,f,i;
	system("clear");
	printf("Enter No. of terms:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	printf("%d ",fibonacci(i));
	}
	return(0);
}
int fibonacci(int n)
{
	int FIBN;
	if(n==0||n==1)
	{
		FIBN=n;
	
	return(FIBN);
	}
	FIBN=fibonacci(n-2)+fibonacci(n-1);
	return(FIBN);
	
}
