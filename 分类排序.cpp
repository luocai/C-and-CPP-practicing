#include <stdio.h>
#define max 1000
void sort(int a[], int n)
{
	int temp;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i] < a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}
int main ()
{
	int n, m; 
	scanf("%d",&n);
	for (int i = 0; i < n; i++)
	{
		int num[max];
		scanf("%d",&m);
		num[0] = m;
		for (int j = 1; j < m+1; j++)
		{
			scanf("%d",&num[j]);
		}
		sort(num, m+1);
		for (int i = 0; i < m+1; i++)
			printf("%d ",num[i]);
		printf("\n");
		for (int i = 0; i < m+1; i++)
		{
			if (num[i] % 2 != 0)
				printf("%d ",num[i]);
		}
		
		for (int i = 0; i < m+1; i++)
		{
			
			if (num[i] % 2 == 0)
				if (i == m)
					printf("%d",num[i]);
				else
					printf("%d ",num[i]); 
		}
		printf("\n");
	}
	
	return 0;
	
}
