#include <stdio.h>
#include <stdlib.h>

//一趟快速排序实现pivot左边的关键字都比它小，右边的都比它大
int Partition(ElemType A[], int low, int high)
{
    ElemType pivot = A[low];
    while (low <high)
    {
        while (low < high&&A[high] >=pivot)
            --high;
        A[low] = A[high];
        while (low < high&&A[low] <=pivot)
            ++low;
        A[high] = A[low];    
    }
    A[low] = pivot;
    return low; 
}

void QuickSort(ElemType A[], int low, int high)
{
    if (low < high)
    {
        int pivotpos = Partition(A, low, high);
        QuickSort(A, low, pivotpos - 1);
        QuickSort(A, pivotpos + 1, high);
    }
}