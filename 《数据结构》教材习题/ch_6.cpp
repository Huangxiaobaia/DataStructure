#include <iostream>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS 1
/*�ֱ����ڽӾ�����ڽӱ���Ϊ�洢�ṹ��ʵ������ͼ�Ļ���������
�� ����һ���¶���v��InsertVex(G, v)��
�� ɾ������v������صıߣ�DeleteVex(G, v);
�� ����һ����<v��w>��InsertArc(G, v, w);
�� ɾ��һ����<v��w>��DeleteArc(G, v, w)
*/
//����һ���¶���v��InsertVex(G, v)
const int MaxInt = 32767;
const int MVNum = 100;
typedef int ArcType;//�ߵ�Ȩֵ����
typedef char VerTexType;//������������
typedef struct {
	char vexs[MVNum];//�����
	int arcs[MVNum][MVNum];//�ڽӾ���
	int vexnum, arcnum;
}AMGraph;

//�ڽӱ�洢
typedef struct ArcNode//�߽��
{
	char  adjvex;//�ñ���ָ��Ķ���
	int  adj;//Ȩֵ
	struct ArcNode* nextarc;//ָ����һ���ߵ�ָ��
}ArcNode;

typedef struct VNode {//������Ϣ
	char data;
	ArcNode *firstarc;//ָ���һ�������ö����ָ��
}VNode,AdjList[MVNum];

typedef struct {//�ڽӱ�
	AdjList vertices;
	int vexnum, arcnum;//ͼ�ĵ�ǰ�������ͱ���
}ALGraph;

void InitAM(AMGraph &G)
{//��ʼ��ͼ
	memset(G.vexs, 0, sizeof(G.vexs));
	memset(G.arcs, 0, sizeof(G.arcs));
}

//����һ���¶���v��InsertVex(G, v)
void InsertVex(AMGraph& G,char v)//�ڽӾ���
{
	if (G.vexnum + 1 > MVNum)cout << "�����˶������" << endl;
	G.arcs[0][G.vexnum] = G.arcs[G.vexnum][0] = v;
	for (int i = 0; i < G.vexnum; i++)
		G.arcs[i][G.vexnum] = G.arcs[G.vexnum][i] = 0;
}

int Location(ALGraph&G, char v)
{
	for (int i = 0; i < G.vexnum; i++)
		if (G.vertices[i].data == v)return i;
	return -1;
}

void InsertVex(ALGraph&G, char v)//�ڽӱ�
{
	if(G.vexnum+1>MVNum)cout << "�����˶������" << endl;
	G.vertices[G.vexnum].data = v;
	G.vertices[G.vexnum].firstarc = NULL;
}

//ɾ������v������صıߣ�DeleteVex(G, v)
int Location(const AMGraph &G,char v)
{//�����򷵻�v�ڶ������±꣬���򷵻�-1
	int i = 0;
	for (i; i < G.vexnum; i++)
		if (G.vexs[i] == v)
			return i;
	return -1;
}

void DeleteVex(AMGraph &G, char v)
{//�ڽӾ���洢��ʽ
	int position = Location(G, v);
	//���±ߵĸ���
	G.arcnum = 0;
	for (int i = 0; i < G.vexnum; i++)
		if (G.arcs[position][i] != 0)
			G.arcnum++;
	//�����ڽӾ���
	for(int i=0;i<G.vexnum;i++)
		for (int j = 0; j < G.vexnum; j++)
		{
			if (i > position&&j > position)G.arcs[i - 1][j - 1] = G.arcs[i][j];
			else if (i > position&&j < position)G.arcs[i - 1][j] = G.arcs[i][j];
			else if (i<position&&j>position)G.arcs[i][j - 1] = G.arcs[i][j];
		}
	for (int i = position; i < G.vexnum; i++)
		G.vexs[i] = G.vexs[i + 1];
	//���¶������
	G.vexnum--;
}

