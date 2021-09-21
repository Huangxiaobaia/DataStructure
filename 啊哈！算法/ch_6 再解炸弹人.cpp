#include <iostream>
using namespace std;

struct note
{
	int x;
	int y;
};

char a[20][21];

int getnum(int i, int j)
{
	int sum,x,y;

	sum = 0;//可以消灭的敌人数
	x = i;
	y = j;
	//向下统计可以消灭的敌人数
	x++;
	while (a[x][y] != '#')//判断是不是墙
	{
		if (a[x][y] == 'G')
			sum++;
		x++;
	}

	x = i;
	y = j;
	//向上统计可以消灭的敌人数
	x--;
	while (a[x][y] != '#')//判断是不是墙
	{
		if (a[x][y] == 'G')
			sum++;
		x--;
	}

	x = i;
	y = j;
	//向左统计可以消灭的敌人数
	y--;
	while (a[x][y] != '#')//判断是不是墙
	{
		if (a[x][y] == 'G')
			sum++;
		y--;
	}

	x = i;
	y = j;
	//向右统计可以消灭的敌人数
	y++;
	while (a[x][y] != '#')//判断是不是墙
	{
		if (a[x][y] == 'G')
			sum++;
		y++;
	}
	return sum;
}

void test01()
{
	int m, n,i,head,tail,startx,starty,max,nx,ny,sum,mx,my;
	int book[20][21] = { 0 };
	int next[][2] = { {0,1},{1,0},{0,-1},{-1,0} };
	cout << "n行字符：";
	cin >> n;
	cout << "\n" << "每行有m列：";
	cin >> m;

	//读入每行字符
	for (i = 0; i <= n - 1; i++)
		cin >> a[i];

	cout << "输入起点、终点坐标：";
	cin >> startx >> starty;

	struct note que[401];
	head = tail = 1;
	que[head].x = startx;
	que[head].y = starty;
	tail++;
	book[startx][starty] = 1;
	max = getnum(startx, starty);
	while (head < tail)
	{
		for (i = 0; i <= 3; i++)
		{
			nx = que[head].x + next[i][0];
			ny = que[head].y + next[i][1];
			//判断是否越界
			if (nx<1 || nx>m || ny<1 || ny>n)
			{
				continue;
			}
			//判断是否为平地或曾经走过
			if (a[nx][ny] == '.'&&book[nx][ny] == 0)
			{
				book[nx][ny] = 1;
				que[tail].x = nx;
				que[tail].y = ny;
				tail++;
				sum = getnum(nx, ny);
				if (sum > max)
				{
					max = sum;
					mx = nx;
					my = ny;
				}
			}
		}
		head++;
	}
	cout << "将炸弹放置在(" << mx << "," << my << ")处，最多可消灭敌人" << max;
}

int main()
{
	test01();
	return 0;
}