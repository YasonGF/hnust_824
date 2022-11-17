//  给定一个单链表，按递增排序输出的单链表中各结点的数据元素，
//  并释放节点所占空间
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int ElemType;

typedef struct LNode {
  struct LNode *next;
  ElemType data;
} LNode, *LinkList;

bool tail(LinkList *pList, int a[], int n);
LNode *newLNode(ElemType x);

void printList(LinkList L);

void insertSort(LinkList *pList);


int main(void) {
  int a[] = {
      2, 3, 11, 17, 7, 5,
  };
  int len = sizeof a / sizeof a[0];
  LinkList L = NULL;
  tail(&L, a, len);  // tail insert
  printList(L);
  // 单链表的插入排序
  // insertSort(&L);
  return 0;
}

bool tail(LinkList *pList, int a[], int n) {  // tail insert
  if (*pList == NULL) *pList = newLNode(a[0]);
  LNode *r = *pList;
  if (r == NULL) return false;

  for (int i = 1; i < n; i++) {
    LNode *p = newLNode(a[i]);
    r->next = p;
    r = p;
  }
  r->next = NULL;
  return true;
}

LNode *newLNode(ElemType x) {
  LNode *p = (LNode *)malloc(sizeof(LNode));
  if (!p) return NULL;
  p->data = x;
  p->next = NULL;
  return p;
}

void printList(LinkList L) {
  while (L) {
    printf("%d -> ", L->data);
    L = L->next;
  }
  printf("NULL\n");
}

void insertSort(LinkList *pList) {  // 无头结点的单链表的直接插入排序
  LNode *p;
}