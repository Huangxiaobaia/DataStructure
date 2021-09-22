#include <iostream>
using namespace std;

int a[50][50];//���صĴ�С
int book[50][50];
int n, m,flag=0;

struct note
{
	int x;
	int y;
}s[100];
int top = 0;

void dfs(int x, int y, int front)
{
	//�ж��Ƿ񵽴��յ�
	if (x == n && y == m + 1)
	{
		int i;
		flag = 1;
		for (i = 0; i < top; i++)
			cout << "(" << s[i].x << "," << s[i].y << ") ";
		cout << "\n";
		return;
	}
	//�ж��Ƿ�Խ��
	if (x<1 || x>n || y<1 || y>m)
	{
		return;
	}
	//�ж�����ܵ��Ƿ���·����ʹ�ù�
	if (book[x][y] == 1)
		return;
	book[x][y] = 1;
	s[top].x = x;
	s[top].y = y;
	top++;
	//ֱ�����
	if (a[x][y] == 5 || a[x][y] == 6)
	{
		if (front == 1)//��ˮ�������
		{
			dfs(x, y + 1, 1);
		}
		if (front == 2)//��ˮ�����ϱ�
		{
			dfs(x + 1, y, 2);
		}
		if (front == 3)//��ˮ�����ұ�
		{
			dfs(x, y - 1, 3);
		}
		if (front == 4)//��ˮ�����±�
		{
			dfs(x - 1, y, 4);
		}
	}
	//������
	if (a[x][y] >= 1 && a[x][y] <= 4)
	{
		if (front == 1)
		{
			dfs(x - 1, y, 4);
			dfs(x + 1, y, 2);
		}
		if (front == 2)
		{
			dfs(x, y-1, 3);
			dfs(x, y+1, 1);
		}
		if (front == 3)
		{
			dfs(x - 1, y, 4);
			dfs(x + 1, y, 2);
		}
		if (front == 4)
		{
			dfs(x, y-1, 3);
			dfs(x, y+1, 1);
		}
	}
	book[x][y] = 0;
	top--;
	return;
}

void test01()
{
	int i, j;
	cout << "n���ַ���";
	cin >> n;
	cout << "\n" << "ÿ����m�У�";
	cin >> m;

	//����ÿ������
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			cin >> a[i][j];
	//��һ�����ˮ�������
	dfs(1, 1, 1);
	if (flag == 1)
		cout << "�ҵ����跽��";
	else
		cout << "�Ҳ������跽��";
}

/*
5 3 5 3
1 5 3 0
2 3 5 1
6 1 1 5
1 5 5 4
*/

int main()
{
	test01();
	return 0;
}