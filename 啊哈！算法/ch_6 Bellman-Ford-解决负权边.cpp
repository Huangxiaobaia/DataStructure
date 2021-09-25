#include <iostream>
using namespace std;



void test01()
{
	int n,m,i,a,b,c,j,h=1,d,flag;
	int u[10], v[10], w[10];
	cout << "输入共有几个顶点：";
	cin >> n;
	cout << "输入共有几条边：";
	cin >> m;
	//循环输入m条边
	for (i = 1; i <= m; i++)
	{
		cin >> u[i];
		cin >> v[i];
		cin >> w[i];
	}

	int inf = 999999,k;
	int dis[10];
	for (i = 1; i <= n; i++)
		dis[i] = inf;
	dis[1] = 0;

	for (k = 1; k <= n - 1; k++)
	{
		flag = 0;
		for (i = 1; i <= m; i++)
			if (dis[v[i]] > dis[u[i]] + w[i])
			{
				flag = 1;
				dis[v[i]] = dis[u[i]] + w[i];
			}
		if (flag == 0)break;
	}
	//检测负权回路
	flag = 0;
	for (i = 1; i <= m; i++)
		if (dis[v[i]] > dis[u[i]] + w[i])
			flag = 1;
	if (flag == 1)
		cout << "含有负权回路";
	else
	{
		for (i = 1; i <= m; i++)
			cout << dis[i] << " ";
	}
}

int main()
{
	test01();
	return 0;
}