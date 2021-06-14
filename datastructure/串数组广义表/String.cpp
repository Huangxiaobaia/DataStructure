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
using namespace std;
typedef int Status;
typedef struct Chunk {
	char ch[CHUNKSIZE];
	struct Chunk* next;
}Chunk;
typedef struct {
	Chunk* head, * tail;
	int length;
}LString;
typedef struct {
	char ch[MAXLEN+1];
	int length;
}SString;
Status InitSString(SString& s)
{
	s.length = 0;
	return OK;
}
int Index_BF(SString S, SString T, int pos)
{//返回模式串T在主串中第pos个字符开始第一次出现的位置，若不存在则返回0
	int i = pos;
	int j = 1;
	while (i <= S.length && j <= T.length)
	{
		if (S.ch[i] == T.ch[j])
		{
			++i;
			++j;
		}
		else
		{
			i = i - j + 2;
			j = 1;
		}
	}
	if (j > T.length)
		return i - T.length;
	else
		return 0;
}
void get_next(SString T, int next[])
{
	int i = 1;
	next[1] = 0;
	int j = 0;
	while (i < T.length)
	{
		if (j == 0 || T.ch[j] == T.ch[i])
		{
			++j;
			++i;
			next[i] = j;
		}
		else
		{
			j = next[j];
		}
	}
}
int Index_KMP(SString S, SString T, int pos)
{
	int i = pos;
	int j = 1;
	int next[10];
	get_next(T,next);
	while (i <= S.length && j <= T.length)
	{
		if (j == 0 || S.ch[i] == T.ch[j])
		{
			++i;
			++j;
		}
		else
			j = next[j];
	}
	if (j > T.length)
		return i - T.length;
	else
		return 0;
}
int main()
{
	SString S,T;//S主串，T模式串
	InitSString(S);
	InitSString(T);
	string s1 = "ababcabsnsbancz";
	string s2 = "bca";
	for (int i = 0; i < s1.length(); i++)
	{
		S.ch[i + 1] = s1[i];
	}
	for (int i = 0; i < s2.length(); i++)
	{
		T.ch[i + 1] = s2[i];
	}
	S.length = s1.length();
	T.length = s2.length();
	int findindex=Index_KMP(S, T,1);
	if (findindex == 0)
		cout << "未找到" << endl;
	else
		cout << "第一次出现的位置为：" << findindex << endl;
	return 0;
}