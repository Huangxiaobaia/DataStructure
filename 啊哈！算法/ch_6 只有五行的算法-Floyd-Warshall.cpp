#include <iostream>
using namespace std;

void test01()
{
	int n, m, i, j, a, b, c,k;
	int e[10][10];
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

	for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
			for (j = 1; j <= n; j++)
			{
				if (e[i][k]<inf&&e[k][j]<inf&&e[i][j] > e[i][k] + e[k][j])
					e[i][j] = e[i][k] + e[k][j];
			}

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			cout << e[i][j] << " ";
		}
		cout << "\n";
	}
		
}

int main()
{
	test01();
	return 0;
}