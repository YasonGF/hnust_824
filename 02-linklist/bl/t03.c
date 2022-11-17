#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 3.删除带头节点单链表中第一个值为x 的结点
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

int find_del(LinkList L, int x) {
  LNode *p = L, *q;
  while (p->next) {
    if (p->next->data == x) break;
    p = p->next;
  }

  if (p->next == NULL) return 0;
  q = p->next;
  p->next = q->next;
  free(q);
  return 1;
}

bool del_first_x(LinkList L, int x) {
  LNode *p = L, *q;
  bool f = false;
  while (p->next) {
    if (p->next->data == x) {
      q = p->next;
      p->next = q->next;
      free(q);
      f = true;
      break;
    } else {
      p = p->next;
    }
  }
  return f;
}

int main(void) {
  LinkList L = init();
  int a[] = {
      7, 1, 4, 3, 2, 1, 5, 7,
  };
  int len = sizeof a / sizeof a[0];

  tail(L, a, len);
  printList(L);

  int x = 7;
  bool f = del_first_x(L, x);
  if (f) {
    printf("当前单链表中第一个x删除成功！\n");
  } else {
    printf("%d is not found!\n", x);
  }

  find_del(L, 7);

  printList(L);

  destroyList(&L);  // 释放空间
  system("pause");
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
