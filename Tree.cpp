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

int max(int a,int b)									//�����ߵĸ������� 
{
	return a>b?a:b; 
}

void CreateBTree(BTNode *&b,char *str)					//����������A(B,C)����ʽ 
{
	BTNode *St[MaxSize], *p;							//St ��Ϊ˳��ջ
	int top=-1,k,j=0;									//topջ��ָ�룬kȷ�����Һ��ӣ�jΪstr�ƶ�
	char ch;
	b=NULL;
	ch = str[j];
	while(ch!='\0')
	{
		switch(ch)
		{
			case '(':	top++;St[top]=p;k=1;break;		//��������
			case ')':	top--;break;					//��������������� 
			case ',':	k=2;break;					 	//�����Һ���
			default:									//������� 
				p=(BTNode *)malloc(sizeof(BTNode));
				p->number = j;
				p->data = ch;
				p->lchild = p->rchild = NULL;
				if(b==NULL)								//����ڵ�����Ǹ��ڵ� 
					b=p;
				else 									//����kֵȷ��pΪ���ڵ����or�Һ��� 
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

void DispBTree(BTNode *b)							//����� 
{
	if(b!=NULL)
	{
		printf("%c&%d",b->data,b->number);			//������ֵ 
		if(b->lchild!=NULL || b->rchild!=NULL)		//������һ���ӽ�㶼Ҫ��� 
		{
			printf("(");
			DispBTree(b->lchild);
			if(b->rchild!=NULL)
				printf(",");						//���ҽ������ ������ 
			DispBTree(b->rchild);
			printf(")");
		}
	}
}

void DestoryBTree(BTNode *&b)						//���ٶ����� 
{
	if(b!=NULL)
	{
		DestoryBTree(b->lchild);
		DestoryBTree(b->rchild);
		free(b);
	}
}

BTNode * FindNode(BTNode *b,int e)					//��ȱ������ݹ飬�ҵ��󷵻ص�ַ 
{
	BTNode *p;
	if(b==NULL)										//��b=NULL 
		return NULL;
	else if(b->number==e)							//��b�����ݼ�Ϊe 
		return b;
	else 
	{
		p=FindNode(b->lchild,e);					//����b->lchild�ҵ� 
		if(p!=NULL)
			return p;
		else
			FindNode(b->rchild,e);					//�������b->rchild�ҵ� 
	}
}

int BTHeight(BTNode *b)								//������ 
{
	if(b==NULL)
		return 0;
	else
		return max(BTHeight(b->lchild),BTHeight(b->rchild))+1;
} 

void PreOrder(BTNode *b)							//������� 
{
	if(b!=NULL)
	{
		printf("%c",b->data);
		PreOrder(b->lchild);
		PreOrder(b->rchild); 
	}
	
}

void InOrder(BTNode *b)								//������� 
{
	if(b!=NULL)
	{
		InOrder(b->lchild);
		printf("%c",b->data);
		InOrder(b->rchild);
	}
}

void PostOrder(BTNode *b)							//������� 
{
	if(b!=NULL)
	{
		PostOrder(b->lchild);
		PostOrder(b->rchild);
		printf("%c",b->data); 
	}
} 


//��α����Ķ��в��� 
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

void LevelOrder(BTNode *b)							//��α��� 
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

BSTNode *BST_Search(BSTNode *T,int key)				//�ǵݹ��������������(��ռ临�Ӷ�O(1)) 
{
	while(T!=NULL&&T->key!=key)
	{
		if(key<T->key)
			T=T->lchild;
		else T = T->rchild;	
	}
	return T;	
} 
BSTNode *BSTSearch(BSTNode *T,int key)				//�ݹ���������������(��ռ临�Ӷ�O(h)) 
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

int BSTInsert(BSTNode *&T,int key)					//�ݹ�������������� 
{
	if(T==NULL)										//����Ϊ�������� 
	{
		T=(BSTNode *)malloc(sizeof(BSTNode));
		T->key=key;
		T->lchild=T->rchild=NULL;
		return 1;
	} 
	else if(key==T->key)							//�����������ͬ��key 
		return 0;
	else if(key<T->key)
		return BSTInsert(T->lchild,key);
	else 
		return 	BSTInsert(T->rchild,key);
}

void Create_BST(BSTNode *&T,int str[],int n)			//������������� 
{
	T=NULL;
	int i=0;
	while(i<n)
	{
		BSTInsert(T,str[i]);
		i++;
	}
}

void DispBSTree(BSTNode *b)							//����� 
{
	if(b!=NULL)
	{
		printf("%d",b->key);			//������ֵ 
		if(b->lchild!=NULL || b->rchild!=NULL)		//������һ���ӽ�㶼Ҫ��� 
		{
			printf("(");
			DispBSTree(b->lchild);
			if(b->rchild!=NULL)
				printf(",");						//���ҽ������ ������ 
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
	printf("�������\n");
	DispBTree(b);
	//DestoryBTree(b);
	printf("����4���ڽ��%c\n",FindNode(b,4)->data);
	printf("���ߣ�%d\n",BTHeight(b));
	printf("ǰ��");
	PreOrder(b);
	printf("\n");
	printf("����");
	InOrder(b);
	printf("\n");
	printf("����");
	PostOrder(b);
	printf("\n");
	printf("��Σ�");
	LevelOrder(b);
	printf("\n");
	Create_BST(t,str2,8);
	DispBSTree(t);
		
	//printf("�������\n"); 
	//DispBTree(b);
}
