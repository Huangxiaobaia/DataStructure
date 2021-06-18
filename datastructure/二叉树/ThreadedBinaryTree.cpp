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
{//����������������
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
{//�Խ��pΪ������������������
	if (p != NULL)
	{
		InThreading(p->lchild);//�������ݹ�������
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
{//�������������T��������������������Thrtָ��ͷ���
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
{//Tָ��ͷ���
	BiThrNode* p;
	p = T->lchild;
	while (p != T)
	{
		while (p->LTag == 0)
			p = p->lchild;
		cout << p->data;
		while (p->RTag == 1 && p->rchild != T)
		{//��ǰ���û�����������Һ�� 
			p = p->rchild;
			cout << p->data;
		}
		//����ǰ�������������ָ������������ѭ��
		p = p->rchild;
	}
}
int main()
{
	BiThrTree H, T;
	cout << "��������Ĵ��������������" << endl;
	CreateBiThrTree(T);
	InOrderThreading(H, T);
	cout << "�������������������" << endl;
	InOrderTraverse_Thr(H);
	return 0;
}
