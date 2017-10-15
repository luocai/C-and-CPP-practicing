#include <iostream>
#include <string>
#define MAX 10010 
using namespace std;
int next[MAX] = {0};
string str1, str2;
void getNext (string str)
{
	for (int i = 2; i < str.length(); i++)
	{
		for (int j = i - 1,k = 0; j > 0 && k < i-1; j--, k++)
		{
			if (str[j] == str[k])
				next[i]++;
			else
				break;
		}
	}
	/²âÊÔ/ 
//	for (int i = 0; i < str.size(); i++)
//	{
//		cout << next[i]  ;
//	}
} 
//abcbanadgad
void KPM(string str1, string str2)
{
	int i = 0, j = 0;
	for (; i < str1.length() && j < str2.length(); )
	{
		if (str1[i] == str2[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
			i++; 
		}
	}
	if (j == str2.length())
	{
		cout << i - str2.length();
	}
	else
		cout << "failed" << endl;
}
int main ()
{
	cin >> str1 >> str2;
	
	getNext(str2);
	KPM(str1, str2);
	
	return 0;
}
