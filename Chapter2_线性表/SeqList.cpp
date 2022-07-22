#include<stdlib.h>
#include<stdio.h>
#define InitSize 10

typedef struct{
	int *data;
	int MaxSize;
	int length;
}SeqList;

void InitList(SeqList &L){
	L.data = (int *)malloc(InitSize * sizeof(int));
	L.length = 0;
	L.MaxSize = InitSize;
} 

bool ListInsert(SeqList &L,int i, int e){
	if(i < 1 || i > L.length + 1) return false;
	if(L.length >= L.MaxSize) return false;
	for(int j=L.length;j>=i;j--){
		L.data[j] = L.data[j-1];
	}
	L.data[i-1] = e;
	L.length++;
	return true;
}

bool ListDelete(SeqList &L,int i, int &e){
	if(i<1||i>L.length+1) return false;
	e = L.data[i-1];
	for(int j=i; j < L.length; j++){
		L.data[j-1] = L.data[j];
	}
	L.length--;
	return true;
}

int LocateElem(SeqList L,int e){
	int i;
	for(i = 0; i < L.length; i++) {
		if(L.data[i] == e) return i+1;
	}
	return 0;
}  

int main(){
	SeqList L;
	InitList(L);
	L.data[0] = 100;
	printf("%d\n",L.data[0]);

	return 0;
}
