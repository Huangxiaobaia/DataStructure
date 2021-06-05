#define _CRT_SECURE_NO_WARNINGS 1
#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;
typedef int Status;
//跳舞者个人信息
typedef struct
{
	char name[20];
	char sex;
}Person;
typedef struct
{
	Person* base;
	int front;
	int rear;
}SqQueue;
Status InitQueue(SqQueue& Q)
{
	Q.base = new Person[MAXSIZE];
	if (!Q.base)exit(OVERFLOW);
	Q.front = 0;
	Q.rear = 0;
	return OK;
}
int QueueLength(const SqQueue& Q)
{
	return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}
Status EnQueue(SqQueue& Q, const Person& e)
{
	if ((Q.rear + 1) % MAXSIZE == Q.front)
		return ERROR;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXSIZE;
	return OK;
}
Status DeQueue(SqQueue& Q, Person& e)
{
	if (Q.front == Q.rear)return ERROR;
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXSIZE;
	return OK;
}
Person GetHead(const SqQueue& Q)
{
	if (Q.front != Q.rear)
		return Q.base[Q.front];
}
bool QueueEmpty(const SqQueue& Q)
{
	if (Q.front == Q.rear)
		return true;
	else
		return false;
}
void DancePartner(Person dancer[], int num)
{
	SqQueue Mdancers, Fdancers;
	InitQueue(Mdancers);
	InitQueue(Fdancers);
	Person p;
	for (int i = 0; i < num; i++)
	{
		if (dancer[i].sex == 'F')//根据性别分到不同的队伍
			EnQueue(Fdancers, dancer[i]);
		else
			EnQueue(Mdancers, dancer[i]);
	}
	cout << "The dancing partners are:" << endl;
	while (!QueueEmpty(Fdancers) && !QueueEmpty(Mdancers))
	{
		DeQueue(Mdancers, p);
		cout << p.name << " ";
		DeQueue(Fdancers, p);
		cout << p.name << " ";
	}
	cout << endl;
	if (!QueueEmpty(Fdancers))
	{
		p = GetHead(Fdancers);
		cout << "The first woman to get a partner is: " << p.name << endl;
	}
	else if (!QueueEmpty(Mdancers))
	{
		p = GetHead(Mdancers);
		cout << "The first man to get a partner is: " << p.name << endl;
	}
}
int main()
{//舞伴问题
	Person dancers[] = { {"bihas",'F'},{"abus",'M'},{"abudha",'F'},{"dbi",'F'} };
	DancePartner(dancers,4);
	return 0;
}