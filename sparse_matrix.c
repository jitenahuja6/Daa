#include<stdio.h>

typedef struct array
{
	int row;
	int col;
	int value;
}sm;

void input(sm *,int);
void output(sm *,int);
void transpose(sm *,sm *);

int main()
{
	sm a[100],b[100];
	int n,r,c;

	printf("\nEnter no. of rows: ");
	scanf("%d",&r);
	printf("\nEnter no. of columns: ");
	scanf("%d",&c);
	printf("\nEnter no. of non zero values: ");
	scanf("%d",&n);

	a[0].row=r;
	a[0].col=c;
	a[0].value=n;

	printf("\nEnter non zero values\n");
	input(a,n);
	
	printf("\nBefore transpose\n");
	output(a,r);

	transpose(a,b);

	printf("\nAfter transpose\n");
	output(b,r);
}

void input(sm *a,int n)
{
	int i; 
	for(i=1;i<=n;i++)
		scanf("%d%d%d",&a[i].row,&a[i].col,&a[i].value);
	return;
}

void output(sm *a,int n)
{
	int i; 
	for(i=0;i<=n;i++)
		printf("%5d%5d%5d\n",a[i].row,a[i].col,a[i].value);
	return;
}
void transpose(sm *a,sm *b)
{
	int i,j,k;
	b[0].row=a[0].col;
	b[0].col=a[0].row;
	b[0].value=a[0].value;
	k=1;
	for(i=1;i<=a[0].row+1;i++)
	{
		for(j=1;j<a[0].col;j++)
		{
			if(a[j].col==i)
			{
				b[k].row=a[j].col;
				b[k].col=a[j].row;
				b[k].value=a[j].value;
				k++;
			}
		}
	}
	return;
}

