#include <iostream>
using namespace std;

void test01()
{
	int n, m, i,k;
	int dis[10], book[10] = {0};
	int u[10], v[10], w[10];
	int first[100], next[100];
	int que[100];
	int head, tail;
	cout << "���빲�м������㣺";
	cin >> n;
	cout << "���빲�м����ߣ�";
	cin >> m;
	for (i = 1; i <= 10; i++)
		first[i] = -1;
	//ѭ������m����
	for (i = 1; i <= m; i++)
	{
		cin >> u[i];
		cin >> v[i];
		cin >> w[i];
		//�����ڽӱ�Ĺؼ�
		next[i] = first[u[i]];//�洢���Ǳ��Ϊi�ĵ����һ���ߵı��
		first[u[i]] = i;//�洢����u[i]�Ŷ����һ���ߵı��
	}

	int inf = 999999;
	for (i = 1; i <= n; i++)
		dis[i] = inf;
	dis[1] = 0;

	//1�Ŷ������
	head = tail = 1;
	que[head] = 1;
	tail++;
	book[1] = 1;//���1���Ѿ����

	while (head < tail)
	{
		k = first[que[head]];//��ǰ��Ҫ����Ķ��׶���
		while(k != -1)
		{
			if (dis[v[k]] > dis[u[k]] + w[k])
			{
				dis[v[k]] = dis[u[k]] + w[k];
				//v[k]������ڶ��������
				if (book[v[k]] == 0)
				{
					que[tail] = v[k];
					tail++;
					book[v[k]] = 1;
				}
			}
			k = next[k];
		}
		//����
		book[que[head]] = 0;
		head++;
	}
	for (i = 1; i <= n; i++)
		cout << dis[i] << " ";

}
/*
1 2 2
1 5 10
2 3 3
2 5 7
3 4 4
4 5 5
5 3 6
*/
int main()
{
	test01();
	return 0;
}