void DeleteVex(ALGraph&G, char v)
{
	int i = Location(G, v);
	if (i == -1)exit(0);

	//ɾ��������������Ӧ����
	ArcNode* p = G.vertices[i].firstarc;
	ArcNode* q;
	while (p)
	{
		q = p;
		p = p->nextarc;
		delete q;
		G.arcnum--;
	}
	//ɾ���뻡��������Ӧ����
	bool found;
	for (int j = 0; j < G.vexnum; j++)
	{
		if (j != i)
		{
			found = false;
			p = G.vertices[j].firstarc;
			while (p && !found)
			{
				if (p->adjvex == v)found = true;
				else
				{//����ǰ�߽����ʱ��������
					q = p;
					p = p->nextarc;
				}
			}
			if (!found)//û���ҵ�
				continue;
			if (p)//�ҵ���ֵΪv�ĵ����������м�
				q->nextarc = p->nextarc;
			else //�ҵ���ֵΪv�ĵ����������ͷ
				G.vertices[j].firstarc = p->nextarc;
			delete q;
			G.arcnum--;
		}
	}
	//ɾ�����������иñ�ɾ���ĵ�
	for (int j = i; j < G.vexnum; j++)
		G.vertices[j] = G.vertices[j + 1];
	G.vexnum--;
}

//����һ����<v��w>��InsertArc(G, v, w)
void InsertArc(AMGraph&G, char v, char w)
{//�ڽӾ�����ʽ�洢����ͼ
	int position1 = Location(G, v);
	int position2 = Location(G, w);
	G.arcs[position1][position2] = G.arcs[position2][position1] = 1;
}

void InsertArc(ALGraph&G, char v, char w)
{
	ArcNode* p = new ArcNode;
	int i = Location(G,v);
	p->nextarc = G.vertices[i].firstarc;
	p->adjvex = w;
	G.vertices[i].firstarc = p;
	G.arcnum++;
	ArcNode* q = new ArcNode;
	i = Location(G, w);
	q->nextarc = G.vertices[i].firstarc;
	q->adjvex = v;
	G.vertices[i].firstarc = q;
	G.arcnum++;
}

//ɾ��һ����<v��w>��DeleteArc(G, v, w)
void DeleteArc(AMGraph&G, char v, char w)
{
	int position1 = Location(G, v);
	int position2 = Location(G, w);
	G.arcs[position1][position2] = G.arcs[position2][position1] = 0;
}

void DeleteArc(ALGraph&G, char v, char w)
{
	int i = Location(G, v);
	int j = Location(G, w);
	if (i == -1||j==-1)exit(0);
	ArcNode* p = G.vertices[i].firstarc;
	ArcNode* q;
	while (p)
	{
		if (p->adjvex != w)
		{
			q = p;
		}
		else
		{
			q->nextarc = p->nextarc;
			delete p;
			G.arcnum--;
		}
		p = p->nextarc;
	}
	ArcNode* m = G.vertices[i].firstarc;
	ArcNode* n;
	while (m)
	{
		if (m->adjvex != w)
		{
			n = m;
		}
		else
		{
			n->nextarc = m->nextarc;
			delete m;
			G.arcnum--;
		}
		m = m->nextarc;
	}
}


/* һ����ͨͼ�����ڽӱ���Ϊ�洢�ṹ�����һ���㷨��
ʵ�ִӶ���v������������ȱ����ķǵݹ���� */
void DFS(ALGraph&G, char v)
{
	ArcNode* p;
	int Stack[MVNum], top = -1;
	int i, k;
	int visit[MVNum];
	for (i = 0; i < MVNum; i++)
		visit[i] = 0;
	Stack[++top] = v;
	int position = Location(G,v);
	visit[position] = 1;
	while (top > 0)
	{
		cout << Stack[top - 1] << " ";//��ȡջ��Ԫ��
		position = Location(G, Stack[top - 1]);
		/* �ҵ��ö���ĵ�һ��δ�����ʵ��ڽӵ� */
		p = G.vertices[position].firstarc;
		while (p&&visit[p->adjvex]==1)
			p = p->nextarc;
		//���ڽӵ㶼�����ʹ���ջ��Ԫ�س�ջ
		if (!p)top--;
		else
		{//������ʸ�Ԫ�ز������ڽӵ���ջ
			cout << p->adjvex << " ";
			Stack[++top] = p->adjvex;
			position = Location(G, p->adjvex);
			visit[position] = 1;
		}		
	}
}
//�ݹ����
void DFS_AL(ALGraph&G, char v)
{
	int visited[MVNum];
	int position = Location(G, v);
	visited[position] = 1;
	ArcNode* p = G.vertices[position].firstarc;
	char q;
	while (p)
	{
		q = p->adjvex;
		position = Location(G, q);
		if (visited[position] != 1)DFS(G, q);
		p = p->nextarc;
	}
}

