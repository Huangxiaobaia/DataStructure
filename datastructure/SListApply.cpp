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

typedef struct
{
	int b[100];
}arr;
typedef struct
{
	arr* a;
	int length;
}SqList;

Status InitList(SqList& L1, SqList& L2)
{
	L1.a = new arr[MAXSIZE];
	L2.a = new arr[MAXSIZE];
	if (!L1.a)exit(OVERFLOW);
	L1.length = 0;
	L2.length = 0;
	return OK;
}

Status EvaluationList(SqList& L1, SqList& L2)
{
	int arr1[] = { 7, 5, 3, 11 };
	int arr2[] = { 2,6,3 };
	for (int i = 0; i < 4; i++)
	{
		L1.a->b[i] = arr1[i];
		L1.length++;
	}
	for (int i = 0; i < 3; i++)
	{
		L2.a->b[i] = arr2[i];
		L2.length++;
	}
	return OK;
}

int GetElem(const SqList& L, int i)
{
	if (i < 1 || i>L.length)return ERROR;
	return L.a->b[i - 1];
}
Status LocateElem(const SqList& L, int e)
{
	for (int i = 0; i < L.length; i++)
	{
		if (L.a->b[i] == e)
			return i+1;
	}
	return 0;
}
Status ListInsert(SqList& L, int i,int e)
{
	if ((i<1) ||( i>L.length+1))return ERROR;
	if (L.length == MAXSIZE)return ERROR;
	for (int j = L.length - 1; j > i - 1; j++)
	{
		L.a->b[j+1] = L.a->b[j];

	}
	L.a->b[i - 1] = e;
	++L.length;
	return OK;
}
void MergeList(SqList& L1, SqList& L2)
{
	int m,n,i,e;
	m = L1.length;
	n = L2.length;
	for (i = 1; i <= n; i++)
	{
		e=GetElem(L2, i);
		if (!LocateElem(L1, e))
			ListInsert(L1 ,++m,e);
	}
}
//顺序表实现线性表的合并
int main()
{
	SqList L1, L2;
	//初始化顺序表
	InitList(L1, L2);
	//赋值
	EvaluationList(L1, L2);
	//合并
	MergeList(L1, L2);
	for (int i = 0; i < L1.length; i++)
	{
		cout << L1.a->b[i] << endl;
	}
	return 0;
}