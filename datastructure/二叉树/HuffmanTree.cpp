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
typedef struct 
{
	int weight;
	int parent, lchild, rchild;
}HTNode,*HuffmanTree;
typedef char** HuffmanCode;
void Select(HuffmanTree& HT,const int& a, int& b,int &c)
{
	int max1 = HT[1].weight;
	int max2 = 0;
	int max_index;
	for (int i = 2; i <= a; i++)
	{//查找最大的权值
		if (HT[i].weight > max1)
		{
			max1 = HT[i].weight;
			max_index = i;
		}
	}
	for (int i = 1; i <= a; i++)
	{
		if (i == max_index)
			max2 = max2;
		else if(HT[i].weight>max2)
			max2 = HT[i].weight;
	}
	b = max1;
	c = max2;
}
void CreateHuffmanTree(HuffmanTree& HT, int n)
{//构造哈夫曼树HT
	int s1;
	int s2;
	if (n <= 1)
		return;
	int m = 2 * n - 1;
	HT = new HTNode[m + 1];
	for (int i = 1; i <= m; i++)
	{
		HT[i].parent = 0;
		HT[i].lchild = 0;
		HT[i].rchild = 0;
	}
	for (int i = 1; i <= n; i++)
	{
 		cin >> HT[i].weight;
	}
	//初始化结束，开始创建
	for (int i = n + 1; i <= m; i++)
	{//经过n-1次选择
		Select(HT, i - 1, s1, s2);
		HT[s1].parent = i;
		HT[s2].parent = i;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
		HT[i].lchild = s1;
		HT[i].rchild = s2;
	}
}
void CreateHuffmanCode(const HuffmanTree& HT, HuffmanCode& HC, int n)
{//根据哈夫曼树求哈夫曼编码
	char* cd = new char[n];
	cd[n - 1] = '\0';
	int start;
	int c, f;
	HC = new char* [n + 1];//从1开始存放
	for (int i = 1; i <= n; i++)
	{
		start = n - i;
		c = i;
		f = HT[c].parent;
		while (f != 0)
		{
			--start;
			if (HT[f].lchild == c)
				cd[start] = '0';
			else
				cd[start] = '1';
			c = f;
			f = HT[c].parent;
		}
		HC[i] = new char[n - start];
		strcpy(HC[i], &cd[start]);
	}
	delete cd;
}
int main()
{
	HuffmanTree HT;
	HuffmanCode HC;
	CreateHuffmanTree(HT, 8);
	CreateHuffmanCode(HT, HC, 8);
	return 0;
}