#include <iostream>
using namespace std;

int root,n;
int flag[10], num[10], low[10],index;//index��������ʱ����ĵ���
int inf = 999999;
int e[10][10];

int min(int a, int b)
{
	return a > b ? b : a;
}

void dfs(int cur,int father)
{
	int child=0,i;
	index++;
	num[cur] = index;
	low[cur] = index;//��ǰ�����ܷ��ʵ������綥���ʱ�����Ȼ���Լ�
	for (i = 1; i <= n; i++)
	{
		if (e[cur][i] != inf && e[cur][i] != 0)
		{
			if (num[i] == 0)//���ʱ�������0��ʾ��ǰ���㻹û�б����ʹ�
			{
				child++;
				dfs(i,cur);//��������������ȱ���
				low[cur] = min(low[cur],low[i]);
				//�����ǰ��㲻�Ǹ��ڵ㲢������low[i]>=num[cur]����ǰ����Ǹ��
				if (cur != root && low[i] >= num[cur])
					flag[cur] = 1;
				//�����ǰ����Ǹ���㲢�Ҹ��ڵ�������������Ӳ��Ǹ��
				if (cur == root && child == 2)
					flag[cur] = 1;
			}
			else if (i != father)
			{
				//i�����ʹ�����i����cur�ĸ��ף���iΪcur������
				low[cur] = min(low[cur], num[i]);
			}
		}
	}
	return;
}

int main()
{
	int m,i,j,a,b;
	cout << "�����м������㣺";
	cin >> n;
	cout << "�����м����ߣ�";
	cin >> m;
	cout << "����ߵĶ����Ȩֵ��";
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			if (i == j)e[i][j] = 0;
			else e[i][j] = inf;

	for (i = 1; i <= m; i++)
	{
		cin >> a;
		cin >> b;
		e[a][b] =1;
		e[b][a] = 1;
	}

	root = 1;

	dfs(1, root);//��1�Ŷ��㿪ʼ����������ȱ���

	for (i = 1; i <= n; i++)
		if (flag[i] == 1)
			cout << i;

	return 0;
}