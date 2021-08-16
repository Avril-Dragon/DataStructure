#include<stdio.h>
#include<stdlib.h>
#define MaxSize 20

typedef struct tnode
{
	char data;
	struct tnode *lchild,*rchild;
	int ltag=0;
	int rtag=0;
}TBTNode;

void InThread(TBTNode *&b,TBTNode *&pre)				//中序线索化 
{
	if(pre!=NULL)
		printf("pre此时为%c\n",pre->data);
	else
		printf("pre此时为NULL\n");
	if(b!=NULL)
	{
		printf("此时结点为%c\n",b->data); 
		InThread(b->lchild,pre);					//递归线索化左子树 
		
		if(b->lchild==NULL)							//左子树为空，建立前驱线索 
		{
			b->lchild=pre;
			b->ltag=1;
			if(pre!=NULL)
				printf("结点%c的前驱设为了%c\n",b->data,pre->data);
			else
				printf("结点%c的前驱设为了NULL\n",b->data);
		}
		if(pre!=NULL&&pre->rchild==NULL)			//右子树为空，建立前驱结点的后继线索 
		{
			pre->rchild=b;
			pre->rtag=1;
			printf("结点%c的后继设为了%c\n",pre->data,b->data);
		}
		pre = b;									//移动pre结点 
		
		InThread(b->rchild,pre);						//递归线索化右子树 
	}
}

void PreThread(TBTNode *&b,TBTNode *&pre)				//先序线索化 
{
	if(pre!=NULL)
		printf("pre此时为%c\n",pre->data);
	else
		printf("pre此时为NULL\n");
	if(b!=NULL)
	{
		
		printf("此时结点为%c\n",b->data); 
		if(b->lchild==NULL)							//左子树为空，建立前驱线索 
		{
			b->lchild=pre;
			b->ltag=1;
			if(pre!=NULL)
				printf("结点%c的前驱设为了%c\n",b->data,pre->data);
			else
				printf("结点%c的前驱设为了NULL\n",b->data);
		}
		if(pre!=NULL&&pre->rchild==NULL)			//右子树为空，建立前驱结点的后继线索 
		{
			pre->rchild=b;
			pre->rtag=1;
			printf("结点%c的后继设为了%c\n",pre->data,b->data);
		}
		pre = b;									//移动pre结点 
		if(b->ltag==0) 
			PreThread(b->lchild,pre);					//递归线索化左子树 
		if(b->rtag==0)
			PreThread(b->rchild,pre);						//递归线索化右子树 
	}
}

void PostThread(TBTNode *&b,TBTNode *&pre)				//先序线索化 
{
	if(pre!=NULL)
		printf("pre此时为%c\n",pre->data);
	else
		printf("pre此时为NULL\n");
	if(b!=NULL)
	{
		PostThread(b->lchild,pre);					//递归线索化左子树 
		PostThread(b->rchild,pre);					//递归线索化右子树 
		printf("此时结点为%c\n",b->data); 
		if(b->lchild==NULL)							//左子树为空，建立前驱线索 
		{
			b->lchild=pre;
			b->ltag=1;
			if(pre!=NULL)
				printf("结点%c的前驱设为了%c\n",b->data,pre->data);
			else
				printf("结点%c的前驱设为了NULL\n",b->data);
		}
		if(pre!=NULL&&pre->rchild==NULL)			//右子树为空，建立前驱结点的后继线索 
		{
			pre->rchild=b;
			pre->rtag=1;
			printf("结点%c的后继设为了%c\n",pre->data,b->data);
		}
		pre = b;									//移动pre结点  
	}
}

void CreateInThread(TBTNode *b)						//中序线索化二叉树 
{
	TBTNode *pre = NULL;							//pre结点作为引用型 传参过去 
	if(b!=NULL)
	{
		InThread(b,pre);
		pre->rchild = NULL;							//处理完成之后，此时pre指向最后一个结点 
		pre->rtag = 1;								//处理其后继节点 
	}
} 

void CreatePreThread(TBTNode *b)						//先序线索化二叉树 
{
	TBTNode *pre = NULL;							//pre结点作为引用型 传参过去 
	if(b!=NULL)
	{
		PreThread(b,pre);
		pre->rchild = NULL;							//处理完成之后，此时pre指向最后一个结点 
		pre->rtag = 1;								//处理其后继节点 
	}
} 

void CreatePostThread(TBTNode *b)						//后序线索化二叉树 
{
	TBTNode *pre = NULL;							//pre结点作为引用型 传参过去 
	if(b!=NULL)
	{
		PostThread(b,pre);
		pre->rchild = NULL;							//处理完成之后，此时pre指向最后一个结点 
		pre->rtag = 1;								//处理其后继节点 
	}
}

void CreateBTree(TBTNode *&b,char *str)					//创建树，以A(B,C)的形式 
{
	TBTNode *St[MaxSize], *p;							//St 作为顺序栈
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
				p=(TBTNode *)malloc(sizeof(TBTNode));
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

void DispBTree(TBTNode *b)							//输出树 
{
	if(b!=NULL)
	{
		printf("%c",b->data);						//输出结点值 
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

void ThInOrder(TBTNode *b)
{
	while(b!=NULL)
	{
		while(b->ltag==0)
		{
			b=b->lchild;
		}
		printf("%c",b->data);
		if(b->rtag==1&&b->rchild!=NULL)
		{
			b=b->lchild;
			printf("%c",b->data); 
		}	
		b=b->rchild;
		
	} 
	
}

int main()
{
	TBTNode *b;
	char str[30]="A(B(D),C)";
	CreateBTree(b,str);
	printf("创建完成\n");
	DispBTree(b);
	printf("\n");
	//CreateInThread(b);
	//printf("中序线索化完成\n");
	
	//CreatePreThread(b);
	//printf("先序线索化完成\n");
	
	CreatePostThread(b);
	printf("后序线索化完成\n");
	//printf("结果为:\n");
	//ThInOrder(b);
}
