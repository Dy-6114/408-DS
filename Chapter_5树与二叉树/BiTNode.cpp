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
}
