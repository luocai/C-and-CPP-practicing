#include <stdio.h>
int isHuiwen(int x)
{
	int a[100];
	int i = 0;
	while (x)
	{
		a[i++] = x % 10;
		x /= 10;
	}
	i--;
	for (int j = 0; j < i; j++,i--)
	{
		if (a[j]!=a[i])
			return 0;
	}
	return 1;
	
}
int main ()
{
	int n,x;
	scanf ("%d",&n);
	for (int i = 0; i < n; i++)
	{
		scanf ("%d",&x);
		if (isHuiwen(x))
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}
