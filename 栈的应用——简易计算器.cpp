#include<iostream>
#include <string>
#include<stack>
#include<map>
using namespace std;
int main ()
{
	cout << "请输入一个表达式，不可以有空格哦，最后加上=" << endl;
	cout << "例如： 8+8/1*2-10+1=" << endl; 
	string str;
	cin >> str;
	
	stack<char> sNum;
	stack<char> sOpr;
	map<char, int> mp;
	
	//用map来存储运算发的优先级 
	mp['+'] = 0;
	mp['-'] = 0;
	mp['*'] = 1;
	mp['/'] = 1;
	
	int a, b, c;
	
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] <= '9' && str[i] >= '0')
		{
			c = str[i] - '0';
			for (int j = i; str[j+1] <= '9' && str[j+1] >= '0'; j++) // 把字符串变成数字，特别注意大于一位数的处理 
			{
				c = c*10 + str[j+1] - '0';
				i++;
			}
			sNum.push(c);
		}
			
		else if (str[i] == '=')
		{
			while (sOpr.size() != 0)
			{
				a = sNum.top();
				sNum.pop();
				b = sNum.top();
				sNum.pop();
				switch(sOpr.top())
				{
					case '+' : 
						sNum.push(a + b);
						sOpr.pop();
						break;
					case '-' :
						sNum.push(b - a); // 注意顺序 
						sOpr.pop();
						break;
					case '*' :
						c = a*b;
						
						sNum.push(c);
						sOpr.pop();
						break;
					case '/' :
						sNum.push(b / a);
						sOpr.pop();
						break;
				}
			}
		}
		else if (str[i] == ')')
		{
			
			while (sOpr.top() != '(')
			{
				a = sNum.top();
				sNum.pop();
				b = sNum.top();
				sNum.pop();
				switch(sOpr.top())
				{
					case '+' : 
						sNum.push(a + b);
						sOpr.pop();
						break;
					case '-' :
						sNum.push(a - b);
						sOpr.pop();
						break;
					case '*' :
						sNum.push(a * b);
						sOpr.pop();
						break;
					case '/' :
						sNum.push(a / b);
						sOpr.pop();
						break;
				}
			}
			sOpr.pop();
		}
		else
		{
			if (str[i] == '(')
			{
				sOpr.push(str[i]);
				continue;
			}
				
			if (sOpr.size() == 0 || sOpr.top() == '(')
			{
				sOpr.push(str[i]);
			}
			else
			{
				if (mp[str[i]] <= mp[sOpr.top()])
				{
					while (sOpr.size() != 0 && mp[str[i]] <= mp[sOpr.top()] )  // 确保执行顺序 4+2-2*(1+2*2)-1=
					{
						a = sNum.top();
						sNum.pop();
						b = sNum.top();
						sNum.pop();
						switch(sOpr.top())
						{
							case '+' : 
								c = a+b; 
								sNum.push(a + b);
								sOpr.pop();
						//		sOpr.push(str[i]);
								break;
							case '-' :
								//c = b - a;
								sNum.push(b - a); // 注意是 b - a 不要搞反啦 
								sOpr.pop();
						//		sOpr.push(str[i]);
								break;
							case '*' :
								c = a*b;
								sNum.push(a * b);
								sOpr.pop();
					//			sOpr.push(str[i]);
								break;
							case '/' :
								c = b/a;
								sNum.push(b / a);
								sOpr.pop();
						//		sOpr.push(str[i]);
								break;
						}
					}
					sOpr.push(str[i]);
					
				}
				else
						sOpr.push(str[i]);
			}
		}
	}
	cout << (int)sNum.top() << endl;
	
	return 0;	
//	4*5+2+5/5*2
//  5+2-1+8/8*4*1
// 8+8/1*2-10+1=
//4+2-2*(1+2*2)-1=
	
}
