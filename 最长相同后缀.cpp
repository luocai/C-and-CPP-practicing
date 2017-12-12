#include <stdio.h>
#include <string.h>
#define max 1000
int main ()
{
	char a[max], b[max], c[max];
	scanf("%s%s",a, b);
	int i = strlen(a) - 1;
	int j = strlen(b) - 1;
	int k = 0;
	int flag = 0;
	while (i >= 0 && j >= 0)
	{
		if (a[i] == b[j])
		{
			c[k++] = a[i];
			i--;
			j--;
			flag = 1;
		}
		else
			break;
	}
	if (flag == 0)
		printf("null");
	else
		for (int m = k- 1; m >= 0; m--)
			printf("%c",c[m]);
	
	return 0;
} 
