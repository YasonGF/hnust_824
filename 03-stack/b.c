#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 链栈(无头结点版本)
// 通常将链表头部作为栈顶，尾部作为栈底
typedef int ElemType;

typedef struct SNode {
  struct SNode *next;
  ElemType data;

} LinkStack;

int main(void) {  // 程序入口，主函数

  return 0;
}