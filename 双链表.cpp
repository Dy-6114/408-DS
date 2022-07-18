#include<stdio.h>
#include<stdlib.h>

typedef struct DNode{
	int data;
	struct DNode *next,*prior;
}DNode, *DLinkList;

bool InitDLinkList(DLinkList &L){
	L = (DLinkList)malloc(sizeof(DNode));
	if (L==NULL) return false;
	L->prior = NULL;
	L->next = NULL;
	return true;
}

bool Empty(DLinkList L) {
	if(L->next==NULL) return true;
	else return false;
}

//在p结点之后插入s结点
bool InsertNextDNode(DNode *p, DNode *s){
	s->next = p->next;
	if(p->next != NULL)
		p->next->prior = s;
	s->prior = p;
	p->next = s;
	return true;
}

//删除p的后继节点q
bool DeleteNextDNode(DNode *p){
	if(p==NULL) return false;
	DNode *q = p->next;
	if(q==NULL) return false;
	p->next = q->next;
	if(q->next!=NULL)
		q->next->prior = p;
	free(q);
	return true;
} 

int main(){
	DLinkList L;
	InitDLinkList(L);
}
