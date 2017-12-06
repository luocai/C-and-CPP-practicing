#include <stdio.h>
#define max 1000
char a[][10] = {"--**-**--",
			    "-*-*****-",
				"-*----**-",
				"--*--**--",
				"---***---",
				"----*----", 
				};
int main()
{
	int n,count = 0;
	scanf("%d",&n);
	
	if (n < 8 && n > 0)
	{
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				int m = 0;
				
					if (i-1>=0 && j-1>=0)
						if (a[i-1][j-1] == '-')
							m++;
				    if (i+1<6 && j-1>= 0)
						if (a[i+1][j-1] == '-')
							m++;
					if (i-1>=0 && j+1<9)
						if (a[i-1][j+1] == '-')
							m++;
					if (i+1<6 && j+1< 9)
						if (a[i+1][j+1] == '-')
							m++;
					if (i-1>=0 && j>=0)
						if (a[i-1][j] == '-')
							m++;
					if (i+1<6 && j>=0)
						if (a[i+1][j] == '-')
							m++;
					if (i >= 0 && j+1<9 )
						if (a[i][j+1] == '-')
							m++;
					if (i >=0 && j-1>= 0)
						if (a[i][j-1] == '-')
							m++;
							
				if (m == n && a[i][j] == '*')
					count++;
			}
		}
		printf("%d",count);
	}
	else
		printf("Input Error"); 
	
	
	return 0;
}
