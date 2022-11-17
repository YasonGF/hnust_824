#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 删除带头节点单链表中所有值为x的结点

typedef int ElemType;

typedef struct node {
  ElemType data;
  struct node* next;
} LNode, *LinkList;

LinkList init();  // 带头结点的单链表的初始化
void tail(LinkList L, int a[], int n);
LNode* newLNode(int x);
void printList(LinkList L);
void destroyList(LinkList* pList);
void clearList(LinkList* pList);

void del_x(LNode* L, int x) {
  LNode* pre = L;      // pre初始指向头结点
  LNode* p = L->next;  // p指向首元结点
  LNode* q;
  while (p != NULL) {
    if (p->data == x) {
      pre->next = p->next;
      q = p;
      p = p->next;
      free(q);
    } else {
      pre = p;
      p = p->next;
    }
  }
}

void del_x2(LNode* L, int x) {
  LNode* p = L;  // p刚开始指向头结点
  LNode* q;
  while (p->next) {
    if (p->next->data == x) {
      q = p->next;
      p->next = p->next->next;
      free(q);
    } else {
      p = p->next;
    }
  }
}

int main(void) {
  LinkList L = init();
  int a[] = {
      4, 4, 3, 7, 4, 4, 3, 4, 4,
  };
  int len = sizeof a / sizeof a[0];

  tail(L, a, len);
  printList(L);

  int x = 4;
  // del_x(L, x);
  del_x2(L, x);
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
    printf("%d->", p->data);
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
