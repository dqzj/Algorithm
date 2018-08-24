#include"Binary_tree.h"
int main()
{
	BiTree Head,T,test;
	CreateBiTree(T);
	int count = 10;
	T->data = 10;
	Head = T;
	while (count--)
	{
		while (InsertChild(T, count) == -1)
		{
			T = T->lchild;
		} 
	}
	
	DeleteChild(T->rchild);
	PreOrderTraverse(Head);
	cout << endl;
	LevelOrderTraverse(Head);
	cout << "���" << BiTreeDepth(Head) << endl;
	ClearBiTree(T);
	PreOrderTraverse(Head);
	cout << endl;
	cout << "���" << BiTreeDepth(Head) << endl;

	test= LeftSibling(Head, 5);
	if (test != NULL)
		LevelOrderTraverse(test);
	else
		cout << "�ڵ㲻���ڣ�" << endl;
}