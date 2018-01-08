#include <stdio.h>
#include <string.h>
#define max 10000
typedef struct {
	char str[1000];
	int num;
}sword;
sword words[max];
int k = 0;
int main()
{
	int a[max];
	int i = 0;
	char c;
	while ((c=getchar()) != EOF)
	{
		a[i++] = c;
	}
	int j;
	for (j = 0; j < i; j++)
	{
		if (a[j] >= 'A' && a[j] <= 'Z')
			a[j] = a[j] + 32;
	}
	
	for (j = 0; j < i ; )
	{
		if (a[j] <= 'z' && a[j] >= 'a')
		{
			char temp[1000];
			int p = 0;
			while (a[j] <= 'z' && a[j] >= 'a')
			{
				temp[p++] = a[j++];
			}
			temp[p] = '\0';
			int flag = 0;
			for (int t = 0; t < k; t++)
			{
				if(strcmp(words[t].str, temp) == 0)
				{
					words[t].num++;
					flag = 1;
					break;
				}
			}
			if (flag == 0)
			{
				sword s;
				strcpy(s.str, temp);
				s.num = 1;
				words[k++] = s;
			}
			
		}
		else
			j++;
	}
	int min = 0;
	for (j = 0; j < k; j++)
	{
		if (words[j].num > words[min].num)
			min = j;
		else if(words[j].num == words[min].num)
		{
			if (strcmp(words[j].str, words[min].str) > 0)
				min = j;
		}
	}
	

	printf("%s %d",words[min].str, words[min].num);
	
	return 0;
}
