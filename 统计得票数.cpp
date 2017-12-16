#include<stdio.h>
#include<string.h>
struct person{
	char name[20];
	int count;
}Leader[3] = {"Li", 0, "Zhang", 0, "Fun", 0};
int main ()
{
	int n;
	scanf("%d",&n);
	for(int i = 0 ;i < n; i++)
	{
		char name[20];
		scanf("%s",name);
		if (strcmp(name, Leader[0].name) == 0)
		{
			Leader[0].count++;
		}
		else if(strcmp(name, Leader[1].name) == 0)
		{
			Leader[1].count++;
		}
		else if(strcmp(name, Leader[2].name) == 0)
		{
			Leader[2].count++;
		}
	}
	for (int i = 0 ;i < 3; i++)
	{
		printf("%s:%d\n",Leader[i].name, Leader[i].count);
	}
	return 0;
}
