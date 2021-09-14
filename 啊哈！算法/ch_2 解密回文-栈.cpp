#include <iostream>
using namespace std;

void test01()
{
	char stack[100];//定义栈
	char a[100];
	int top=0;//栈顶
	int i,next;
	gets_s(a, 100);//读入字符串
	int len = strlen(a);
	int mid = len / 2-1;

	for (i = 0; i <= mid; i++)
		stack[++top] = a[i];

	if (len % 2 == 0)
		next = mid + 1;
	else
		next = mid + 2;

	while (top > 0)
	{
		if (a[next++] != stack[top--])break;
	}

	if (top == 0)
		cout << "是回文字符串" << endl;
	else
		cout << "不是回文字符串" << endl;
}

int main()
{
	test01();
	return 0;
}