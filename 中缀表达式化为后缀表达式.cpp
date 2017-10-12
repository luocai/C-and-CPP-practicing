#include <iostream>
#include <stack>
#include <string> 
#include <map>
using namespace std;

int main ()
{
	string str;
	string str1;
	cin >> str;
	
	stack<char> s;
	map <char, int> mp;
	
	mp['+'] = 0;
	mp['-'] = 0;
	mp['*'] = 1;
	mp['/'] = 1;
	
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] <= '9' && str[i] >= '0')
			str1.append(1, str[i]);
		else if (str[i] == ')')
		{
			while (s.top() != '(')
			{
				str1.append(1, s.top());
				s.pop();
			}
			s.pop();
		}
		else
			{
				if (s.size() != 0)
				{
					if (str[i] == '(')
					{
						s.push(str[i]);
						continue;
					}
					if (s.top() != '(' && mp[str[i]] <= mp[s.top()])
					{
						//int count = 2;
						while (s.size() != 0)
						{
							char temp = s.top();
							str1.append(1,temp);
							s.pop();
							//count--;
//							if (s.size() == 0 || mp[temp] > mp[s.top()])
//								break;
							if (s.size() == 0 || mp[str[i]] > mp[s.top()])
								break;
						}
						s.push(str[i]);
					} 
					else
					{
						s.push(str[i]);
					}
				}
				else
				{
					s.push(str[i]);
				}
			} 
	}
	
	while (s.size() != 0)
	{
		str1.append(1, s.top());
		s.pop();
	}
	
	cout << str1 << endl;
//	1+2/5+9*7*5+2 
	
	return 0;
}
