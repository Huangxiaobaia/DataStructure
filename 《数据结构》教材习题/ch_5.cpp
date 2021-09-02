#include <cstddef>
#include <iostream>
#include <deque>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS 1

/* �Զ���������Ϊ�������Ĵ洢�ṹ����д�����㷨��
 */

typedef struct BiNode {
	int data;
	struct BiNode* lchild, * rchild;
}BiTNode,*BiTree;

//���������˳������������
void CreateBiTree(BiTree& T)
{
	int ch;
	cin >> ch;
	if (ch != '#')
	{
		T = new BiTNode;
		T->data=ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
}

//ͳ�ƶ�������Ҷ������
int LeafNodeCount(const BiTree &T)
{
	if (T == NULL)return 0;
	else if (T->lchild == NULL && T->rchild == NULL)
		return 1;
	else
		return LeafNodeCount(T->lchild) + LeafNodeCount(T->rchild);
}

//�б��������Ƿ����
bool IsEqual(const BiTree &T1,const BiTree &T2)
{
	if(T1 == NULL && T2 == NULL)return true;
	if (T1 != NULL && T2 != NULL)
	{
		if (T1->data == T2->data)
		{
			if (IsEqual(T1->lchild, T2->lchild) && IsEqual(T1->rchild, T2->rchild))
				return true;
		}
	}
	return false;
}

//����������ÿ���������Ӻ��Һ���
void SwapLR(BiTree &T)
{
	BiTree temp;
	if (T->lchild == NULL && T->rchild == NULL)return;
	else
	{
		temp = T->lchild;
		T->lchild = T->rchild;
		T->rchild = temp;
	}
	SwapLR(T->lchild);
	SwapLR(T->rchild);
}

/*��ƶ�������˫������㷨��˫�������ָ���ڶ�������ÿһ�������˵���ȷ��������㣬�ٰ�˫�����������������
Ȼ����һ�η��������㣬��������˫�����������������*/
void DoubleTraverse(const BiTree& T)
{
	if (T == NULL)return;
	else if (T->lchild == NULL && T->rchild == NULL)cout<< T->data;
	else
	{
		cout << T->data<<"\n";
		DoubleTraverse(T->lchild);
		cout << T->data << "\n";
		DoubleTraverse(T->rchild);
	}
}

/*������������Ŀ�ȣ����������������ָ���������в��н����������ֵ��*/
int Width(const BiTree& T)
{
	if (T == NULL)return 0;//��Ϊ�շ���0
	int maxWidth = 1;
	deque<BiTree>dq;
	dq.push_back(T);

	while (true)
	{
		int len = dq.size();//��ǰ��εĳ���
		if (len == 0)//�����һ�㶼���Ӻ�����ѭ��
			break;
		while (len>0)
		{
			BiTNode* temp = dq.front();
			if (temp->lchild)//����һ�������
				dq.push_back(temp->rchild);
			if (temp->rchild)
				dq.push_back(temp->rchild);
			dq.pop_front();
			len--;
		}
		maxWidth = maxWidth > dq.size() ? maxWidth : dq.size();
	}
	return maxWidth;
}

/* �ð����˳������������ķ�����ͳ�����о��ж�Ϊ1�Ľ����Ŀ*/
int Level(const BiTree& T)
{
	if (T == NULL)return 0;
	int num = 0,len=0;
	deque<BiTree>dq;
	dq.push_back(T);
	while (true)
	{
		len = dq.size();
		if (len == 0)break;
		while (len > 0)
		{
			BiNode* temp = dq.front();
			dq.pop_front();
			if (temp->lchild && !temp->rchild || !temp->lchild && temp->rchild)
				num++;
			if (temp->lchild)dq.push_back(temp->lchild);
			if (temp->rchild)dq.push_back(temp->rchild);
			len--;
		}
	}
	return num;
}
int main()
{

	return 0;
}