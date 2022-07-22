#include<stdio.h>
#include<stdlib.h>
#include"408-DS/DSfunc.h"


bool bracketCheck(char str[], int length){
    SqStack S;
    InitStack(S);
    for (int i = 0; i < length; i++){
        if(str[i] == '(' || str[i] == '[' || str[i] == '{'){
            Push(S,str[i]);
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