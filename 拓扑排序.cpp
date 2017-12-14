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
vector<Node*> garph; // 图 
int inDegree[max] = {0}; //节点的度 
int ege = 0; 
// 用邻接表存储 （我认为最难的地方） 
void creatGarph()
{
	char start, end;
	cout << "请输入您要构建的图的边数" << endl;
	cin >> ege;
	for (int i = 0; i < ege; i ++)
	{
		bool flag1 = 0, flag2 = 0;
		int k = 0;
		cout << "请输入第" << i + 1<< "条边（以起始点 终点的形式输入）" << endl;
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
		if (flag1 == 0) // 表示表头中还没用这个节点，接新建一个表头节点 
		{
			Node *n_node1 = new Node;
			n_node1->data = start;
			n_node1->head = 1;// 标识它是表头节点 
			garph.push_back(n_node1);
		}
		
		if (flag2 == 0) // 出现了未出现过的点，放入表头中 
		{
			Node *n_node3 = new Node;
			n_node3->data = end;
			n_node3->head = 1;
			garph.push_back(n_node3);
		}
		
		Node *n_node2 = new Node;
		n_node2->data = end;
		//更新入度 
		for (int j = 0; j < garph.size(); j++)
		{
			if (garph[j]->data == end)
				inDegree[j]++;
		} 
		
		for(int j = 0; j < garph.size(); j++)  // 把终点加入 
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
//		int m, n;   // 一开始的想法 
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
// 打印邻接表 
void print()
{
	cout << "该图的邻接表如下：（第一列是表头节点）" << endl << endl; 
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
//进行拓扑排序 
void topuSort()
{
	cout << "拓扑排序结果如下" << endl; 
	queue<Node*> q; // 用队列来进行存储，把入度为0的节点依次放入队列中，先放入的先取出 
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
				temp = garph[i];  // 用其等值表头节点替代 （很容易搞错！） 
				break;
			}
		cout << temp->data << " ";
		q.pop();
		while (temp->next)  // 对出栈的节点的所有终点进行操作 
		{
			Node* v = temp->next;
			for (int i = 0 ; i < garph.size(); i++)
				if (v->data == garph[i]->data)
				{
					inDegree[i]--; // 入度减一，当入度为0时进队 
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