/* ���һ���㷨����ͼG�о��붥��v�����·����������һ�����㣬
��v�ɴ������������ */
void ShortestPath_Floyd(AMGraph&G,char v)
{
	int D[100][100],Path[100][100];
	for(int i=0;i<G.vexnum;i++)
		for (int j = 0; j < G.vexnum; j++)
		{
			D[i][j] = G.arcs[i][j];
			if (D[i][j] < MaxInt)Path[i][j] = i;
			else Path[i][j] = -1;
		}
	for(int k=0;k<G.vexnum;k++)
		for(int i=0;i<G.vexnum;i++)
			for (int j = 0; j < G.vexnum; j++)
				if(D[i][j]>D[i][k]+D[k][j])
				{
					D[i][j] = D[i][k] + D[k][j];
					Path[i][j] = Path[k][j];
				}
	int maxLength = 0,length=0;
	int j = 0;
	int position = Location(G, v);
	for (int i = 0; i < G.vexnum - 1; i++)
	{
		if (i != position && Path[position][i] != -1)
		{
			while (Path[position][i] != i)
			{
				length++;
				i = Path[position][i];
			}
			if (length > maxLength)
			{
				maxLength = length;
				j = i;
			}
		}
	}
	cout << "���·�������Ϊ��"<<maxLength << endl;
	cout << "��������ǣ�" << G.vexs[j]<< endl;
}

/* �Ի���ͼ�����������������дһ�㷨���б����ڽӱ�ʽ�洢������ͼ���Ƿ�����ɶ���vi������vj��·����i��j�� */

void DFS(ALGraph&G, char v, char w, int visited[100], int &found)
{
	ArcNode* p = new ArcNode;
	int position = Location(G, v);//���v�ڶ�����е�λ��
	visited[position] = 1;
	if (v == w)found = 1;
	else
	{
		p = G.vertices[position].firstarc;//�ҵ���һ�������ö���ı�
		while (!found&&p != NULL)
		{
			int p_position = Location(G, p->adjvex);
			if (!visited[p_position])
				DFS(G, p->adjvex, w, visited, found);
			p = p->nextarc;
		}
	}
}

int exit_path_DFS(ALGraph&G, char v, char w)
{
	int visited[100];
	int found=0;
	DFS(G, v, w, visited, found);
	return found;
}

/* �����ڽӱ�洢�ṹ����дһ���㷨���б�����ͼ�������������������֮���Ƿ����һ������ΪΪk�ļ�·�� */
int visited[100];
int exist_path_len(ALGraph&G, char i, char j, int k)
{
	int position = Location(G, i);
	int l_position;
	if (k == 0 && i == j)return 1;//�ҵ���һ��·�����ҷ���Ҫ��
	else if(k>0)
	{
		visited[position] = 1;
		for (ArcNode* p = G.vertices[position].firstarc; p; p = p->nextarc)
		{
			char l = p->adjvex;
			l_position = Location(G, l);
			if(!visited[l_position])
				exist_path_len(G, l, j, k - 1);//ʣ��·�����ȼ�һ
		}
		visited[l_position] = 0;//���������ʹ��Ľ�������������һ��·����
	}
	return 0;//û�ҵ�
}

int main()
{

	return 0;



