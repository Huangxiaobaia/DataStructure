#include <iostream>
using namespace std;

void test01()
{
	int n, m, i,k;
	int dis[10], book[10] = {0};
	int u[10], v[10], w[10];
	int first[100], next[100];
	int que[100];
	int head, tail;
	cout << "输入共有几个顶点：";
	cin >> n;
	cout << "输入共有几条边：";
	cin >> m;
	for (i = 1; i <= 10; i++)
		first[i] = -1;
	//循环输入m条边
	for (i = 1; i <= m; i++)
	{
		cin >> u[i];
		cin >> v[i];
		cin >> w[i];
		//建立邻接表的关键
		next[i] = first[u[i]];//存储的是编号为i的点的下一条边的编号
		first[u[i]] = i;//存储的是u[i]号顶点第一条边的编号
	}

	int inf = 999999;
	for (i = 1; i <= n; i++)
		dis[i] = inf;
	dis[1] = 0;

	//1号顶点入队
	head = tail = 1;
	que[head] = 1;
	tail++;
	book[1] = 1;//标记1号已经入队

	while (head < tail)
	{
		k = first[que[head]];//当前需要处理的队首顶点
		while(k != -1)
		{
			if (dis[v[k]] > dis[u[k]] + w[k])
			{
				dis[v[k]] = dis[u[k]] + w[k];
				//v[k]如果不在队中则入队
				if (book[v[k]] == 0)
				{
					que[tail] = v[k];
					tail++;
					book[v[k]] = 1;
				}
			}
			k = next[k];
		}
		//出队
		book[que[head]] = 0;
		head++;
	}
	for (i = 1; i <= n; i++)
		cout << dis[i] << " ";

}
/*
1 2 2
1 5 10
2 3 3
2 5 7
3 4 4
4 5 5
5 3 6
*/
int main()
{
	test01();
	return 0;
}