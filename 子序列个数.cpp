#include <stdio.h>
#define max 1000
char a[max];
char b[max];
int main ()
{
	scanf("%s%s",a,b);
	int ans = 0;
	for (int i = 0; a[i] != '\0';)
	{
		int flag = 1;
		int j ;
		for (j = 0;  b[j] != '\0'; j++, i++) 
		{
			 if (a[i] != b[j])
			 {
			 
			 	i = i - j + 1; 
			 	j = 0;
			 	flag = 0;
			 	break;
			 }
		}
		if (flag == 1)
		{
			ans++;
			i = i - j + 1 ;
		}
			
	} 
	
	printf("%d",ans);
	
	return 0;
	
}
