#include <iostream>
#include <algorithm>
#define max 1000
using namespace std;
typedef struct node{
	char value;
	int num;
	struct node* left;
	struct node* right;
	node ()
	{
		value = '#';
		left = NULL;
		right = NULL;
		num = 0;
	}
}hfnode, *hftree;
hfnode *nodes[max];  // �ڵ����� 
bool cmp(hfnode* a, hfnode* b)
{
	return a->num > b->num;  //�Ӵ�С���� 
}
int not_zero(int n) // �жϽڵ�������Ȩֵ��Ϊ0�Ľڵ���������㴴������������ʱ���˳�ѭ�� 
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (nodes[i]->num != 0)
			count++;
	}
	return count;
}
void creat( hftree &tree, int &n)
{
	while (not_zero(n) > 1) // 
	{
		sort(nodes,nodes + n, cmp); // �����������ǰ�棬�����Ļ���ЩΪȨֵΪ0�Ļ����Ѿ������˵Ľڵ�Ͳ�����ź��� 
		int index = not_zero(n) - 1;
		hfnode *node = new hfnode;
		node->num = nodes[index]->num + nodes[index-1]->num;  // �½��ϳɵĽڵ� 
		node->left = nodes[index];  
		node->right = nodes[index-1];
		nodes[n++] = node;  // �ϳɵĽڵ����ڵ����� 
		nodes[index]->num = 0;    // �Ѿ��Ƚ����Ȩֵ��Ϊ�㣬��ֹӰ������ıȽ� 
		nodes[index-1]->num = 0;		 
	}
	sort(nodes, nodes + n, cmp);
	tree = nodes[0];
}
void input(int n)
{
	char a;
	int num;
	for (int i = 0; i < n; i++)
	{
		cout << "�������" << i+1 << "���ַ���Ȩֵ���м�ո����)" << endl;
		cin >>  a >> num;
		hfnode *node = new hfnode;
		node->value = a;
		node->num = num;
		nodes[i] = node;
	}
}
void preTravel(hftree tree) // ���Զ������Ƿ񴴽��ɹ� 
{
	if (tree != NULL)
	{
		cout << tree->value;
		preTravel(tree->left);
		preTravel(tree->right);
	}
}
void hfman_code(hftree tree,int a[],int i)
{
	if (tree->left == NULL && tree->right == NULL) // ���������Ҷ�ӽڵ� 
	{
		cout << tree->value << "�ı����ǣ�" ; 
		for(int j = 0; j < i; j++)
		{
			cout << a[j] << " ";
		} 
		cout << endl;
		return;
	}
	if (tree->left != NULL)
		a[i] = 0;
	hfman_code(tree->left, a, i+1);
	if (tree->right != NULL)
		a[i] = 1;
	hfman_code(tree->right, a, i+1);
	
} 
int main ()
{
	hftree hfman;
	int n;// ����
	cout << "��Ҫ������������ݣ��ַ�-Ȩֵ��" << endl;
	cin >> n;
	input(n);
	creat(hfman, n);
	cout << "���ɵĹ���������ǰ������Ľ���ǣ���'#'�Ŵ���ϳɵĽڵ㣩" << endl; 
	preTravel(hfman);
	cout << endl << endl; 
	// ���������� 
	int a[max];
	int i = 0;
	hfman_code(hfman, a, i);
	
	return 0;
	
}
