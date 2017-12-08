#include <stdio.h>
int main ()
{
	int n,count = 0;
	scanf("%d",&n);
	count = (n / 50) * 2 + ((n / 50) * 5);
	if (n % 50 >= 30) 
		count = count + (n % 50) / 10 + 1;
	else 
		count = count + (n % 50) / 10;
	printf("%d",count);
	
	return 0;
} 
