#include <iostream>
using namespace std;

int e[100][100],book[100],sum,n;

//深度优先搜索
void dfs(int x)//x是当前所在顶点的编号
{
	int i;
	sum++;
	cout << x << " ";
	if (sum == n)
		return;
	for (i = 0; i < n; i++)
		if (book[i] == 0 && e[x][i] == 1)
		{
			book[i] = 1;
			dfs(i);
		}
	return;
}

void test01()
{
	int i, j,m,a,b;
	cout << "输入共有几个顶点：";
	cin >> n;
	//初始化邻接矩阵
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (i == j)e[i][j] = 0;
			else e[i][j] = 999999;
	cout << "输入共有几条边：";
	cin >> m;
	cout << "输入边对应的顶点：";
	for (i = 0; i < m; i++)
	{
		cin >> a;
		cin >> b;
		e[a][b] = 1;
		e[b][a] = 1;
	}
	book[0] = 1;           
	dfs(0);
}
//广度优先搜索
void test02()
{
	int i, j, m, n,a,b,cur;
	cout << "输入共有几个顶点：";
	cin >> n;
	//初始化邻接矩阵
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (i == j)e[i][j] = 0;
			else e[i][j] = 999999;
	cout << "输入共有几条边：";
	cin >> m;
	cout << "输入边对应的顶点：";
	for (i = 0; i < m; i++)
	{
		cin >> a;
		cin >> b;
		e[a][b] = 1;
		e[b][a] = 1;
	}

	book[0] = 1;

	int que[10000], head, tail;
	head = 0;
	tail = 0;
	que[tail] = 0;
	tail++;

	while (head < tail)
	{
		cur = que[head];
		for (i = 0; i < n; i++)
		{
			if (e[cur][i] == 1 && book[i] == 0)
			{
				que[tail] = i;
				tail++;
				book[i] = 1;
			}
			if (tail > n)//如果tail大于n则表示所有顶点已被访问
				break;
		}
		head++;
	}
	for (i = 0; i < n; i++)
		cout << que[i] << " ";
}

int main()
{
	//test01();
	test02();
	return 0;
}