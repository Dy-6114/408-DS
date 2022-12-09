#include <stdio.h>
#include <stdlib.h>

void InsertSort(ElemType A[],int n){
    int i,j;
    for (int i = 2; i <= n ; i++)
    {
        if(A[i]<A[i-1]){
            A[0] = A[i];
            for (int j = i-1; A[0] < A[j]; --j)
            {
                A[j+1] = A[j];
            }
            A[j+1] = A[0];
        }
    }
    
}

//时间复杂度为O(n方)，空间复杂度为O(1)    