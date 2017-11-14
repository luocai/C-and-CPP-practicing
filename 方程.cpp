#include <stdio.h>
#include <math.h>
int main ()
{
	int n,flag = 1, flag2 = 1,flag3 = 1; // 1正0负  1右0左（lsum rsum)  1右0左 (未知数的位置） 
	float rsum = 0, lsum = 0,c = 0;
	char x,ch,str[100];
	scanf("%d",&n);
	getchar();
	for (int i = 0; i < n; i++)
	{
		char str[100];
		gets(str);
		for (int i = 0; str[i] != '\0'; i++)
		{
			ch = str[i];
	
			if (ch <= '9' && ch >= '0')
			{
				if (str[i+1] <= '9' && str[i+1] >= '0' )
				{
					c = c*10 + ch - '0'; 
					continue;
				}
				else
				{
					c = c * 10 + ch - '0'; 
					if (flag2 == 1) // 还未遇到=号 
					{
						if(flag == 1)
						{
							rsum += c;
						}
						else
						{
							rsum -= c;
							flag = 1;
						}	
					}
					else
					{
						if(flag == 1)
						{
							lsum += c;
						}
						else
						{
							lsum -= c;
							flag = 1;
						}	
					}
					c = 0; // c 恢复 
				}		 
			}
			else if (ch <= 'z' && ch >= 'a')
			{
				x = ch;
				if (flag2 == 1)
					flag3 = 1;
				else
					flag3 = 0;
					
				if (flag == 0) // 未知数系数为负数，移动方向 
					flag3 = !flag3; 
			}
			else
			{
				switch(ch)
				{
					case '+' : flag = 1; break;
					case '-' : flag = 0; break;
					case '=' : flag2 = 0; flag = 1; break; 
				}
				
			}	
		
			
			
		}
		if (flag3 == 1)
		{
			printf("%c=%.6f\n",x,lsum - rsum);
		} 
		else
			printf ("%c=%.6f\n",x,rsum - lsum);
		c = lsum = rsum = 0;  // 数据恢复 
		flag = flag2 = flag3 = 1;
	} 
	
	return 0;
} 
