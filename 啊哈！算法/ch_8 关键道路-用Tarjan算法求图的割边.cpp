#include <iostream>
using namespace std;

int n,m,index=0;
int e[10][10];
int inf = 999999;
int root;
int num[10],low[10];

int min(int a, int b)
{
	return a > b ? b : a;
}

void dfs(int cur, int father)
{
	int i;
	index++;
	num[cur] = index;
	low[cur] = index;
	for (i = 1; i <= n; i++)
	{
		if (e[cur][i]!=inf&&e[cur][i]!=0)
		{
			if (num[i] == 0)
			{
				dfs(i, cur);
				low[cur] = min(low[cur], low[i]);
				if (low[i] > num[cur])
					cout << cur << "-" << i;
			}
			else if (i != father)
			{
				low[cur] = min(low[cur], num[i]);
			}
		}
	}

	return;
}


int main()
{
	int m, i,j, a, b;
	cout << "�����м������㣺";
	cin >> n;
	cout << "�����м����ߣ�";
	cin >> m;
	cout << "����ߵĶ����Ȩֵ��";
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			if (i == j)e[i][j] = 0;
			else e[i][j] = inf;

	for (i = 1; i <= m; i++)
	{
		cin >> a;
		cin >> b;
		e[a][b] = 1;
		e[b][a] = 1;
	}

	root = 1;

	dfs(1, root);//��1�Ŷ��㿪ʼ����������ȱ���

	return 0;
}