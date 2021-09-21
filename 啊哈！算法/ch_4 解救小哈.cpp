#include <iostream>
using namespace std;

int a[50][50], book[50][50];
int min=999,m,n,desx,desy;

void dfs(int x, int y, int step)
{
	int next[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
	int nx, ny, i;
	//判断是否找到小哈
	if (x == desx && y == desy)
	{
		if (step < min)
			min = step;
		return;
	}
	//遍历四种方向
	for (i = 0; i < 4; i++)
	{
		nx = x+next[i][0];
		ny = y+next[i][1];
		//判断是否越界
		if (nx<1 || nx>n || ny<1 || ny>m)
			continue;
		//判断是否为障碍物或已经在路径中
		if (a[nx][ny] ==0 && book[nx][ny] == 0)
		{
			book[nx][ny] = 1;
			dfs(nx, ny, step + 1);
			book[nx][ny] = 0;
		}
	}
	return;
}

void test01()
{
	int i,j,startx,starty;
	cout << "输入m行n列：";
	cin >> m>>n;
	cout << "输入" << m << "行" << n << "列的数据：";
	for(i=1;i<=m;i++)
		for (j = 1; j <=n; j++)
		{
			cin >> a[i][j];
		}

	//起点、终点坐标
	cout << "输入起点、终点坐标：";
	cin >> startx >> starty >> desx >> desy;

	book[startx][starty] = 1;

	dfs(startx, starty, 0);

	cout << "最短步数为：" << min << "\n";

	return;
}

int main()
{
	test01();
	return 0;
}