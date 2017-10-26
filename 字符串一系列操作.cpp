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
		//�ַ���������ʼ�� 
		SqString(char str[])
		{
		//	cout << strlen(str) << endl;
			for (int i = 0; i < strlen(str);i++) // �˴��Ǹ��ӣ�һ��ʼ�õ�sizeof  ˼�������鴫���˻�Ϊָ������� 
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
		//ָ��λ�ò���һ��˳�� 
		void Insert(SqString s, int pos)
		{
			if (pos < 0 || pos > length || pos+s.getLength() > MAX)
			{
				cout << "����ʧ�ܣ�" << endl;
				return ; 
			}
			char tempdata[MAX];
			for (int i = pos,j = 0; i < length; i++,j++) //���ȱ��±��һ
				tempdata[j] = data[i];
			for (int i = pos, j = 0; j < s.getLength(); i++, j++)
				data[i] =  s.getData()[j];
			for (int i = pos + s.getLength(), j = 0; j < length - pos; i++, j++)
				data[i] = tempdata[j];
			length = length + s.getLength();
		}
		// ����ָ���ַ����״γ���λ��  
		int Search(SqString s)   // �ַ���ƥ��bf�㷨 
		{
			if (s.getLength() > length)
			{
				cout << "�����̫������" << endl;
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
			cout << "û�г��ֹ�Ŷ" << endl; 
			return -1;
		}
		// ��ȡ��i��ʼ ,����Ϊlength���Ӵ� 
		SqString getSub(int i, int length) 
		{
			if (i < 0 || i + length > this->length)  // ������ . ?? 
			{
				cout << "���ȳ�����";
				return *this; // �Ƿ��������� 
			}
			SqString temp;
			for (int j = i, k = 0; j <= length; j++, k++)
			{
				temp.getData()[k] = data[j];
			}
			temp.setLength(length);
			return temp;
		} 
		// ���� == 
		bool operator==(SqString s)
		{
			return (this->data == s.getData() && this->length == s.getLength());
		}
		// ��˳�򴮴�i��ʼ�ĳ���Ϊ length���Ӵ��� ���ַ��� s���� 
		void Replace (SqString s, int i,int len)  // 
		{
			if (getSub(i,len) == *this)  // �˴���Ҫ���� == ����� 
			{
				cout << "������������������";
				return ; 
			} 
			for (int j = i; j + len < length; j++)  //��ҪĿ���Ӵ�ɾ�� 
			{
				data[j] = data[j+len];
			}
			length = length - len;// �����������ǣ����Եĳ��ȵĸ��� 
			Insert(s,i);    // �� Ҫ�滻���Ӵ���i������ 
		} 
		// ɾ���ӵ�pos��λ����ĳ���Ϊlen���Ӵ� 
		void Remove(int pos, int len)
		{
			if (pos < 0 || pos + len > length)
			{
				cout << "�������Ŷ" << endl;
				return ;
			}
			for (int i = pos; i + len < length; i++)
				data[i] = data[i+len];
			length = length - len;
		}
		// ����ɾ��������ɾ��s�Ӵ� 
		void Remove(SqString s)
		{
			int pos = Search(s);
			if (pos == -1)
			{
				cout << "û������Ӵ�ɾ������Ŷ" << endl;
				return ;
			}
			Remove(pos, s.getLength());
		} 
		//��ӡ��Ϣ 
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
	cout << "��������Ҫ�������ַ����ı�Ŷ" << endl;
	gets(str);
	cout << "�������ո�������ַ���Ŷ" << endl;
	SqString s(str);
	s.print(); 
	
	cout << "��������Ҫ������ַ�����" << endl;
	gets(str2);
	cout << "��������Ҫ�����λ��~" <<endl;
	int pos;
	cin >> pos;
	SqString s2(str2);
	s.Insert(s2, pos);
	cout << "���ڵ��ַ�������������" << endl;
	s.print();
	
	cout << endl;
	
	cout << "��������Ҫ��ѯ���ַ���Ŷ" << endl;
	gets(str3);
	cin >> str3;
	SqString s3(str3);
	pos = s.Search(s3);
	if (pos == -1)
		cout << "��ѯʧ��" <<endl;
	else
		cout << "�ҵ����������ֵ�λ���ǣ� " << pos <<endl;
	
	cout << endl;
	
	cout << "��������Ҫɾ�����Ӵ�~" <<endl;
	getchar();
	gets(str4);
	SqString s4(str4);
	s.Remove(s4);
	cout << "ɾ����Ĵ��ǣ�" << endl;
	s.print();
	
	cout << endl;
	
	cout << "��һ��ɾ����ʽ�� " << "��������Ҫɾ�����Ӵ���λ��" << endl;
	int x,l;
	cin >> x;
	cout << "������Ҫɾ���ĳ��ȣ�"<<endl;
	cin >> l;
	s.Remove(x, l);
	cout << "ɾ����" << endl;
	s.print(); 
	 
	return 0;
}
