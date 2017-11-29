#include <stdio.h>
int main ()
{

	int m, n;
	scanf("%d%d",&m, &n);
	if (m <= 5 && m > 1 && n <= 5 && n > 1)
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				printf("--**-**--");
			}
			printf("\n");
			for (int j = 0; j < n; j++)
			{
				printf("-*--*--*-");
			}
			printf("\n");
			for (int j = 0; j < n; j++)
			{
				printf("-*-----*-");
			}
			printf("\n");
			for (int j = 0; j < n; j++)
			{
				printf("--*---*--");
			}
			printf("\n");
			for (int j = 0; j < n; j++)
			{
				printf("---*-*---");
			}
			printf("\n");
			for (int j = 0; j < n; j++)
			{
				printf("----*----");
			}
			printf("\n");
			
		}
	}
	else
		printf("Input Error");
	
	
	return 0;
}
