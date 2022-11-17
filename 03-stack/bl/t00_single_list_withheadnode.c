#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 带头结点的单链表c语言代码展示

typedef int ElemType;

typedef struct node {
  ElemType data;
  struct node* next;
} LNode, *LinkList;

LinkList init();                        // 带头结点的单链表的初始化
void tail(LinkList L, int a[], int n);  // 尾插
void head(LinkList L, int a[], int n);  // 头插
LNode* newLNode(int x);
void printList(LinkList L);
void destroyList(LinkList* pList);
void clearList(LinkList* pList);

LNode* newLNode(int x) {
  LNode* s = (LNode*)malloc(sizeof(LNode));
  if (!s) return NULL;
  s->data = x;
  s->next = NULL;
  return s;
}

void head(LinkList L, int a[], int n) {
  LNode* p;
  for (int i = 0; i < n; i++) {
    p = newLNode(a[i]);
    // 头插法
    p->next = L->next;
    L->next = p;
  }
}

void tail(LinkList L, int a[], int n) {
  LNode* r = L;
  for (int i = 0; i < n; i++) {
    LNode* p = newLNode(a[i]);
    r->next = p;
    r = p;
  }
  r->next = NULL;
}

void printList(LinkList L) {
  if (L == NULL) return;
  LNode* p = L->next;
  while (p) {
    printf("%d -> ", p->data);
    p = p->next;
  }
  printf("NULL\n");
}

void destroyList(LinkList* pList) {
  clearList(pList);
  // 删除头结点
  free(*pList);
  *pList = NULL;
}

void clearList(LinkList* pList) {
  LNode* p = (*pList)->next;
  LNode* q;
  while (p) {
    q = p;
    p = p->next;
    free(q);
  }
  (*pList)->next = NULL;
}

LinkList init() {
  LinkList L = (LinkList)malloc(sizeof(LNode));
  L->next = NULL;
  L->data = 0x3f3f3f3f;
  return L;
}
