#include <stdio.h>
#include <stdlib.h>

// 构建树的结构
typedef int ElemType;
typedef struct BSTNode
{
    ElemType data;
    BSTNode *lchild; //树的左孩子结点
    BSTNode *rchild; //树的右孩子结点
} BSTNode, *BiTree;

BSTNode *BST_Search(BiTree T, ElemType key)
{
    while (T != NULL && key != T->data)
        if (key < T->data)
            T = T->lchild;
        else
            T = T->rchild;
    return T;
} //非递归

// BSTNode *BST_Search(BiTree T, KeyType key)
// {
//     if (NULL == T)
//         return NULL;
//     if (key == T->data)
//         return T;      
//     if (key < T->data) 
//         return BST_Search(T->lchild, key);
//     else
//         return BST_Search(T->rchild, key);
// }//递归

int BST_Insert(BiTree &T, ElemType k){
    if(T==NULL){
        T=(BiTree)malloc(sizeof(BSTNode));
        T->data = k;
        T->lchild = T->rchild = NULL;
        return 1;
    }else if(k = T->data)
        return 0;
    else if(k<T->data)
        return BST_Insert(T->lchild,k);
    else
        return BST_Insert(T->rchild,k);  
}

void Creat_BST(BiTree &T, ElemType str[],int n){
    T=NULL;
    int i=0;
    while (i<n)
    {
        BST_Insert(T,str[i]);
        i++;
    }
}

void DeleteNode(BiTree& root, ElemType x) {
	if (root == NULL) {
		return;
	}
	if (root->data > x) {
		DeleteNode(root->lchild, x);
	}
	else if (root->data < x) {
		DeleteNode(root->rchild, x);
	}
	else//找到了要删除的结点
	{
		if (root->lchild == NULL) {//左子树为空，右子树直接顶上去
			BiTree tempNode = root;//用临时的存着的目的是一会要给他free
			root = root->rchild;
			free(tempNode);
		}
		else if (root->rchild == NULL) {//右子树为空，左子树直接顶上去
			BiTree tempNode = root;
			root = root->lchild;
			free(tempNode);
		}
		else//左右子树都不为空
		{//一般的删除策略是：左子树的最大数据 或 右子树的最小数据 代替删除的结点
			//这里采用使用左子树最大数据代替删除结点的方法
			BiTree tempNode = root->lchild;
			if (tempNode->rchild != NULL) {
				tempNode = tempNode->rchild;
			}
			root->data = tempNode->data;
			DeleteNode(root->lchild, tempNode->data);
		}
	}
}

