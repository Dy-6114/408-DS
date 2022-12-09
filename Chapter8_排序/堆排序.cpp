#include <iostream>
using namespace std;

typedef int ElemType;

void HeadAdjust(ElemType A[],int k,int len){ //堆调整
    A[0] = A[k]; //A[0]作为哨兵
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

void BuildMaxHeap(ElemType A[],int len){
    for(int i = len/2;i>0;i--)
        HeadAdjust(A,i,len);
}

void HeapSort(ElemType A[],int len){
    BuildMaxHeap(A,len);
    for (int  i = len; i > 1; i--)
    {
        swap(A[i],A[1]);
        HeadAdjust(A,1,i-1);
    }
    
}

int main(){
    ElemType A[] = {-10000,1,9,7,11,5,6,8};
    HeapSort(A,7);
    cout<<endl;
    for (int i = 0; i < 8; i++)
    {
        cout<<A[i]<<" ";
    }
    return 0;
}