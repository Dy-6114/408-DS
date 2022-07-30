#include <stdio.h>
#include <stdlib.h>
typedef struct ElemType
{
    int value;
};

typedef struct ThreadNode
{
    ElemType data;
    struct ThreadNode *lchild, *rchild;
    int ltag, rtag;
} ThreadNode, *ThreadTree;

void visit(ThreadNode *T)
{
    printf("%d", T->data.value);
}

//通过中序遍历对二叉树线索化的递归算法
void InThread(ThreadTree &p, ThreadTree &pre)
{
    if (p != NULL)
    {
        InThread(p->lchild, pre);
        if (p->lchild == NULL)
        {
            p->lchild = pre;
            p->ltag = 1;
        }
        if (pre != NULL && pre->rchild == NULL)
        {
            pre->rchild = p;
            pre->rtag = 1;
        }
        pre = p;
        InThread(p->rchild, pre);
    }
}

void CreateInThread(ThreadTree T)
{
    ThreadTree pre = NULL;
    if (T != NULL)
    {
        InThread(T, pre);
        pre->rchild = NULL;
        pre->rtag = 1;
    }
}

//求中序线索二叉树中中序序列下的第一个结点
ThreadNode *Firstnode(ThreadNode *p)
{
    while (p->ltag == 0)
        p = p->lchild;
    return p;
}

//求中序线索二叉树中结点p在中序序列下的后继
ThreadNode *Nextnode(ThreadNode *p)
{
    if (p->rtag == 0)
        return Firstnode(p->rchild);
    else
        return p->rchild;
}

//求中序线索二叉树中序序列下的最后一个结点
ThreadNode *Lastnode(ThreadNode *p)
{
    while (p->rtag == 0)
        p = p->rchild;
    return p;
}

//求中序线索二叉树中结点p在中序序列下的前驱
ThreadNode *Prenode(ThreadNode *p)
{
    if (p->ltag == 0)
        return Lastnode(p->lchild);
    else
        return p->lchild;
}

//不含头结点的中序线索二叉树的中序遍历的算法
void Inorder(ThreadNode *T)
{
    for (ThreadNode *p = Firstnode(T); p != NULL; p = Nextnode(p))
    {
        visit(p);
    }
}