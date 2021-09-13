#include <iostream>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS 1
/*分别以邻接矩阵和邻接表作为存储结构，实现以下图的基本操作：
① 增添一个新顶点v，InsertVex(G, v)；
② 删除顶点v及其相关的边，DeleteVex(G, v);
③ 增加一条边<v，w>，InsertArc(G, v, w);
④ 删除一条边<v，w>，DeleteArc(G, v, w)
*/
//增添一个新顶点v，InsertVex(G, v)
const int MaxInt = 32767;
const int MVNum = 100;
typedef int ArcType;//边的权值类型
typedef char VerTexType;//顶点数据类型
typedef struct {
	char vexs[MVNum];//定点表
	int arcs[MVNum][MVNum];//邻接矩阵
	int vexnum, arcnum;
}AMGraph;

//邻接表存储
typedef struct ArcNode//边结点
{
	char  adjvex;//该边所指向的顶点
	int  adj;//权值
	struct ArcNode* nextarc;//指向下一条边的指针
}ArcNode;

typedef struct VNode {//顶点信息
	char data;
	ArcNode *firstarc;//指向第一条依附该顶点的指针
}VNode,AdjList[MVNum];

typedef struct {//邻接表
	AdjList vertices;
	int vexnum, arcnum;//图的当前顶点数和边数
}ALGraph;

void InitAM(AMGraph &G)
{//初始化图
	memset(G.vexs, 0, sizeof(G.vexs));
	memset(G.arcs, 0, sizeof(G.arcs));
}

//增添一个新顶点v，InsertVex(G, v)
void InsertVex(AMGraph& G,char v)//邻接矩阵
{
	if (G.vexnum + 1 > MVNum)cout << "超出了顶点个数" << endl;
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

void InsertVex(ALGraph&G, char v)//邻接表
{
	if(G.vexnum+1>MVNum)cout << "超出了顶点个数" << endl;
	G.vertices[G.vexnum].data = v;
	G.vertices[G.vexnum].firstarc = NULL;
}

//删除顶点v及其相关的边，DeleteVex(G, v)
int Location(const AMGraph &G,char v)
{//存在则返回v在定点表的下标，否则返回-1
	int i = 0;
	for (i; i < G.vexnum; i++)
		if (G.vexs[i] == v)
			return i;
	return -1;
}

void DeleteVex(AMGraph &G, char v)
{//邻接矩阵存储形式
	int position = Location(G, v);
	//更新边的个数
	G.arcnum = 0;
	for (int i = 0; i < G.vexnum; i++)
		if (G.arcs[position][i] != 0)
			G.arcnum++;
	//更新邻接矩阵
	for(int i=0;i<G.vexnum;i++)
		for (int j = 0; j < G.vexnum; j++)
		{
			if (i > position&&j > position)G.arcs[i - 1][j - 1] = G.arcs[i][j];
			else if (i > position&&j < position)G.arcs[i - 1][j] = G.arcs[i][j];
			else if (i<position&&j>position)G.arcs[i][j - 1] = G.arcs[i][j];
		}
	for (int i = position; i < G.vexnum; i++)
		G.vexs[i] = G.vexs[i + 1];
	//更新顶点个数
	G.vexnum--;
}

void DeleteVex(ALGraph&G, char v)
{
	int i = Location(G, v);
	if (i == -1)exit(0);

	//删除出弧，弧数对应减少
	ArcNode* p = G.vertices[i].firstarc;
	ArcNode* q;
	while (p)
	{
		q = p;
		p = p->nextarc;
		delete q;
		G.arcnum--;
	}
	//删除入弧，弧数对应减少
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
				{//将当前边结点暂时保存起来
					q = p;
					p = p->nextarc;
				}
			}
			if (!found)//没有找到
				continue;
			if (p)//找到了值为v的点且在链表中间
				q->nextarc = p->nextarc;
			else //找到了值为v的点且在链表表头
				G.vertices[j].firstarc = p->nextarc;
			delete q;
			G.arcnum--;
		}
	}
	//删除顶点数组中该被删除的点
	for (int j = i; j < G.vexnum; j++)
		G.vertices[j] = G.vertices[j + 1];
	G.vexnum--;
}

//增加一条边<v，w>，InsertArc(G, v, w)
void InsertArc(AMGraph&G, char v, char w)
{//邻接矩阵形式存储无向图
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

//删除一条边<v，w>，DeleteArc(G, v, w)
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


/* 一个连通图采用邻接表作为存储结构，设计一个算法，
实现从顶点v出发的深度优先遍历的非递归过程 */
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
		cout << Stack[top - 1] << " ";//获取栈顶元素
		position = Location(G, Stack[top - 1]);
		/* 找到该顶点的第一个未被访问的邻接点 */
		p = G.vertices[position].firstarc;
		while (p&&visit[p->adjvex]==1)
			p = p->nextarc;
		//其邻接点都被访问过，栈顶元素出栈
		if (!p)top--;
		else
		{//否则访问该元素并将该邻接点入栈
			cout << p->adjvex << " ";
			Stack[++top] = p->adjvex;
			position = Location(G, p->adjvex);
			visit[position] = 1;
		}		
	}
}
//递归过程
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

/* 设计一个算法，求图G中距离顶点v的最短路径长度最大的一个顶点，
设v可达其余各个顶点 */
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
	cout << "最短路径长度最长为："<<maxLength << endl;
	cout << "这个顶点是：" << G.vexs[j]<< endl;
}

/* 试基于图的深度优先搜索策略写一算法，判别以邻接表方式存储的有向图中是否存在由顶点vi到顶点vj的路径（i≠j） */

void DFS(ALGraph&G, char v, char w, int visited[100], int &found)
{
	ArcNode* p = new ArcNode;
	int position = Location(G, v);//结点v在顶点表中的位置
	visited[position] = 1;
	if (v == w)found = 1;
	else
	{
		p = G.vertices[position].firstarc;//找到第一条依附该顶点的边
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

/* 采用邻接表存储结构，编写一个算法，判别无向图中任意给定的两个顶点之间是否存在一条长度为为k的简单路径 */
int visited[100];
int exist_path_len(ALGraph&G, char i, char j, int k)
{
	int position = Location(G, i);
	int l_position;
	if (k == 0 && i == j)return 1;//找到了一条路径并且符合要求
	else if(k>0)
	{
		visited[position] = 1;
		for (ArcNode* p = G.vertices[position].firstarc; p; p = p->nextarc)
		{
			char l = p->adjvex;
			l_position = Location(G, l);
			if(!visited[l_position])
				exist_path_len(G, l, j, k - 1);//剩余路径长度减一
		}
		visited[l_position] = 0;//曾经被访问过的结点允许出现在另一条路径上
	}
	return 0;//没找到
}

int main()
{

	return 0;



