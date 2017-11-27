#include <stdio.h>
#include <string.h>
#define max 100

int main ()
{
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; i++)
	{
		char n1[max];
		char n2[max];
		int flag = 0;
		scanf("%s%s",n1,n2);
		if (strlen(n1) < strlen(n2))
		{
			printf("%s\n",n1);
		}
		else if (strlen(n1) > strlen(n2)) 
		{
			printf("%s\n",n2);
		}
		else
		{
			for (int i = 0; i < strlen(n1); i++)
			{
				if (n1[i] < n2[i])
				{
					printf("%s\n",n1);
					flag = 1;
					break;
				}
				else if (n1[i] > n2[i])
				{
					printf("%s\n",n2);
					flag = 1;
					break;
				}
				else
					continue;
			}
			if (flag == 0)
			{
				printf("%s",n1);
			}
			flag = 0;
		}
		
	}
}
