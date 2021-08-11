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
	BTNode *St[MaxSize], *p;		//St ��Ϊ˳��ջ
	int top=-1,k,j=0;			//topջ��ָ�룬kȷ�����Һ��ӣ�jΪstr�ƶ�
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

void DispBTree(BTNode *b)
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

void DestoryBTree(BTNode *&b)
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
			FindNode(b->rchild,e);			//�������b->rchild�ҵ� 
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
	printf("�������\n");
	DispBTree(b);
	//DestoryBTree(b);
	printf("%c",FindNode(b,4)->data);
	printf("%d",BTHeight(b));
		
	//printf("�������\n"); 
	//DispBTree(b);
}
