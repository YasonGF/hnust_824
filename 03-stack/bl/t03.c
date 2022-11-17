#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
两个栈 s1,s2 都采用顺序存储，并共享一个存储区[0,...,maxsize-1]。
采用栈顶相向，迎面增长的存储方式，设计 s1,s2 入栈和出栈的操作。
*/
typedef int ElemType;

#define MaxSize 10

typedef struct {
  ElemType data[MaxSize];
  int top1;
  int top2;
} double_stack;

void init(double_stack *s) {
  s->top1 = -1;
  s->top2 = MaxSize;
  memset(s->data, -1, MaxSize * sizeof(ElemType));
}

bool empty(double_stack *s, int op) {
  if (op == 1) return s->top1 == -1;
  if (op == 2) return s->top2 == MaxSize;
  printf("op is error\n");
  return true;
}

bool overflow(double_stack *s) {  // 判断是否栈满
  return s->top1 + 1 == s->top2;
}

bool push(double_stack *s, int op, ElemType x) {
  if (op < 1 || op > 2) return false;
  if (overflow(s)) return false;

  switch (op) {
    case 1:
      s->data[++s->top1] = x;
      break;
    case 2:
      s->data[--s->top2] = x;
      break;
  }
  return true;
}

bool pop(double_stack *s, int op, ElemType *x) {
  if (empty(s, op)) return false;

  switch (op) {
    case 1:
      *x = s->data[s->top1--];
      break;
    case 2:
      *x = s->data[s->top2++];
      break;
  }
  return true;
}

bool top(double_stack *s, int op, ElemType *x) {
  if (empty(s, op)) return false;

  switch (op) {
    case 1:
      *x = s->data[s->top1];
      break;
    case 2:
      *x = s->data[s->top2];
      break;
  }
  return true;
}

int main(void) {
  double_stack s;
  init(&s);

  push(&s, 1, 2);  // 向栈s1添加元素2
  push(&s, 1, 3);
  push(&s, 1, 4);
  push(&s, 2, 67);  // 向栈s2添加元素67
  push(&s, 1, 61);

  int op, x;
  while (scanf("%d%d", &op, &x)) {
    if (push(&s, op, x)) {
      printf("%d inserted s%d\n", x, op);
    }
  }

  return 0;
}
