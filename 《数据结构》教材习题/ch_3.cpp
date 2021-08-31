#define _CRT_SECURE_NO_WARNINGS 1
#include <string.h>
#include <assert.h>
#include <iostream>
#include <algorithm>
using namespace std;
/* 3.1 ������ָ������������ͬ���ַ����У��硰abba���͡�abdba�����ǻ��ģ�����good�����ǻ��ġ�
��дһ���㷨�ж��������ַ������Ƿ�Ϊ���ġ�
(��ʾ����һ���ַ���ջ)  */

#define StackSize 100
typedef float DataType;
typedef struct {
	DataType *base;
	DataType* top;
	int stacksize;//ջ���õ��������
}SeqStack;

void InitStack(SeqStack& S)
{
	S.base = new DataType[StackSize];
	S.top = S.base;
	S.stacksize = StackSize;
}

void Push(SeqStack& S, float c)
{
	if (S.top - S.base == S.stacksize)cout << "ջ��" << endl;
	*S.top++ = c;
}

int IsHuiWen(char* t)
{//�ж��ַ������Ƿ��ǻ���
	SeqStack S;
	InitStack(S);
	int len = strlen(t);
	int i = 0;
	char c;
	for (i; i < len / 2; i++)
		Push(S, t[i]);//��ջ
	i = len % 2 ? i+1 : i;
	if (S.top != S.base)
	{
		c = *--S.top;
		if (c != t[i++])return 0;
	}
	return 1;
}

/* ��Ӽ�������һ���������У�a1, a2, a3������an���Ա�д�㷨ʵ�֣���ջ�ṹ�洢�����������
��ai��-1ʱ����ai��ջ����ai=-1ʱ�����ջ����������ջ��
�㷨Ӧ���쳣�������ջ���ȣ�������Ӧ����Ϣ */

void InOutS(SeqStack& S,int n)
{
	int m=0;
	InitStack(S);
	for (int i = 0; i < n; i++)
	{
		cin >> m;
		if (m != -1)
		{
			if (S.top - S.base == S.stacksize)cout << "ջ����" << endl;
			else *S.top++ = m;
		}
		else
		{
			if (S.top == S.base)cout << "ջ�ѿ�" << endl;
			else cout << *--S.top << " ��ջ" << endl;
		}
	}
}

/* �Ӽ���������һ����׺���ʽ���Ա�д�㷨������ʽ��ֵ���涨���沨�����ʽ�ĳ��Ȳ�����һ�У���$����Ϊ���������
������֮���ÿո�ָ�,������ֻ������+��-��*��/�������㡣���磺234 34+2*$�� */

float Pop(SeqStack& S)
{
	if (S.top == S.base) { cout << "ջ�ѿ�" << endl; return 0; }
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
			while ((c >= '0' && c <= '9') || c == '.')//ƴ��
				if (c != '.')
				{
					num = num * 10 + (int(c) - int('0'));
					cin >> c;
				}
				else//С������
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
	cout << "��׺���ʽ��ֵΪ��" << Pop(OPND) << endl;
}

/*  ������I��O�ֱ��ʾ��ջ�ͳ�ջ������ջ�ĳ�̬����̬��Ϊ�գ���ջ�ͳ�ջ�Ĳ������пɱ�ʾΪ����I��O��ɵ����У�
�ƿ��Բ���������Ϊ�Ϸ����У������Ϊ�Ƿ����С�д��һ���㷨���ж������Ĳ��������Ƿ�Ϸ������Ϸ�������true��
���򷵻�false���ٶ����ж��Ĳ��������Ѵ���һά�����У��� */

int Judge(char A[])
{
	int i = 0;
	int j = 0,k=0;//jΪI��ĸ�ĸ�����kΪO��ĸ�ĸ���
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
				cout << "�Ƿ�����" << endl;
				return 0;
			}
		}
		++i;

	}
	if (j != k)
	{
		cout << "�Ƿ�����" << endl;
		return 0;
	}
	else
		return 1;
}

/* �����Դ�ͷ����ѭ�������ʾ���У�����ֻ��һ��ָ��ָ���βԪ��վ��(ע�ⲻ��ͷָ��) ��
�Ա�д��Ӧ���ÿնӡ��жӿ� ����Ӻͳ��ӵ��㷨�� */

