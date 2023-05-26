//双亲表示法

#include<stdio.h>
#include<stdlib.h>
#define MAX_TREE_SIZE 100

typedef struct{
    char data;
    int parent;
}PTNode;

typedef struct{
    PTNode nodes[MAX_TREE_SIZE];
    int n;
}PTree;