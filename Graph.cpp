#include<stdio.h>
#include<stdlib.h>
#define MaxVertexNum 10
#define VertexType char

//�ڽӱ�
typedef struct VNode{			//���� 
	VertexType data;
	ArcNode *first;
}VNode; 

typedef struct ArcNode{			//��/�� 
	int adjvex;					//�߻�ָ���ĸ�����
	struct ArcNode *next;		//ָ����һ������ָ�� 
}ArcNode;

typedef struct{					//���ڽӱ����ͼ 
	VNode[MaxVertexNum] vertices;
	int vexnum,arcnum;
}ALGraph;

bool visited [MAX_VERTEX_NUM];		//���ʱ������

void BFSTraverse(Graph G)			//��ͼG���й�����ȱ���
{
	for(int i=0; i<G.vexnum;++i)
	{
		visited [i]=FALSE;			//���ʱ�������ʼ��
		InitQueue(Q);				//��ʼ����������Q
	} 	
	for(i=0; i<G.vexnum;++i)		//��0�Ŷ��㿪ʼ����	
	{
		if( !visited[i])			//��ÿ����ͨ��������һ��BFS
		BFS( G,i);					//viδ���ʹ�����vi��ʼBFS
	} 
}

void BFS(Graph G,int x)			//������ȱ���(����) 
{
	visit(v);					//���ʳ�ʼ��� 
	visted[v] = true;			//������Ϊ �ѷ��� 
	Enqueue(Q,v);				//��� 
	while(!isEmpyt(Q))			//ֻҪ���в�Ϊ�� ��һֱ���� 
	{
		Dequeue(Q,v);			//���� 
		for(w=FirstNeighbor(G,v);w>0;w=NextNeighbor(G,v,w))		//���v�������ڽӵ� 
		{
			if(!visited[w])		//û���ʹ��ͷ��ʣ���ǣ���� 
			{
				visit(w);
				visited[w] = true;
				Enqueue(Q,w);
			}
		}
	}
}

void DFSTraverse(Graph G)			//��ͼG����������ȱ���
{

	for( v=0; v<G.vexnum; ++v)
		visited[v]=FALSE;			//��ʼ���ѷ��ʱ������

	for( v=0; v<G.vexnum;++v)
		if( ! visited[v])
			DFS(G,v);
}

void DFS(Graph G,int v)			//������ȱ���(ջ) 
{
	visit(v);					//���ʶ���v 
	visted[v] = true;			//������ 
	for(w=FirstNeighbor(G,v));w>0;w=NextNeighbor(G,v,w)			//��������ڽӵ� 
	{
		if(!visited[w])			//û�з�������з��� 
			DFS(G,w);
	} 
}

void BFS_MIN_Distance(Graph G,int u)			//BFS�����·�� 
{
	for(i=0;i<G.vexnum;i++)
	{
		d[i] = 999;						//d[i]��ʾ��u��i�����·�� 
		path[i] = -1;					//path[i]��ʾ���·�����Ĺ��� 
	} 
	
	d[u]=0;						
	visited[u]=true;
	Enqueue(Q,u);				//��� 
	while(!isEmpyt(Q))			//ֻҪ���в�Ϊ�� ��һֱ���� 
	{
		Dequeue(Q,u);			//���� 
		for(w=FirstNeighbor(G,u);w>0;w=NextNeighbor(G,u,w))		//���v�������ڽӵ� 
		{
			if(!visited[w])		//wΪu����δ���ʵ��ڽӶ��� 
			{
				d[w] = d[u]+1;			//·������+1 
				path[w] = u;			//���·����u��w 
				visited[w] = true;		//����ѷ���	
				Enqueue(Q,w);			//w��� 
			}
		}
	}
	
} 




















