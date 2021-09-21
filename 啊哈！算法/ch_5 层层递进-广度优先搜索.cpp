#include <iostream>
using namespace std;

struct note
{
	int x;
	int y;
	int f;//父亲在队列中的编号
	int s;//步数
};

void test01()
{
	int a[50][50] = { 0 }, book[50][50] = { 0 };
	int next[][2] = { {0,1},{1,0},{0,-1},{-1,0} };
	int m, n, startx, starty, desx, desy,i,j,nx,ny,flag=0;
	int head, tail;
	cout << "输入m行n列：";
	cin >> m >> n;
	cout << "输入" << m << "行" << n << "列的数据：";
	for (i = 1; i <= m; i++)
		for (j = 1; j <= n; j++)
		{
			cin >> a[i][j];
		}

	//起点、终点坐标
	cout << "输入起点、终点坐标：";
	cin >> startx >> starty >> desx >> desy;

	book[startx][starty] = 1;
	struct note que[2500];
	head = tail = 1;
	que[tail].x = startx;
	que[tail].y = starty;
	que[tail].f = 0;
	que[tail].s = 0;
	tail++;
	
	while (head < tail)
	{
		//四个方向
		for (i = 0; i < 4; i++)
		{
			nx = que[head].x + next[i][0];
			ny = que[head].y + next[i][1];
			//判断是否越界
			if (nx<1 || nx>m || ny<1 || ny>n)
			{
				continue;
			}
			//判断是否为障碍物或者已经走过
			if (a[nx][ny] == 0 && book[nx][ny] == 0)
			{
				book[nx][ny] = 1;
				que[tail].x = nx;
				que[tail].y = ny;
				que[tail].f = head;
				que[tail].s = que[head].s + 1;
				tail++;
			}
			//判断是否已找到
			if (nx == desx && ny == desy)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 1)
			break;
		head++;//出队
		
	}
	cout << "最短步数为：" << que[tail - 1].s;
	cout << "路径为：" << "\n";
	i = tail - 1;
	while (que[i].f != 0)
	{
		cout << que[i].x << "," << que[i].y << " ";
		i = que[i].f;
	}
	cout << 1 << "," << 1;
}

int main()
{
	test01();
	return 0;
}