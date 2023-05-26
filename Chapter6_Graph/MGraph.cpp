//邻接矩阵法
#include<stdio.h>
#include<stdlib.h>
#define MaxVertexNum 100

typedef char VertexType;
typedef int EdgeType;
typedef struct{
    VertexType Vex[MaxVertexNum];
    EdgeType Edge[MaxVertexNum][MaxVertexNum];
    int vexnum, arcnum;
}MGraph;