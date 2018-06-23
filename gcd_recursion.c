#include<stdio.h>
int gcd(int ,int);
int main()
{
	int a,b;
	printf("\n Enter The Value of A and B:");
	scanf("%d%d",&a,&b);
	printf("GCD=%d",gcd(a,b));
return(0);
}
int gcd(int a,int b)
{
	if(b==0)
	{
	return(a);
	}
	else
	{
	return(gcd(b,a%b));
	}
} 
