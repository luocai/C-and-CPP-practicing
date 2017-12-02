#include <stdio.h>
#define max 1000
int main ()
{
	char str[max];
	gets(str);
	char m = str[0];
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] > m)
			m = str[i];
	}
	for (int i = 0; str[i] != '\0'; i++)
	{
		printf("%c",str[i]);
		if (str[i] == m)
		{
			printf("%s","(SCU)");
		}
	}
	return 0;
} 
