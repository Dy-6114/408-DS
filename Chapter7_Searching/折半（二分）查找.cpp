#include <stdio.h>
#include <stdlib.h>
//有序线性表的二分查找
typedef struct
{
    ElemType *elem;
    int TableLen;
} SeqList;

int Binary_Search(SeqList L, ElemType key)
{
    int low = 0, high = L.TableLen - 1, mid;
    while (low < high)
    {
        mid = (low + high) / 2;
        if (L.elem[mid] == key)
            return mid;
        else if (L.elem[mid] > key)//依赖于是升序还是降序
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}