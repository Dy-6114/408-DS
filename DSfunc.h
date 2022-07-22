#ifdef DSFUNC_H
#define DSFUNC_H

typedef struct SqStack{
    int data[MaxSize];
    int top;
}SqStack;

void InitStack(SqStack &S);
bool StackEmpty(SqStack S);
bool Push(SqStack &S, int x);
bool Pop(SqStack &S, int &x);
bool GetTop(SqStack &S, int &x);

#endif