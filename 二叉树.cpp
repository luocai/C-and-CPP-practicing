#include <iostream>
#include <cstring>
#include <stack>
using namespace std;
typedef struct node{
	char data;
	struct node* left;
	struct node* right;
}btnode;
void creatTree(btnode *&tree)
{
	char ch;
	cin >> ch;
	if (ch == '#')
	{
		tree = NULL;
		return ;
	}		
	else
	{
		btnode *Node = new btnode;
		Node->left = NULL;
		Node->right = NULL;
		Node->data = ch;
		tree = Node;
	}
	creatTree(tree->left);
	creatTree(tree->right);
}
/*void creatTree2(btnode *& tree,int index, char ch[])
{
/*	if (ch[index] == '#')
	{
		tree = NULL;

		return ; 
	}
	else
	{
		btnode *Node = new btnode;    //char ch[] = {'a','b','c','d','#','#','#','e','#','#','f','g','#','#','h','#','#'};
		Node->data = ch[index];
		Node->left = NULL;
		Node->right = NULL;
		tree = Node;
	
	}
	creatTree2(tree->left ,index+1, ch);
	creatTree2(tree->right, index+1, ch);	*/
/*	for (int i = 0; i < strlen(ch); i++)
	{
		stack<btnode*> s;
		if (ch[i] == '#' && s.size() != 0)
		{
			tree = NULL;
		}
		else
		{
			btnode *Node = new btnode;
			Node->data = ch[i];
			Node->left = NULL;
			Node->right = NULL;
			tree = Node;
			s.push(tree);
		}
	}	
}*/
void preTravel(btnode *tree)
{
	if (tree == NULL)
		return;
	cout << tree->data << " ";
	preTravel(tree->left);
	preTravel(tree->right);
}
void preTravel2(btnode *tree)
{
	stack<btnode*> s;
	btnode *p;
	if (tree != NULL)
	{
		s.push(tree);
		while (s.empty() != 1)
		{
			p = s.top();
			s.pop();
			cout << p->data << " ";
			if (p->right != NULL)
				s.push(p->right);
			if (p->left != NULL)
				s.push(p->left);
		}
		cout << endl;
	}
}
void midTravel(btnode *tree)
{
	if (tree == NULL)
		return ;
	midTravel(tree->left);
	cout << tree->data << " ";
	midTravel(tree->right);
}
void aftTravel(btnode *tree)
{
	if (tree == NULL)
		return;
	aftTravel(tree->left);
	aftTravel(tree->right);
	cout << tree->data << " ";
}
int main ()
{
	char ch[] = {'a','b','c','d','#','#','#','e','#','#','f','g','#','#','h','#','#'};
	btnode *btree = new btnode;
	creatTree(btree);
	preTravel2(btree);
	
	return 0;
}
