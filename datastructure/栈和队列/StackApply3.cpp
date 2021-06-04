#define _CRT_SECURE_NO_WARNINGS 1
#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;
typedef int Status;
//运算数栈
typedef struct StackNode
{
	float a;
	StackNode* next;
}StackNode,*LinkStack;
//运算符栈
typedef struct StackNode1
{
	char c;
	StackNode1* next;
}StackNode1, * LinkStack1;
Status InitStack(LinkStack& S)
{
	S = NULL;
	return OK;
}
Status InitStack1(LinkStack1& S)
{
	S = NULL;
	return OK;
}
Status Push1(LinkStack1& S,const char &ch)
{
	StackNode1* newnode = new StackNode1;
	newnode->c = ch;
	newnode->next = S;
	S = newnode;
	return OK;
}
Status Push(LinkStack& S, const float& f)
{
	StackNode* newnode = new StackNode;
	newnode->a = f;
	newnode->next = S;
	S = newnode;
	return OK;
}
char GetTop(const LinkStack1& OPTR)
{
	return OPTR->c;
}
bool In(char ch)
{
	string s ="+-*/()#";
	if (s.find(ch)!=string::npos)
		return true;
	else
		return false;
}
char GetTop1(const LinkStack1& OPTR)
{
	return OPTR->c;
}
float GetTop(const LinkStack& OPND)
{
	return OPND->a;
}
Status Pop1(LinkStack1& OPTR,char &c)
{
	StackNode1* p;
	if (OPTR == NULL)
		return ERROR;
	p = OPTR;
	c = p->c;
	OPTR = OPTR->next;
	delete p;
	return OK;
}
char Precede(char c,char ch)
{
	string s1 = "+-(";
	string s2 = "*/";
	string s3 = s1.append(s2);
	if (s1.find(c) != string::npos && s2.find(ch) != string::npos)
		return '<';
	else if ((c == ch) && (s3.find(c) != string::npos || s3.find(ch) != string::npos))
		return '>';
	else if (s3.find(c) != string::npos && (ch == '('))
		return '<';
	else if (c == '(' && (ch == ')'))
		return '=';
	else if (ch == ')' && s3.find(c) != string::npos)
		return '>';
	else if (s3.find(ch) != string::npos && c == '(')
		return '<';
	else if (ch == '#')
		return '>';
	else if (c == '#')
		return '<';
	else
		return '=';
}
Status Pop(LinkStack& S,int &n)
{
	if (S == NULL)return ERROR;
	StackNode* s;
	s = S;
	n = S->a;
	S = S->next;
	delete s;
	return OK;
}
float Operate(const float& a, const char& theta, const float& b)
{
	switch (theta)
	{
		case'+':
			return a + b;
			break;
		case'-':
			return a - b;
			break;
		case'*':
			return a * b;
			break;
		case'/':
			return a / b;
			break;
	}
}
float EvaluateExpression(LinkStack1&OPTR,LinkStack&OPND)
{//设OPTR和OPND分别为运算符栈和操作数栈
	char ch,x;
	char theta;
	char flo[5];
	string s;
	float f;
	int i = 0;
	int a, b;
	InitStack(OPND);
	InitStack1(OPTR);
	Push1(OPTR, '#');
	cin >> ch;
	while (ch != '#' || GetTop(OPTR) != '#')
	{
		if (!In(ch))
		{
			while (!In(ch))
			{//如果当前输入字符不是运算符和#，把当前字符存入字符数组中
				flo[i++] = ch;
				cin >> ch;
			}
			f = strtof(flo, NULL);
			Push(OPND, f);
			for (i=0; i < 5; i++)
				flo[i] = NULL;
			i = 0;
		}
		else
			switch (Precede(GetTop1(OPTR), ch))
			{
				case'<':
					Push1(OPTR, ch);
					cin >> ch;
					break;
				case'>':
					Pop1(OPTR, theta);
					Pop(OPND, b);
					Pop(OPND, a);
					Push(OPND, Operate(a, theta,b));
					break;
				case'=':
					Pop1(OPTR, x);
					cin >> ch;
					break;
			}
	}
	return GetTop(OPND);
}
int main()
{
	LinkStack1 OPTR;
	LinkStack OPND;
	cout<<EvaluateExpression(OPTR,OPND)<<endl;
	return 0;
}
