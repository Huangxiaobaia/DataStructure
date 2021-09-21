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

	sum = 0;//��������ĵ�����
	x = i;
	y = j;
	//����ͳ�ƿ�������ĵ�����
	x++;
	while (a[x][y] != '#')//�ж��ǲ���ǽ
	{
		if (a[x][y] == 'G')
			sum++;
		x++;
	}

	x = i;
	y = j;
	//����ͳ�ƿ�������ĵ�����
	x--;
	while (a[x][y] != '#')//�ж��ǲ���ǽ
	{
		if (a[x][y] == 'G')
			sum++;
		x--;
	}

	x = i;
	y = j;
	//����ͳ�ƿ�������ĵ�����
	y--;
	while (a[x][y] != '#')//�ж��ǲ���ǽ
	{
		if (a[x][y] == 'G')
			sum++;
		y--;
	}

	x = i;
	y = j;
	//����ͳ�ƿ�������ĵ�����
	y++;
	while (a[x][y] != '#')//�ж��ǲ���ǽ
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
	cout << "n���ַ���";
	cin >> n;
	cout << "\n" << "ÿ����m�У�";
	cin >> m;

	//����ÿ���ַ�
	for (i = 0; i <= n - 1; i++)
		cin >> a[i];

	cout << "������㡢�յ����꣺";
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
			//�ж��Ƿ�Խ��
			if (nx<1 || nx>m || ny<1 || ny>n)
			{
				continue;
			}
			//�ж��Ƿ�Ϊƽ�ػ������߹�
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
	cout << "��ը��������(" << mx << "," << my << ")���������������" << max;
}

int main()
{
	test01();
	return 0;
}