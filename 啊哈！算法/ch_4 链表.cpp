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
	cout << "ѭ������n������";
	cin >> n;

	struct node *head,*p,*q=NULL,*t;

	head = NULL;

	cout << "����n������ֵ��" << endl;
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

	//��������е�������
	t = head;
	cout << "�������";
	while (t != NULL)
	{
		cout << t->data << " ";
		t = t->next;
	}

	cout << "��������������" << endl;
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

	//��������е�������
	t = head;
	cout << "�������";
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