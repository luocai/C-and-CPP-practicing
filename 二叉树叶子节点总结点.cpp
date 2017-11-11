#include <iostream>
using namespace std;
typedef struct btnode{
	char data;
	struct btnode* left;
	struct btnode* right;
}node;
class btree {
	private :
		node* tree;
//		int node_cnt;
	public :
		btree ()
		{
			cout << "请输入您要创建的二叉树(先序创建)，'#' 为空，例如输入 a b # # c # # 则前序遍历的结果是 a b c" << endl; 
			cout << "如输入 a b c # # d # # e f # # g # # 则前序遍历的结果是 a b c d e f g" << endl; 
			tree = init();
		}
		node* root()
		{
			return tree;
		} 
		node* init() // 前序创建一颗二叉树 
		{
			char ch;
			node *bnode = new node;
			cin >> ch;
			if (ch == '#')
				bnode = NULL;
			else
			{
				bnode->data = ch;
				bnode->left = init();
				bnode->right = init();
			}
			return bnode;		 
		}
//		void creat(node*& tree)   // 为何这种方法不行？ 
//		{
//			char ch;
//			node *bnode = new node;
//			cin >> ch;
//			if (ch == '#')
//				return;
//			else
//			{
//				bnode->data = ch;
//				bnode->left = NULL;
//				bnode->right = NULL;
//				tree = bnode;
//				creat(tree->left);
//				creat(tree->right);
//			}
//		}
		void preTravel(node *tree)
		{
			if (tree == NULL)
				return;
			cout << tree->data << " ";
			preTravel(tree->left);
			preTravel(tree->right);
			
		}
		int nodeCount(node *tree)
		{
			if (tree == NULL)
				return 0;    //递归出口 
			else
				return nodeCount(tree->left) + nodeCount(tree->right) + 1;
		}
		int yzCount(node *tree) 
		{
			if (tree == NULL)
				return 1;  // 递归出口 
			else
				return yzCount(tree->left) + yzCount(tree->right); 
		}
		
}; 
int main ()
{
	btree Tree;
	cout << "前序遍历的结果是：" << endl;
	Tree.preTravel(Tree.root());
	cout << endl;
	cout << "总的节点数有:" ;
	cout << Tree.nodeCount(Tree.root()) << endl;
	cout << "叶子节点个数有：" ;
	cout << Tree.yzCount(Tree.root()); 
	
	return 0;
}
