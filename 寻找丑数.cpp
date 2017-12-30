#include <stdio.h>
#include <math.h>
#define max 10000
int primer[max];
int ans[max];
int main ()
{
	int n;
	scanf("%d",&n);
	
	primer[0] = 2;
	primer[1] = 3;
	primer[2] = 5;
	int k = 3;
	
	for (int i = 6; i < max; i++)
	{
		int flag = 1;
		for (int j = 2; j < sqrt(i); j++)
		{
			if (i % j == 0)
			{
				flag = 0;
				break;
			}
			
		}
		if (flag == 1)
			primer[k++] = i;
	}
//	for (int i = 0; i < 20; i++)
//		printf("%d ",primer[i]);
	ans[0] = 1;
	int p = 1;
	for (int i = 2; i < max; i++)
	{
		int flag = 1;
		for (int j = 3; j < k; j++)
		{
			if (i % primer[j] == 0)
			{
				flag = 0;
				break;
			}
			
		}
		if (flag == 1)
			ans[p++] = i;
	}
//	for (int i = 0; i < 20; i++)
//		printf("%d ",ans[i]);
	for (int i = 0; i < n; i++)
	{
		int m;
		scanf("%d",&m);
		for (int j = 0; ans[j] <= m; j++)
		{
			printf("%d ",ans[j]);
		}
		printf("\n");
	}		
	return 0;
	
}
