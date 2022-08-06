#include <stdio.h>
#include <stdlib.h>

void swap(ElemType a,ElemType b);//交换记录信息，相比于直接插入而言移动次数更低。

void SelectSort(ElemType A[],int n){
    int min;
    for (int i = 0; i < n-1; i++)
    {
        min = i;
        for(int j = i+ 1;j<n;j++){
            if(A[j]<A[min])
                min =j; //每趟记录最小值的下标
        }
        if(min != i)
            swap(A[min],A[i]); 
    }
    
}