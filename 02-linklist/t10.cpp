#include <algorithm>
#include <iostream>

#include "template1.cpp"  // 带头结点的单链表模板实现
using namespace std;

// 将一个带头节点的单链表 A 分解成两个带头节点的单链表 A 和 B，
// 使 A 中含奇数位置元素，B 中含偶数位置元素，且相对位置不变
LinkList t10(LinkList L) {
  LNode *p = L;                     // a的头结点
  LNode *q = newLNode(0x003f3f00);  // b的头结点
  LNode *qr = q;
  while (p->next) {
    if (p->next->data % 2) {  // 奇数
      p = p->next;
    } else {
      qr->next = p->next;
      qr = p->next;
      p->next = qr->next;
    }
  }
  return q;
}

int main(void) {
  LinkList L = init();
  int a[] = {
      // 4, 2, 3, 7, 9, 6, 5, 4, 1, 8,
      // 1, 3, 5, 7, 9,
      2, 4, 6, 8, 10, 18,
  };
  int len = sizeof a / sizeof a[0];

  tail(L, a, len);
  printList(L);

  LinkList B = t10(L);
  printList(L);
  printList(B);

  destroyList(&L);  // 释放空间
  return 0;
}