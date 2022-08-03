#include <stdio.h>
#include <stdlib.h>
//一般线性表的顺序查找
typedef struct
{
    ElemType *elem;
    int TableLen;
} SSTable;

int Search_Seq(SSTable ST, ElemType key)
{
    ST.elem[0] = key;
    for (int i = ST.TableLen; ST.elem[i] != key; --i)
    {
        return i;
    }
}