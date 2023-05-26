//并查集

#include<stdio.h>
#include<stdlib.h>
#define SIZE 100

int UFSets[SIZE];

void Initial(int S[]){
    for (int i = 0; i < SIZE; i++)
    {
        S[i] = -1;
    }
    
}

int Find(int S[],int x){
    while (S[x]>=0)
    {
        x = S[x];
    }
    return x;
}

void Union(int S[],int Root1,int Root2) {
    S[Root2] = Root1;
}