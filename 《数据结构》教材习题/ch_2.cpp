#include <cstddef>
#include <iostream>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS 1
/* 2.1 ��������������������ϲ�Ϊһ����������������
Ҫ����������ʹ��ԭ����������Ĵ洢�ռ�, 
������ռ�������Ĵ洢�ռ䡣���в��������ظ������ݡ�*/
typedef struct LNode{
	int data;
	struct LNode* next;//ָ����
}LNode,*LinkList;

void CreateList_R(LinkList& L, int n=0)
{
	L = new LNode;//����ͷ���
	L->next = NULL;
	LNode* r = L;//����βָ��
	for (int i = 0; i < n; ++i)
	{
		LNode* p = new LNode;
		cin >> p->data;
		p->next = NULL;
		r->next = p;
		r = p;//rָ���µĽ��*p
	}
}

void MergeList_L(LinkList& La, LinkList& Lb, LinkList& Lc)
{//ǰ�巨
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
			//ɾ����pb��ǰָ��Ľ��
			tmp = pb->next;
			delete pb;
			pb = tmp;
		}
	}
	pc->next = pa ? pa : pb;//����ʣ���
	delete Lb;//�ͷ�Lb��ͷ���
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

/* 2.2 �������ǵݼ�����������ϲ�Ϊһ���ǵ�������������
Ҫ����������ʹ��ԭ����������Ĵ洢�ռ�,
������ռ�������Ĵ洢�ռ䡣�����������ظ������ݡ� */
void MergeList_r(LinkList& La, LinkList& Lb, LinkList& Lc)
{//��巨
	LinkList pa = La->next, pb = Lb->next;
	Lc = La;//��La��ͷ�����ΪLc��ͷ���
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
		Lc->next = tmp;//����
	}
	delete Lb;
}

/* 2.3 ��֪��������A��B�ֱ��ʾ�������ϣ���Ԫ�ص������С�
������㷨���A��B�Ľ������������A�����С� */
void Mix(LinkList& La, LinkList& Lb,LinkList&Lc)
{
	LinkList pa = La->next;
	LinkList pb = Lb->next;
	Lc = La;//��La��ͷ�����ΪLc��ͷ���
	LinkList pc = Lc;
	LNode* tmp;
	while (pa && pb)
	{
		if (pa->data < pb->data) { tmp = pa; pa = pa->next; delete tmp; }
		else if (pa->data > pb->data) { tmp = pb; pb = pb->next;delete tmp; }
		else
		{//������
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
	pc->next = NULL;//������β���
	delete Lb;//Ҳ�ɶ�B�������ͷŴ���
}

/* 2.4  ��֪��������A��B�ֱ��ʾ�������ϣ���Ԫ�ص������С�
������㷨�����������A��B �Ĳ����������A�г��ֶ�����B�г��ֵ�Ԫ�������ɵļ��ϣ���
����ͬ������ʽ�洢��ͬʱ���ظü��ϵ�Ԫ�ظ����� */

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

/* 2.5  ����㷨��һ����ͷ���ĵ�����A�ֽ�Ϊ����������ͬ�ṹ������B��C��
����B��Ľ��ΪA����ֵС����Ľ�㣬��C��Ľ��ΪA����ֵ������Ľ�㣨����A��Ԫ������Ϊ���ͣ�
Ҫ��B��C������A��Ľ�㣩��  */

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

/* 2.7 ���һ���㷨��ͨ������һ�ˣ������������н������ӷ�����ת��������ԭ��Ĵ洢�ռ䡣 */

void inverse(LinkList& L)
{
	LinkList p = L->next,q;
	L->next = NULL;
	while (p)
	{//��巨
		q = p->next;
		p->next = L->next;
		L->next = p;
		p = q;
	}
}

/* 2.9 ��֪pָ��˫��ѭ�������е�һ����㣬����ṹΪdata��prior��next������
д���㷨change(p),����p��ָ��Ľ�������ǰ׺����˳�� */

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
	DuLNode* q = p->prior;//p��ǰ��
	q->prior->next = p;//pǰ����ǰ����nextΪp
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

/* 2.10 ��֪����Ϊn�����Ա�A����˳��洢�ṹ����дһʱ�临�Ӷ�ΪO(n)���ռ临�Ӷ�ΪO(1)���㷨��
���㷨ɾ�����Ա�������ֵΪitem������Ԫ�ء�  */
#define MAXSIZE 100
typedef struct
{
	int* elem;//�洢�ռ�Ļ���ַ
	int length;//��ǰ����
}SqList;
void InitList(SqList& L)
{//˳���ĳ�ʼ���������ڴ�һ������ɹ�
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