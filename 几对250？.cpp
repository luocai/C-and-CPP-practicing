#include<stdio.h>
#define max 1000
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
	{
		int m;
		int a[max];
		int count = 0;
		scanf("%d",&m);
		for (int j = 0; j < m; j++)
			scanf("%d",&a[j]);
		for (int x = 0; x < m; x++)
		{
			for (int y = x+1; y < m; y++)
			{
				if (a[x] + a[y] == 250)
					count++;
			}
		}
		printf("%d\n",count);
	} 
	return 0;
 } 
