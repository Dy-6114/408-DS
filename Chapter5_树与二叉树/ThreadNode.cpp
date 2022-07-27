#include<stdio.h>
#include<stdlib.h>

typedef struct ThreadNode
{
    ElemType data;
    struct ThreadNode *lchild, *rchild;
    int ltag,rtag;
}ThreadNode, *ThreadTree;
