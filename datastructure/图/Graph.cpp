#define _CRT_SECURE_NO_WARNINGS 1
#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MaxInt 32767
#define MVNum 100
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
typedef int Status;
//ͼ���ڽӾ���洢��ʾ
typedef struct
{
	char vexs[MVNum];//�����
	int arcs[MVNum][MVNum];//�ڽӾ���
	int vexnum, arcnum;//��ǰ���ͱ���
}AMGraph;
int LocateVex(const AMGraph& G, char c)
{
	for (int i = 0; i < G.vexnum; i++)
	{
		if (G.vexs[i] == c)
			return i;
	}
	return -1;
}
Status CreateUDN(AMGraph& G)
{//�����ڽӾ����ʾ��������������G
	cin >> G.vexnum >> G.arcnum;
	int k = 0,i=0,j=0;
	char v1;
	char v2;
	int w;
	for (int i = 0; i < G.vexnum; i++)
		cin >> G.vexs[i];
	for (int i = 0; i < G.vexnum; ++i)
		for (int j = 0; j < G.vexnum; ++j)
			G.arcs[i][j] = MaxInt;
	for (k = 0; k < G.arcnum; k++)
	{
		cin >> v1 >> v2 >> w;
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		G.arcs[i][j] = w;
		G.arcs[j][i] = G.arcs[i][j];
	}
	return OK;
}
//------ͼ���ڽӱ�洢��ʾ-----------
typedef struct ArcNode
{
	int adjvex;
	struct ArcNode* nextarc;
}ArcNode;
typedef struct VNode
{
	int data;
	ArcNode* firstarc;
}VNode,AdjList[MVNum];
typedef struct
{
	AdjList vertices;
	int vexnum, arcnum;
}ALGraph;
int LocateVex(const ALGraph& G, int c)
{
	for (int i = 0; i < G.vexnum; i++)
	{
		if (G.vertices[i].data == c)
			return i;
	}
	return -1;
}
Status CreateUDG(ALGraph& G)
{//�����ڽӱ��ʾ������������ͼG
	cin >> G.vexnum >> G.arcnum;
	int i = 0, j = 0,k=0;
	int v1, v2;
	ArcNode* p1,*p2;
	for (i; i < G.vexnum; i++)
	{//�����ͷ���
		cin >> G.vertices[i].data;
		G.vertices[i].firstarc = NULL;
	}
	for (k; k < G.arcnum; k++)
	{//�����ڽӱ�
		cin >> v1 >> v2;
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		p1 = new ArcNode;
		p1->adjvex = j;
		p1->nextarc = G.vertices[i].firstarc;
		G.vertices[i].firstarc = p1;

		p2 = new ArcNode;
		p2->adjvex = i;
		p2->nextarc = G.vertices[j].firstarc;
		G.vertices[j].firstarc = p2;
	}
	return OK;
}
//--------����ͼ��ʮ������洢��ʾ��ʽ-------------
#define MAX_VERTEX_NUM 20
typedef struct ArcBox
{
	int tailvext, headvex;
	ArcBox* hlink, * tlink;
}ArcBox;
typedef struct VexNode
{
	int data;
	ArcBox* firstin, * firstout;
}VexNode;
typedef struct
{
	VexNode xlist[MAX_VERTEX_NUM];
	int vecnum, arcnum;
}OLGraph;
int LocateVex(const OLGraph& G, int v)
{
	for (int i = 0; i < G.vecnum; i++)
	{
		if (G.xlist[i].data == v)
			return i;
	}
	return -1;
}
Status CreateUDT(OLGraph& G)
{
	cout << "����������ͼ�Ķ�����,����:";
	cin >> G.vecnum >> G.arcnum;
	int i = 0, j = 0,k=0;
	int v1, v2;
	ArcBox* p;
	cout << "���붥��:";
	for (i; i < G.vecnum; i++)
	{
		cin>>G.xlist[i].data;
		G.xlist[i].firstin = NULL;
		G.xlist[i].firstout = NULL;
	}
	cout << "������" << G.arcnum << "�����Ļ�β�ͻ�ͷ(�ո�Ϊ���): " << endl;
	for (k; k < G.arcnum; k++)
	{
		cin >> v1 >> v2;//ͷ���� β����
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		p = new ArcBox;
		p->tailvext = i;
		p->headvex = j;
		p->hlink = G.xlist[j].firstin;
		p->tlink = G.xlist[i].firstout;
		G.xlist[i].firstout = G.xlist[j].firstin = p;
	}
	return OK;
}
void Display(const OLGraph& G)
{//�������ͼ
	int i;
	ArcBox* p;
	cout << "��" << G.vecnum << "������," << G.arcnum << "����:" << endl;
	for (i = 0; i < G.vecnum; i++)
	{
		cout << "����" << G.xlist[i].data << "���: ";
		p = G.xlist[i].firstin;
		while (p)
		{
			cout << G.xlist[p->tailvext].data << " ";
			p = p->hlink;
		}
		cout << "���ȣ�";
		p = G.xlist[i].firstout;
		while (p)
		{
			cout << G.xlist[p->headvex].data << " ";
			p = p->tlink;
		}
		cout << endl;
	}
}

int main()
{
	OLGraph G;
	CreateUDT(G);
	Display(G);
	return 0;
}