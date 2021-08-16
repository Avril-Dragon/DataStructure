#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MaxSize 20

typedef struct node
{
	int number;
	char data;
	struct node *lchild,*rchild;
}BTNode;

typedef struct tnode
{
	char data;
	struct tnode *lchild,*rchild;
	int ltag,rtag;
}TBTNode;

typedef struct bstnode
{
	int key;
	struct bstnode *lchild,*rchild;
}BSTNode;

typedef struct
{
	BTNode *data[MaxSize];
	int front,rear;
}SqQueue;

int max(int a,int b)									//求树高的辅助函数 
{
	return a>b?a:b; 
}

void CreateBTree(BTNode *&b,char *str)					//创建树，以A(B,C)的形式 
{
	BTNode *St[MaxSize], *p;							//St 作为顺序栈
	int top=-1,k,j=0;									//top栈顶指针，k确定左右孩子，j为str移动
	char ch;
	b=NULL;
	ch = str[j];
	while(ch!='\0')
	{
		switch(ch)
		{
			case '(':	top++;St[top]=p;k=1;break;		//处理左孩子
			case ')':	top--;break;					//结点的子树处理完毕 
			case ',':	k=2;break;					 	//处理右孩子
			default:									//创建结点 
				p=(BTNode *)malloc(sizeof(BTNode));
				p->number = j;
				p->data = ch;
				p->lchild = p->rchild = NULL;
				if(b==NULL)								//这个节点可能是根节点 
					b=p;
				else 									//根据k值确定p为根节点的左or右孩子 
				{
					switch(k)
					{
					case 1:St[top]->lchild =p;break;
					case 2:St[top]->rchild =p;break;	
					}
					
				}
		}
		j++;
		ch=str[j];
	}
	 
}

void DispBTree(BTNode *b)							//输出树 
{
	if(b!=NULL)
	{
		printf("%c&%d",b->data,b->number);			//输出结点值 
		if(b->lchild!=NULL || b->rchild!=NULL)		//但凡有一个子结点都要输出 
		{
			printf("(");
			DispBTree(b->lchild);
			if(b->rchild!=NULL)
				printf(",");						//有右结点才输出 “，” 
			DispBTree(b->rchild);
			printf(")");
		}
	}
}

void DestoryBTree(BTNode *&b)						//销毁二叉树 
{
	if(b!=NULL)
	{
		DestoryBTree(b->lchild);
		DestoryBTree(b->rchild);
		free(b);
	}
}

BTNode * FindNode(BTNode *b,int e)					//深度遍历，递归，找到后返回地址 
{
	BTNode *p;
	if(b==NULL)										//若b=NULL 
		return NULL;
	else if(b->number==e)							//若b点数据即为e 
		return b;
	else 
	{
		p=FindNode(b->lchild,e);					//若在b->lchild找到 
		if(p!=NULL)
			return p;
		else
			FindNode(b->rchild,e);					//否则就在b->rchild找到 
	}
}

int BTHeight(BTNode *b)								//求树高 
{
	if(b==NULL)
		return 0;
	else
		return max(BTHeight(b->lchild),BTHeight(b->rchild))+1;
} 

void PreOrder(BTNode *b)							//先序遍历 
{
	if(b!=NULL)
	{
		printf("%c",b->data);
		PreOrder(b->lchild);
		PreOrder(b->rchild); 
	}
	
}

void InOrder(BTNode *b)								//中序遍历 
{
	if(b!=NULL)
	{
		InOrder(b->lchild);
		printf("%c",b->data);
		InOrder(b->rchild);
	}
}

void PostOrder(BTNode *b)							//后序遍历 
{
	if(b!=NULL)
	{
		PostOrder(b->lchild);
		PostOrder(b->rchild);
		printf("%c",b->data); 
	}
} 


//层次遍历的队列操作 
void InitQueue(SqQueue *&q)
{
	q = (SqQueue *)malloc(sizeof(SqQueue));
	q->front = q->rear = -1;
}

bool QueueEmpty(SqQueue *q)
{
	return(q->front==q->rear);
}

bool enQueue(SqQueue *&q,BTNode *p)
{
	if(q->rear==MaxSize-1)
		return false;
	q->rear++;
	q->data[q->rear]=p;
	return true;
}

bool deQueue(SqQueue *&q,BTNode *&p)
{
	if(q->front==q->rear)
		return false;
	q->front++;
	p=q->data[q->front];
		return true;
}

void LevelOrder(BTNode *b)							//层次遍历 
{
	BTNode *p;
	SqQueue *qu;
	InitQueue(qu);
	enQueue(qu,b);
	while(!QueueEmpty(qu))
	{
		deQueue(qu,p);
		printf("%c",p->data);
		if(p->lchild!=NULL)
			enQueue(qu,p->lchild);
		if(p->rchild!=NULL)
			enQueue(qu,p->rchild);
	}
}

BSTNode *BST_Search(BSTNode *T,int key)				//非递归二叉排序树搜索(最坏空间复杂度O(1)) 
{
	while(T!=NULL&&T->key!=key)
	{
		if(key<T->key)
			T=T->lchild;
		else T = T->rchild;	
	}
	return T;	
} 
BSTNode *BSTSearch(BSTNode *T,int key)				//递归版二叉排序树搜索(最坏空间复杂度O(h)) 
{
	if (T==NULL) 
		return NULL;
	if(T->key==key)
		return T;
	else if(key<T->key)
		return BSTSearch(T->lchild,key);
	else 
		return BSTSearch(T->rchild,key);
} 		

int BSTInsert(BSTNode *&T,int key)					//递归版二叉树插入操作 
{
	if(T==NULL)										//若树为空则构造树 
	{
		T=(BSTNode *)malloc(sizeof(BSTNode));
		T->key=key;
		T->lchild=T->rchild=NULL;
		return 1;
	} 
	else if(key==T->key)							//不允许出现相同的key 
		return 0;
	else if(key<T->key)
		return BSTInsert(T->lchild,key);
	else 
		return 	BSTInsert(T->rchild,key);
}

void Create_BST(BSTNode *&T,int str[],int n)			//构造二叉排序树 
{
	T=NULL;
	int i=0;
	while(i<n)
	{
		BSTInsert(T,str[i]);
		i++;
	}
}

void DispBSTree(BSTNode *b)							//输出树 
{
	if(b!=NULL)
	{
		printf("%d",b->key);			//输出结点值 
		if(b->lchild!=NULL || b->rchild!=NULL)		//但凡有一个子结点都要输出 
		{
			printf("(");
			DispBSTree(b->lchild);
			if(b->rchild!=NULL)
				printf(",");						//有右结点才输出 “，” 
			DispBSTree(b->rchild);
			printf(")");
		}
	}
}

int main()
{
	BTNode *b;
	BSTNode *t;
	char str[30]="A(B(D(,J),K),C(E,F))";
	int str2[10]={50,66,60,26,21,30,70,68};
	CreateBTree(b,str);
	printf("创建完成\n");
	DispBTree(b);
	//DestoryBTree(b);
	printf("查找4所在结点%c\n",FindNode(b,4)->data);
	printf("树高：%d\n",BTHeight(b));
	printf("前序：");
	PreOrder(b);
	printf("\n");
	printf("中序：");
	InOrder(b);
	printf("\n");
	printf("后序：");
	PostOrder(b);
	printf("\n");
	printf("层次：");
	LevelOrder(b);
	printf("\n");
	Create_BST(t,str2,8);
	DispBSTree(t);
		
	//printf("销毁完成\n"); 
	//DispBTree(b);
}
