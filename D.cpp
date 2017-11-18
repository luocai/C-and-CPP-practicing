#include <stdio.h>
int main ()
{
	int n,a,b,c,d;
	scanf("%d",&n);
	for (int i = 0;i < n; i++)
	{
		scanf("%d%d%d%d",&a, &b, &c, &d);
		printf("%d %d\n",a*c-b*d,b*c+a*d);
	}
	return 0;
} 
