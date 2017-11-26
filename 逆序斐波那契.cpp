#include <stdio.h>
#define max 10000
int a[max] = {0};

int main ()
{
	int n;
	scanf("%d",&n);
	a[0] = 1;
	a[1] = 1;
	for (int i = 2; i <= max; i++)
	{
		a[i] = a[i-1] + a[i-2];
	}
	
	for (int i =  n-1; i >= 0; i--)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	
	return 0;
} 
