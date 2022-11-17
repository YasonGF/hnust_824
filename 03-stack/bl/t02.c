// 判断单链表的全部 n 个字符是否中心对称

#include "03-stack\bl\t00_single_list_withheadnode.c"
// #include "t01_seq_stack.c"


bool t02(LNode *L) {
  // 初始化栈
  int stack[50];
  int top = -1;
  // 统计链表长度
  LNode *p = L->next;
  int n = 0;
  while (p) {
    n++;
    p = p->next;
  }
  //   将链表中前n/2个元素入栈
  p = L->next;
  for (int i = 0; i < n / 2; ++i) {
    stack[++top] = p->data;  // 入栈
    p = p->next;
  }
  if (n % 2) p = p->next;
  //   弹栈，并依次与 后n/2个元素比较
  while (p) {
    int x = stack[top--];
    if (x == p->data)
      p = p->next;
    else
      return false;
  }
  return true;
}

int main(void) {  //
  LinkList L = init();
  int a[] = {
      1, 2, 3, 4, 3, 2, 1,
  };
  int len = sizeof a / sizeof a[0];

  // tail(L, a, len);
  head(L, a, len);
  printList(L);

  if (t02(L)) {
    printf("okok\n");
  }else {
    printf("not today\n");
  }
  destroyList(&L);
  return 0;
}
