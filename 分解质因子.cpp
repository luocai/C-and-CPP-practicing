#include <stdio.h>
#include <math.h>
#define max 100000
int a[max] = {2,3};
int isprimer(int x)
{
	if (x == 1)
		return 0;
	if (x == 2 || x == 3)
		return 1;
	for (int i = 2; i < sqrt(x);i++)
	{
		if (x % i == 0)
			return 0;
	}
	return 1;
}
int main ()
{
	int n, k = 2, num;
	scanf ("%d",&n);
	for (int i = 4; i < max; i++)
	{
		if (isprimer(i))
			a[k++] = i;
	}
	
	for (int i = 0; i < n; i++)
	{
		scanf ("%d",&num);
		if (num == 1)
		{
			printf("%d\n",1);
			continue;
		}
		for (int j = 0; num > 1; j++)
		{
			if (num % a[j] == 0)
			{
				while (num % a[j] == 0)
				{
					if (num / a[j] != 1)
						printf ("%d*",a[j]);
					else
						printf ("%d\n",a[j]);
					num /= a[j];
				}
				
			}
		}
	}
}
