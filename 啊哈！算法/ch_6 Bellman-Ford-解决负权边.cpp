#include <iostream>
using namespace std;



void test01()
{
	int n,m,i,a,b,c,j,h=1,d,flag;
	int u[10], v[10], w[10];
	cout << "���빲�м������㣺";
	cin >> n;
	cout << "���빲�м����ߣ�";
	cin >> m;
	//ѭ������m����
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
	//��⸺Ȩ��·
	flag = 0;
	for (i = 1; i <= m; i++)
		if (dis[v[i]] > dis[u[i]] + w[i])
			flag = 1;
	if (flag == 1)
		cout << "���и�Ȩ��·";
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