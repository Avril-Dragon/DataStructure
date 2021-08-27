#include<stdio.h>
#include<stdlib.h>
typedef struct DNode{//定义双链表结构类型
	int data;//数据域
	struct DNode*prior,*next;//前驱和后继指针
}DNode,*DLinkList;
bool InitList(DLinkList &L){//初始化双链表
	L=(DNode*)malloc(sizeof(DNode));//分配一个头结点
	if(L==NULL)//分配不足，内存失败
		return false;
	L->next=NULL;//头结点的prior永远指向NULL
	L->prior=NULL;//头结点之后暂时还没有结点
	return true;
}
bool InsertNextDNode(DNode*p,DNode*s){//双链表的插入
	if(p==NULL||s==NULL)
		return false;
	s->next=p->next;
	if(p->next!=NULL)
		p->next->prior=s;
	s->prior=p;
	p->next=s;
	return true;
}
//双链表的删除
bool DeleteNextDNode(DNode *p){
	if(p==NULL)
		return false;
	DNode*q=p->next;
	if(q=NULL)
		return false;
	p->next=q->next;
	if(q->next!=NULL)
		q->next->prior=p;
		free(q);
		return true;
	}

//销毁链表
void DestoryList(DLinkList &L){
	while(L->next!=NULL){
		DeleteNextDNode(L);
		free(L);
		L=NULL;
	}
}
int main(){
	DLinkList L;
	InitList (L);
	return 0;
}
