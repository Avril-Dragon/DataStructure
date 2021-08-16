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

TBTNode * pre=NULL;		//ȫ�ֱ�����ָ��ǰ���ʽ���ǰ��
 

void visit(TBTNode *q)
{
	if(q->lchild==NULL)							//������Ϊ�գ�����ǰ������ 
	{
		q->lchild=pre;
		q->ltag=1;
		if(pre!=NULL)
			printf("���%c��ǰ����Ϊ��%c\n",q->data,pre->data);
		else
			printf("���%c��ǰ����Ϊ��NULL\n",q->data);
	}
	if(pre!=NULL&&pre->rchild==NULL)			//������Ϊ�գ�����ǰ�����ĺ������ 
	{
		pre->rchild=q;
		pre->rtag=1;
		printf("���%c�ĺ����Ϊ��%c\n",pre->data,q->data);
	}
	pre = q;									//�ƶ�pre��� 	
}
 
void InThread(TBTNode *&b)							//���������� 
{
	if(b!=NULL)
	{
		InThread(b->lchild);						//�ݹ������������� 
		visit(b);									//���ʸ��ڵ� 
		InThread(b->rchild);						//�ݹ������������� 
	}
}
	
void PreThread(TBTNode *b)							//���������� 
{
	if(b!=NULL)
	{
		visit(b);
		if(b->ltag==0)									//�ر�ע�� ֻ��ȷ������ǰ����������ܷ��� 
			PreThread(b->lchild);						//�������ѭ�� 
		if(b->rtag==0)									//�ر�ע�� ֻ��ȷ�����Ǻ����������ܷ���
			PreThread(b->rchild); 
	}
}

void PostThread(TBTNode *&b)							//���������� 
{
	if(b!=NULL)
	{
		PostThread(b->lchild);						//�ݹ������������� 
		PostThread(b->rchild);						//�ݹ������������� 
		visit(b);									//���ʸ��ڵ� 
	}
}



void CreateInThread(TBTNode *b)						//���������������� 
{
	pre = NULL;
	if(b!=NULL)
	{
		InThread(b);
		if(pre->rchild = NULL)							//�������֮�󣬴�ʱpreָ�����һ����� 
			pre->rtag = 1;								//�������̽ڵ� 
	}
} 

void CreatePreThread(TBTNode *b)						//���������������� 
{
	pre = NULL;
	if(b!=NULL)
	{
		PreThread(b);
		if(pre->rchild = NULL)							//�������֮�󣬴�ʱpreָ�����һ����� 
			pre->rtag = 1;								//�������̽ڵ� 
	}
} 

void CreatePostThread(TBTNode *b)						//���������������� 
{
	pre = NULL;
	if(b!=NULL)
	{
		PostThread(b);
		if(pre->rchild = NULL)							//�������֮�󣬴�ʱpreָ�����һ����� 
			pre->rtag = 1;								//�������̽ڵ� 
	}
}

void CreateBTree(TBTNode *&b,char *str)					//����������A(B,C)����ʽ 
{
	TBTNode *St[MaxSize], *p;							//St ��Ϊ˳��ջ
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
				p=(TBTNode *)malloc(sizeof(TBTNode));
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

void DispBTree(TBTNode *b)							//����� 
{
	if(b!=NULL)
	{
		printf("%c",b->data);						//������ֵ 
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
	char str[30]="A(B(D,E),C)";
	CreateBTree(b,str);
	printf("�������\n");
	DispBTree(b);
	printf("\n");
	//CreateInThread(b);
	//printf("�������������\n");

	//CreatePreThread(b);
	//printf("ǰ�����������\n");
	
	CreatePostThread(b);
	printf("�������������\n");
	//ThInOrder(b);
}
