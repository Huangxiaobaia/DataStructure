#pragma once
#include <cstddef>
#include <iostream>
using namespace std;

class List;

class ListNode
{
	friend class List;
private:
	int data;
	ListNode* link;
	//构造函数
	ListNode(const int item) :data(item), link(NULL) {}
};

class List
{
public:
	List() :first(NULL), current(NULL) {}
	~List() {}
	ListNode* NewNode(const int item);//创造链表节点
	void NewList(const int retvalue);//建立链表，以输入retvalue结束
	void PrintList();//输出链表节点数据
	int GetMax() { return Max(first); }//输出链表结点最大值
	int GetNum() { return Num(first); }//输出链表数据个数
	float GetAvg(int &n) { return Avg(first,n); }//输出链表所有数据的平均值

private:
	ListNode* first, *current;
	int Max(ListNode* f);
	int Num(ListNode* f);
	float Avg(ListNode* f,int &n);

};

ListNode* List::NewNode(const int item)
{
	ListNode* newnode =new ListNode(item);
	return newnode;
}

void List::NewList(const int retvalue)
{
	int value;
	ListNode* q=NULL;
	cout << "Input your data:" << endl;
	cin >> value;
	while (value != retvalue)
	{
		q = NewNode(value);
		if (first == NULL)first=current = q;
		else { current->link = q; current = q; }
		cin >> value;
	}
	current->link = NULL;
}

void List::PrintList()
{
	cout << "The first is: ";
	ListNode* p = first;
	while (p != NULL) { cout << p->data << " "; p = p->link; }
	cout << '\n';
}

int List::Max(ListNode* f)
{//递归算法：求链表中的最大值
	if (f->link == NULL)return f->data;
	int tmp = Max(f->link);
	if (f->data > tmp)return f->data;
	else return tmp;
}

int List::Num(ListNode* f)
{//递归算法：求链表中结点的个数
	if (f->link == NULL)return 1;//最后一个结点返回1
	return 1 + Num(f->link);//否则，返回后继链表结点个数加1
}

float List::Avg(ListNode* f,int &n)
{
	if (f->link == NULL) { n = 1; return (float)(f->data); }
	else { float sum = Avg(f->link, n)*n; n++; return (f->data + sum) / n; }
}