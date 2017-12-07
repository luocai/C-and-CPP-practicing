#include <stdio.h>
#define max 1000001
double a[max];
int main()
{
	int n;
	scanf("%d",&n);
	a[0] = 1;
	a[1] = 2;
	for (int i = 2; i < max; i++)
	{
		a[i] = a[i-1] + a[i-2];
	}
	double ans = 0;
	int k;
	for (int i = 0; i < n; i++)
	{
		scanf("%d",&k);
		for (int i = 0; i < k; i++)
		{
			ans = ans + (a[i] / a[i+1]);
		}
		printf("%.6lf\n",ans);
		ans = 0;
	}
	
	return 0;
} 
