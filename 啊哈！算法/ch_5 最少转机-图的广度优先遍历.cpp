#include <iostream>
using namespace std;

struct note
{
	int x;//���б��
	int s;//ת������
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


	cout << "���빲�м������㣺";
	cin >> n;
	//��ʼ���ڽӾ���
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			if (i == j)e[i][j] = 0;
			else e[i][j] = 999999;
	cout << "���빲�м����ߣ�";
	cin >> m;
	cout << "����߶�Ӧ�Ķ��㣺";
	for (i = 1; i <= m; i++)
	{
		cin >> a;
		cin >> b;
		e[a][b] = 1;
		e[b][a] = 1;
	}
	cout << "������㣺";
	cin >> start;
	cout << "�����յ㣺";
	cin >> end;
	book[1] = 1;
	que[1].x = start;
	que[1].s = 0;
	tail++;

	flag = 0;
	while (head < tail)
	{
		cur = que[head].x;//��ǰ�������׳��еı��
		//û�е����յ㣬�����Ըõ�Ϊ����ı�
		for (i = 1; i <= n; i++)
		{
			if (e[cur][i] != 0 && e[cur][i] != 999999 && book[i] == 0)
			{
				book[i] = 1;
				que[tail].x = i;
				que[tail].s=que[head].s+1;
				tail++;
			}
			if (que[tail - 1].x == end)//�ж��Ƿ񵽴��յ�
			{
				cout << "ת��������" << que[tail - 1].s;
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