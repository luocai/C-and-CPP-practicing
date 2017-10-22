#include <stdio.h>
#include <stdlib.h> 
typedef struct node {
	int data;
	struct node* next;
}Node;
void sort (int a[], int n)
{
	int temp;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i] < a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}
void creatlinklist(Node* &list,int a[], int n)
{
	Node* p = list;
	for (int i = 0; i < n; i++)
	{
		Node *newnode = (Node*) malloc (sizeof (Node));
		newnode->data = a[i];
		newnode->next = NULL;
		p->next = newnode;
		p = newnode;
	}
} 

//插入 
void insert (Node* &list, int x)
{
	Node *p = list;
	while (p && x >= p->next->data)
	{
		p = p->next;
	}
	if (p == NULL)
	{
		printf ("你输入的数不存在\n");
	}
	else
	{
		Node *newnode = (Node*) malloc(sizeof(Node));
		newnode->data = x;
		newnode->next = p->next;
		p->next = newnode;
	}
}
void print (Node *list)
{
	Node *p = list->next;
	while (p)
	{
		printf ("%d ", p->data);
		p = p->next;
	}
	printf ("\n");
}

//原地转置 
void reverse(Node *&list)
{
	Node *p, *q;
	p = list;
	q = list->next;
	list->next = NULL;
	while(q)
	{
		p = q;
		q = q->next;
		p->next = list->next;
		list->next = p;
	} 
}
int main ()
{
	int a[10] = {1,2,5,9,6,8,3,4,7,10};
	Node *list = (Node*) malloc (sizeof (Node));
	list->next = NULL;
	sort (a, 10);
//	for (int i = 0; i < 10; i++)
//	{
//		printf ("%d ", a[i]);
//	}
	creatlinklist(list, a, 10);
	print (list);
	
	insert(list, 5);
	print(list);
	
	reverse (list);
	print (list);
	return 0;
}
