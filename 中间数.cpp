#include <stdio.h>
#define max 10000
int a[max];
int big(int a[], int n, int x)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > x)
			count++;
	}
	return count;
}
int sml(int a[], int n, int x)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] < x)
			count++;
	}
	return count;
}
int main ()
{
	int n;
	scanf("%d",&n);
	int flag = 1;
	for (int i = 0; i < n; i++)
	{
		scanf("%d",&a[i]);
	}
	for (int i = 0; i < n; i++)
	{
		if (big(a, n, a[i]) == sml(a, n, a[i]))
		{
			printf("%d",a[i]);
			flag = 0;
			break;
		}
	} 
	if (flag == 1)
		printf("-1");
	return 0;	
} 
