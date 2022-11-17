// 无头结点的链栈
#include<stdio.h>
#include<string.h>

typedef int ElemType; 

typedef struct LinkNode{
  ElemType data;
  struct LinkNode *next;
} *LiStack;

