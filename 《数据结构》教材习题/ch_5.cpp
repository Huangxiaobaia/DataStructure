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
int LeafNodeCount(const BiTree T)
{
	if (T == NULL)return 0;
	else if (T->lchild == NULL && T->rchild == NULL)
		return 1;
	else
		return LeafNodeCount(T->lchild) + LeafNodeCount(T->rchild);
}

//判别两棵树是否相等
bool IsEqual(const BiTree T1,const BiTree T2)
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
void SwapLR(BiTree T)
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
void DoubleTraverse(const BiTree T)
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
int Width(const BiTree T)
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
int Level(const BiTree T)
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

/*求任意二叉树中第一条最长的路径长度，并输出此路径上各结点的值*/
void LongestPath(const BiTree T)
{
	BiTree p = T, s[100], l[100]; //l,s是栈，元素是二叉树结点指针，l中保留当前最长路径中的结点
	int top = 0, tag[100], longest = 0;
	while (p || top > 0)
	{
		while (p)
		{
			s[++top] = p;
			tag[top] = 0;
			p = p->lchild;
		}//沿左分支向下
		if (tag[top] == 1)//当前结点的右分支已遍历
		{
			if(!s[top]->lchild&&!s[top]->rchild)//只有到叶子结点时，才查看路径长度
				if (top > longest)
				{
					for (int i = 1; i <= top; i++)
						l[i] = s[i];
					longest = top;
					top--;
				}//保留当前最长路径到l，记住最高栈顶指针，退栈
		}
		else if (top > 0)
		{
			tag[top] = 1;
			p = s[top]->rchild;
		}//沿右分支向下
	}
	for (int k = 0; k < longest; k++)
	{
		cout << l[k]->data << "\n";
	}
}

/* 输出二叉树中从每个叶子结点到根结点的路径*/
void AllPath(const BiTree T, int path[], int& pathLength)
{
	if (T != NULL)
	{
		if (!T->lchild == NULL && !T->rchild == NULL)
		{
			cout << T->data<<"叶子结点到根节点的路径为：";
			path[pathLength] = T->data;
			for (int i = pathLength; i >= 0; i--)
				cout << path[i];
			cout << "\n";
		}
		else
		{
			path[pathLength++] = T->data;
			AllPath(T->lchild, path, pathLength);
			AllPath(T->rchild, path, pathLength);
			pathLength--;
		}
	}
}

/* 利用上面这个方法重新输出最长路径上各结点的值*/
void LongestPath(const BiTree T, int path[], int& pathLength, int longestPath[], int longestLength)
{
	if (T != NULL)
	{
		if (T->lchild == NULL && T->rchild == NULL)
		{
			path[pathLength] = T->data;
			if (pathLength > longestLength)
			{
				for (int i = pathLength; i >= 0; i--)
				{
					longestPath[i] = path[i];
				}
				longestLength = pathLength;
			}
		}
		else
		{
			path[pathLength++] = T->data;
			LongestPath(T->lchild, path, pathLength, longestPath, longestLength);
			LongestPath(T->rchild, path, pathLength, longestPath, longestLength);
			pathLength--;
		}
	}
	cout << "最长路径：";
	for (int i = 0; i < longestLength; i++)
		cout << longestPath[i] <<" ";
}

int main()
{

	return 0;
}