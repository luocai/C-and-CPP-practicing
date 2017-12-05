#include <stdio.h>
#define max 1000010
int a[max];
int b[max];
int main ()
{
	int n, m;
	scanf("%d%d",&n,&m);
	if (m <= n)
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%d",&a[i]);
		}
		int temp;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if(a[i] < a[j])
				{
					temp = a[i];
					a[i] = a[j];
					a[j] = temp;
				}
			}
		}
		int k = 1;
		b[0] = a[0];
		for (int i = 1 ; i < n; i++)
		{
			
			if (a[i] != a[i-1])
			{
				b[k++] = a[i];
			}
		}
		if (m < k)
			printf("%d",b[m-1]);
		else
			printf("%d",b[k-1]);
		
	}
	
	return 0;
	//20 10
//1 2 3 4 5 6 7 8 9 9 9 9 9 12 13 3 2 8 9 98
} 
