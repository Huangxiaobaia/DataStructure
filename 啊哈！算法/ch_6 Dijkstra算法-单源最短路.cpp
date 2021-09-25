#include <iostream>
using namespace std;

void test01()
{
	int n, m, i, j, a, b, c, k,min,u,v;
	int e[10][10];
	int book[10] = {0},dis[10];
	int inf = 999999;
	cout << "输入共有几个顶点：";
	cin >> n;
	//初始化邻接矩阵
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			if (i == j)e[i][j] = 0;
			else e[i][j] = inf;
	cout << "输入共有几条边：";
	cin >> m;
	cout << "输入边对应的顶点：";
	for (i = 1; i <= m; i++)
	{
		cin >> a;
		cin >> b;
		cin >> c;
		e[a][b] = c;
	}

	//初始化dis数组，1号顶点到其余各顶点的初始路程
	for (i = 1; i <= n; i++)
		dis[i] = e[1][i];

	book[1] = 1;

	for (i = 1; i <= n - 1; i++)
	{
		min = inf;
		//找到离1号顶点最近的顶点
		for (j = 1; j <= n; j++)
		{
			if (book[j] == 0 && dis[j] < min)
			{
				min = dis[j];
				u = j;
			}
		}
		book[u] = 1;
		for (v = 1; v <= n; v++)
		{
			if (e[u][v] < inf)
			{
				if (dis[v] > dis[u] + e[u][v])
					dis[v] = dis[u] + e[u][v];
			}
		}
	}
	for (i = 1; i <= n; i++)
		cout << dis[i] << " ";

}

int main()
{
	test01();
	return 0;
}