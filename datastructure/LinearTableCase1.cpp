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
typedef struct PNode
{
	float coef;//系数
	float expn;//指数
	struct PNode* next;
}PNode,*Polynomial;
void CreatePolyn(Polynomial& P, int n)
{
	P = new PNode;
	P->next = NULL;
	PNode* s;
	PNode* pre;
	PNode* q;
	for (int i = 1; i <= n; i++)
	{
		s = new PNode;
		cin >> s->coef >> s->expn;
		pre = P;
		q = P->next;
		while (q && q->expn < s->expn)
		{
			pre = q;
			q = q->next;
		}
		s->next = q;
		pre->next = s;//将输入项插入到q和其前驱节点pre之间
	}
}
void AddPolyn(Polynomial& Pa, Polynomial& Pb)
{
	PNode* p1 = Pa->next;
	PNode* p2 = Pb->next;
	PNode* p3 = Pa;
	PNode* r;
	while (p1 && p2)
	{
		if (p1->expn == p2->expn)
		{
			float sum = p1->coef + p2->coef;
			if (sum)
			{
				p1->coef = sum;
				p3->next = p1;
				p3 = p1;
				p1 = p1->next;
				r = p2;
				p2 = p2->next;
				delete r;
			}
			else
			{
				r = p1;
				p1 = p1->next;
				delete r;
				r = p2;
				p2 = p2->next;
				delete r;
			}
		}
		else if (p1->expn < p2->expn)
		{
			p3->next = p1;
			p3 = p1;
			p1 = p1->next;
		}
		else
		{
			p3->next = p2;
			p3 = p2;
			p2 = p2->next;
		}
	}
	//插入非空多项式的剩余段
	p3->next = p1 ? p1 : p2;
	delete Pb;
}
int main()
{
	Polynomial P1;
	Polynomial P2;
	CreatePolyn(P1, 4);
	CreatePolyn(P2, 3);
	AddPolyn(P1, P2);
	PNode* start = P1->next;
	while (start)
	{
		cout << start->coef << "x[" << start->expn << "]" << endl;
		start = start->next;
	}
}