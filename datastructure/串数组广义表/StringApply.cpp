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
typedef struct {
	char ch[MAXLEN];
	int length;
}SString;
int Index_BF(SString S, SString T, int pos)
{//����ģʽ��T�������е�pos���ַ���ʼ��һ�γ��ֵ�λ�ã����������򷵻�0
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
void Virus_detection()
{//����BF�㷨ʵ�ֲ������
	ifstream inFile("������Ⱦ�����������.txt");
	ofstream outFile("������Ⱦ���������.txt");
	int num;
	SString Virus;
	SString Person;
	SString temp;
	string Vir;
	string Per;
	int m,flag,i,j;
	inFile >> num;
	while (num--)
	{
		inFile >> Virus.ch + 1;
		inFile >> Person.ch + 1;
		Vir = Virus.ch;
		Per = Person.ch;
		Virus.length = Vir.length();
		Person.length = Per.length();
		flag = 0;
		m = Virus.length;
		for (i = m + 1, j = 1; j <= m; j++)
		{//�������ַ���������������
			Virus.ch[i++] = Virus.ch[j];
		}
		Virus.ch[2 * m + 1] = '\0';
		for (i = 0; i < m; i++)
		{
			for (j = 0; j < m; j++)
			{
				temp.ch[j + 1] = Virus.ch[i + j + 1];
			}
			temp.ch[m + 1] = '\0';
			flag = Index_BF(Person, temp, 1);
			if (flag)
				break;
		}
		if (flag)
			outFile << Virus.ch + 1 << "  " << Person.ch + 1 << " " << "YES" << endl;
		else
			outFile << Virus.ch + 1 << "  " << Person.ch + 1 << " " << "YES" << endl;
	}
}
int main()
{
	Virus_detection();
	return 0;
}