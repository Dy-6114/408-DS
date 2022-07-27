/*代码中与栈相关的部分由第三章实现，其中接口位置可能存在问题，而且我是个新手。
遇到的问题：1、引用.h文件不会，写了.h发现和cpp文件链接不上。
2、直接引用cpp文件，如果在同一个文件夹下没有问题，在多个文件夹是又出现找不到文件位置的问题，意思和编译时的编码有关，中文文件夹会出现乱码*/

#include <stdio.h>
#include <stdlib.h>

typedef struct ElemType{
    int value;
};

typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

void visit(BiTree T){
    printf("%d", T->data.value);
}

//先序遍历
void PreOrder(BiTree T){
    if (T!=NULL) {
        visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

void PreOrder2(BiTree T){
    SqStack S;
    InitStack(S);
    BiTree p=T;
    while (p || !StackEmpty(S))
    {
        if(p){
            visit(p);
            Push(S,p);
            p = p->lchild;
        }else{
            Pop(S,p);
            p = p->rchild;
        }
    }
    
}

//中序遍历
void InOrder(BiTree T){
    if (T!=NULL) {
        InOrder(T->lchild);
        visit(T);
        InOrder(T->rchild);
    }
}

void InOrder2(BiTree T){
    SqStack S;
    InitStack(S);
    BiTree p=T;
    while (p || !StackEmpty(S))
    {
        if(p){
            Push(S,p);
            p = p->lchild;
        }else{
            Pop(S,p);
            visit(p);
            p = p->rchild;
        }
    }

//后序遍历
void PostOrder(BiTree T){
    if (T!=NULL) {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        visit(T);
    }
}

int main(){
    //插入根结点
    BiTree root = NULL;
    root = (BiTNode *)malloc(sizeof(BiTNode));
    root->data = {1};
    root->lchild = NULL;
    root->rchild = NULL;

    //插入新结点
    BiTNode *p = (BiTNode *)malloc(sizeof(BiTNode));
    p->data = {2};
    root->lchild = p;
    p->rchild = NULL;
    p->lchild = NULL;

    InOrder(root);
}
