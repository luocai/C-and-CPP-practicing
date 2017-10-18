#include <stdio.h>

int isFlower(int x)
{
	if (x >= 100 && x <= 999)
	{
		int a, b , c;
		a = x / 100;
		b = x / 10 % 10;
		c = x % 10;
		if (x == a*a*a + b*b*b + c*c*c)
			return 1;
		else
			return 0;
    } 
	
}
int main ()
{
	int n;
	int x , y;
	int i, j, k;
	int flag = 0;
	int a[1000][50] = {0};
	scanf ("%d",&n);
	for (i = 0,k = 0; i < n; i++)
	{
		scanf ("%d%d",&x, &y);
		if (x >= 100 && x <= 999 && y >= 100 && y <= 999)
		{
			for (j = x; j <= y; j++)
			{
				if (isFlower(j))
				{
					a[i][k] = j;
					k++;
				}
			}
			k = 0;
		}
		
	}
	k = 0;
	for (i = 0; i < n; i++)
	{
		if (a[i][k] != 0)
		{
			while (a[i][k] != 0)
			{
				if (a[i][k+1] == 0)
				{
					printf ("%d\n",a[i][k]);
					break;
				}
				printf ("%d ", a[i][k]);
				k++;
			}
		}
		else
			printf ("-1\n");
		k = 0;
	}
	
	return 0;
	
}
