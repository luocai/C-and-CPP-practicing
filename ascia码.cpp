#include <stdio.h> 
int main ()
{
	int n;
	scanf("%d",&n);
	getchar();
	for (int i = 0; i < n; i++)
	{
		char str[100];
		int sum = 0;
		gets(str);
		for (int i = 0; str[i] != '\0'; i++)
		{
			if (i % 2 == 0 && i != 0)
			{
				printf ("%c",sum);
				sum = 0;
			}
			if (str[i] <= '9' && str[i] >= 0)
			{
				sum = sum * 16 + str[i] - '0';
			}
			else
			{
				switch(str[i])
				{
					case 'A': sum = sum * 16 + 10; break;
					case 'B': sum = sum * 16 + 11; break;
					case 'C': sum = sum * 16 + 12; break;
					case 'D': sum = sum * 16 + 13; break;
					case 'E': sum = sum * 16 + 14; break;
					case 'F': sum = sum * 16 + 15; break;
				}
			}
		
		}
		printf ("%c\n",sum) ;
	}
	
	return 0;
}
