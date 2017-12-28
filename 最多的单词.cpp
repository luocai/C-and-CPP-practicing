#include <stdio.h>
#include <string.h>
#define max 10000
struct node{
	char a[max];
	int n;
	node(){
		n = 0;
	}
}
node words[max];
int k = 0;
int main ()
{
	char str[max];
	while(gets(str) != NULL)
	{
		char temp[max];
		int a = 0;
		for (int i = 0; i < strlen(str); i++)
		{
			if(str[i] >= 'A' && str[i] <= 'Z' && str[i] >= 'a' && str[i] <= 'z')
			{
				temp[a++] = str[i];
			}	
			else
			{
				node nd;
				strcpy(nd.a, temp);
			}
		}
	}
	return 0;
}
