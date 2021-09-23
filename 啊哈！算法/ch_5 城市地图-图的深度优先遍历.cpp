#include <iostream>
using namespace std;

int e[100][100];
int book[10000];
int min = 99999,n;
void dfs(int x,int sum)
{
	int i;
	if (sum > min)return;
	if (x == n)//判断是否到达了目标城市
	{
		if(sum<min)min = sum;
		return;
	}
	for (i = 1; i <= n; i++)
	{
		if (e[x][i] != 999999 && e[x][i] != 0 && book[i] == 0)
		{
			book[i] = 1;
			dfs(i, sum+e[x][i]);
			book[i] = 0;//探索完毕后取消对城市i的标记
		}
	}
	return;
}

void test01()
{
	int m, i, j, a, b,c;
	cout << "输入共有几个顶点：";
	cin >> n;
	//初始化邻接矩阵
	for (i = 1; i <=n; i++)
		for (j = 1; j <=n; j++)
			if (i == j)e[i][j] = 0;
			else e[i][j] = 999999;
	cout << "输入共有几条边：";
	cin >> m;
	cout << "输入边对应的顶点以及权值：";
	for (i = 1; i <=m; i++)
	{
		cin >> a;
		cin >> b;
		cin >> c;
		e[a][b] = c;
	}
	book[1] = 1;
	dfs(1,0);//0表示已走过的路程
	cout << min;
}
/*
1 2 2
1 5 10
2 3 3
2 5 7
3 1 4
3 4 4
4 5 5
5 3 3
*/
int main()
{
	test01();
	return 0;
}