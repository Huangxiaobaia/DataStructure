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

	//读入6张纸牌，分别放入到小哼小哈手中
	int i = 0;
	for (i = 0; i < 6; i++)
		cin >> q1.data[q1.tail++];
	for (i = 0; i < 6; i++)
		cin >> q2.data[q2.tail++];

	int temp,flag=0;
	while (q1.head != q1.tail&&q2.head != q2.tail)
	{
		//小哼出牌
		temp = q1.data[q1.head];
		for (i = 1; i <= s.top; i++)
		{
			if (s.data[i] == temp)
			{
				flag = 1;//桌上有相等的牌
				break;
			}
		}

		if (flag == 1)
		{
			//将打出的牌出队
			q1.head++;
			q1.data[q1.tail++] = temp;//这轮赢牌，将打出的牌放到队尾
			//小哼收走桌上的一部分牌
			while (s.data[s.top] != temp)
			{
				q1.data[q1.tail] = s.data[s.top];
				q1.tail++;
				s.top--;
			}
			q1.data[q1.tail++] = s.data[s.top--];//将相等牌的另一张也放入队尾
		}

		if (flag == 0)
		{
			s.data[++s.top] = temp;
			q1.head++;
		}

		if (q1.head == q1.tail)break;

		flag = 0;

		//小哈出牌
		temp = q2.data[q2.head];
		for (i = 1; i <= s.top; i++)
		{
			if (s.data[i] == temp)
			{
				flag = 1;//桌上有相等的牌
				break;
			}
		}

		if (flag == 1)
		{
			//将打出的牌出队
			q2.head++;
			q2.data[q2.tail++] = temp;//这轮赢牌，将打出的牌放到队尾
			//小哈收走桌上的一部分牌
			while (s.data[s.top] != temp)
			{
				q2.data[q2.tail] = s.data[s.top];
				q2.tail++;
				s.top--;
			}
			q2.data[q2.tail++] = s.data[s.top--];//将相等牌的另一张也放入队尾
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
		cout << "小哼win\n";
		cout << "小哼当前手中的牌是：";
		for(i=q1.head;i<q1.tail;i++)
			cout << q1.data[i] << " ";
		
		if (s.top != 0)
		{
			cout << "\n" << "桌上的牌是：";
			for (i = 1; i <=s.top; i++)
				cout << s.data[i] << " ";
		}
		else
		{
			cout << "\n" << "桌上已经没有牌了";
		}
	}

	if (q2.head != q2.tail)
	{
		cout << "小哈win\n";
		cout << "小哈当前手中的牌是：";
		for (i = q2.head; i < q2.tail; i++)
			cout << q2.data[i] << " ";

		if (s.top != 0)
		{
			cout << "\n" << "桌上的牌是：";
			for (i = 1; i <= s.top; i++)
				cout << s.data[i] << " ";
		}
		else
		{
			cout << "\n" << "桌上已经没有牌了";
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

	//读入6张纸牌，分别放入到小哼小哈手中
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
		//小哼出牌
		temp = q1.data[q1.head];
		

		if (book[temp]!=0)
		{
			//将打出的牌出队
			q1.head++;
			q1.data[q1.tail++] = temp;//这轮赢牌，将打出的牌放到队尾
			//小哼收走桌上的一部分牌
			while (s.data[s.top] != temp)
			{
				book[s.data[s.top]] = 0;//取消标记
				q1.data[q1.tail] = s.data[s.top];
				q1.tail++;
				s.top--;
			}
			book[s.data[s.top]] = 0;//将相同两张的另一张也取消标记
			q1.data[q1.tail++] = s.data[s.top--];//将相等牌的另一张也放入队尾
		}

		if (book[temp]==0)
		{
			s.data[++s.top] = temp;
			q1.head++;
			book[temp] = 1;//标记桌面上现在已经有牌面为t的牌
		}

		if (q1.head == q1.tail)break;
		

		//小哈出牌
		temp = q2.data[q2.head];
	
		if (book[temp]!=0)
		{
			//将打出的牌出队
			q2.head++;
			q2.data[q2.tail++] = temp;//这轮赢牌，将打出的牌放到队尾
			//小哈收走桌上的一部分牌
			while (s.data[s.top] != temp)
			{
				book[s.data[s.top]] = 0;//取消标记
				q2.data[q2.tail] = s.data[s.top];
				q2.tail++;
				s.top--;
			}
			book[s.data[s.top]] = 0;
			q2.data[q2.tail++] = s.data[s.top--];//将相等牌的另一张也放入队尾
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
		cout << "小哼win\n";
		cout << "小哼当前手中的牌是：";
		for (i = q1.head; i < q1.tail; i++)
			cout << q1.data[i] << " ";

		if (s.top != 0)
		{
			cout << "\n" << "桌上的牌是：";
			for (i = 1; i <= s.top; i++)
				cout << s.data[i] << " ";
		}
		else
		{
			cout << "\n" << "桌上已经没有牌了";
		}
	}

	if (q2.head != q2.tail)
	{
		cout << "小哈win\n";
		cout << "小哈当前手中的牌是：";
		for (i = q2.head; i < q2.tail; i++)
			cout << q2.data[i] << " ";

		if (s.top != 0)
		{
			cout << "\n" << "桌上的牌是：";
			for (i = 1; i <= s.top; i++)
				cout << s.data[i] << " ";
		}
		else
		{
			cout << "\n" << "桌上已经没有牌了";
		}
	}
}

int main()
{
	//test01();
	test02();
	return 0;
}