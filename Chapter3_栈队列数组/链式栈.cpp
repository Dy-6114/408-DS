#include<stdio.h>
#include<stdlib.h>
#define MaxSize 50

typedef struct Linknode{
	int data;               //数据域 
	struct Linknode *next;  //指针域 
}Linknode, *LiStack;

//初始化
bool InitLiStack(LiStack &S){
    S = NULL;
	return true;
}

//判空
bool StackEmpty(LiStack S){
    if (S == NULL)
        return true;
    else
        return false;
}

//进栈操作：新元素入栈
bool Push(LiStack &S, int e){
	Linknode *p = (Linknode *)malloc(sizeof(Linknode));
    if(p==NULL) return false;
	p->data = e;
	p->next = S;
	S = p;
	return true;
}

//出栈操作：栈顶元素出栈
bool Pop(LiStack &S,int &x){
	if(StackEmpty(S))
		return false;
	Linknode *p = S;
	x=p->data;
	S=S->next;
	free(p);//释放p结点 
	return true;
}

//获得栈顶元素
int GetTop(LiStack &S){
	if(S) 
        return S->data;
    else  
        return 0;	
}

/*输出链栈*/
void PrintLiStack(LiStack &S){
	Linknode *p=S;
	int js=0;
	while(p) {
        printf("%d ",p->data);
		if(!(js%5)){
			printf("\n");
		}
		js++;
		p=p->next;
	}
	printf("\n");
}

int main(){
	LiStack S;
	InitLiStack(S);
	if(StackEmpty)
        printf("空链栈\n");
	else 
        printf("非空链栈\n");
	
	for(int i=1;i<=100;i++)
		Push(S,i);
	
	PrintLiStack(S);
	printf("当前出栈的元素为:");
	int x;
	Pop(S,x);
	printf("%d\n",x);
	
	printf("出栈之后，当前栈顶元素为:");
	x=GetTop(S);
	printf("%d\n",x);

	return 0;
}