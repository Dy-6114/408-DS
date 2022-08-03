//拓扑排序
/*
性能分析：采用邻接表存储时间复杂度为O(|V|+|E|)；采用邻接矩阵存储的时间复杂度为O(|V|方)。
*/

#include <stdio.h>
#include <stdlib.h>

typedef ALGraph Graph;

bool ToplogicalSort(Graph G){
    InitStack(S); //存储入度为0的顶点
    for (int i = 0; i < G.vexnum; i++)
    {
        if (indegree[i] == 0)
        {
            Push(S,i);
        }
    }
    int count = 0; //记录已经输出的顶点数
    while (!StackEmpty(S))
    {
        Pop(S,i);
        print[count++] = i;
        for (p  = G.vertices[i].firstarc; p; p=p->nextarc)
        {
            v = p->adjvex;
            if(!(--indegree[v])) //将所有i指向的顶点入度-1
                Push(S,v); //将入度0的顶点入栈
        }
        
    }
    if (count<G.vexnum) 
        return false;
    else
        return true;   
}