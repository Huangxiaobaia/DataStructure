#include <iostream>
using namespace std;

struct note
{
	int x;//城市编号
	int s;//转机次数
};

void test01()
{
	int n, m, i, j, a, b,start,end,cur,flag;
	int e[50][50];
	int book[2500] = {0};
	struct note que[50];
	int head, tail;
	head = 1;
	tail = 1;


	cout << "输入共有几个顶点：";
	cin >> n;
	//初始化邻接矩阵
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			if (i == j)e[i][j] = 0;
			else e[i][j] = 999999;
	cout << "输入共有几条边：";
	cin >> m;
	cout << "输入边对应的顶点：";
	for (i = 1; i <= m; i++)
	{
		cin >> a;
		cin >> b;
		e[a][b] = 1;
		e[b][a] = 1;
	}
	cout << "输入起点：";
	cin >> start;
	cout << "输入终点：";
	cin >> end;
	book[1] = 1;
	que[1].x = start;
	que[1].s = 0;
	tail++;

	flag = 0;
	while (head < tail)
	{
		cur = que[head].x;//当前队列中首城市的编号
		//没有到达终点，遍历以该点为顶点的边
		for (i = 1; i <= n; i++)
		{
			if (e[cur][i] != 0 && e[cur][i] != 999999 && book[i] == 0)
			{
				book[i] = 1;
				que[tail].x = i;
				que[tail].s=que[head].s+1;
				tail++;
			}
			if (que[tail - 1].x == end)//判断是否到达终点
			{
				cout << "转机次数：" << que[tail - 1].s;
				flag = 1;
				break;
			}
		}
		if (flag == 1)
			break;
		head++;
	}
}
/*
1 2
1 3
2 3
2 4
3 4
3 5
4 5
*/
int main()
{
	test01();
	return 0;
}