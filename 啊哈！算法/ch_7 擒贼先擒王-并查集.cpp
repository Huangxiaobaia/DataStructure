#include <iostream>
using namespace std;

int f[100] = { 0 };

int getf(int v)
{
	if (f[v] == v)return f[v];
	else
	{
		f[v] = getf(f[v]);
		return f[v];
	}
}

void merge(int a, int b)
{
	int t1, t2;

	t1 = getf(a);
	t2 = getf(b);

	if (t1 != t2)
	{
		f[t2] = t1;//����ԭ��
	}

	return;
}
/* 1 2
3 4
5 2
4 6
2 6
7 11
8 7
9 7
9 11
1 6 */
int main()
{
	int n, m,i,a,b,sum=0;
	cout << "�����м���ǿ����";
	cin >> n;
	for (i = 1; i <= 100; i++)
		f[i] = i;
	cout << "�����м���ǿ��ͬ���ϵ��";
	cin >> m;
	cout << "��������ǿ��ͬ���ϵ��";
	for (i = 1; i <= m; i++)
	{
		cin >> a;
		cin >> b;
		//�ϲ�����ͬ��
		merge(a, b);
	}

	for (i = 1; i <= n; i++)
		if (f[i] == i)
			sum++;
	cout << "����" << sum << "������ͬ��";

	return 0;
}