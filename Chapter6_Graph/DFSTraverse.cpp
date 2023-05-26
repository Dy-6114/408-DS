/* 深度优先搜索
性能分析：DFS算法需要借助需要借助递归工作栈，空间复杂度为O(|V|)。
采用邻接表法时：访问顶点的时间为O(|V|)；查找所有顶点的邻接点所需的时间为O(|E|)；算法的总时间复杂度为O(|V|+|E|)。
采用邻接矩阵法时：查找每个顶点的邻接点所需的时间为O(|V|)，故算法总时间复杂度为O(|V|方)。
*/

#include <stdio.h>
#include <stdlib.h>
#define MaxVertexNum 100

bool visited[MaxVertexNum];

typedef ALGraph Graph;

int FirstNeighbor(Graph G, int u);
int NextNeighbor(Graph G, int v, int w);
void visit(int v);

void DFSTraverse(Graph G)
{
    for (int v = 0; v < G.vexnum; ++v)
        visited[v] = false;
    for (int v = 0; v < G.vexnum; ++v)
        if (!visited[v])
            DFS(G, v);
}

void DFS(Graph G, int v)
{
    visit(v);
    visited[v] = true;
    for (int w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w))
        if (!visited[w])
        {
            DFS(G, w);
        }
}