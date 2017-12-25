#include <stdio.h>
#define max 1000
void sort(int a[], int n)
{
	int temp;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i] > a[j])
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
		int a[max];
		scanf("%d",&m);
		for(int i = 0; i < m; i++)
		{
			scanf("%d",&a[i]);
		}
		sort(a, m);
		for (int i = 0; i < m; i++)
			printf("%d ",a[i]);
		int k = 1;
		int j = 1;
		while (k != 2 && j < m)
		{
			if (a[j] != a[j-1])
				k++;
			j++;
		}
		if (k == 2)
		{
			printf("%d\n",a[j-1]);
		}
		else
			printf("ERROR\n");
	}
	
	return 0;
}
