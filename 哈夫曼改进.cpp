#include <iostream>
#include <algorithm>
#include <string>
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
hfnode *nodes[max];  // 节点数组 
bool cmp(hfnode* a, hfnode* b)
{
	return a->num > b->num;  //从大到小排序 
}
int not_zero(int n) // 判断节点数组内权值不为0的节点个数，方便创建哈夫曼树的时候退出循环 
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
		sort(nodes,nodes + n, cmp); // 排序后大的排在前面，这样的话那些为权值为0的或者已经处理了的节点就不会干扰后续 
		int index = not_zero(n) - 1;
		hfnode *node = new hfnode;
		node->num = nodes[index]->num + nodes[index-1]->num;  // 新建合成的节点 
		node->left = nodes[index];  
		node->right = nodes[index-1];
		nodes[n++] = node;  // 合成的节点加入节点数组 
		nodes[index]->num = 0;    // 已经比较完的权值置为零，防止影响后续的比较 
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
		cout << "请输入第" << i+1 << "组字符和权值（中间空格隔开)" << endl;
		cin >>  a >> num;
		hfnode *node = new hfnode;
		node->value = a;
		node->num = num;
		nodes[i] = node;
	}
}
void preTravel(hftree tree) // 测试二叉树是否创建成功 
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
	if (tree->left == NULL && tree->right == NULL) // 从左到右输出叶子节点 
	{
		cout << tree->value << "的编码是：" ; 
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
// 解码 
void de_code(hftree tree) 
{
	string str;
	cout << "请输入上述已经编好的其中一个码(字符串输入无需空格)" << endl;
	cin >> str;
	hfnode *t = tree;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '0')
			t = t->left;
		else if (str[i] == '1')
			t = t->right;
	}
	cout << "该码对应的字符是：" << t->value << endl; 
	 
}
int main ()
{
	hftree hfman;
	int n;// 数字
	cout << "你要输入多少组数据（字符-权值）" << endl;
	cin >> n;
	input(n);
	creat(hfman, n);
	cout << "构成的哈夫曼树的前序遍历的结果是：（'#'号代表合成的节点）" << endl; 
	preTravel(hfman);
	cout << endl << endl; 
	// 哈夫曼编码 
	int a[max];
	int i = 0;
	hfman_code(hfman, a, i);
	//解码 
	cout << endl;
	de_code(hfman);
	
	return 0;
	
}
