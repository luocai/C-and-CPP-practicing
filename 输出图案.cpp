#include <stdio.h>
char str[][10] = {"--**-**--",
			    "-*--*--*-",
				"-*-----*-",
				"--*---*--",
				"---*-*---",
				"----*----", 
				};
int main ()
{
	int x, y , w, h;
	scanf("%d%d%d%d",&x,&y,&w,&h);
	if (x<=9 && x>=1 && y<=6 && y>=1 && w>=1 && w<=9 && h<=6 && h>=1 && x+w>=2 && x+w<=10 && y+h>=2 && y+h<=7)
	{
		for (int i = y-1; i <y + h - 1;i++)
		{
			for (int j = x-1; j <x + w -1; j++)
			{
				printf("%c",str[i][j]);
			}
			printf("\n");
		}
	}
	else
		printf("Input Error\n");
	
	return 0;
}
