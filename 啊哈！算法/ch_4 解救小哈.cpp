#include <iostream>
using namespace std;

int a[50][50], book[50][50];
int min=999,m,n,desx,desy;

void dfs(int x, int y, int step)
{
	int next[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
	int nx, ny, i;
	//�ж��Ƿ��ҵ�С��
	if (x == desx && y == desy)
	{
		if (step < min)
			min = step;
		return;
	}
	//�������ַ���
	for (i = 0; i < 4; i++)
	{
		nx = x+next[i][0];
		ny = y+next[i][1];
		//�ж��Ƿ�Խ��
		if (nx<1 || nx>n || ny<1 || ny>m)
			continue;
		//�ж��Ƿ�Ϊ�ϰ�����Ѿ���·����
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
	cout << "����m��n�У�";
	cin >> m>>n;
	cout << "����" << m << "��" << n << "�е����ݣ�";
	for(i=1;i<=m;i++)
		for (j = 1; j <=n; j++)
		{
			cin >> a[i][j];
		}

	//��㡢�յ�����
	cout << "������㡢�յ����꣺";
	cin >> startx >> starty >> desx >> desy;

	book[startx][starty] = 1;

	dfs(startx, starty, 0);

	cout << "��̲���Ϊ��" << min << "\n";

	return;
}

int main()
{
	test01();
	return 0;
}