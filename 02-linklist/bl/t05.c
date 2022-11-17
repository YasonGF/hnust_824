#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 单链表的就地逆置
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

// 单链表的就地逆置
// 带头结点的原地头插
void reverse_headInsert(LinkList L) {
  LNode *p = L->next, *q;
  L->next = NULL;  // 非常重要
  while (p) {
    q = p->next;
    p->next = L->next;
    L->next = p;
    p = q;
  }
}

//
void reverseList(LinkList L) {
  LNode *p = L->next, *q = p->next;
  LNode* pre;
  p->next = NULL;
  while (q) {
    pre = p;
    p = q;
    q = q->next;
    p->next = pre;
  }
  L->next = p;
}

int main(void) {
  LinkList L = init();
  int a[] = {
      2, 3, 7, 5, 11,
  };
  int len = sizeof a / sizeof a[0];

  tail(L, a, len);
  printList(L);

  // reverse_headInsert(L);
  reverseList(L);
  printList(L);

  destroyList(&L);  // 释放空间
  return 0;
}

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
