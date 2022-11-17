#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 两个递增有序的单链表，设计算法成一个非递减有序的链表
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

void t13(LinkList* pA, LinkList* pB) {
  LNode* p = (*pA)->next;
  LNode* q = (*pB)->next;
  (*pA)->next = (*pB)->next = NULL;
  LNode* r = *pA;
  while (p && q) {
    if (p->data > q->data) {
      r->next = q;
      r = q;
      q = q->next;
    } else {
      r->next = p;
      r = p;
      p = p->next;
    }
  }
  // if (p == NULL) r->next = q;
  // if (q == NULL) r->next = p;
  r->next = p ? p : q;
}

void concat(LinkList p, LinkList q) {
  LNode *po = p->next, *qo = q->next, *newTail = p;
  while (po && qo) {
    if (po->data < qo->data) {
      newTail->next = po;
      newTail = po;
      po = po->next;
    } else {
      newTail->next = qo;
      newTail = qo;
      qo = qo->next;
    }
  }
  if (po == NULL) newTail->next = qo;
  if (qo == NULL) newTail->next = po;
}

int main(void) {
  int a[] = {
      2, 4, 5, 6, 8,
  };
  int lena = sizeof a / sizeof a[0];

  int b[] = {
      1, 3, 5, 9, 11, 19,
  };
  int lenb = sizeof b / sizeof b[0];

  LinkList L1 = init();
  LinkList L2 = init();

  tail(L1, a, lena);
  tail(L2, b, lenb);

  printList(L1);
  printList(L2);

  t13(&L1, &L2);
  // concat(L1, L2);

  printList(L1);

  destroyList(&L1);  // 释放空间
  printList(L2);

  // destroyList(&L2);  // 释放空间
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
