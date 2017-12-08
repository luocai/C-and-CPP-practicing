#include <stdio.h>
#define max 100
int a[max];
int b[max];
int c[max];
int main ()
{
	int m, n;
	scanf("%d%d",&m,&n);
	for (int i = 0; i < m; i++)
		scanf("%d",&a[i]);
	for (int i = 0; i < n; i++)
		scanf("%d",&b[i]);
	int i = 0, j = 0, k = 0;
	while (i < m && j < n)
	{
		if (a[i] < b[j])
		{
			c[k++] = a[i++];
		}
		else
		{
			c[k++] = b[j++];
		}
	}
	while (i < m)
	{
		c[k++] = a[i++];
	}
	while (j < n)
	{
		c[k++] = b[j++];
	}
	
	for (int i = 0; i < k; i++)
	{
		printf("%d ",c[i]);
	}
	
	return 0;
} 
