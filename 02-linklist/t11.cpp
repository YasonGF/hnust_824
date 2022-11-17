#include <algorithm>
#include <iostream>

#include "template1.cpp"  // 带头结点的单链表模板实现
using namespace std;

// 将一个单链表{a1,b1,a2,b2……an,bn}
// 拆分成{ a1,a2……an }和{ bn,bn-1,……b1 }

void t11() {
  
}

int main(void) {

  LinkList L = init();
  int a[] = {
      // 4, 2, 3, 7, 9, 6, 5, 4, 1, 8,
      1, 3, 5, 7, 9, 2, 4, 6, 8, 10, 18,
  };
  int len = sizeof a / sizeof a[0];

  tail(L, a, len);
  printList(L);
  t11();

  destroyList(&L);  // 释放空间
  return 0;
}