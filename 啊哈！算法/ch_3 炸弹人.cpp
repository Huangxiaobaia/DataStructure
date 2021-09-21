#include <iostream>
using namespace std;

int main()
{
	//此版本存在问题

	char a[20][21];
	int i, j,n,m,sum,x,y,map=0,p,q;
	cout << "n行字符：";
	cin >> n;
	cout << "\n" << "每行有m列：";
	cin >> m;

	//读入每行字符
	for (i = 0; i <= n - 1; i++)
		cin >> a[i];

	//用两重循环枚举地图上的每一点
	for(i=0;i<=n-1;i++)
		for (j = 0; j <= m - 1; j++)
		{
			//判断这个点是不是平地，是平地可以放置炸弹
			if (a[i][j] == '.')
			{
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

				if (sum > map)
				{
					p = i;
					q = j;
					map = sum;
				}
			}
		}

	cout << "将炸弹放置在(" << p << "," << q << ")处，最多可消灭敌人" << map;

	return 0;
}