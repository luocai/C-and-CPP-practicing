#include<iostream>
#include<string>
using namespace std;
int main ()
{
	string str1, str2;
	cin >> str1 >> str2;
	
	int i = 0, j = 0;
	
	for (; i < str1.size() && j < str2.size(); )
	{
		if (str1[i] == str2[j])
		{
			i++;
			j++;
		}
		else
		{
			j = 0;
			i = i - j + 1;
		}
	}
	if (j == str2.size())
	{
		cout << i - str2.size() << endl; 
	}
	else
		cout << "failed" << endl;
		
	return 0;
} 
