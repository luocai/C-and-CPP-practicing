#include <stdio.h>
#include <string.h> 
#define max 1000
int main ()
{
	char s[max];
	char t[max];
	gets(s);
	gets(t);
	int i = 0, j = 0;
	for (; s[j] != '\0'; )
	{
		if (s[j] == t[i])
		{
			j++;
			i++;
		}
		else
		{
			j++;
		}
		
	}
	if(i == strlen(t))
		printf("YES");
	else
		printf("NO"); 
	
} 
