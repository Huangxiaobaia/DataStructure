#include <iostream>
using namespace std;

struct note
{
	int x;
	int y;
};

void test01()
{
	struct note que[2501];
	int head, tail;
	head = 1;
	tail = 1;
	int a[50][50], book[50][50] = {0};
	int next[][2] = { {0,1},{1,0},{0,-1},{-1,0} };

	int m, n, i,j, startx, starty,nx,ny,sum=1;
	cout << "n行字符：";
	cin >> n;
	cout << "\n" << "每行有m列：";
	cin >> m;

	//读入每行字符
	for (i = 1; i <= n; i++)
		for(j=1;j<=m;j++)
			cin >> a[i][j];

	cout << "输入起点：";
	cin >> startx >> starty;

	que[tail].x = startx;
	que[tail].y = starty;
	book[startx][starty] = 1;
	tail++;

	while (head < tail)
	{
		//遍历周围点
		for (i = 0; i <= 3; i++)
		{
			nx =que[head].x+next[i][0];
			ny = que[head].y + next[i][1];

			//判断是否越界
			if (nx<1 || nx>n || ny<1 || ny>m)
				continue;
			//判断是否为陆地或曾经是否走过
			if (book[nx][ny] == 0 && a[nx][ny] > 0)
			{
				sum++;
				que[tail].x = nx;
				que[tail].y = ny;
				tail++;
				book[nx][ny] = 1;
			}
		}
		head++;
	}
	cout << sum;
}

/*

1 2 1 0 0 0 0 0 2 3
3 0 2 0 1 2 1 0 1 2
4 0 1 0 1 2 3 2 0 1
3 2 0 0 0 1 2 4 0 0
0 0 0 0 0 0 1 5 3 0
0 1 2 1 0 1 5 4 3 0
0 1 2 3 1 3 6 2 1 0
0 0 3 4 8 9 7 5 0 0
0 0 0 3 7 8 6 0 1 2
0 0 0 0 0 0 0 0 1 0
*/

int a[50][50], book[50][50] = { 0 };
int n, m,sum;
void dfs(int x,int y,int color)
{
	int next[][2] = { {0,1},{1,0},{0,-1},{-1,0} };
	a[x][y] = color;
	int i,nx,ny;
	//遍历周围点
	for (i = 0; i <= 3; i++)
	{
		nx =x + next[i][0];
		ny =y + next[i][1];

		//判断是否越界
		if (nx<1 || nx>n || ny<1 || ny>m)
			continue;
		//判断是否为陆地或曾经是否走过
		if (book[nx][ny] == 0 && a[nx][ny] > 0)
		{
			sum++;
			book[nx][ny] = 1;
			dfs(nx, ny, color);
		}
	}
	return;
}

void test02()
{
	int i,j, startx, starty,num=0;
	cout << "n行字符：";
	cin >> n;
	cout << "\n" << "每行有m列：";
	cin >> m;

	//读入每行字符
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			cin >> a[i][j];

	for(i=1;i<=n;i++)
		for (j = 1; j <= m; j++)
		{
			if (a[i][j] > 0 && book[i][j] == 0)
			{
				num--;
				book[i][j] = 1;
				dfs(i, j, num);
			}
		}

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "小岛个数：" <<- num;
}

int main()
{
	//test01();
	test02();
	return 0;
}