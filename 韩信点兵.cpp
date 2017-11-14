#include <stdio.h>
int main ()
{
	int n,a,b,c;
	scanf ("%d",&n);
	for (int i = 0; i < n; i++)
	{
		int flag = 0;
		scanf("%d%d%d",&a,&b,&c);
		for (int j = 10; j <= 100; j++)
		{
			if (j % 3 == a && j % 5 == b && j % 7 == c)
			{
				flag = 1;
				printf ("%d\n",j);
			}			
		}
		if (flag == 0)
			printf ("Impossible\n");
	}
	
	return 0;
}
