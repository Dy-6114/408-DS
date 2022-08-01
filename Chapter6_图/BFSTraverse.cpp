/* 广度优先搜索
性能分析：BFS算法需要借助一个辅助队列，n个顶点均需入队一次，最坏空间复杂度为O(|V|)
采用邻接表法时：每个顶点均需搜索一次，故时间复杂度为O(|V|)；在搜索任一顶点的邻接点时，每条边至少访问一次，故时间复杂度为O(|E|)；算法的总时间复杂度为O(|V|+|E|)。
采用邻接矩阵法时：查找每个顶点的邻接点所需的时间为O(|V|)，故算法总时间复杂度为O(|V|方)。
*/

#include <stdio.h>
#include <stdlib.h>
#define MaxVertexNum 100

bool visited[MaxVertexNum];
int d[MaxVertexNum];

typedef ALGraph Graph;

int FirstNeighbor(Graph G, int u);
int NextNeighbor(Graph G, int v, int w);
void visit(int v);

void BFSTraverse(Graph G)
{
    for (int i = 0; i < G.vexnum; i++)
    {
        visited[i] = false;
    }
    InitQueue(Q);
    for (int i = 0; i < G.vexnum; i++)
    {
        if (!visited[i])
        {
            BFS(G, i);
        }
    }
}

void BFS(Graph G, int v)
{
    visit(v);
    visited[v] = true;
    EnQueue(Q, v);
    while (!QueueEmpty(Q))   
    {
        DeQueue(v);
        for (int w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w))
        {
            if (!visited[w])
            {
                visit(w);
                visited[w] = true;
                EnQueue(w);
            }
        }
    }
}

//BFS算法求解单源最短路径问题
void BFS_MIN_Distance(Graph G, int u){
    //d[i]表示从u到i结点的最短路径
    for (int i = 0; i < G.vexnum; ++i)
    {
        d[i] = -1;
    }
    visited[u] = true;
    d[u] = 0;
    EnQueue(Q,u);
    while (!QueueEmpty(Q))
    {
        DeQueue(Q,u);
        for (int w = FirstNeighbor(G, u); w >= 0; w = NextNeighbor(G, u, w))
        {
            if (!visited[w])
            {
                visited[w] = true;
                d[w] = d[u] + 1;
                EnQueue(Q,w);
            }
        }
    }
    

    
}