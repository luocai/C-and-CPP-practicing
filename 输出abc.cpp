#include <stdio.h>
int main ()
{
	int n, a, b, c;
	int temp;
	int i, j;
	scanf ("%d",&n);
	for (i = 0; i < n; i++)
	{
		scanf ("%d%d%d", &a, &b, &c);
		if (!(a <= 1000 && a >= 2 && b <= 1000 && b >= 2 && c <= 1000 && c >= 2))
		{
			i--;
			continue;
		}
		if (a < b)
			printf("0.");
		else
		{	
			printf ("%d.", a / b);
			a = a % b;
		}
				
	  	for (j = 0; j < c - 1;)
	  	{	 
		  	a *= 10; 		
	  		while (a < b && j < c - 1)
	  		{
	  			printf ("0");
	  			j++;
	  			a *= 10;
			}
			if (j!= c -1)
				printf("%d",a / b);
			a %= b;
			j++;
		}
		a *= 10;		
	//	a >= b ? temp = a/b : temp = 0;
		if (a >=0 )
			temp = a/b;
		else
			temp = 0;
		a = a % b;
		a *= 10;
		a / b >= 5 ? printf("%d",temp+1) : printf ("%d", temp); 
		printf ("\n");
	}
	
	return 0; 
	
}
