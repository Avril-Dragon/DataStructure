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

int max(int a,int b)
{
	return a>b?a:b; 
}
void CreateBTree(BTNode *&b,char *str)
{
	BTNode *St[MaxSize], *p;		//St 作为顺序栈
	int top=-1,k,j=0;			//top栈顶指针，k确定左右孩子，j为str移动
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

void DispBTree(BTNode *b)
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

void DestoryBTree(BTNode *&b)
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
			FindNode(b->rchild,e);			//否则就在b->rchild找到 
	}
}
int BTHeight(BTNode *b)
{
	if(b==NULL)
		return 0;
	else
		return max(BTHeight(b->lchild),BTHeight(b->rchild))+1;
} 
int main()
{
	BTNode *b;
	char str[30]="A(B(D(J,G),K),C(E,F))";
	CreateBTree(b,str);
	printf("创建完成\n");
	DispBTree(b);
	//DestoryBTree(b);
	printf("%c",FindNode(b,4)->data);
	printf("%d",BTHeight(b));
		
	//printf("销毁完成\n"); 
	//DispBTree(b);
}
