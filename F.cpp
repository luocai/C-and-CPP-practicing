#include <stdio.h>
int gcd (int a, int b)
{
	int m = a, n = b,r;
	while (b)
	{
		r = a % b;
		a = b;
		b = r;
	}
	return m * n / a;
}

int main()
{
	int n,a,b;
	scanf ("%d",&n);
	for (int i = 0; i < n; i++)
	{
		scanf ("%d%d",&a,&b);
		printf ("%d\n",gcd(a, b));
	}
	
	return 0;
 } 
