#include <iostream>
using namespace std;

void test01()
{
	int n, m, i, j, a, b, c, k,min,u,v;
	int e[10][10];
	int book[10] = {0},dis[10];
	int inf = 999999;
	cout << "���빲�м������㣺";
	cin >> n;
	//��ʼ���ڽӾ���
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			if (i == j)e[i][j] = 0;
			else e[i][j] = inf;
	cout << "���빲�м����ߣ�";
	cin >> m;
	cout << "����߶�Ӧ�Ķ��㣺";
	for (i = 1; i <= m; i++)
	{
		cin >> a;
		cin >> b;
		cin >> c;
		e[a][b] = c;
	}

	//��ʼ��dis���飬1�Ŷ��㵽���������ĳ�ʼ·��
	for (i = 1; i <= n; i++)
		dis[i] = e[1][i];

	book[1] = 1;

	for (i = 1; i <= n - 1; i++)
	{
		min = inf;
		//�ҵ���1�Ŷ�������Ķ���
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