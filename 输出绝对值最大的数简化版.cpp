#include <stdio.h>
#define MAX 1000
int max(int a[], int n)
{
	int m = -1;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > m)
		{
			m = a[i];
		}
	}
	return m;
}
int main ()
{
	int n; 
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
	{
		int m;
		int a[MAX];
		int x, y;
		scanf("%d",&m);
		for (int j = 0; j < m; j++)
		{
			scanf("%d",&a[j]);
			if (a[j] < 0)
				a[j] = -a[j];
		}
		x = max(a, m);
		int c = 0;
		for (int k = 0; k < m; k++)
		{
			if (a[k] == x)
			{
				a[k] = -1;
				c++;
			}		
		}
		if (c == m)
			y = x;
		else
			y = max(a, m);
		printf("%d %d\n",x, y);
	}
	return 0;
}
