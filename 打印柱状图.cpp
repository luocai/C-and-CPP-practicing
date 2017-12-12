#include <stdio.h>
#define max 100
char a[max][max];
int max_n (int b[], int n)
{
	int m = b[0];
	for (int i = 0; i < n; i++)
	{
		if (b[i] > m)
			m = b[i];
	}
	
	return m;
}
int judge(int b[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (b[i] < 0 || b[i] > 10)
			return 0;
	}
	return 1;
}
int main ()
{
	int n, m;
	int b[max];
	scanf("%d",&n);
	for (int i = 0; i < n; i++)
		scanf("%d",&b[i]);
//	if (n >= 1 && n <= 10 && judge(b, n))
//	{
//		
//	}
//	else
	
	if (n >= 1 && n <= 10 && judge(b, n) == 1)
	{
		m = max_n (b, n);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (j < m - b[i])
					a[i][j] = '-';
				else
					a[i][j] = '*';
			} 
		} 
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				printf("%c",a[j][i]);
			}
			printf("\n");
		}
	}
	else
		printf("Input Error");
	
	
	return 0;
}

