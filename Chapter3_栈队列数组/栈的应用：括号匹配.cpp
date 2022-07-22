#include<stdio.h>
#include<stdlib.h>
#include"SqStack.cpp"


bool bracketCheck(char str[], int length){
    SqStack S;
    InitStack(S);
    // char x;
    for (int i = 0; i < length; i++){
        if(str[i] == '(' || str[i] == '[' || str[i] == '{'){
            Push(S,str[i]);
            // GetTop(S, x);
            // printf("%c,",x);

        }else{
            if (StackEmpty(S)) return false;
            char topElem;
            Pop(S,topElem);
            if(str[i] == ')' && topElem != '(') return false;
            if(str[i] == ']' && topElem != '[') return false;
            if(str[i] == '}' && topElem != '{') return false;
        }
    }
    return StackEmpty(S);    
}


int main(){
    char a[5] = {'(',')','(',')','['};
    // for (int i = 0; i < 5; i++)
    // {
    //     printf("%c ",a[i]);
    // }
    // printf("\n");
    int b = bracketCheck(a,5);
    printf("\n%d", b);
    return 0;
}