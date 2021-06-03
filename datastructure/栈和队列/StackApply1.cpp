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
typedef struct StackNode
{
	int data;
	StackNode* next;

}StackNode,*LinkStack;
Status InitStack(LinkStack& S)
{
	S = NULL;
	return OK;
}
Status Push(LinkStack& S, int i)
{
	StackNode* newnode=new StackNode;
	newnode->data = i;
	newnode->next = S;
	S = newnode;
	return OK;
}
bool StackEmpty(LinkStack S)
{
	if (S == NULL)
		return true;
	return false;
}
Status PoP(LinkStack& S, int &e)
{
	StackNode* p;
	e = S->data;
	p = S;
	S = S->next;
	delete p;
	return OK;
}
void conversion(int N,LinkStack&S)
{
	int e;
	while (N)
	{
		Push(S, N % 8);
		N = N / 8;
	}
	while (!StackEmpty(S))
	{
		PoP(S, e);
		cout << e;
	}
}
int main()
{//对于一个非负十进制数，打印输出其八进制数
	LinkStack S;
	InitStack(S);
	conversion(18, S);
}