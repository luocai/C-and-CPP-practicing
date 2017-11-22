#include <stdio.h>
#include <string.h>
#define max 300
void reverse (char *str)
{
	

	for (int j = strlen(str)-1; j >= 0; j--)
	{
		printf("%c", str[j]);
		str[j] = '\0';
	}
	
	
}
int main ()
{
	char str[max];
	char temp[max];
	int j = 0;
	gets(str);
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ')
			temp[j++] = str[i]; 
		else
		{
			temp[j] = '\0';
			reverse(temp);
			printf(" ");
			j = 0;
		}
		if (str[i + 1] == '\0')
			reverse(temp);
	}
	return 0;
}
