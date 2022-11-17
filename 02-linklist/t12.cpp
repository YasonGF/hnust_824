#include <algorithm>
#include <iostream>

#include "template1.cpp"  // 带头结点的单链表模板实现
using namespace std;

// 删除递增链表中重复的元素
void t12(LinkList L) {
  LNode *p = L->next, *pre = L;
  while (p->next) {
    if (p->next->data == p->data) {
      LNode *q = p->next;
      p = q->next;
      pre->next = q;
      free(q);
    } else {
      pre = p;
      p = p->next;
    }
  }
}

int main(void) {
  LinkList L = init();
  int a[] = {
      3, 3, 5, 7, 11, 11, 19, 19, 19,
      // 4, 2, 3, 7, 9, 6, 5, 4, 1, 8,
      // 1, 3, 5, 7, 9,
      // 2, 4, 6, 8, 10, 18,
  };
  int len = sizeof a / sizeof a[0];

  tail(L, a, len);
  printList(L);
  t12(L);
  printList(L);

  destroyList(&L);  // 释放空间
  return 0;
}