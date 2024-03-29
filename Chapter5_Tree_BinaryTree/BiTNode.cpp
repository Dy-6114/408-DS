// 二叉树

/*代码中与栈相关的部分由第三章实现，其中接口位置可能存在问题，而且我是个新手。
遇到的问题：1、引用.h文件不会，写了.h发现和cpp文件链接不上。
2、直接引用cpp文件，如果在同一个文件夹下没有问题，在多个文件夹是又出现找不到文件位置的问题，意思和编译时的编码有关，中文文件夹会出现乱码*/

#include <stdio.h>
#include <stdlib.h>
#include "D:\考研\408\408-DS\Chapter3_栈队列数组\SqStack.cpp" //有错误
#include "D:\考研\408\408-DS\Chapter3_栈队列数组\SqQueue.cpp" //有错误

typedef int ElemType;

typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild, *rchild;
    int flag; // 非递归后序遍历时，记录结点的访问次数
} BiTNode, *BiTree;

void visit(BiTree T)
{
    printf("%d", T->data);
}

// 递归先序遍历
void PreOrder(BiTree T)
{
    if (T != NULL)
    {
        visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

// 非递归先序遍历
void PreOrder2(BiTree T)
{
    SqStack S;
    InitStack(S);
    BiTree p = T;
    while (p || !StackEmpty(S))
    {
        if (p)
        {
            visit(p);
            Push(S, p);
            p = p->lchild;
        }
        else
        {
            Pop(S, p);
            p = p->rchild;
        }
    }
}

// 递归中序遍历
void InOrder(BiTree T)
{
    if (T != NULL)
    {
        InOrder(T->lchild);
        visit(T);
        InOrder(T->rchild);
    }
}

// 非递归中序遍历
void InOrder2(BiTree T)
{
    SqStack S;
    InitStack(S);
    BiTree p = T;
    while (p || !StackEmpty(S))
    {
        if (p)
        {
            Push(S, p);
            p = p->lchild;
        }
        else
        {
            Pop(S, p);
            visit(p);
            p = p->rchild;
        }
    }
}

// 递归后序遍历
void PostOrder(BiTree T)
{
    if (T != NULL)
    {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        visit(T);
    }
}

// 非递归后序遍历
void PostOrder2(BiTree T)
{
    /*遍历过程中，会发现树根及子树的树根会被访问两次，为了避免这个问题，
    第一次遇到的时候不访问，而第二次遇到的时候再访问，因此引入了一个访问标志。*/
    SqStack S;
    InitStack(S);
    BiTNode *p = T;
    while (p || !StackEmpty(S))
    {
        if (p)
        {
            Push(S, p);    // 结点入栈
            p = p->lchild; // 向左子树走
        }
        else
        { // p为空，则出栈
            Pop(S, p);
            if (p->rchild == NULL || p->flag == 1) //如果结点右子树为空，或者该结点是返回时的第二次被访问即第二次入栈的情况，则访问
            {
                visit(p);
                p == NULL; //进入下一次循环
            }
            else//右子树非空，则该节点重新入栈，设标志位为1，之后访问结点的右子树
            {
                Push(S, p);
                p->flag = 1;
                p = p->rchild;
            }
        }
    }
}

// 层次遍历
void LevelOrder(BiTree T)
{
    SqQueue Q;
    InitQueue(Q);
    EnQueue(Q, T);
    BiTree p;
    while (!QueueEmpty(Q))
    {
        DeQueue(Q, p);
        visit(p);
        if (p->lchild != NULL)
            EnQueue(Q, p->lchild);
        if (p->rchild != NULL)
            EnQueue(Q, p->rchild);
    }
}

// int main()
// {
//     //插入根结点
//     BiTree root = NULL;
//     root = (BiTNode *)malloc(sizeof(BiTNode));
//     root->data = {1};
//     root->lchild = NULL;
//     root->rchild = NULL;

//     //插入新结点
//     BiTNode *p = (BiTNode *)malloc(sizeof(BiTNode));
//     p->data = {2};
//     root->lchild = p;
//     p->rchild = NULL;
//     p->lchild = NULL;

//     InOrder(root);
// }
