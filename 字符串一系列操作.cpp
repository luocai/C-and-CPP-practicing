#include <iostream>
#include <cstring>
#include <cstdio>
#define MAX 100
using namespace std; 
class SqString{
	private :
		char data[MAX];
		int length;
	public :
		SqString()
		{
			length = 0;
		}
		//字符数组对其初始化 
		SqString(char str[])
		{
		//	cout << strlen(str) << endl;
			for (int i = 0; i < strlen(str);i++) // 此处是个坑，一开始用的sizeof  思考，数组传入退化为指针的问题 
			{
				data[i] = str[i];
			}
			length = strlen(str);
		}
		char* getData ()
		{
			return data;
		}
		int getLength()
		{
			return length;
		}
		void setLength(int l)
		{
			length = l;
		}
		//指定位置插入一个顺序串 
		void Insert(SqString s, int pos)
		{
			if (pos < 0 || pos > length || pos+s.getLength() > MAX)
			{
				cout << "插入失败！" << endl;
				return ; 
			}
			char tempdata[MAX];
			for (int i = pos,j = 0; i < length; i++,j++) //长度比下标多一
				tempdata[j] = data[i];
			for (int i = pos, j = 0; j < s.getLength(); i++, j++)
				data[i] =  s.getData()[j];
			for (int i = pos + s.getLength(), j = 0; j < length - pos; i++, j++)
				data[i] = tempdata[j];
			length = length + s.getLength();
		}
		// 查找指定字符串首次出现位置  
		int Search(SqString s)   // 字符串匹配bf算法 
		{
			if (s.getLength() > length)
			{
				cout << "这个串太长啦！" << endl;
				return -1; 
			}
			char *temp = s.getData();
			int i = 0, j = 0;
			while (i < length ) // && j < s.getLength()'
			{
				if (data[i] == temp[j] && j < s.getLength())
				{
					i++;
					j++;
				}
				else
				{
					i = i - j + 1; //
					j = 0;
				}
				if (j == s.getLength())
					return i - s.getLength();
			}
			cout << "没有出现过哦" << endl; 
			return -1;
		}
		// 获取从i开始 ,长度为length的子串 
		SqString getSub(int i, int length) 
		{
			if (i < 0 || i + length > this->length)  // 不是用 . ?? 
			{
				cout << "长度超啦！";
				return *this; // 非法返回自身 
			}
			SqString temp;
			for (int j = i, k = 0; j <= length; j++, k++)
			{
				temp.getData()[k] = data[j];
			}
			temp.setLength(length);
			return temp;
		} 
		// 重载 == 
		bool operator==(SqString s)
		{
			return (this->data == s.getData() && this->length == s.getLength());
		}
		// 将顺序串从i开始的长度为 length的子串用 新字符串 s代替 
		void Replace (SqString s, int i,int len)  // 
		{
			if (getSub(i,len) == *this)  // 此处需要重载 == 运算符 
			{
				cout << "输入有误，请重新输入";
				return ; 
			} 
			for (int j = i; j + len < length; j++)  //把要目标子串删除 
			{
				data[j] = data[j+len];
			}
			length = length - len;// 这里容易忘记，忽略的长度的更新 
			Insert(s,i);    // 把 要替换的子串在i处插入 
		} 
		// 删除从第pos个位置起的长度为len的子串 
		void Remove(int pos, int len)
		{
			if (pos < 0 || pos + len > length)
			{
				cout << "输入错误哦" << endl;
				return ;
			}
			for (int i = pos; i + len < length; i++)
				data[i] = data[i+len];
			length = length - len;
		}
		// 重载删除方法，删除s子串 
		void Remove(SqString s)
		{
			int pos = Search(s);
			if (pos == -1)
			{
				cout << "没有这个子串删除不了哦" << endl;
				return ;
			}
			Remove(pos, s.getLength());
		} 
		//打印信息 
		void print ()
		{
			for (int i = 0; i < length; i++)
			{
				cout << data[i];
			}
			cout << endl;
		}
};
int main ()
{
	char str[MAX],str2[MAX],str3[MAX],str4[MAX];
	cout << "请输入你要操作的字符串文本哦" << endl;
	gets(str);
	cout << "这是您刚刚输入的字符串哦" << endl;
	SqString s(str);
	s.print(); 
	
	cout << "请输入您要插入的字符串：" << endl;
	gets(str2);
	cout << "请输入您要插入的位置~" <<endl;
	int pos;
	cin >> pos;
	SqString s2(str2);
	s.Insert(s2, pos);
	cout << "现在的字符串是这样的呢" << endl;
	s.print();
	
	cout << endl;
	
	cout << "请输入您要查询的字符串哦" << endl;
	gets(str3);
	cin >> str3;
	SqString s3(str3);
	pos = s.Search(s3);
	if (pos == -1)
		cout << "查询失败" <<endl;
	else
		cout << "找到啦，它出现的位置是： " << pos <<endl;
	
	cout << endl;
	
	cout << "请输入您要删除的子串~" <<endl;
	getchar();
	gets(str4);
	SqString s4(str4);
	s.Remove(s4);
	cout << "删除后的串是：" << endl;
	s.print();
	
	cout << endl;
	
	cout << "换一种删除方式啦 " << "请输入您要删除的子串的位置" << endl;
	int x,l;
	cin >> x;
	cout << "请输入要删除的长度："<<endl;
	cin >> l;
	s.Remove(x, l);
	cout << "删除后：" << endl;
	s.print(); 
	 
	return 0;
}
