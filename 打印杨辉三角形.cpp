#include <stdio.h>
int a[21][21] = {0};
int main ()
{
	int m; 
	scanf("%d",&m);
	if (m <= 0 || m > 20)
	{
		printf("Input Error");
	}
	else
	{
		a[0][0] = 1;
		a[1][0] = 1;
		a[1][1] = 1;
		if (m == 1)
		{
			printf("%d,",a[0][0]);
		}
		else if (m == 2)
		{
			printf("%d,\n%d,%d,\n",a[0][0],a[1][0],a[1][1]);
		}
		else
		{
			printf("%d,\n%d,%d,\n",a[0][0],a[1][0],a[1][1]);
			for(int i = 2; i < m; i++)
			{	
				for (int j = 0; j <= i; j++)
				{
					if (j == 0)
						a[i][j] = 1;
					else if (i == j)
						a[i][j] = 1;
					else
						a[i][j] = a[i-1][j] + a[i-1][j-1];
				
				printf("%d,",a[i][j]);
				if (i == j)
					printf("\n");
				}				
			}
		}
	}
	
	
	
	return 0;
} 
