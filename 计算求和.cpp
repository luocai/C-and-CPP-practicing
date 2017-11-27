#include <stdio.h>
int cal(int i)
{
	return (i-1)*i*(i+1);
}
int main ()
{
	int n,m;
	int ans = 0;
	scanf("%d",&n); 
	for (int i = 0;i < n;i++)
	{
		scanf("%d",&m);
		for (int j = 2; j <= m; j++)
		{
			ans += cal(j);
		}
		printf("%d\n",&ans);
		ans = 0;
	}
	
	return 0;
} 
