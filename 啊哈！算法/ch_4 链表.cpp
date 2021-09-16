#include <iostream>
using namespace std;

struct node
{
	int data;
	struct node*next;
};

void test01()
{
	int n,i,m;
	cout << "循环读入n个数：";
	cin >> n;

	struct node *head,*p,*q=NULL,*t;

	head = NULL;

	cout << "输入n个数的值：" << endl;
	for (i = 0; i < n; i++)
	{
		cin >> m;
		p = (struct node*)malloc(sizeof(struct node));
		p->data = m;
		p->next = NULL;
		if (head == NULL)
			head = p;
		else
			q->next = p;
		q = p;
	}

	//输出链表中的所有数
	t = head;
	cout << "输出链表：";
	while (t != NULL)
	{
		cout << t->data << " ";
		t = t->next;
	}

	cout << "输入待插入的数：" << endl;
	cin >> m;
	t = head;
	while (t != NULL)
	{
		if (t->next->data > m || t->data == NULL)
		{
			p = (struct node*)malloc(sizeof(struct node));
			p->data = m;
			p->next = t->next;
			t->next = p;
			break;
		}
		t = t->next;
	}

	//输出链表中的所有数
	t = head;
	cout << "输出链表：";
	while (t != NULL)
	{
		cout << t->data << " ";
		t = t->next;
	}
}

int main()
{
	test01();
	return 0;
}