#include <stdio.h>
#define max 10
char a[max][max] = {"I","II","III","IV","V","VI","VII","VIII","IX"};
char b[max][max] = {"X","XX","XXX","XL","L","LX","LXX","LXXX","XCC"};
char c[max][max] = {"C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
int main()
{
	int n;
	while (1)
	{
		scanf("%d",&n);
		if (n < 0)
		{
			printf("Input Error\n");
		}
		else if (n > 0)
		{
			if (n / 100)
			{
				printf("%s",c[n/100 - 1]);
				n %= 100;
			}
			if (n / 10)
			{
				printf("%s",b[n/10 - 1]);
				n %= 10;
			}
			if (n)
				printf("%s\n",a[n-1]);
		}
		else
		{
			printf("End Of Input\n");
			break; 
		}
			
	}
	return 0;
	
} 

