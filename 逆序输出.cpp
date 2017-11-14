#include <stdio.h>
#include <string.h>
int main ()
{
	int n;
	scanf ("%d",&n);
	getchar();
	for (int i = 0; i < n; i++)
	{
		char str[100];
		int size;
		gets(str);
		size = strlen(str);
		for (int i = size - 1; i >= 0; i--)
		{
			printf ("%c",str[i]);
		}
		printf ("\n");
	}
	return 0;
} 
