#include <iostream>
using namespace std;

//简化版桶排序
void test01()
{
	int t[11],i,j;
	for (i = 0; i < 11; i++)
		t[i] = 0;//初始化

	for (i = 0; i < 5; i++)
	{
		cin >> j;
		t[j]++;
	}

	for (i = 0; i < 11; i++)
		for (j = 0; j < t[i]; j++)
			cout << i << " ";

}

//冒泡排序
void test02()
{
	int t[100], n,i,j,temp;
	cout << "共输入n个数：" ;
	cin >> n;
	cout << "开始输入：";
	for (i = 0; i < n; i++)
		cin >> t[i];

	for(i=0;i<n-1;i++)//共n-1趟
		for(j=0;j<n-1-i;j++)//每趟共比较n-1-i次
			if (t[j] < t[j + 1])
			{
				temp = t[j];
				t[j] = t[j + 1];
				t[j + 1] = temp;
			}
	cout << "排序后为：\n";
	for (i = 0; i < n; i++)
		cout << t[i] << " ";
}

//快速排序
int t[100];
void quicksort(int left, int right)
{
	int i = left, j = right;//设置哨兵
	int p;
	if (left > right)return;
	int temp = t[left];//设置基准数
	while (i != j)
	{
		while (i < j&&t[j] >= temp)
			j--;
		while (i < j&&t[i] <= temp)
			i++;
		if (i < j)
		{
			p = t[i];
			t[i] = t[j];
			t[j] = p;
		}
	}
	//此时i=j，基准数归位
	t[left] = t[i];
	t[i] = temp;
	//继续处理两边的
	quicksort(left, i - 1);
	quicksort(i+1, right);
	return;
}

void test03()
{
	int n,i;
	cout << "共输入n个数：";
	cin >> n;
	cout << "开始输入：";
	for (i = 0; i < n; i++)
		cin >> t[i];

	quicksort(0,n-1);

	cout << "排序后为：\n";
	for (i = 0; i < n; i++)
		cout << t[i] << " ";
}

//小哼买书
void test04()
{
	int n, i,length=1,q[100],j=0;
	cout << "共有n个同学参与调查：";
	cin >> n;
	cout << "每位同学喜欢书籍的ISBN号：";
	for (i = 0; i < n; i++)
		cin >> t[i];

	quicksort(0, n - 1);
	q[0] = t[0];
	for (i = 1; i < n; i++)
	{
		if (t[i] != t[i - 1])
		{
			length++;
			q[++j] = t[i];
		}
	}

	cout << "需要买的本数：" << length << endl;
	cout << "每本书的ISBN号：" << endl;
	for (i = 0; i < length; i++)
		cout << q[i] << " ";
}


int main()
{
	//test01();
	//test02();
	//test03();
	test04();
	return 0;
}