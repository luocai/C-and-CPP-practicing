#include <stdio.h>
void swap (int *a,int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
int caculate(int a,int b)
{
	int ans = 0;
	if (a > b)
		swap(&a, &b);
		
	for (int i = a; i <= b; i++)
	{
		if (i % 2 != 0)
			ans += i;
	}
	return ans;
}
int main ()
{
	int n,a,b,ans;
	scanf("%d",&n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d",&a,&b);
		if (a <= 0 || b <= 0)
		{
			printf ("error\n");
		}
		else
		{
			ans = caculate(a, b);
			printf ("%d\n",ans);
		}
	}
	
	return 0;
}
