#include <stdio.h>
#include <stdlib.h>

//归并则是利用一个辅助数组实现两个有序表的合并。其中这两个有序表递归到最后就是只含一个元素的有序表
ElemType *B = (ElemType *)malloc((n + 1) * sizeof(ElemType));

void Merge(ElemType A[], int low, int mid, int high)
{
    //表A的两段各自有序，合并成一个有序表
    for (int k = low; k <= high; k++)

        B[k] = A[k];
    int i, j, k;
    for (i = low, j = mid + 1, k = i; i <= mid && j <= high; k++)
        if (B[i] <= B[j])
            A[k] = B[i++];
        else
            A[k] = B[j++];
    while (i <= mid)
        A[k++] = B[i++];
    while (j <= high)
        A[k++] = B[j++];
}

void MergeSort(ElemType A[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        MergeSort(A, low, mid);
        MergeSort(A, mid + 1, high);
        Merge(A, low, mid, high);
    }
}