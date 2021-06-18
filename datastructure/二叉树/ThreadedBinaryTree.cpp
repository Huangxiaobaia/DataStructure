#define _CRT_SECURE_NO_WARNINGS 1
#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define CHUNKSIZE 80
#define MAXLEN 255
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
typedef int Status;
typedef struct BiThrNode
{
	char data;
	BiThrNode* lchild, * rchild;
	int LTag, RTag;
}BiThrNode,*BiThrTree;
BiThrTree pre;
void CreateBiThrTree(BiThrTree& T)
{//先序构造线索二叉树
	char ch;
	cin >> ch;
	if (ch == '#')
		T = NULL;
	else
	{
		T = new BiThrNode;
		if (!T)
			exit(OVERFLOW);
		T->data = ch;
		CreateBiThrTree(T->lchild);
		if (T->lchild)
			T->LTag = 0;
		CreateBiThrTree(T->rchild);
		if (T->rchild)
			T->RTag = 0;
	}
}
void InThreading(const BiThrTree& p)
{//以结点p为根的子树中序线索化
	if (p != NULL)
	{
		InThreading(p->lchild);//左子树递归线索化
		if (!p->lchild)
		{
			p->LTag = 1;
			p->lchild = pre;
		}
		else
			p->LTag = 0;
		if (!pre->rchild)
		{
			pre->RTag = 1;
			pre->rchild = p;
		}
		else
			pre->RTag = 0;
		pre = p;
		InThreading(p->rchild);
	}
}
void InOrderThreading(BiThrTree& Thrt,BiThrTree& T)
{//中序遍历二叉树T，并将其中序线索化，Thrt指向头结点
	Thrt = new BiThrNode;
	Thrt->LTag = 0;
	Thrt->RTag = 1;
	Thrt->rchild = Thrt;
	if (!T)
		Thrt->lchild = Thrt;
	else
	{
		Thrt->lchild = T;
		pre = Thrt;
		InThreading(T);
		pre->rchild = Thrt;
		pre->RTag = 1;
		Thrt->rchild = pre;
	}
}
void InOrderTraverse_Thr(const BiThrTree& T)
{//T指向头结点
	BiThrNode* p;
	p = T->lchild;
	while (p != T)
	{
		while (p->LTag == 0)
			p = p->lchild;
		cout << p->data;
		while (p->RTag == 1 && p->rchild != T)
		{//当前结点没有右子树，找后继 
			p = p->rchild;
			cout << p->data;
		}
		//若当前结点有右子树，指向其右子树再循环
		p = p->rchild;
	}
}
int main()
{
	BiThrTree H, T;
	cout << "按照先序的次序输入二叉树：" << endl;
	CreateBiThrTree(T);
	InOrderThreading(H, T);
	cout << "中序遍历线索二叉树：" << endl;
	InOrderTraverse_Thr(H);
	return 0;
}
