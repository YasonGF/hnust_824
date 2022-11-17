// 无头结点的链栈
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int ElemType;

typedef struct LinkNode {
  ElemType data;
  struct LinkNode *next;
} LinkNode, *LiStack;

void init(LinkNode *&p);
bool push(LiStack &s, ElemType x);
bool pop(LiStack &s, ElemType &x);
bool top(LiStack s, ElemType &x);
bool empty(LiStack s);

void init(LinkNode *&p) { p = NULL; }

bool push(LiStack &L, int x) {
  //   创建一个新结点
  LinkNode *p = (LinkNode *)malloc(sizeof(LinkNode));
  if (p == NULL) return false;
  p->data = x;
  p->next = NULL;

  // 头插
  p->next = L;
  L = p;
  return true;
}

bool pop(LiStack &s, ElemType &x) {
  if (s == NULL) return false;
  x = s->data;
  LinkNode *q = s;
  s = s->next;
  free(q);
  q = NULL;
  return true;
}

bool top(LiStack &s, ElemType &x) {
  if (s == NULL) return false;
  x = s->data;
  return true;
}
bool empty(LiStack s) { return s == NULL; }