#include <iostream>
using namespace std;

struct queue
{
	int data[100];
	int head;
	int tail;
};

struct stack
{
	int data[10];
	int top;
};

void test01()
{
	queue q1;
	queue q2;
	stack s;

	q1.head = q1.tail=1;
	q2.head = q2.tail = 1;
	s.top = 0;

	//����6��ֽ�ƣ��ֱ���뵽С��С������
	int i = 0;
	for (i = 0; i < 6; i++)
		cin >> q1.data[q1.tail++];
	for (i = 0; i < 6; i++)
		cin >> q2.data[q2.tail++];

	int temp,flag=0;
	while (q1.head != q1.tail&&q2.head != q2.tail)
	{
		//С�߳���
		temp = q1.data[q1.head];
		for (i = 1; i <= s.top; i++)
		{
			if (s.data[i] == temp)
			{
				flag = 1;//��������ȵ���
				break;
			}
		}

		if (flag == 1)
		{
			//��������Ƴ���
			q1.head++;
			q1.data[q1.tail++] = temp;//����Ӯ�ƣ���������Ʒŵ���β
			//С���������ϵ�һ������
			while (s.data[s.top] != temp)
			{
				q1.data[q1.tail] = s.data[s.top];
				q1.tail++;
				s.top--;
			}
			q1.data[q1.tail++] = s.data[s.top--];//������Ƶ���һ��Ҳ�����β
		}

		if (flag == 0)
		{
			s.data[++s.top] = temp;
			q1.head++;
		}

		if (q1.head == q1.tail)break;

		flag = 0;

		//С������
		temp = q2.data[q2.head];
		for (i = 1; i <= s.top; i++)
		{
			if (s.data[i] == temp)
			{
				flag = 1;//��������ȵ���
				break;
			}
		}

		if (flag == 1)
		{
			//��������Ƴ���
			q2.head++;
			q2.data[q2.tail++] = temp;//����Ӯ�ƣ���������Ʒŵ���β
			//С���������ϵ�һ������
			while (s.data[s.top] != temp)
			{
				q2.data[q2.tail] = s.data[s.top];
				q2.tail++;
				s.top--;
			}
			q2.data[q2.tail++] = s.data[s.top--];//������Ƶ���һ��Ҳ�����β
		}

		if (flag == 0)
		{
			s.data[++s.top] = temp;
			q2.head++;
		}

		flag = 0;
	}

	if (q1.head != q1.tail)
	{
		cout << "С��win\n";
		cout << "С�ߵ�ǰ���е����ǣ�";
		for(i=q1.head;i<q1.tail;i++)
			cout << q1.data[i] << " ";
		
		if (s.top != 0)
		{
			cout << "\n" << "���ϵ����ǣ�";
			for (i = 1; i <=s.top; i++)
				cout << s.data[i] << " ";
		}
		else
		{
			cout << "\n" << "�����Ѿ�û������";
		}
	}

	if (q2.head != q2.tail)
	{
		cout << "С��win\n";
		cout << "С����ǰ���е����ǣ�";
		for (i = q2.head; i < q2.tail; i++)
			cout << q2.data[i] << " ";

		if (s.top != 0)
		{
			cout << "\n" << "���ϵ����ǣ�";
			for (i = 1; i <= s.top; i++)
				cout << s.data[i] << " ";
		}
		else
		{
			cout << "\n" << "�����Ѿ�û������";
		}
	}
}

void test02()
{
	queue q1;
	queue q2;
	stack s;

	q1.head = q1.tail = 1;
	q2.head = q2.tail = 1;
	s.top = 0;

	int book[10];

	//����6��ֽ�ƣ��ֱ���뵽С��С������
	int i = 0;

	for (i = 0; i < 10; i++)
		book[i] = 0;

	for (i = 0; i < 6; i++)
		cin >> q1.data[q1.tail++];
	for (i = 0; i < 6; i++)
		cin >> q2.data[q2.tail++];

	int temp;
	while (q1.head != q1.tail&&q2.head != q2.tail)
	{
		//С�߳���
		temp = q1.data[q1.head];
		

		if (book[temp]!=0)
		{
			//��������Ƴ���
			q1.head++;
			q1.data[q1.tail++] = temp;//����Ӯ�ƣ���������Ʒŵ���β
			//С���������ϵ�һ������
			while (s.data[s.top] != temp)
			{
				book[s.data[s.top]] = 0;//ȡ�����
				q1.data[q1.tail] = s.data[s.top];
				q1.tail++;
				s.top--;
			}
			book[s.data[s.top]] = 0;//����ͬ���ŵ���һ��Ҳȡ�����
			q1.data[q1.tail++] = s.data[s.top--];//������Ƶ���һ��Ҳ�����β
		}

		if (book[temp]==0)
		{
			s.data[++s.top] = temp;
			q1.head++;
			book[temp] = 1;//��������������Ѿ�������Ϊt����
		}

		if (q1.head == q1.tail)break;
		

		//С������
		temp = q2.data[q2.head];
	
		if (book[temp]!=0)
		{
			//��������Ƴ���
			q2.head++;
			q2.data[q2.tail++] = temp;//����Ӯ�ƣ���������Ʒŵ���β
			//С���������ϵ�һ������
			while (s.data[s.top] != temp)
			{
				book[s.data[s.top]] = 0;//ȡ�����
				q2.data[q2.tail] = s.data[s.top];
				q2.tail++;
				s.top--;
			}
			book[s.data[s.top]] = 0;
			q2.data[q2.tail++] = s.data[s.top--];//������Ƶ���һ��Ҳ�����β
		}

		if (book[temp]==0)
		{
			s.data[++s.top] = temp;
			q2.head++;
			book[temp] = 1;
		}

	}

	if (q1.head != q1.tail)
	{
		cout << "С��win\n";
		cout << "С�ߵ�ǰ���е����ǣ�";
		for (i = q1.head; i < q1.tail; i++)
			cout << q1.data[i] << " ";

		if (s.top != 0)
		{
			cout << "\n" << "���ϵ����ǣ�";
			for (i = 1; i <= s.top; i++)
				cout << s.data[i] << " ";
		}
		else
		{
			cout << "\n" << "�����Ѿ�û������";
		}
	}

	if (q2.head != q2.tail)
	{
		cout << "С��win\n";
		cout << "С����ǰ���е����ǣ�";
		for (i = q2.head; i < q2.tail; i++)
			cout << q2.data[i] << " ";

		if (s.top != 0)
		{
			cout << "\n" << "���ϵ����ǣ�";
			for (i = 1; i <= s.top; i++)
				cout << s.data[i] << " ";
		}
		else
		{
			cout << "\n" << "�����Ѿ�û������";
		}
	}
}

int main()
{
	//test01();
	test02();
	return 0;
}