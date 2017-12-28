#include <stdio.h>
#define max 10000
int main ()
{
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; i++)
	{
		int m;
		int a[max];
		scanf("%d",&m);
		int count = m;
		for (int j = 0; j < m; j++)
		{
			a[j] = j+1;
		}
		int p = 0,k = 0; 
		while (count > 1)
		{
			if (k == 3)
			{
				
				a[(p+k-1)%m] = 0;
				p = p + k;
				k = 0;
				count--;
			}
			else
			{
				if(a[(p+k)%m] == 0)
					p++;
				else
					k++; 
			}
		}
		for (int j = 0; j < m; j++)
		{
			if (a[j] != 0)
			{
				printf("%d\n",a[j]);
				break;
			}
		}
	}
	return 0;
}
