#include "template1.cpp"        // 带头结点的单链表模板实现

#include<algorithm>
#include<iostream>
using namespace std;

int main(void) {
  LinkList L = init();
  int a[] = {
      4, 2, 3, 7, 9, 6, 5, 4, 1, 8,
  };
  int len = sizeof a / sizeof a[0];

  tail(L, a, len);
  printList(L);

  destroyList(&L);  // 释放空间
  return 0;
}