typedef struct queuenode {
	int data;
	struct queuenode* next;
}QueueNode;

typedef struct {
	queuenode* rear;
}LinkQueue;

//�ÿն�
void InitQueue(LinkQueue& Q)
{
	QueueNode* s;
	Q.rear = Q.rear->next;//����βָ��ָ��ͷ���
	while (Q.rear != Q.rear->next)//�����зǿգ�������Ԫ���������
	{
		s = Q.rear->next;
		Q.rear->next = s->next;
		delete(s);
	}
}

//�жӿ�
bool EmptyQueue(LinkQueue& Q)
{
	if (Q.rear->next == Q.rear)return true;
	else return false;
}

//���
void EnQueue(LinkQueue& Q, int x)
{
	QueueNode* p = new QueueNode;
	p->data = x;
	p->next=Q.rear->next;
	Q.rear->next = p;
	Q.rear = p;//��βָ�������½ڵ�
}

//����
int DeQueue(LinkQueue& Q)
{
	int t;
	QueueNode* p;
	if (EmptyQueue(Q))
		return NULL;
	p = Q.rear->next->next; //ѭ��������ж�βָ����һ���(Ҳ��ͷ���)����һ���(����ͷָ��)
	t = p->data;
	Q.rear->next = p->next;
	delete(p);
	return t;
}

/* ����������Q[m]���ѭ�������е�Ԫ��, ͬʱ����һ����־tag����tag == 0��tag == 1�������ڶ�ͷָ��(front)�Ͷ�βָ��(rear)���ʱ������״̬Ϊ���ա����ǡ�������
�Ա�д��˽ṹ��Ӧ�Ĳ���(enqueue)��ɾ��(dlqueue)�㷨�� */

#include "Queue.h"

template<class Type>
Queue<Type>::Queue(int sz) :rear(0), front(0), tag(0), m(sz)
{
	Q = new Type[m];
	assert(Q != 0);//���ԣ���̬�洢����ɹ����
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

/* ���������ѭ�����е����˶����Խ��в����ɾ��������Ҫ��
�� д��ѭ�����е����Ͷ��壻
�� д�����Ӷ�βɾ�����͡��Ӷ�ͷ���롱���㷨��
 */

#define M 20
typedef struct {
	int data[M];
	int front, rear;
}cycqueue;

//�Ӷ�βɾ��
int delqueue(cycqueue& Q)
{
	if (Q.front == Q.rear) { cout << "���п�" << endl; exit(0); }
	Q.rear = (Q.rear - 1 + M) % M;
	return Q.data[(Q.rear + 1 + M) % M];
}

//�Ӷ�ͷ����
void enqueue(cycqueue& Q, int x)
{
	if ((Q.rear + 1) % M == Q.front) { cout << "������" << endl; exit(0); }
	Q.data[Q.front] = x;
	Q.front = (Q.front - 1 + M) % M;
}

/* ��֪Ackermann������������:д������Ack(m,n)�ĵݹ��Լ��ǵݹ��㷨 */

//�ݹ��㷨
int Ack(int m, int n)
{
	if (m == 0)return n + 1;
	else if (n == 0)return Ack(m - 1, n);
	else return Ack(m - 1, Ack(m, n - 1));
}

//�ǵݹ�
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

/* ��֪fΪ������ı�ͷָ��, �����д洢�Ķ����������ݣ���д��ʵ����������ĵݹ��㷨��	
�� �������е����������
�� ������Ľ�������
�� ������������ƽ��ֵ��
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
		cout << "���кϷ�" << endl;
	}
	else
		cout << "���зǷ�" << endl;*/

	//3.5
	List test;
	int finished,n=0;
	cout << "�����뽨�������־���ݣ�";
	cin >> finished;
	test.NewList(finished);
	test.PrintList();
	cout << "\nThe Max is: " << test.GetMax();
	cout << "\nThe Num is: " << test.GetNum();
	cout << "\nThe Ave is: " << test.GetAvg(n) << "\n";

	return 0;
}