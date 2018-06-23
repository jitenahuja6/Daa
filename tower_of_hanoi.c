#include<stdio.h>
void tower(int,char,char,char);
int c;
int main()
{
	int n;
	system("clear");
	printf("\n Enter No. of Disk to Be inserted:");
	scanf("%d",&n);
	tower(n,'S','A','D');
	return(0);	
}
void tower(int n,char S,char A,char D)
{
	if (n==1)
	{
		printf("\nStep %d :  %c -> %c",++c,S,D);
		return;
	}
	tower(n-1,S,D,A);
	printf("\nStep %d :  %c -> %c",++c,S,D);
	tower(n-1,A,S,D);
	return;
}

