#include <stdio.h>
#include <iostream>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS 1
/* дһ���㷨ͳ���������ַ����и�����ͬ�ַ����ֵ�Ƶ�Ȳ�����������ļ�
���ַ����еĺϷ��ַ�ΪA-Z��26����ĸ��0-9��10�����֣��� */

void Count()
{
	int i, num[36];
	char ch;
	for (i = 0; i < 36; i++)num[i] = 0;
	while((ch=getchar())!='#')
		if ('0' <= ch <= '9') { i = ch - 48; num[i]++; }
		else if ('A' <= ch <= 'Z') { i = ch - 65 + 10; num[i]++; }
	for (i = 0; i < 10; i++)
		cout << "����" << i << "�ĸ�����" << num[i] << endl;
	for (i = 10; i < 36; i++)
		cout << "��ĸ" << char(i+55) << "�ĸ�����" << num[i] << endl;
}

/* дһ���ݹ��㷨��ʵ���ַ�������洢��Ҫ�����贮�洢�ռ䡣 */

void InvertStore(char a[])
{
	char ch;
	static int i = 0;
	cin >> ch;
	if (ch != '#')
	{
		InvertStore(a);
		a[i++] = ch;
	}
	a[i] = '\0';
}

/* ��д�㷨��ʵ�����溯���Ĺ��ܡ�����void insert(char*s,char*t,int pos)���ַ���t���뵽�ַ���s�У�
����λ��Ϊpos�����������ַ���s�Ŀռ��㹻���ַ���t���롣��˵��������ʹ���κο⺯���� */

void insert(char* s, char* t, int pos)
{
	int i = 1, x = 0;
	char* p = s, * q = t;
	if (pos < 1) { cout << "pos�����Ƿ�\n"; exit(0); }
	while (*p != '\0' && i < pos) { p++; i++; }//����posλ��
	if (*p == '\0') { cout << "pos��ֵ�����ַ���s�ĳ���"; exit(0); }
	else while (*p != '\0') { p++; i++; }//�鵽βʱ��iΪ'\0'���±꣬pҲָ��'\0'
	while (*q!='\0')
	{//�����ַ���t�ĳ���x������ʱqָ��'\0'
		q++;
		x++;
	}
	while (i > pos)
	{//��s��pos����ִ����ƣ��ճ���t��λ��
		*(p + x) = *p;
		p--;
		i--;
	}
	q--;
	int j = x;
	while (j > 0)
	{
		*(p+x) = *q--;
		p--;
		j--;
	}
	//��s�Ľ������('\0')Ҳ�����ˣ�����t�Ľ�β��ǲ�Ӧ���뵽s�С�
}

/* ��֪�ַ���S1�д��һ��Ӣ�ģ�д���㷨format(s1,s2,s3,n),���䰴�����ĳ���n��ʽ�������˶�����ַ���S2, 
�������ַ���S3�� */

void format(char* s1, char* s2, char* s3, int n)
{
	int i = 0,j=0;
	while (s1[i] != '\0' && s1[i] == ' ') { i++; }//iΪ��һ���ǿ��ַ�
	if (s1[i ]== '\0') { cout << "�ַ���s1Ϊ�մ���ո�\n"; exit(0); }
	while (j < n)
	{
		while(s1[i] != '\0' && s1[i] != ' '&&j<n) { s2[j++] = s1[i++]; }
		while (s1[i] == ' ') { i++; }
		if (s1[i] == '\0') { cout << "�ַ���s1��û��n���ǿ��ַ�\n"; exit(0); }
		
	}
	s2[j + 1] = '\0';//�ý������
	i = i + 1,j=0;
	while (s1[i] != '\0')//��ʣ����ַ����Ƶ�s3��
	{
		s3[j++] = s1[i++];
	}
	s3[j] = '\0';//�ý������
}

/* ���ά����a[1..m, 1..n] ����m*n ��������
�� дһ���㷨�ж�a������Ԫ���Ƿ񻥲���ͬ?��������Ϣ(yes/no)��
�� �Է����㷨��ʱ�临�Ӷȡ�
 */

bool JudgEqual(int a[][5], int m, int n)
{
	int p = 0,k=0;
	for(int i=0;i<m;i++)//�ڼ���
		for (int j = 0; j < n-1; j++)
		{
			for (p = j + 1; p < n; p++)//��һ������Ԫ�رȽ�
			{
				if (a[i][j] == a[i][p]) { return false; }
			}
			for (k = i + 1; k < m; k++)//��i+1������Ԫ�رȽ�
			{
				for (p = 0; p < n; p++)//���������е���
				{
					if (a[k][p] == a[i][j]) { return false; }
				}
			}
			
		}
	return true;
}

/* ������n���������������A(1:n)�У��Ա�д�㷨�������������������и���ǰ�棨Ҫ���㷨������Ϊ0(n)����  */

void Arrange(int A[], int n)
{
	int i = 0, j = n - 1, tmp;
	while (i < j)
	{
		while (A[i] > 0 && i < j)i++;
		while (A[j] < 0 && i < j)j--;
		if (i < j) { tmp = A[i]; A[i] = A[j]; A[j] = tmp; }
	}
}

int main()
{
	//4.1
	//Count();

	//4.2
	/*char a[20];
	InvertStore(a);
	int j = 0;
	while (a[j] != '\0')
	{
		cout << a[j++];
	}*/

	//4.3
	/*char s[20] = "hjfksndka";
	char t[] = "hua";
	insert(s, t, 3);
	int j = 0;
	while (s[j] != '\0')
	{
		cout << s[j] << " ";
		j++;
	}*/

	//4.4
	/*char s1[] = "sbh ajso huas joas   joasjis jao";
	char s2[20];
	char s3[30];
	format(s1, s2, s3, 10);
	int j = 0;
	while (s2[j] != '\0')
		cout << s2[j++] << "\n";
	cout << "=====================\n";
	j = 0;
	while (s3[j] != '\0')
		cout << s3[j++] << "\n";*/

	//4.5
	/*int a[5][5] = { {1, 2, 3, 4, 5} ,{6, 7, 8, 9, 10},{11, 12, 13, 14, 15},{16, 17, 18, 19, 20}, {21, 22, 23, 24, 25} };
	cout << JudgEqual(a, 5, 5) << endl;*/

	//4.6
	int A[] = { 1,-4,5,-1,7,-9,7,3,-9,-3 };
	Arrange(A, 10);
	for (int j = 0; j < 10; j++)
		cout << A[j] << " ";

	return 0;
}