#include <stdio.h>
#define max 1000
int a[max];
int main ()
{
	int n , m, c;
	scanf("%d%d%d",&n, &m, &c);
	for (int i = 0; i < n; i++)
		scanf("%d",&a[i]);
	if (c == 1)
	{
		for (int i = m; i < n; i++)
			printf("%d ",a[i]);
		for (int i = 0; i < m; i++)
			printf("%d ",a[i]);
	}
	if (c == 0)
	{
		for (int i = n - m; i < n; i++)
			printf("%d ",a[i]);
		for (int i = 0; i < n - m; i++)
			printf("%d ",a[i]);
	}
	return 0;
} 
