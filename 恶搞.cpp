#include <stdio.h>
int count(char str[])
{
	int ans = 0; 
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '(')
		{
			ans++;
		}
		else if (str[i] == ')')
		{
			ans--;
		}
		else
		{
			return ans;
		}
	} 
}
int main ()
{
	char str[1001];
	gets(str);
	int ans = count(str);
	
	printf("%d",ans);
	
	return 0;
}
