#include <stdio.h>
#include <stdlib.h>
#define MaxSize 50

typedef struct Node
{
	int data;
	int next;
} SLinkList[MaxSize];

void testSLinkList()
{
	SLinkList a;
	printf("size=%d\n", sizeof(a));
}
