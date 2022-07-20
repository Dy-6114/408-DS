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













void main(){
    SqQueue Q;
    InitQueue(Q);
    //后续操作。。。。
}
