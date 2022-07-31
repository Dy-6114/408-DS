//树的顺序存储：一定要把二叉树的节点编号与完全二叉树对应起来
#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100

struct TreeNode
{
    int value;
    bool isEmpty;
};

TreeNode t[MaxSize]; //t[0]不存结点

int main()
{
    for (int i = 0; i < MaxSize; i++)
    {
        t[i].isEmpty = true;
    }
}
