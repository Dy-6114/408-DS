//邻接表法

#include<stdio.h>
#include<stdlib.h>
#define MaxVertexNum 100

typedef char VertexType;

typedef struct ArcNode{
    int adjvex;
    struct ArcNode *next;
    //InfoType info;
}ArcNode;

typedef struct VNode{
    VertexType data;
    ArcNode *first;
}VNode, AdjList[MaxVertexNum];

typedef struct{
    AdjList vertices;
    int vexnum, arcnum;
}ALGraph;