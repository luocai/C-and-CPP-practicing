#include <stdio.h>
double calculator (char *str)
{
	float a = 0, b = 0;
	int flag = 0;
	char temp;
	int count = 0;
	for (int i = 0 ; str[i] != '\0'; i++)
	{
		if (str[i] <= '9' && str[i] >= '0')
		{
			if (flag == 0)
				a = a * 10 + str[i] - '0';
			else
				b = b * 10 + str[i] - '0';
		}
		else
		{
			temp = str[i];
			flag = 1;
			count++;
		}
	}
	if (count != 1)
		return -1;
	switch (temp)
	{
		case '+' : return a + b;
		case '-' : return a - b;
		case '*' : return a * b;
		case '/' : if (b == 0) return -1; else return a / b;
		default : return -1;
	}
} 
int main ()
{
	int n; 
	

	char str[100];
	gets (str);
	float ans = calculator (str);
	if (ans == -1)
		printf ("Input Error\n");
	else
		printf ("%.2f\n",ans);

	
	return 0;
}
