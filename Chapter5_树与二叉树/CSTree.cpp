//孩子兄弟表示法

#include<stdio.h>
#include<stdlib.h>

typedef struct CSNode
{
    char data;
    struct CSNode *firstchild, *nextsibling;
}CSNode,*CSTree;
