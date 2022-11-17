#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 设计一个递归算法，删除不带头结点的单链表L中所有值为x的结点
typedef int ElemType;

typedef struct node {
  ElemType data;
  struct node* next;
} LNode, *LinkList;

void destroyLinkList(LinkList* pList);
void printLinkList(LinkList L);
LinkList createLinkListByTailInsert(int a[], int n);  // 尾插法建立单链表

void del_x(LNode** p, int x) {  // 不带引用写法
  LNode* q;
  if (*p == NULL) return;

  if ((*p)->data == x) {
    q = *p;
    *p = (*p)->next;
    free(q);
    del_x(p, x);
  } else {
    // error:   p=p->next;  del_x(p, x);
    del_x(&(*p)->next, x);
  }
}

int main(void) {
  int a[] = {3, 1, 2, 3, 4};
  int len = sizeof a / sizeof a[0];
  LinkList L = createLinkListByTailInsert(a, len);

  printLinkList(L);

  // 设计一个递归算法，删除不带头结点的单链表L中所有值为x的结点
  int x = 3;
  del_x(&L, x);
  printLinkList(L);

  destroyLinkList(&L);
  printLinkList(L);

  return 0;
}

LinkList createLinkListByTailInsert(int a[], int n) {
  LinkList L = (LinkList)malloc(sizeof(LNode));
  L->data = a[0];
  L->next = NULL;
  LNode* r = L;
  LNode* p;

  for (int i = 1; i < n; i++) {
    p = (LNode*)malloc(sizeof(LNode));
    p->data = a[i];
    r->next = p;
    r = p;
  }
  r->next = NULL;
  return L;
}

void printLinkList(LinkList L) {
  while (L) {
    printf("%d -> ", L->data);
    L = L->next;
  }

  printf("NULL\n");
}

void destroyLinkList(LinkList* pList) {
  LNode* p = *pList;
  while (p) {
    *pList = p->next;
    free(p);
    p = *pList;
  }
  free(p);
}