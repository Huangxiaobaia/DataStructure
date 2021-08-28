#define _CRT_SECURE_NO_WARNINGS 1
#include <string.h>
#include <assert.h>
#include <iostream>
#include <algorithm>
using namespace std;
/* 3.1 回文是指正读反读均相同的字符序列，如“abba”和“abdba”均是回文，但“good”不是回文。
试写一个算法判定给定的字符向量是否为回文。
(提示：将一半字符入栈)  */

#define StackSize 100
typedef float DataType;
typedef struct {
	DataType *base;
	DataType* top;
	int stacksize;//栈可用的最大容量
}SeqStack;

void InitStack(SeqStack& S)
{
	S.base = new DataType[StackSize];
	S.top = S.base;
	S.stacksize = StackSize;
}

void Push(SeqStack& S, float c)
{
	if (S.top - S.base == S.stacksize)cout << "栈满" << endl;
	*S.top++ = c;
}

int IsHuiWen(char* t)
{//判断字符向量是否是回文
	SeqStack S;
	InitStack(S);
	int len = strlen(t);
	int i = 0;
	char c;
	for (i; i < len / 2; i++)
		Push(S, t[i]);//进栈
	i = len % 2 ? i+1 : i;
	if (S.top != S.base)
	{
		c = *--S.top;
		if (c != t[i++])return 0;
	}
	return 1;
}

/* 设从键盘输入一整数的序列：a1, a2, a3，…，an，试编写算法实现：用栈结构存储输入的整数，
当ai≠-1时，将ai进栈；当ai=-1时，输出栈顶整数并出栈。
算法应对异常情况（入栈满等）给出相应的信息 */

void InOutS(SeqStack& S,int n)
{
	int m=0;
	InitStack(S);
	for (int i = 0; i < n; i++)
	{
		cin >> m;
		if (m != -1)
		{
			if (S.top - S.base == S.stacksize)cout << "栈已满" << endl;
			else *S.top++ = m;
		}
		else
		{
			if (S.top == S.base)cout << "栈已空" << endl;
			else cout << *--S.top << " 出栈" << endl;
		}
	}
}

/* 从键盘上输入一个后缀表达式，试编写算法计算表达式的值。规定：逆波兰表达式的长度不超过一行，以$符作为输入结束，
操作数之间用空格分隔,操作符只可能有+、-、*、/四种运算。例如：234 34+2*$。 */

float Pop(SeqStack& S)
{
	if (S.top == S.base) { cout << "栈已空" << endl; return 0; }
	return *--S.top;

}

void expr()
{
	SeqStack OPND;
	InitStack(OPND);
	float num = 0.0;
	char c;
	cin >> c;
	while (c != '$')
	{
		if ('0' <= c <= '9')
			while ((c >= '0' && c <= '9') || c == '.')//拼数
				if (c != '.')
				{
					num = num * 10 + (int(c) - int('0'));
					cin >> c;
				}
				else//小数部分
				{
					int scale = 10;
					cin >> c;
					while (c >= '0' && c <= '9')
					{
						num = num + (int(c) - int('0')) / scale;
						scale = scale * 10;
						cin >> c;
					}
				}
		Push(OPND, num);
		num = 0;
		if (c == 'a') {}
		else if (c == '+') { Push(OPND, Pop(OPND) + Pop(OPND)); }
		else if (c == '-') { Push(OPND, Pop(OPND) - Pop(OPND)); }
		else if (c == '*') { Push(OPND, Pop(OPND)* Pop(OPND)); }
		else
		{
			Push(OPND, Pop(OPND) / Pop(OPND));
		}
		cin >> c;
	}
	cout << "后缀表达式的值为：" << Pop(OPND) << endl;
}

/*  假设以I和O分别表示入栈和出栈操作。栈的初态和终态均为空，入栈和出栈的操作序列可表示为仅由I和O组成的序列，
称可以操作的序列为合法序列，否则称为非法序列。写出一个算法，判定所给的操作序列是否合法。若合法，返回true，
否则返回false（假定被判定的操作序列已存入一维数组中）。 */

int Judge(char A[])
{
	int i = 0;
	int j = 0,k=0;//j为I字母的个数，k为O字母的个数
	while (A[i] != '\0')
	{
		switch (A[i])
		{
		case 'I':
			j++;
			break;
		case 'O':
			k++;
			if (k > j) {
				cout << "非法序列" << endl;
				return 0;
			}
		}
		++i;

	}
	if (j != k)
	{
		cout << "非法序列" << endl;
		return 0;
	}
	else
		return 1;
}

/* 假设以带头结点的循环链表表示队列，并且只设一个指针指向队尾元素站点(注意不设头指针) ，
试编写相应的置空队、判队空 、入队和出队等算法。 */

typedef struct queuenode {
	int data;
	struct queuenode* next;
}QueueNode;

typedef struct {
	queuenode* rear;
}LinkQueue;

