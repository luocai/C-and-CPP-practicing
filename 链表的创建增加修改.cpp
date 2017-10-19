#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
typedef struct node{
	int data;
	struct node* next;
}Node;
void print (Node *list)
{
	Node *p = list->next;
	if (!p)
	{
		cout << "����Ϊ��" <<endl;
		return ;
	}
	else
		cout << "�������Ԫ��Ϊ:" << endl; 
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
void creatLinklist(Node* &list,int n)
{
	srand((unsigned)time(NULL)); //  ����� 
	Node *p = list;
	for (int i = 0; i < n; i++)
	{
		Node *newnode = new Node;
		newnode->data = rand() % 10;
		newnode->next = NULL;
		p->next = newnode;
		p = newnode;
	}
	print(list);
} 
void insert (Node* &list, int x, int pos)
{
	if (list == NULL)
		return ;
	Node* p = list;
	int i = 0;
	while (p && i != pos)
	{
		p = p->next;
		i++;
	}
	
	if (p == NULL)
		return;
	else
	{
		Node* newnode = new Node;
		newnode->data = x;
		newnode->next = p->next;
		p->next = newnode;
	} 
}
void remove (Node* &list, int x)
{
	bool flag = false;
	Node *p = list, *q = list->next;
	while (q != NULL)
	{
//		cout << q->data; 
		if (q->data == x)
		{
			flag = true;
			Node *temp = q;
			p->next = q->next;
			q = p->next;
			delete temp;
			continue;
		}
		p = p->next;
		q = q->next;
	}
	if (flag == false)
		cout << "�����в��������������" <<endl;
	else
	{
		cout << "ɾ���������Ϊ��" << endl;
		print (list); 
	} 
	
}

int main ()
{
	Node *list = new Node;
	list->next = NULL;
	int n;
	cout << "��������������ĳ��ȣ�" << endl;
	cin >> n;
	creatLinklist (list, n);
	int x, pos;
	cout << "������Ҫ�����Ԫ��:" ;
	cin >> x ;
	cout << "������Ҫ�����λ�ã�";
	cin >> pos; 
	insert (list, x, pos);
	print(list);
	int y;
	cout << "��������Ҫɾ����Ԫ�أ�";
	cin >> y;
	remove (list, y);
	
	return 0;
	
}
