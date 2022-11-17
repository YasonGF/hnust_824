#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 试编写在不带头结点的单链表 L 中删除最小值点的高效算法（已知最小值唯一
typedef int ElemType;

typedef struct node {
  ElemType data;
  struct node* next;
} LNode, *LinkList;

bool init(LinkList* pList);
void tail(LinkList* pList, int a[], int n);  // 尾插
void head(LinkList* pList, int a[], int n);  // 头插
LNode* newLNode(int x);
void printList(LinkList L);
void destroyList(LinkList* pList);
void clearList(LinkList* pList);

// 试编写在不带头结点的单链表 L 中删除最小值点的高效算法（已知最小值唯一
void t08(LinkList* pList) {
  LNode *p = *pList, *minp = p;
  LNode* pre = NULL;
  while (p->next) {
    if (p->next->data < minp->data) {
      pre = p;
      minp = p->next;
    }
    p = p->next;
  }

  if (pre == NULL) {  // 第一个位置就是最小的
    pre = *pList;
    (*pList) = (*pList)->next;
    free(pre);
    return;
  }

  pre->next = minp->next;
  free(minp);
}

void t08_m2(LinkList* pList) {
  LNode* minp = *pList;
  LNode* p = (*pList)->next;
  while (p) {
    if (p->data < minp->data) {
      minp = p;
    }
    p = p->next;
  }

  if (*pList == minp) {
    *pList = (*pList)->next;
    free(minp);
    return;
  }

  p = *pList;
  while (p->next != minp) p = p->next;

  p->next = minp->next;
  free(minp);
}

int main(void) {
  LinkList L;
  init(&L);
  int a[] = {
      3, 1, 7, 6, 9, 4, 2,
      // 1, 2, 3, 4, 5,
      // 5, 4, 3, 2, 1,
      // 1, -1, 3, 2, 5,
  };
  int len = sizeof a / sizeof a[0];

  tail(&L, a, len);

  // head(&L, a, len);
  printList(L);

  // t08(&L);
  t08_m2(&L);

  printList(L);

  destroyList(&L);  // 释放空间
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
