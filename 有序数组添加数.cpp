#include <stdio.h>
int a[10] = {1,3,5,7};
int main ()
{
	int n;
	int flag = 0;
	scanf("%d",&n);
	for (int i = 0; i < 4; i++)
	{
		if (n < a[i])
		{
			int j = 3;
			while (j != i)
			{
				a[j+1] = a[j];
				j--;
			}
			a[j+1]= a[j];
			a[j] = n;
			flag = 1;
			break;
		}
	}
	if (flag == 0)
		a[4] = n;
	for (int i= 0; i < 5; i++)
		printf("%d ",a[i]);
		
	return 0;
} 
