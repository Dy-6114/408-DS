#include <stdio.h>
#include <stdlib.h>

void swap(ElemType a,ElemType b);

void SelectSort(ElemType A[],int n){
    int min;
    for (int i = 0; i < n-1; i++)
    {
        min = i;
        for(int j = i+ 1;j<n;j++){
            if(A[j]<A[min])
                min =j;
        }
        if(min != i)
            swap(A[min],A[i]);
    }
    
}