//置空队
void InitQueue(LinkQueue& Q)
{
	QueueNode* s;
	Q.rear = Q.rear->next;//将队尾指针指向头结点
	while (Q.rear != Q.rear->next)//当队列非空，将队中元素逐个出队
	{
		s = Q.rear->next;
		Q.rear->next = s->next;
		delete(s);
	}
}

//判队空
bool EmptyQueue(LinkQueue& Q)
{
	if (Q.rear->next == Q.rear)return true;
	else return false;
}

//入队
void EnQueue(LinkQueue& Q, int x)
{
	QueueNode* p = new QueueNode;
	p->data = x;
	p->next=Q.rear->next;
	Q.rear->next = p;
	Q.rear = p;//将尾指针移至新节点
}

//出队
int DeQueue(LinkQueue& Q)
{
	int t;
	QueueNode* p;
	if (EmptyQueue(Q))
		return NULL;
	p = Q.rear->next->next; //循环链表队列队尾指针下一结点(也即头结点)的下一结点(即队头指针)
	t = p->data;
	Q.rear->next = p->next;
	delete(p);
	return t;
}

/* 假设以数组Q[m]存放循环队列中的元素, 同时设置一个标志tag，以tag == 0和tag == 1来区别在队头指针(front)和队尾指针(rear)相等时，队列状态为“空”还是“满”。
试编写与此结构相应的插入(enqueue)和删除(dlqueue)算法。 */

#include "Queue.h"

template<class Type>
Queue<Type>::Queue(int sz) :rear(0), front(0), tag(0), m(sz)
{
	Q = new Type[m];
	assert(Q != 0);//断言：动态存储分配成功与否
}

template<class Type>
void Queue<Type>::EnQueue(Type& item)
{
	assert(!IsFull());
	rear = (rear + 1) % m;
	Q[rear] = item;
	tag = 1;
}

template<class Type>
Type Queue<Type>::DeQueue()
{
	assert(!isEmpty());
	front = (front + 1) % m;
	tag = 0;
	return Q[front];
}

template<class Type>
Type Queue<Type>::GetFront()
{
	assert(!isEmpty());
	return Q[(front + 1) % m];
}

/* 如果允许在循环队列的两端都可以进行插入和删除操作。要求：
① 写出循环队列的类型定义；
② 写出“从队尾删除”和“从队头插入”的算法。
 */

#define M 20
typedef struct {
	int data[M];
	int front, rear;
}cycqueue;

//从队尾删除
int delqueue(cycqueue& Q)
{
	if (Q.front == Q.rear) { cout << "队列空" << endl; exit(0); }
	Q.rear = (Q.rear - 1 + M) % M;
	return Q.data[(Q.rear + 1 + M) % M];
}

//从队头插入
void enqueue(cycqueue& Q, int x)
{
	if ((Q.rear + 1) % M == Q.front) { cout << "队列满" << endl; exit(0); }
	Q.data[Q.front] = x;
	Q.front = (Q.front - 1 + M) % M;
}

/* 已知Ackermann函数定义如下:写出计算Ack(m,n)的递归以及非递归算法 */

//递归算法
int Ack(int m, int n)
{
	if (m == 0)return n + 1;
	else if (n == 0)return Ack(m - 1, n);
	else return Ack(m - 1, Ack(m, n - 1));
}

//非递归
int Ackerman(int m, int n)
{
	int akm[M][20];
	int i, j;
	for (j = 0; j < 20; j++)akm[0][j] = j + 1;
	for (i = 1; i < M; i++)
	{
		akm[i][0] = akm[i - 1][1];
		for (j = 1; j < 20; j++)
			akm[i][j] = akm[i - 1][akm[i][j - 1]];
	}
	return akm[m][n];
}

/* 已知f为单链表的表头指针, 链表中存储的都是整型数据，试写出实现下列运算的递归算法：	
① 求链表中的最大整数；
② 求链表的结点个数；
③ 求所有整数的平均值。
 */

#include "RecurveList.h"


int main()
{
	//3.1
	/*char c[] = "abdba";
	cout<<IsHuiWen(c)<<endl;*/

	//3.2
	/*SeqStack S;
	InitStack(S);*/
	//InOutS(S, 5);

	//3.3
	//expr();

	//3.4
	/*char c[] = "IOIIOIOO";
	int x=Judge(c);
	if (x == 1)
	{
		cout << "序列合法" << endl;
	}
	else
		cout << "序列非法" << endl;*/

	//3.5
	List test;
	int finished,n=0;
	cout << "请输入建表结束标志数据：";
	cin >> finished;
	test.NewList(finished);
	test.PrintList();
	cout << "\nThe Max is: " << test.GetMax();
	cout << "\nThe Num is: " << test.GetNum();
	cout << "\nThe Ave is: " << test.GetAvg(n) << "\n";

	return 0;
}