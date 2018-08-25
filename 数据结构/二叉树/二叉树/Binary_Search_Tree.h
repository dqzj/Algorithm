#pragma once
#ifndef _BINARY_SEARCH_TREE_H_
#define MAXSIGN  10000
#include"Binary_tree.h"

//��������������Ľڵ�
void Insert_Search_Tree(BiTree &T,int Value)
{
	BiTree temp = (BiTree)malloc(sizeof(BiTNode));
	temp->data = Value;
	temp->lchild = temp->rchild = NULL;	
	if (T->data==MAXSIGN)
	{
		T->data = temp->data;
		return;
	}
	while (true)
	{
		if ((T->data > Value))
		{
			if (T->lchild == NULL)
			{
				T->lchild = temp;
				return;
			}
			else
				T = T->lchild;
		}
		else
		{
			if (T->rchild == NULL)
			{
				T->rchild = temp;
				return;
			}
			else
				T = T->rchild;
		}
	}

}

//�ڶ����������в���
BiTree Search_Tree(BiTree T,int Value)
{
	while (true)
	{
		if (T->data == Value)
			return T;
		else
		{
			if ((T->data > Value))
				T = T->lchild;
			else
				T = T->rchild;
		}
	}
	return NULL;
}

//���ص�ǰ���������������ֵ
BiTree Max_tree(BiTree T)
{
	while (T->rchild != NULL)
		T = T->rchild;
	return T;
}
//���ص�ǰ��������������Сֵ
BiTree Min_tree(BiTree T)
{
	while (T->lchild != NULL)
		T = T->lchild;
	return T;
}

//�Ӷ�����������ɾ��ĳ���ڵ�
void Delete_S_Node(BiTree &T, int Value)
{
	BiTree temp,parent;
	temp=Search_Tree(T, Value);
	parent = Parent(T, Value);
	if (temp->lchild == NULL&&temp->rchild==NULL)
	{
		parent->lchild = parent->rchild = NULL;
		free(temp);
		temp = NULL;
	}
	else if (temp->lchild == NULL)
	{
		if (parent->lchild->data == temp->data)
			parent->lchild = temp->rchild;
		else
			parent->rchild = temp->rchild;
		free(temp);
		temp = NULL;
	}
	else if (temp->rchild == NULL)
	{
		if (parent->lchild->data == temp->data)
			parent->lchild = temp->lchild;
		else
			parent->rchild = temp->lchild;
		free(temp);
		temp = NULL;
	}
	else
	{
		BiTree mintemp,min_parent;
		mintemp = Min_tree(temp->rchild);
		if (mintemp->data != temp->rchild->data)
		{
			min_parent = Parent(temp->rchild, mintemp->data);
			min_parent->lchild = mintemp->rchild;
			mintemp->rchild = temp->rchild;
		}
		mintemp->lchild = temp->lchild;
		if (parent->lchild->data == temp->data)
			parent->lchild = mintemp;
		else
			parent->rchild = mintemp;
		free(temp);
		temp = NULL;
	}
}



#endif // !_BINARY_SEARCH_TREE_H_


