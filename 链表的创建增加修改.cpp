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
		cout << "链表为空" <<endl;
		return ;
	}
	else
		cout << "链表里的元素为:" << endl; 
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
void creatLinklist(Node* &list,int n)
{
	srand((unsigned)time(NULL)); //  随机数 
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
		cout << "链表中不存在你输入的数" <<endl;
	else
	{
		cout << "删除后的链表为：" << endl;
		print (list); 
	} 
	
}

int main ()
{
	Node *list = new Node;
	list->next = NULL;
	int n;
	cout << "请输入生成链表的长度：" << endl;
	cin >> n;
	creatLinklist (list, n);
	int x, pos;
	cout << "请输入要插入的元素:" ;
	cin >> x ;
	cout << "请输入要插入的位置：";
	cin >> pos; 
	insert (list, x, pos);
	print(list);
	int y;
	cout << "请输入你要删除的元素：";
	cin >> y;
	remove (list, y);
	
	return 0;
	
}
