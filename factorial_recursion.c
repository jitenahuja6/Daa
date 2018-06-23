#include<stdio.h>
int factorial(int);

int main()
{
	int n;
	printf("Enter No. to Find its Factorial:");
	scanf("%d",&n);
	printf(" %d! = %d\n",n,factorial(n));
	return(0);
}
int factorial(int n)
{
	if(n==0)
	{
		return(1);
	}
	else
	{
		return(n*factorial(n-1));
	}
}

