#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 无头结点的单链表c语言代码展示
typedef int ElemType;

typedef struct node {
  ElemType data;
  struct node* next;
} LNode, *LinkList;

bool init(LinkList* pList);  // 不带头结点的单链表的初始化
void tail(LinkList* pList, int a[], int n);  // 尾插
void head(LinkList* pList, int a[], int n);  // 头插
LNode* newLNode(int x);
void printList(LinkList L);
void destroyList(LinkList* pList);
void clearList(LinkList* pList);

int main(void) {
  LinkList L;
  init(&L);
  int a[] = {
      3, 1, 7, 6, 9, 4, 2,
      // 1, 2, 3, 4, 5,
  };
  int len = sizeof a / sizeof a[0];

  // tail(&L, a, len);

  head(&L, a, len);
  printList(L);

  destroyList(&L);  // 释放空间
  printList(L);
  return 0;
}

void head(LinkList* pList, int a[], int n) {  // 不带头结点的头插法
  int i;
  LNode* p;
  *pList = newLNode(a[0]);
  for (i = 1; i < n; i++) {
    p = newLNode(a[i]);
    p->next = (*pList);
    (*pList) = p;
  }
}

void tail(LinkList* pList, int a[], int n) {
  int i = 0;
  if (*pList == NULL) {  // L == NULL
    *pList = newLNode(a[i]);
  }
  LNode* r = *pList;
  if (r == NULL) return;

  for (i = 1; i < n; i++) {
    LNode* p = newLNode(a[i]);
    r->next = p;
    r = p;
  }
  r->next = NULL;
}

LNode* newLNode(int x) {
  LNode* s = (LNode*)malloc(sizeof(LNode));
  if (!s) return NULL;
  s->data = x;
  s->next = NULL;
  return s;
}

void printList(LinkList L) {
  while (L) {
    printf("%d -> ", L->data);
    L = L->next;
  }
  printf("NULL\n");
}

void destroyList(LinkList* pList) {
  clearList(pList);
  // // 删除头结点
  // free(*pList);
  // *pList = NULL;
}

void clearList(LinkList* pList) {
  LNode* p = (*pList);
  LNode* q;
  while (p) {
    q = p;
    p = p->next;
    free(q);
  }
  (*pList) = NULL;
}

bool init(LinkList* pList) {
  *pList = NULL;
  return true;
}
