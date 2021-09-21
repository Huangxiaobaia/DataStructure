#include <iostream>
using namespace std;

int a[10], book[10], n;
void test01(int step)
{
	int i;
	if (step == n + 1)
	{
		for (i = 1; i <= n; i++)
			cout << a[i] << " ";
		cout << "\n";
		return;//书上说这句必须加，但经过验证该句可以不加
	}

	for (i = 1; i <= n; i++)
	{
		if (book[i] == 0)
		{
			a[step] = i;
			book[i] = 1;
			test01(step+1);
			book[i] = 0;
		}
	}
	return;
}

int total=0;
void test02(int step)
{
	int i;
	if (step == 10)
	{
		if (a[1] * 100 + a[2] * 10 + a[3] + a[4] * 100 + a[5] * 10 + a[6] == a[7] * 100 + a[8] * 10 + a[9])
		{
			total++;
			cout << a[1] * 100 + a[2] * 10 + a[3] << "+" << a[4] * 100 + a[5] * 10 + a[6] << "=" << a[7] * 100 + a[8] * 10 + a[9] << "\n";
		}
	}

	for (i = 0; i <= 9; i++)
	{
		if (book[i] == 0)//表示这张牌还在手上
		{
			a[step] = i;
			book[i] = 1;
			test02(step + 1);
			book[i] = 0;
		}
	}



	return;
}

int main()
{
	//cin >> n;
	//test01(1);
	test02(1);
	cout << "total=" << total / 2;
	return 0;
}