#include<stdio.h>
#define max 1000
int a[max];
int main()
{
	int n,ans = 0;
	scanf("%d",&n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d",&a[i]);
	}
	for (int i = 1; i < n - 1; i++)
	{
		if ((a[i]-a[i-1])*(a[i]-a[i+1]) > 0)
			ans++;
	}
	printf("%d",ans);
	
	return 0;
} 
