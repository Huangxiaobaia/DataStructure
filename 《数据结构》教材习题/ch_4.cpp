#include <stdio.h>
#include <iostream>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS 1
/* 写一个算法统计在输入字符串中各个不同字符出现的频度并将结果存入文件
（字符串中的合法字符为A-Z这26个字母和0-9这10个数字）。 */

void Count()
{
	int i, num[36];
	char ch;
	for (i = 0; i < 36; i++)num[i] = 0;
	while((ch=getchar())!='#')
		if ('0' <= ch <= '9') { i = ch - 48; num[i]++; }
		else if ('A' <= ch <= 'Z') { i = ch - 65 + 10; num[i]++; }
	for (i = 0; i < 10; i++)
		cout << "数字" << i << "的个数：" << num[i] << endl;
	for (i = 10; i < 36; i++)
		cout << "字母" << char(i+55) << "的个数：" << num[i] << endl;
}

/* 写一个递归算法来实现字符串逆序存储，要求不另设串存储空间。 */

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

/* 编写算法，实现下面函数的功能。函数void insert(char*s,char*t,int pos)将字符串t插入到字符串s中，
插入位置为pos。假设分配给字符串s的空间足够让字符串t插入。（说明：不得使用任何库函数） */

void insert(char* s, char* t, int pos)
{
	int i = 1, x = 0;
	char* p = s, * q = t;
	if (pos < 1) { cout << "pos参数非法\n"; exit(0); }
	while (*p != '\0' && i < pos) { p++; i++; }//查找pos位置
	if (*p == '\0') { cout << "pos的值超过字符串s的长度"; exit(0); }
	else while (*p != '\0') { p++; i++; }//查到尾时，i为'\0'的下标，p也指向'\0'
	while (*q!='\0')
	{//查找字符串t的长度x，结束时q指向'\0'
		q++;
		x++;
	}
	while (i > pos)
	{//串s的pos后的字串右移，空出串t的位置
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
	//串s的结束标记('\0')也后移了，而串t的结尾标记不应插入到s中。
}

/* 已知字符串S1中存放一段英文，写出算法format(s1,s2,s3,n),将其按给定的长度n格式化成两端对齐的字符串S2, 
其多余的字符送S3。 */

void format(char* s1, char* s2, char* s3, int n)
{
	int i = 0,j=0;
	while (s1[i] != '\0' && s1[i] == ' ') { i++; }//i为第一个非空字符
	if (s1[i ]== '\0') { cout << "字符串s1为空串或空格串\n"; exit(0); }
	while (j < n)
	{
		while(s1[i] != '\0' && s1[i] != ' '&&j<n) { s2[j++] = s1[i++]; }
		while (s1[i] == ' ') { i++; }
		if (s1[i] == '\0') { cout << "字符串s1中没有n个非空字符\n"; exit(0); }
		
	}
	s2[j + 1] = '\0';//置结束标记
	i = i + 1,j=0;
	while (s1[i] != '\0')//将剩余的字符复制到s3中
	{
		s3[j++] = s1[i++];
	}
	s3[j] = '\0';//置结束标记
}

/* 设二维数组a[1..m, 1..n] 含有m*n 个整数。
① 写一个算法判断a中所有元素是否互不相同?输出相关信息(yes/no)；
② 试分析算法的时间复杂度。
 */

bool JudgEqual(int a[][5], int m, int n)
{
	int p = 0,k=0;
	for(int i=0;i<m;i++)//第几行
		for (int j = 0; j < n-1; j++)
		{
			for (p = j + 1; p < n; p++)//与一行其他元素比较
			{
				if (a[i][j] == a[i][p]) { return false; }
			}
			for (k = i + 1; k < m; k++)//与i+1行其他元素比较
			{
				for (p = 0; p < n; p++)//控制其他行的列
				{
					if (a[k][p] == a[i][j]) { return false; }
				}
			}
			
		}
	return true;
}

/* 设任意n个整数存放于数组A(1:n)中，试编写算法，将所有正数排在所有负数前面（要求算法复杂性为0(n)）。  */

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