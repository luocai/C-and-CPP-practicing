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
			cout << "��������Ҫ�����Ķ�����(���򴴽�)��'#' Ϊ�գ��������� a b # # c # # ��ǰ������Ľ���� a b c" << endl; 
			cout << "������ a b c # # d # # e f # # g # # ��ǰ������Ľ���� a b c d e f g" << endl; 
			tree = init();
		}
		node* root()
		{
			return tree;
		} 
		node* init() // ǰ�򴴽�һ�Ŷ����� 
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
//		void creat(node*& tree)   // Ϊ�����ַ������У� 
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
				return 0;    //�ݹ���� 
			else
				return nodeCount(tree->left) + nodeCount(tree->right) + 1;
		}
		int yzCount(node *tree) 
		{
			if (tree == NULL)
				return 1;  // �ݹ���� 
			else
				return yzCount(tree->left) + yzCount(tree->right); 
		}
		
}; 
int main ()
{
	btree Tree;
	cout << "ǰ������Ľ���ǣ�" << endl;
	Tree.preTravel(Tree.root());
	cout << endl;
	cout << "�ܵĽڵ�����:" ;
	cout << Tree.nodeCount(Tree.root()) << endl;
	cout << "Ҷ�ӽڵ�����У�" ;
	cout << Tree.yzCount(Tree.root()); 
	
	return 0;
}
