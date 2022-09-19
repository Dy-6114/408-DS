#include <stdio.h>
#include <stdlib.h>

void Swap(ElemType a,ElemType b);//输出堆顶元素（和堆底元素交换）

void BuildMaxHeap(ElemType A[],int len){
    for(int i = len/2;i>0;i--)
        HeadAdjust(A,i,len);
}

void HeadAdjust(ElemType A[],int k,int len){
    A[0] = A[k];
    for (int i = 2*k; i <=len; i*=2)
    {
        if(i<len&&A[i]<A[i+1])
            i++;
        if(A[0]>=A[i]) break;
        else{
            A[k] = A[i];
            k = i;
        }
    }
    A[k] = A[0];
}

void HeapSort(ElemType A[],int len){
    BuildMaxHeap(A,len);
    for (int  i = len; i > 1; i--)
    {
        Swap(A[i],A[1]);
        HeadAdjust(A,1,i-1);
    }
    
}
