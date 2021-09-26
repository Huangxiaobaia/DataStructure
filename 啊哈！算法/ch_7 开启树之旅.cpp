#include <iostream>
using namespace std;

int h[100],n;

void siftdown_(int i);

void siftdown(int i)
{
	int t,flag = 0;
	while(i*2<=n&&flag==0)
	{
		//�ж�������
		if (h[i] > h[2 * i])
		{
			t = 2 * i;
		}
		else
			t = i;
		//�ж�������
		if (2 * i + 1 <= n && h[t] > h[2 * i + 1])//����Ҷ��ӵ�ֵ��С������½�С�Ľ����
		{
			t = 2 * i + 1;
		}
		
		if (t != i)
		{
			swap(h[t], h[i]);
			i = t;
		}
		else
			flag = 1;
	}
	return;
}

void create()
{
	int i = n / 2;//�ҵ����һ����Ҷ�ӽ��
	for (; i >= 1; i--)
		siftdown_(i);//���µ���
	return;
}

int deletemin()
{
	int t;
	t = h[1];
	h[1] = h[n];
	n--;
	siftdown(1);
	return t;
}

void siftdown_(int i)
{
	int t,flag = 0;//����Ƿ���Ҫ�������µ���
	while (i <= n / 2 && flag == 0)
	{
		//���������Ƚ�
		if (h[i] < h[2 * i])
		{
			t = 2 * i;
		}
		else
			t = i;
		//���������Ƚ�
		if (h[t] < h[2 * i + 1]&&2*i+1<=n)
		{
			t = 2 * i + 1;
		}
		if (t != i)
		{
			swap(h[t], h[i]);
			i = t;//����iΪ�ղ����������Ķ��ӽ��ı�ţ����ڽ�������������
		}
		else
			flag = 1;
	}
	return;
}

void heapsort()
{
	while (n > 1)
	{
		swap(h[1], h[n]);
		n--;
		siftdown_(1);
	}
	return;
}

void test01()
{
	int m,i;
	cout << "����Ҫ��������ֵĸ�����";
	cin >> m;
	cout << "�������֣�";
	for (i = 1; i <= m; i++)
		cin >> h[i];

	n = m;
	//�����
	create();

	//������
	heapsort();

	for (i = 1; i <= m; i++)
		cout << h[i]<<" ";

	return;
}
/* 99 5 36 7 22 17 46 12 2 19 25 28 1 92 */



int main()
{
	test01();
	return 0;
}