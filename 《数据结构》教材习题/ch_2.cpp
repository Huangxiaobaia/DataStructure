#include <cstddef>
#include <iostream>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS 1
/* 2.1 将两个递增的有序链表合并为一个递增的有序链表。
要求结果链表仍使用原来两个链表的存储空间, 
不另外占用其它的存储空间。表中不允许有重复的数据。*/
typedef struct LNode{
	int data;
	struct LNode* next;//指针域
}LNode,*LinkList;

void CreateList_R(LinkList& L, int n=0)
{
	L = new LNode;//建立头结点
	L->next = NULL;
	LNode* r = L;//建立尾指针
	for (int i = 0; i < n; ++i)
	{
		LNode* p = new LNode;
		cin >> p->data;
		p->next = NULL;
		r->next = p;
		r = p;//r指向新的结点*p
	}
}

void MergeList_L(LinkList& La, LinkList& Lb, LinkList& Lc)
{//前插法
	LinkList pa = La->next,pb=Lb->next;
	Lc = La;
	LinkList pc = Lc,tmp;
	while (pa && pb)
	{
		if (pa->data > pb->data)
		{
			pc->next = pb;
			pc = pb;
			pb = Lb->next;
		}
		else if (pa->data < pb->data)
		{
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else
		{
			pc->next = pa;
			pc = pa;
			pa = pa->next;
			//删除掉pb当前指向的结点
			tmp = pb->next;
			delete pb;
			pb = tmp;
		}
	}
	pc->next = pa ? pa : pb;//插入剩余段
	delete Lb;//释放Lb的头结点
}

void PrintList(const LinkList& L)
{
	LNode* r =new LNode;
	r = L->next;
	while (r)
	{
		cout << r->data<<" ";
		r = r->next;
	}
}

/* 2.2 将两个非递减的有序链表合并为一个非递增的有序链表。
要求结果链表仍使用原来两个链表的存储空间,
不另外占用其它的存储空间。表中允许有重复的数据。 */
void MergeList_r(LinkList& La, LinkList& Lb, LinkList& Lc)
{//后插法
	LinkList pa = La->next, pb = Lb->next;
	Lc = La;//用La的头结点作为Lc的头结点
	Lc->next = NULL;
	LNode* tmp = new LNode;
	while (pa||pb)
	{
		if (!pa)
		{
			tmp = pb;
			pb = pb->next;
		}
		else if (!pb)
		{
			tmp = pa;
			pa = pa->next;
		}
		else if(pa->data<=pb->data)
		{
			tmp = pa;
			pa = pa->next;
		}
		else
		{
			tmp = pb;
			pb = pb->next;
		}
		tmp->next = Lc->next;
		Lc->next = tmp;//插入
	}
	delete Lb;
}

/* 2.3 已知两个链表A和B分别表示两个集合，其元素递增排列。
请设计算法求出A与B的交集，并存放于A链表中。 */
void Mix(LinkList& La, LinkList& Lb,LinkList&Lc)
{
	LinkList pa = La->next;
	LinkList pb = Lb->next;
	Lc = La;//用La的头结点作为Lc的头结点
	LinkList pc = Lc;
	LNode* tmp;
	while (pa && pb)
	{
		if (pa->data < pb->data) { tmp = pa; pa = pa->next; delete tmp; }
		else if (pa->data > pb->data) { tmp = pb; pb = pb->next;delete tmp; }
		else
		{//相等情况
			pc->next = pa;
			pc = pa;
			pa = pa->next;
			tmp = pb;
			pb = pb->next;
			delete tmp;
		}
	}
	while (pa) { tmp = pa; pa = pa->next; delete tmp; }
	while (pb) { tmp = pb; pb = pb->next; delete tmp; }
	pc->next = NULL;//置链表尾标记
	delete Lb;//也可对B链表不做释放处理
}

/* 2.4  已知两个链表A和B分别表示两个集合，其元素递增排列。
请设计算法求出两个集合A和B 的差集（即仅由在A中出现而不在B中出现的元素所构成的集合），
并以同样的形式存储，同时返回该集合的元素个数。 */

void Difference(LinkList& La, LinkList& Lb, int& n)
{
	LinkList pa = La->next,pb=Lb->next,pc=La,tmp;
	while (pa && pb)
	{
		if (pa->data == pb->data)
		{	
			tmp = pa;
			pa = pa->next;
			delete tmp;
			tmp = pb;
			pb = pb->next;
			delete tmp;
		}
		else
		{
			if (pa->data < pb->data) { pc->next = pa; pc = pa; pa = pa->next; n++; }
			else { pc->next = pb; pc = pb; pb = pb->next; n++; }
		}
	}
	pc->next = NULL;
	delete Lb;
}

/* 2.5  设计算法将一个带头结点的单链表A分解为两个具有相同结构的链表B、C，
其中B表的结点为A表中值小于零的结点，而C表的结点为A表中值大于零的结点（链表A的元素类型为整型，
要求B、C表利用A表的结点）。  */

void DivideList(LinkList& La, LinkList& Lb, LinkList& Lc)
{
	LinkList pa = La->next, pb= Lb, pc= Lc,tmp;
	while (pa)
	{
		if (pa->data < 0) { pb->next = pa; pa = pa->next; pb = pb->next; }
		else if (pa->data > 0) { pc->next = pa; pa = pa->next; pc = pc->next; }
		else { tmp = pa; pa = pa->next; delete tmp; }
	}
	pb->next =pc->next= NULL;
}

/* 2.7 设计一个算法，通过遍历一趟，将链表中所有结点的链接方向逆转，仍利用原表的存储空间。 */

void inverse(LinkList& L)
{
	LinkList p = L->next,q;
	L->next = NULL;
	while (p)
	{//后插法
		q = p->next;
		p->next = L->next;
		L->next = p;
		p = q;
	}
}

/* 2.9 已知p指向双向循环链表中的一个结点，其结点结构为data、prior、next三个域，
写出算法change(p),交换p所指向的结点和它的前缀结点的顺序。 */

typedef struct DuLNode
{
	int data;
	struct DuLNode* prior;
	struct DuLNode* next;
}DuLNode,*DuLinkList;

void Create_DL(DuLinkList& L, int a)
{
	L = new DuLNode;
	L->next = L;
	L->prior = L;
	DuLinkList q=L;
	for (int i = 0; i < a; ++i)
	{
		DuLNode* p = new DuLNode;
		cin >> p->data;
		
		q->next = p;
		p->prior = q;
		q = p;
	}
	q->next = L;
	L->prior = q;
}

void change(DuLinkList& p)
{
	DuLNode* q = p->prior;//p的前驱
	q->prior->next = p;//p前驱的前驱的next为p
	p->prior = q->prior;
	q->next = p->next;
	q->prior = p;
	p->next->prior = q;
	p->next = q;
	
}

void PrintDuL(const DuLinkList& L)
{
	DuLinkList p = L->next;
	while (p != L)
	{
		cout << p->data<<" ";
		p = p->next;
	}
}

/* 2.10 已知长度为n的线性表A采用顺序存储结构，请写一时间复杂度为O(n)、空间复杂度为O(1)的算法，
该算法删除线性表中所有值为item的数据元素。  */
#define MAXSIZE 100
typedef struct
{
	int* elem;//存储空间的基地址
	int length;//当前长度
}SqList;
void InitList(SqList& L)
{//顺序表的初始化，假设内存一定分配成功
	L.elem = new int[MAXSIZE];
	L.length = 0;
}
void Create_SL(SqList& L,int n)
{
	int i = 0;
	while (i < n)
	{
		cin >> L.elem[i];
		L.length++;
		i++;
	}
}
int Delete(int a[], int n,int item)
{
	int i = 0, j = n-1,m=n;
	while (i < j)
	{
		while (i < j && a[i] != item)i++;
		if (i < j)while (i < j && a[j] == item) { j--; m--; };
		if (i < j) { //cout << a[i] << endl; cout << a[j] << " "; 
			a[i++] = a[j--]; m--; 
			//cout << a[i] << " "; cout << a[j] << " ";
		};
	}
	return m;
}

int main()
{
	//2.1
	LinkList L1;
	LinkList L2;
	LinkList L3;
	//CreateList_R(L1, 5);
	//CreateList_R(L2, 5);
	//MergeList_L(L1, L2, L3);
	//MergeList_r(L1, L2, L3);
	//2.3
	//Mix(L1, L2, L3);
	//2.4
	/*int n=0;
	Difference(L1, L2, n);
	cout << n << endl;
	PrintList(L1);*/
	//2.5
	/*CreateList_R(L2);
	CreateList_R(L3);
	DivideList(L1, L2, L3);
	PrintList(L2);
	cout << endl;
	PrintList(L3);*/
	//2.7
	/*inverse(L1);
	PrintList(L1);*/
	//2.9
	/*DuLinkList L4;
	Create_DL(L4, 5);
	change(L4->next->next->next);
	PrintDuL(L4);*/
	//2.10
	SqList L5;
	InitList(L5);
	Create_SL(L5,6);
	int n=Delete(L5.elem,6,5);
	int i = 0;
	while (n != 0)
	{
		cout << L5.elem[i++]<<" ";
		n--;
	}
	return 0;
}