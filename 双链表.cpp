#include<stdio.h>
#include<stdlib.h>
typedef struct DNode{//����˫����ṹ����
	int data;//������
	struct DNode*prior,*next;//ǰ���ͺ��ָ��
}DNode,*DLinkList;
bool InitList(DLinkList &L){//��ʼ��˫����
	L=(DNode*)malloc(sizeof(DNode));//����һ��ͷ���
	if(L==NULL)//���䲻�㣬�ڴ�ʧ��
		return false;
	L->next=NULL;//ͷ����prior��Զָ��NULL
	L->prior=NULL;//ͷ���֮����ʱ��û�н��
	return true;
}
bool InsertNextDNode(DNode*p,DNode*s){//˫����Ĳ���
	if(p==NULL||s==NULL)
		return false;
	s->next=p->next;
	if(p->next!=NULL)
		p->next->prior=s;
	s->prior=p;
	p->next=s;
	return true;
}
//˫�����ɾ��
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

//��������
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
