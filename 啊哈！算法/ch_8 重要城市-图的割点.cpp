#include <iostream>
using namespace std;

int root,n;
int flag[10], num[10], low[10],index;//index用来进行时间戳的递增
int inf = 999999;
int e[10][10];

int min(int a, int b)
{
	return a > b ? b : a;
}

void dfs(int cur,int father)
{
	int child=0,i;
	index++;
	num[cur] = index;
	low[cur] = index;//当前顶点能访问到的最早顶点的时间戳当然是自己
	for (i = 1; i <= n; i++)
	{
		if (e[cur][i] != inf && e[cur][i] != 0)
		{
			if (num[i] == 0)//如果时间戳等于0表示当前顶点还没有被访问过
			{
				child++;
				dfs(i,cur);//继续往下深度优先遍历
				low[cur] = min(low[cur],low[i]);
				//如果当前结点不是根节点并且满足low[i]>=num[cur]，则当前结点是割点
				if (cur != root && low[i] >= num[cur])
					flag[cur] = 1;
				//如果当前结点是根结点并且根节点必须有两个孩子才是割点
				if (cur == root && child == 2)
					flag[cur] = 1;
			}
			else if (i != father)
			{
				//i被访问过并且i不是cur的父亲，则i为cur的祖先
				low[cur] = min(low[cur], num[i]);
			}
		}
	}
	return;
}

int main()
{
	int m,i,j,a,b;
	cout << "输入有几个顶点：";
	cin >> n;
	cout << "输入有几条边：";
	cin >> m;
	cout << "输入边的顶点和权值：";
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			if (i == j)e[i][j] = 0;
			else e[i][j] = inf;

	for (i = 1; i <= m; i++)
	{
		cin >> a;
		cin >> b;
		e[a][b] =1;
		e[b][a] = 1;
	}

	root = 1;

	dfs(1, root);//从1号顶点开始进行深度优先遍历

	for (i = 1; i <= n; i++)
		if (flag[i] == 1)
			cout << i;

	return 0;
}