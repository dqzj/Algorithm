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
	cout << "树深：" << BiTreeDepth(Head) << endl;
	ClearBiTree(T);
	PreOrderTraverse(Head);
	cout << endl;
	cout << "树深：" << BiTreeDepth(Head) << endl;

	test= LeftSibling(Head, 5);
	if (test != NULL)
		LevelOrderTraverse(test);
	else
		cout << "节点不存在！" << endl;
}