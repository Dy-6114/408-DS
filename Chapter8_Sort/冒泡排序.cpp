#include <stdio.h>
#include <stdlib.h>

void swap(ElemType a, ElemType b); //交换

void BubbleSort(ElemType A[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool flag = false;
        for (int j = n - 1; j > i; j--) //从后往前
        {
            if (A[j - 1] > A[j])
            {
                swap(A[j - 1], A[j]);
                flag = true;
            }
        }
        if (flag == false) //本趟遍历没有发生交换，说明表已经有序
            return;
    }
}