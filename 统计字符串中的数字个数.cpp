#include <stdio.h>
#define max 1000
char str[max];
int main ()
{
	gets(str);
	int flag = 1;
	int ans = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= '0' && str[i] <= '9' && flag == 1)
		{
			ans++;
			flag = 0;
		}
		else if (!(str[i] >= '0' && str[i] <= '9'))
			flag = 1;
	}
	
	printf("%d",ans);
	
	return 0;
}
