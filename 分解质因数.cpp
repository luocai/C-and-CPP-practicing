#include <stdio.h>
#include <math.h>
#define max 100000
int a[max];
int main ()
{
	int k,x;
	scanf("%d",&k);
	int m = 2;
	a[0] = 2;
	a[1] = 3;
	for (int i = 4; i < max; i++)
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
			a[m++] = i;
	}
	for (int i = 0; i < k; i++)
	{
		scanf("%d",&x);
		while(x != 1)
		{
			for (int j = 0; j < m; j++)
			{
				if (x % a[j] == 0)
				{
					x = x / a[j];
					if(x == 1)
					{
						printf("%d\n",a[j]);
						break;
					}
					else
						printf("%d*",a[j]);
					while (x % a[j] == 0 && x != 0)
					{
						x = x / a[j];
						if(x == 1)
						{
							printf("%d\n",a[j]);
							break;
						}
						else
							printf("%d*",a[j]);
					}
				}
			}
		}
	}
	
}
