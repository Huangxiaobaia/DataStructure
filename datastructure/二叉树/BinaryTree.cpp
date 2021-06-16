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
typedef struct BiTNode {
	char data;
	struct BiTNode* lchild, * rchild;
}BiTNode,*BiTree;
typedef struct StackNode {
	BiTNode* data;
	StackNode* next;
}StackNode,*LinkStack;
Status InitStack(LinkStack& S)
{
	S = NULL;
	return OK;
}
bool StackEmpty(const LinkStack& S)
{
	if (S == NULL)
		return true;
	else
		return false;
}
Status Push(LinkStack& S, BiTNode* p)
{
	StackNode* newnode = new StackNode;
	newnode->data = p;
	newnode->next = S;
	S = newnode;
	return OK;
}
Status Pop(LinkStack& S, BiTNode* q)
{
	StackNode* tmps;
	q= S->data;
	tmps = S;
	S = S->next;
	delete tmps;
	return OK;
}
void InOrderTraverse(BiTree T)
{//中序遍历二叉树T的递归算法
	if (T)
	{
		InOrderTraverse(T->lchild);
		cout << T->data;
		InOrderTraverse(T->rchild);
	}
}
void InOrderTraverse1(BiTree T)
{//中序遍历非递归算法
	LinkStack S;
	InitStack(S);
	BiTNode* p = T;
	BiTNode* q = new BiTNode;
	while (p || StackEmpty(S))
	{
		if (p)
		{
			Push(S, p);
			p = p->lchild;
		}
		else
		{
			Pop(S, q);
			cout << q->data;
			p = q->rchild;
		}
	}
}
void CreateBiTree(BiTree& T)
{//先序输入
	char ch;
	cin >> ch;
	if (ch == '#')T = NULL;
	else
	{
		T = new BiTNode;
		T->data = ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}

}
void Copy(const BiTree& T, BiTree& NewT)
{
	if (T == NULL)
	{
		NewT = NULL;
		return;
	}
	else
	{
		NewT = new BiTNode;
		NewT->data = T->data;
		Copy(T->lchild, NewT->lchild);
		Copy(T->lchild, NewT->rchild);
	}
}
int Depth(const BiTree& T)
{
	int m = 0, n = 0;
	if (T == NULL)
		return 0;
	else
	{
		m = Depth(T->lchild);
		n = Depth(T->rchild);
		if (m > n)return (m + 1);
		return (n + 1);
	}
}
int NodeCount(const BiTree& T)
{
	if (T == NULL)
		return 0;
	else
	{
		return NodeCount(T->lchild) + NodeCount(T->rchild) + 1;
	}
}
int main()
{
	BiTree T;
	CreateBiTree(T);
	return 0;
}