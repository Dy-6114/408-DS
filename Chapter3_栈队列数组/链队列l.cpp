#include<stdlib.h>
#include<stdio.h>

typedef struct LinkNode{
	int data;//数据域 
	struct LinkNode *next;//指针域 
}LinkNode;

typedef struct{
	LinkNode *front,*rear;
}LinkQueue;

//void InitQueue(LinkQueue &Q) { //不带头结点 
//	Q.front = NULL;
//	Q.rear = NULL;
//}

void InitQueue(LinkQueue &Q) { //带头结点 
	Q.front = Q.rear = (LinkNode *)malloc(sizeof(LinkNode));
	Q.front->next = NULL;
}

//判空：不带头结点 
// bool IsEmpty(LinkQueue Q) {
// 	if(Q.front == Q.rear) 
// 		return true;
// 	else 
// 		return false;
// }

//判空：带头结点
bool IsEmpty(LinkQueue Q) {
	if(Q.front==NULL) 
		return true;
	else 
		return false;//不带头结点 
}

//入队
void EnQueue(LinkQueue &Q, int e){//带头结点 
	LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
	s->data=e;
	s->next=NULL;
	Q.rear->next=s;
	Q.rear=s;
}

// void EnQueue(LinkQueue &Q, int e){//不带头结点
// 	LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
// 	s->data=e;
// 	s->next=NULL;
// 	if(Q.front == NULL){
// 		Q.front = s;
// 		Q.rear = s;
// 	}else{
// 		Q.rear->next=s;
// 	Q.rear=s;
// 	}	
// }

//出队
bool DeQueue(LinkQueue &Q, int &x){//带头结点
	if(Q.front == Q.rear){
		return false;
	}
	LinkNode *p = Q.front->next;
	x = p->data;
	Q.front->next = p->next;
	if(Q.rear == p){
		Q.rear = Q.front;
	}
	free(p);
	return true;
}

// bool DeQueue(LinkQueue &Q, int &x){//不带头结点
// 	if(Q.front == NULL){
// 		return false;
// 	}
// 	LinkNode *p = Q.front;
// 	x = p->data;
// 	Q.front = p->next;
// 	if(Q.rear == p){
// 		Q.rear = NULL;
// 		Q.front = NULL;
// 	}
// 	free(p);
// 	return true;
// }

void main(){
	LinkQueue Q;
	InitQueue(Q);
}
