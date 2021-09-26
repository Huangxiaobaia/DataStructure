#include <iostream>
using namespace std;

int h[100],n;

void siftdown_(int i);

void siftdown(int i)
{
	int t,flag = 0;
	while(i*2<=n&&flag==0)
	{
		//判断左子树
		if (h[i] > h[2 * i])
		{
			t = 2 * i;
		}
		else
			t = i;
		//判断右子树
		if (2 * i + 1 <= n && h[t] > h[2 * i + 1])//如果右儿子的值更小，则更新较小的结点编号
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
	int i = n / 2;//找到最后一个非叶子结点
	for (; i >= 1; i--)
		siftdown_(i);//向下调整
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
	int t,flag = 0;//标记是否需要继续向下调整
	while (i <= n / 2 && flag == 0)
	{
		//与左子树比较
		if (h[i] < h[2 * i])
		{
			t = 2 * i;
		}
		else
			t = i;
		//与右子树比较
		if (h[t] < h[2 * i + 1]&&2*i+1<=n)
		{
			t = 2 * i + 1;
		}
		if (t != i)
		{
			swap(h[t], h[i]);
			i = t;//更新i为刚才与它交换的儿子结点的编号，便于接下来继续调整
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
	cout << "输入要排序的数字的个数：";
	cin >> m;
	cout << "输入数字：";
	for (i = 1; i <= m; i++)
		cin >> h[i];

	n = m;
	//创造堆
	create();

	//堆排序
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