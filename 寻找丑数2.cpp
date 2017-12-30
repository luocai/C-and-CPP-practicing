#include <stdio.h>
#define max 1000000
int a[max];
int main ()
{
	int n;
	scanf("%d",&n);
	
	a[0] = 1;
	int k = 1;
	
	for (int i = 2; i < max; i++)
	{
		int flag = 1;
		int temp = i;
		while (flag && temp != 1)
		{
			if (temp % 2 == 0)
			{
				temp /= 2;
			}
			else if (temp % 3 == 0)
			{
				temp /=3; 
			}
			else if (temp % 5 == 0)
			{
				temp /= 5;
			}
			else
			{
				flag = 0;
			} 
		}
		if (flag == 1)
			a[k++] = i;
	}
	
	for (int i = 0; i < n; i++)
	{
		int m;
		scanf("%d",&m);
		for (int j = 0; a[j] <= m; j++)
		{
			printf("%d ",a[j]);
		}
		printf("\n");
	}		
		
	return 0;
}
