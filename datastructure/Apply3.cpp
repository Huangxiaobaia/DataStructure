#define _CRT_SECURE_NO_WARNINGS 1
#define MAXSIZE 100
#define OK 1
#define ERROR 0
typedef int Status;
#define OVERFLOW -2
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
typedef struct LNode
{
	int a;
	struct LNode* next;
}*LinkList;

Status CreateList_R(LinkList& L1, LinkList& L2)
{
	int arr1[] = { 3,5,8,11 };
	int arr2[] = { 2,6,8,9,11,15,20 };
	L1 = new LNode;
	L2 = new LNode;
	L1->next = NULL;
	L2->next = NULL;
	LNode* s;
	LNode* r=L1;
	
	for (int i = 0; i < 4; i++)
	{
		s = new  LNode;
		s->a=arr1[i];
		s->next = NULL;
		r->next = s;
		r = s;
	}
	LNode* p;
	LNode* e = L2;
	for (int i = 0; i < 7; i++)
	{
		s = new  LNode;
		s->a = arr2[i];
		s->next = NULL;
		e->next = s;
		e = s;
	}
	return OK;
}
void MergeList_L(LinkList& L1, LinkList& L2, LinkList& L3)
{
	LNode* pa = L1->next;
	LNode* pb = L2->next;
	L3 = L1;
	LNode* pc = L3;
	while (pa && pb)
	{
		if (pa->a <= pb->a)
		{
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else
		{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}
	pc->next = pa ? pa : pb;
	delete L2;
}
//单链表实现有序表的合并
int main()
{
	LinkList L1,L2,L3;
	CreateList_R(L1, L2);
	MergeList_L(L1, L2, L3);
	LNode* start = L3;
	do 
	{
		cout << start->next->a << endl;
		start = start->next;
	} 	while (start->next);
	return 0;
}

