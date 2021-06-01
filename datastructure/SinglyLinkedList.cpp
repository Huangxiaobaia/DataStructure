#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
typedef int Status;
typedef struct
{
	float coef;//系数
	int expn;//指数
}Polynomial;
bool operator==(const Polynomial& p1, const Polynomial& p2) {
	if ((p1.coef == p2.coef) && (p1.expn == p2.expn))
		return true;
	else
		return false;
}
bool operator!=(const Polynomial& p1, const Polynomial& p2)
{
	if ((p1.coef != p2.coef) || p1.expn != p2.expn)
		return true;
	else
		return false;
}
istream& operator>>(istream& is, Polynomial& e)
{
	is >> e.coef >> e.expn;
	return is;
}
typedef struct LNode
{
	Polynomial data;
	struct LNode* next;
}LNode,*LinkList;
LinkList L;
Status InitList(LinkList& L)
{
	L = new LNode;
	L->next = NULL;
	return OK;
}
//取值
Status GetElem(LinkList L, int i, Polynomial& e)
{
	LNode* p = L->next;
	int j = 1;
	while (p && j < i)
	{
		j++;
		p = p->next;
	}
	if (!p || j > i)return ERROR;
	e = p->data;
	return OK;
}
//查找
LNode* LocateElem(LinkList L, Polynomial e)
{
	LNode* p;
	p = L->next;
	while (p && p->data != e)
		p = p->next;
	return p;
}
//插入
Status ListInsert(LinkList& L, int i, Polynomial e)
{
	LNode* p;
	p = L;
	int j = 0;
	while (p && j < i-1)
	{
		p = p->next;
		j++;
	}
	if (!p || j > i - 1)
		return ERROR;
	LNode* s = new LNode;
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}
//删除
Status ListDelete(LinkList& L, int i)
{
	LNode* p = L;
	int j = 0;
	while (p->next && (j < i - 1))
	{
		p = p->next;
		j++;
	}
	if (!p || j > i - 1)return ERROR;
	LNode* q = p->next;
	p->next = q->next;
	delete q;
	return OK;
}
//前插法创建单链表
void CresteList_H(LinkList& L, int n)
{
	LinkList L;
	L->next = NULL;
	LNode* p;
	for (int i = 0; i < n; i++)
	{
		p = new LNode;
		cin >> p->data;
		p->next = L->next;
		L->next = p;
	}
}
//后插法创建单链表
void CreateList_R(LinkList& L, int n)
{
	LinkList L;
	L->next = NULL;
	LNode* p;
	LNode* r;
	for (int i = 0; i < n; i++)
	{
		p = new LNode;
		cin >> p->data;
		p->next = NULL;
		r->next = p;
		r = p;
	}
}