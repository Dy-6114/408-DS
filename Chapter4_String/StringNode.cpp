#include <stdio.h>
#include <stdlib.h>
#define MAXLEN 255

// typedef struct StringNode
// {
//     char ch;//每个节点存一个字符
//     struct StringNode *next;
// }StringNode,*String;

typedef struct StringNode
{
    char ch[4]; //每个节点存4个字符
    struct StringNode *next;
} StringNode, *String;