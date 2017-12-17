#include<stdio.h>
#define max 1000
int a[max][max] = {0};
int main ()
{
	int m, n;
	scanf("%d%d",&m,&n);
	a[0][0] = 1;
	int i = 0, j = 0, k = 1;
	while (i <= m || j <= n)
	{
		if (j < n - 1)
			a[i][++j] = ++k;
		else
			a[++i][j] = ++k;
//printf("%d %d %d\n",i, j,a[i][j]);
		while (j > 0 && i < m - 1)
		{
			a[++i][--j] = ++k; 
//printf("%d %d %d\n",i, j,a[i][j]);
		}
		if (i < m - 1) 
			a[++i][j] = ++k;
		else
			a[i][++j] = ++k;
//printf("%d %d %d\n",i, j,a[i][j]);
		if (i == m-1 && j == n-1)
			break;
		while (i > 0 && j < n - 1)
		{
			a[--i][++j] = ++k;
//printf("%d %d %d\n",i, j,a[i][j]);
		}
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
