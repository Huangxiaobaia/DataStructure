#include <iostream>
using namespace std;

void test01()
{
	int q[100] = {0,6,3,1,7,5,8,9,2,4}, head, tail;
	head = 1;
	tail = 10;//tail指向队尾元素的后一位置
	while (head < tail)
	{
		cout << q[head] << " ";
		head++;
		q[tail++] = q[head];
		head++;
	}
}

struct queue
{
	int date[100];
	int head;
	int tail;
};

void test02()
{
	struct queue q;
	int a[]={ 0,6,3,1,7,5,8,9,2,4 };
	int i;
	q.head = 1;
	q.tail = 1;
	for (i = 0; i < 9; i++)
		q.date[q.tail++] = a[i + 1];

	while (q.head < q.tail)
	{
		cout << q.date[q.head++] << " ";
		q.date[q.tail] = q.date[q.head++];
		q.tail++;
	}
}

int main()
{
	//test01();
	test02();
	return 0;
}
