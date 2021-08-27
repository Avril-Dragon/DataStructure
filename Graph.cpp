#include<stdio.h>
#include<stdlib.h>
#define MaxVertexNum 10
#define VertexType char

//邻接表法
typedef struct VNode{			//顶点 
	VertexType data;
	ArcNode *first;
}VNode; 

typedef struct ArcNode{			//边/弧 
	int adjvex;					//边或弧指向哪个顶点
	struct ArcNode *next;		//指向下一条弧的指针 
}ArcNode;

typedef struct{					//用邻接表储存的图 
	VNode[MaxVertexNum] vertices;
	int vexnum,arcnum;
}ALGraph;

bool visited [MAX_VERTEX_NUM];		//访问标记数组

void BFSTraverse(Graph G)			//对图G进行广度优先遍历
{
	for(int i=0; i<G.vexnum;++i)
	{
		visited [i]=FALSE;			//访问标记数组初始化
		InitQueue(Q);				//初始化辅助队列Q
	} 	
	for(i=0; i<G.vexnum;++i)		//从0号顶点开始遍历	
	{
		if( !visited[i])			//对每个连通分量调用一次BFS
		BFS( G,i);					//vi未访问过，从vi开始BFS
	} 
}

void BFS(Graph G,int x)			//广度优先遍历(队列) 
{
	visit(v);					//访问初始结点 
	visted[v] = true;			//将其标记为 已访问 
	Enqueue(Q,v);				//入队 
	while(!isEmpyt(Q))			//只要队列不为空 就一直遍历 
	{
		Dequeue(Q,v);			//出队 
		for(w=FirstNeighbor(G,v);w>0;w=NextNeighbor(G,v,w))		//检测v的所有邻接点 
		{
			if(!visited[w])		//没访问过就访问，标记，入队 
			{
				visit(w);
				visited[w] = true;
				Enqueue(Q,w);
			}
		}
	}
}

void DFSTraverse(Graph G)			//对图G进行深度优先遍历
{

	for( v=0; v<G.vexnum; ++v)
		visited[v]=FALSE;			//初始化已访问标记数据

	for( v=0; v<G.vexnum;++v)
		if( ! visited[v])
			DFS(G,v);
}

void DFS(Graph G,int v)			//广度优先遍历(栈) 
{
	visit(v);					//访问顶点v 
	visted[v] = true;			//将其标记 
	for(w=FirstNeighbor(G,v));w>0;w=NextNeighbor(G,v,w)			//检测所有邻接点 
	{
		if(!visited[w])			//没有访问则进行访问 
			DFS(G,w);
	} 
}

void BFS_MIN_Distance(Graph G,int u)			//BFS求最短路径 
{
	for(i=0;i<G.vexnum;i++)
	{
		d[i] = 999;						//d[i]表示从u到i的最短路径 
		path[i] = -1;					//path[i]表示最短路径从哪过来 
	} 
	
	d[u]=0;						
	visited[u]=true;
	Enqueue(Q,u);				//入队 
	while(!isEmpyt(Q))			//只要队列不为空 就一直遍历 
	{
		Dequeue(Q,u);			//出队 
		for(w=FirstNeighbor(G,u);w>0;w=NextNeighbor(G,u,w))		//检测v的所有邻接点 
		{
			if(!visited[w])		//w为u的尚未访问的邻接顶点 
			{
				d[w] = d[u]+1;			//路径长度+1 
				path[w] = u;			//最短路径从u到w 
				visited[w] = true;		//标记已访问	
				Enqueue(Q,w);			//w入队 
			}
		}
	}
	
} 




















