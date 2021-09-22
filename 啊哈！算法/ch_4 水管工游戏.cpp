#include <iostream>
using namespace std;

int a[50][50];//土地的大小
int book[50][50];
int n, m,flag=0;

struct note
{
	int x;
	int y;
}s[100];
int top = 0;

void dfs(int x, int y, int front)
{
	//判断是否到达终点
	if (x == n && y == m + 1)
	{
		int i;
		flag = 1;
		for (i = 0; i < top; i++)
			cout << "(" << s[i].x << "," << s[i].y << ") ";
		cout << "\n";
		return;
	}
	//判断是否越界
	if (x<1 || x>n || y<1 || y>m)
	{
		return;
	}
	//判断这个管道是否在路径中使用过
	if (book[x][y] == 1)
		return;
	book[x][y] = 1;
	s[top].x = x;
	s[top].y = y;
	top++;
	//直管情况
	if (a[x][y] == 5 || a[x][y] == 6)
	{
		if (front == 1)//进水口在左边
		{
			dfs(x, y + 1, 1);
		}
		if (front == 2)//进水口在上边
		{
			dfs(x + 1, y, 2);
		}
		if (front == 3)//进水口在右边
		{
			dfs(x, y - 1, 3);
		}
		if (front == 4)//进水口在下边
		{
			dfs(x - 1, y, 4);
		}
	}
	//弯管情况
	if (a[x][y] >= 1 && a[x][y] <= 4)
	{
		if (front == 1)
		{
			dfs(x - 1, y, 4);
			dfs(x + 1, y, 2);
		}
		if (front == 2)
		{
			dfs(x, y-1, 3);
			dfs(x, y+1, 1);
		}
		if (front == 3)
		{
			dfs(x - 1, y, 4);
			dfs(x + 1, y, 2);
		}
		if (front == 4)
		{
			dfs(x, y-1, 3);
			dfs(x, y+1, 1);
		}
	}
	book[x][y] = 0;
	top--;
	return;
}

void test01()
{
	int i, j;
	cout << "n行字符：";
	cin >> n;
	cout << "\n" << "每行有m列：";
	cin >> m;

	//读入每行数字
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			cin >> a[i][j];
	//第一个格进水口在左边
	dfs(1, 1, 1);
	if (flag == 1)
		cout << "找到铺设方案";
	else
		cout << "找不到铺设方案";
}

/*
5 3 5 3
1 5 3 0
2 3 5 1
6 1 1 5
1 5 5 4
*/

int main()
{
	test01();
	return 0;
}