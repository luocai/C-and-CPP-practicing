#include <stdio.h>
#include <math.h> 
int islegal(int a, int b, int c) 
{
	if (a + b > c && a + c > b && b + c > a)
		return 1;
	else
		return 0;
}
int main ()
{
	int n,a,b,c;
	scanf ("%d",&n);
	for (int i = 0; i < n; i++)
	{
		scanf ("%d%d%d",&a, &b, &c);
		if (islegal(a, b, c))
		{
			int p = (a+b+c)/2;
			printf ("%.2f\n",sqrt(p*(p-a)*(p-b)*(p-c)));
		}
		else
			printf ("error\n");
	}
	
	return 0;
}
