//邻接表法

#include<stdio.h>
#include<stdlib.h>
#define MaxVertexNum 100

typedef char VertexType;

typedef struct ArcNode{
    int adjvex; //指向顶点序号
    struct ArcNode *next;
    //InfoType info;
}ArcNode;

typedef struct VNode{
    VertexType data; //顶点名称
    ArcNode *first; //第一个相邻边
}VNode, AdjList[MaxVertexNum];

typedef struct{
    AdjList vertices;
    int vexnum, arcnum;
}ALGraph;