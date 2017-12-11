#include <stdio.h>
#include <string.h> 
#define max 1000
char n1[max];
char n2[max];
int ans[max];
int main()
{
	int n;
	scanf("%d",&n);
	for (int m = 0; m < n; m++)
	{
		 scanf("%s%s",&n1,&n2);
		 int a = strlen(n1);
		 int b = strlen(n2);
		 int c = 0;
		 int k = 0;
		 int i, j;
		 for(i = a -1, j = b -1; i >= 0 && j >= 0; i--,j--)
		 {
		 	int temp = n1[i] - '0' + n2[j] - '0' + c;
		 	c = temp / 10;
		 	ans[k++] = temp % 10;
		 }
		 while (i >= 0)
		 {
		 	int temp = n1[i--] - '0' + c;
		 	c = temp / 10;
		 	ans[k++] = temp % 10;
		 }
		 while(j >= 0)
		 {
		 	int temp = n2[j--] - '0' + c;
		 	c = temp / 10;
		 	ans[k++] = temp % 10;
		 }
		if (c > 0)
			ans[k++] = c; 
		 for (int i = k - 1; i >= 0; i--)
		 	printf("%d",ans[i]);
		printf("\n");
	}
	 
}
