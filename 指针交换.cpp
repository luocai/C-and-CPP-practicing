#include <stdio.h>
void swapByPointer(int *A, int *B)
{
	int temp;
	temp = *A;
	*A = *B;
	*B = temp;
} 
int main ()
{
	int a, b;
	scanf("%d%d",&a,&b);
	swapByPointer(&a, &b);
	
	printf("%d %d",a ,b);
	
	return 0;
}
