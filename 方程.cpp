#include <stdio.h>
#include <math.h>
int main ()
{
	int n,flag = 1, flag2 = 1,flag3 = 1; // 1��0��  1��0��lsum rsum)  1��0�� (δ֪����λ�ã� 
	float rsum = 0, lsum = 0;
	char x,ch;
	scanf("%d",&n);
	getchar();
	for (int i = 0; i < n; i++)
	{
		ch = getchar();
		while (ch != '\n')
		{
			if (ch <= '9' && ch >= '0')
			{
				if (flag2 == 1) // 
				{
					if(flag == 1)
					{
						rsum += (ch - '0');
					}
					else
					{
						rsum -= (ch - '0');
						flag = 1;
					}	
				}
				else
				{
					if(flag == 1)
					{
						lsum += (ch - '0');
					}
					else
					{
						lsum -= (ch - '0');
						flag = 1;
					}	
				}
			
					 
			}
			else if (ch <= 'z' && ch >= 'a')
			{
				x = ch;
				if (flag2 == 1)
					flag3 = 1;
				else
					flag3 = 0;
					
				if (flag == 0) // δ֪��ϵ��Ϊ�������ƶ����� 
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
			
			ch = getchar();
		}
		if (flag3 == 1)
		{
			printf("%c=%.6f\n",x,lsum - rsum);
		} 
		else
			printf ("%c=%.6f\n",x,rsum - lsum);
		lsum = rsum = 0;  // ���ݻָ� 
		flag = flag2 = flag3 = 1;
		
		
	}
	return 0;
} 
