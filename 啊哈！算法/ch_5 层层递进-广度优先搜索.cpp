#include <iostream>
using namespace std;

struct note
{
	int x;
	int y;
	int f;//�����ڶ����еı��
	int s;//����
};

void test01()
{
	int a[50][50] = { 0 }, book[50][50] = { 0 };
	int next[][2] = { {0,1},{1,0},{0,-1},{-1,0} };
	int m, n, startx, starty, desx, desy,i,j,nx,ny,flag=0;
	int head, tail;
	cout << "����m��n�У�";
	cin >> m >> n;
	cout << "����" << m << "��" << n << "�е����ݣ�";
	for (i = 1; i <= m; i++)
		for (j = 1; j <= n; j++)
		{
			cin >> a[i][j];
		}

	//��㡢�յ�����
	cout << "������㡢�յ����꣺";
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
		//�ĸ�����
		for (i = 0; i < 4; i++)
		{
			nx = que[head].x + next[i][0];
			ny = que[head].y + next[i][1];
			//�ж��Ƿ�Խ��
			if (nx<1 || nx>m || ny<1 || ny>n)
			{
				continue;
			}
			//�ж��Ƿ�Ϊ�ϰ�������Ѿ��߹�
			if (a[nx][ny] == 0 && book[nx][ny] == 0)
			{
				book[nx][ny] = 1;
				que[tail].x = nx;
				que[tail].y = ny;
				que[tail].f = head;
				que[tail].s = que[head].s + 1;
				tail++;
			}
			//�ж��Ƿ����ҵ�
			if (nx == desx && ny == desy)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 1)
			break;
		head++;//����
		
	}
	cout << "��̲���Ϊ��" << que[tail - 1].s;
	cout << "·��Ϊ��" << "\n";
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