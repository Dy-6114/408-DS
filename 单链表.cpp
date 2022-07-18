#include<stdlib.h>
#include<stdio.h>

typedef struct LNode{
	int data;//数据域 
	struct LNode *next;//指针域 
}LNode, *LinkList;

//采用头插法建立单链表
LinkList List_HeadInsert(LinkList &L){ //逆向建立单链表 
	LNode *s; int x;
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	scanf("%d",&x);
	while(x!=9999) {
		s = (LNode *)malloc(sizeof(LNode));
		s->data = x;
		s->next = L->next;
		L->next = s;
		scanf("%d",&x);
	}
	return L;
}

//采用尾插法建立单链表
LinkList List_TailInsert(LinkList &L){//正向建立单链表 
	int x;
	L = (LinkList)malloc(sizeof(LNode));
	LNode *s,*r=L;
	scanf("%d", &x);
	while(x!=9999){
		s = (LNode *)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;
		scanf("%d", &x);
	}
	r->next = NULL;
	return L;
} 


//bool InitList(LinkList &L) { //不带头结点 
//	L = NULL;
//	return true;
//}

bool InitList(LinkList &L) { //带头结点 
	L = (LNode *)malloc(sizeof(LNode));
	if(L==NULL) return false;
	L->next = NULL;
	return true;
}

bool Empty(LinkList L) {
	if(L->next==NULL) 
		return true;
	else 
		return false;//带头结点 
//	return (L==NULL);//不带头结点 
}

//按位查找，返回第i个元素（带头结点）
LNode *GetElem(LinkList L, int i){
	int j=1;
	LNode *p=L->next;
	if(i==0) return L;
	if(i<1) return NULL;
	while(p!=NULL && j<i){
		p=p->next;
		j++;
	}
	return p;
}

//按值插入，找到数据域==e的结点
LNode * LocateElem(LinkList L, int e){
	LNode *p = L->next;
	while(p!=NULL && p->data!=e)
		p = p->next;
	return p;
}

//求表的长度
int Length(LinkList L){
	LNode *p = L;
	int len = 0;
	while(p->next != NULL){
		len++;
		p = p->next;
	}
	return len;
} 

//bool ListInsert(LinkList &L, int i, int e){//不带头结点 
//	if(i<1) return false;
//	if(i==1){
//		LNode *s=(LNode *)malloc(sizeof(LNode));
//		s->data = e;
//		s->next = L;
//		L = s;
//		return true;
//	} 
//	LNode *p;
//	int j=1;
//	p = L;
//	while (p!=NULL && j<i-1) {
//		p=p->next;
//		j++;
//	}
//	if(p==NULL) return false;
//	LNode *s = (LNode *)malloc(sizeof(LNode));
//	s->data=e;
//	s->next=p->next;
//	p->next=s;
//	return ture;
//}

bool ListInsert(LinkList &L, int i, int e){//带头结点 
	//LNode *p = GetElem(L, i-1)
	if(i<1) return false;
	LNode *p;
	int j=0;
	p = L;
	while (p!=NULL && j<i-1) {
		p=p->next;
		j++;
	}
	// return InsertNextNode(p, e) 封装的好处 
	if(p==NULL) return false;
	LNode *s = (LNode *)malloc(sizeof(LNode));
	s->data=e;
	s->next=p->next;
	p->next=s;
	return true;
}

//后插操作：在p结点之后插入e 
bool InsertNextNode(LNode *p, int e){
	if(p==NULL) return false;
	LNode *s = (LNode *)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}

//前插操作：在p结点之前插入结点s 
bool InsertPriorNode(LNode *p, LNode *s){
	if(p==NULL) return false;
	if(s==NULL) return false;
	s->next = p->next;
	p->next = s;
	int temp = p->data;
	p->data = s->data;
	s->data = temp;
	return true;
} 

//按位序删除（带头结点）
bool ListDelete(LinkList &L, int i, int &e){
	if(i<1) return false;
	LNode *p;
	int j=0;
	p = L;
	while (p!=NULL && j<i-1) {
		p=p->next;
		j++;
	}
	if(p==NULL) return false;
	LNode *q = p->next;
	e = q->data;
	p->next = q->next;
	free(q);
	return true;
} 

//删除指定结点p
bool DeleteNode(LNode *p){
	if(p==NULL) return false;
	LNode *q = p->next;
	p->data = q->data;
	p->next = q->next;
	free(q);
	return true;
} 


int main(){
	LinkList L;
	InitList(L);
	return 0;
}
