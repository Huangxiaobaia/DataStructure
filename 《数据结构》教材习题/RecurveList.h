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
	//���캯��
	ListNode(const int item) :data(item), link(NULL) {}
};

class List
{
public:
	List() :first(NULL), current(NULL) {}
	~List() {}
	ListNode* NewNode(const int item);//��������ڵ�
	void NewList(const int retvalue);//��������������retvalue����
	void PrintList();//�������ڵ�����
	int GetMax() { return Max(first); }//������������ֵ
	int GetNum() { return Num(first); }//����������ݸ���
	float GetAvg(int &n) { return Avg(first,n); }//��������������ݵ�ƽ��ֵ

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
{//�ݹ��㷨���������е����ֵ
	if (f->link == NULL)return f->data;
	int tmp = Max(f->link);
	if (f->data > tmp)return f->data;
	else return tmp;
}

int List::Num(ListNode* f)
{//�ݹ��㷨���������н��ĸ���
	if (f->link == NULL)return 1;//���һ����㷵��1
	return 1 + Num(f->link);//���򣬷��غ�������������1
}

float List::Avg(ListNode* f,int &n)
{
	if (f->link == NULL) { n = 1; return (float)(f->data); }
	else { float sum = Avg(f->link, n)*n; n++; return (f->data + sum) / n; }
}