#include <iostream>
using namespace std;

void test01()
{
	char stack[100];//����ջ
	char a[100];
	int top=0;//ջ��
	int i,next;
	gets_s(a, 100);//�����ַ���
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
		cout << "�ǻ����ַ���" << endl;
	else
		cout << "���ǻ����ַ���" << endl;
}

int main()
{
	test01();
	return 0;
}