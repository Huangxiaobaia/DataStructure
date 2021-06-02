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
	int b[20];
}arr;
typedef struct
{
	int* a;
	int length;
}SqList;
Status InitList(SqList& L1, SqList& L2,SqList &L3)
{
	L1.a = new int[20];
	L2.a = new int[20];
	L3.a = new int[20];
	if (!L1.a)exit(OVERFLOW);
	L1.length = 0;
	L2.length = 0;
	L3.length = 0;
	return OK;
}
Status EvaluationList(SqList& L1, SqList& L2)
{
	int arr1[] = { 3,5,8,11 };
	int arr2[] = { 2,6,8,9,11,15,20 };
	for (int i = 0; i < 4; i++)
	{
		L1.a[i] = arr1[i];
		L1.length++;
	}
	for (int i = 0; i < 7; i++)
	{
		L2.a[i] = arr2[i];
		L2.length++;
	}
	return OK;
}
void MergeList_Sq(SqList L1, SqList L2, SqList& L3)
{
	L3.length = L1.length + L2.length;
	int* pc = L3.a;
	int* pa = L1.a;
	int* pb = L2.a;
	int* pa_last = L1.a + L1.length - 1;
	int* pb_last = L2.a + L2.length - 1;
	while ((pa <= pa_last) && (pb <= pb_last))
	{//L1和L2均未到表尾
		if (*pa <= *pb)*pc++ = *pa++;
		else *pc++ = *pb++;
	}
	while (pa <= pa_last)*pc++ = *pa++;
	while (pb <= pb_last)*pc++ = *pb++;
}
//顺序表实现有序表的合并
int main()
{
	SqList L1;
	SqList L2;
	SqList L3;
	InitList(L1, L2,L3);
	EvaluationList(L1, L2);
	MergeList_Sq(L1, L2, L3);
	for (int i = 0; i < L3.length; i++)
	{
		cout << L3.a[i] << endl;
	}
	return 0;
}