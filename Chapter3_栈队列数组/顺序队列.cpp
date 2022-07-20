#include<stdio.h>
#include<stdlib.h>
#define MaxSize 50

typedef struct{
    int front,rear;
    int data[MaxSize];
}SqQueue;

//初始化
void InitQueue(SqQueue &Q){
    Q.rear = Q.front = 0;
}

//判空
bool QueueEmpty(SqQueue Q){
    if(Q.front == Q.rear) return true;
    else return false;
}

//入队
bool EnQueue(SqQueue &Q, int x){
    if ((Q.rear + 1) % MaxSize == Q.front) return false;
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MaxSize;
    return true;
    
}

//出队
bool DeQueue(SqQueue &Q, int &x){
    if (Q.rear == Q.front) return false;
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    return true;
}

//获得队头元素
bool GetHead(SqQueue &Q, int &x){
    if (Q.rear == Q.front) return false;
    x = Q.data[Q.front];
    return true;
}












void main(){
    SqQueue Q;
    InitQueue(Q);
    //后续操作。。。。
}
