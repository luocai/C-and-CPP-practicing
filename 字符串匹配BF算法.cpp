#include <iostream>
#include <string>
using namespace std;
int main ()
{
	string str1, str2;
	cin >> str1 >> str2;
	
	int i = 0, j , k;
	bool flag = false;
	
	while (i < str1.size())
	{
		for (k = i,j = 0; j < str2.size() && k < str1.size() && str1[k] == str2[j]; k++, j++)
		{
			;
		}
		
		if (j == str2.size())
		{
			flag = true;
			cout << i << endl;
			break;
		}
		i++;
	}
	if (flag == false)
		cout << "failed" <<endl;
		
	return 0; 
}
