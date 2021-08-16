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

void InThread(TBTNode *&b,TBTNode *&pre)				//���������� 
{
	if(pre!=NULL)
		printf("pre��ʱΪ%c\n",pre->data);
	else
		printf("pre��ʱΪNULL\n");
	if(b!=NULL)
	{
		printf("��ʱ���Ϊ%c\n",b->data); 
		InThread(b->lchild,pre);					//�ݹ������������� 
		
		if(b->lchild==NULL)							//������Ϊ�գ�����ǰ������ 
		{
			b->lchild=pre;
			b->ltag=1;
			if(pre!=NULL)
				printf("���%c��ǰ����Ϊ��%c\n",b->data,pre->data);
			else
				printf("���%c��ǰ����Ϊ��NULL\n",b->data);
		}
		if(pre!=NULL&&pre->rchild==NULL)			//������Ϊ�գ�����ǰ�����ĺ������ 
		{
			pre->rchild=b;
			pre->rtag=1;
			printf("���%c�ĺ����Ϊ��%c\n",pre->data,b->data);
		}
		pre = b;									//�ƶ�pre��� 
		
		InThread(b->rchild,pre);						//�ݹ������������� 
	}
}

void PreThread(TBTNode *&b,TBTNode *&pre)				//���������� 
{
	if(pre!=NULL)
		printf("pre��ʱΪ%c\n",pre->data);
	else
		printf("pre��ʱΪNULL\n");
	if(b!=NULL)
	{
		
		printf("��ʱ���Ϊ%c\n",b->data); 
		if(b->lchild==NULL)							//������Ϊ�գ�����ǰ������ 
		{
			b->lchild=pre;
			b->ltag=1;
			if(pre!=NULL)
				printf("���%c��ǰ����Ϊ��%c\n",b->data,pre->data);
			else
				printf("���%c��ǰ����Ϊ��NULL\n",b->data);
		}
		if(pre!=NULL&&pre->rchild==NULL)			//������Ϊ�գ�����ǰ�����ĺ������ 
		{
			pre->rchild=b;
			pre->rtag=1;
			printf("���%c�ĺ����Ϊ��%c\n",pre->data,b->data);
		}
		pre = b;									//�ƶ�pre��� 
		if(b->ltag==0) 
			PreThread(b->lchild,pre);					//�ݹ������������� 
		if(b->rtag==0)
			PreThread(b->rchild,pre);						//�ݹ������������� 
	}
}

void PostThread(TBTNode *&b,TBTNode *&pre)				//���������� 
{
	if(pre!=NULL)
		printf("pre��ʱΪ%c\n",pre->data);
	else
		printf("pre��ʱΪNULL\n");
	if(b!=NULL)
	{
		PostThread(b->lchild,pre);					//�ݹ������������� 
		PostThread(b->rchild,pre);					//�ݹ������������� 
		printf("��ʱ���Ϊ%c\n",b->data); 
		if(b->lchild==NULL)							//������Ϊ�գ�����ǰ������ 
		{
			b->lchild=pre;
			b->ltag=1;
			if(pre!=NULL)
				printf("���%c��ǰ����Ϊ��%c\n",b->data,pre->data);
			else
				printf("���%c��ǰ����Ϊ��NULL\n",b->data);
		}
		if(pre!=NULL&&pre->rchild==NULL)			//������Ϊ�գ�����ǰ�����ĺ������ 
		{
			pre->rchild=b;
			pre->rtag=1;
			printf("���%c�ĺ����Ϊ��%c\n",pre->data,b->data);
		}
		pre = b;									//�ƶ�pre���  
	}
}

void CreateInThread(TBTNode *b)						//���������������� 
{
	TBTNode *pre = NULL;							//pre�����Ϊ������ ���ι�ȥ 
	if(b!=NULL)
	{
		InThread(b,pre);
		pre->rchild = NULL;							//�������֮�󣬴�ʱpreָ�����һ����� 
		pre->rtag = 1;								//�������̽ڵ� 
	}
} 

void CreatePreThread(TBTNode *b)						//���������������� 
{
	TBTNode *pre = NULL;							//pre�����Ϊ������ ���ι�ȥ 
	if(b!=NULL)
	{
		PreThread(b,pre);
		pre->rchild = NULL;							//�������֮�󣬴�ʱpreָ�����һ����� 
		pre->rtag = 1;								//�������̽ڵ� 
	}
} 

void CreatePostThread(TBTNode *b)						//���������������� 
{
	TBTNode *pre = NULL;							//pre�����Ϊ������ ���ι�ȥ 
	if(b!=NULL)
	{
		PostThread(b,pre);
		pre->rchild = NULL;							//�������֮�󣬴�ʱpreָ�����һ����� 
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
	char str[30]="A(B(D),C)";
	CreateBTree(b,str);
	printf("�������\n");
	DispBTree(b);
	printf("\n");
	//CreateInThread(b);
	//printf("�������������\n");
	
	//CreatePreThread(b);
	//printf("�������������\n");
	
	CreatePostThread(b);
	printf("�������������\n");
	//printf("���Ϊ:\n");
	//ThInOrder(b);
}
