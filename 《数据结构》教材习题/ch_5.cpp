#include <cstddef>
#include <iostream>
#include <deque>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS 1

/* 以二叉链表作为二叉树的存储结构，编写以下算法：
 */

typedef struct BiNode {
	int data;
	struct BiNode* lchild, * rchild;
}BiTNode,*BiTree;

//先序遍历的顺序建立二叉链表
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

//统计二叉树的叶结点个数
int LeafNodeCount(const BiTree &T)
{
	if (T == NULL)return 0;
	else if (T->lchild == NULL && T->rchild == NULL)
		return 1;
	else
		return LeafNodeCount(T->lchild) + LeafNodeCount(T->rchild);
}

//判别两棵树是否相等
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

//交换二叉树每个结点的左孩子和右孩子
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

/*设计二叉树的双序遍历算法（双序遍历是指对于二叉树的每一个结点来说，先访问这个结点，再按双序遍历它的左子树，
然后再一次访问这个结点，接下来按双序遍历它的右子树）*/
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

/*计算二叉树最大的宽度（二叉树的最大宽度是指二叉树所有层中结点个数的最大值）*/
int Width(const BiTree& T)
{
	if (T == NULL)return 0;//树为空返回0
	int maxWidth = 1;
	deque<BiTree>dq;
	dq.push_back(T);

	while (true)
	{
		int len = dq.size();//当前层次的长度
		if (len == 0)//当最后一层都出队后跳出循环
			break;
		while (len>0)
		{
			BiTNode* temp = dq.front();
			if (temp->lchild)//将下一层结点入队
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

/* 用按层次顺序遍历二叉树的方法，统计树中具有度为1的结点数目*/
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