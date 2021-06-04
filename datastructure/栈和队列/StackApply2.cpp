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
	char ch;
	StackNode* next;
}StackNode,*LinkStack;
Status InitStack(LinkStack& S)
{
	S = NULL;
	return OK;
}
Status Push(LinkStack& S, const char& c)
{
	StackNode* newnode=new StackNode;
	newnode->ch = c;
	newnode->next = S;
	S = newnode;
	return OK;
}
Status PoP(LinkStack& S, char& c)
{
	if (S == NULL)return ERROR;
	StackNode* tmp = S;
	c = S->ch;
	S = S->next;
	delete tmp;
	return OK;
}
bool StackEmpty(LinkStack& S)
{
	if (S == NULL)return true;
	return false;
}
char GetTop(const LinkStack& S)
{
	return S->ch;
}
Status Matching(LinkStack&S)
{
	char ch;
	char c;
	int flag = 1;
	cin >> ch;
	while (ch != '#' && flag)
	{
		if (ch == '(' || ch == '[')
		{
			Push(S, ch);
		}
		else if (ch == ')')
		{
			if (!StackEmpty(S) && GetTop(S) == '(')
				PoP(S, c);
			else flag = 0;
		}
		else if (ch == ']')
		{
			if (!StackEmpty(S) && GetTop(S) == '[')
				PoP(S, c);
			else flag = 0;
		}
		cin >> ch;
	}
	if (StackEmpty(S) && flag)return true;
	return false;
}
int main()
{//À¨ºÅÆ¥ÅäµÄ¼ìÑé
	LinkStack S;
	InitStack(S);
	if (Matching(S))
		cout << "Æ¥Åä³É¹¦" << endl;
	else
		cout << "Æ¥ÅäÊ§°Ü" << endl;
}