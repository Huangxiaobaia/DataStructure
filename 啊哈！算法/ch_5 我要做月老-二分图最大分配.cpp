#include <iostream>
using namespace std;

int e[10][10];
int match[10];
int book[10];
int n;

int dfs(int u)
{
	int i;
	for (i = 1; i <= n; i++)
	{
		if (book[i] == 0 && e[u][i]==1)
		{
			book[i] = 1;
			if (match[i] == 0 || dfs(match[i]))
			{
				match[i] = u;
				return 1;
			}
		}
	}
	return 0;
}

int main()
{
	int m,i,t1,t2,j,sum=0;
	cout << "输入有几个点：";
	cin >> n;
	cout << "输入有几条边：";
	cin >> m;

	for (i = 1; i <= m; i++)
	{
		cin >> t1;
		cin >> t2;
		e[t1][t2] = 1;
	}

	for (i = 1; i <= n; i++)match[i] = 0;

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)book[j] = 0;
		if (dfs(i))sum++;
	}

	cout << sum;

	return 0;
}