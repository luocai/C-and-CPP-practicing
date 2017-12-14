#include <iostream>
#include <vector>
#include <queue>
#define max 1000
using namespace std;
typedef struct node{
	char data;
	bool head; 
	struct node* next;
	node(){
		data = '#';
		next = NULL;
		head = 0;
	}
}Node;
vector<Node*> garph; // ͼ 
int inDegree[max] = {0}; //�ڵ�Ķ� 
int ege = 0; 
// ���ڽӱ�洢 ������Ϊ���ѵĵط��� 
void creatGarph()
{
	char start, end;
	cout << "��������Ҫ������ͼ�ı���" << endl;
	cin >> ege;
	for (int i = 0; i < ege; i ++)
	{
		bool flag1 = 0, flag2 = 0;
		int k = 0;
		cout << "�������" << i + 1<< "���ߣ�����ʼ�� �յ����ʽ���룩" << endl;
		cin >> start >> end; 
		for (int j = 0; j < garph.size(); j++)
		{
			if (garph[j]->data == start)
			{
				flag1 = 1;  
			}
			if (garph[j]->data == end)
			{
				flag2 = 1;
			}
		}
		if (flag1 == 0) // ��ʾ��ͷ�л�û������ڵ㣬���½�һ����ͷ�ڵ� 
		{
			Node *n_node1 = new Node;
			n_node1->data = start;
			n_node1->head = 1;// ��ʶ���Ǳ�ͷ�ڵ� 
			garph.push_back(n_node1);
		}
		
		if (flag2 == 0) // ������δ���ֹ��ĵ㣬�����ͷ�� 
		{
			Node *n_node3 = new Node;
			n_node3->data = end;
			n_node3->head = 1;
			garph.push_back(n_node3);
		}
		
		Node *n_node2 = new Node;
		n_node2->data = end;
		//������� 
		for (int j = 0; j < garph.size(); j++)
		{
			if (garph[j]->data == end)
				inDegree[j]++;
		} 
		
		for(int j = 0; j < garph.size(); j++)  // ���յ���� 
		{
			if (garph[j]->data == start)
			{
				Node *temp = garph[j];
				while (temp->next)
				{
					temp = temp->next;
				}
				temp->next = n_node2;
			}
		}
//		int m, n;   // һ��ʼ���뷨 
//		for (int j = 0; j < garph.size(); j++)
//		{
//			if (garph[j]->data == start)
//			{
//				m = j;
//			}
//			if (garph[j]->data == end) 
//			{
//				n = j;
//			}
//		}
	} 
}
// ��ӡ�ڽӱ� 
void print()
{
	cout << "��ͼ���ڽӱ����£�����һ���Ǳ�ͷ�ڵ㣩" << endl << endl; 
	for (int i = 0; i < garph.size(); i++)
	{
		Node* p = garph[i];
		while (p)
		{
			cout << p->data << "->";
			p = p->next;
		}
		cout << "#" << endl;
	}
}
//������������ 
void topuSort()
{
	cout << "��������������" << endl; 
	queue<Node*> q; // �ö��������д洢�������Ϊ0�Ľڵ����η�������У��ȷ������ȡ�� 
	for (int i = 0; i < garph.size(); i++)
	{
		if (inDegree[i] == 0)
			q.push(garph[i]); 
	}
	while (!q.empty())
	{
		Node *temp = q.front();
		for (int i = 0; i < garph.size(); i++)
			if (temp->data == garph[i]->data)
			{
				temp = garph[i];  // �����ֵ��ͷ�ڵ���� �������׸���� 
				break;
			}
		cout << temp->data << " ";
		q.pop();
		while (temp->next)  // �Գ�ջ�Ľڵ�������յ���в��� 
		{
			Node* v = temp->next;
			for (int i = 0 ; i < garph.size(); i++)
				if (v->data == garph[i]->data)
				{
					inDegree[i]--; // ��ȼ�һ�������Ϊ0ʱ���� 
					if (inDegree[i] == 0)
						q.push(v);
				}	
			temp = temp->next;
		}
	}
} 
int main ()
{
	creatGarph();
	print();
	
	topuSort();
	
	return 0;
}
