#include<stdio.h>
#include<stdlib.h>

#define MaxSize 50

typedef struct{
    int data[MaxSize];
    int top;
}SqStack;

//初始化栈
void InitStack(SqStack &S){
    S.top = -1;
}

//判断栈空
bool StackEmpty(SqStack S){
    if (S.top == -1)
        return true;
    else
        return false;
}

//进栈操作：新元素入栈
bool Push(SqStack &S, int x){
    if(S.top == MaxSize-1)
        return false;
    S.data[++S.top] = x;
    return true;
}

//出栈操作：栈顶元素出栈
bool Pop(SqStack &S, int &x){
    if(S.top == -1)
        return false;
    x = S.data[S.top--];
    return true;
}

//读栈顶元素
bool GetTop(SqStack &S, int &x){
    if(S.top == -1)
        return false;
    x = S.data[S.top];
    return true;
}

void testSqStack(){
    SqStack S;
    InitStack(S);
}


